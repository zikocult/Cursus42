/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:48:30 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/11 12:29:43 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/*
int main(void)
{
	printf("%i\n", isalpha('a'));
	printf("%i\n", isalpha(1));
	printf("%i\n", isalpha('z'));
	printf("%i\n", isalpha('Z'));
	printf("%i\n", isalpha(':'));
}*/
