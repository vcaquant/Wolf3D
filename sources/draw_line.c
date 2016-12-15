/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:42:58 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/23 09:56:57 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf.h"

void	init_point(t_env *env, t_point *p1, t_point *p2, t_point *p3)
{
	(*p2).x = 0;
	(*p3).x = 0;
	(*p2).y = 0;
	(*p3).y = 0;
	(*p1).x = env->x / 10 * W_X;
	(*p1).y = env->y / 9 * W_Y;
}

void	change_point(t_point *p2, t_point *p3)
{
	(*p2).x = (*p2).x / 10 * W_X;
	(*p2).y = (*p2).y / 9 * W_Y;
	(*p3).x = (*p3).x / 10 * W_X;
	(*p3).y = (*p3).y / 9 * W_Y;
}

double	draw_line(t_env *env, double angle, int *color)
{
	int		t;
	t_point	p;
	t_point	p2;
	t_point	p3;
	int		col;

	t = 0;
	init_point(env, &p, &p2, &p3);
	(angle > 0 && angle < M_PI) ? t = hor_sup_z(env, &p3, angle, &col) :
		(t = hor_inf_z(env, &p3, angle, &col));
	(angle >= M_PI / 2 && angle < 3 * M_PI / 2) ?
		ver_sup_pi(env, &p2, angle, color) : ver_inf_pi(env, &p2, angle, color);
	change_point(&p2, &p3);
	if (t == 1 || sqrt((p.x - p2.x) * (p.x - p2.x) + (p.y - p2.y) *
(p.y - p2.y)) < sqrt((p.x - p3.x) * (p.x - p3.x) + (p.y - p3.y) * (p.y - p3.y)))
		return (sqrt((p.x - p2.x) * (p.x - p2.x) +
					(p.y - p2.y) * (p.y - p2.y)));
	else
	{
		*color = col;
		return (sqrt((p.x - p3.x) * (p.x - p3.x) +
			(p.y - p3.y) * (p.y - p3.y)));
	}
}
