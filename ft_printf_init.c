/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:02:49 by mmaj              #+#    #+#             */
/*   Updated: 2020/02/26 15:51:17 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_func	*ft_init_func(t_func *ft_tab)
{
	ft_tab[0].ptrfunc = &type_c;
	ft_tab[0].key = 'c';
	ft_tab[1].ptrfunc = &type_s;
	ft_tab[1].key = 's';
	ft_tab[2].ptrfunc = &type_p;
	ft_tab[2].key = 'p';
	ft_tab[3].ptrfunc = &type_di;
	ft_tab[3].key = 'd';
	ft_tab[4].ptrfunc = &type_di;
	ft_tab[4].key = 'i';
	ft_tab[5].ptrfunc = &type_u;
	ft_tab[5].key = 'u';
	ft_tab[6].ptrfunc = &type_x;
	ft_tab[6].key = 'x';
	ft_tab[7].ptrfunc = &type_gx;
	ft_tab[7].key = 'X';
	ft_tab[8].ptrfunc = &type_prcent;
	ft_tab[8].key = '%';
	ft_tab[9].ptrfunc = NULL;
	ft_tab[9].key = FAILURE;
	return (ft_tab);
}

void	ft_func_conv(t_func *ft_tab, t_flags_set flag, va_list va)
{
	int i;

	i = 0;
	while (ft_tab[i].key != FAILURE && ft_tab[i].key != flag.type)
		i++;
	if (ft_tab[i].key == flag.type)
		ft_tab[i].ptrfunc(va, flag);
	return ;
}

int		ft_conversion(t_flags_set flag, va_list va)
{
	t_func		ft_tab[10];

	ft_init_func(ft_tab);
	ft_func_conv(ft_tab, flag, va);
	return (0);
}
