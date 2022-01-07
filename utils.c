/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:41:36 by adriouic          #+#    #+#             */
/*   Updated: 2022/01/07 17:24:45 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes.h"

void __init__ops(var *strct)
{
    strct->shifts = 0;
    strct->ascci = 0;
}

int reset(int bit, struct __siginfo *info)
{
    if (bit == 7)
    {

        if (ops.ascci == 0)
        {
            ops.shifts = 0;
			kill(info->si_pid, SIGUSR1);
            return (1);
        }
        else
        {
            write(1, (char *)&ops.ascci, 1);
            ops.shifts = -1;
            ops.ascci = 0;
        }
    }
    return (0);
}

void    do_(int sg, struct __siginfo *info, void *vp)
{
    (void)sg;
    (void)vp;

	ops.ascci += pow_(2, ops.shifts);
    if(reset(ops.shifts, info))
   	    return ;
   	ops.shifts += 1;

}

void    do_1(int sg, struct __siginfo *info, void *vp)
{
    (void)sg;
    (void)vp;

	if (reset(ops.shifts, info))
		return ;
    ops.shifts += 1;
}

int pow_(int a, int b)
{
    int t;

    t = a;
    if (!b)
        return (1);
    while (--b)
        a *= t;
    return (a);
}

void yell_end(int pid)
{
    int i;
    i = 0;

    while (i++ < 8)
    {
        kill(pid, SIGUSR2);
        usleep(100);
    }
}

void end_status(int n)
{
	(void)n;
	write(1, "Communication has ended Succedfully!\n", 37);
	return ;
}
