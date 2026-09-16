/* Floor: 1760B window, obj 1748B, 39 differing words, and every one of them
   is a register name: an instruction-level alignment against retail reports
   zero inserts and zero deletes.  Retail colours `result` $s0 and `count`
   $s1; this build swaps the pair, and the later $s1/$s3 rotation at the
   case-2 entry follows because each build reuses whichever register the
   count freed.  Measured inert: declaration order for both variables in
   every position, variable names, local and parameter types, statement
   order, an extra AI-table local, inlining the `unit` deref, merging `r`
   into `result`, and opt_propagation / opt_lifetimes / opt_dead_assignments
   / opt_strength_reduction / opt_unroll_loops / optimization_level.
   `optimize_for_size off` flips the pair but re-colours five other
   variables (284 words); `-O2,p` for the unit costs 17 matched functions.
   Micro-experiments flip the pair only when `result` outlives the switch or
   `count` is consumed once before it, and retail's code does neither. */
/* INCLUDE_ASM retained in src; retail disassembly is the authoritative body. */
s32 func_001dd920(u8 *arg0, u8 *arg1, s16 arg2, s32 arg3)
{
    u8 *unit;
    u16 count;
    u16 *commands;
    u16 table[8];
    u16 n;
    s16 result;
    u16 cmd;
    u32 hp;
    u32 max;
    s32 cur;
    s32 r;

    result = -1;
    n = 0;
    unit = *(u8 **)(arg0 + 0x30);
    count = func_0023e130(*(u8 **)(unit + 0xA64));
    commands = (u16 *)func_0023e140(*(u8 **)(unit + 0xA64));
    if (func_002428f0(*(u32 *)(*(u32 *)(arg1 + 0x30) + 0xA64), 0) != 0) {
        result = 0;
    } else {
        hp = *(u16 *)(*(u32 *)(*(u32 *)(arg1 + 0x30) + 0xA64) + 8);
        max = (u16)func_00231f80(*(u32 *)(*(u32 *)(arg1 + 0x30) + 0xA64));
        if (hp * 100 <= max * 60) {
            result = 1;
        } else {
            if (func_00232710(*(u32 *)(*(u32 *)(arg1 + 0x30) + 0xA64), 0xC) != 0) {
                result = 2;
            } else {
                cur = func_00231ed0(*(u32 *)(*(u32 *)(arg1 + 0x30) + 0xA64)) & 0xFFFF;
                if (cur < (s32)(func_00231f80(*(u32 *)(*(u32 *)(arg1 + 0x30) + 0xA64)) & 0xFFFF))
                    result = 1;
            }
        }
    }
    switch (result) {
    case 0: {
        u16 i;
        u16 *entry;
        s32 limit;

        i = 0;
        limit = count;
        while (i < limit) {
            entry = commands + i;
            cmd = *entry;
            if (cmd != 0 && cmd < 0x1B8) {
                switch (cmd) {
                case 0xD1: case 0xD2:
                    if (btlCommandUsable(arg0, cmd)) {
                        table[n] = *entry;
                        n++;
                    }
                    break;
                }
            }
            i++;
        }
        break;
    }
    case 1: {
        u16 i;
        u16 *entry;
        s32 limit;

        i = 0;
        limit = count;
        while (i < limit) {
            entry = commands + i;
            cmd = *entry;
            if (cmd != 0 && cmd < 0x1B8) {
                switch (cmd) {
                case 0xC0: case 0xC1: case 0xC2: case 0xC3:
                case 0xC4: case 0xC5: case 0xC6:
                    if (btlCommandUsable(arg0, cmd)) {
                        table[n] = *entry;
                        n++;
                    }
                    break;
                }
            }
            i++;
        }
        if (n > 0) {
            switch (arg3) {
            case 0:
                r = func_001dd3a0(arg0, arg1, table, n, 0);
                if (r < 0)
                    r = func_001dd3a0(arg0, arg1, table, n, 1);
                break;
            case 1:
                r = func_001dd3a0(arg0, arg1, table, n, 1);
                if (r < 0)
                    r = func_001dd3a0(arg0, arg1, table, n, 0);
                break;
            default:
                r = func_001dd3a0(arg0, arg1, table, n, 0xFFFF);
                break;
            }
            return r;
        }
        break;
    }
    case 2: {
        u16 i;
        u16 *entry;
        s32 limit;

        i = 0;
        limit = count;
        while (i < limit) {
            entry = commands + i;
            cmd = *entry;
            if (cmd != 0 && cmd < 0x1B8) {
                switch (cmd) {
                case 0xC7: case 0xC8:
                    if (btlCommandUsable(arg0, cmd)) {
                        table[n] = *entry;
                        n++;
                    }
                    break;
                }
            }
            i++;
        }
        break;
    }
    }
    if (n > 0)
        return table[func_00231d70(n)];
    return -1;
}
