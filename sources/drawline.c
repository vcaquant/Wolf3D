/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:57:21 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/23 19:52:19 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf.h"

void	other_cadran(t_drawline *draw, t_env *env)
{
	if (draw->dx < 0 && draw->dy > 0 && -(draw->dx) < draw->dy)
		cadran3_a(draw, env);
	else if (draw->dx < 0 && draw->dy > 0 && -(draw->dx) >= draw->dy)
		cadran3_b(draw, env);
	else if (draw->dx < 0 && draw->dy < 0 && draw->dx <= draw->dy)
		cadran4_a(draw, env);
	else if (draw->dx < 0 && draw->dy < 0 && draw->dx > draw->dy)
		cadran4_b(draw, env);
	else if (draw->dx == 0 && draw->dy > 0)
		(dx_null_a(draw, env));
	else if (draw->dx == 0 && draw->dy < 0)
		(dx_null_b(draw, env));
	else if (draw->dy == 0 && draw->dx > 0)
		(dy_null_a(draw, env));
	else if (draw->dy == 0 && draw->dx < 0)
		(dy_null_b(draw, env));
	else
		ft_color(env, (int)draw->x1, (int)draw->y1);
}

void	ft_drawline(t_env *env, t_point p1, t_point p2)
{
	t_drawline	*draw;

	draw = malloc(sizeof(t_drawline));
	draw->x1 = p1.x;
	draw->x2 = p2.x;
	draw->y1 = p1.y;
	draw->y2 = p2.y;
	draw->dx = p2.x - p1.x;
	draw->dy = p2.y - p1.y;
	if (draw->dx > 0 && draw->dy < 0 && draw->dx < -(draw->dy))
		cadran1_a(draw, env);
	else if (draw->dx > 0 && draw->dy < 0 && draw->dx >= -(draw->dy))
		cadran1_b(draw, env);
	else if (draw->dx > 0 && draw->dy > 0 && draw->dx >= draw->dy)
		cadran2_a(draw, env);
	else if (draw->dx > 0 && draw->dy > 0 && draw->dx < draw->dy)
		cadran2_b(draw, env);
	else
		other_cadran(draw, env);
	free(draw);
}
