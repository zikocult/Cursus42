/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:24:45 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/07/17 15:50:49 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	// esta opción sería la mas sencilla, pero vamos a asegurar con CHAR_BIT, que es parte de limits.h
	// i = 8 * sizeof(octet);
	i = CHAR_BIT * sizeof(octet);
	// con CHAR_BIT, nos aseguramos que el tamaño del char sea de 8 bits, independientemente de la arquitectura
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

int main(void) 
{
    unsigned char octet = 'a';

	print_bits(octet);
	write(1, "\n", 1);
    return (0);
}

