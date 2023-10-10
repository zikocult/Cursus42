/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZikoCult <ZikoCult>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:54:00 by ZikoCult          #+#    #+#             */
/*   Updated: 2023/10/09 20:12:37 by ZikoCult         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		s++;
		count++;
	}
	return (count);
}

/* int main(void) */
/*   { */
/*   printf("Longitud = %li\n", ft_strlen("")); */
/*   printf("Longitud = %li\n", strlen("")); */
/*   printf("Longitud = %li\n", ft_strlen(" :\n234/093kdia")); */
/*   printf("Longitud = %li\n", strlen(" :\n234/093kdia")); */
/*   printf("Longitud = %li\n", ft_strlen("Hello World!")); */
/*   printf("Longitud = %li\n", strlen("Hello World!")); */
/*   printf("Longitud = %li\n", ft_strlen(" i ")); */
/*   printf("Longitud = %li\n", strlen(" i ")); */
/*   printf("Longitud = %li\n", ft_strlen("Ramona")); */
/*   printf("Longitud = %li\n", strlen("Ramona")); */
/*   return (0); */
/*   } */
