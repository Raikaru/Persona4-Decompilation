/* Closest compliant plain-C probe for func_003e2430; not an exact match. */
s32 func_003e2430(void) {
    Ctx2430003e *ctx;
    Node2430003e *node;
    Node2430003e *next;
    void (*callback)(u8 *);

    ctx = (Ctx2430003e *)(D_008872E0 + (s32)iGpffffb780);
    ctx->head_prev = ctx->tail_next;
    node = (Node2430003e *)ctx->head_next;
    if (node != (Node2430003e *)&ctx->tail_next) {
        do {
            next = (Node2430003e *)node->next;
            callback = (void (*)(u8 *))node->cb;
            if (callback != NULL) {
                callback((u8 *)node);
            }
            if (node->dtor != NULL) {
                *(s32 *)node->dtor = 0;
            }
            if (next != NULL) {
                *(void **)node->prev = (void *)next;
                next->prev = node->prev;
                ctx->unk4 -= node->size;
                func_003e4520((void *)node, node->size);
            } else {
                jtbl_008873EC[0]((u8 *)node);
            }
            node = next;
        } while (node != (Node2430003e *)&ctx->tail_next);
    }
    ctx = (Ctx2430003e *)(D_008872E0 + (s32)iGpffffb780);
    ctx->head_next = (void *)&ctx->head_next;
    ctx->head_prev = (void *)&ctx->head_next;
    ctx->tail_next = (void *)&ctx->head_next;
    ctx->tail_prev = (void *)&ctx->head_next;
    ctx->count = 0;
    return 1;
}
