/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:48:54 by smerante          #+#    #+#             */
/*   Updated: 2025/08/06 19:02:46 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h>
#include <string.h> */

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*copy1;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	copy1 = malloc(i + 1);
	if (!copy1)
	{
		return (NULL);
	}
	j = 0;
	while (j <= i)
	{
		copy1[j] = s1[j];
		j++;
	}
	return (copy1);
}

/* int	main(void)
{
	char	*s1;

	s1 = "Hello World!";
	printf("%s", ft_strdup(s1));
	return (0);
} */

//line28: allocation of n 'i' bytes to copy1 + 1 for '\0'
//line29-32: if copy1 is null, return null
//line33-39: set the counter j to 0,
// while the counter is less or equal(for '\0') to the one i used
// to count the bytes to allocate to copy1,
// copy the char of s1[j] to copy1[j],
// increasing the j counter every time it copies
// and return the string copy1 in the end