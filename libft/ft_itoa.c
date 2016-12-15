/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:33:11 by vcaquant          #+#    #+#             */
/*   Updated: 2015/12/07 16:12:44 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	taille(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	char	*str;
	size_t	t;
	int		neg;

	neg = negative(n);
	t = taille(n) + neg;
	str = (char*)malloc(sizeof(char) * (t + neg + 1));
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n > 0)
		n = -n;
	str[t] = '\0';
	while (t-- >= 1)
	{
		str[t] = -(n % 10) + 48;
		n /= 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
