/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:58:31 by kmayika           #+#    #+#             */
/*   Updated: 2018/06/05 11:30:59 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*new;

	new = (unsigned char *)malloc(size);
	if (new == NULL)
	{
		return (NULL);
	}
	while (size)
	{
		ft_memset(new, 0, size);
		return (new);
	}
	return (NULL);
}
