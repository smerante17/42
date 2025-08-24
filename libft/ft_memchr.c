/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:30:39 by smerante          #+#    #+#             */
/*   Updated: 2025/08/13 15:02:08 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>
#include <string.h> */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int		i;
	const unsigned char	*ptrs;

	ptrs = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptrs[i] == (unsigned char)c)
		{
			return ((char *) &ptrs[i]);
		}
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	s[10];
	int		c;
	int		d;
	int		e;

	c = 'l';
	d = 'h';
	e = 'q';
	strcpy(s, "hello");
	printf("%s\n", ft_memchr(s, c, 5));
	printf("%s\n", ft_memchr(s, d, 5));
	printf("%s", ft_memchr(s, e, 5));
	return (0);
} */
//line 19-22: i had to cast the variable 
//from const void to const unsigned char
//and put its value in the pointer ptrs
//to make the function work,
//otherwise it will not accept the variable
//the function will return
//a pointer to the value inside the string
//and, if the char is not persent will return (NULL)
//line26: for the same reason as before,
// i had to cast the c variable from int to unsigned char