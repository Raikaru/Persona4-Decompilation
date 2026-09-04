/*
 * Target: func_004b5800 @ 0x004B5800
 *
 * Best compilable C floor measured with MWCCPS2 b210 -O2 through
 * tools/fndiff.py.  Object size is 324 B; the retail window is 336 B.
 * The body has 5 differing words (reloc-masked):
 *
 *   +0x54 (84): MWCC emits sll $s0,$s3,3; retail emits lw $v1,4($s4).
 *   +0x58 (88): MWCC emits lw $v1,4($s4); retail emits sll $s0,$s3,3.
 *   +0x144 (324), +0x148 (328), +0x14C (332): retail-only zero tail
 *   padding; all executable words and relocations otherwise agree.
 *
 * Measured source-shaping attempts:
 *   - plain while-loop body below: obj 324 B, fndiff nd 5;
 *   - typed local generator and typed RuntimeVpadWork parameter: nd 6 and
 *     nd 5 respectively, with no change to the two loop words;
 *   - explicit request temporary: obj 320 B, nd 61;
 *   - #pragma schedule off and #pragma opt_propagation off: unchanged nd 5;
 *   - #pragma schedule on: obj 288 B, nd 72;
 *   - #pragma opt_common_subs off: obj 344 B, nd 73;
 *   - AST permuter seed 47 for 90 seconds: 2,584 compilations, no exact hit
 *     (best score 11).
 *
 * Required declarations already present in src/Kosaka/k_vpad.c:
 *   RuntimeVec3, RuntimeMatrix, RuntimeWork, RuntimeListNode;
 *   func_004b6de0(RuntimeListNode *);
 *   func_003e0f80(void), func_0047a510(void *, void *, RuntimeMatrix *),
 *   func_003e0f40(void *).
 *
 * Keep src/Kosaka/k_vpad.c on its INCLUDE_ASM fallback until a future
 * compiler/source-shape measurement closes the sll/lw schedule difference.
 */
void func_004b5800(RuntimeWork* work)
{
    s32 i;
    RuntimeMatrix* firstMatrix;
    RuntimeMatrix* secondMatrix;

    if (func_004b6de0((RuntimeListNode*)work) == 0)
    {
        return;
    }

    firstMatrix = func_003e0f80();
    secondMatrix = func_003e0f80();
    i = 0;
    while (i < *(s16*)((u8*)(uintptr_t)work->requestFlags + 4))
    {
        func_0047a510(
            *(void**)((u8*)(uintptr_t)work->requestFlags + 0x20),
            *(void**)((u8*)*(void**)((u8*)(uintptr_t)work->requestFlags + 0x18) +
                      i * 8),
            firstMatrix);
        func_0047a510(
            *(void**)((u8*)(uintptr_t)work->requestFlags + 0x20),
            *(void**)((u8*)*(void**)((u8*)(uintptr_t)work->requestFlags + 0x18) +
                      i * 8 + 4),
            secondMatrix);
        ((RuntimeVec3*)(uintptr_t)work->selection)[i * 2] =
            *(RuntimeVec3*)((u8*)firstMatrix + 0x30);
        ((RuntimeVec3*)(uintptr_t)work->selection)[i * 2 + 1] =
            *(RuntimeVec3*)((u8*)secondMatrix + 0x30);
        i++;
    }

    work->flags |= 2;
    func_003e0f40(firstMatrix);
    func_003e0f40(secondMatrix);
}
