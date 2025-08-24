/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 19:55:28 by smerante          #+#    #+#             */
/*   Updated: 2025/07/31 21:13:18 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
/* #include <string.h>
#include <stdio.h> */

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
	return ;
}

/* int	main(void)
{
	char	*s;
	int		fd;

	s = "Hello World!\n";
	fd = 0;
	ft_putstr_fd(s, fd);
	fd = 1;
	ft_putstr_fd(s, fd);
	fd = 2;
	ft_putstr_fd(s, fd);
	return (0);
}
 */