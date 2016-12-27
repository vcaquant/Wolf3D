/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:04:38 by vcaquant          #+#    #+#             */
/*   Updated: 2016/12/23 16:09:25 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# define W_X		1200
# define W_Y		850

# define BLACK		0x000000
# define WHI		0xFFFFFF
# define AZUR		0x74D0F1
# define A_F		0x1E7FCB
# define ABS		0x7FDD4C
# define RED		0x00FF0000
# define BRO		0x00996600
# define G_P		0x0099FF00
# define G_F		0x0000CC00
# define Y_P		0x00CCCC66

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx_macos/mlx.h"

# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_img
{
	void		*ptr_img;
	char		*bts_img;
	int			size_line;
	int			bpp;
	int			end;
}				t_img;

typedef struct	s_env
{
	int		**tab;
	void	*mlx;
	void	*win;
	int		fd;

	char	*line;

	int		*color;

	double	front;
	double	back;

	double	x;
	double	y;

	double	theta;
	double	fov;

	double	angle;

	int		ret;
	int		xc;
	int		yc;
	int		endx;
	int		endy;

	t_img	*img;

	int		move;
}				t_env;

typedef struct	s_drawline
{
	double		dx;
	double		dy;
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	double		z1;
	double		z2;
	double		e;
}				t_drawline;

int				red_cross(void);
void			prp_win(t_env *env);
void			ft_color(t_env *env, int x, int y);
void			map(t_env *env);

int				verify2(t_env *env);
int				verify(t_env *env);
int				ft_error(void);
int				ft_error2(void);

void			freetab(t_env *env);
void			img_init(t_env *env);
int				ft_init_struct(t_env **env);
void			init_var(t_env *env);

int				ft_init_tab(t_env *env, char **av);
int				ft_count_x(char *str);
int				*ft_recupline(char *str);
void			ft_recup(t_env *env);

void			init_point(t_env *env, t_point *p1, t_point *p2, t_point *p3);
void			change_point(t_point *p2, t_point *p3);
double			draw_line(t_env *env, double angle, int *color);

void			ft_drawline(t_env *env, t_point p1, t_point p2);
void			cadran1_a(t_drawline *draw, t_env *env);
void			cadran1_b(t_drawline *draw, t_env *env);
void			cadran2_a(t_drawline *draw, t_env *env);
void			cadran2_b(t_drawline *draw, t_env *env);
void			cadran3_a(t_drawline *draw, t_env *env);
void			cadran3_b(t_drawline *draw, t_env *env);
void			cadran4_a(t_drawline *draw, t_env *env);
void			cadran4_b(t_drawline *draw, t_env *env);
void			dx_null_a(t_drawline *draw, t_env *env);
void			dx_null_b(t_drawline *draw, t_env *env);
void			dy_null_a(t_drawline *draw, t_env *env);
void			dy_null_b(t_drawline *draw, t_env *env);

void			put(t_env *env, int x, int y, int color);
void			put_black(t_env *env, int x, int y);
void			put_blue(t_env *env, int x, int y);
void			sky_floor(t_env *env, int x, int y, double h);

void			mini(t_env *env);
void			minimap(t_env *env);

int				hor_sup_z(t_env *env, t_point *p3, double angle, int *color);
int				hor_inf_z(t_env *env, t_point *p3, double angle, int *color);
void			ver_sup_pi(t_env *env, t_point *p2, double angle, int *color);
void			ver_inf_pi(t_env *env, t_point *p2, double angle, int *color);

void			speed(t_env *env);
void			move_back(t_env *env);
void			move_front(t_env *env);
void			cam(t_env *env, int keycode);
int				aff_key(int keycode, t_env *env);

#endif
