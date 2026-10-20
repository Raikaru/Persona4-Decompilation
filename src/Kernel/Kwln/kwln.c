/* Source unit: src/Kernel/Kwln/kwln_002519b0.c (1 function markers) */
#include "type.h"

extern void kwlnTaskGetWork(void* task);

extern void itfMesFlushPending(void* a0);

extern void yTimeLimitDraw(void* task);

extern void mcDrawDispatch(void* taskAddress);

extern void pscModelDraw(void* model);



// Intent: task callback that forwards its work pointer to kwlnTaskGetWork. Stored in a task node's +8 callback slot (comuTimerSequence_inferred_002519e0.c).
// FUN_002519B0
void kwlnTaskGetWorkCallback(void* node, void* work)
{
    kwlnTaskGetWork(work);
}



// Intent: callback that forwards its work pointer to itfMesFlushPending. Stored in a manager node's +8 callback slot (itfMesManager_inferred_0027b5d0.c).
// FUN_0027B5A0
void itfMesFlushPendingCallback(void* node, void* work)
{
    itfMesFlushPending(work);
}



// Intent: draw-node callback that forwards its work pointer to yTimeLimitDraw. Stored in the draw node's +8 slot.
// FUN_002A1EF0
void yTimeLimitDrawCallback(void* node, void* work)
{
    yTimeLimitDraw(work);
}



// Intent: draw-node callback that forwards its work pointer to mcDrawDispatch. Stored in a draw work item's +8 slot (Kernel/mc.c).
// FUN_002A6650
void mcDrawDispatchCallback(void* node, void* work)
{
    mcDrawDispatch(work);
}



// Intent: draw-node callback that forwards its work pointer to pscModelDraw. Stored in a panel draw node's +8 slot (gc_model_inferred_00369470.c).
// FUN_00369440
void pscModelDrawCallback(void* node, void* work)
{
    pscModelDraw(work);
}
extern void (*D_00887300[])();
extern s32 (*D_00887310[])(s32, void *, s32);
extern void (*D_00887304[])();
extern void (*D_008873EC[])(void *);
extern s8 iGpffffba84;
extern s8 iGpffffba85;
extern s8 iGpffffba86;
extern s8 iGpffffba87;
extern s8 iGpffffba88;
extern s8 iGpffffba89;
extern s8 iGpffffba8a;
extern s8 iGpffffba8b;
extern void (*D_008873FC[])(s32 param, u8* arg);
// Intent: sets the four bytes of the kwln RGBA colour record (the one kwlnGetColorRgb returns).
// FUN_00457140
void kwlnSetColorRgba(u8 red, u8 green, u8 blue, u8 alpha)
{
    iGpffffba88 = red;
    iGpffffba89 = green;
    iGpffffba8a = blue;
    iGpffffba8b = alpha;
}


// Intent: sets the four bytes of the kwln colour record that kwlnGetColorBytes returns.
// FUN_00457170
void kwlnSetColorBytes(s8 red, s8 green, s8 blue, s8 alpha)
{
    iGpffffba84 = red;
    iGpffffba85 = green;
    iGpffffba86 = blue;
    iGpffffba87 = alpha;
}


