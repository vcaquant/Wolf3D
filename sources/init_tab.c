/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:40:56 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/23 04:48:05 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	init_tab1(t_env *env)
{
	env->tab[0][0] = 1;
	env->tab[0][1] = 1;
	env->tab[0][2] = 1;
	env->tab[0][3] = 1;
	env->tab[0][4] = 1;
	env->tab[0][5] = 1;
	env->tab[0][6] = 1;
	env->tab[0][7] = 1;
	env->tab[0][8] = 1;
	env->tab[0][9] = 1;
	env->tab[1][0] = 1;
	env->tab[1][1] = 0;
	env->tab[1][2] = 0;
	env->tab[1][3] = 0;
	env->tab[1][4] = 0;
	env->tab[1][5] = 0;
	env->tab[1][6] = 0;
	env->tab[1][7] = 0;
	env->tab[1][8] = 0;
	env->tab[1][9] = 1;
	env->tab[2][0] = 1;
	env->tab[2][1] = 0;
	env->tab[2][2] = 0;
	env->tab[2][3] = 0;
	env->tab[2][4] = 0;
}

void	init_tab2(t_env *env)
{
	env->tab[2][5] = 0;
	env->tab[2][6] = 0;
	env->tab[2][7] = 0;
	env->tab[2][8] = 0;
	env->tab[2][9] = 1;
	env->tab[3][0] = 1;
	env->tab[3][1] = 0;
	env->tab[3][2] = 0;
	env->tab[3][3] = 0;
	env->tab[3][4] = 0;
	env->tab[3][5] = 0;
	env->tab[3][6] = 0;
	env->tab[3][7] = 0;
	env->tab[3][8] = 0;
	env->tab[3][9] = 1;
	env->tab[4][0] = 1;
	env->tab[4][1] = 0;
	env->tab[4][2] = 0;
	env->tab[4][3] = 1;
	env->tab[4][4] = 0;
	env->tab[4][5] = 0;
	env->tab[4][6] = 0;
	env->tab[4][7] = 0;
	env->tab[4][8] = 0;
	env->tab[4][9] = 1;
}

void	init_tab3(t_env *env)
{
	env->tab[5][0] = 1;
	env->tab[5][1] = 0;
	env->tab[5][2] = 0;
	env->tab[5][3] = 0;
	env->tab[5][4] = 0;
	env->tab[5][5] = 0;
	env->tab[5][6] = 0;
	env->tab[5][7] = 0;
	env->tab[5][8] = 0;
	env->tab[5][9] = 1;
	env->tab[6][0] = 1;
	env->tab[6][1] = 0;
	env->tab[6][2] = 0;
	env->tab[6][3] = 1;
	env->tab[6][4] = 0;
	env->tab[6][5] = 0;
	env->tab[6][6] = 1;
	env->tab[6][7] = 0;
	env->tab[6][8] = 0;
	env->tab[6][9] = 1;
	env->tab[7][0] = 1;
	env->tab[7][1] = 0;
	env->tab[7][2] = 0;
	env->tab[7][3] = 1;
	env->tab[7][4] = 0;
}

void	init_tab4(t_env *env)
{
	env->tab[7][5] = 0;
	env->tab[7][6] = 0;
	env->tab[7][7] = 0;
	env->tab[7][8] = 0;
	env->tab[7][9] = 1;
	env->tab[8][0] = 1;
	env->tab[8][1] = 1;
	env->tab[8][2] = 1;
	env->tab[8][3] = 1;
	env->tab[8][4] = 1;
	env->tab[8][5] = 1;
	env->tab[8][6] = 1;
	env->tab[8][7] = 1;
	env->tab[8][8] = 1;
	env->tab[8][9] = 1;
}
