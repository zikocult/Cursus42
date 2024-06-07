/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:03:52 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/06 12:34:05 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
/*
int main(void)
{
	printf("%i\n", ft_sqrt(25));
	printf("%i\n", ft_sqrt(81));
	printf("%i\n", ft_sqrt(49));
	printf("%i\n", ft_sqrt(48));
	printf("%i\n", ft_sqrt(12));
}*/
