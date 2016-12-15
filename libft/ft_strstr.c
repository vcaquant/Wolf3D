/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:54:34 by vcaquant          #+#    #+#             */
/*   Updated: 2015/11/28 17:15:10 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	n;

	if (*s2 == '\0')
		return ((char*)s1);
	n = ft_strlen(s2);
	while (*s1 != '\0')
	{
		if (*s1 == *s2 && ft_memcmp(s1, s2, n) == 0)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
