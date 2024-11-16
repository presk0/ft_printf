/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:20:59 by nidionis          #+#    #+#             */
/*   Updated: 2024/11/16 15:11:21 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "libftprintf.h"

int	main(int argc, char **argv)
{
	char	*str;
	int		output;
	char	*str;
	int		output;

	str = argv[1];
	printf("\n");
	printf("[ft_printf] ");
	printf("\n");
	output = ft_printf(str, -1);
	printf("\n");
	printf("output printf: %d\n", output);
	printf("\n");
	printf("[printf] ");
	printf("\n");
	output = printf(str, -1);
	printf("\n");
	printf("output ft_printf: %d\n", output);
	printf("\n");

	printf("\n");
	printf("[ft_printf] ");
	printf("\n");
	output = ft_printf(str, 0);
	printf("\n");
	printf("output printf: %d\n", output);
	printf("\n");
	printf("[printf] ");
	printf("\n");
	output = printf(str, 0);
	printf("\n");
	printf("output ft_printf: %d\n", output);
	printf("\n");

	printf("\n");
	printf("[ft_printf] ");
	printf("\n");
	output = ft_printf(str, 1);
	printf("output printf: %d\n", output);
	printf("\n");
	printf("[printf] ");
	printf("\n");
	output = printf(str, 1);
	printf("\n");
	output = printf("\n");
	printf("[ft_printf] ");
	printf("\n");
	output = ft_printf(str, ULONG_MAX);
	printf("\n");
	printf("output ft_printf: %d\n", output);
	printf("\n");
	printf("[printf] ");
	printf("\n");
	output = printf(str, ULONG_MAX);
	printf("\n");
	printf("output printf: %d\n", output);
	printf("\n");

	printf("\n");
	printf("[ft_printf] ");
	printf("\n");
	output = ft_printf(str, 15);
	printf("\n");
	printf("output printf: %d\n", output);
	printf("\n");
	printf("[printf] ");
	printf("\n");
	output = printf(str, 15);
	printf("\n");
	printf("output ft_printf: %d\n", output);
	printf("\n");

	printf("\n");
	printf("[ft_printf] ");
	printf("\n");
	output = ft_printf(str, 16);
	printf("\n");
	printf("output printf: %d\n", output);
	printf("\n");
	printf("[printf] ");
	printf("\n");
	output = printf(str, 16);
	printf("\n");
	printf("output ft_printf: %d\n", output);
	printf("\n");

	printf("\n");
	printf("[ft_printf] ");
	printf("\n");
	output = printf(str, 1700000000000);
	printf("\n");
	printf("output printf: %d\n", output);
	printf("\n");
	printf("[printf] ");
	printf("\n");
	output = printf(str, 1700000000000);
	printf("\n");
	printf("output ft_printf: %d\n", output);
	printf("\n");

	printf("\n");
	printf("[ft_printf] ");
	printf("\n");
	output = ft_printf(str, LONG_MIN);
	printf("\n");
	printf("output printf: %d\n", output);
	printf("\n");
	output = printf("\n");
	printf("[ft_printf] ");
	printf("\n");
	output = ft_printf(str, ULONG_MAX);
	printf("\n");
	printf("output ft_printf: %d\n", output);
	printf("\n");
	printf("[printf] ");
	printf("\n");
	output = printf(str, ULONG_MAX);
	printf("\n");
	printf("output printf: %d\n", output);
	printf("\n");

	printf("[printf] ");
	printf("\n");
	output = printf(str, LONG_MIN);
	printf("\n");
	printf("output printf: %d\n", output);
	printf("\n");
	printf("[printf] ");
	printf("\n");
	output = ft_printf(str, LONG_MIN);
	printf("\n");
	printf("output ft_printf: %d\n", output);
	printf("\n");

	printf("\n");
	printf("[ft_printf] ");
	printf("\n");
	output = ft_printf(str, LONG_MAX);
	printf("\n");
	printf("output printf: %d\n", output);
	printf("\n");
	printf("[printf] ");
	printf("\n");
	output = printf(str, LONG_MAX);
	printf("\n");
	printf("output ft_printf: %d\n", output);
	printf("\n");

	printf("\n");
	printf("[ft_printf] ");
	printf("\n");
	output = ft_printf(str, INT_MAX);
	printf("\n");
	printf("output ft_printf: %d\n", output);
	printf("\n");
	printf("[printf] ");
	printf("\n");
	output = printf(str, INT_MAX);
	printf("\n");
	printf("output printf: %d\n", output);
	printf("\n");

	output = printf("\n");
	printf("[ft_printf] ");
	printf("\n");
	output = ft_printf(str, INT_MIN);
	printf("\n");
	printf("output ft_printf: %d\n", output);
	printf("\n");
	printf("[printf] ");
	printf("\n");
	output = printf(str, INT_MIN);
	printf("output printf: %d\n", output);
	printf("\n");

	output = printf("\n");
	printf("[ft_printf] ");
	printf("\n");
	output = ft_printf(str, ULONG_MAX);
	printf("\n");
	printf("output ft_printf: %d\n", output);
	printf("\n");
	printf("[printf] ");
	printf("\n");
	output = printf(str, ULONG_MAX);
	printf("\n");
	printf("output printf: %d\n", output);
	printf("\n");
	return (0);
}
