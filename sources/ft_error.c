/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:24:33 by vcaquant          #+#    #+#             */
/*   Updated: 2016/12/23 13:33:27 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		verify2(t_env *env)
{
	if (env->endx < 3 || env->endy < 3)
		return (-1);
	while (env->tab[(int)env->y][(int)env->x] != 0)
	{
		if (env->x < env->endx - 1)
			env->x++;
		else
		{
			env->x = 1.5;
			if (env->y < env->endy - 2)
				env->y++;
			else
				return (-1);
		}
	}
	return (1);
}

int		verify(t_env *env)
{
	int		x;
	int		y;

	y = env->endy - 1;
	while (y >= 0)
	{
		x = env->endx - 1;
		while (x >= 0)
		{
			if (y == 0 && env->tab[y][x] != 1)
				return (-1);
			else if (y == env->endy - 1 && env->tab[y][x] != 1)
				return (-1);
			else if (x == 0 && env->tab[y][x] != 1)
				return (-1);
			else if (x == env->endx - 1 && env->tab[y][x] != 1)
				return (-1);
			x--;
		}
		y--;
	}
	if (verify2(env) == -1)
		return (-1);
	return (1);
}

int		ft_error(void)
{
	ft_putstr("Invalid File. Please chose a valid file in map directory\n");
	return (-1);
}

int		ft_error2(void)
{
	ft_putstr("error syntax : ./wolf3d <valid file>\n");
	return (-1);
}
