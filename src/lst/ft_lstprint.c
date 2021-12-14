/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 23:57:11 by jzeybel           #+#    #+#             */
/*   Updated: 2021/12/13 17:49:59 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static  void PrintStr(t_list *lst)
{
    while (lst)
    {
        printf("%s\n", (char *)lst->data);
        lst = lst->next;
    }
}

static  void PrintInt(t_list *lst, char *sep)
{
    while (lst)
    {
        printf("%d", *(int *)lst->data);
        if (!ft_strncmp(sep, "\n", 1))
            printf("\n");
        else if (!ft_strncmp(sep, "\t", 1))
            printf("\t");
        else if (!ft_strncmp(sep, " ", 1))
            printf(" ");
        lst = lst->next;
    }
}

static  void PrintNode(t_list *lst)
{
    while (lst)
    {
        printf("Current :%d (%p)\n", *(int *)lst->data, lst);
        if (lst->next)
            printf("Next :%d (%p)\n", *(int *)lst->next->data, lst->next);
        printf("\n");
        lst = lst->next;
    }
}

void    ft_lstprint(t_list *lst, char *param, char *sep)
{
    if (!lst)
        return ;
    else if (!ft_strncmp(param, "str", ft_strlen(param)))
        PrintStr(lst);
    else if (!ft_strncmp(param, "int", ft_strlen(param)))
        PrintInt(lst, sep);
    else if (!ft_strncmp(param, "node", ft_strlen(param)))
        PrintNode(lst);
    else
        return ;
}
