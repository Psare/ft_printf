/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:58:08 by damarry           #+#    #+#             */
/*   Updated: 2021/11/19 22:09:47 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(int c, t_flags *flags)
{
	int	ret;

	ret = 0;
	if (flags->spec == '%' && flags->negative == 1)
		flags->zero = 0;
	if (flags->negative == 1)
		ret += ft_putchar(c);
	ret += put_width_c(flags->width, 1, flags->zero);
	if (flags->negative == 0)
		ret += ft_putchar(c);
	return (ret);
}

int	put_width_c(int width, int len, int zero)
{
	int	ret;

	ret = 0;
	while (len < width)
	{
		if (zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len++;
		ret++;
	}
	return (ret);
}

int	ft_nbrlen(unsigned long long nbr, t_flags *flags)
{
	int	i;

	if (nbr == 0 && flags->precision != 0)
		return (1);
	i = 0;
	while (nbr)
	{
		i++;
		nbr /= flags->nbr_base;
	}
	return (i);
}

int	ft_ptr_prefix(char **buffer)
{
	*buffer = ft_strjoin("0x", *buffer, 2);
	return (ft_strlen(*buffer));
}

char	*ft_baseset(char spec)
{
	if (spec == 'u' || spec == 'd' || spec == 'i')
		return ("0123456789");
	else if (spec == 'x' || spec == 'p')
		return ("0123456789abcdef");
	else if (spec == 'X')
		return ("0123456789ABCDEF");
	return (0);
}
