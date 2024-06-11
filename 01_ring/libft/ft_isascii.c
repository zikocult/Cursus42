/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:22:52 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/11 12:26:16 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int main(void)
{
	printf("%i\n", isascii('a'));
	printf("%i\n", isascii(1));
	printf("%i\n", isascii('1'));
	printf("%i\n", isascii('5'));
	printf("%i\n", isascii(':'));
}*/
