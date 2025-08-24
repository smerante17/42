/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:15:22 by smerante          #+#    #+#             */
/*   Updated: 2025/07/21 10:18:25 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	char		*ptrb;

	i = 0;
	ptrb = (char *)b;
	while (len--)
	{
		ptrb[i] = c;
		i++;
	}
	return (b);
}

/* int	main(void)
{
	char	b[20];
	char	c;
	char	*ptb

	*ptb = b[20];
	*ptb = "testing function";
	c = 'S';
	ft_memset(b, c, 4);
	printf("string is %s", b);
	return (0);
} */

// line 22 to casting a *void into *char unsing a pointer to store the value