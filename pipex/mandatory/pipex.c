/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:22:18 by abenajib          #+#    #+#             */
/*   Updated: 2025/02/03 19:58:34 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_find_path(char *cmd, char *envp[])
{
	char	**paths;
	char	*path;
	char	*full_path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[i] + 5, ":");
			while (*paths)
			{
				path = ft_strjoin(*paths, "/");
				full_path = ft_strjoin(path, cmd);
				free(path);
				if (access(full_path, X_OK) == 0)
					return (full_path);
				free(full_path);
				paths++;
			}
			freeall(paths, countwords(envp[i] + 5, ":"));
		}
		i++;
	}
	return (NULL);
}

pid_t	child_process(int fd[2], char *argv[], char *envp[], int process)
{
	pid_t	pid;
	char	**split;
	char *cmd_path;

	pid = fork();
	if (pid == 0)
	{
		if (process == 1)
		{
			split = ft_split(argv[2], " \t");
			dup2(fd[1], 1);
			if (dup2(open(argv[1], O_RDONLY), 0) == -1)
				return (perror("Error: input file not found\n"), -1);
			close(fd[0]);
			close(fd[1]);
			cmd_path = ft_find_path(split[0], envp);
			if (cmd_path == NULL)
				return (perror("Error: command not found\n"), exit(1), -1);
			execve(cmd_path, split, envp);
		}
		else if (process == 2)
		{
			split = ft_split(argv[3], " \t");
			dup2(fd[0], 0);
			int n = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
			if (n == -1)
				return (perror("Error: output file not found\n"), -1);
			if (dup2(n, 1) == -1)
				return (perror("Error: output file not found\n"), -1);
			close(n);
			close(fd[0]);
			close(fd[1]);
			cmd_path = ft_find_path(split[0], envp);
			if (cmd_path == NULL)
				return (perror("Error: command not found\n"), exit(1), -1);
			execve(cmd_path, split, envp);
		}
	}
	return (pid);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		return (perror("Error: wrong number of arguments\n"), 1);
	else
	{
		pipe(fd);
		pid1 = child_process(fd, argv, envp, 1);
		if (pid1 == -1)
			return (perror("Error: fork failed\n"), 1);

		pid2 = child_process(fd, argv, envp, 2);
		if (pid2 == -1)
			return (perror("Error: fork failed\n"), 1);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	return (0);
}
