/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:27:01 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/12 18:31:35 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}
/*
int main ()
{
	printf("%c\n", ft_tolower('a'));
	printf("%c\n", ft_tolower('A'));
	printf("%c\n", ft_tolower(91));
	printf("%c\n", ft_tolower('z'));
	printf("%c\n", ft_tolower('Z'));
}*/
