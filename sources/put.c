/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:22:32 by vcaquant          #+#    #+#             */
/*   Updated: 2016/12/23 16:07:19 by vcaquant         ###   ########.fr       */
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

void	sky_floor(t_env *env, int x, int y, double h)
{
	if (y < ((1 - (h * 1.0 / W_Y)) * W_Y) / 2)
		put_blue(env, x, y);
	else if (y > (W_Y / 2.0 + h / 2.0))
		put_black(env, x, y);
}
