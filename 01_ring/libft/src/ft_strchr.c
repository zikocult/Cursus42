/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZikoCult <ZikoCult>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:14:29 by ZikoCult          #+#    #+#             */
/*   Updated: 2023/10/16 16:57:15 by ZikoCult         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr != '\0')
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	if (*ptr == (char)c)
		return (ptr);
	return (NULL);
}

// int main(void)
// {
//     const char *str = "heea";
//     char  c;
//     c = 'e';
//     printf("Found letter:%c\n", *ft_strchr(str, c));
//     return (0);
// }
