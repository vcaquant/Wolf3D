/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:37:23 by vcaquant          #+#    #+#             */
/*   Updated: 2015/12/03 11:56:20 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	int		t;

	i = 0;
	t = 0;
	while (i < n)
	{
		if (src[i] && !t)
			dst[i] = src[i];
		else
		{
			dst[i] = '\0';
			t = 1;
		}
		i++;
	}
	return (dst);
}
