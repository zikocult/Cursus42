/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:27:54 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/17 14:54:49 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
/*
int main(void){
	int i = 0;
	int max = 5;
	char *ptr;

	ptr = (char *)ft_calloc(max, sizeof(char));
	while (i < max){
		if (ptr[i] == '\0')
			printf("%d - NULL\n", i);
		else
		{
			printf("%d - La cagaste en algún lado nen\n", i);
			free(ptr);
			return (1);
		}
		i++;
	}
	free(ptr);
	return (0);
}*/
