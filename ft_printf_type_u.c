/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 10:41:26 by mmaj              #+#    #+#             */
/*   Updated: 2020/02/28 11:55:10 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_u(va_list va, t_flags_set flag)
{
	long	nb;
	int		len_field;
	char	*str;
	char	*str_precision;
	int		is_negatif;

	nb = va_arg(va, unsigned int);
	is_negatif = FALSE;
	if (nb < 0)
	{
		nb = nb * -1;
		is_negatif = TRUE;
	}
	str = ft_itoa(nb);
	if (nb == 0 && flag.digit_precision > NO_PRECISION)
		str = NULL;
	str_precision = ft_zerostr(flag.digit_precision, ft_strlen(str));
	str = ft_strjoin(str_precision, str);
	len_field = flag.digit_field - ft_strlen(str) + 1;
	if (flag.field == NO_FLAG)
	{
		if (is_negatif == TRUE)
		{
			len_field--;
			ft_noflag(len_field);
			ft_putchar_fd('-', 1);
		}
		else
			ft_noflag(len_field);
		ft_putstr(str, ft_strlen(str));
	}
	if (flag.field == MINUS)
	{
		if (is_negatif == TRUE)
		{
			ft_putchar_fd('-', 1);
			len_field--;
		}
		ft_putstr(str, ft_strlen(str));
		ft_noflag(len_field);
	}
	if (flag.field == ZERO && flag.digit_precision > NO_PRECISION)
	{
		if (is_negatif == TRUE)
		{
			len_field--;
			ft_noflag(len_field);
			ft_putchar_fd('-', 1);
		}
		else
			ft_noflag(len_field);
		ft_putstr(str, ft_strlen(str));
	}
	if (flag.field == ZERO && flag.digit_precision <= NO_PRECISION)
	{
		if (is_negatif == TRUE)
		{
			ft_putchar_fd('-', 1);
			len_field--;
		}
		ft_flag_zero(len_field);
		ft_putstr(str, ft_strlen(str));
	}
	free(str);
	str = NULL;
}
