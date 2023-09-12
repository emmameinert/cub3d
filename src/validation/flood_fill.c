#include "../../headers/cubed.h"

static  void    validate_start_point(t_info **info)
{
    if ((*info)->begin->x == 0 || (*info)->begin->x == (*info)->m_width)
        ft_put_error_exit("Start point out of maze");
    if ((*info)->begin->y == 0 || (*info)->begin->y == (*info)->m_height)
        ft_put_error_exit("Start point out of maze");
    //need to check for spaces around
}

void  flood_fill(t_info **info)
{
    int i;
    int j;
    i = (*info)->begin->x;
    j = (*info)->begin->y;
    (*info)->map[j][i].ch = '0';
    validate_start_point(info);
    while (j < (*info)->m_height)
    {
        while (i < (*info)->m_width && (*info)->map[j][i].ch != ' ')
        {
            if (i >= 0 && i < (*info)->m_width && j >= 0 && j <  (*info)->m_height && (*info)->map[j][i].ch == '1')
                (*info)->map[j][i].ch = '2';
            i++;
        }
        i = 0;
        j++;
    }
    j = 0;
    while (j < (*info)->begin->y && (*info)->map[j][i].ch != ' ')
    {
        i = 0;
        while (i < (*info)->m_width && (*info)->map[j][i].ch != ' ')
        {
            if (i >= 0 && i < (*info)->m_width && j >= 0 && j <  (*info)->m_height && (*info)->map[j][i].ch == '1')
                (*info)->map[j][i].ch = '2';
            i++;
        }
        j++;
    }
    if (j == (*info)->begin->y)
    {
        i = 0;
        while (i < (*info)->begin->x && (*info)->map[j][i].ch != ' ')
        {
            if (i >= 0 && i < (*info)->m_width && j >= 0 && j <  (*info)->m_height && (*info)->map[j][i].ch == '1')
                (*info)->map[j][i].ch = '2';
            i++;
        }
    }
}

