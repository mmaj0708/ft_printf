/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:48:08 by mmaj              #+#    #+#             */
/*   Updated: 2020/02/26 15:48:19 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_strcpy(char *dst, char *src)
{
	size_t		i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ;
}

char			*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*new;

	i = ft_strlen(s1);
	if ((!s1) && (!s2))
		return (NULL);
	if (!(new = malloc(sizeof(new)
		* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	if (s1 != NULL)
		ft_strcpy(new, s1);
	if (s2 != NULL)
	{
		ft_strcpy(&new[i], s2);
		free(s2);
		s2 = NULL;
	}
	free(s1);
	s1 = NULL;
	return (new);
}
