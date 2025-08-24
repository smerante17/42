/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:44:05 by smerante          #+#    #+#             */
/*   Updated: 2025/07/23 19:43:19 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char				*ptrdst;
	char				*ptrsrc;
	unsigned int		i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	ptrdst = (char *)dst;
	ptrsrc = (char *)src;
	while (i < n)
	{
		ptrdst[i] = ptrsrc[i];
		i++;
	}
	return (dst);
}

/* int	main(void)
{
	char	src[20];
	char	dst[2];

	src[20] = "destination";
	printf("%s\n", dst);
	ft_memcpy(dst, src, 3);
	printf("%s", dst);
	return (0);
}
 */