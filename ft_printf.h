/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:55:49 by mmaj              #+#    #+#             */
/*   Updated: 2020/02/25 15:06:53 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

# define TRUE			1
# define FALSE			0
# define SUCCESS		0
# define FAILURE		-1
# define MINUS			0
# define ZERO			1
# define NO_FLAG		-1
# define NO_PRECISION	-1

typedef struct	s_flags_set
{
	char	type;
	int		field;
	int		digit_field;
	int		digit_precision;
}				t_flags_set;

typedef struct	s_funct
{
	void	(*ptrfunc)(va_list va, t_flags_set flag);
	char	key;
}				t_func;

int					ft_printf(const char *format, ...);
void				ft_putchar_fd(char c, int fd);
const char			*ft_decal(const char **format);
void				ft_func_conv(t_func *ft_tab, t_flags_set flag, va_list va);
int					ft_conversion(t_flags_set flag, va_list va);
int					ft_strlen(char *str);
void				ft_flag_zero(int len);
void				ft_noflag(int len);
void				ft_putnbr(int n);
int					ft_strlen_int(long n);
char				*ft_itoa(long n);
void				ft_strcpy(char *dst, char *src);
char				*ft_strjoin(char *s1, char *s2);
void				*ft_calloc(size_t count, size_t size);
void				ft_putstr(char *str, int len);
char				*ft_zerostr(int precision, int len);
char				*ft_itoa_base(long n, char *base);

void				type_c(va_list va, t_flags_set flag);
void				type_s(va_list va, t_flags_set flag);
void				type_p(va_list va, t_flags_set flag);
void				type_di(va_list va, t_flags_set flag);
void				type_u(va_list va, t_flags_set flag);
void				type_x(va_list va, t_flags_set flag);
void				type_gx(va_list va, t_flags_set flag);
void				type_prcent(va_list va, t_flags_set flag);

#endif