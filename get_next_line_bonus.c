/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 01:51:47 by msilva-c          #+#    #+#             */
/*   Updated: 2023/09/18 10:53:03 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (BUFFER_SIZE < 1 || fd < 0)
	{
		if (fd >= 0 && fd <= FOPEN_MAX)
		{
			while (buff[fd][i])
				buff[fd][i++] = '\0';
		}
		return (NULL);
	}
	line = NULL;
	while (buff[fd][0] || read(fd, buff[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buff[fd]);
		if (ft_clean(buff[fd]))
			break ;
	}
	return (line);
}

/* #include <errno.h>
int main()
{
	char	*line = NULL;
	int		fd[2];

	printf("%d is FOPEN_MAX\n", FOPEN_MAX);	
	fd[0] = open("fd0.txt", O_RDONLY);
	fd[1] = open("tester.txt", O_RDONLY);
	printf("%d\n", fd[0]);
	if (fd[0] < 0 || fd[1] < 0)
	{
		printf("fd[0] is: %d\nfd[0] is: %d\n", fd[0], fd[1]);
		perror("problem");
	}
	while (1)
	{
		line = get_next_line(fd[0]);
		if (line == NULL)
		{
			printf("end of fd[0]\n");
			break ;
		}
		printf("fd[0]$%s", line);
		free (line);
		line = get_next_line(fd[1]);
		if (line == NULL)
		{
			printf("end of fd[1]\n");
			break ;
		}
		printf("fd[1]$%s", line);
		free (line);
	}
	close(fd[0]);
	close(fd[1]);
	return (0);
} */
