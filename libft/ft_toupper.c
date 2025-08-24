/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:42:26 by smerante          #+#    #+#             */
/*   Updated: 2025/07/21 18:08:10 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c -= 32);
	}
	else
	{
		return (c);
	}
}

/* int	main(void)
{
	int	c;

	c = 'g';
	printf("%c", ft_toupper(c));
	return (0);
} */
//i used "%c" to print the correct output
//even if the function requires an integer
//with "d%" i will get the ascii digits of the char