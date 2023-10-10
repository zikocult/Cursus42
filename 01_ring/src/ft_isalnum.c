/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZikoCult <ZikoCult>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 23:23:32 by ZikoCult          #+#    #+#             */
/*   Updated: 2023/10/10 19:25:38 by ZikoCult         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/* int main(void) */
/* {  */
/* printf("%i\n", ft_isalnum('a')); */
/* printf("%i\n", ft_isalnum('1')); */
/* printf("%i\n", ft_isalnum('R')); */
/* printf("%i\n", ft_isalnum('/')); */
/* printf("%i\n", ft_isalnum('\n')); */
/* printf("%i\n", ft_isalnum('Z')); */
/* return EXIT_SUCCESS; */
/* } */
