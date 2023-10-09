/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarulls <gbarulls@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:40:36 by gbarulls          #+#    #+#             */
/*   Updated: 2023/10/09 23:25:38 by ZikoCult         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/* int main(void) */
/* {  */
/* printf("%i\n", ft_isprint('0')); */
/* printf("%i\n", ft_isprint('1')); */
/* printf("%i\n", ft_isprint('R')); */
/* printf("%i\n", ft_isprint('/')); */
/* printf("%i\n", ft_isprint(200)); */
/* printf("%i\n", ft_isprint('\n')); */
/* printf("%i\n", ft_isprint('9')); */
/* return EXIT_SUCCESS; */
/* } */
