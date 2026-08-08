/* Consolidated Persona 4 source units. */
/* Original translation unit k_readtex.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

extern void (*jtbl_008873EC[])(u8 *);

extern void func_0044ea90(const void *msg, s32 id);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern s32 func_00451de0(const void *data, s32 a, s32 b, s32 c,
                         s32 (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern u8 D_005F60B8[];
extern u8 D_005F6040[];
extern u8 D_005F6060[];
extern u8 D_005F6080[];
extern u8 D_005F60A0[];
extern u8 D_005F60D0[];
extern u8 D_005F60F0[];
extern u8 D_005F6110[];
extern u8 D_005F6130[];
extern u8 D_005F6150[];
extern s32 func_001901d0(u8 *arg0);
extern void func_001905d0(u8 *arg0);
extern void func_003ef3a0(void *handle);
extern s32 func_003ef6d0(void);
extern void *func_003ef650(s32 owner, const void *name);
extern void func_00440b68(const void *file, const void *message, s32 line);
extern void *func_00454a60(const char *path, s32 flags);
extern void func_00454bd0(void *handle);
extern s32 func_004667d0(s32, const void *, s32, s32, s32, s32, s32, s32, s64, s64);
extern void func_004669d0(s32 task, s32 *result, s32 flags);
extern s32 iGpffffa030;





// FUN_001901D0
s32 func_001901d0(u8 *arg0)
{
    typedef struct {
        s32 state;
        void *handles[4];
        s32 tasks[4];
        u8 pad24[0x14];
        s32 *owner;
    } ReadTexState;
    ReadTexState *state;
    void *handle;
    s32 i;
    s32 *slot;
    s32 result;

    state = *(ReadTexState **)(arg0 + 0x38);
    switch (state->state) {
    case 0:
        handle = func_003ef650(func_003ef6d0(), D_005F6040);
        if (handle != NULL) {
            func_003ef3a0(handle);
        }
        handle = func_003ef650(func_003ef6d0(), D_005F6060);
        if (handle != NULL) {
            func_003ef3a0(handle);
        }
        handle = func_003ef650(func_003ef6d0(), D_005F6080);
        if (handle != NULL) {
            func_003ef3a0(handle);
        }
        handle = func_003ef650(func_003ef6d0(), D_005F60A0);
        if (handle != NULL) {
            func_003ef3a0(handle);
        }
        func_00440b68(&iGpffffa030, D_005F60B8, 0x54);
        state->handles[0] = func_00454a60((const char *)D_005F60D0, 0);
        func_00440b68(&iGpffffa030, D_005F60B8, 0x55);
        state->handles[1] = func_00454a60((const char *)D_005F60F0, 0);
        func_00440b68(&iGpffffa030, D_005F60B8, 0x56);
        state->handles[2] = func_00454a60((const char *)D_005F6110, 0);
        func_00440b68(&iGpffffa030, D_005F60B8, 0x57);
        state->handles[3] = func_00454a60((const char *)D_005F6130, 0);
        state->state += 1;
        /* fall through */
    case 1:
        if (func_004553c0(state->handles[0]) == 0) {
            return 0;
        }
        if (func_004553c0(state->handles[1]) == 0) {
            return 0;
        }
        if (func_004553c0(state->handles[2]) == 0) {
            return 0;
        }
        if (func_004553c0(state->handles[3]) == 0) {
            return 0;
        }
        state->tasks[0] = func_004667d0(0, D_005F6040, 0, 0, 0, 0, 0, 0, 0, 0);
        state->tasks[1] = func_004667d0(0, D_005F6060, 0, 0, 0, 0, 0, 0, 0, 0);
        state->tasks[2] = func_004667d0(0, D_005F6080, 0, 0, 0, 0, 0, 0, 0, 0);
        state->tasks[3] = func_004667d0(0, D_005F60A0, 0, 0, 0, 0, 0, 0, 0, 0);
        state->state += 1;
        /* fall through */
    case 2:
        for (i = 0; i < 4; i++) {
            slot = &state->tasks[i];
            if (*slot != 0) {
                func_004669d0(*slot, &result, 0);
                if (result != 0) {
                    *slot = 0;
                    continue;
                }
                return 0;
            }
        }
        func_00454bd0(state->handles[0]);
        func_00454bd0(state->handles[1]);
        func_00454bd0(state->handles[2]);
        func_00454bd0(state->handles[3]);
        return -1;
    default:
        return 0;
    }
}

// FUN_001905D0
void func_001905d0(u8 *arg0) {
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}



// FUN_00190600
void func_00190600(void)
{
    u8 *mem;

    func_0044ea90(D_005F60B8, 0x91);
    mem = D_008873F4[0](1, 0x24, 0x40000);
    if (mem != NULL) {
        func_00451de0(D_005F6150, 0xF, 0, 0, func_001901d0, func_001905d0, mem);
    }
}

