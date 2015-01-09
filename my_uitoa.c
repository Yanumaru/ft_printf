/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 08:11:35 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/27 19:37:57 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>

void	continue_uitoa(unsigned int n, char *str, unsigned int b, char *base)
{
	char	buf[2];

	if (n < b)
	{
		buf[0] = base[n];
		buf[1] = '\0';
		str = ft_strcat(str, buf);
	}
	else
	{
		continue_uitoa(n / b, str, b, base);
		continue_uitoa(n % b, str, b, base);
	}
}

char	*uitoa(char *base, unsigned int n)
{
	unsigned int		i;
	unsigned int		b;
	unsigned int		save;
	char				*str;

	i = 0;
	save = n;
	b = ft_strlen(base);
	while (save >= b)
	{
		save /= b;
		i++;
	}
	if (!(str = ft_memalloc(i + 1)))
		exit(-1);
	continue_uitoa(n, str, b, base);
	return (str);
}
