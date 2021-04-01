#include <stdio.h>
#include <stdlib.h>
#include "ft_mlx.h"

void	ft_mlx_handle_move(int keycode, t_vars *vars)
{
	if (keycode == w || keycode == up)
		printf("Moving north");
	else if (keycode == a || keycode == left)
		printf("Moving west");
	else if (keycode == s || keycode == down)
		printf("Moving south");
	else if (keycode == d || keycode == right)
		printf("Moving east");
}

void	ft_mlx_handle_rotation(int keycode, t_vars *vars)
{
	if (keycode == i)
		printf("Rotating north");
	else if (keycode == j)
		printf("Rotating west");
	else if (keycode == k)
		printf("Rotating south");
	else if (keycode == l)
		printf("Rotating east");
}

void	ft_mlx_exit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	exit(0);
}
