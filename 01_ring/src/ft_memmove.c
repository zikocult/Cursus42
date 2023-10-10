/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZikoCult <ZikoCult>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:13:02 by ZikoCult          #+#    #+#             */
/*   Updated: 2023/10/10 21:13:53 by ZikoCult         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dst);
}

/* int main (void) */
/* { */
/* 	char dest[] = "La prueba definitiva"; */
/* 	char orig[] = "xxxxxxx"; */
/* 	//strcpy(dest, "La prueba definitiva"); */
/* 	//strcpy(orig, "xxxxxxx"); */
/* 	printf("Origen antes: %s\n", orig); */
/* 	printf("Destino antes: %s\n", dest); */
/* 	ft_memmove(dest, orig, 3); */
/* 	printf("Origen después: %s\n", orig); */
/* 	printf("Destino después: %s\n", dest); */
/* 	return (0); */
/* } */
