/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:45:48 by kmayika           #+#    #+#             */
/*   Updated: 2018/06/05 10:46:23 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	i;
	size_t	len;

	x = 0;
	i = 0;
	while (dst[x] != '\0' && x < dstsize)
	{
		x++;
	}
	while (src[i] != '\0' && (x + i + 1) < dstsize)
	{
		dst[x + i] = src[i];
		i++;
	}
	if (x != dstsize)
	{
		dst[x + i] = '\0';
	}
	len = ft_strlen(src);
	return (x + len);
}
