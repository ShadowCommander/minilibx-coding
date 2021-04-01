#ifndef FT_MLX_H
# define FT_MLX_H

# include "mlx.h"

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		bytes_per_pixel;
}				t_img;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_img		img;
	int			width;
	int			height;
}				t_vars;

enum e_keycodes {
	w = 119,
	a = 97,
	s = 115,
	d = 100,
	up = 65362,
	left = 65361,
	down = 65364,
	right = 65363,
	i = 105,
	j = 106,
	k = 107,
	l = 108,
	esc = 65307
};

void	ft_mlx_handle_move(int keycode, t_vars *vars);
void	ft_mlx_handle_rotation(int keycode, t_vars *vars);
void	ft_mlx_exit();

#endif
