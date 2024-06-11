/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:12:32 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/11 12:16:56 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (0);
	return (1);
}
/*
int main(void)
{
	printf("%i\n", isdigit('a'));
	printf("%i\n", isdigit(1));
	printf("%i\n", isdigit('1'));
	printf("%i\n", isdigit('5'));
	printf("%i\n", isdigit(':'));
}*/
