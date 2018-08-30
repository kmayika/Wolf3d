/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 10:47:58 by kmayika           #+#    #+#             */
/*   Updated: 2018/05/23 11:02:03 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	x;

	x = 0;
	while (src[x] != '\0' && x < len)
	{
		dest[x] = src[x];
		x++;
	}
	while (x < len)
	{
		dest[x] = '\0';
		x++;
	}
	return (dest);
}
