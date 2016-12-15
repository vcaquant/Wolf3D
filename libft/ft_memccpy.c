/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:08:57 by vcaquant          #+#    #+#             */
/*   Updated: 2015/12/03 11:49:11 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*text;
	unsigned char	*text1;

	if (n == 0)
		return (NULL);
	text = (unsigned char *)dst;
	text1 = (unsigned char *)src;
	while (n--)
	{
		*text = *text1;
		if (*text1 == (unsigned char)c)
			return (text + 1);
		text++;
		text1++;
	}
	return (NULL);
}
