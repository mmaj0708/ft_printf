/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_di.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:30:49 by mmaj              #+#    #+#             */
/*   Updated: 2020/02/25 11:15:08 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_zerostr(int precision, int len)
{
	int		i;
	int		len_prec;
	char	*str_zero;

	i = 0;
	len_prec = precision - len;
	str_zero = NULL;
	if (len_prec > 0)
	{
		if(!(str_zero = malloc(len_prec + 1))) 			// 1 fonction
			return (NULL);
		while (i < len_prec)
		{
			str_zero[i] = '0';
			i++;
		}
		str_zero[i] = '\0';								//
	}
	return (str_zero);
}

void	ft_inject(int is_negatif)
{
	if (is_negatif == TRUE)
		ft_putchar_fd('-', 1);
	return ;
}

void	type_di(va_list va, t_flags_set flag)
{
	long		nb;
	int		len_field;
	char	*str;
	char	*str_precision;
	int		is_negatif;

	nb = va_arg(va, int);
	is_negatif = FALSE;
	if (nb < 0)
	{
		nb = nb * -1;
		is_negatif = TRUE;
	}
	str = ft_itoa(nb);
//	printf("check int : %s", str);
	if (nb == 0 && flag.digit_precision != NO_PRECISION)
		str = NULL;
	
	str_precision = ft_zerostr(flag.digit_precision, ft_strlen(str));
	str = ft_strjoin(str_precision, str);
	len_field = flag.digit_field - ft_strlen(str) + 1;
	if (flag.field == NO_FLAG)
	{
		if(is_negatif == TRUE)
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
		if(is_negatif == TRUE)
		{
			ft_putchar_fd('-', 1);
			len_field--;
		}
		ft_putstr(str, ft_strlen(str));
		ft_noflag(len_field);
	}
	if (flag.field == ZERO && flag.digit_precision != NO_PRECISION)
	{
		if(is_negatif == TRUE)
		{
			len_field--;
			ft_noflag(len_field);
			ft_putchar_fd('-', 1);
		}
		else
		ft_noflag(len_field);
		ft_putstr(str, ft_strlen(str));
	}
	if (flag.field == ZERO && flag.digit_precision == NO_PRECISION)
	{
		if(is_negatif == TRUE)
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
