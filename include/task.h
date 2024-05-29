#ifndef BENBEN_TASK_H
#define BENBEN_TASK_H

#ifdef __cplusplus
extern "C" {
#endif


int e_create_task(void (*fn)(void *args), 
            char *thread_name);
            

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // BENBEN_TASK_H