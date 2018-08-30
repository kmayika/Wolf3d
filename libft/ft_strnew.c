/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:02:04 by kmayika           #+#    #+#             */
/*   Updated: 2018/05/31 16:25:14 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	new = (char *)malloc(size + 1);
	if (new != NULL)
	{
		ft_memset(new, 0, size + 1);
		return ((char *)new);
	}
	return (NULL);
}
