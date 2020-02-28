/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:41:03 by mmaj              #+#    #+#             */
/*   Updated: 2020/02/26 15:43:36 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

void			*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = malloc(size * count);
	if (mem == NULL)
		return (NULL);
	while (i < size * count)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}

void			ft_flag_zero(int len)
{
	int i;

	i = 1;
	while (i < len)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	return ;
}

void			ft_noflag(int len)
{
	int i;

	i = 1;
	while (i < len)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	return ;
}

int				ft_atoi(const char *str)
{
	long			i;
	long			sign;
	unsigned int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n' ||
	str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + str[i] - 48;
		i++;
	}
	return ((int)(nb * sign));
}
