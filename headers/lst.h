/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:43:29 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:47:47 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_coord
{
	int		x;
	int		y;
	int		z;
	char	ch;
	int		checked;
}	t_coord;

typedef struct s_node
{
	t_coord			*coords;
	struct s_node	*next;
}	t_node;

t_node	*ft_lstadd_back(t_node **lst, int x, int y, char ch);
void	ft_lstclear(t_node **lst, void (*del)(void *));
void	ft_lstiter(t_node *lst, void (*f)(void *));
t_node	*ft_lstlast(t_node **lst);
t_node	*ft_lstnew(int x, int y, char ch);
int		ft_lstsize(t_node *lst);

#endif
