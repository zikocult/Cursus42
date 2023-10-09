/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZikoCult <ZikoCult>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 23:34:19 by ZikoCult          #+#    #+#             */
/*   Updated: 2023/10/08 23:35:22 by ZikoCult         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isascii(int c)
{
	if (c >= 32 && c <= 127)
		return (1);
	return (0);
}

/* int main(void) */
/* {  */
/* printf("%i\n", ft_isascii('0')); */
/* printf("%i\n", ft_isascii('1')); */
/* printf("%i\n", ft_isascii('R')); */
/* printf("%i\n", ft_isascii('/')); */
/* printf("%i\n", ft_isascii(200)); */
/* printf("%i\n", ft_isascii('\n')); */
/* printf("%i\n", ft_isascii('9')); */
/* return EXIT_SUCCESS; */
/* } */
