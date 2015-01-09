/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/23 07:24:45 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/27 19:31:32 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		ft_clean(int size, va_list arg, char **split)
{
	split = split;
	va_end(arg);
	return (size);
}

int		ft_display(va_list arg, char **str)
{
	t_opt	opt;

	opt = get_opt(str, arg);
	return (ft_award(opt, str, arg));
}
