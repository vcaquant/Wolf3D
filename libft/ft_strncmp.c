/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:28:10 by vcaquant          #+#    #+#             */
/*   Updated: 2015/12/03 13:47:18 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char*s3;
	unsigned char*s4;

	s3 = (unsigned char*)s1;
	s4 = (unsigned char*)s2;
	while ((*s3 || *s4) && n--)
	{
		if (*s3 != *s4)
			return (*s3 - *s4);
		s3++;
		s4++;
	}
	return (0);
}
