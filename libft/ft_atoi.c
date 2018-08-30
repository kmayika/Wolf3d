/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <kmayika@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:33:17 by kmayika           #+#    #+#             */
/*   Updated: 2018/08/28 13:30:09 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	total;
	int	sign;

	sign = 1;
	total = 0;
	while (ft_isspace(*str))
		++str;
	if (!ft_isdigit(*str))
	{
		if (*str == '-')
			sign = -1;
		else if (*str != '+')
			return (0);
		str++;
	}
	while (ft_isdigit(*str))
		total = total * 10 + (*str++ - '0') * sign;
	return (total);
}
