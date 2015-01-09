/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/21 08:06:20 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/27 19:32:06 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>
#include <unistd.h>

int		ft_find(const char *format)
{
	int	i;

	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
			return (i);
	}
	return (-1);
}

int		ft_print_percent(const char *format)
{
	int	i;
	int	f;

	i = -1;
	f = ft_find(format);
	while (format[++i])
	{
		if (i != f)
			write(1, &format[i], 1);
	}
	return (i - 1);
}

int		ft_print_std(const char *format)
{
	write(1, format, ft_strlen(format));
	return (ft_strlen(format));
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		flag;
	int		size;
	char	**split;
	va_list	arg;

	i = -1;
	size = 0;
	va_start(arg, format);
	if (!ft_strchr(format, '%'))
		return (ft_print_std(format));
	flag = (format[0] == '%') ? 1 : 0;
	if (ft_find(format) != -1)
		return (ft_print_percent(format));
	if (!(split = ft_strsplit(format, '%')))
		return (size);
	while (split[++i])
	{
		if (i != 0 || flag)
			ft_display(arg, &split[i]);
		ft_putstr(split[i]);
		size += ft_strlen(split[i]);
	}
	return (ft_clean(size, arg, split));
}
