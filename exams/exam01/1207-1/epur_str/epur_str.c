/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:57:36 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/12 18:17:43 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int argc, char **argv)
{
	int	i, sw;

	i = 0;
	if (argc > 1)
	{
		while ((argv[1][i] >= 9 && argv[1][i] <= 13) || argv[1][i] == ' ')
			i++;
		while (argv[1][i])
		{
			sw = 0;
			if ((argv[1][i] >= 9 && argv[1][i] <= 13) || argv[1][i] == ' ')
			{
				while ((argv[1][i] >= 9 && argv[1][i] <= 13) || argv[1][i] == ' ')
					i++;
				sw = 1;
				if (argv[1][i])
					write (1, " ", 1);
			}
			if (sw == 0)
			{
				write (1, &argv[1][i], 1);
				i++;
			}
		} 
	}
	write (1, "\n", 1);
	return (0);
}
