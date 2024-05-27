#ifndef BENBEN_LIST_H
#define BENBEN_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <io.h>
#include <types.h>


#define LIST_INIT_HEAD(name) \
    struct list_node name = { .next = NULL, .prev = NULL}

static inline void LIST_INIT_NODE(struct list_node *node) 
{
    WRITE_ONCE(node->next, NULL);
    WRITE_ONCE(node->prev, NULL);
}

static inline void list_add(struct list_node *head, struct list_node *node)
{
    head->
}

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // BENBEN_LIST_H