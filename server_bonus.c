/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:24:39 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/02/18 11:39:34 by rgatnaou         ###   ########.fr       */
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

void	handler(pid_t signum, siginfo_t *info, void *act)
{
	static int	i;
	static char	c;
	static int	pid;

	(void)act;
	if (pid != info->si_pid)
		reset(&i, &c, &pid, info);
	c = (c << 1) | (signum & 1);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		if (c == 0)
		{
			write(1, GRN" >> send from: "REST, 27);
			put_nbr((int)info->si_pid);
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	put_nbr(getpid());
	write(1, "\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
