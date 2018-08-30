/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 10:49:59 by kmayika           #+#    #+#             */
/*   Updated: 2018/06/05 13:31:24 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*src;
	unsigned char	*dst;

	dst = (unsigned char *)s1;
	src = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (--n && *src != '\0')
	{
		if (*dst != *src)
		{
			return (*dst - *src);
		}
		dst++;
		src++;
	}
	return (*dst - *src);
}
