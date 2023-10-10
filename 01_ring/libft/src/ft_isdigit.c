/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZikoCult <ZikoCult>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 23:18:04 by ZikoCult          #+#    #+#             */
/*   Updated: 2023/10/08 23:32:36 by ZikoCult         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* int main(void) */
/* {  */
/* printf("%i\n", ft_isdigit('0')); */
/* printf("%i\n", ft_isdigit('1')); */
/* printf("%i\n", ft_isdigit('R')); */
/* printf("%i\n", ft_isdigit('/')); */
/* printf("%i\n", ft_isdigit('\n')); */
/* printf("%i\n", ft_isdigit('9')); */
/* return EXIT_SUCCESS; */
/* } */
