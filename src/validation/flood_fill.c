#include "../../headers/cubed.h"

void  flood_fill(t_textures **texture)
{
    int i;
    int j;
    i = (*texture)->x_start;
    j = (*texture)->y_start;
    (*texture)->map[j][i].ch = '0';
    while (j < (*texture)->m_height)
    {
        while (i < (*texture)->m_width)
        {
            if (i >= 0 && i < (*texture)->m_width && j >= 0 && j <  (*texture)->m_height && (*texture)->map[j][i].ch == '1')
                (*texture)->map[j][i].ch = '2';
            i++;
        }
        i = 0;
        j++;
    }
    j = 0;
    while (j < (*texture)->y_start)
    {
        i = 0;
        while (i < (*texture)->m_width)
        {
            if (i >= 0 && i < (*texture)->m_width && j >= 0 && j <  (*texture)->m_height && (*texture)->map[j][i].ch == '1')
                (*texture)->map[j][i].ch = '2';
            i++;
        }
        j++;
    }
    if (j == (*texture)->y_start)
    {
        i = 0;
        while (i < (*texture)->x_start)
        {
            if (i >= 0 && i < (*texture)->m_width && j >= 0 && j <  (*texture)->m_height && (*texture)->map[j][i].ch == '1')
                (*texture)->map[j][i].ch = '2';
            i++;
        }
    }
}

