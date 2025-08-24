/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:38:14 by smerante          #+#    #+#             */
/*   Updated: 2025/07/29 20:15:24 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdlib.h>
#include <string.h>
#include <stdio.h> */

int	count_char(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		lenght;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	lenght = count_char(n);
	str = malloc (lenght + 1);
	if (!str)
		return (NULL);
	str[lenght] = '\0';
	i = lenght - 1;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

/* int	main(void)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = -112;
	b = 2;
	c = -42;
	d = -2147483648;
	printf("%s\n", ft_itoa (a));
	printf("%s\n", ft_itoa (b));
	printf("%s\n", ft_itoa (c));
	printf("%s\n", ft_itoa (d));
	return (0);
} */

//24:to include '-'
//25:to count the chars in the int
//27:extracting digits until n is 0, it delete the digits
// because an int can't handle decimal digits
//28:incrementing digits count
//30:returning the number of chars '-' included
//39:to handle the INT_MIN
//43:space to allocate in str
//45:allocating space for str + '\0'
//47:if allocation fails, return (NULL)
//49:last available position
//50:if n is negative, put '-' at the start
//55:begin to copy/convert chars in the string
//57:starting from the last available
// index i am converting in ascii
//58:deleting the last digit and decrease the index