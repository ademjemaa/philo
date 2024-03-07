/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:11:58 by adjemaa           #+#    #+#             */
/*   Updated: 2021/05/13 16:12:43 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned long	the_time(void)
{
	struct timeval	eat;

	gettimeofday(&eat, NULL);
	return ((eat.tv_sec * 1000) + (eat.tv_usec / 1000));
}

void	pick_up_forks(int cur, t_condi *stru)
{
	int second;

	second = cur + 1;
	if (cur + 1 == stru->philo)
		second = 0;
	pthread_mutex_lock(&stru->philos[cur].fork);
	pthread_mutex_lock(&stru->philos[second].fork);
}

void	drop_forks(int cur, t_condi *stru)
{
	int second;
	second = cur + 1;
	if (cur + 1 == stru->philo)
		second = 0;
	pthread_mutex_unlock(&stru->philos[cur].fork);
	pthread_mutex_unlock(&stru->philos[second].fork);
}

void	*function(void *args)
{
	t_params	*tab;

	tab = (t_params *)args;
	if (!check_stats(tab->stru) || tab->stru->state)
		return (NULL);
	pick_up_forks(tab->id,tab->stru);
	ft_locked_print("is eating\n", tab->id, tab->stru);
	tab->stru->philos[tab->id].last_meal = the_time();
	usleep(tab->stru->time_eat * 1000);

	drop_forks(tab->id, tab->stru);
	tab->stru->philos[tab->id].total_meals++;

	ft_locked_print("is sleeping\n", tab->id, tab->stru);
	usleep((tab->stru->time_sleep) * 1000);

	ft_locked_print("is thinking \n", tab->id, tab->stru);

	if (tab->stru->state == 0)
		function(args);
	return (0);
}
