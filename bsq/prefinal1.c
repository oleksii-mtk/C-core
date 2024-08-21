#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int rows;
    int cols;
    char empty;
    char obstacle;
    char full;
    char **map;
} MapInfo;

MapInfo *create_map_from_data(char **data, int rows, char empty, char obstacle, char full) {
    MapInfo *map_info = (MapInfo *)malloc(sizeof(MapInfo));
    map_info->rows = rows;
    map_info->empty = empty;
    map_info->obstacle = obstacle;
    map_info->full = full;
    
    // Определяем количество колонок по первой строке
    int cols = 0;
    while (data[0][cols] != '\0') {
        cols++;
    }
    map_info->cols = cols;
    
    map_info->map = (char **)malloc(rows * sizeof(char *));
    
    for (int i = 0; i < rows; i++) {
        // Проверяем, совпадает ли количество колонок в текущей строке
        int current_cols = 0;
        while (data[i][current_cols] != '\0') {
            current_cols++;
        }
        
        if (current_cols != cols) {
            // Ошибка: количество колонок не совпадает
            write(STDERR_FILENO, "Error: inconsistent row lengths.\n", 34);
            free_map(map_info);
            exit(1);
        }

        // Копируем строку в карту
        map_info->map[i] = (char *)malloc((cols + 1) * sizeof(char)); // cols + 1 для '\0'
        for (int j = 0; j < cols; j++) {
            map_info->map[i][j] = data[i][j];
        }
        map_info->map[i][cols] = '\0'; // Завершаем строку нулевым символом
    }

    return map_info;
}

void free_map(MapInfo *map_info) {
    for (int i = 0; i < map_info->rows; i++) {
        free(map_info->map[i]);
    }
    free(map_info->map);
    free(map_info);
}

// Проверка, может ли квадрат с началом в (i, j) и стороной step поместиться на карте
int can_place_square(MapInfo *map_info, int i, int j, int step) {
    if (i + step > map_info->rows || j + step > map_info->cols) {
        return 0; // Выход за границы карты
    }

    for (int x = i; x < i + step; x++) {
        for (int y = j; y < j + step; y++) {
            if (map_info->map[x][y] == map_info->obstacle) {
                return 0; // Внутри квадрата найдено препятствие
            }
        }
    }
    return 1; // Квадрат может быть построен
}

// Функция для поиска максимального квадрата
void find_max_square(MapInfo *map_info, int *i_max, int *j_max, int *step_max) {
    *step_max = 0; // Изначально максимальный размер квадрата равен 0

    for (int i = 0; i < map_info->rows; i++) {
        for (int j = 0; j < map_info->cols; j++) {
            int step = 1;
            while (can_place_square(map_info, i, j, step)) {
                if (step > *step_max) {
                    *step_max = step;
                    *i_max = i;
                    *j_max = j;
                }
                step++;
            }
        }
    }
}

// Функция для заполнения квадрата символом full
void fill_square(MapInfo *map_info, int i_max, int j_max, int step_max) {
    for (int i = i_max; i < i_max + step_max; i++) {
        for (int j = j_max; j < j_max + step_max; j++) {
            map_info->map[i][j] = map_info->full;
        }
    }
}

// Функция для вывода карты
void print_map(MapInfo *map_info) {
    for (int i = 0; i < map_info->rows; i++) {
        write(STDOUT_FILENO, map_info->map[i], map_info->cols);
        write(STDOUT_FILENO, "\n", 1);
    }
}

int main() {
    // Пример использования с жестко закодированной картой
    char *map_data[] = {
        "...........................",
        "....o......................",
        "............o..............",
        "...........................",
        "....o......................",
        "...............o...........",
        "...........................",
        "......o..............o.....",
        "..o.......o................"
    };
    
    int rows = 9;
    char empty = '.';
    char obstacle = 'o';
    char full = 'x';

    MapInfo *map_info = create_map_from_data(map_data, rows, empty, obstacle, full);

    int i_max, j_max, step_max;
    find_max_square(map_info, &i_max, &j_max, &step_max);

    // Заполнение найденного максимального квадрата символом full
    fill_square(map_info, i_max, j_max, step_max);

    // Вывод карты на экран
    print_map(map_info);

    // Освобождение памяти
    free_map(map_info);

    return 0;
}
