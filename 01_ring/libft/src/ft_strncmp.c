/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZikoCult <ZikoCult>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:18:52 by ZikoCult          #+#    #+#             */
/*   Updated: 2023/10/16 22:44:01 by ZikoCult         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i && s1[i] != '\0' && s2[i] != '\0')
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	if (i != n)
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}

// int main(void)
// {
// 	printf("%i", ft_strncmp("test\200", "test\0", 6));
// 	return EXIT_SUCCESS;
// }
