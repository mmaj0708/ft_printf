/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:18:45 by mmaj              #+#    #+#             */
/*   Updated: 2020/02/26 15:48:04 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_strlen_int(long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(long n)
{
	long			nb;
	size_t			i;
	char			*str;

	if (!(str = ft_calloc(sizeof(char) * (ft_strlen_int(n) + 1), 1)))
		return (NULL);
	nb = n;
	if (n < 0)
	{
		str[0] = '-';
		nb = -n;
	}
	i = ft_strlen_int(n) - 1;
	if (n == 0)
		str[i] = 48;
	while (nb != 0)
	{
		str[i] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	return (str);
}

int				ft_strlen_base(long n, int taille_base)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / taille_base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(long n, char *base)
{
	unsigned long		nb;
	size_t				i;
	char				*str;
	int					taille_base;

	if (!(str = ft_calloc(sizeof(char) * (ft_strlen_int(n) + 1), 1)))
		return (NULL);
	nb = n;
	taille_base = ft_strlen(base);
	if (n < 0)
	{
		str[0] = '-';
		nb = -n;
	}
	i = ft_strlen_base(n, taille_base) - 1;
	if (n == 0)
		str[i] = 48;
	while (nb != 0)
	{
		str[i] = base[nb % taille_base];
		nb = nb / taille_base;
		i--;
	}
	return (str);
}
