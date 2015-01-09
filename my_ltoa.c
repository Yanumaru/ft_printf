/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 08:11:10 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/27 19:34:59 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>

void	continue_ltoa(long int n, char *str, long int b, char *base)
{
	char	buf[2];

	if (n < 0)
	{
		n *= -1;
		str = ft_strcat(str, "-");
	}
	if (n < b)
	{
		buf[0] = base[n];
		buf[1] = '\0';
		str = ft_strcat(str, buf);
	}
	else
	{
		continue_ltoa(n / b, str, b, base);
		continue_ltoa(n % b, str, b, base);
	}
}

char	*ltoa(char *base, long int n)
{
	long int		i;
	long int		b;
	long int		save;
	char			*str;

	i = 0;
	save = n;
	save = save < 0 ? save : save * -1;
	b = (long int)ft_strlen(base);
	while (save >= b)
	{
		save /= b;
		i++;
	}
	if (!(str = ft_memalloc(i + 1)))
		exit(-1);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	continue_ltoa(n, str, b, base);
	return (str);
}
