/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:23:06 by ykichena          #+#    #+#             */
/*   Updated: 2014/10/27 12:09:50 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		i;
	char	*p;

	if (!*s || s == NULL)
		return (NULL);
	if ((p = (char *)malloc((ft_strlen(s)) * sizeof(char))))
	{
		i = 0;
		while (s[i] != '\0')
		{
			p[i] = s[i];
			i++;
		}
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}
