/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:20:59 by nidionis          #+#    #+#             */
/*   Updated: 2024/10/23 15:51:49 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define FD 1
#define FLAGS "cspdiuxX%"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

size_t	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		return (write(fd, s, ft_strlen(s)));
	}
}

int	ft_putchar(char c)
{
	return (write(FD, &c, 1));
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return ((char *)str);
}

size_t	ft_writenbase(long long int n, char *base, size_t base_len, int fd)
{
	char	c;

	c = base[n];
	return (fd, &c, fd);
}

size_t	ft_putnbrbase_fd(long long int n, char *base, size_t base_len, int fd)
{
	static	size_t	len;

	if (n < 0)
	{
		len += write(fd, "-", 1);
		ft_putnbrbase_fd(-1 * n, base, base_len, fd);
	}
	else if (n >= base_len)
	{
		ft_putnbrbase_fd(n / base_len, base, base_len, fd);
		ft_putnbrbase_fd(n % base_len, base, base_len, fd);
	}
	else
	{
		len += write(FD, base + n % base_len, 1);
	}
	return (len);
}

int	print_item(va_list ap, char c)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(ap, int)));
	if (c == 's')
		return (ft_putstr_fd((char *) va_arg(ap, char *), FD));
	if (c == 'p')
		return (ft_putnbrbase_fd((long int) va_arg(ap, void *), "0123456789", 10, FD));
	if (c == 'i' || c == 'd')
		return (ft_putnbrbase_fd((int) va_arg(ap, int), "0123456789", 10, FD));
	if (c == 'u')
		return (ft_putnbrbase_fd((unsigned int) va_arg(ap, unsigned int), "0123456789", 10, FD));
	if (c == 'x')
		return (ft_putnbrbase_fd((int) va_arg(ap, int), "0123456789abcdef", 16, FD));
	if (c == 'X')
		return (ft_putnbrbase_fd((int) va_arg(ap, int), "0123456789ABCDEF", 16, FD));
	if (c == '%')
		return (write(FD, "%", 1));
	return (1);
}

int ft_printf(const char *str, ...)
{
   va_list	ap;
   void		*item;
   int		ret_val;

   ret_val = 0;
   va_start(ap, str);
   if (!str)
	   return (-1);
   while (*str)
   {
	   if (*str == '%' && ft_strchr(FLAGS, *(str + 1)))
		   ret_val += print_item(ap, *(++str));
	   else
		   ret_val += write(FD, str, 1);
		str++;
   }
   va_end(ap);
   return (ret_val);
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	//ft_putnbrbase_fd(atoi(argv[1]), argv[2], ft_strlen(argv[2]), FD);
	printf(argv[1], argv[2]);
	printf("\n");
	printf(argv[1], argv[2]);
}
