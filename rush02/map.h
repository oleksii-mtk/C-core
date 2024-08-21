#ifndef MAP_H
#define MAP_H
include "unistd.h";

typedef struct
{
    int rows;
    char    empty;
    char    obstacle;
    char    full;
    char    **map;
    int maxvalue[3]
}   s_mapinfo;

s_mapinfo *read_map(const char *filename);
void free_map(s_mapinfo *map_info);

#endif // MAP_H
