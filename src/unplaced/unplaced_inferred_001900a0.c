/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 001900a0-00190130 */

#include "btl_skill_target_internal.h"
#include "rw_geometry_internal.h"
#include "model_motion_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_packet_create_internal.h"
#include "effect_instance_internal.h"
#include "btl_skill_internal.h"
#include "datPersona_internal.h"
#include "datUnit_internal.h"
#include "rw_types_internal.h"
static inline s32 *fldMapEditorEntryAtOffset(s32 offset, s32 *base)
{
    return (s32 *)((s32)base + offset);
}

extern void func_003ef3a0(s32);
extern void (*jtbl_008873EC[])(void *arg0);
extern void chkmemAllocSiteTag(void *file, s32 line);
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 K_MapEditTask(u8 *task);
// FUN_001900A0
/* Destroy the nine loaded texture dictionaries, then release editor work. */
void K_MapEdit_Destroy(u8 *task)
{
    s32 *entries;
    s32 dictionary;
    s32 index;

    /* Task work is at +0x38; retain the pointer access types for MWCC reloads. */
    entries = *(s32 **)(task + 0x38);
    index = 0;
    while (index < 9) {
        dictionary = fldMapEditorEntryAtOffset(index * 4, entries)[1];
        if (dictionary != 0) {
            func_003ef3a0(dictionary);
        }
        index++;
    }
    jtbl_008873EC[0](*(void **)(task + 0x38));
}

// FUN_00190130
/* Allocate the 0x1CD20-byte map editor and attach it to its parent task. */
s32 K_MapEdit_Create(s32 parent)
{
    s32 *work;

    chkmemAllocSiteTag(D_005F6010, 0x184);
    work = (s32 *)D_008873F4[0](1, 0x1CD20, 0x40000);
    if (work == NULL) {
        return 0;
    }
    return (s32)kwlnTaskCreateChild((void *)((u8 *)parent), (const void *)(D_005F6020), 0xF, 0, 0, K_MapEditTask, K_MapEdit_Destroy, (u8 *)(work));
}
