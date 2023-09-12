#include "../../headers/cubed.h"

void  flood_fill(char **tab, t_textures *map, t_coord *begin)
{
    char filler;
    int i;
    int j;

    // filler = tab[begin.y][begin.x];
    i = begin->x;
    j = begin->y;
    while (j < map->m_height)
    {
        while (i < map->m_width)
        {
            if (i >= 0 && i < map->m_width && j >= 0 && j <  map->m_height && tab[j][i] == filler)
                tab[j][i] = 'F';
            i++;
        }
        i = 0;
        j++;
    }
    j = 0;
    while (j < begin->y)
    {
        i = 0;
        while (i < map->m_width)
        {
            if (i >= 0 && i < map->m_width && j >= 0 && j <  map->m_height && tab[j][i] == filler)
                tab[j][i] = 'F';
            i++;
        }
        j++;
    }
    if (j == begin->y)
    {
        i = 0;
        while (i < begin->x)
        {
            if (i >= 0 && i < map->m_width && j >= 0 && j <  map->m_height && tab[j][i] == filler)
                tab[j][i] = 'F';
            i++;
        }
    }
}

