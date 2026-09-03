/* func_003b7ca0 best body (Main + lane TRnd, 2026-09-03): object 352B / window 352B, nd 2 (reloc-masked).
   Residual: retail emits `lbu v0,(s1)` before `sll t0,t0,0x10` in the sp4C block; b210 swaps the two.
   Pre-schedule order is identical for every OR association / byte-first / temp spelling tried (16
   variants), and peephole/common_subs/propagation/loop_invariants pragmas do not move it. Scheduler
   tie-break floor. */
