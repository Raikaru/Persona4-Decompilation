/*
 * eekernel.h - the Emotion Engine kernel declarations the CRI sources use.
 * See include/cri/ps2/libcdvd.h for provenance and validation.
 */
#ifndef CRI_SHIM_EEKERNEL_H
#define CRI_SHIM_EEKERNEL_H

#include <eetypes.h>

extern int DIntr(void);
extern int EIntr(void);
extern void FlushCache(int mode);
extern int iSignalSema(int sema);
extern int SignalSema(int sema);
extern int WaitSema(int sema);
extern int PollSema(int sema);
typedef struct t_ThreadParam {
    int status;
    void *func;
    void *stack;
    int stack_size;
    void *gp_reg;
    int initial_priority;
    int current_priority;
    unsigned int attr;
    unsigned int option;
    int waitType;
    int waitId;
    int wakeupCount;
} ThreadParam;

extern int CreateSema(void *param);
extern int CreateThread(ThreadParam *param);
extern int StartThread(int thread_id, void *arg);
extern int DeleteThread(int thread_id);
extern int ReferThreadStatus(int thread_id, ThreadParam *info);
extern int ChangeThreadPriority(int thread_id, int priority);
extern int DeleteSema(int sema);
extern int GetThreadId(void);
extern int RotateThreadReadyQueue(int priority);
extern void *AllocScratchPad(int pages);

#endif /* CRI_SHIM_EEKERNEL_H */
