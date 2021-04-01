#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

typedef struct	s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

int		key_hook(int keycode, t_vars *vars)
{
	printf("Keypress: %d\n", keycode);
	return (0);
}

int		main()
{
	t_vars		vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "02 print input");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);

	return (0);
}
