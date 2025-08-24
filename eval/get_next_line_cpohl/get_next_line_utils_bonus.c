/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpohl <cpohl@student.42.de>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:01:00 by cpohl             #+#    #+#             */
/*   Updated: 2025/08/18 14:08:48 by cpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	size_t	counter;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	counter = 0;
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (counter < len && s[start + counter] != '\0')
	{
		str[counter] = s[start + counter];
		counter++;
	}
	str[counter] = '\0';
	return (str);
}

char	*ft_strchr(char *str, char ch)
{
	int		counter;

	counter = 0;
	if (!str)
		return (NULL);
	while (str[counter] != '\0')
	{
		if (str[counter] == ch)
			return ((char *)&str[counter]);
		counter++;
	}
	if (ch == '\0')
		return ((char *)&str[counter]);
	return (NULL);
}

char	*ft_strdup(char *str1)
{
	char	*temp;
	int		counter;

	counter = 0;
	if (!str1)
		return (NULL);
	temp = malloc(ft_strlen(str1) + 1);
	if (!temp)
		return (NULL);
	while (str1[counter] != '\0')
	{
		temp[counter] = str1[counter];
		counter++;
	}
	temp[counter] = '\0';
	return (temp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*temp;
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	temp = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!temp)
		return (NULL);
	while (s1[counter] != '\0')
	{
		temp[counter] = s1[counter];
		counter++;
	}
	while (s2[i] != '\0')
	{
		temp[counter + i] = s2[i];
		i++;
	}
	temp[counter + i] = '\0';
	return (temp);
}

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	if (!str)
		return (0);
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}
