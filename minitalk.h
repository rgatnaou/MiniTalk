/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 08:27:08 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/02/18 11:37:57 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include<unistd.h>
# include<stdlib.h>
# include<signal.h>
# include<stdbool.h>

void	put_nbr(int nb);
int		ft_atoi(char *str);
void	put_char(char c);

# define RED "\e[0;31m"
# define YEL "\e[0;33m"
# define GRN "\e[0;32m"
# define WHT "\e[0;37m"
# define REST "\e[0m"

#endif