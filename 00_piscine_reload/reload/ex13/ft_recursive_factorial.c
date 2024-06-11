/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:38:42 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/07 19:14:09 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb >= 13)
		return (0);
	else if (nb == 1 || nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	if (nb <= 1)
		return (1);
	else
		return (nb * ft_recursive_factorial(nb -1));
}
/*
int main (void)
{
	printf("38 - %i\n", ft_recursive_factorial(34));
	printf("37 - %i\n", ft_recursive_factorial(34));
	printf("36 - %i\n", ft_recursive_factorial(34));
	printf("35 - %i\n", ft_recursive_factorial(34));
	printf("34 - %i\n", ft_recursive_factorial(34));
	printf("33 - %i\n", ft_recursive_factorial(33));
	printf("32 - %i\n", ft_recursive_factorial(32));
	printf("31 - %i\n", ft_recursive_factorial(31));
	printf("30 - %i\n", ft_recursive_factorial(30));
	printf("29 - %i\n", ft_recursive_factorial(29));
	printf("28 - %i\n", ft_recursive_factorial(28));
	printf("27 - %i\n", ft_recursive_factorial(27));
	printf("26 - %i\n", ft_recursive_factorial(26));
	printf("25 - %i\n", ft_recursive_factorial(25));
	printf("24 - %i\n", ft_recursive_factorial(24));
	printf("23 - %i\n", ft_recursive_factorial(23));
	printf("22 - %i\n", ft_recursive_factorial(22));
	printf("21 - %i\n", ft_recursive_factorial(21));
	printf("20 - %i\n", ft_recursive_factorial(20));
	printf("19 - %i\n", ft_recursive_factorial(19));
	printf("18 - %i\n", ft_recursive_factorial(18));
	printf("17 - %i\n", ft_recursive_factorial(17));
	printf("16 - %i\n", ft_recursive_factorial(16));
	printf("15 - %i\n", ft_recursive_factorial(15));
	printf("14 - %i\n", ft_recursive_factorial(14));
	printf("13 - %i\n", ft_recursive_factorial(13));
	printf("12 - %i\n", ft_recursive_factorial(12));
	printf("11 - %i\n", ft_recursive_factorial(11));
	printf("10 - %i\n", ft_recursive_factorial(10));
	printf("9 - %i\n", ft_recursive_factorial(9));
	printf("8 - %i\n", ft_recursive_factorial(8));
	printf("7 - %i\n", ft_recursive_factorial(7));
	printf("6 - %i\n", ft_recursive_factorial(6));
	printf("5 - %i\n", ft_recursive_factorial(5));
	printf("4 - %i\n", ft_recursive_factorial(4));
	printf("3 - %i\n", ft_recursive_factorial(3));
	printf("2 - %i\n", ft_recursive_factorial(2));
	printf("1 - %i\n", ft_recursive_factorial(1));
}*/
