/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:18:52 by larlyne           #+#    #+#             */
/*   Updated: 2019/04/13 15:04:17 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src,
				size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memalloc(size_t size);
char			*ft_strnew(size_t size);
void			*ft_realloc(void *src, size_t old_size, size_t new_size);
#endif
