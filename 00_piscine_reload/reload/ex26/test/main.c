/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:24:17 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/07 14:51:54 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (f(tab[i]) == 1)
			count++;
		i++;
	}
	return (count);
}

int ft_random(char *tab)
{
	if (strlen(tab) > 4)
		return (0);
	return (1);
}

int main (int argc, char **argv)
{
	if (argc > 1)
		printf("%i\n", ft_count_if(argv, &ft_random));
	return (0);
}
