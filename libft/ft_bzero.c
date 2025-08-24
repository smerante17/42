/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:11:22 by smerante          #+#    #+#             */
/*   Updated: 2025/08/06 18:53:08 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int		i;
	char				*ptrs;

	i = 0;
	ptrs = (char *)s;
	while (i != n)
	{
		ptrs[i] = 0;
		i++;
	}
}

// int	main(void)
// {
// 	int		i;
// 	char	s[] = "Hello!";

// 	i = 0;
// 	ft_bzero(s, 2);
// 	while (i < 6)
// 	{
// 		printf("%c", s[i]);
// 		i++;
// 	}
// 	return (0);
// }

/* printf("string is %c\n", s[0]);
	printf("string is %c\n", s[1]);
	printf("string is %c\n", s[2]);
	printf("string is %c\n", s[3]);
	printf("string is %c\n", s[4]);
	printf("string is %c", s[5]); */