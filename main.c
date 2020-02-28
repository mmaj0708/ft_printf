/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:06:02 by mmaj              #+#    #+#             */
/*   Updated: 2020/02/28 11:36:00 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main()
{
	unsigned int nb = -1;
//	count = write(1, "c\n", 2);
//	printf("%d\n\n", count);

//	char		*ptr = NULL;
      printf("[%d]\n", ft_printf("ftprintf : [%7c][%020.5u]USD1y2V93LLTT", 'p', 2147483647));

	     printf("[%d]\n", printf("  printf : [%7c][%020.5u]USD1y2V93LLTT", 'p', 2147483647));
	
//	printf(av[1]);
//	printf("mon mien : ");
//	ft_printf(av[1]);

	return (0);
}
