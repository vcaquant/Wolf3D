/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_code.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:20:51 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/23 04:47:21 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	freetab(t_env *env)
{
	int		y;

	y = 0;
	while (y < env->endy)
	{
		free(env->tab[y]);
		y++;
	}
}

void	move(t_env *env, int keycode)
{
	mlx_destroy_image(env->mlx, env->img->ptr_img);
	env->img = malloc(sizeof(t_img));
	env->img->ptr_img = mlx_new_image(env->mlx, W_X, W_Y);
	env->img->bts_img = mlx_get_data_addr(env->img->ptr_img, &(env->img->bpp),
			&(env->img->size_line), &(env->img->end));
	if (keycode == 124)
	{
		env->angle = (int)((env->angle / M_PI / 2) * 360 + 5)
			/ 360.0 * M_PI * 2;
		env->angle >= 2 * M_PI ? env->angle -= 2 * M_PI : 0;
	}
	else if (keycode == 123)
	{
		env->angle = (int)((env->angle / M_PI / 2) * 360 - 5)
			/ 360.0 * M_PI * 2;
		env->angle >= 2 * M_PI ? env->angle += 2 * M_PI : 0;
	}
	map(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img->ptr_img, 0, 0);
}

void	move_back(t_env *env)
{
	if (env->tab[(int)(env->y - sin(env->angle) * -0.15)][
		(int)(env->x + cos(env->angle) * -0.15)] == 0)
	{
		env->x += cos(env->angle) * -0.15;
		env->y -= sin(env->angle) * -0.15;
	}
}

void	move_front(t_env *env)
{
	if (env->tab[(int)(env->y - sin(env->angle) * 0.15)][
		(int)(env->x + cos(env->angle) * 0.15)] == 0)
	{
		env->x += cos(env->angle) * 0.15;
		env->y -= sin(env->angle) * 0.15;
	}
}

void	cam(t_env *env, int keycode)
{
	if (keycode == 124)
	{
		env->angle += (M_PI / 2) / 90 * 5;
		env->angle >= 2 * M_PI ? env->angle -= 2 * M_PI : 0;
	}
	else if (keycode == 123)
	{
		env->angle -= (M_PI / 2) / 90 * 5;
		env->angle < 0 ? env->angle += 2 * M_PI : 0;
	}
}

int		aff_key(int keycode, t_env *env)
{
	if (keycode >= 123 && keycode <= 126)
	{
		mlx_destroy_image(env->mlx, env->img->ptr_img);
		free(env->img);
		if (keycode == 124 || keycode == 123)
			cam(env, keycode);
		else if (keycode == 125)
			move_back(env);
		if (keycode == 126)
			move_front(env);
		env->img = malloc(sizeof(t_img));
		env->img->ptr_img = mlx_new_image(env->mlx, W_X, W_Y);
		env->img->bts_img = mlx_get_data_addr(env->img->ptr_img,
			&(env->img->bpp), &(env->img->size_line), &(env->img->end));
		map(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img->ptr_img, 0, 0);
	}
	if (keycode == 12 || keycode == 53)
	{
		ft_putstr("\033[0;32m✔︎ Wolf3D Closed\033[0m\n");
		free(env->img);
		freetab(env);
		free(env->tab);
		free(env);
		// while (42) ;
		exit(EXIT_SUCCESS);
	}
	return (0);
}
