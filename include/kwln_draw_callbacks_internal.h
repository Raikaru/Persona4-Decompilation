#ifndef KWLN_DRAW_CALLBACKS_INTERNAL_H
#define KWLN_DRAW_CALLBACKS_INTERNAL_H

/* Queue dispatch supplies the node followed by its work argument. These
 * adapters ignore the node and forward the second argument unchanged. */
void kwlnTaskGetWorkCallback(void *node, void *work);
void itfMesFlushPendingCallback(void *node, void *work);
void yTimeLimitDrawCallback(void *node, void *work);
void mcDrawDispatchCallback(void *node, void *work);
void pscModelDrawCallback(void *node, void *work);

#endif
