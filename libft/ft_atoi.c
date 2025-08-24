/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:40:26 by smerante          #+#    #+#             */
/*   Updated: 2025/08/06 18:53:02 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <string.h>
#include <stdio.h> */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	r;
	int	s;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	s = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			s = -1;
		}
		i++;
	}
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (s * r);
}

/* int	main(void)
{
	char	str[20];

	strcpy(str, "-345xyz");
	printf("%d", ft_atoi(str));
	return (0);
} */

//line23: checking if there are some spaces, tabs or newlines
//line27: checking the sign and store it if is negative
//line35: checking if the char is a digit 
// and convert from ascii to decimal
//line 37: the operation r = r * 10 is used
//  to build the digits one by one
//line37: the operation (str[i] - '0')
// it's used to convert from ascii to its real value
// it works only if the char is a digit between 0 and 9
//line40: return the sign and the result