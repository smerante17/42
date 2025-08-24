/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpohl <cpohl@student.42.de>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:00:56 by cpohl             #+#    #+#             */
/*   Updated: 2025/08/20 16:35:24 by cpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	_i_handling(int i, char *buffer, char *temp)
{
	if (i < 0)
	{
		buffer[0] = '\0';
		return (-1);
	}
	if (i == 0)
	{
		buffer[0] = '\0';
		if (!temp || temp[0] == '\0')
			return (0);
		return (1);
	}
	buffer[i] = '\0';
	return (2);
}

static char	*_read_until_newline(int fd, char *buffer, char *temp)
{
	int		i;
	int		st;
	char	*result;

	while (!ft_strchr(temp, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		st = _i_handling(i, buffer, temp);
		if (st == -1)
		{
			free (temp);
			return (NULL);
		}
		if (st == 0 || st == 1)
			return (temp);
		result = ft_strjoin(temp, buffer);
		if (!result)
		{
			free (temp);
			return (NULL);
		}
		free (temp);
		temp = result;
	}
	return (temp);
}

static void	_get_rest(char *buffer, char *temp)
{
	char	*pos;
	size_t	position;
	size_t	counter;

	counter = 0;
	pos = ft_strchr(temp, '\n');
	if (!pos)
	{
		buffer[0] = '\0';
		return ;
	}
	position = pos - temp;
	while (temp[counter + position + 1] != '\0')
	{
		buffer[counter] = temp[counter + position + 1];
		counter++;
	}
	buffer[counter] = '\0';
}

static char	*_fill_line(char *temp)
{
	char	*temporary;
	char	*pos;

	temporary = ft_strdup(temp);
	free(temp);
	if (!temporary)
		return (NULL);
	pos = ft_strchr(temporary, '\n');
	if (!pos)
		return (temporary);
	temp = ft_substr(temporary, 0, (pos - temporary) + 1);
	if (!temp)
	{
		free (temporary);
		return (NULL);
	}
	free (temporary);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	buffer[FD_MAX][BUFFER_SIZE + 1];
	char		*temp;
	char		*result;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_strdup(buffer[fd]);
	if (!temp)
		return (NULL);
	temp = _read_until_newline(fd, buffer[fd], temp);
	if (!temp)
		return (NULL);
	if (temp[0] == '\0')
	{
		free (temp);
		return (NULL);
	}
	_get_rest(buffer[fd], temp);
	result = _fill_line(temp);
	if (!result)
		return (NULL);
	return (result);
}
