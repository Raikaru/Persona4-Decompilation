/* object 448B vs window 448B, normalized_diff 0 (ASM), differing offsets none; classification confirmed movz conditional-move compiler floor; ruled out plain-C probing because retail executes `movz $s0,$zero,$v0` after func_003d7490. */
/* Retail evidence: conditional move at the post-003d7490 return path; b210 emits a branch for equivalent C conditionals. */
