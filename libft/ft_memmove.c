/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:20:14 by kmayika           #+#    #+#             */
/*   Updated: 2018/06/05 13:03:21 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_memcpy_rev(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			x;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	x = n;
	while (x > 0)
	{
		d[x - 1] = s[x - 1];
		--x;
	}
	return (dst);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
		ft_memcpy_rev(dst, src, len);
	return ((void *)dst);
}
