/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:20:59 by nidionis          #+#    #+#             */
/*   Updated: 2024/10/22 23:48:57 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define FD 1
#define FLAGS "cspdiuxX%"

int	print_item(va_list ap, char c)
{
	if (c == 'c')
		return (ft_printchar((int) va_arg(ap, char));
	if (c == 's')
		return (ft_printchar((char *) va_arg(ap, char *));
	if (c == 'p')
		return (ft_printlonghex((long int) va_arg(ap, (void *));
	if (c == 'd')
		return (ft_printlongnbr((long long int) va_arg(ap, long long int));
	if (c == 'i')
		return (ft_printnbr((int) va_arg(ap, int));
	if (c == 'u')
		return (ft_printlongnbr((unsigned int) va_arg(ap, unsigned int));
	if (c == 'x')
		return (ft_printhex((int) va_arg(ap, int));
	if (c == 'X')
		return (ft_printhexmaj((int) va_arg(ap, int));
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
	   if (*str == '%' && ft_strchr(FLAGS, *(str))
		   ret_val += print_item(ap, *(++str);
	   else
		   ret_val += write(FD, str, 1);
		str++;
   }
   va_end(ap);
   return (ret_val);
}

/*
int va_test(const char *str, ...)
{
   va_list ap;
   char	*s;

   s = (char *)1;
   va_start(ap, str);
   s = va_arg(ap, char *);
   while (s)
   {
	   printf("%s\n", (char *)s);
	   s = va_arg(ap, char *);
   }
   va_end(ap);
   return (0);
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	va_test(argv[0], argv[1], argv[2]);
}
