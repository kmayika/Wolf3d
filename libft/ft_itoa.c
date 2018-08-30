/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:27:19 by kmayika           #+#    #+#             */
/*   Updated: 2018/06/05 10:30:31 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*new;

	if (!(new = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(new, "-2147483648"));
	if (n < 0)
	{
		new[0] = '-';
		new[1] = '\0';
		new = ft_strjoin(new, ft_itoa(-n));
	}
	else if (n >= 10)
		new = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n < 10 && n >= 0)
	{
		new[0] = n + '0';
		new[1] = '\0';
	}
	return (new);
}
