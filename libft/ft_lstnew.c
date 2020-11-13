#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *newlist;

	if(!(newlist = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	newlist->next = NULL;
	newlist->content = content;
	return (newlist);
}