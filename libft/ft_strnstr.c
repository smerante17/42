/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:45:56 by smerante          #+#    #+#             */
/*   Updated: 2025/07/21 19:57:54 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>
#include <string.h> */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j]
			&& i + j < len && haystack[i + j] == needle[j])
		{
			j++;
		}
		if (needle[j] == '\0')
		{
			return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	haystack[25];
	char	needle[5];

	strcpy(haystack, "hello salut hi");
	strcpy(needle, "hi");
	printf("%s", ft_strnstr(haystack, needle, 14));
	return (0);
} */
//-line23: if the needle is empty, i return the haystack.
//-line27: while i < len and you are not at the end of the haystack
//i check if the needle is present in the haystack.
//-line29: i check if i am at the end of needle or
// haystack and if the actual char in needle and haystack are equal
//-line39: i return a pointer
//to the firts char in the haystack.