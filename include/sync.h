#ifndef BENBEN_SYNC_H
#define BENBEN_SYNC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <list.h>

struct semaphore{
    int count;
    struct list_node *wait_list;
};


#ifdef __cplusplus
}
#endif // __cplusplus


#endif // BENBEN_SYNC_H