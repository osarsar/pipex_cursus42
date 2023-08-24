/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 08:41:35 by osarsar           #+#    #+#             */
/*   Updated: 2023/05/13 16:53:28 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*find_path(t_pipe *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		if (!ft_strncmp(data->env[i], "PATH", 4))
		{
			return (data->env[i]);
		}
			i++;
	}
	exit(1);
}

void	ft_execve(t_pipe *data)
{
	char	**comand;

	comand = ft_split(data->av[data->x], ' ');
	data->join = ft_strjoin(data->join, comand[0]);
	if (access(data->join, F_OK) == 0)
		execve(data->join, comand, data->env);
}

int	ft_execve_valid_path(t_pipe *data)
{
	int	i;

	i = 0;
	data->path = find_path(data);
	while (*data->path != '/')
		data->path++;
	data->split_path = ft_split(data->path, ':');
	while (data->split_path[i])
	{
		data->join = ft_strjoin(data->split_path[i], "/");
		ft_execve(data);
		i++;
	}
	ft_putstr_fd("command not found\n", 2);
	exit(1);
	return (0);
}

void	here_doc(t_pipe **data)
{
	char	*input;
	char	*limit;

	limit = ft_strjoin1((*data)->av[2], "\n");
	if (!ft_strcmp((*data)->av[1], "here_doc"))
	{
		ft_putstr_fd("heredoc>", 1);
		input = get_next_line(0);
		if (!input)
			return ;
		while (ft_strcmp(input, limit))
		{
			write ((*data)->in, input, ft_strlen(input));
			ft_putstr_fd("heredoc>", 1);
			input = get_next_line(0);
			if (!input)
				break ;
		}
		(*data)->in = open((*data)->av[1], O_RDWR);
	}
}

void	message_error(void)
{
	ft_putstr_fd("file not found\n", 2);
	exit(1);
}
