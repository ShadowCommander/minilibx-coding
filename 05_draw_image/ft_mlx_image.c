#include "ft_mlx.h"

int		ft_mlx_create_image(t_vars *vars)
{
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, vars.width, vars.height);
}

void	ft_mlx_fill(void *mlx, int x, int y, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			mlx_pixel_put(mlx, vars->win, j, i, color);
			j++;
		}
		i++;
	}
}


void	ft_mlx_image_pixel_put(t_img *img, int x, int y, int color)
{
	img->addr[(y * img->size_line) + x] = color;
}
