/* func_002add90 (y_smap.c, window 1936B) -- 2026-09-26 group 0 round 4.
 * Fresh rewrite from the retail listing. Object is 1920B against retail's
 * 1924B of code, with about 93 aligned instruction edits (the old guarded draft
 * had 203 edits). NOT installed.
 *
 * Shape found:
 * - The dungeon map is SmapGrid (0x50-byte header, then 16x16 cells of 16
 *   bytes: kind at +4, wall bits at +0xE, door bits at +0xF). Every
 *   access re-calls func_00155280(), as retail does. Neighbour checks are
 *   cell[y][x+-1] / cell[y+-1][x], which fold into retail's 0x64/0x44/
 *   -0xAC/0x154 offsets.
 * - D_007EFA04 must be an unsized array (`extern u8 *D_007EFA04[]`) to get
 *   retail's absolute lui/lw rather than a gp load.
 * - p[4] is s8 (lb) for both the switch and the increment. The first switch
 *   arms fall through (2->5->1, 3->6->4) with a shared `return 0`.
 * - The unit-slot check reproduces retail's sltu/`== 1` only as
 *   `(u8)(live != 0) == 1`. Plain `(live != 0) == 1` folds to beqz.
 * - u8 buf[0xC] copied to YVec3f pos matches retail's lwc1/swc1 copy
 *   (a YVec3f buf gives ld/sd).
 * - The tile-scale literal is 66.666664f (gp -0x7B08).
 * Residual: saved-register roles are permuted. Retail has p s1, unit
 * counter s0, slot s2, x s2/s3, y s4, y<<8 s0. A 500-step
 * declaration-order hill-climb found one step (107 -> 93). The (u8)x
 * re-mask is placed differently, and the -6 adds in the tile loop are
 * scheduled after the D_007EFA04 reload.
 */
/* One 16-byte floor cell of the dungeon map; rows are 16 cells wide and the
   grid starts 0x50 bytes into the map block. */
typedef struct SmapCell {
    u8 pad0[4];
    u8 kind;
    u8 pad5[9];
    u8 wall;
    u8 door;
} SmapCell;

typedef struct SmapGrid {
    u8 pad0[0x50];
    SmapCell cell[16][16];
} SmapGrid;

#define SMAP_GRID() ((SmapGrid *)func_00155280())

// FUN_002ADD90
s32 func_002add90(u8 *arg0)
{
    extern u8 func_002b11c0(YVec3f *pos);
    extern u8 func_002b1210(YVec3f *pos);
    extern s32 func_002b6850(u8 *arg0);
    extern void func_002b67a0(u8 *arg0, u32 arg1, s8 arg2);
    extern s32 func_002b4a10(s32 arg0, s32 arg1);
    extern s32 func_00452490(void *target);
    YVec2f scale;
    YVec3f pos;
    u8 buf[0xC];
    YVec3f d1;
    YVec3f d2;
    u8 *p;
    u8 *task;
    s32 j;
    u8 y;
    s32 i;
    u8 x;

    p = *(u8 **)(arg0 + 0x38);
    func_001687f0(buf, *(u8 **)(D_007EFA04[0] + 0x220));
    pos = *(YVec3f *)buf;
    task = func_00460990();
    *(void **)(task + 8) = func_002add10;
    *(u8 **)(task + 0x10) = p;
    func_00460ac0(D_00794C30, task);
    task = func_00460990();
    *(void **)(task + 8) = func_002add60;
    *(u8 **)(task + 0x10) = p;
    func_00460ac0(D_00794E10, task);
    switch ((s8)p[4]) {
    case 0:
        func_002b2290(arg0);
        (*(s8 *)(p + 4))++;
        break;
    case 2:
        *(s16 *)(p + 0x766) = func_002b2cb0(*(s16 *)(p + 0x766), 1, 5, 0, 1);
        if ((s8)func_002b6850(*(u8 **)(p + 0x748)) == 0) {
            func_002b67a0(*(u8 **)(p + 0x748), 0, 1);
        }
        if ((s8)func_002b6850(*(u8 **)(p + 0x74C)) == 0) {
            func_002b67a0(*(u8 **)(p + 0x74C), 0, 1);
        }
    case 5:
        *(s16 *)(p + 0x764) = func_002b2cb0(*(s16 *)(p + 0x764), 1, 10, 0, 1);
    case 1:
        p[0xB8] = 0;
        for (i = 0; i < 15; i++) {
            s32 live = 0;
            u8 *unit = D_007E8C00 + i * 0x750;

            if ((*(s32 *)(unit + 0x48) != 0) && (*(s32 *)(unit + 0x54) != 0)) {
                live = 1;
            }
            if ((u8)(live != 0) == 1) {
                u8 **slot = (u8 **)(p + 0xD8) + i;

                if (*slot == NULL) {
                    *slot = (u8 *)func_002b4a10((s32)arg0, (s8)i);
                }
            }
        }
        x = func_002b11c0(&pos);
        y = func_002b1210(&pos);
        func_002ac750(x, y);
        if (SMAP_GRID()->cell[y][x + 1].kind == 1 && (SMAP_GRID()->cell[y][x].wall & 8)) {
            if (SMAP_GRID()->cell[y][x].door & 8) {
                if (SMAP_GRID()->cell[y][x].door & 0x80) {
                    func_002ac750((u8)(x + 1), y);
                }
            } else {
                func_002ac750((u8)(x + 1), y);
            }
        }
        if (SMAP_GRID()->cell[y][x - 1].kind == 1 && (SMAP_GRID()->cell[y][x].wall & 2)) {
            if (SMAP_GRID()->cell[y][x].door & 2) {
                if (SMAP_GRID()->cell[y][x].door & 0x20) {
                    func_002ac750((u8)(x - 1), y);
                }
            } else {
                func_002ac750((u8)(x - 1), y);
            }
        }
        if (SMAP_GRID()->cell[y - 1][x].kind == 1 && (SMAP_GRID()->cell[y][x].wall & 1)) {
            if (SMAP_GRID()->cell[y][x].door & 1) {
                if (SMAP_GRID()->cell[y][x].door & 0x10) {
                    func_002ac750(x, (u8)(y - 1));
                }
            } else {
                func_002ac750(x, (u8)(y - 1));
            }
        }
        if (SMAP_GRID()->cell[y + 1][x].kind == 1 && (SMAP_GRID()->cell[y][x].wall & 4)) {
            if (SMAP_GRID()->cell[y][x].door & 4) {
                if (SMAP_GRID()->cell[y][x].door & 0x40) {
                    func_002ac750(x, (u8)(y + 1));
                }
            } else {
                func_002ac750(x, (u8)(y + 1));
            }
        }
        func_002b31a0((u8 *)&d1, p + 8, (u8 *)&pos);
        scale.x = (s32)(d1.x / 66.666664f);
        func_002b31a0((u8 *)&d2, p + 8, (u8 *)&pos);
        scale.y = (s32)(d2.z / 66.666664f);
        for (i = 0; i < 13; i++) {
            for (j = 0; j < 13; j++) {
                s16 tx = i + func_001687d0(*(u8 **)(D_007EFA04[0] + 0x220)) - 6;
                s16 ty = j + func_001687e0(*(u8 **)(D_007EFA04[0] + 0x220)) - 6;

                if ((tx > 0) && (ty > 0) && (tx < 16) && (ty < 24)) {
                    u8 **tile = (u8 **)(p + 0x148) + ty * 16 + tx;

                    if (func_00452490(*tile) == 1) {
                        if ((((u16)(1 << tx) & ((u16 *)D_00764658)[ty]) >> tx) == 1) {
                            func_002b10e0(*tile, 1);
                        }
                        func_002b10a0(*tile, scale);
                    }
                }
            }
        }
        func_002b2240(arg0);
        break;
    case 3:
        *(s16 *)(p + 0x766) = func_002b2cb0(*(s16 *)(p + 0x766), 1, 5, 0, 1);
    case 6:
        *(s16 *)(p + 0x764) = func_002b2cb0(*(s16 *)(p + 0x764), 1, 5, 0, 1);
    case 4:
        func_002b2240(arg0);
        break;
    case 7:
        return -1;
    }
    return 0;
}
