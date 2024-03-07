/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:59:50 by adjemaa           #+#    #+#             */
/*   Updated: 2021/05/13 16:42:10 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned long	the_time(void)
{
	struct timeval	eat;

	gettimeofday(&eat, NULL);
	return ((eat.tv_sec * 1000) + (eat.tv_usec / 1000));
}

void	pick_up_forks()
{

}

void	drop_forks()
{

}

void	*function(void *args)
{
	t_stat	*stat;

	stat = (t_stat *)args;
	pick_up_forks();
	usleep(stat->stru->time_eat * 1000);
	drop_forks();
	usleep((stat->stru->time_sleep) * 1000);
	function(stat);
	return (0);
}
