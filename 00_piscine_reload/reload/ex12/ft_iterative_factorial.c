/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:54:21 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/07 17:48:29 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_iterative_factorial(int nb)
{
	long	result;
	int		i;

	result = 1;
	i = 1;
	if (nb == 1 || nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	while (i <= nb)
	{
		result = result * i;
		i++;
	}
	return (result);
}
/*int main(void)
{
	printf("%i\n", ft_iterative_factorial(0));
	printf("%i\n", ft_iterative_factorial(-1));
	printf("%i\n", ft_iterative_factorial(12));
	return (0);
}*/
