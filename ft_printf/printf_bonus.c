/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:58:04 by damarry           #+#    #+#             */
/*   Updated: 2021/11/20 20:40:22 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_print(va_list ap, t_flags *flags)
{
	int		op;
	char	spec;

	op = 0;
	spec = flags->spec;
	if (spec == 'c')
		op = ft_print_c(va_arg(ap, int), flags);
	else if (spec == '%')
		op = ft_print_c('%', flags);
	else if (spec == 's')
		op = ft_print_str(va_arg(ap, char *), flags);
	else if (spec == 'd' || spec == 'i')
		op = ft_print_nbr(va_arg(ap, int), flags);
	else if (spec == 'x' || spec == 'X' || spec == 'u')
		op = ft_print_nbr(va_arg(ap, unsigned int), flags);
	else if (spec == 'p')
		op = ft_print_nbr(va_arg(ap, unsigned long long), flags);
	return (op);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	parse_format(va_list ap, int op, char *format)
{
	int		i;
	t_flags	*flags;

	i = 0;
	flags = malloc(sizeof(t_flags) * 1);
	if (!(flags))
		return (-1);
	while (format[i] != '\0')
	{
		while (format[i] != '\0' && format[i] != '%')
			op += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			obr(flags);
			while (format[i++] != '\0' && !(ft_strchr(SPEC, format[i]))
				&& ft_strchr(FLAGS, format[i]))
				check_flags(format, flags, i);
			if (ft_strchr(SPEC, format[i]))
				zero_logic(flags, format[i++]);
			op += ft_print(ap, flags);
		}
	}
	free(flags);
	return (op);
}

int	ft_printf(const char *format, ...)
{
	int		op;
	va_list	ap;

	op = 0;
	if (format == NULL)
		return (-1);
	va_start(ap, format);
	op = parse_format(ap, op, (char *)format);
	va_end(ap);
	return (op);
}
