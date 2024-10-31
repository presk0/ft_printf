/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:48:16 by supersko          #+#    #+#             */
/*   Updated: 2024/10/30 21:11:11 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str)
		while (str[i] != '\0')
			i++;
	return (i);
}

/*
//
#include "error_msg.h"
#include <ctype.h>
#include <string.h>
// MAIN
int test_strlen(char *str, int buf_size)
{
	if (strlen(str) != ft_strlen(str))
	{
		printf("differents output for str=%s\n\t\
			strlen(str) = %lu; ft_strlen(str) = %lu\nbuf_size = %d\n",\
			str, strlen(str), ft_strlen(str), buf_size);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int ii = 0;

	while (ii < 6)
	{
		char str[ii];
		strcpy(str, "abc\n");
		test_strlen(str, ii);
		strcpy(str, "");
		test_strlen(str, ii);
		ii++;
	}
	printf("can be a good job ;)\n");
}
*/
