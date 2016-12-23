/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:02:25 by vcaquant          #+#    #+#             */
/*   Updated: 2016/12/23 14:02:27 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	mini(t_env *env)
{
	double	x2;
	double	y2;

	y2 = (env->y * ((W_Y / 7) / env->endy)) + 2;
	while (y2 > (env->y * ((W_Y / 7) / env->endy)))
	{
		x2 = (env->x * ((W_X / 7) / env->endx)) + 2;
		while (x2 > (env->x * ((W_X / 7) / env->endx)))
		{
			env->img->bts_img
				[(int)x2 * 4 + 0 + (int)y2 * env->img->size_line] = 0;
			env->img->bts_img
				[(int)x2 * 4 + 1 + (int)y2 * env->img->size_line] = 232;
			env->img->bts_img
				[(int)x2 * 4 + 2 + (int)y2 * env->img->size_line] = 255;
			x2--;
		}
		y2--;
	}
}

void	minimap(t_env *env)
{
	int		x;
	int		y;

	y = -1;
	while (++y < W_Y / 7)
	{
		x = -1;
		while (++x < W_X / 7)
		{
			if (env->tab[(int)(((double)y / (W_Y / 7)) * env->endy)]
				[(int)(((double)x / (W_X / 7)) * env->endx)] == 1)
			{
				env->img->bts_img[x * 4 + 0 + y * env->img->size_line] = 255;
				env->img->bts_img[x * 4 + 1 + y * env->img->size_line] = 255;
				env->img->bts_img[x * 4 + 2 + y * env->img->size_line] = 255;
			}
			else
			{
				env->img->bts_img[x * 4 + 0 + y * env->img->size_line] = 101;
				env->img->bts_img[x * 4 + 1 + y * env->img->size_line] = 100;
				env->img->bts_img[x * 4 + 2 + y * env->img->size_line] = 87;
			}
		}
	}
	mini(env);
}
