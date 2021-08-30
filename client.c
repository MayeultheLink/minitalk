/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:27:42 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/30 20:04:13 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int nb, int pid)
{
	if (nb == 0)
		kill(pid, SIGUSR1);
	if (nb == 1)
		kill(pid, SIGUSR2);
}

int	main(int ac, char **av)
{
	int		pid;
	char	c;
	int		nb;
	int		i;
	int		j;

	if (ac != 3)
		return (0);
	pid = ft_atoi(av[1]);
	j = 0;
	while (av[2][j])
	{
		c = av[2][j];
		i = 0;
		while (i < 8)
		{
			nb = (c >> i) & 1;
			usleep(800);
			send_char(nb, pid);
			i++;
		}
		j++;
	}
	return (0);
}
