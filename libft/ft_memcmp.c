/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:33:04 by vcaquant          #+#    #+#             */
/*   Updated: 2015/11/27 09:14:31 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*text;
	unsigned char	*text1;
	int				i;

	i = 0;
	text = (unsigned char*)s1;
	text1 = (unsigned char*)s2;
	while (n--)
	{
		if (text[i] != text1[i])
			return (text[i] - text1[i]);
		i++;
	}
	return (0);
}
