/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:06:19 by kmayika           #+#    #+#             */
/*   Updated: 2018/06/05 11:47:31 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	x;
	unsigned int	i;
	unsigned int	j;
	char			*new;

	if (!s)
		return (NULL);
	x = 0;
	j = 0;
	while (s[x] == ' ' || s[x] == '\n' || s[x] == '\t')
		x++;
	if (s[x] == '\0')
		return (ft_strcpy(ft_memalloc(sizeof(char) * 2), ""));
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	if ((new = (char *)malloc(sizeof(char) * (i - x + 2))) == NULL)
		return (NULL);
	while (j < i - x + 1)
	{
		new[j] = s[x + j];
		j++;
	}
	new[j] = '\0';
	return (new);
}
