/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 17:02:42 by vcaquant          #+#    #+#             */
/*   Updated: 2016/10/31 15:41:47 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		ft_init_tab(t_env *env, char **av)
{
	char	*line;
	int		ret;
	int		x;
	int		y;

	y = 0;
	env->fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(env->fd, &line)) > 0)
	{
		x = 0;
		x = ft_count_x(line);
		env->endx = x;
		if (y == 0)
			env->xc = x;
		if (x != env->xc)
			return (-1);
		y++;
		free(line);
	}
	if (ret == -1)
		return (-1);
	env->endy = y;
	close(env->fd);
	return (1);
}

int		ft_count_x(char *str)
{
	int		count;
	int		x;

	count = 0;
	x = 0;
	while (str[x] != '\n' && str[x] != '\0')
	{
		while (str[x] == ' ')
			x++;
		if (str[x] <= '9' && str[x] >= '0')
			count++;
		x++;
	}
	return (count);
}

int		*ft_recupline(char *str)
{
	int		*tab;
	int		columns;
	int		i;
	int		j;

	j = 0;
	if (!str || str[j] == '\n' || str[j] == '\0')
		return (NULL);
	columns = ft_count_x(str);
	if (str[j] == '\n' || columns == 0)
		return (NULL);
	tab = (int*)malloc(sizeof(int) * (columns + 1));
	i = 0;
	while (str[j] != '\0' && str[j] != '\n')
	{
		while (str[j] == ' ')
			j++;
		if (str[j] <= '9' && str[j] >= '0')
			tab[i++] = ft_atoi(&str[j]);
		while (str[j] != '\0' && str[j] != '\n' && str[j] != ' ')
			j++;
	}
	return (tab);
}

void	ft_recup(t_env *env)
{
	env->yc = 0;
	while ((env->ret = get_next_line((int const)env->fd, &env->line)) > 0)
	{
		env->tab[env->yc] = ft_recupline(env->line);
		env->yc++;
		free(env->line);
	}
	close(env->fd);
	env->endy = env->yc;
}
