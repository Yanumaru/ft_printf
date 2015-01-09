/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 06:15:25 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/27 19:33:26 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>

void	continue_itoa(int n, char *str, int b, char *base)
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
		continue_itoa(n / b, str, b, base);
		continue_itoa(n % b, str, b, base);
	}
}

char	*itoa(char *base, int n)
{
	int		i;
	int		b;
	int		save;
	char	*str;

	i = 0;
	save = n;
	save = save < 0 ? save : save * -1;
	b = (int)ft_strlen(base);
	while (save >= b)
	{
		save /= b;
		i++;
	}
	if (!(str = ft_memalloc(i + 1)))
		exit(-1);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	continue_itoa(n, str, b, base);
	return (str);
}
