/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:16:04 by msilva-c          #+#    #+#             */
/*   Updated: 2023/09/15 15:43:30 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i + (str[i] == '\n'));
}

char	*ft_strjoin(char *line, char *buff)
{
	char	*new;
	size_t	i;

	new = (char *)malloc((ft_strlen(line) + ft_strlen(buff)) + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (line && line[++i])
		new[i] = line[i];
	i += (!line);
	while (*buff)
	{
		new[i++] = *buff;
		if (*buff++ == '\n')
			break ;
	}
	new[i] = '\0';
	free(line);
	return (new);
}

int	ft_clean(char *buff)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			EOF--;
			buff[i++] = 0;
			break ;
		}
		buff[i++] = 0;
	}
	if (eof)
	{
		while (buff[i])
		{
			buff[j++] = buff[i];
			buff[i++] = 0;
		}
	}
	return (0);
}