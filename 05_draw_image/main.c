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

int		ft_mlx_from_rgb(int r, int g, int b)
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

	color = r << 16 | g << 8 | b;
	return (color);
}

void	ft_mlx_image_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->img.addr + (y * vars->img.size_line + x *
			vars->img.bytes_per_pixel);
	*(unsigned int *)dst = color;
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
			ft_mlx_image_pixel_put(vars, j, i, color);
			j++;
		}
		i++;
	}
}

void	ft_mlx_image_create_try_draw(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, vars->width, vars->height);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.size_line, &vars->img.endian);
	vars->img.bytes_per_pixel = vars->img.bits_per_pixel / 8;

	int		color = ft_mlx_from_rgb(255, 255, 255);
	printf("%.6x\n", color);

	ft_mlx_fill(vars, vars->width, vars->height, color);

	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void	get_size(t_vars *vars, int width, int height)
{
	int		screen_width;
	int		screen_height;

	mlx_get_screen_size(vars->mlx, &screen_width, &screen_height);
	vars->width = width < screen_width ? width : screen_width;
	vars->height = height < screen_height ? height : screen_height;
}

int		main()
{
	t_vars	vars;

	vars.mlx = mlx_init();
	get_size(&vars, 1000, 500);

	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "05 draw image");
	mlx_key_hook(vars.win, ft_mlx_handle_key_input, &vars);

	ft_mlx_image_create_try_draw(&vars);

	mlx_loop(vars.mlx);

	return (0);
}
