#include "minishell.h"

//delete the node and his content, and reconnect the list
void	delete_node(t_list **list, t_list *node)
{
	t_list	*i;

	if (list == NULL || *list == NULL || node == NULL)
		return ;
	if (*list == node)
		*list = (*list)->next;
	else
	{
		i = *list;
		while (i->next != NULL && i->next != node)
			i = i->next;
		i->next = node->next;
	}
	ft_lstdelone(node, free);
}
