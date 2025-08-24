/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:14:59 by smerante          #+#    #+#             */
/*   Updated: 2025/07/21 16:56:18 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t					i;
	unsigned char			*ptrdst;
	unsigned char			*ptrsrc;

	if (!dst && !src)
		return (NULL);
	ptrdst = (unsigned char *)dst;
	ptrsrc = (unsigned char *)src;
	if (ptrsrc < ptrdst && ptrdst < ptrsrc + len)
	{
		i = len;
		while (i-- > 0)
			ptrdst[i] = ptrsrc[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			ptrdst[i] = ptrsrc[i];
			i++;
		}
	}
	return (dst);
}

/* int	main(void)
{
	char src[] = "Hi people";
	char dst[50]; //= "Hello World!";
	printf("%s\n", ft_memmove(dst, src, 4));
	return (0);
} */
//try to print the uninitialized dst[50]
//and got problems with the output
//i had to add a check for the overlap
//of the memory of dst and src to flag all green
//i had to modify the conditions to cover more tests, even the null