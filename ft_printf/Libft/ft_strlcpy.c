/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:10:05 by damarry           #+#    #+#             */
/*   Updated: 2021/10/11 19:26:43 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srcs;

	i = 0;
	srcs = ft_strlen(src);
	if (srcs < dstsize)
	{
		while (i < srcs && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		return (srcs);
	}
	else if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcs);
}
