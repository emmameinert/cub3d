
# include <stdlib.h>
# include <unistd.h>

typedef struct s_coord
{
	int		x;
	int		y;
	int		z;
	char	ch;
}	t_coord;

typedef struct s_node
{
	t_coord			*coords;
	struct s_node	*next;
}	t_node;

void	ft_lstadd_back(t_node **lst, int x, int y, char ch);
void	ft_lstclear(t_node **lst, void (*del)(void *));
void	ft_lstiter(t_node *lst, void (*f)(void *));
t_node	*ft_lstlast(t_node *lst);
t_node	*ft_lstnew(int x, int y, char ch);
int		ft_lstsize(t_node *lst);
