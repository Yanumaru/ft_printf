/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/23 07:30:17 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/27 18:58:07 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>

int		get_precision(char **str, va_list arg)
{
	int		value;

	value = 0;
	(*str)++;
	if (ft_isdigit(**str))
	{
		value = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
		(*str)--;
	}
	else if (**str == '*')
		value = va_arg(arg, int);
	if (value < 0)
		value *= -1;
	return (value);
}

char	*turn_off(void)
{
	int		i;
	char	*str;

	i = -1;
	if (!(str = ft_memalloc(127)))
		exit(-1);
	while (++i < 127)
		str[i] = OFF;
	return (str);
}

int		ft_isopt(char c)
{
	if (ft_strchr(OPTIONS, c))
		return (1);
	if (c == '.')
		return (2);
	if (ft_isdigit(c))
		return (3);
	return (0);
}

void	check_opt(char *get, char **str, t_opt *opt, va_list arg)
{
	unsigned int	i;

	if ((ft_isdigit(**str) && **str != '0') || **str == '*')
	{
		if (**str == '*')
			opt->width = va_arg(arg, int);
		else
		{
			opt->width = ft_atoi(*str);
			while (ft_isdigit(**str))
				(*str)++;
			(*str)--;
		}
	}
	else if (ft_isopt(**str) == 2)
	{
		get['.'] = ON;
		opt->len_prec = get_precision(str, arg);
	}
	else if (ft_isopt(**str) == 1)
	{
		i = (unsigned int)(unsigned char)**str;
		get[i] = ON;
	}
}

t_opt	get_opt(char **str, va_list arg)
{
	t_opt	tmp;

	if (!(tmp.get = ft_memalloc(127)))
		exit(-1);
	tmp.get = turn_off();
	tmp.width = 0;
	tmp.len_prec = -1;
	while (*str && ft_isopt(**str))
	{
		check_opt(tmp.get, str, &tmp, arg);
		(*str)++;
	}
	if (tmp.width < 0)
		tmp.width *= -1;
	return (tmp);
}
