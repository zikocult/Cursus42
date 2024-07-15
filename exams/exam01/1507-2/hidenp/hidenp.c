/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:29:52 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/15 18:45:24 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int argc, char **argv)
{
	int i = 0, j = 0;
	int control = 1;

	if (argc == 3)
	{
		while (argv[1][i] && control == 1)
		{
			control = 0;
			while (argv[2][j] && control == 0)
			{
				if (argv[2][j] == argv[1][i])
					control = 1;
				j++;
			}
			i++;
		}
		if (control == 1)
			write (1, "1", 1);
		else if (control == 0)
			write (1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}
