
#include "include_asm.h"
#include "type.h"
#include "scr_internal.h"
#include "effect_instance_internal.h"
#include "datPersona_internal.h"
extern u32 kwlnTaskGetWork(void *task);
extern void (*jtbl_008873EC[])(void *ptr);
extern s32 TnGetTableBase(void);
extern void TnSetTableBase(s32 table);

/* Five words consumed by the task callbacks; the fourth is not used here. */
typedef struct BlurFilterTaskWork {
    s32 kind;
    s32 filter;
    s32 elapsed;
    s32 unk0C;
    s32 tableBase;
} BlurFilterTaskWork;
// Task update for a blur filter task: advances the direct or copied blur filter and syncs it.
// FUN_0025F960
s32 effBlurFilterTaskUpdate(u8 *task) {
    s32 savedTableBase;
    BlurFilterTaskWork *work;
    s32 kind;

    work = (BlurFilterTaskWork *)kwlnTaskGetWork(task);
    if (work->tableBase != 0) {
        savedTableBase = TnGetTableBase();
        TnSetTableBase(work->tableBase);
    }
    kind = work->kind;
    switch (kind) {
    case 0:
        effBlurFilterDirectAdvanceAndSync((u8 *)work->filter);
        work->elapsed = work->elapsed + 1;
        break;
    case 1:
        effBlurFilterCopiedAdvanceAndSync((u8 *)work->filter);
        work->elapsed = work->elapsed + 1;
        break;
    }
    if (work->tableBase != 0) {
        TnSetTableBase(savedTableBase);
    }
    return 0;
}

// Task destroy for a blur filter task: destroys the direct or copied blur filter, then frees the
// work block.
// FUN_0025FA30
void effBlurFilterTaskDestroy(u8 *task)
{
    BlurFilterTaskWork *work;
    s32 kind;

    work = (BlurFilterTaskWork *)kwlnTaskGetWork(task);
    kind = work->kind;
    switch (kind) {
    case 0:
        effBlurFilterDirectDestroy((void *)work->filter);
        break;
    case 1:
        effBlurFilterCopiedDestroy((void *)work->filter);
        break;
    }
    jtbl_008873EC[0](work);
}
