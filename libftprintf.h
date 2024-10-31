
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:03:26 by supersko          #+#    #+#             */
/*   Updated: 2024/10/16 15:05:56 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>


size_t	ft_writenbase(long long int n, char *base, int fd);
size_t	ft_putnbrbase_fd(long long int n, char *base, size_t base_len, int fd);
size_t	ft_putptr(long long int ptr, int fd);
int		print_item(va_list ap, char c);
int		ft_printf(const char *str, ...);

#endif
