/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:47:01 by adriouic          #+#    #+#             */
/*   Updated: 2022/01/07 17:21:03 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int main(int ac, char **av)
{
	int	i;
	int	c;
	int	nb_bits;
	int	pid;
	
	signal(SIGUSR1, end_status);
	i = 0;
	if (ac != 3)
		return (0);
	pid = atoi(av[1]);
	if (ac == 3)
	{
		while (av[2][i])
		{
			c = av[2][i];
			nb_bits = 0;
			while (nb_bits < 8)
			{
				if ((c >> nb_bits)&1)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				nb_bits++;
				usleep(100);
			}
			i++;
		}
		yell_end(pid);
	}
}
