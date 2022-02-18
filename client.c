/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 08:27:18 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/02/17 17:14:56 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	send(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		kill(pid, (1 & (c >> i)) + SIGUSR1);
		i--;
		usleep(800);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac == 3)
	{
		i = 0;
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			write(1, RED"Invatid Pid.\n", 21);
			return (1);
		}
		while (av[2][i])
			send(pid, av[2][i++]);
		send(pid, av[2][i]);
		return (0);
	}
	write(1, RED"Invatid Args.\n", 22);
	return (1);
}
