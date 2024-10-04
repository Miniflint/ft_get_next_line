/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 02:18:56 by trgoel            #+#    #+#             */
/*   Updated: 2024/10/04 02:18:57 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_file(int fd, char **line)
{
	int		rd;
	char	buf[BUFFER_SIZE];
	char	*tmp;

	rd = 1;
	while (!ft_strchr(*line, '\n') && rd)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (!*line && rd)
			*line = ft_strdup(buf, rd);
		else if (rd)
		{
			tmp = *line;
			*line = ft_strljoin(tmp, buf, rd);
			free(tmp);
		}
		if (!*line || (!*line[0] && !rd))
		{
			free(*line);
			*line = NULL;
			return (0);
		}
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*tmp;
	char		*ret_str;
	int			i;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE == 0 || fd < 0)
		return (NULL);
	if (!read_file(fd, &line))
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i])
		i++;
	ret_str = ft_strdup(line, i);
	if (!ret_str)
		return (NULL);
	tmp = line;
	line = ft_strdup(tmp + i, ft_strlen(tmp + i));
	free(tmp);
	if (!line)
		return (NULL);
	return (ret_str);
}
