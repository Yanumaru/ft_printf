/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 10:20:53 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/27 14:20:55 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (*(str + i))
		i++;
	return (i);
}
