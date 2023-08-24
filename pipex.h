/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 08:39:37 by osarsar           #+#    #+#             */
/*   Updated: 2023/05/12 15:17:57 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_pipe
{
	char	**env;
	char	*path;
	char	**split_path;
	char	*join;
	int		ac;
	char	**av;
	int		fd_in;
	int		fd_out;
	int		x;

}t_pipe;

char	*find_path(t_pipe *data);
int		ft_execve_valid_path(t_pipe *data, int pid);
void	ft_process(t_pipe *data);
void	ft_execve(t_pipe *data, int x);
void	message_error(void);
#endif
