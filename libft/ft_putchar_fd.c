/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:47:03 by smerante          #+#    #+#             */
/*   Updated: 2025/08/13 15:02:05 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
/* #include <stdio.h>
#include <string.h> */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}

/* int	main(void)
{
	char	c;
	int		fd;

	c = 'a';
	fd = 2;
	ft_putchar_fd(c, fd);
	fd = 1;
	ft_putchar_fd(c, fd);
	fd = 0;
	ft_putchar_fd(c, fd);
	return (0);
} */