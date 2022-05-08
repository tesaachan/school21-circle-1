/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:29:32 by georgy            #+#    #+#             */
/*   Updated: 2022/01/21 16:01:05 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_string(char *str);
int	ft_char(char c);
int	ft_int(int dec);
int	ft_unsigned_int(unsigned int dec);
int	ft_hex(unsigned int dec, char c);
int	ft_hex_p(unsigned long dec);

#endif