/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:31:24 by adjemaa           #+#    #+#             */
/*   Updated: 2021/05/13 16:32:19 by adjemaa          ###   ########.fr       */
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
	t_params	*tab;

	tab = (t_params *)args;

	pick_up_forks();
	usleep(tab->stru->time_eat * 1000);
	drop_forks();
	tab->stru->philos[tab->id].total_meals++;
	if (tab->stru->philos[tab->id].total_meals == tab->stru->total_must_eat)
		return (0);
	usleep((tab->stru->time_sleep) * 1000);
	function(args);
	return (0);
}
