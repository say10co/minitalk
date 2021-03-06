/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:43:15 by adriouic          #+#    #+#             */
/*   Updated: 2022/02/01 19:49:58 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_vars
{
	int	shifts;
	int	ascci;
}t_vars;

t_vars	g_vars;

int		pow_(int a, int b);
void	ft_putnbr(unsigned int n);
void	__init__vars(t_vars *strct);
void	end_status(int n);
void	signal_handler(int sig, siginfo_t *info, void *uncontext);

#endif
