/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:08:46 by smerante          #+#    #+#             */
/*   Updated: 2025/07/21 19:01:37 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>
#include <string.h> */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i]
			|| s1[i] == '\0' || s2[i] == '\0')
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

/* int	main(void)
{
	char	s1[10];
	char	s2[10];

	strcpy(s1, "hello");
	strcpy(s2, "helLo");
	printf("%d", ft_strncmp(s1, s2, 5));
	return (0);
}
 */
//line24 and 27: i had to cast
// them to handle chars that
// are not in the ascii table