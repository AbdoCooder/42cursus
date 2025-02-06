/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:22:18 by abenajib          #+#    #+#             */
/*   Updated: 2025/02/06 18:35:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

pid_t	ft_excute_1(char *argv[], int fd[2], char *envp[])
{
	char	*cmd_path;
	int		n;
	char	**split;

	split = ft_split(argv[2], " \t");
	if (!split[0])
		return (freeall(split, countwords(argv[2], " \t")),
			perror("Error: command not found"), -1);
	dup2(fd[1], 1);
	n = open(argv[1], O_RDONLY);
	if (n == -1 || dup2(n, 0) == -1)
		return (freeall(split, countwords(argv[2], " \t")),
			perror("Error: input file not found"), -1);
	close(n);
	close(fd[0]);
	close(fd[1]);
	cmd_path = ft_find_path(split[0], envp);
	if (cmd_path == NULL)
		return (freeall(split, countwords(argv[2], " \t")),
			perror("Error: command path"), -1);
	if (execve(cmd_path, split, envp) == -1)
		return (freeall(split, countwords(argv[2], " \t")),
			free(cmd_path), perror("Error: execution"), -1);
	return (0);
}

pid_t	ft_excute_2(char *argv[], int fd[2], char *envp[])
{
	char	*cmd_path;
	char	**split;
	int		n;

	split = ft_split(argv[3], " \t");
	if (!split[0])
		return (freeall(split, countwords(argv[3], " \t")),
			perror("Error: command not found"), -1);
	dup2(fd[0], 0);
	n = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (n == -1 || dup2(n, 1) == -1)
		return (freeall(split, countwords(argv[3], " \t")),
			perror("Error: output file not found"), -1);
	close(n);
	close(fd[0]);
	close(fd[1]);
	cmd_path = ft_find_path(split[0], envp);
	if (cmd_path == NULL)
		return (freeall(split, countwords(argv[3], " \t")),
			perror("Error: command path"), -1);
	if (execve(cmd_path, split, envp) == -1)
		return (freeall(split, countwords(argv[3], " \t")),
			free(cmd_path), perror("Error: execution"), -1);
	return (0);
}

pid_t	child_process(int fd[2], char *argv[], char *envp[], int process)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (perror("Error: fork failed"), -1);
	if (pid == 0)
	{
		if (process == 1)
		{
			if (ft_excute_1(argv, fd, envp) == -1)
				return (-1);
		}
		else if (process == 2)
		{
			if (ft_excute_2(argv, fd, envp) == -1)
				return (-1);
		}
	}
	return (pid);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		return (perror("Error: wrong number of arguments "), 1);
	else
	{
		pipe(fd);
		pid1 = child_process(fd, argv, envp, 1);
		if (pid1 == -1)
			return (1);
		pid2 = child_process(fd, argv, envp, 2);
		if (pid2 == -1)
			return (1);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	return (0);
}
