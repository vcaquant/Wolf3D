/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:40:54 by vcaquant          #+#    #+#             */
/*   Updated: 2016/05/12 14:47:44 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sleep(void)
{
	usleep(200000);
	system("clear");
}

void	ft_wait(void)
{
	int	i;

	i = 0;
	while (i != 2)
	{
		ft_putstr("[\033[0;31m|\033[0;33m] Wait a minute");
		ft_sleep();
		ft_putstr("[\033[0;31m/\033[0;33m] Wait a minute");
		ft_sleep();
		ft_putstr("[\033[0;31m-\033[0;33m] Wait a minute");
		ft_sleep();
		ft_putstr("[\033[0;31m\\\033[0;33m] Wait a minute");
		ft_sleep();
		ft_putstr("[\033[0;31m|\033[0;33m] Wait a minute");
		ft_sleep();
		ft_putstr("[\033[0;31m/\033[0;33m] Wait a minute");
		ft_sleep();
		ft_putstr("[\033[0;31m-\033[0;33m] Wait a minute");
		ft_sleep();
		ft_putstr("[\033[0;31m\\\033[0;33m] Wait a minute");
		ft_sleep();
		i++;
	}
}
