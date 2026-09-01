/* archived best measured attempt: object=64 window=64 normalized_diff=14. */
#include "type.h"
typedef void (*Code1B9Callback)(s32 arg0, s32 arg1, void *arg2);
typedef struct {
    Code1B9Callback callback;
    s32 arg1;
    s32 count;
} Code1B9Work;
extern Code1B9Work D_00745C78;
void func_0052b9a0(s32 arg0, s32 arg1, void *arg2)
{
    Code1B9Work *work = &D_00745C78;

    work->count += 1;
    if (work->callback != NULL) {
        work->callback(work->arg1, (s32)arg2, work->callback);
    }
}
