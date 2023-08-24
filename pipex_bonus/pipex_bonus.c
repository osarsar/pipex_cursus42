/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 08:36:00 by osarsar           #+#    #+#             */
/*   Updated: 2023/05/12 15:16:13 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_struct(t_pipe *data, int ac, char **av, char**env)
{
	data->ac = ac;
	data->av = av;
	data->env = env;
	if (!ft_strcmp(data->av[1], "here_doc"))
	{
		data->x = 3;
		data->in = open(data->av[1], O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (data->in == -1)
			message_error();
		data->out = open(data->av[data->ac - 1],
				O_CREAT | O_RDWR | O_APPEND, 0777);
		if (data->out == -1)
			message_error();
	}
	else
	{
		data->x = 2;
		data->in = open(data->av[1], O_RDWR | O_APPEND);
		if (data->in == -1)
			message_error();
		data->out = open(data->av[data->ac - 1],
				O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (data->out == -1)
			message_error();
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t		i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_process(t_pipe *data)
{
	int	fd[2];
	int	pid;

	pipe(fd);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		ft_execve_valid_path(data);
	}
	wait(0);
	dup2(fd[0], 0);
	close(fd[1]);
}

int	main(int ac, char **av, char **env)
{
	t_pipe	*data;

	if (ac >= 5)
	{
		data = malloc(sizeof(t_pipe));
		if (!data)
			return (0);
		init_struct(data, ac, av, env);
		here_doc(&data);
		dup2(data->in, 0);
		while (data->x < data->ac - 2)
		{
			ft_process(data);
			data->x++;
		}
		dup2(data->out, 1);
		ft_execve_valid_path(data);
	}
	else
	{
		ft_putstr_fd("Add argument\n", 2);
		exit(1);
	}
}
