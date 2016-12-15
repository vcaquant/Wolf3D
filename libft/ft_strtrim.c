/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:21:48 by vcaquant          #+#    #+#             */
/*   Updated: 2015/12/03 11:30:12 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		t;

	i = 0;
	if (s == NULL)
		return (NULL);
	t = ft_strlen(s);
	str = (char*)malloc(sizeof(char) * (t + 1));
	if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[t] != ' '
			&& s[t] != '\t' && s[t] != '\n')
		ft_strcpy(str, s);
	else
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		while ((s[t] == ' ' || s[t] == '\t' || s[t] == '\n'
					|| s[t] == '\0') && t != i)
			t--;
	}
	str = (char*)malloc(sizeof(char) * ((t - i) + 1));
	ft_strnncpy(str, s, i, t);
	return (str);
}
