#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	//t_list	*newelem;

	if (!lst || !new)
		return ;
	// newelem = ft_create_elem(data);
	// newelem->next = *begin_list;
	// *begin_list = newelem;
	new->next = *lst;
	*lst = new;
}