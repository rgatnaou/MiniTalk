/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:43:41 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/02/17 17:18:57 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	put_char(char c)
{
	write(1, &c, 1);
}

void	put_nbr(int nb)
{
	long int	x;

	x = nb;
	if (x < 0)
	{
		put_char('-');
		x = -x;
	}
	if (x >= 10)
	{
		put_nbr(x / 10);
		put_nbr(x % 10);
	}
	else
	{
		put_char(x + 48);
	}
}
