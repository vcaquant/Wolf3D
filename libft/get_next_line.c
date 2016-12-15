/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:16:00 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/16 21:47:39 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_first(char *str, int n)
{
	char	*new;

	new = ft_strdup(str + n + 1);
	free(str);
	return (new);
}

int		ft_init(t_g **g)
{
	if (*g == NULL)
	{
		if (!(*g = (t_g*)malloc(sizeof(t_g))))
			return (0);
		(*g)->ret = 0;
		if (!((*g)->save = ft_strnew(BUFF_SIZE + 1)))
			return (0);
	}
	else if ((*g)->save == NULL)
	{
		if (!((*g)->save = ft_strnew(BUFF_SIZE + 1)))
			return (0);
	}
	return (1);
}

char	*ft_tmp(char *save, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(save, buff);
	free(save);
	save = tmp;
	return (save);
}

char	*ft_line(t_g **g, char *line)
{
	if (ft_strchr((*g)->save, '\n'))
	{
		line = ft_strsub((*g)->save, 0, ft_strclen((*g)->save, '\n'));
		(*g)->save = ft_free_first((*g)->save, ft_strclen((*g)->save, '\n'));
	}
	else
	{
		line = ft_strsub((*g)->save, 0, ft_strlen((*g)->save));
		ft_bzero((*g)->save, ft_strlen((*g)->save));
	}
	return (line);
}

int		get_next_line(int const fd, char **line)
{
	static t_g		*g = NULL;

	if (!ft_init(&g) || (BUFF_SIZE <= 0) || !line)
		return (-1);
	while (!ft_strchr(g->save, '\n'))
	{
		ft_bzero(g->buff, BUFF_SIZE + 1);
		if ((g->ret = read(fd, g->buff, BUFF_SIZE)) > 0)
			g->save = ft_tmp(g->save, g->buff);
		else if ((g->ret = read(fd, g->buff, BUFF_SIZE)) == -1)
			return (-1);
		else
			break ;
	}
	if (g->ret < 0)
		return (-1);
	if (g->ret == 0 && g->save[0] == '\0')
	{
		*line = NULL;
		ft_strdel(&(g->save));
		ft_memdel((void**)&g);
		return (0);
	}
	*line = ft_line(&g, *line);
	return (1);
}
