/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:43:15 by adriouic          #+#    #+#             */
/*   Updated: 2022/01/07 17:23:41 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef INCLUDES_H
# define INCLUDES_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct variables
{
    int shifts;
    int ascci;
}var;

var	ops;

int		check_spid(int pid);
void    do_(int sg, struct __siginfo *info, void *vp);
void    do_1(int sg, struct __siginfo *info, void *vp);
int		pow_(int a, int b);
void	yell_end(int pid);
int		reset(int bit, struct __siginfo *info);
void	__init__ops(var *strct);
void	end_status(int n);

# endif
