#include "include_asm.h"
/* Persona 4 USA decompilation - btlPanelCursor.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

/* measured: case-3/4 switch bodies are laid out 8-28 bytes earlier than retail
   because mwcc b210 drops the redundant else-if(v4>=0xB) guard that retail keeps
   (arg1[0x14]=8 / arg1[0x10]&=0xFFEF), and keeps the case-4 tail inline instead of
   out-of-line after the switch (nd 294). The mula/msub f20=2*f1-f1*f1, u16 bltz
   srl+add.s doubling, 0xE0 frame, and overflow guard all match. Tried else-if and
   separate-if spellings, goto to a shared tail, and declaration orders. */
// FUN_0020BFF0
INCLUDE_ASM("asm/nonmatchings/btlPanelCursor", func_0020bff0);

/* measured: same case-4-tail + else-if guard placement floor as func_0020bff0 —
   retail puts the tail (arg1[8]=arg3[0];arg1[0xC]=arg3[1]) out-of-line after the
   switch and keeps the redundant else-if(v4>=0xB) guard; mwcc b210 inlines both,
   shifting every case branch target (nd 368). The FPU MAC chain
   (adda.s f20 / msuba.s 2*f2 / madd.s f2*f2 -> arg1[0x1A]=360*(f20-2f2+f2^2))
   and the 0xE0 frame match. Tried the standard spellings. */
// FUN_0020C680
INCLUDE_ASM("asm/nonmatchings/btlPanelCursor", func_0020c680);

/* measured: same case-4 switch-body floor as func_0020bff0/func_0020c680 — mwcc
   b210 positions the case-3/4 bodies earlier than retail (drops redundant
   else-if guards, inlines the case-4 tail) and allocates the 1.0f scale into a
   fresh register instead of reusing the saved f23 (nd 398). Also has a second
   switch in case 4 (arg1[0x18] easing via adda.s/msub.s) and the func_00364c90
   ring block. The 0xE0 frame matches. */
// FUN_0020CE60
INCLUDE_ASM("asm/nonmatchings/btlPanelCursor", func_0020ce60);

/* measured: same case-4 switch-body floor as the other three functions, plus
   this variant's ring loop (madd.s chains) and func_00201720 calls do not
   converge (nd 475). mwcc b210 keeps the case-4 tail inline and drops the
   redundant else-if guards, so case branch targets shift. The 0xF0 frame
   matches. */
// FUN_0020D6A0
INCLUDE_ASM("asm/nonmatchings/btlPanelCursor", func_0020d6a0);
