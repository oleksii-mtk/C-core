#include <stdlib.h>
#include "map.h"

int read_number(int fd)
{
    char c;
    int number = 0;

    while (read(fd, &c, 1) > 0 && c >= '0' && c <= '9')
    {
        number = number * 10 + (c - '0');
    }
    return number;
}

s_mapinfo *read_map(const char *filename)
{
    char chars[3];
    int rows;
    int fd;
    s_mapinfo *map_info;
    int i;
    int j;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        _exit(EXIT_FAILURE);
    }

    // 1st raw
    rows = read_number(fd);
    read(fd, &chars, 3);

    char newline;
    read(fd, &newline, 1); // Пропускаем символ новой строки

    // Выделяем память для структуры MapInfo
    map_info = (s_mapinfo *)malloc(sizeof(s_mapinfo));
    map_info->rows = rows;
    map_info->empty = chars[0];
    map_info->obstacle = chars[1];
    map_info->full = chars[2];
    map_info->map = (char **)malloc(rows * sizeof(char *));

    // Чтение строк карты
    i = 0;
    while (i < rows)
    {
        map_info->map[i] = (char *)malloc(1024 * sizeof(char)); 
        j = 0;
        while (read(fd, &map_info->map[i][j], 1) > 0 && map_info->map[i][j] != '\n')
        {
            j++;
        }
        map_info->map[i][j] = '\0'; 
        i++;
    }

    close(fd);
    return map_info;
}

void free_map(s_mapinfo *map_info)
{
    int i;
    i = 0;
    while (i < map_info->rows)
    {
        free(map_info->map[i]);
        i++
    }
    free(map_info->map);
    free(map_info);
}

int main()
{
    s_mapinfo *map_info;
    int i;

    map_info = read_map("input.txt");
    i = 0;
    while (i < map_info->rows)
    {
        write(STDOUT_FILENO, map_info->map[i], 1024);
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }

    free_map(map_info);

    return 0;
}
