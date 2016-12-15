/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:20:11 by vcaquant          #+#    #+#             */
/*   Updated: 2015/12/03 11:50:37 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*text;

	text = (unsigned char*)malloc(sizeof(char) * len);
	ft_memcpy(text, src, len);
	ft_memcpy(dst, text, len);
	free(text);
	return (dst);
}
