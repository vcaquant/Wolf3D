/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_balader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 09:58:29 by vcaquant          #+#    #+#             */
/*   Updated: 2016/12/23 14:00:00 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		hor_sup_z(t_env *env, t_point *p3, double angle, int *color)
{
	(*p3).y = ((int)env->y);
	(*p3).x = ((env->y - (int)env->y) / tan(angle) + env->x);
	if ((*p3).y >= (env->endy - 1) || (*p3).y < 0 || (*p3).x < 0
			|| (*p3).x >= env->endx)
		return (1);
	else
		while (env->tab[(int)(*p3).y - 1][(int)(*p3).x] == 0 &&
				env->tab[(int)(*p3).y][(int)(*p3).x] == 0)
		{
			(*p3).y--;
			(*p3).x += 1 / tan(angle);
			if ((*p3).y >= env->endy || (*p3).y <= 0 || (*p3).x < 0
					|| (*p3).x >= env->endx)
				return (1);
		}
	*color = 0xe74c3c;
	return (0);
}

int		hor_inf_z(t_env *env, t_point *p3, double angle, int *color)
{
	(*p3).y = ((int)env->y + 1);
	(*p3).x = ((((int)env->y + 1) - env->y) / tan(-1 * angle) + env->x);
	if ((*p3).y >= env->endy || (*p3).y <= 0 || (*p3).x < 0
			|| (*p3).x >= (env->endx - 1))
		return (1);
	else
		while (env->tab[(int)(*p3).y - 1][(int)(*p3).x] == 0 &&
				env->tab[(int)(*p3).y][(int)(*p3).x] == 0)
		{
			(*p3).y++;
			(*p3).x += -1 / tan(angle);
			if ((*p3).y >= env->endy || (*p3).y <= 0 || (*p3).x < 0
					|| (*p3).x >= env->endx)
				return (1);
		}
	*color = 0x71cc2e;
	return (0);
}

void	ver_sup_pi(t_env *env, t_point *p2, double angle, int *color)
{
	(*p2).x = ((int)env->x);
	(*p2).y = (tan(angle) * (env->x - (int)env->x) + env->y);
	if ((*p2).y < env->endy && (*p2).y >= 0 && (*p2).x > 0
			&& (*p2).x < env->endx)
		while (env->tab[(int)(*p2).y][(int)(*p2).x - 1] == 0 &&
				env->tab[(int)(*p2).y][(int)(*p2).x] == 0)
		{
			(*p2).x--;
			(*p2).y += tan(angle);
			if ((*p2).y >= env->endy || (*p2).y < 0 || (*p2).x < 0
					|| (*p2).x >= (env->endx - 1))
				break ;
		}
	*color = 0xb6599b;
}

void	ver_inf_pi(t_env *env, t_point *p2, double angle, int *color)
{
	(*p2).x = ((int)env->x + 1);
	(*p2).y = (tan(angle * -1) * ((int)env->x + 1 - env->x) + env->y);
	if ((*p2).y < env->endy && (*p2).y >= 0 && (*p2).x > 0
			&& (*p2).x < env->endx)
		while (env->tab[(int)(*p2).y][(int)(*p2).x - 1] == 0 &&
				env->tab[(int)(*p2).y][(int)(*p2).x] == 0)
		{
			(*p2).x++;
			(*p2).y -= tan(angle);
			if ((*p2).y >= (env->endy - 1) || (*p2).y < 0 || (*p2).x <= 0
					|| (*p2).x >= env->endx)
				break ;
		}
	*color = 0x3c4ce7;
}
