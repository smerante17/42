/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:12:40 by smerante          #+#    #+#             */
/*   Updated: 2025/07/21 19:24:55 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>
#include <string.h> */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (unsigned char *) s1;
	ptr2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
		{
			return (ptr1[i] - ptr2[i]);
		}
		i++;
	}
	return (0);
}

/* int	main(void)
{
	char	s1[15];
	char	s2[15];

	strcpy(s1, "hello world");
	strcpy(s2, "hello worlD");
	printf("%d", ft_memcmp(s1, s2, 10));
	return (0);
}*/
//i had to cast the void s1 and 2 into an unsigned char
//to be able to perform these operations
// and equalyize the data type
//line28: the condition tells that at the firt two different bytes
//it will return the difference between them. 