/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:16:11 by smerante          #+#    #+#             */
/*   Updated: 2025/08/02 18:21:56 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
/* #include <limits.h>
#include <string.h>
#include <stdio.h> */

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

/* int	main(void)
{
	int	n;
	int	fd;

	n = -123;
	fd = 0;
	ft_putnbr_fd(n, fd);
	write(1, "\n", 1);
	n = -2147483648;
	ft_putnbr_fd(n, fd);
	write(1, "\n", 1);
	n = INT_MAX;
	ft_putnbr_fd(n, fd);
	write(1, "\n", 1);
	return (0);
} */

/* 
Line 23: Handle INT_MIN special case (-2147483648)
 and can't be converted in positive
Line 28: Handle negative number,
 write '-' and convert to positive
 for semplify the next processing
Line 33: Recursive case for multi-digit numbers
 process all digits except the last one recursively
Line 37: Convert last digit to ASCII and write,
 Modulo (%) gets the last digit and +'0' converts to ASCII
*/