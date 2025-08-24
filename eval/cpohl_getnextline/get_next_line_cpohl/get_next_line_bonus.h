/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpohl <cpohl@student.42.de>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:35:54 by cpohl             #+#    #+#             */
/*   Updated: 2025/08/20 16:20:10 by cpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <fcntl.h>
# include <unistd.h>
# include <printf.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*get_next_line_bonus(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(char *str, char ch);
char	*ft_strdup(char *str1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);

#endif