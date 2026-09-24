#include "type.h"

/* Persona 4 SRD/PS2EE 2.22 DVD and host execution state machines,
 * independently derived from retail code at 0x004E3DC8..0x004E417C.
 * Older CRI 2.18a source at
 * https://github.com/crowded-street/3s-decomp/blob/main/src/anniversary/cri/libadxe/cri_srd.c
 * corroborates the API names, not this implementation; no external source
 * bodies were copied. */

typedef struct {
    s8 used, devtype, stat, pad;
    s32 active, sector, count;
    void *dvd_buffer;
    u8 mode[4];
    void *buffer;
    s32 pad1c, size, pad24;
    s64 offset;
    s32 fd, error;
} SRD;

extern volatile s32 D_00731C54;
extern s32 D_00731C78;
extern u8 D_00731C7C;
extern const char D_0075AB48[];
extern s32 func_0042f548(void), func_0042e7c8(s32);
extern s32 func_0042f200(s32, s32, void *, u8 *), func_004e3c78(SRD *);
extern void func_004244c8(const char *, ...);
extern volatile s32 D_00731C58, D_00731C5C;
extern void func_004e4618(s32), func_004e3a10(SRD *);
extern s64 func_004e47f8(s32, s64, s32), func_004e49e8(s32, void *, s32);
extern s32 func_004e48b0(s32, s32, s32 *);

/* srd_exec_dvd: DVD break, read and sync state machine. */
// FUN_004E3DC8
void func_004e3dc8(SRD *srd) {
    s32 break_ok, read_ok, sync, check;
    if (srd->active == 1) {
        /* Explicit states preserve retail's ten-entry dispatch table. */
        switch (srd->stat) {
        case 2:
            func_004e4618(0x1600);
            break_ok = func_0042f548();
            func_004e4618(0x1601);
            if (break_ok == 0) func_004244c8(D_0075AB48, D_00731C54);
            func_004e4618(0x1700);
            func_0042e7c8(0);
            func_004e4618(0x1701);
            srd->stat = 0;
            ++D_00731C5C;
            break;
        case 1: case 3: case 9:
            srd->stat = 0;
            /* fall through */
        case 0: case 4: case 5: case 6: case 7: case 8:
        default:
            break;
        }
        srd->active = 0;
    }
    if (srd->stat == 1) {
        func_004e4618(0x1800);
        if (D_00731C78 == 1) srd->mode[1] = D_00731C7C;
        read_ok = func_0042f200(srd->sector, srd->count,
                                srd->dvd_buffer, srd->mode);
        func_004e4618(0x1801);
        if (read_ok == 1) {
            ++D_00731C58;
            srd->stat = 2;
        } else {
            srd->stat = 9;
            srd->error = -1;
        }
    }
    if (srd->stat == 2) {
        func_004e4618(0x1900);
        sync = func_0042e7c8(1);
        func_004e4618(0x1901);
        check = func_004e3c78(srd);
        if (sync == 0) {
            srd->stat = (check == 1) ? 9 : 3;
            ++D_00731C5C;
        }
    }
}

/* srd_exec_hst: host seek/read state machine. */
// FUN_004E3FB0
void func_004e3fb0(SRD *srd) {
    s64 result;
    s32 done;
    if (srd->active == 1) {
        /* All ten observed states retain the retail jump-table lowering. */
        switch (srd->stat) {
        case 2:
            func_004e3a10(srd);
            srd->stat = 0;
            ++D_00731C5C;
            /* fall through */
        case 1: case 3: case 9:
            srd->stat = 0;
            /* fall through */
        case 0: case 4: case 5: case 6: case 7: case 8:
        default:
            srd->active = 0;
            break;
        }
    }
    if (srd->stat == 1) {
        func_004e4618(0x2000);
        result = func_004e47f8(srd->fd, srd->offset << 11, 0);
        func_004e4618(0x2001);
        if (result < 0) {
            srd->stat = 9;
            srd->error = (s32)result;
        }
        func_004e4618(0x2100);
        result = func_004e49e8(srd->fd, srd->buffer, srd->size);
        func_004e4618(0x2101);
        if (result >= 0) {
            srd->stat = 2;
            ++D_00731C58;
        } else {
            srd->stat = 9;
            srd->error = (s32)result;
        }
    }
    if (srd->stat == 2) {
        func_004e4618(0x2200);
        if (func_004e48b0(srd->fd, 1, &done) < 0) {
            func_004e4618(0x2201);
            srd->stat = 9;
            srd->error = -1;
        } else {
            func_004e4618(0x2202);
            if (done == 0) {
                srd->stat = 3;
                ++D_00731C5C;
            }
        }
    }
}


