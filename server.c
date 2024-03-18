/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizitout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:54:05 by sizitout          #+#    #+#             */
/*   Updated: 2024/03/18 00:51:53 by sizitout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_build_string(char c, siginfo_t *info)
{
	static char	*str = NULL;

	if (c == 0)
	{
		ft_putstr_fd(str, 1);
		ft_putstr_fd("\n", 1);
		kill(info->si_pid, SIGUSR2);
		free(str);
		str = NULL;
	}
	else
	{
		str = ft_strjoin(str, c);
	}
}

void	bin_char(int signum, siginfo_t *info, void *context)
{
	static int	bit;
	static char	c;

	(void)context;
	if (signum == SIGUSR1)
		c = (c << 1) | 1;
	else if (signum == SIGUSR2)
		c <<= 1;
	if (bit < 7)
		bit++;
	else
	{
		ft_build_string(c, info);
		c = 0;
		bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
		return (ft_printf("Error\n"), 1);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &bin_char;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("The PID : %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
