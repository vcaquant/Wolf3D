/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_code.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:20:51 by vcaquant          #+#    #+#             */
/*   Updated: 2016/12/23 14:11:34 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	speed(t_env *env)
{
	if (env->front == 0.10)
		env->front = 0.30;
	else
		env->front = 0.10;
}

void	move_back(t_env *env)
{
	if (env->tab[(int)(env->y - sin(env->angle) * env->back)][
		(int)(env->x + cos(env->angle) * env->back)] == 0)
	{
		env->x += cos(env->angle) * env->back;
		env->y -= sin(env->angle) * env->back;
	}
}

void	move_front(t_env *env)
{
	if (env->tab[(int)(env->y - sin(env->angle) * env->front)][
		(int)(env->x + cos(env->angle) * env->front)] == 0)
	{
		env->x += cos(env->angle) * env->front;
		env->y -= sin(env->angle) * env->front;
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
		img_init(env);
		map(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img->ptr_img, 0, 0);
	}
	if (keycode == 1)
		speed(env);
	if (keycode == 12 || keycode == 53)
	{
		ft_putstr("\033[0;32m✔︎ Wolf3D Closed\033[0m\n");
		free(env->img);
		freetab(env);
		free(env);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
