/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:56:01 by mmaj              #+#    #+#             */
/*   Updated: 2020/02/25 17:13:49 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_c(va_list va, t_flags_set flag)
{
	if (flag.field == ZERO)
	{
		ft_flag_zero(flag.digit_field);
		ft_putchar_fd(va_arg(va, int), 1);
	}
	if (flag.field == MINUS)
	{
		ft_putchar_fd(va_arg(va, int), 1);
		ft_noflag(flag.digit_field);
	}
	if (flag.field == NO_FLAG)
	{
		ft_noflag(flag.digit_field);
		ft_putchar_fd(va_arg(va, int), 1);
	}
	return ;
}


















void	type_p(va_list va, t_flags_set flag)
{
	ft_putchar_fd('%', 1);
	return ;
}

void	type_u(va_list va, t_flags_set flag)
{
//	ft_putnbru(va_arg(va, unsigned int));
	return ;
}
