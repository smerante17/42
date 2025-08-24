/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:59:17 by smerante          #+#    #+#             */
/*   Updated: 2025/07/22 11:04:13 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>
#include <string.h> */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

/* int	main(void)
{
	char	s[10];
	int		c;

	c = 't';
	strcpy(s, "hello");
	printf("%s", ft_strchr(s, c));
	return (0);
} */

//line 26 and 32: i used ((char *)&s[i])
//because it needs to match
//the return type of the function
//that is (char *), instead i was 
//using a type 'const char *'
//line24: i had to cast the variable c
// to be able to confront s[i] and c.
