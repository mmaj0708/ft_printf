/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_%.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:11:00 by mmaj              #+#    #+#             */
/*   Updated: 2020/02/25 12:31:24 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_prcent(va_list va, t_flags_set flag)
{
	int i;

	if (va)
		i = 1;
	if (flag.field == ZERO)
	{
		ft_flag_zero(flag.digit_field);
		ft_putchar_fd('%', 1);
	}
	if (flag.field == MINUS)
	{
		ft_putchar_fd('%', 1);
		ft_noflag(flag.digit_field);
	}
	if (flag.field == NO_FLAG)
	{
		ft_noflag(flag.digit_field);
		ft_putchar_fd('%', 1);
	}
	return ;
}