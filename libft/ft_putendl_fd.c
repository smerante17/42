/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:04:28 by smerante          #+#    #+#             */
/*   Updated: 2025/07/31 21:14:35 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
/* #include <string.h>
#include <stdio.h> */

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
	write(fd, "\n", 1);
	return ;
}

/* int	main(void)
{
	char	*s;
	int		fd;

	s = "Hello World!";
	fd = 0;
	ft_putendl_fd(s, fd);
	fd = 1;
	ft_putendl_fd(s, fd);
	fd = 2;
	ft_putendl_fd(s, fd);
	return (0);
} */
