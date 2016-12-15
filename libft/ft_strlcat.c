/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:31:43 by vcaquant          #+#    #+#             */
/*   Updated: 2015/11/30 11:31:40 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	t;
	size_t	fin;

	t = 0;
	while (dst[t] && t < size)
		t++;
	fin = t;
	while (src[t - fin] && t < size - 1)
	{
		dst[t] = src[t - fin];
		t++;
	}
	if (fin < size)
		dst[t] = '\0';
	return (fin + ft_strlen(src));
}
