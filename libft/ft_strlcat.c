/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:28:22 by smerante          #+#    #+#             */
/*   Updated: 2025/07/21 19:55:30 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>
#include<string.h> */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_lenght;
	size_t	src_lenght;

	dst_lenght = 0;
	src_lenght = 0;
	while (dst[dst_lenght] && dst_lenght < dstsize)
		dst_lenght++;
	while (src[src_lenght])
		src_lenght++;
	if (dst_lenght == dstsize)
		return (dstsize + src_lenght);
	i = 0;
	while (src[i] && dst_lenght + i < dstsize - 1)
	{
		dst[dst_lenght + i] = src[i];
		i++;
	}
	if (dst_lenght + i < dstsize)
	{
		dst[dst_lenght + i] = '\0';
	}
	return (dst_lenght + src_lenght);
}

/* int	main(void)
{
	char	dst[10];
	char	src[10];

	strcpy(src, " World");
	strcpy(dst, "Hello");
	ft_strlcat (dst, src, 10);
	printf("%s", dst);
	return (0);
} */
//line25-30: i wrote this to get
// the size of the strings
// and if the size and lenght are equal
// it will return the lenght (dst_lenght + src_lenght)
// that the string sohould have been.
//line32-41: i wrote a condition to check
// if the total size fit in the dstsize - 1 
// to be able to add the '\0'
// at the end of the string,
// then i concat the string based on the dst_lenght + the counter
// and increase the counter until i reach the limit of dstsize
// in the end i add the '\0' if the string is long enough
// and return the total lenght of the
// string without considering the dstsize
// it is very useful to find truncation in strings.