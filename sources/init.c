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

void	freetab(t_env *env)
{
	int		y;

	y = 0;
	while (y < env->endy)
	{
		free(env->tab[y]);
		y++;
	}
	free(env->tab);
}

void	img_init(t_env *env)
{
	env->img = malloc(sizeof(t_img));
	env->img->ptr_img = mlx_new_image(env->mlx, W_X, W_Y);
	env->img->bts_img = mlx_get_data_addr(env->img->ptr_img,
		&(env->img->bpp), &(env->img->size_line), &(env->img->end));
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
