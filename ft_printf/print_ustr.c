/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ustr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:24:04 by damarry           #+#    #+#             */
/*   Updated: 2021/11/19 22:09:42 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_width_str(char **buffer, t_flags *flags)
{
	char	*width;
	int		i;

	if (flags->width <= (int)ft_strlen(*buffer))
		return ((int)ft_strlen(*buffer));
	width = (char *)malloc(sizeof(char)
			* (flags->width - ft_strlen(*buffer) + 1));
	i = 0;
	while ((size_t)i < flags->width - ft_strlen(*buffer))
	{
		if (flags->zero == 1)
			width[i] = '0';
		else
			width[i] = ' ';
		i++;
	}
	width[i] = '\0';
	if (flags->negative == 0)
		*buffer = ft_strjoin(width, *buffer, 3);
	else
		*buffer = ft_strjoin(*buffer, width, 3);
	return (flags->width);
}

char	*parse_buffer(char *str, int end, int len)
{
	int		i;
	char	*buffer;

	if (end > len)
		end = len;
	buffer = (char *)malloc(sizeof(char) * end + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < end)
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_str(char *str, t_flags *flags)
{
	int		ret;
	char	*buffer;

	ret = 0;
	if (str == NULL)
		str = "(null)";
	if (flags->precision == -1 || (size_t)flags->precision > ft_strlen(str))
		flags->precision = ft_strlen(str);
	buffer = parse_buffer(str, flags->precision, ft_strlen(str));
	ret = put_width_str(&buffer, flags);
	ft_putstr(buffer);
	free(buffer);
	return (ret);
}
