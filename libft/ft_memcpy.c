/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:54:58 by vcaquant          #+#    #+#             */
/*   Updated: 2015/12/03 11:48:23 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*text;
	char	*text1;

	if (n == 0)
		return (dst);
	text = (char*)dst;
	text1 = (char*)src;
	while (n--)
		*text++ = *text1++;
	return (dst);
}
