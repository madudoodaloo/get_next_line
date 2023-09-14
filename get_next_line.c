/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:16:35 by msilva-c          #+#    #+#             */
/*   Updated: 2023/09/14 18:20:32 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_copyit(char	*buff)
{
	char	*temp;
	int		i;
	
	i = -1;
	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (buff[++i])
		temp[i] = buff[i];
	temp[BUFFER_SIZE] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	size_t 		count;
	static char	*buff;
	char		*line;

	if (BUFFER_SIZE < 0)
		return (NULL);
	buff = (char *)malloc(BUFFER_SIZE);
	if (!buff)
		return (NULL);

	count = read(fd, buff, BUFFER_SIZE);

	while (count > 0)
	{
		line = ft_copyit(buff);
		ft_clean(buff);
		count = read(fd, buff, BUFFER_SIZE);
	}
	if (count < 0)
		return ("-1 on read ft");

	return ()
}