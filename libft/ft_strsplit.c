/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 12:49:35 by kmayika           #+#    #+#             */
/*   Updated: 2018/08/13 11:23:30 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	unsigned int	x;
	int				counter;

	x = 0;
	counter = 0;
	while (s[x])
	{
		while (s[x] == c)
			x++;
		if (s[x] != '\0')
			counter++;
		while (s[x] && (s[x] != c))
			x++;
	}
	return (counter);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * n + 1);
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	int		x;
	int		i;
	int		j;
	char	**tab;

	if (!s)
		return (NULL);
	x = 0;
	i = 0;
	if ((tab = (char **)malloc(sizeof(char *)\
					* (ft_word_count(s, c)) + 1)) == NULL)
		return (NULL);
	while (s[x])
	{
		while (s[x] == c)
			x++;
		j = x;
		while (s[x] && s[x] != c)
			x++;
		if (x > j)
			tab[i++] = ft_strndup(s + j, x - j);
	}
	tab[i] = NULL;
	return (tab);
}
