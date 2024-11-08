/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:45:21 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/11/08 01:25:00 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

static int	resp = 0;

void	sigusr_handle(int sig)
{

	if (sig == SIGUSR1)
		resp++;
	else
		printf(" %d\n", resp - 1);
}

void	send_message(int pid, char *str)
{
	int		i;
	char	chr;

	while (*str)
	{
		i = 8;
		chr = *str++;
		while (i--)
		{
			if (chr >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	chr = '\n';
	while (i--)
	{
		if (chr >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int main(int argc, char **argv)
{
	if (argc != 3 || !strlen(argv[2]))
		return (1);
	printf("Sent     : %ld\nReceived :", strlen(argv[2]));
	signal(SIGUSR1, &sigusr_handle);
	signal(SIGUSR2, &sigusr_handle);
	send_message(atoi(argv[1]), argv[2]);
	if (resp == 0)
		printf(" 0\n");
}
