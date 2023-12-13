/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:10:02 by rvandepu          #+#    #+#             */
/*   Updated: 2023/12/13 11:03:20 by remty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

typedef struct s_buf {
	char			content[BUFFER_SIZE];
	long			read;
	struct s_buf	*next;
}	t_buf;

// get_next_line.c
char		*get_next_line(int fd);

// get_next_line_utils.c
bool	ft_memclear(t_buf **mem);

#endif
