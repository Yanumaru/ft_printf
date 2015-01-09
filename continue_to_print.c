/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   continue_to_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/25 09:14:27 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/27 19:35:52 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>

char	*end_print(char *str, t_opt opt)
{
	char	f;

	if (opt.width > 1 && opt.width > (int)ft_strlen(str))
	{
		f = (opt.get['0'] == ON) ? '0' : ' ';
		if (opt.get['-'] == ON)
			str = ft_strjoin(str, fill(' ', opt.width - (int)ft_strlen(str)));
		else
			str = ft_strjoin(fill(f, opt.width - (int)ft_strlen(str)), str);
	}
	return (str);
}

char	*print_precision(char *str, t_opt opt)
{
	int	f;

	f = 0;
	if ((opt.get['+'] == ON && *str != '-')
		|| (opt.width == 0 && opt.get[' '] == ON && *str != '-'))
		f++;
	if (opt.len_prec > ((int)ft_strlen(str) + f))
		return (str);
	else
		str = ft_strsub(str, 0, (size_t)opt.len_prec);
	return (str);
}

char	*continue_to_print_p2(char *str, t_opt opt, int flag)
{
	flag = flag;
	if (opt.get['.'] == ON)
		str = print_precision(str, opt);
	if (opt.get['+'] == ON && *str != '-')
		str = ft_strjoin("+", str);
	else if (opt.width == 0 && opt.get[' '] == ON && *str != '-')
		str = ft_strjoin(" ", str);
	return (end_print(str, opt));
}
