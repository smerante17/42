/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:19:33 by smerante          #+#    #+#             */
/*   Updated: 2025/08/08 17:47:45 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h>
#include <string.h> */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}

/* void	f(unsigned int i, char *c)
{
	(void)i;
	*c = ft_toupper(*c);
	return ;
} */

/* int	main(void)
{
	char	s[15];

	ft_strlcpy(s, "hi 42 world!", 15);
	ft_striteri(s, f);
	printf("%s\n", s);
	return (0);
} */

/*
22: checking if the argument is empty
24: until i reach the '\0', iapply the f
 function to every single index of the string
26: i need to use &s[i] to specify that this is a pointer to a char
29: only return because this is a void function, like f
34: casting i in void to let the function ignore it.
35: i use for example toupper function to modify
 the pointer at the actual index
43: i need to use this strcpy or strlcpy to copy the string
 in the array, i can't assign a literal string to an array
The difference between strmapi and this function is that
the argument passed in f is a pointer to a char (char*), not a char
*/