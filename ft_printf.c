/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:04:19 by mmaj              #+#    #+#             */
/*   Updated: 2020/02/28 11:50:45 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				g_count;

void			ft_putchar_fd(char c, int fd)
{
	g_count += write(fd, &c, 1);
	return ;
}

int				ft_strchr(int c, char *s)
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

const char		*ft_decal(const char **format)
{
	while (**format != 0 && ft_strchr(**format, "cspdiuxX%") == FALSE)
		(*format)++;
	(*format)++;
	return (*format);
}

t_flags_set		set_options(const char *format, t_flags_set flag, va_list va)
{
	flag.field = NO_FLAG;
	flag.field = (*format == '-') ? MINUS : flag.field;
	flag.field = (*format == '0') ? ZERO : flag.field;
	if (flag.field != NO_FLAG)
		format++;
	flag.digit_field = ft_atoi(format);
	flag.digit_field = (*format == '*') ? va_arg(va, int) : flag.digit_field;
	if (flag.digit_field < 0)
	{
		flag.digit_field = -flag.digit_field;
		flag.field = MINUS;
	}
	if (*format == '*' || (*format >= '0' && *format <= '9'))
		while (*format != 0 && (*format == '*' || (*format >= '0' && *format <= '9')))
			format++;
	flag.digit_precision = NO_PRECISION;
	flag.digit_precision = (*format == '.') ? ft_atoi(++format) : flag.digit_precision;
	flag.digit_precision = ((*format) == '*') ? va_arg(va, int) : flag.digit_precision;
	if (*format == '*' || ((*format) >= '0' && (*format) <= '9'))
		while (*format != 0 && (*format == '*' || (*format >= '0' && *format <= '9')))
			format++;
	flag.type = *format;
	return (flag);
}

int				ft_printf(const char *format, ...)
{
	t_flags_set	flag;
	va_list		va;

	g_count = 0;
	va_start(va, format);
	while (*format != 0)
	{
		if (*format == '%')
		{
			format++;
			flag = set_options(format, flag, va);
			ft_conversion(flag, va);
			ft_decal(&format);
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
