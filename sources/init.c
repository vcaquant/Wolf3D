/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:11:14 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/23 09:28:57 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	put(t_env *env, int x, int y, int col)
{
	env->img->bts_img[x * 4 + 0 + y * env->img->size_line] = (col >> 16) & 0xff;
	env->img->bts_img[x * 4 + 1 + y * env->img->size_line] = (col >> 8) & 0xff;
	env->img->bts_img[x * 4 + 2 + y * env->img->size_line] = (col >> 0) & 0xff;
}

void	put_blue(t_env *env, int x, int y)
{
	env->img->bts_img[x * 4 + 0 + y * env->img->size_line] = 255;
	env->img->bts_img[x * 4 + 1 + y * env->img->size_line] = 165;
	env->img->bts_img[x * 4 + 2 + y * env->img->size_line] = 0;
}

void	put_black(t_env *env, int x, int y)
{
	env->img->bts_img[x * 4 + 0 + y * env->img->size_line] = 149;
	env->img->bts_img[x * 4 + 1 + y * env->img->size_line] = 165;
	env->img->bts_img[x * 4 + 2 + y * env->img->size_line] = 166;
}

void	color(t_env *env)
{
	env->color[0] = RED;
	env->color[1] = AZUR;
}

void	init_var(t_env *env)
{
	int	i;

	i = 0;
	env->x = 1.5;
	env->y = 1.5;
	env->front = 0.10;
	env->back = -0.10;
	env->xc = 0;
	env->yc = 0;
	env->move = 0;
	env->fov = M_PI / 3;
	env->theta = 0;
	env->angle = env->theta - (env->fov / 2) + (1 * 64 / W_X) * (env->fov);
}

int		ft_init_struct(t_env **env)
{
	int x;

	x = 0;
	if (!(*env = (t_env*)malloc(sizeof(t_env))))
		return (0);
	if (!((*env)->img = (t_img*)malloc(sizeof(t_img))))
		return (0);
	return (1);
}
