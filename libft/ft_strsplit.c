/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:22:35 by vcaquant          #+#    #+#             */
/*   Updated: 2015/12/07 16:13:20 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	t_mot(char const *s, char c)
{
	int	t;
	int	i;

	t = 0;
	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
		t++;
	}
	return (t);
}

static int	nbr_mots(char const *s, char c)
{
	int	t;
	int	i;
	int	nbr;

	t = 0;
	i = 0;
	nbr = 0;
	while (s[t] != '\0')
	{
		if (i == 1 && s[t] == c)
			i = 0;
		if (i == 0 && s[t] != c)
		{
			i = 1;
			nbr++;
		}
		t++;
	}
	return (nbr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		t;

	t = nbr_mots(s, c);
	i = 0;
	if (s == NULL)
		return (NULL);
	tab = (char**)malloc(sizeof(*tab) * t + 1);
	if (tab == NULL)
		return (NULL);
	while (t--)
	{
		while (*s == c && *s)
			s++;
		tab[i] = ft_strsub(s, 0, t_mot(s, c));
		s = s + t_mot(s, c);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
