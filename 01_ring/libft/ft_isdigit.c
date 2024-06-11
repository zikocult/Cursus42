/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:12:32 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/11 20:28:12 by ZikoCult         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
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
