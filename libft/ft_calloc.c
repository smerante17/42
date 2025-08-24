/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerante <smerante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:29:49 by smerante          #+#    #+#             */
/*   Updated: 2025/07/23 21:07:29 by smerante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/* #include <stdio.h> */

void	*ft_calloc(size_t count, size_t size)
{
	size_t			totsize;
	void			*ptr;
	unsigned char	*p;
	size_t			i;

	totsize = count * size;
	ptr = malloc(totsize);
	if (!ptr)
	{
		return (NULL);
	}
	p = (unsigned char *)ptr;
	i = 0;
	while (i < totsize)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}

/* int	main(void)
{
	size_t			count;
	size_t			size;
	unsigned char	*ptr;
	size_t			i;

	count = 3;
	size = 4;
	ptr = ft_calloc(count, size);
	if (!ptr)
	{
		printf("failed allocation\n");
		return (1);
	}
	i = 0;
	while (i < count * size)
	{
		printf("ptr[%zu] = %d\n", i, ptr[i]);
		i++;
	}
	free (ptr);
	return (0);
} */

//line23-24: the 'totsize' we need
// is the number of elements 'count'
// multiplied by the 'size' of ech element
// with malloc we are allocating 'totsize' bytes in ptr,
// we have to initialize the ptr with void to have flexibility.
//line27: if ptr is NULL, return null.
//line29: casting the void *ptr in unsigned char
// to access the memory in
// the best way,
// the only way to do
// that is by using
// an unsigned char
// because is the data type used to
// manipuate memory in C
// and put 0 in every single byte of p.
// a best practice is to free the pointer
// after the allocation, to free the memory 