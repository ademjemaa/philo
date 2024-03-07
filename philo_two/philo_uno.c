/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_uno.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:35:36 by adjemaa           #+#    #+#             */
/*   Updated: 2021/05/13 16:38:11 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_all(t_condi *stru, t_params **tab)
{
	int	i;

	i = -1;
	while (++i < stru->philo)
		pthread_join(stru->philos[i].thread_id, NULL);
	i = -1;
	usleep(20000);
	while (++i < stru->philo)
		free(tab[i]);
	free(stru->philos);
	free(tab);
}

int	check_stats(t_condi *stru)
{
	int	index;
	int	i;

	index = 0;
	i = -1;
	(void)index;
	while (++i < stru->philo)
	{

	}

	return (1);
}

int	init_vars(char **argv, int argc, t_condi *stru)
{
	unsigned long	current;
	int				i;

	if (init_philos(argv, argc, stru) == 0)
		return (0);
	stru->philos = malloc(sizeof(t_phil) * stru->philo);
	current = the_time();
	(void)current;
	while (++i < stru->philo)
	{

	}
	return (1);
}

int	main(int argc, char **argv)
{
	int			i;
	t_condi		stru;
	t_params	**tab;

	i = -1;
	if (init_vars(argv, argc, &stru) == 0)
	{
		ft_putstr("config error\n");
		return (0);
	}
	tab = create_params_tab(&stru);
	while (++i < stru.philo)
	{
		pthread_create(&stru.philos[i].thread_id, NULL,
			function, (void*)tab[i]);
		pthread_detach(stru.philos[i].thread_id);
	}
	while (check_stats(&stru))
		i = -1;
	usleep(20000);
	free_all(&stru, tab);
}
