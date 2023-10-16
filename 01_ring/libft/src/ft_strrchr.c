/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZikoCult <ZikoCult>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:57:50 by ZikoCult          #+#    #+#             */
/*   Updated: 2023/10/16 17:12:38 by ZikoCult         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = ft_strlen(ptr);
	while (i >= 0)
	{
		if (ptr[i] == (char)c)
			return (ptr + i);
		i--;
	}
	return (NULL);
}

// int main(void)
// {
//     const char *str = "heea";
//     char  c;
//     c = 'e';
//     printf("Found letter:%c\n", *ft_strrchr(str, c));
//     return (0);
// }
