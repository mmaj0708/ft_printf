/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:18:45 by mmaj              #+#    #+#             */
/*   Updated: 2020/02/25 17:04:27 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
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

void	ft_putnbr(int n)
{
	unsigned int nb;

	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		nb = -1 * n;
	}
	else
		nb = n;
	if (nb > 9)
		ft_putnbr(nb / 10);
	nb = nb % 10;
	ft_putchar_fd(nb % 10 + 48, 1);
}

void	ft_flag_zero(int len)
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

void	ft_noflag(int len)
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

int		ft_strlen_int(long n)
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

char	*ft_itoa(long n)
{
	long	nb;
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

int		ft_strlen_base(long n, int taille_base)
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

char	*ft_itoa_base(long n, char *base)
{
	unsigned long		nb;
	size_t			i;
	char			*str;
	int				taille_base;

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
	//printf("check itoabase %d\n", ft_strlen_int(n));
	if (n == 0)
		str[i] = 48;
	while (nb != 0)
	{
		str[i] = base[nb % taille_base];
//	printf("check str %d\n", i);
		nb = nb / taille_base;
		i--;
	}
	return (str);
}

void	ft_strcpy(char *dst, char *src)
{
	size_t		i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ;
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*new;

	i = ft_strlen(s1);
	if ((!s1) && (!s2))
		return (NULL);
	if (!(new = malloc(sizeof(new)
		* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	if (s1 != NULL)
		ft_strcpy(new, s1);
	if (s2 != NULL)
		ft_strcpy(&new[i], s2);
	free(s1);
	s1 = NULL;
	return (new);
}

// char	*ft_strdup(const char *s1)
// {
// 	char	*str1;
// 	char	*str2;
// 	int		i;

// 	i = 0;
// 	str1 = (char *)s1;
// 	while (str1[i])
// 		i++;
// 	str2 = malloc(sizeof(*s1) * (i + 1));
// 	if (str2 == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (str1[i])
// 	{
// 		str2[i] = str1[i];
// 		i++;
// 	}
// 	str2[i] = '\0';
// 	return (str2);
// }
