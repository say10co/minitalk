/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:46:29 by adriouic          #+#    #+#             */
/*   Updated: 2022/02/01 20:11:35 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes.h"

int	main(void)
{
	struct sigaction	act;

	__init__vars(&g_vars);
	ft_putnbr_fd(getpid(), 1);
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		;
	return (0);
}
