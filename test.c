/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:20:59 by nidionis          #+#    #+#             */
/*   Updated: 2024/10/31 18:25:17 by nidionis         ###   ########.fr       */
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
	printf(str,(void *) -1);
	printf("\n");
	ft_printf(str, (void *)-1);
	printf("\n");

	//printf("\n");
	//ft_printf(" %p ",(void *) 1);
	//printf("\n");
	//printf(" %p ",(void *) 1);
	//printf("\n");

	//printf("\n");
	//ft_printf(" %p ",(void *) 15);
	//printf("\n");
	//printf(" %p ",(void *) 15);
	//printf("\n");

	//printf("\n");
	//ft_printf(" %p ",(void *) 16);
	//printf("\n");
	//printf(" %p ",(void *) 16);
	//printf("\n");

	//printf("\n");
	//printf(" %p ",(void *) 1700000000000);
	//printf("\n");
	//printf(" %p ",(void *) 1700000000000);
	//printf("\n");

	//printf("\n");
	//printf(" %p ",(void *) LONG_MIN);
	//printf("\n");
	//ft_printf(" %p ",(void *) LONG_MIN);
	//printf("\n");

	//printf("\n");
	//printf(" %p %p ", LONG_MIN, LONG_MAX);
	//printf("\n");
	//ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	//printf("\n");

	//printf("\n");
	//ft_printf(" %p %p ", INT_MIN, INT_MAX);
	//printf("\n");
	//printf(" %p %p ", INT_MIN, INT_MAX);
	//printf("\n");

	//printf("\n");
	//ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	//printf("\n");
	//printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	//printf("\n");

	//printf("\n");
	//ft_printf(" %p %p ", 0, 0);
	//printf("\n");
	//printf(" %p %p ", 0, 0);
	//printf("\n");

	//printf("\n");
	//ft_printf(" %p %p ", ULONG_MAX - 1, -ULONG_MAX - 1);
	//printf("\n");
	//printf(" %p %p ", ULONG_MAX - 1, -ULONG_MAX - 1);
	//printf("\n");

	//ft_printf("afsfg%p\n", 16);
	return (0);
}

