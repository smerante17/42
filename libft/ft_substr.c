/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 09:38:01 by smerante          #+#    #+#             */
/*   Updated: 2025/07/31 19:00:50 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h> */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	str_len;
	size_t	copy_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	copy_len = str_len - start;
	if (len < copy_len)
		copy_len = len;
	new_str = malloc(copy_len + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s + start, copy_len);
	new_str[copy_len] = '\0';
	return (new_str);
}

/* int	main(void)
{
	char	s[10];

	ft_strlcpy(s, "HelloWorld", 10);
	printf("%s", ft_substr(s, 0, 7));
	return (0);
} */

/*
Lines 5-6: null-check, returns NULL immediately
if input string doesn't exist.
Line 7: calculates the complete length of
the source string using ft_strlen.
Lines 8-9: handles edge case where start position
is beyond string length. Returns a new empty string
Lines 10-12: calculates the actual copy length
Lines 13-15: memory allocation with safety checks
Lines 16-17: ft_memcpy safely copies the exact needed characters
Line 18: final return of the new substring (or NULL if earlier checks failed).
*/