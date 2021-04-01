#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

int		main()
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx_project");
	mlx_loop(mlx);

	return (0);
}
