/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:20:59 by nidionis          #+#    #+#             */
/*   Updated: 2024/11/08 14:52:52 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str)
		while (str[i] != '\0')
			i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	*s;

	s = (char *)str;
	c = (char)c;
	if (s)
	{
		while (*s != c)
		{
			if (!*s)
				return (NULL);
			s++;
		}
	}
	return (s);
}

size_t	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (write(fd, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}

int	ft_putchar(char c)
{
	return (write(FD, &c, 1));
}

void	loop_norminette(char **str_addr, va_list ap, int *p_itm, int *ret_val)
{
	if (**str_addr == '%')
	{
		*p_itm = print_item(ap, *(++(*str_addr)));
		if (*p_itm == -1)
			*ret_val = -1;
		if (*ret_val != -1)
			*ret_val += *p_itm;
	}
	else
	{
		write(FD, *str_addr, 1);
		if (*ret_val != -1)
			(*ret_val)++;
	}
	if (**str_addr)
		(*str_addr)++;
}
