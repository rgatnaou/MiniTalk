/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:38:35 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/02/18 11:40:05 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	handler(int signum)
{
	(void)signum;
	write(1, GRN"Message has been sent.\n"REST, 35);
}

void	send(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		kill (pid, ((c >> i) & 1) + SIGUSR1);
		i--;
		usleep(800);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	signal(SIGUSR1, handler);
	if (ac == 3)
	{
		i = 0;
		pid = ft_atoi(av[1]);
		if (pid < 1)
			return (write(1, RED"Invalid Pid.\n"REST, 25));
		while (av[2][i])
			send(pid, av[2][i++]);
		send(pid, av[2][i]);
		return (0);
	}
	write(1, RED"Invalid Args.\n"REST, 26);
	return (1);
}
