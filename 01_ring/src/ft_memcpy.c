/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZikoCult <ZikoCult>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:06:43 by ZikoCult          #+#    #+#             */
/*   Updated: 2023/10/10 21:11:50 by ZikoCult         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*destiny;
	size_t			i;

	destiny = (unsigned char *) dest;
	i = 0;
	if (dest == NULL || src == NULL)
		return (0);
	while (i < n)
	{
		destiny[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/* int main (void) */
/* { */
/*     char dest[50] = "La prueba definitiva"; */
/*     char orig[50] = "Probando"; */
/*     //strcpy(dest, "La prueba definitiva"); */
/*     //strcpy(orig, "Probando"); */
/*     printf("Destino antes: %s\n", dest); */
/*     ft_memcpy(dest, orig, 5); */
/*     printf("Destino después: %s\n", dest); */
/*     return (0); */
/* } */
