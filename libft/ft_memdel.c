/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 14:30:11 by kmayika           #+#    #+#             */
/*   Updated: 2018/06/05 10:53:02 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	unsigned char	**str;

	str = (unsigned char **)ap;
	if (str != NULL)
	{
		free((void *)*str);
		*str = NULL;
	}
}
