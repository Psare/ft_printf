/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uflags_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:03:51 by damarry           #+#    #+#             */
/*   Updated: 2021/11/20 19:32:29 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	obr(t_flags *flags)
{
	flags->negative = 0;
	flags->zero = 0;
	flags->plus = 0;
	flags->alt = 0;
	flags->costi = 0;
	flags->prob = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->spec = 0;
	flags->nbr_base = 10;
	flags->sign = 1;
}

void	check_flags(char *format, t_flags *flags, int i)
{
	if (format[i] == '-')
		flags->negative = 1;
	else if (format[i] == '.')
		flags->precision = 0;
	else if (format[i] == '+')
		flags->plus = 1;
	else if (format[i] == '#')
		flags->alt = 1;
	else if (format[i] == ' ')
		flags->prob = 1;
	else if (format[i] == '0' && flags->width == 0 && flags->precision == -1)
		flags->zero = 1;
	else if (ft_isdigit(format[i]))
		width_precision(format, flags, i);
}

void	width_precision(char *format, t_flags *flags, int i)
{
	if (ft_isdigit(format[i]))
	{
		if (flags->precision == -1)
			flags->width = flags->width * 10 + format[i] - 48;
		else
			flags->precision = flags->precision * 10 + format[i] - 48;
	}
}

void	zero_logic(t_flags *flags, char format)
{
	flags->spec = format;
	if ((flags->negative == 1 || flags->precision > -1)
		&& flags->spec != '%')
		flags->zero = 0;
}
