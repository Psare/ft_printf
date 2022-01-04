/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:22:07 by damarry           #+#    #+#             */
/*   Updated: 2021/11/19 22:09:30 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_znak(t_flags *flags, char **buffer)
{
	int		l;

	l = 0;
	if ((flags->spec == 'i' || flags->spec == 'd' )
		&& flags->zero == 0 && flags->sign == -1)
	{
		*buffer = ft_strjoin("-", *buffer, 2);
		l = 1;
	}
	else if ((flags->spec == 'i' || flags->spec == 'd' )
		&& flags -> zero == 0 && flags->plus == 1 && flags->sign == 1)
	{
		*buffer = ft_strjoin("+", *buffer, 2);
		l = 1;
	}
	else if ((flags->spec == 'x' || flags->spec == 'X') && flags-> zero == 0
		&& flags-> alt == 1 && flags->sign == 1 && flags->costi == 0)
	{
		if (flags->spec == 'x')
			*buffer = ft_strjoin("0x", *buffer, 2);
		if (flags->spec == 'X')
			*buffer = ft_strjoin("0X", *buffer, 2);
	}
	return (l);
}

int	ft_put_minus1(int buffer_len, t_flags *flags, char **buffer)
{
	int		l;

	l = 0;
	if (flags->sign == -1 && flags->zero == 1)
	{
		if (buffer_len >= flags->width)
		{
			*buffer = ft_strjoin("-", *buffer, 2);
			l = 1;
		}
		else if (buffer_len < flags->width)
			*buffer[0] = '-';
	}
	return (l);
}

int	ft_probel(t_flags *flags, char **buffer)
{
	int	l;

	l = 0;
	if ((flags->spec == 'i' || flags->spec == 'd' )
		&& flags->prob == 1 && flags->zero == 0 && flags->sign == 1)
	{
		*buffer = ft_strjoin(" ", *buffer, 2);
		l = 1;
	}
	return (l);
}

int	ft_put_precision(unsigned long long nbr, t_flags *flags, char **buffer)
{
	int	buffer_len;
	int	ret;
	int	i;

	buffer_len = ft_nbrlen(nbr, flags);
	if (flags->precision > buffer_len)
		ret = flags->precision;
	else
		ret = buffer_len;
	*buffer = (char *)malloc(sizeof(char) * ret + 1);
	if (!(*buffer))
		return (0);
	i = -1;
	(*buffer)[ret] = '\0';
	while (buffer_len + ++i < ret)
		(*buffer)[i] = '0';
	i = 1;
	if (nbr == 0 && flags->precision != 0)
		(*buffer)[ret - i] = '0';
	while (nbr)
	{
		(*buffer)[ret - i++] = ft_baseset(flags->spec)[nbr % flags->nbr_base];
		nbr /= flags->nbr_base;
	}
	return (buffer_len);
}

int	ft_print_nbr(unsigned long long nbr, t_flags *flags)
{
	char	*buffer;
	int		buffer_len;
	int		ret;

	if (flags->spec == 'x' || flags->spec == 'X' || flags->spec == 'p')
		flags->nbr_base = 16;
	if ((flags->spec == 'd' || flags->spec == 'i') && (int)nbr < 0)
	{
		flags->sign = -1;
		nbr = -nbr;
	}
	buffer_len = ft_put_precision(nbr, flags, &buffer);
	if (nbr == 0)
		flags->costi = 1;
	buffer_len += ft_probel(flags, &buffer);
	buffer_len += ft_put_znak(flags, &buffer);
	if (flags->spec == 'p')
		buffer_len = ft_ptr_prefix(&buffer);
	ret = put_width_str(&buffer, flags);
	ret += ft_put_minus1(buffer_len, flags, &buffer);
	ft_putstr(buffer);
	free(buffer);
	return (ret);
}
