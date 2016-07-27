/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 11:52:34 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/02/27 15:12:26 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_dlst
{
	void				*content;
	size_t				content_size;
	struct s_dlst		*prev;
	struct s_dlst		*next;
}						t_dlst;

typedef struct			s_nlist
{
	size_t				size;
	t_list				*head;
	t_list				*tail;
	int					(*match)(const void *key1, const void *key2);
	void				(*destroy)(void *, size_t);
}						t_nlist;

/*
** t_list type
*/

t_list					*ft_lstnew(void const *content, size_t content_size);
t_list					*ft_lstnew_raw(void const *content,
						size_t content_size);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst,
						void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstadd_back(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_lstreverse(t_list **begin_list);
t_list					*ft_lstlast(t_list *begin_list);
t_list					*ft_lstbefore(t_list *start, const t_list *node);

/*
** t_dlst type
*/

t_dlst					*ft_dlst_new(void const *content, size_t content_size);
void					ft_dlst_add_back(t_dlst *root, t_dlst *new);
void					ft_dlst_add_front(t_dlst *root, t_dlst *new);
void					ft_dlst_del_one(t_dlst *root, t_dlst **to_del,
						void (*del)(void *, size_t));
t_dlst					*ft_dlst_init(void const *content, size_t content_size);
void					ft_dlst_destroy(t_dlst *root,
						void (*del)(void *, size_t));
void					ft_dlst_clear(t_dlst *root,
						void (*del)(void *, size_t));

/*
** t_nlist type
*/

t_nlist					*ft_nlist_create(void (*destroy)(void *, size_t));
void					ft_nlist_init(t_nlist *list,
						void (*destroy)(void *, size_t));
void					ft_nlist_delete(t_nlist **list);
void					ft_nlist_destroy(t_nlist *list);
int						ft_nlist_add(t_nlist *list, t_list *after,
						t_list *new);
int						ft_nlist_rem(t_nlist *list, t_list *after,
						void **data, size_t *content_size);
int						ft_nlist_delone(t_nlist *list, t_list *after);
int						ft_nlist_addback(t_nlist *lst, t_list *elem);
int						ft_nlist_addfront(t_nlist *lst, t_list *elem);
void					ft_nlist_reverse(t_nlist *lst);
void					ft_nlist_iter(t_nlist const *l,
						void (*f)(t_list *elem));
int						ft_nlist_merge(t_nlist *new, const t_nlist *a,
						const t_nlist *b);

#endif
