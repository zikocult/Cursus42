/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZikoCult <ZikoCult>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:55:37 by ZikoCult          #+#    #+#             */
/*   Updated: 2023/10/09 22:31:01 by ZikoCult         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		n--;
	}
	return (s);
}
/**/
/* int main(void) */
/* { */
/* 	char str[50]; */
/* 	strcpy(str, "This is string.h library function"); */
/* 	puts(str); */
/* 	ft_memset(str, '$', 15); */
/* 	printf("%s\n", str); // Es el mateix que PUTS */
/* 	return EXIT_SUCCESS; */
/* } */
