/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:17:57 by smerante          #+#    #+#             */
/*   Updated: 2025/07/24 17:01:25 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <string.h>
#include <stdio.h> */

int	ft_inset(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*str;

	start = 0;
	end = 0;
	len = 0;
	str = NULL;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[start] && ft_inset(s1[start], set))
		start++;
	while (end > start && ft_inset(s1[end - 1], set))
		end--;
	len = end - start;
	str = ft_substr(s1, start, len);
	if (!str)
		return (NULL);
	return (str);
}

/* int	main(void)
{
	char	*s1;
	char	*set;

	s1 = "--++-+sssaaasMy name is Albertssaaaaaass";
	set = "-+as";
	printf("%s", ft_strtrim(s1, set));
	return (0);
} */

//line22:until i reach \0
//line24:i check that c is in set and increment until i reach \0
//line25:if the char is present, return 1, else 0
//line41:checking parameters
//line43:found s1 last char
//line44:if start is not \0 and the
// actual index is present in s1, increment the counter
//line46:i check that i don't go further than start and the actual
// index is present in set. -1 because i do not want to check \0
//line48:real lenght to copy in the new string
//line49:allocates memory and create a substring from s1
//line50:check the mem alloc