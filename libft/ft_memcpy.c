/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:01:08 by kmayika           #+#    #+#             */
/*   Updated: 2018/06/05 11:03:08 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			x;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	x = 0;
	while (n-- != 0)
	{
		d[x] = s[x];
		x++;
	}
	return (dst);
}
