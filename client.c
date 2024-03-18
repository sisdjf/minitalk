/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizitout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:54:01 by sizitout          #+#    #+#             */
/*   Updated: 2024/03/18 03:18:48 by sizitout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_globale;

void	ft_gestion(int signum)
{
	if (signum == SIGUSR1)
		g_globale = 1;
	else if (signum == SIGUSR2)
		ft_printf("Bien recu\n");
}

void	char_bin(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		while (!g_globale)
			usleep(200);
		g_globale = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
		return (ft_printf("Error\n"), 1);
	signal(SIGUSR1, &ft_gestion);
	signal(SIGUSR2, &ft_gestion);
	pid = ft_atoi(argv[1]);
	if (pid == 4194305 || pid <= 0 || kill(pid, 0))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	while (argv[2][i] != 0)
	{
		char_bin(pid, argv[2][i]);
		i++;
	}
	if (i > 0 && argv[2][i] == 0)
		char_bin(pid, '\0');
}
