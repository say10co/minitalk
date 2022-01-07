/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:46:29 by adriouic          #+#    #+#             */
/*   Updated: 2022/01/07 16:59:59 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes.h"

int main(void)
{
	__init__ops(&ops);
	printf("%d\n", getpid());
	
	struct sigaction act;
	struct sigaction act1;

	act.sa_sigaction = do_;
	act1.sa_sigaction = do_1;
	act.sa_flags = SA_NODEFER|SA_SIGINFO;
	act1.sa_flags = SA_NODEFER|SA_SIGINFO;

	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act1, NULL);
	
	while (1);
	return (0);

}
