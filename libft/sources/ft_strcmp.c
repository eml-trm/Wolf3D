/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:32:23 by etermeau          #+#    #+#             */
/*   Updated: 2015/01/08 18:00:35 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *str1, const char *str2)
{
	char	*s1;
	char	*s2;

	s1 = (char *)str1;
	s2 = (char *)str2;
	while (*s1)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - *s2);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - *s2);
}
