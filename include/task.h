#ifndef BENBEN_TASK_H
#define BENBEN_TASK_H

#ifdef __cplusplus
extern "C" {
#endif

struct task{
    int id;
    int prio;
    char *name;
    void (*fn)(void *args);
};

int create_task(char *task_name, void (*fn)(void *args), void *args,
            char *stack);

int get_task_id(char *task_name);

void get_task_name(int id, char *name_buf);            

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // BENBEN_TASK_H