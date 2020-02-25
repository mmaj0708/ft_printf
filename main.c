/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:06:02 by mmaj              #+#    #+#             */
/*   Updated: 2020/02/25 17:14:04 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main()
{
	unsigned int nb = -1;
//	count = write(1, "c\n", 2);
//	printf("%d\n\n", count);

	printf("[%d]\n", ft_printf("ft_printf : [%.50X]\n", -214748364));

	     printf("[%d]", printf("   printf : [%.50X]\n", -214748364));
//	printf(av[1]);
//	printf("mon mien : ");
//	ft_printf(av[1]);

	return (0);
}
