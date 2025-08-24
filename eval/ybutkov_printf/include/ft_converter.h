/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:49:00 by ybutkov           #+#    #+#             */
/*   Updated: 2025/08/04 20:09:11 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERTER_H
# define FT_CONVERTER_H

// int				get_index_in_base(char *base_from, char ch);
// int				check_base(char *base);
// int				calc_number(char *nbr, char *base_from, int number);
// int				int_to_base(long n, int base_size, int index_base,
// 					char **base_data);
// long			base_to_long(char *nbr, char *base_from);
// char			*get_array(char str[50]);
// void			set_zero_to_base(char *base_to, char *base_num);
// char			*ft_convert_base(char *nbr, char *base_from, char *base_to);
// char			*int_to_hex(int nbr, char *base, unsigned int base_size);
char			*p_to_hex(void *p, char *base, unsigned int base_size);
// char			*llint_to_hex(long long int nbr, char *base,
// 					unsigned int base_size);

// unsigned int	ft_calculate_len_new_nbr(int nbr, char *base);
// char			*to_base(int nbr, char *base);
char			*ft_ultoa(unsigned long n);
// char			*ft_lltoa(long long n);
// char			*ft_ulltoa(unsigned long long n);

char			*unlong_to_hex(unsigned long nbr, char *base,
					unsigned int base_size);

#endif