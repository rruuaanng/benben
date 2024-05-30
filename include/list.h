#ifndef BENBEN_LIST_H
#define BENBEN_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <types.h>

struct list_node {
    void *owner;
    int prio;
    struct list_node *next;
    struct list_node *prev;  
};

#define LIST_INIT_HEAD(name) \
    struct list_node name = {NULL, -1 ,NULL, NULL}

static inline 
void list_init_node(struct list_node *node, void *owner, int prio) 
{
    node->owner = owner;
    node->prio = prio;
    node->next = node;
    node->prev = node;
}

#define list_for_each(head, pos) \
    for (pos = (head)->next; pos != (head); pos = pos->next)


#define list_node_next(node)            ((node)->next)

#define list_node_prev(node)            ((node)->prev)



static inline 
struct list_node *__list_for_each_end(struct list_node *head)
{
    struct list_node *tmp;
    
    for(tmp = head; tmp->next != NULL; tmp = tmp->next) {
        /* nothing */
    }

    return tmp;
}

static inline
void list_add(struct list_node *head, struct list_node *node)
{
    // struct list_node *tmp = __for_each_list_end(head);


}

static inline
void list_add_tail(struct list_node *head, struct list_node *node)
{
    
}

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // BENBEN_LIST_H