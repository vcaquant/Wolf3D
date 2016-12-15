/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:30:56 by vcaquant          #+#    #+#             */
/*   Updated: 2015/12/03 13:47:37 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char*ft_strnncpy(char *dst, const char *src, int ndeb, int nfin)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (ndeb <= nfin)
	{
		if (!t)
			dst[i] = src[ndeb];
		else
		{
			dst[i] = '\0';
			t = 1;
		}
		ndeb++;
		i++;
	}
	return (dst);
}
