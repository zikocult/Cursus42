/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZikoCult <ZikoCult>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:53:45 by ZikoCult          #+#    #+#             */
/*   Updated: 2023/10/09 22:40:57 by ZikoCult         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// Necesarios, librerias para NULL, SIZE, MALLOC y WRITE
// LIMITS no es necesaria, pero ayuda
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <limits.h>

// No son necesarios excepto para los test
# include <stdio.h>
# include <string.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_bzero(void *s, size_t n);

#endif
