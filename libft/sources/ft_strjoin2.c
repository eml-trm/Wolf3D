/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 12:13:28 by etermeau          #+#    #+#             */
/*   Updated: 2015/05/07 12:13:30 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin2(char **s1, char *s2)
{
	char	*tmp;

	tmp = NULL;
	if (*s1 && s2)
	{
		tmp = (char *)malloc(ft_strlen(*s1) + ft_strlen(s2) + 1);
		if (!tmp)
			return (NULL);
		tmp = ft_strcpy(tmp, *s1);
		tmp = ft_strcat(tmp, s2);
		tmp[ft_strlen(*s1) + ft_strlen(s2) + 1] = '\0';
	}
	if (s2)
		free((char *)s2);
	return (tmp);
}
