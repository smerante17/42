/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:44:34 by smerante          #+#    #+#             */
/*   Updated: 2025/07/22 11:12:50 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	while (s[i] != ch && i > 0)
	{
		i--;
	}
	if (s[i] == ch)
	{
		return ((char *) &s[i]);
	}
	else
	{
		return (NULL);
	}
}

// int	main(void)
// {
// 	char	s[7];
// 	int		c;
// 	int		d;
// 	int		e;

// 	e = 's';
// 	c = 'x';
// 	d = 'h';
// 	strcpy(s, "teste");
// 	printf("%s\n", ft_strrchr(s, c));
// 	printf("%s\n", ft_strrchr(s, d));
// 	printf("%s", ft_strrchr(s, e));
// 	return (0);
// }