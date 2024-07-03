/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:18:23 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/03 13:18:15 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf(const char *str, ...);
void	ft_putchar_pf(char c, int *count);
void	ft_putstr_pf(char *str, int *count);
void	ft_nbr_pf(int nbr, int *count);
void	ft_unnbr_pf(unsigned int nbr, int *count);
void	ft_hexa_pf(unsigned long int num, char *base, int *count);
void	ft_pointer_pf(void *pointer, int *count);

#endif
