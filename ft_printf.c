/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:20:59 by nidionis          #+#    #+#             */
/*   Updated: 2024/11/02 15:32:18 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_putibase_fd(long long int n, char *base, size_t base_len, int fd)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len += write(fd, "-", 1);
		if (-(n) != n)
			len += ft_putibase_fd(-1 * n, base, base_len, fd);
	}
	else if (n >= (int) base_len)
	{
		len += ft_putibase_fd(n / base_len, base, base_len, fd);
		len += ft_putibase_fd(n % base_len, base, base_len, fd);
	}
	else
		len += ft_writenbase(n % base_len, base, fd);
	return (len);
}

size_t	ft_putubase_fd(\
			long long unsigned n, char *base, size_t base_len, int fd)
{
	size_t	len;

	len = 0;
	if (n >= base_len)
	{
		len += ft_putibase_fd(n / base_len, base, base_len, fd);
		len += ft_putibase_fd(n % base_len, base, base_len, fd);
	}
	else
		len += ft_writenbase(n % base_len, base, fd);
	return (len);
}

size_t	ft_putptr(unsigned long ptr, int fd)
{
	size_t	len;

	len = 0;
	if (!ptr)
		return (write(fd, "(nil)", 5));
	len += write(fd, "0x", 2);
	len += ft_putubase_fd(ptr, "0123456789abcdef", 16, fd);
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
		return (ft_putibase_fd((int) va_arg(ap, int), "0123456789", 10, FD));
	if (c == 'u')
		return (ft_putubase_fd(va_arg(ap, unsigned int), "0123456789", 10, FD));
	if (c == 'x')
		return (ft_putibase_fd(va_arg(ap, int), "0123456789abcdef", 16, FD));
	if (c == 'X')
		return (ft_putibase_fd(va_arg(ap, int), "0123456789ABCDEF", 16, FD));
	if (c == '%')
		return (write(FD, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		ret_val;

	ret_val = 0;
	va_start(ap, str);
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == '%')
			ret_val += print_item(ap, *(++str));
		else
			ret_val += write(FD, str, 1);
		str++;
	}
	va_end(ap);
	return (ret_val);
}
