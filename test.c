/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:20:59 by nidionis          #+#    #+#             */
/*   Updated: 2024/11/02 13:48:50 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "libftprintf.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *str = argv[1];

	//ft_putnbrbase_fd(atoi(argv[1]), argv[2], ft_strlen(argv[2]), FD);

	//printf(str, -1);
	//printf("\n");
	//ft_printf(str, -1);
	//printf("\n");

	printf("\n");
	printf("[ft_printf] ");
	ft_printf(str, 0);
	printf("\n");
	printf("[printf] ");
	printf(str , 0);
	printf("\n");

	//printf("\n");
	//printf("[ft_printf] ");
	//ft_printf(str, 1);
	//printf("\n");
	//printf("[printf] ");
	//printf(str, 1);
	//printf("\n");

	//printf("\n");
	//printf("[ft_printf] ");
	//ft_printf(str, 15);
	//printf("\n");
	//printf("[printf] ");
	//printf(str, 15);
	//printf("\n");

	//printf("\n");
	//printf("[ft_printf] ");
	//ft_printf(str, 16);
	//printf("\n");
	//printf("[printf] ");
	//printf(str, 16);
	//printf("\n");

	printf("\n");
	printf("[ft_printf] ");
	printf(str, 1700000000000);
	printf("\n");
	printf("[printf] ");
	printf(str, 1700000000000);
	printf("\n");

	printf("\n");
	printf("[ft_printf] ");
	ft_printf(str, LONG_MIN);
	printf("\n");
	printf("[printf] ");
	printf(str, LONG_MIN);
	printf("\n");

	printf("\n");
	printf("[ft_printf] ");
	ft_printf(str, LONG_MAX);
	printf("\n");
	printf("[printf] ");
	printf(str, LONG_MAX);
	printf("\n");

	printf("\n");
	printf("[ft_printf] ");
	ft_printf(str, LONG_MIN);
	printf("\n");
	printf("[printf] ");
	printf(str, LONG_MIN);
	printf("\n");


	printf("\n");
	printf("[ft_printf] ");
	ft_printf(str, INT_MAX);
	printf("\n");
	printf("[printf] ");
	printf(str, INT_MAX);
	printf("\n");


	printf("\n");
	printf("[ft_printf] ");
	ft_printf(str, INT_MIN);
	printf("\n");
	printf("[printf] ");
	printf(str, INT_MIN);
	printf("\n");


	printf("\n");
	printf("[ft_printf] ");
	ft_printf(str, ULONG_MAX);
	printf("\n");
	printf("[printf] ");
	printf(str, ULONG_MAX);
	printf("\n");


	printf("\n");
	printf("[ft_printf] ");
	ft_printf(str, ULONG_MAX);
	printf("\n");
	printf("[printf] ");
	printf(str, ULONG_MAX);
	printf("\n");

	//ft_printf("afsfg%p\n", 16);
	return (0);
}

