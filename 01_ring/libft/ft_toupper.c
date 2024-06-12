/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:19:16 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/12 18:30:01 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}
/*
int main ()
{
	printf("%c\n", ft_toupper('a'));
	printf("%c\n", ft_toupper('A'));
	printf("%c\n", ft_toupper(91));
	printf("%c\n", ft_toupper('z'));
	printf("%c\n", ft_toupper('Z'));
}*/
