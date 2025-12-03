/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:01:05 by pcordero          #+#    #+#             */
/*   Updated: 2025/12/03 20:19:19 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_printf(char const *str, ...);

size_t	ft_printf_char(char const **str, va_list args);
size_t	ft_printf_str(char const **str, va_list args);
size_t	ft_printf_ptr(char const **str, va_list args);
size_t	ft_printf_int(char const **str, va_list args);
size_t	ft_printf_uint(char const **str, va_list args);
size_t	ft_printf_hex(char const **str, va_list args, unsigned int mayus);

char	*ft_strchr(const char *str, int ch);
size_t	ft_strlen(const char *str);
int		ft_putnbr_base(long number, const char *base);
