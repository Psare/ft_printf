/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:58:11 by damarry           #+#    #+#             */
/*   Updated: 2021/11/20 20:40:44 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./Libft/libft.h"

# define SPEC "cspdiuxX%"
# define FLAGS "-0.# +123456789"

typedef struct s_flags
{
	int		negative;
	int		zero;
	int		plus;
	int		alt;
	int		costi;
	int		prob;
	int		width;
	int		precision;
	char	spec;
	int		nbr_base;
	int		sign;
}	t_flags;

int		ft_printf(const char *format, ...);
int		ft_print(va_list ap, t_flags *flags);
int		parse_format(va_list ap, int op, char *format);
int		ft_print_c(int c, t_flags *flags);
int		put_width_c(int width, int len, int zero);
int		put_width_str(char **buffer, t_flags *flags);
int		ft_print_str(char *str, t_flags *flags);
int		ft_ptr_prefix(char **buffer);
int		ft_put_znak(t_flags *flags, char **buffer);
int		ft_put_minus1(int buffer_len, t_flags *flags, char **buffer);
int		ft_put_precision(unsigned long long nbr, t_flags *flags, char **buffer);
int		ft_print_nbr(unsigned long long nbr, t_flags *flags);
int		ft_putstr(char *s);
int		ft_nbrlen(unsigned long long nbr, t_flags *flags);
int		ft_putchar(char c);
char	*parse_buffer(char *str, int end, int len);
char	*ft_baseset(char spec);
void	obr(t_flags *flags);
void	check_flags(char *format, t_flags *flags, int i);
void	zero_logic(t_flags *flags, char format);
void	width_precision(char *format, t_flags *flags, int i);

#endif
