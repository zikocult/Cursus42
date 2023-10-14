/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZikoCult <ZikoCult>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:34:57 by ZikoCult          #+#    #+#             */
/*   Updated: 2023/10/13 20:25:26 by ZikoCult         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
	return (s);
}

/* int main(void) */
/* { */
/* 	char str[50]; */
/* 	strcpy(str, "This is string.h library function"); */
/* 	puts(str); */
/* 	ft_bzero(str, 5); */
/* 	puts(str); */
/* 	printf("%s\n", str); // Es el mateix que PUTS */
/* 	return EXIT_SUCCESS; */
/* } */
