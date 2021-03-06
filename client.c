/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:47:01 by adriouic          #+#    #+#             */
/*   Updated: 2022/02/01 21:07:04 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	send_signals(unsigned int n, int pid)
{
	int	i;

	i = 0;
	while (i != 8)
	{
		if (n % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		n /= 2;
		i++;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	if (ac == 3)
	{
		i = 0;
		pid = ft_atoi(av[1]);
		signal(SIGUSR1, end_status);
		while (av[2][i])
			send_signals(av[2][i++], pid);
		send_signals(0, pid);
	}
	return (0);
}
