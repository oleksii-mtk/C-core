#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**map;
}			s_mapinfo;

int get_str_len(char *str)
{
    int i;

    i = 0;
    while (*str)
    {
        i++;
        str++;
    }
    return i;
}

void write_error(char *error_msg)
{
    write(2, "map error", 9);
    if (error_msg)
    {
        write(2, ":  ", 2);
        write(2, error_msg, get_str_len(error_msg));
    }
    write(2, "\n", 1);
    exit(EXIT_FAILURE);

}

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


void	free_map(s_mapinfo *map_info)
{
	int	i;

	i = 0;
	while (i < map_info->rows)
	{
		free(map_info->map[i]);
		i++;
	}
	free(map_info->map);
	free(map_info);
}

int	can_place_square(s_mapinfo *map_info, int i, int j, int step)
{
	int	x;
	int	y;

	if (i + step > map_info->rows || j + step > map_info->cols)
	{
		return (0);
	}
	x = i;
	while (x < i + step)
	{
		y = j;
		while (y < j + step)
		{
			printf("%c [%d][%d][%c]\n",map_info->obstacle, x,y, map_info->map[x][y] );
			if (map_info->map[x][y] == map_info->obstacle)
			{
				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

void	find_max_square(s_mapinfo *map_info, int *i_max, int *j_max,
		int *step_max)
{
	int	step;
	int	i;
	int	j;

	*step_max = 0;
	printf("%d\n",map_info->rows );	
	i = 0;
	while (i < map_info->rows)
	{
		j = 0;
		while (j < map_info->cols)
		{
			step = 1;
			while (can_place_square(map_info, i, j, step))
			{
//				printf("i=%d j=%d step=%d\n", i, j, step);
				if (step > *step_max)
				{
					printf("i=%d j=%d step=%d\n", i, j, step);

					*step_max = step;
					*i_max = i;
					*j_max = j;
				}
				step++;
			}
			j++;
		}
		i++;
	}
}
void	fill_square(s_mapinfo *map_info, int i_max, int j_max, int step_max)
{
	int	i;
	int	j;

	i = i_max;
	while (i < i_max + step_max)
	{
		j = j_max;
		while (j < j_max + step_max)
		{
			map_info->map[i][j] = map_info->full;
			j++;
		}
		i++;
	}
}
void	print_map(s_mapinfo *map_info)
{
	int	i;

	i = 0;
	while (i < map_info->rows)
	{
		write(STDOUT_FILENO, map_info->map[i], map_info->cols);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

s_mapinfo *create_map_from_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        write(STDERR_FILENO, "error: cannot open file\n", 24);
        return NULL;
    }

    char buffer[1024];
    int bytes_read = 0;
    int index = 0;

    
    while ((bytes_read = read(fd, &buffer[index], 1)) > 0 && buffer[index] != '\n') {
        index++;
    }
    buffer[index] = '\0';

    
    s_mapinfo *map_info = (s_mapinfo *)malloc(sizeof(s_mapinfo));
    map_info->rows = atoi(buffer);   
    map_info->empty = buffer[1];     
    map_info->obstacle = buffer[2];  
    map_info->full = buffer[3];      

    
    map_info->map = (char **)malloc(map_info->rows * sizeof(char *));

    int row_count = 0;
    while (row_count < map_info->rows) {
        index = 0;

        while ((bytes_read = read(fd, &buffer[index], 1)) > 0 && buffer[index] != '\n') {
            index++;
        }

        if (bytes_read == 0) break; 

        buffer[index] = '\0';
        map_info->cols = index; // 

        map_info->map[row_count] = (char *)malloc((index + 1) * sizeof(char));

        int col = 0;
        while (col < index) {
            map_info->map[row_count][col] = buffer[col];
            col++;
        }
        map_info->map[row_count][col] = '\0';

        row_count++;
    }

    
    if (read(fd, buffer, 1) > 0) {
        write(STDERR_FILENO, "map error\n", 10);
        free_map(map_info);
        close(fd);
        return NULL;
    }

    close(fd);
    return map_info;
}


int	main(void)
{
/*	s_mapinfo	*map_info;

	int i_max, j_max, step_max;
	map_info = read_map("input.txt");
	print_map(map_info);
	find_max_square(map_info, &i_max, &j_max, &step_max);
	fill_square(map_info, i_max, j_max, step_max);
	print_map(map_info);
	free_map(map_info);*/
	s_mapinfo *map_info = create_map_from_file("input.txt");
	int i_max, j_max, step_max;
	i_max = 0;
	j_max = 0;
	step_max = 0;

    if (map_info != NULL) {
        
	print_map(map_info);
	find_max_square(map_info, &i_max, &j_max, &step_max);
//	printf("%d %d %d ", i_max, j_max, step_max);

        fill_square(map_info, i_max, j_max, step_max);
	//printf("%d %d %d ", i_max, j_max, step_max);

	print_map(map_info);

        free_map(map_info);
    }

	return (0);
}
