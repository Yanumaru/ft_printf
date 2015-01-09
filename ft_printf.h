/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/13 16:01:12 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/27 16:50:32 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ON 1
# define OFF 2
# define OPTIONS "# +-0*vhlLn"
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_flag
{
	int			space;
	int			num;
	char		sharp;
	char		sum;
	char		sub;
}				t_flag;

typedef struct	s_opt
{
	char		*get;
	int			width;
	int			len_prec;
}				t_opt;

typedef struct	s_tab
{
	char		*flag;
	char		*(*func) (t_opt, va_list, int);
}				t_tab;

char			*uitoa(char *base, unsigned int n);
char			*ltoa(char *base, long int n);
char			*ultoa(char *base, unsigned long n);
char			*itoa(char *base, int n);
char			*continue_to_print_p2(char *str, t_opt opt, int flag);
char			*fill(char c, int len);
char			*ft_print_num(t_opt opt, va_list arg, int flag);
char			*ft_print_str(t_opt opt, va_list arg, int flag);
char			*ft_print_car(t_opt opt, va_list arg, int flag);
int				ft_display(va_list arg, char **str);
int				ft_clean(int size, va_list arg, char **split);
int				ft_award(t_opt opt, char **str, va_list arg);
t_opt			get_opt(char **str, va_list arg);

#endif
