/*
 * sifrpc.h - the Sony SIF RPC declarations the CRI sources use.
 * See include/cri/ps2/libcdvd.h for provenance and validation.
 */
#ifndef CRI_SHIM_SIFRPC_H
#define CRI_SHIM_SIFRPC_H

typedef void *(*sceSifRpcFunc)(unsigned int fno, void *buffer, int length);
typedef void (*sceSifEndFunc)(void *param);

typedef struct t_sceSifRpcHeader {
    void *pkt_addr;
    unsigned int rpc_id;
    int sema_id;
    unsigned int mode;
} sceSifRpcHeader;

typedef struct t_sceSifClientData {
    sceSifRpcHeader hdr;
    unsigned int command;
    void *buff;
    void *cbuff;
    sceSifEndFunc func;
    void *para;
    struct t_sceSifServeData *serve;
} sceSifClientData;

typedef struct t_sceSifRpcDataQueue {
    int thread_id;
    int active;
    struct t_sceSifServeData *link;
    struct t_sceSifServeData *start;
    struct t_sceSifServeData *end;
    struct t_sceSifRpcDataQueue *next;
} sceSifQueueData;

typedef struct t_sceSifServeData {
    unsigned int command;
    sceSifRpcFunc func;
    void *buff;
    int size;
    sceSifRpcFunc cfunc;
    void *cbuff;
    int csize;
    sceSifClientData *client;
    void *paddr;
    unsigned int fno;
    void *receive;
    int rsize;
    int rmode;
    unsigned int rid;
    struct t_sceSifServeData *link;
    struct t_sceSifServeData *next;
    sceSifQueueData *base;
} sceSifServeData;

extern void sceSifInitRpc(int mode);
extern int sceSifBindRpc(sceSifClientData *client, unsigned int number, unsigned int mode);
extern int sceSifCallRpc(sceSifClientData *client, unsigned int fno, unsigned int mode,
                         void *send, int ssize, void *receive, int rsize,
                         sceSifEndFunc func, void *para);
extern void sceSifRegisterRpc(sceSifServeData *serve, unsigned int fno, sceSifRpcFunc func,
                              void *buff, sceSifRpcFunc cfunc, void *cbuff,
                              sceSifQueueData *base);
extern sceSifQueueData *sceSifSetRpcQueue(sceSifQueueData *queue, int thread_id);
extern sceSifServeData *sceSifGetNextRequest(sceSifQueueData *queue);
extern void sceSifExecRequest(sceSifServeData *serve);
extern void sceSifRpcLoop(sceSifQueueData *queue);
extern int sceSifCheckStatRpc(sceSifRpcHeader *header);
extern void *sceSifAllocIopHeap(int size);
extern int sceSifFreeIopHeap(void *addr);

#endif /* CRI_SHIM_SIFRPC_H */
