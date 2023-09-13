#include "../../headers/cubed.h"

static int	on_edge(t_info **info, int y, int x)
{
	if (y == 0 || x == 0
		|| x == ((*info)->m_width - 1)
		|| y == ((*info)->m_height - 1))
		return (1);
	return (0);
}

void	flood_fill(t_info **info, int y, int x)
{
	t_coord *temp;

	temp = &(*info)->map[y][x];
	printf("evaluating '%c' on [%d,%d]\n", temp->ch, temp->y, temp->x);
	if (temp->ch == ' ')
		ft_put_error_exit("Invalid map");
	else if (temp->checked)
		return ;
	if (temp->ch == '1')
		return ;
	if (on_edge(info, y, x))
		ft_put_error_exit("Invalid map");
	temp->checked = 1;
	flood_fill(info, temp->y - 1, temp->x);
	flood_fill(info, temp->y, temp->x - 1);
	flood_fill(info, temp->y + 1, temp->x);
	flood_fill(info, temp->y, temp->x + 1);
}

//static  void    validate_start_point(t_info **info)
//{
//    if ((*info)->begin->x == 0 || (*info)->begin->x == (*info)->m_width)
//        ft_put_error_exit("Start point out of maze");
//    if ((*info)->begin->y == 0 || (*info)->begin->y == (*info)->m_height)
//        ft_put_error_exit("Start point out of maze");
//    //need to check for spaces around
//}

//void  flood_fill(t_info **info)
//{
//    int i;
//    int j;
//    i = (*info)->begin->x;
//    j = (*info)->begin->y;
//    (*info)->map[j][i].ch = '0';
//    validate_start_point(info);
//    while (j < (*info)->m_height)
//    {
//        while (i < (*info)->m_width && (*info)->map[j][i].ch != ' ')
//        {
//            if (i >= 0 && i < (*info)->m_width && j >= 0 && j <  (*info)->m_height && (*info)->map[j][i].ch == '1')
//                (*info)->map[j][i].ch = '2';
//            i++;
//        }
//        i = 0;
//        j++;
//    }
//    j = 0;
//    while (j < (*info)->begin->y && (*info)->map[j][i].ch != ' ')
//    {
//        i = 0;
//        while (i < (*info)->m_width && (*info)->map[j][i].ch != ' ')
//        {
//            if (i >= 0 && i < (*info)->m_width && j >= 0 && j <  (*info)->m_height && (*info)->map[j][i].ch == '1')
//                (*info)->map[j][i].ch = '2';
//            i++;
//        }
//        j++;
//    }
//    if (j == (*info)->begin->y)
//    {
//        i = 0;
//        while (i < (*info)->begin->x && (*info)->map[j][i].ch != ' ')
//        {
//            if (i >= 0 && i < (*info)->m_width && j >= 0 && j <  (*info)->m_height && (*info)->map[j][i].ch == '1')
//                (*info)->map[j][i].ch = '2';
//            i++;
//        }
//    }
//}

