/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 15:40:42 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/27 14:26:25 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		length;

	length = ft_strlen(s1) + ft_strlen(s2);
	str = ft_strnew(length + 1);
	i = 0;
	while (i < length)
	{
		if (s1 && *s1)
		{
			str[i] = *s1;
			s1++;
		}
		else if (s2 && *s2)
		{
			str[i] = *s2;
			s2++;
		}
		i++;
	}
	str[i] = '\0';
	return (str);
}
