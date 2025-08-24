/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:08:50 by smerante          #+#    #+#             */
/*   Updated: 2025/07/13 15:18:57 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/* #include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (*(s + count) != '\0') 
	//this operation is an alternative to helping find the end of the string
	{
		count++;
	}
	return (count);
}


int	main(void)
{
	char	*s;

	s = "Hi!";
	printf("count %zu", ft_strlen(s)); //zu because the return type is size_t
	return (0);
} */
