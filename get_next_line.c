/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:16:35 by msilva-c          #+#    #+#             */
/*   Updated: 2023/09/15 15:43:02 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	line = NULL;
	while (*buff || read(fd, buff, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buff);
		if (ft_clean(buff))
			break ;
	}
	free(buff);
	return (line);
}
/* 
#include <stdio.h>
#include <errno.h>
int main()
{
    int fd = open("tester.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("error nr %d\n", errno);
        perror("open problem");
    }
    char *line = get_next_line(fd);
    printf("line is: \"$%s$\"", line);
} */