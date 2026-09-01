/* NOT a normal reconstruction target: the 240-byte window at func_003ca740
   genuinely spans THREE independent tail-call trampolines with separate
   entry points, confirmed by raw disassembly:

     0x3ca740-0x3ca774 (52B): func_003ca740 itself. Tail-jumps through
       *(p+16) after copying *(p+12) to D_008872E4 and incrementing the
       D_008872E8 counter. No stack frame.
     0x3ca780-0x3ca79c (28B): a second, unrelated trampoline. Zeroes
       D_008872E4 then tail-jumps through *(p+20). No stack frame.
     0x3ca7a0-0x3ca82c (140B): a real function with its own sq/lq-saved
       frame, unrelated control flow (dispatch via *(p+24), *(p+12),
       calls to func_003cb300 and a global function-pointer D_00887380).

   Both IDA Hex-Rays and manual disassembly agree on this split; Ghidra's
   own auto-analysis independently placed 3 separate function boundaries at
   these exact 3 addresses when asked to create one at 0x3ca740.

   Only 0x3ca740 has an entry in tools/slus21782_functions.json; 0x3ca780
   and 0x3ca7a0 have none, so the campaign's own window table treats all
   240 bytes as belonging to one marker. verify.py's function() scores a
   marker by ITS COMPILED SYMBOL'S OWN byte length (obj.function(name),
   ELF symbol table lookup), not by an address range in the final linked
   image -- so three separate C function definitions, even placed
   sequentially in source, do not get concatenated under one marker's
   score. Confirmed empirically: writing all 3 as separate functions
   compiles correctly (103 MATCH preserved) but scores func_003ca740 at
   its own 52/80-byte size against the 240-byte window every time,
   regardless of what follows in source.

   This is not a source-shape problem reachable by any C reconstruction
   technique: it needs tools/slus21782_functions.json to gain two more
   function-table entries (0x3ca780 size 28, 0x3ca7a0 size 140) so each
   trampoline can be scored on its own. That is a ground-truth data change
   outside the scope of a single reconstruction attempt.

   The individual C bodies below ARE correct (byte-exact modulo the
   optimization_level 4 tail-call fold already applied) and can be dropped
   in once the window table is corrected. */
#pragma optimization_level 4
s32 func_003ca740(s32 arg0)
{
    u8 *p;

    p = D_008872E0 + arg0;
    *(u32 *)D_008872E4 = *(u32 *)(p + 12);
    D_008872E8[0] += 1;
    return ((s32 (*)(void))*(void **)(p + 16))();
}

s32 func_003ca780(s32 arg0)
{
    u8 *p;

    *(u32 *)D_008872E4 = 0;
    p = D_008872E0 + arg0;
    return ((s32 (*)(void))*(void **)(p + 20))();
}

extern s32 func_003cb300(u8 *arg0, s32 arg1);
extern s32 (*D_00887380)(s32, s32, s32);

s32 func_003ca7a0(s32 arg0)
{
    u8 *p;
    u8 *field_c;
    s32 v0;

    p = D_008872E0 + arg0;
    v0 = ((s32 (*)(void))*(void **)(p + 24))();
    if (v0 == 0) {
        return 0;
    }
    field_c = *(u8 **)(p + 12);
    if (field_c == NULL) {
        return arg0;
    }
    func_003cb300(field_c, arg0);
    v0 = *(s32 *)(field_c + 12);
    D_00887380(0, 0, (u32)(v0 ^ 1) < 1);
    return arg0;
}
#pragma optimization_level 2
