/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:16:11 by smerante          #+#    #+#             */
/*   Updated: 2025/08/08 17:47:39 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h>
#include <string.h> */

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*result;

	if (!s || !f)
		return (NULL);
	result = malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/* char	f(unsigned int j, char c)
{
	j = 32 ;
	return (c - j);
} */

/* int	main(void)
{
	char			*s;
	char			*result;
	unsigned int	i;

	i = 0;
	s = "helloworld";
	printf("%s\n", s);
	result = ft_strmapi(s, f);
	printf("%s\n", result);
	return (0);
} */

/*
17: this function takes as an argument a pointer to another function,
we choose what this function does defining it by ourselves using
the given arguments in the function.
22: checking if the argument is valid
24: allocating memory for a string + '\0', i could use a len variable to store
the value of ft_strlen(s) but it does not change anything
25: checking if the allocation fails and return NULL if that's the case
28: while the index is smaller than the lenght of the string, i apply the
function f for every char in the given string and in the end i will put the
null terminator and return the new string.
37: i've defined a simple function toupper to test the result, i could have
defined any function that i could.
*/