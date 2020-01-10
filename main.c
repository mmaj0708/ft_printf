/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:39:17 by mmaj              #+#    #+#             */
/*   Updated: 2020/01/09 15:48:36 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_printf(const char *format, ...);

int 	main(int ac, char **av)
{
	char *str = "bonjour";

	//printf(av[1], str, -15);
	printf("%0000d\n", 15);
	//ft_printf(av[1], str, str);
	return (0);
}
