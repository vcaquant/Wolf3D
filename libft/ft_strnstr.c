/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 23:25:31 by vcaquant          #+#    #+#             */
/*   Updated: 2015/11/28 17:14:54 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	t;

	if (*s2 == '\0')
		return ((char*)s1);
	t = ft_strlen(s2);
	while (n-- >= t && *s1 != '\0')
	{
		if (*s1 == *s2 && ft_memcmp(s1, s2, t) == 0)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
