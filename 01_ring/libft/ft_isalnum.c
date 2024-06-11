/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:17:52 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/11 12:29:17 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
		|| (c >= 48 && c <= 57))
		return (1);
	return (0);
}
/*
int main(void)
{
	printf("%i\n", isalnum('a'));
	printf("%i\n", isalnum(1));
	printf("%i\n", isalnum('1'));
	printf("%i\n", isalnum('Z'));
	printf("%i\n", isalnum(':'));
}*/
