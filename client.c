/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:18:47 by wting             #+#    #+#             */
/*   Updated: 2022/08/11 13:20:27 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//send

int main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;
	// struct sigaction sa;

	if (argc != 3)
	{
		// printf("Kematian program");
		return (0);
	}
	// sigaction(SIGUSR1, &sa, 0);
	// sigaction(SIGUSR2, &sa, 0);
	pid = (pid_t)ft_atoi(argv[1]);
	message = argv[2]; 
	if (*message == 'a')
		kill(pid, SIGUSR1);
	else if (*message == 'b')
		kill(pid, SIGUSR2);
	return (0);
}