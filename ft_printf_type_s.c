/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:20:27 by mmaj              #+#    #+#             */
/*   Updated: 2020/02/28 11:59:34 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int len)
{
	if (str == NULL)
		return ;
	while (*str != 0 && len > 0)
	{
		ft_putchar_fd(*str, 1);
		str++;
		len--;
	}
	return ;
}

void	type_s(va_list va, t_flags_set flag)
{
	int		len_str;
	int		len_field;
	char	*str;

	str = va_arg(va, char*);
	if (str == NULL)
		str = "(null)";
	len_str = ft_strlen(str);
	if (flag.digit_precision > NO_PRECISION && flag.digit_precision < len_str)
		len_str = flag.digit_precision;
	len_field = flag.digit_field - len_str + 1;
	if (flag.field == MINUS)
	{
		ft_putstr(str, len_str);
		ft_noflag(len_field);
	}
	if (flag.field == ZERO)
	{
		ft_flag_zero(len_field);
		ft_putstr(str, len_str);
	}
	if (flag.field == NO_FLAG)
	{
		ft_noflag(len_field);
		ft_putstr(str, len_str);
	}
	return ;
}
