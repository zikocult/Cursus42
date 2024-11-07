/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:29:58 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/11/07 19:33:19 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	sigusr_handle(int sig, siginfo_t *info, void *context)
{
	static int		i = 0;
	static pid_t	pid = 0;
	static char		chr = 0;

	(void)context;
	if (!pid) 
		pid = info->si_pid;
	chr |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!chr)
		{
			kill(pid, SIGUSR2);
			pid = 0;
			return ;
		}
		// cree el putchar, pues con el printf no funcionaba 
		// hasta que he encontrado el fflush que limpia stdout
		ft_putchar_fd(chr, 1);
		// printf("%c", chr);
		// fflush(stdout);
		chr = 0;
		kill(pid, SIGUSR1);
	}
	else 
		chr <<= 1;
}

int main(void)
{
	struct sigaction	sa;

	printf("Server PID = %d\n", getpid());
	sa.sa_sigaction = sigusr_handle;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
	return (0);
}
