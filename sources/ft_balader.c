/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_balader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 09:58:29 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/23 09:58:31 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void 	mini(t_env *env)
{
	double	x2;
	double	y2;

	y2 = (env->y * ((W_Y / 7) / env->endy)) + 2;
	while (y2 > (env->y * ((W_Y / 7) / env->endy)))
	{
		x2 = (env->x * ((W_X / 7) / env->endx)) + 2;
		while (x2 > (env->x * ((W_X / 7) / env->endx)))
		{
			env->img->bts_img[(int)x2 * 4 + 0 + (int)y2 * env->img->size_line]
				= 0;
			env->img->bts_img[(int)x2 * 4 + 1 + (int)y2 * env->img->size_line]
				= 232;
			env->img->bts_img[(int)x2 * 4 + 2 + (int)y2 * env->img->size_line]
				= 255;
			x2--;
		}
		y2--;
	}
}

void 	minimap(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < W_Y / 7)
	{
		x = 0;
		while (x < W_X / 7)
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
			x++;
		}
		y++;
	}
	mini(env);
}

int		hor_sup_z(t_env *env, t_point *p3, double angle, int *color)
{
	(*p3).y = ((int)env->y);
	(*p3).x = ((env->y - (int)env->y) / tan(angle) + env->x);
	if ((*p3).y >= (env->endy - 1) || (*p3).y < 0 || (*p3).x < 0 || (*p3).x >= env->endx)
		return (1);
	else
		while (env->tab[(int)(*p3).y - 1][(int)(*p3).x] == 0 &&
				env->tab[(int)(*p3).y][(int)(*p3).x] == 0)
		{
			(*p3).y--;
			(*p3).x += 1 / tan(angle);
			if ((*p3).y >= env->endy || (*p3).y <= 0 || (*p3).x < 0 || (*p3).x >= env->endx)
				return (1);
		}
	*color = 0xe74c3c;
	return (0);
}

int		hor_inf_z(t_env *env, t_point *p3, double angle, int *color)
{
	(*p3).y = ((int)env->y + 1);
	(*p3).x = ((((int)env->y + 1) - env->y) / tan(-1 * angle) + env->x);
	if ((*p3).y >= env->endy || (*p3).y <= 0 || (*p3).x < 0 || (*p3).x >= (env->endx - 1))
		return (1);
	else
		while (env->tab[(int)(*p3).y - 1][(int)(*p3).x] == 0 &&
				env->tab[(int)(*p3).y][(int)(*p3).x] == 0)
		{
			(*p3).y++;
			(*p3).x += -1 / tan(angle);
			if ((*p3).y >= env->endy || (*p3).y <= 0 || (*p3).x < 0 || (*p3).x >= env->endx)
				return (1);
		}
	*color = 0x71cc2e;
	return (0);
}

void	ver_sup_pi(t_env *env, t_point *p2, double angle, int *color)
{
	(*p2).x = ((int)env->x);
	(*p2).y = (tan(angle) * (env->x - (int)env->x) + env->y);
	if ((*p2).y < env->endy && (*p2).y >= 0 && (*p2).x > 0 && (*p2).x < env->endx)
		while (env->tab[(int)(*p2).y][(int)(*p2).x - 1] == 0 &&
				env->tab[(int)(*p2).y][(int)(*p2).x] == 0)
		{
			(*p2).x--;
			(*p2).y += tan(angle);
			if ((*p2).y >= env->endy || (*p2).y < 0 || (*p2).x < 0 || (*p2).x >= (env->endx - 1))
				break ;
		}
	*color = 0xb6599b;
}

void	ver_inf_pi(t_env *env, t_point *p2, double angle, int *color)
{
	(*p2).x = ((int)env->x + 1);
	(*p2).y = (tan(angle * -1) * ((int)env->x + 1 - env->x) + env->y);
	if ((*p2).y < env->endy && (*p2).y >= 0 && (*p2).x > 0 && (*p2).x < env->endx)
		while (env->tab[(int)(*p2).y][(int)(*p2).x - 1] == 0 &&
				env->tab[(int)(*p2).y][(int)(*p2).x] == 0)
		{
			(*p2).x++;
			(*p2).y -= tan(angle);
			if ((*p2).y >= (env->endy - 1) || (*p2).y < 0 || (*p2).x <= 0 || (*p2).x >= env->endx)
				break ;
		}
	*color = 0x3c4ce7;
}
