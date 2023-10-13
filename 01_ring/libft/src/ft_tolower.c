/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZikoCult <ZikoCult>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:24:24 by ZikoCult          #+#    #+#             */
/*   Updated: 2023/10/13 17:26:18 by ZikoCult         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

/* int main() */
/* { */
/*     printf("%c\n", ft_tolower('A')); */
/*     printf("%c\n", ft_tolower('a')); */
/*     printf("%c\n", ft_tolower('B')); */
/*     printf("%c\n", ft_tolower('b')); */
/*     printf("%c\n", ft_tolower('%')); */
/*     return 0; */
/* } */
