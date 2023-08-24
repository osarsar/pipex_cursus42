/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 08:36:00 by osarsar           #+#    #+#             */
/*   Updated: 2023/05/12 15:19:34 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_struct(t_pipe *data, int ac, char **av, char**env)
{
	data->ac = ac;
	data->av = av;
	data->env = env;
	data->x = 2;
	data->fd_out = open(data->av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (data->fd_out == -1)
		message_error();
	data->fd_in = open(data->av[1], O_RDWR);
	if (data->fd_in == -1)
		message_error();
}

void	ft_process(t_pipe *data)
{
	int	fd[2];
	int	pid1;

	pipe(fd);
	pid1 = fork();
	if (pid1 == -1)
		exit(1);
	if (pid1 == 0)
	{
		close(fd[0]);
		dup2(data->fd_in, 0);
		dup2(fd[1], 1);
		ft_execve_valid_path(data, data->x);
	}
	data->x++;
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(data->fd_out, 1);
	ft_execve_valid_path(data, data->x);
}

int	main(int ac, char **av, char **env)
{
	t_pipe	*data;

	if (ac == 5)
	{
		data = malloc(sizeof(t_pipe));
		if (!data)
			return (0);
		init_struct(data, ac, av, env);
		ft_process(data);
		free(data);
	}
	else
	{
		ft_putstr_fd("Error : number of arguments\n", 2);
		exit(1);
	}
}
