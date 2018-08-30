/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 13:19:18 by kmayika           #+#    #+#             */
/*   Updated: 2018/06/05 11:18:07 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	x;
	unsigned char	*new;

	if (!s)
		return (NULL);
	x = 0;
	new = (unsigned char *)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
	{
		return (NULL);
	}
	while (x < len)
	{
		new[x] = s[start + x];
		x++;
	}
	new[x] = '\0';
	return ((char *)new);
}
