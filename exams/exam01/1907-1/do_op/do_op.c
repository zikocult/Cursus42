/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:38:14 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/19 10:52:01 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int first, second;

	if (argc == 4)
	{
		first = atoi(argv[1]);
		second = atoi(argv[3]);
		if (argv[2][0] == '+')
			printf("%i", first + second);
		else if (argv[2][0] == '-')
			printf("%i", first - second);
		else if (argv[2][0] == '*')
			printf("%i", first * second);
		else if (argv[2][0] == '/')
			printf("%i", first / second);
		else
			printf("0");
	}
	printf("\n");
	return (0);
}
