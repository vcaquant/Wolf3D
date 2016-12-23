/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:43:32 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/23 09:28:00 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		red_cross(void)
{
	ft_putstr("\033[0;32m✔︎ Wolf3D Closed\033[0m\n");
	exit(EXIT_SUCCESS);
}

void	prp_win(t_env *env)
{
	env->win = mlx_new_window(env->mlx, W_X, W_Y, "WOLF");
	env->img->ptr_img = mlx_new_image(env->mlx, W_X, W_Y);
	env->img->bts_img = mlx_get_data_addr(env->img->ptr_img, &(env->img->bpp),
			&(env->img->size_line), &(env->img->end));
	mlx_hook(env->win, 17, (1L << 17), red_cross, env);
}

void	ft_color(t_env *env, int x, int y)
{
	if (x < 800 && y < 650 && x >= 0 && y >= 0)
	{
		env->img->bts_img[x * 4 + 0 + y * env->img->size_line] = 255;
		env->img->bts_img[x * 4 + 1 + y * env->img->size_line] = 255;
		env->img->bts_img[x * 4 + 2 + y * env->img->size_line] = 255;
	}
}

void	map(t_env *env)
{
	int		x;
	int		y;
	int		color;
	double	h;
	double	angle;

	x = -1;
	while (++x < W_X)
	{
		y = -1;
		angle = env->angle - M_PI / 6 + (M_PI / 3 * (x * 1.0 / W_X));
		angle > 2 * M_PI ? angle -= 2 * M_PI : 0;
		angle < 0 ? angle += 2 * M_PI : 0;
		h = draw_line(env, angle, &color);
		h = cos(M_PI / 6 - (M_PI / 3 * (x * 1.0 / W_X))) * h;
		h = 100000 / h;
		while (++y < W_Y)
		{
			if (y > ((1 - (h * 1.0 / W_Y)) * W_Y) / 2 &&
				y < (W_Y / 2.0 + h / 2.0))
				put(env, x, y, color);
			sky_floor(env, x, y, h);
		}
	}
	minimap(env);
}

int		main(int ac, char **av)
{
	t_env	*env;

	if (ac > 2)
		return (ft_error2());
	if (!ft_init_struct(&env))
		return (-1);
	if (ft_init_tab(env, av) == -1)
		return (ft_error());
	init_var(env);
	env->fd = open(av[1], O_RDONLY);
	env->tab = (int**)malloc(sizeof(int*) * (env->endy + 1));
	ft_recup(env);
	if (verify(env) == -1)
		return (ft_error());
	env->mlx = mlx_init();
	prp_win(env);
	map(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img->ptr_img, 0, 0);
	mlx_hook(env->win, 2, 0, aff_key, env);
	mlx_do_key_autorepeaton(env->mlx);
	mlx_loop(env->mlx);
	return (0);
}
