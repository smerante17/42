/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:03:07 by smerante          #+#    #+#             */
/*   Updated: 2025/07/13 15:17:23 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c < 'A' || c > 'Z')
		&& (c < 'a' || c > 'z'))
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

/* int	main(void)
{
	printf("%d", ft_isalpha('t'));
	return (0);
} */