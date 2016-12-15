/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:35:34 by vcaquant          #+#    #+#             */
/*   Updated: 2015/12/03 11:44:04 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
			&& (unsigned char)s1[i] != '\0' && (unsigned char)s2[i] != '\0')
		i++;
	return ((int)(unsigned char)s1[i] - (unsigned char)s2[i]);
}
