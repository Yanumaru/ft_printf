/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_award.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/21 00:43:27 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/27 19:38:48 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>

t_tab			g_tab[10] =
{
	{"c", ft_print_car},
	{"s", ft_print_str},
	{"d", ft_print_num},
	{"i", ft_print_num},
	{"o", ft_print_num},
	{"u", ft_print_num},
	{"x", ft_print_num},
	{"X", ft_print_num},
	{"p", ft_print_num},
	{"b", ft_print_num}
};

int		ft_award(t_opt opt, char **str, va_list arg)
{
	int		i;
	int		flag;
	char	*cpy;
	char	*str2;

	i = -1;
	flag = 0;
	while (++i < 10)
	{
		if (**str == g_tab[i].flag[0])
		{
			cpy = g_tab[i].func(opt, arg, i);
			flag++;
		}
	}
	if (flag)
	{
		(*str)++;
		str2 = ft_strjoin(cpy, *str);
		*str = str2;
	}
	return (ft_strlen(*str));
}
