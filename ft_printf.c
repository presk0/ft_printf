/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:20:59 by nidionis          #+#    #+#             */
/*   Updated: 2024/10/31 20:55:10 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#define MIN_POINTER -9223372036854775808


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
	return (write(fd, s, ft_strlen(s)));
}

int	ft_putchar(char c)
{
	return (write(FD, &c, 1));
}

size_t	ft_writenbase(long long int n, char *base, int fd)
{
	char	c;

	c = base[n];
	return (write(fd, &c, fd));
}

size_t	ft_putnbrbase_fd(long long int n, char *base, size_t base_len, int fd)
{
	static	size_t	len;

	if (n < 0)
	{
		len += write(fd, "-", 1);
		ft_putnbrbase_fd(-1 * n, base, base_len, fd);
	}
	else if ((size_t) n >= base_len)
	{
		ft_putnbrbase_fd(n / base_len, base, base_len, fd);
		//ft_putnbrbase_fd(n % base_len, base, base_len, fd);
	}
	else
	{
		len += ft_writenbase(n, base, fd);
	}
	return (len);
}

static size_t	ft_intlen(unsigned long long int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

size_t	ft_putptr(unsigned long int ptr, int fd)
{
	size_t	len;
	size_t	i;

	len = ft_intlen(ptr);
	len += write(fd, "0x", 2);
	i = 0;
	ft_putnbrbase_fd(ptr, "0123456789abcdef", 16, FD);
	return (len);
}

int	print_item(va_list ap, char c)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(ap, int)));
	if (c == 's')
		return (ft_putstr_fd((char *) va_arg(ap, char *), FD));
	if (c == 'p')
		return (ft_putptr((unsigned long)va_arg(ap, void *), FD));
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

/*
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	//ft_putnbrbase_fd(atoi(argv[1]), argv[2], ft_strlen(argv[2]), FD);
	printf(" %p ",(void *) -1);
	printf("\n");
	ft_printf(" %p ", (void *)-1);
	printf("\n");

	printf("\n");
	ft_printf(" %p ",(void *) 1);
	printf("\n");
	printf(" %p ",(void *) 1);
	printf("\n");

	printf("\n");
	ft_printf(" %p ",(void *) 15);
	printf("\n");
	printf(" %p ",(void *) 15);
	printf("\n");

	printf("\n");
	ft_printf(" %p ",(void *) 16);
	printf("\n");
	printf(" %p ",(void *) 16);
	printf("\n");

	printf("\n");
	printf(" %p ",(void *) 1700000000000);
	printf("\n");
	printf(" %p ",(void *) 1700000000000);
	printf("\n");

	printf("\n");
	printf(" %p ",(void *) LONG_MIN);
	printf("\n");
	ft_printf(" %p ",(void *) LONG_MIN);
	printf("\n");

	printf("\n");
	printf(" %p %p ", LONG_MIN, LONG_MAX);
	printf("\n");
	ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	printf("\n");

	printf("\n");
	ft_printf(" %p %p ", INT_MIN, INT_MAX);
	printf("\n");
	printf(" %p %p ", INT_MIN, INT_MAX);
	printf("\n");

	printf("\n");
	ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	printf("\n");
	printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	printf("\n");

	printf("\n");
	ft_printf(" %p %p ", 0, 0);
	printf("\n");
	printf(" %p %p ", 0, 0);
	printf("\n");

	printf("\n");
	ft_printf(" %p %p ", ULONG_MAX - 1, -ULONG_MAX - 1);
	printf("\n");
	printf(" %p %p ", ULONG_MAX - 1, -ULONG_MAX - 1);
	printf("\n");

}
*/
