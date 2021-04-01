#include <stdio.h>
#include <stdlib.h>
#include "ft_mlx.h"

int		ft_mlx_handle_key_input(int keycode, t_vars *vars)
{
	if (keycode == w || keycode == a || keycode == s || keycode == d ||
		keycode == up || keycode == left || keycode == right || keycode == down)
	{
		ft_mlx_handle_move(keycode, vars);
	}
	else if (keycode == i || keycode == j || keycode == k || keycode == l)
	{
		ft_mlx_handle_rotation(keycode, vars);
	}
	else if (keycode == esc)
	{
		ft_mlx_exit(vars);
	}
	printf("\n");
	return (0);
}

void	ft_mlx_fill(t_vars *vars, int x, int y, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			mlx_pixel_put(vars->mlx, vars->win, j, i, color);
			j++;
		}
		i++;
	}
}

int		ft_mlx_build_color(int r, int g, int b)
{
	int		color;

	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	else if (b > 255)
		b = 255;

	color = r << 4 & g << 2 & b;
	return (color);
}

int		main()
{
	t_vars	vars;
	int		height;
	int		width;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "04_draw");
	mlx_key_hook(vars.win, ft_mlx_handle_key_input, &vars);
	mlx_get_screen_size(vars.mlx, &height, &width);
	ft_mlx_fill(&vars, height, width, ft_mlx_build_color(255, 255, 255));
	mlx_loop(vars.mlx);

	return (0);
}
