/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 08:29:03 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/02/18 11:39:16 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	reset(int *i, char *c, int *pid, siginfo_t *info)
{
	*i = 0;
	*c = 0;
	*pid = info->si_pid;
	write (1, YEL"\nmgs : "REST, 19);
}

void	handler(int signum, siginfo_t *info, void *pr)
{
	static int	i;
	static char	c;
	static int	pid_old;

	(void) pr;
	if (pid_old != info->si_pid)
		reset(&i, &c, &pid_old, info);
	c = (c << 1) | (signum & 1);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		if (c == 0)
		{
			write(1, GRN" >> send from ", 22);
			put_nbr((int)info->si_pid);
			write(1, "\n", 1);
		}	
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	pid = getpid();
	put_nbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
