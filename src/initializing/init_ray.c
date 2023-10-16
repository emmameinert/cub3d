
#include "../../headers/cubed.h"

void	init_ray(double angle, t_ray *ray, t_player *player)
{
	ray->angle = angle;
	ray->x = player->x;
	ray->y = player->y;
	ray->cos = 0;
	ray->sin = 0;
	ray->text_x = 0;
}
