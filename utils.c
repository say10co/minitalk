/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:41:36 by adriouic          #+#    #+#             */
/*   Updated: 2022/02/01 21:17:39 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	signal_handler(int sig, siginfo_t *info, void *uncontext)
{
	(void)(uncontext);
	(void)(info);
	if (sig == SIGUSR1)
		g_vars.ascci += pow_(2, g_vars.shifts++);
	else
		g_vars.shifts += 1;
	if (g_vars.shifts == 8)
	{
		if (g_vars.ascci == 0)
			kill(info->si_pid, SIGUSR1);
		write(1, (char *)&g_vars.ascci, 1);
		__init__vars(&g_vars);
	}
}

int	pow_(int a, int b)
{
	int	t;

	t = a;
	if (!b)
		return (1);
	while (--b)
		a *= t;
	return (a);
}

void	__init__vars(t_vars *strct)
{
	strct->shifts = 0;
	strct->ascci = 0;
}

void	end_status(int n)
{
	(void)(n);
	write(1, "Communication has ended Succedfully!\n", 37);
	return ;
}
