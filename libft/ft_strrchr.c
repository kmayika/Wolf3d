/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:47:36 by kmayika           #+#    #+#             */
/*   Updated: 2018/06/05 13:41:41 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*str;
	int				len;

	str = (unsigned char *)s;
	len = ft_strlen(s);
	str += len;
	if (str == NULL)
		return (NULL);
	while (len-- && *str != c)
		str--;
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (NULL);
}
