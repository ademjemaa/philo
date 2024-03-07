/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_uno.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:46:44 by adjemaa           #+#    #+#             */
/*   Updated: 2021/05/13 16:47:59 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_stats(int cur, t_condi *stru)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stru->philo)
	{
	}
	return (1);
}

int	init_vars(char **argv, int argc, t_condi *stru)
{
	int	i;

	if (init_philos(argv, argc, stru) == 0)
		return (0);
	stru->philos = malloc(sizeof(t_phil) * stru->philo);
	i = -1;
	while (++i < stru->philo)
	{
		stru->philos[i].id = i;
		stru->philos[i].last_meal = the_time();
		stru->philos[i].total_meals = 0;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_condi	stru;

	if (init_config(argv, argc, &stru) == 0)
		return (0);
}
