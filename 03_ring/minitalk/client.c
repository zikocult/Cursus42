/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:45:21 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/11/12 12:55:59 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void	sigusr_handle(int sig)
{
	static int	resp = 0;

	if (sig == SIGUSR1)
		resp++;
	else
		printf(" %d\n", resp - 1);
}

void	send_message(int pid, char *str)
{
	int		j;
	char	chr;

	j = 0;
	while (str[j])
	{
		chr = str[j];
		for (int i = 8; i--;)
		{
			if (chr >> i & 1)
			{
				if (kill(pid, SIGUSR2) == -1)
				{
					perror("PID");
					fprintf(stderr, "Invalid PID: %d\n", pid);
					exit(EXIT_FAILURE);
				}
			}
			else
				if (kill(pid, SIGUSR1) == -1)
				{
					perror("PID");
					fprintf(stderr, "Invalid PID: %d\n", pid);
					exit(EXIT_FAILURE);
				}
			usleep(200);
		}
		j++;
	}
	chr = '\n';
	for (int i = 8; i--;)
	{
		if (chr >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(200);
	}
	printf("Sent     : %ld\nReceived :", strlen(str));
	for (int i = 8; i--;)
	{
		kill(pid, SIGUSR1);
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !strlen(argv[2]))
	{
		fprintf(stderr, "Arguments error:  %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (atoi(argv[1]) <= 0)
	{
		fprintf(stderr, "Invalid PID: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, &sigusr_handle);
	signal(SIGUSR2, &sigusr_handle);
	send_message(atoi(argv[1]), argv[2]);
	exit(EXIT_SUCCESS);
}
