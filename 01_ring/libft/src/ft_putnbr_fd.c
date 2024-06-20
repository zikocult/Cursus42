/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:26:16 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/20 16:53:47 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long	lnb;

	lnb = nb;
	if (lnb < 0)
	{
		lnb *= -1;
		ft_putchar_fd('-', fd);
	}
	if (lnb >= 10)
	{
		ft_putnbr_fd(lnb / 10, fd);
		lnb = lnb % 10;
	}
	if (lnb < 10)
		ft_putchar_fd(lnb + '0', fd);
}
