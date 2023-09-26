
#include "../../headers/cubed.h"

void	calc_player_angle(t_info **info)
{
	(*info)->player->dir_x = cos(ft_dtorad((*info)->player->angle));
	(*info)->player->dir_y = -sin(ft_dtorad((*info)->player->angle));
}

void	rot_player(int sign, t_info **info)
{
	(*info)->player->angle = ft_angle((*info)->player->angle + (sign * PLR_ROT_STEP));
	calc_player_angle(info);
}

void	move_front_back(int sign_x, int sign_y, t_info **info)
{
	(*info)->player->x += sign_x * (*info)->player->dir_x * PLR_STEP;
	(*info)->player->y += sign_y * (*info)->player->dir_y * PLR_STEP;
}

void	move_side(int sign_x, int sign_y, t_info **info)
{
	(*info)->player->angle += (90 * sign_x);
	calc_player_angle(info);
	move_front_back(1, 1, info);
	(*info)->player->angle += (90 * sign_y);
}
