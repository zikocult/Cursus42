/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:01:34 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/07/19 17:50:29 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// hecha por copilot

unsigned char swap_bits(unsigned char octet)
{
    return ((octet >> 4) | (octet << 4));
}

// hecha por mi

unsigned char swap_bits2(unsigned char octet)
{
	unsigned char temp;

	temp = octet >> 4;
	octet = octet << 4 | temp;

	return (octet);
}

