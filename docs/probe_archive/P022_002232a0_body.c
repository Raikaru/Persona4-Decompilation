/* Complete ordinary-C reconstruction; production remains INCLUDE_ASM.
 * Correct owner compiler profile: 1020 object bytes / 1040-byte retail window;
 * retail executable extent is 1036 bytes, followed by four alignment bytes.
 * Fully resolved comparison: 788 differing overlap bytes, 256 executable-word
 * positions including 16 missing executable bytes, no overrun or unresolved
 * relocations. All 26 code relocations and nine 36-byte jump-table entries
 * were checked. All nine generated table targets differ from retail.
 * No runtime/game execution is claimed for this archived candidate.
 *
 * The real 0x94-byte input block is declared as D_008C0240[], as in sdkTask.c.
 * Its +0xC/+0xE halfwords must not be declared standalone small-data scalars:
 * that first spelling emitted unrepresentable GP-relative displacements.
 *
 * Registered-work invariant: constructor 00223730 clears 0x54 bytes and enters
 * state 0; initialization gives index=0 and count<=12. The two increment sites
 * follow index<count and advance only once. Parent exit/query and the order
 * node callback do not alter index/count. Thus 0<=index<=count<=12. Retail's
 * index>count path consumes incoming s2; this candidate does not invent that
 * input or define a fallback for corrupted task work.
 *
 * Retail jtbl_00747750 (36 bytes), state 0 through state 8:
 * 00223314 002233A4 00223558 00223560 0022358C 002235FC 0022362C 00223644 00223688
 * Actual automatic data: s32 messages[11]={12,0,6,9,10,11,13,14,19,20,21};
 * f32 position[2]={0,19}. No artificial stack padding is introduced.
 * D_00795F20 is a mutable order list with an eight-byte accessed header;
 * a zero-filled on-disk window does not establish its total extent.
 *
 * Required real contracts are now repaired: task getter u32(void*), task-aware
 * cleanup 002236c0, persona release 0011f580(u8*) returning s32, and mode
 * forwarding 00353f50 -> 002bb7c0(s32). Owner declaration of this ASM target
 * remains untouched; a future C promotion must use s32(KwlnTask*).
 */
#include "type.h"
typedef struct KwlnTask KwlnTask;
extern u32 func_00452560(void *task);
extern u8 *func_00455ea0(u8 *resource, s32 index, s32 *sizeOut);
extern u8 D_00795F20[];
extern u8 D_006296D0[];
extern u8 D_008C0240[];

extern void func_00460ac0(u8 *list, u8 *node);
extern u16 func_0010b6f0(void);
extern u16 *func_0010ace0(s16 slot);
extern u8 *func_00117780(s32 parent, s32 priority, s32 mode, s32 layout, s32 option);
extern void func_00117580(u8 *window, s32 value);
extern void func_0011d100(u8 *window, f32 *position);
extern void func_0011bb90(u8 *window);
extern void func_0011b480(u8 *window, s32 mode, u32 persona, s32 option);
extern u8 *func_0011f410(s32 parent, s32 window, s32 record, s32 payload, s32 option, s32 messages);
extern u32 func_0011f560(u8 *child);
extern s32 func_0011f580(u8 *child);
extern s32 func_00353f50(s32 mode);
extern s32 func_0021de60(void);
extern void func_0046d730(const void *file, u32 line);

s32 func_002232a0(KwlnTask *task)
{
    u8 *work;
    u8 *results;
    u8 *persona;
    u8 *payload;
    s32 index;
    s32 messages[11];
    f32 position[2];

    work = (u8 *)func_00452560(task);
    results = *(u8 **)(work + 0x40);
    *(u32 *)(work + 8) = 0;
    *(u32 *)(work + 0xC) = 0;
    func_00460ac0(D_00795F20, work + 8);

    switch (*(u32 *)(work + 4)) {
    case 0:
        *(s32 *)(work + 0x3C) = 0;
        *(s32 *)(work + 0x38) = (u16)func_0010b6f0();
        *(u8 **)(work + 0x4C) = func_00117780(0, 15, 4, 5, 0);
        if (*(u8 **)(work + 0x4C) == 0) {
            func_0046d730(D_006296D0, 0x2F);
        }
        func_00117580(*(u8 **)(work + 0x4C), 0xAE);
        position[0] = 0.0f;
        position[1] = 19.0f;
        func_0011d100(*(u8 **)(work + 0x4C), position);
        func_0011bb90(*(u8 **)(work + 0x4C));
        *(s32 *)(work + 4) = 1;
        /* fall through */
    case 1:
        results += 0x60;
        /* The registered task maintains 0 <= index <= count <= 12. */
        while ((index = *(s32 *)(work + 0x3C)) < *(s32 *)(work + 0x38)) {
            persona = (u8 *)func_0010ace0((s16)index);
            *(u32 *)(persona + 8) +=
                *(u32 *)(results + 8 + *(s32 *)(work + 0x3C) * 4);
            index = *(s32 *)(work + 0x3C);
            if (results[index * 0x88 + 0x38] != 0) {
                if (index == *(s32 *)(work + 0x38)) {
                    goto exhausted;
                }
                func_0011b480(*(u8 **)(work + 0x4C), 1, (u32)persona, 0);
                messages[0] = 12;
                messages[1] = 0;
                messages[2] = 6;
                messages[3] = 9;
                messages[4] = 10;
                messages[5] = 11;
                messages[6] = 13;
                messages[7] = 14;
                messages[8] = 19;
                messages[9] = 20;
                messages[10] = 21;
                payload = func_00455ea0(
                    *(u8 **)(*(u8 **)(work + 0x40) + 0x934), 0, 0);
                index = *(s32 *)(work + 0x3C);
                *(u8 **)(work + 0x50) = func_0011f410(
                    (s32)task, *(s32 *)(work + 0x4C),
                    (s32)(results + index * 0x88 + 0x38),
                    (s32)payload, 0, (s32)messages);
                *(u16 *)work |= 2;
                *(s32 *)(work + 4) = 2;
                return 0;
            }
            *(u32 *)(work + 0x3C) = (u32)index + 1;
        }
exhausted:
        if (*(u32 *)(*(u8 **)(work + 0x40) + 0x60) & 0x10) {
            *(u16 *)work &= 0xFFFE;
            *(s32 *)(work + 4) = 8;
        } else {
            *(u16 *)work &= 0xFFFE;
            *(s32 *)(work + 4) = 8;
            *(u16 *)work |= 4;
        }
        break;

    case 2:
        *(s32 *)(work + 4) = 3;
        /* fall through */
    case 3:
        if (func_0011f560(*(u8 **)(work + 0x50)) == 0) {
            break;
        }
        func_0011f580(*(u8 **)(work + 0x50));
        *(s32 *)(work + 4) = 4;
        *(u16 *)(work + 0x48) = 0;
        /* fall through */
    case 4:
        *(u16 *)(work + 0x48) = (u16)(*(u16 *)(work + 0x48) + 1);
        if (*(u16 *)(work + 0x48) < 45) {
            if ((*(u16 *)(D_008C0240 + 0xE) & 0x50) == 0) {
                if ((*(u16 *)(D_008C0240 + 0xC) & 0x10) == 0) {
                    break;
                }
                if (*(u16 *)(work + 0x48) < 4) {
                    break;
                }
            }
        }
        *(u32 *)(work + 0x3C) += 1;
        *(s32 *)(work + 4) = 1;
        break;

    case 5:
        if (func_00353f50(1) != 0) {
            break;
        }
        *(u16 *)work &= 0xFFFE;
        *(s32 *)(work + 4) = 8;
        break;

    case 6:
        if (func_0021de60() == 0) {
            break;
        }
        *(s32 *)(work + 4) = 7;
        /* fall through */
    case 7:
        if ((*(u16 *)work & 4) == 0) {
            *(u16 *)(work + 0x48) = (u16)(*(u16 *)(work + 0x48) + 1);
            if (*(u16 *)(work + 0x48) < 5) {
                break;
            }
        }
        *(u16 *)work &= 0xFFFD;
        return -1;

    case 8:
    default:
        break;
    }
    return 0;
}
