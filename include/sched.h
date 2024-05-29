#ifndef BENBEN_SCHED_H
#define BENBEN_SCHED_H

#ifdef __cplusplus
extern "C" {
#endif

#define TASK_STATUS_RUNNING           0x01
#define TASK_STATUS_READY             0x02
#define TASK_STATUS_WAIT              0x03
#define TASK_STATUS_FREE              0x04


void e_init_sched(void);
int e_get_current(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // BENBEN_SCHED_H
