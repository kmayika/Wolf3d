/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:01:50 by kmayika           #+#    #+#             */
/*   Updated: 2018/06/05 11:14:55 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		len;
	int		x;

	x = 0;
	len = ft_strlen(s1) + 1;
	dup = (char *)malloc(sizeof(char) * len);
	if (dup == NULL)
	{
		return (NULL);
	}
	while (s1[x])
	{
		dup[x] = s1[x];
		x++;
	}
	dup[x] = '\0';
	return (dup);
}
