/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:16:54 by vcaquant          #+#    #+#             */
/*   Updated: 2015/11/27 06:48:03 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while ((unsigned char *)s != '\0' && n--)
	{
		if ((*(unsigned char *)s) == (unsigned char)c)
			return ((void*)s);
		s++;
	}
	return (NULL);
}
