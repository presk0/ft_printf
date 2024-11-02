/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:03:26 by supersko          #+#    #+#             */
/*   Updated: 2024/11/02 15:36:07 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define FD 1
# define FLAGS "cspdiuxX%"

size_t	ft_strlen(char *s);
size_t	ft_putstr_fd(char *s, int fd);
int		ft_putchar(char c);
char	*ft_strchr(const char *str, int c);
size_t	ft_writenbase(long long int n, char *base, int fd);
size_t	ft_putnbrbase_fd(long long int n, char *base, size_t base_len, int fd);
int		print_item(va_list ap, char c);
int		ft_printf(const char *str, ...);

#endif
