/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:20:59 by smerante          #+#    #+#             */
/*   Updated: 2025/08/03 14:05:56 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/* #include <string.h>
#include <stdio.h> */

static int	ft_words_count(const char *s, char c)
{
	size_t	i;
	size_t	count;
	int		iaminword;

	i = 0;
	count = 0;
	iaminword = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && iaminword == 0)
		{
			iaminword = 1;
			count++;
		}
		else if (s[i] == c)
		{
			iaminword = 0;
		}
		i++;
	}
	return (count);
}

static char	*ft_strndup_words(const char *s, size_t start, size_t len)
{
	size_t	i;
	char	*newstr;

	if (!s)
		return (NULL);
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		newstr[i] = s[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

static void	free_words(char **words, size_t count)
{
	while (count--)
		free(words[count]);
	free(words);
}

static int	process_word(const char *s, char **res, size_t *i, char c)
{
	i[2] = 0;
	while (s[i[0] + i[2]] && s[i[0] + i[2]] != c)
		i[2]++;
	if (i[2] > 0)
	{
		res[i[1]] = ft_strndup_words(s + i[0], 0, i[2]);
		if (!res[i[1]])
			return (0);
		i[1]++;
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	i[3];

	i[0] = 0;
	i[1] = 0;
	res = malloc((ft_words_count(s, c) + 1) * sizeof(char *));
	if (!s || !res)
		return (NULL);
	while (s[i[0]])
	{
		while (s[i[0]] == c)
			i[0]++;
		if (!process_word(s, res, i, c))
			return (free_words(res, i[1]), NULL);
		i[0] += i[2];
	}
	res[i[1]] = NULL;
	return (res);
}
/* int	main(void)
{
	char	*s;
	char	c;
	char	**result;
	size_t	i;

	i = 0;
	c = '+';
	s = "++Hello++Word+42!+";
	result = ft_split(s, c);
	while (result[i])
	{
		printf("%s\n", result[i++]);
	}
	return (0);
} */
/*
Including stdlib.h for correctly using malloc.
line26: until i reach the end of the string
line28: if the index is not equal c and i am not in a word,
i set 1(i am in a word) and update the count of words
line33: if the index is equal to c, i've reached the end
of the word (delimiter),
so i set 0 to iaminword and update the idnex outside the loop.
in the end i return the count of the words.
line42: create a function to duplicate the substring
line48: i allocate memory for every char of the
founded word with len + 1
line51: i copy the single chars until i
reach the len of the word and return the copied string
Line72: defining a function to process the words using pointer at
split variables that are modifying directly the variable value
Line74: reset the word lenght counter
Line75: calculating the lenght (i[2]) until the delimiter (c)
Line77: processing only if the world is greater than 0
Line79: duplicating the world into the array
 of strings at the right index
Line80: checking if the duplication fails, return 0 if that's the case
 and malloc fails.
Line82: increment the word counter only if malloc is ok.
Line84: return 1 if everything is ok.
line90: i[0] = string position, i[1] = word count,
 i[2] = word lenght.
Line92-93: initializing the position in string i[0] = 0 and
the word count i[1].
Line94: allocation of needed memory for every word
Line95: checking if the allocation fails or the argument is empty
Line99: skipping all the delimiter chars.
Line101: run the function to process the words and
 insert them at the right index in the array of strings,
 return null if the function or malloc in it fails
 freeing the space with free_words in case
Line103: move forward to the next potential word
Line105: adding NULL at the last index of the array of strings
Line106: returning the array of strings.
*/