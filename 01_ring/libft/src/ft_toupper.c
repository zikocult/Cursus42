/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZikoCult <ZikoCult>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:28:21 by ZikoCult          #+#    #+#             */
/*   Updated: 2023/10/13 17:34:38 by ZikoCult         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

/* int main() */
/* { */
/*     printf("%c\n", ft_toupper('A')); */
/*     printf("%c\n", ft_toupper('a')); */
/*     printf("%c\n", ft_toupper('B')); */
/*     printf("%c\n", ft_toupper('b')); */
/*     printf("%c\n", ft_toupper('%')); */
/*     return 0; */
/* } */
