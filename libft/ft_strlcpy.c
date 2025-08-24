/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:47:26 by smerante          #+#    #+#             */
/*   Updated: 2025/08/03 18:19:39 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
	{
		i++;
	}
	return (i);
}

/* int	main(void)
{
	char	src[20];
	char	dst[20];
	char	*ptsrc;
	char	*ptdst;

	ptsrc = src;
	ptdst = dst;
	ptsrc = "Hello World!";
	ft_strlcpy(ptdst, ptsrc, 8);
	printf("%s\n", dst);
	return (0);
} */
//line23-28: i had to write this condition
// to assure that i had not reach the end of the src string
// and that it will secure space for 
// the null terminator at the end of the string
// comparing the counter i to the dstsize - 1
// to add the null terminator
// then i copy the chars until i reach the dstsize