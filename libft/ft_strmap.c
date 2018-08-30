/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 12:10:03 by kmayika           #+#    #+#             */
/*   Updated: 2018/06/05 10:48:15 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	size_t	len;
	size_t	x;

	if (!s || !f)
		return (NULL);
	x = 0;
	len = ft_strlen(s) + 1;
	new = (char *)malloc(sizeof(char) * len);
	if (new == NULL)
	{
		return (NULL);
	}
	while (s[x] != '\0')
	{
		new[x] = f(s[x]);
		x++;
	}
	new[x] = '\0';
	return ((char *)new);
}
