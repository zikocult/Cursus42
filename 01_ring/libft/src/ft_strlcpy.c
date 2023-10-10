/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZikoCult <ZikoCult>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:40:51 by ZikoCult          #+#    #+#             */
/*   Updated: 2023/10/10 22:01:30 by ZikoCult         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int		len;
	size_t	i;

	i = 0;
	len = ft_strlen(src);
	if (size != 0)
	{
		while (i < (size -1) && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}

/* int main (void) */
/* { */
/*     char dest[50] = "La prueba definitiva"; */
/*     char orig[50] = "Probando"; */
/* 	int len; */
/*     //strcpy(dest, "La prueba definitiva"); */
/*     //strcpy(orig, "Probando"); */
/*     printf("Destino antes: %s\n", dest); */
/*     len = ft_strlcpy(dest, orig, 5); */
/*     printf("Destino después: %s\n", dest); */
/* 	printf("El retorno de la función es: %i", len); */
/*     return (0); */
/* } */
