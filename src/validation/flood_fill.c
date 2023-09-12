#include "../../headers/cubed.h"

static  void    validate_start_point(t_textures **texture)
{
    if ((*texture)->x_start == 0 || (*texture)->x_start == (*texture)->m_width)
        ft_put_error_exit("Start point out of maze");
    if ((*texture)->y_start == 0 || (*texture)->y_start == (*texture)->m_height)
        ft_put_error_exit("Start point out of maze");
    //need to check for spaces around
}

void  flood_fill(t_textures **texture)
{
    int i;
    int j;
    i = (*texture)->x_start;
    j = (*texture)->y_start;
    (*texture)->map[j][i].ch = '0';
    validate_start_point(texture);
    while (j < (*texture)->m_height)
    {
        while (i < (*texture)->m_width && (*texture)->map[j][i].ch != ' ')
        {
            if (i >= 0 && i < (*texture)->m_width && j >= 0 && j <  (*texture)->m_height && (*texture)->map[j][i].ch == '1')
                (*texture)->map[j][i].ch = '2';
            i++;
        }
        i = 0;
        j++;
    }
    j = 0;
    while (j < (*texture)->y_start && (*texture)->map[j][i].ch != ' ')
    {
        i = 0;
        while (i < (*texture)->m_width && (*texture)->map[j][i].ch != ' ')
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
        while (i < (*texture)->x_start && (*texture)->map[j][i].ch != ' ')
        {
            if (i >= 0 && i < (*texture)->m_width && j >= 0 && j <  (*texture)->m_height && (*texture)->map[j][i].ch == '1')
                (*texture)->map[j][i].ch = '2';
            i++;
        }
    }
}

