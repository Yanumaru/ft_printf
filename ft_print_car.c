/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_car.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/24 03:41:08 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/27 12:55:32 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>

void	fill_to_empty(char *str, int len, va_list arg)
{
	int	i;

	i = 0;
	str[0] = va_arg(arg, int);
	while (++i < len)
		str[i] = ' ';
	str[i] = '\0';
}

void	empty_to_fill(char *str, char c, int len, va_list arg)
{
	int	i;

	i = -1;
	while (++i < len)
		str[i] = c;
	str[i] = va_arg(arg, int);
	str[i] = '\0';
}

char	*ft_print_car(t_opt opt, va_list arg, int flag)
{
	char	*str;
	char	fill;

	flag = flag;
	if (opt.width > 1)
	{
		if (!(str = ft_memalloc(2 + opt.width)))
			exit(-1);
		fill = opt.get['0'] == ON ? '0' : ' ';
		if (opt.get['-'] == ON)
			fill_to_empty(str, opt.width, arg);
		else
			empty_to_fill(str, fill, opt.width, arg);
	}
	else
	{
		if (!(str = ft_memalloc(2)))
			exit(-1);
		if ((str[0] = va_arg(arg, int)))
			str[1] = '\0';
	}
	return (str);
}
