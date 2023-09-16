/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:18:32 by msilva-c          #+#    #+#             */
/*   Updated: 2023/09/16 22:39:26 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE -3

# endif

# include <unistd.h>
# include <fcntl.h>  
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buff);
int		ft_clean(char *buff);
size_t	ft_strlen(char *str);

#endif