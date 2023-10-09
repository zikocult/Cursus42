/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZikoCult <ZikoCult>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:59:50 by ZikoCult          #+#    #+#             */
/*   Updated: 2023/10/08 23:32:45 by ZikoCult         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/* int main(void) */
/* {  */
/* printf("%i\n", ft_isalpha('a')); */
/* printf("%i\n", ft_isalpha('1')); */
/* printf("%i\n", ft_isalpha('R')); */
/* printf("%i\n", ft_isalpha('/')); */
/* printf("%i\n", ft_isalpha('\n')); */
/* printf("%i\n", ft_isalpha('Z')); */
/* return EXIT_SUCCESS; */
/* } */
