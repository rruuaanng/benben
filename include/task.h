#ifndef BENBEN_TASK_H
#define BENBEN_TASK_H

#ifdef __cplusplus
extern "C" {
#endif

struct task{
    int pid;
    int prio;
    char *name;
    void (*fn)(void *args);
};

int e_create_task(void (*fn)(void *args), 
            char *task_name);
            

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // BENBEN_TASK_H