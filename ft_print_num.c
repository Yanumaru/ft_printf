/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/24 13:07:31 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/27 19:36:44 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>

char	*give_base(int flag)
{
	char	*base;

	if (flag == 4)
		base = ft_strdup("01234567");
	else if (flag == 6 || flag == 8)
		base = ft_strdup("0123456789abcdef");
	else if (flag == 7)
		base = ft_strdup("0123456789ABCDEF");
	else if (flag == 9)
		base = ft_strdup("01");
	else
		base = ft_strdup("0123456789");
	if (base == NULL)
		exit(-1);
	return (base);
}

char	*ul(int flag, char *base, va_list arg)
{
	char	*str;

	if (flag == 5)
		str = ultoa(base, va_arg(arg, unsigned long));
	else
		str = ltoa(base, va_arg(arg, long int));
	return (str);
}

char	*ft_print_num(t_opt opt, va_list arg, int flag)
{
	char	*str;
	char	*base;
	int		n;

	base = give_base(flag);
	if (opt.get['l'] == ON)
		str = ul(flag, base, arg);
	else
	{
		if (flag == 4 || (flag >= 6 && flag <= 8))
		{
			if (flag == 8)
				str = ft_strjoin("0x", ultoa(base, va_arg(arg, long)));
			else
			{
				n = va_arg(arg, int);
				str = uitoa(base, n);
			}
		}
		else if (flag == 5)
			str = uitoa(base, va_arg(arg, unsigned int));
		else
			str = itoa(base, va_arg(arg, int));
	}
	return (continue_to_print_p2(str, opt, flag));
}
