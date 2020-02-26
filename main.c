/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:06:02 by mmaj              #+#    #+#             */
/*   Updated: 2020/02/26 11:40:51 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main()
{
//	unsigned int nb = -1;
//	count = write(1, "c\n", 2);
//	printf("%d\n\n", count);

//	char		*ptr = NULL;
	printf("[%d]\n", ft_printf("ft_printf : [%-40.50d]\n", 0));

	     printf("[%d]", printf("   printf : [%-40.50d]\n", 0));
//	printf(av[1]);
//	printf("mon mien : ");
//	ft_printf(av[1]);

	return (0);
}
