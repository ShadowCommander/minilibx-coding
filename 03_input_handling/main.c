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

int		main()
{
	t_vars		vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "03 input handling");
	mlx_key_hook(vars.win, ft_mlx_handle_key_input, &vars);
	mlx_loop(vars.mlx);

	return (0);
}
