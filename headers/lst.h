
# include <stdlib.h>
# include <unistd.h>

typedef struct s_coord
{
	int	x;
	int	y;
	int	z;
}	t_coord;

typedef struct s_list
{
	t_coord			*coords;
	struct s_node	*next;
}	t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(t_coord *coords);
int		ft_lstsize(t_list *lst);
