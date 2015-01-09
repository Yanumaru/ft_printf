/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/24 12:14:31 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/27 20:58:01 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"
#include <libft.h>

int		check_arg(va_list arg)
{
	char	*value_of_ptr;
	va_list	arg2;
	int		value_of_return;

	value_of_return = ON;
	va_copy(arg2, arg);
	value_of_ptr = va_arg(arg2, char*);
	if (!value_of_ptr)
		value_of_return = OFF;
	else if (!*value_of_ptr)
		value_of_return = 0;
	va_end(arg2);
	return (value_of_return);
}

char	*fill(char c, int len)
{
	char	*str;
	int		i;

	i = -1;
	if (!(str = ft_memalloc(len + 1)))
		exit(-1);
	while (++i < len)
		str[i] = c;
	str[i] = '\0';
	return (str);
}

char	*continue_to_print(char *str, t_opt opt)
{
	char	f;

	if (opt.width > 1 && (unsigned int)opt.width > ft_strlen(str))
	{
		f = opt.get['0'] == ON ? '0' : ' ';
		if (opt.get['-'] == ON)
			str = ft_strjoin(str, fill(' ', opt.width - (int)ft_strlen(str)));
		else
			str = ft_strjoin(fill(f, opt.width - (int)ft_strlen(str)), str);
		if (str == NULL)
			exit(-1);
	}
	return (str);
}

char	*ft_print_str(t_opt opt, va_list arg, int f)
{
	char	*s;

	f = check_arg(arg);
	if (f == 0)
		return (NULL);
	if (opt.get['l'] == ON)
		exit(-1);
	if (opt.get['.'] == ON && opt.len_prec < 1)
	{
		if (!(s = ft_memalloc(1)))
			exit(-1);
		*s = '\0';
	}
	else if (opt.get['.'] == ON && opt.len_prec > 0)
	{
		s = f == OFF ? ft_strdup("(null)") : ft_strdup(va_arg(arg, char *));
		if ((unsigned int)opt.len_prec < ft_strlen(s))
			s = ft_strsub(s, 0, (size_t)opt.len_prec);
	}
	else
		s = f == OFF ? ft_strdup("(null)") : ft_strdup(va_arg(arg, char *));
	return (continue_to_print(s, opt));
}
