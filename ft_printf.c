/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:04:19 by mmaj              #+#    #+#             */
/*   Updated: 2020/02/21 13:59:39 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		g_count;

void	ft_putchar_fd(char c, int fd)
{
	g_count += write(fd, &c, 1);
	return ;
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (TRUE);
	return (FALSE);
}

int	ft_atoi(const char *str)
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

int		ft_elmt_strchr(char *str, char *ref)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (ref[j] == '\0')
		return (FALSE);
	while (str[i])
	{
		j = 0;
		while (ref[j] != 0 && str[i] != ref[j])
			j++;
		if (str[i] == ref[j])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int		ft_strchr(int c, char *s)
{
	size_t i;

	i = 0;
	if (c == 0)
		return (FALSE);
	while (s[i] != c)
	{
		i++;
		if (s[i] == '\0')
			return (FALSE);
	}
	return (TRUE);
}

const char	*ft_decal(const char **format)
{
	while (**format != 0 && ft_strchr(**format, "cspdiuxX%") == FALSE)
		(*format)++;
	(*format)++;
	return (*format);
}

t_flags_set set_options(const char *format, t_flags_set flag, va_list va)
{
	flag.field = NO_FLAG;							  //
	flag.field = (*format == '-') ? MINUS : flag.field; //affectation de la width
	flag.field = (*format == '0') ? ZERO : flag.field;//

	if (flag.field != NO_FLAG)//
		format++;			  // char suivant si on a '-' ou '0' au début

	flag.digit_field = ft_atoi(format); // affectation de la taille de champ
	flag.digit_field = (*format == '*') ? va_arg(va, int) : flag.digit_field;      
	if (*format == '*' || (*format >= '0' && *format <= '9')) // décalage
		while (*format != 0 && (*format == '*' || (*format >= '0' && *format <= '9')))
			format++;

	flag.digit_precision = NO_PRECISION;
	flag.digit_precision = (*format == '.') ? ft_atoi(++format) : flag.digit_precision;	// affectation de la precision
	flag.digit_precision = (*format == '*') ? va_arg(va, int) : flag.digit_precision;
	if (*format == '*' || (*format >= '0' && *format <= '9')) // décalage
		while (*format != 0 && (*format == '*' || (*format >= '0' && *format <= '9')))
			format++;
	flag.type = *format; // affectation type
	return (flag);
}

int		ft_printf(const char *format, ...)
{
	t_flags_set flag;
	va_list va;

	va_start(va, format);
	while (*format != 0)
	{
		if (*format == '%')
		{
			format++;
			flag = set_options(format, flag, va); //&format ? &va ?
			ft_conversion(flag, va);
			ft_decal(&format);
//			printf("field : %d\ndigit_field : %d\ndigit_precision : %d\ntype : %c\n", flag.field, flag.digit_field, flag.digit_precision, flag.type);
		}
		else
		{		
			ft_putchar_fd(*format, 1);
			format++;
		}
	}
	va_end(va);
	return (g_count);
}
