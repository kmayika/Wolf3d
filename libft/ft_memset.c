/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:17:59 by kmayika           #+#    #+#             */
/*   Updated: 2018/06/05 10:49:33 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			x;

	x = 0;
	str = (unsigned char *)b;
	while (len-- != 0)
	{
		str[x] = (unsigned char)c;
		x++;
	}
	return (b);
}
