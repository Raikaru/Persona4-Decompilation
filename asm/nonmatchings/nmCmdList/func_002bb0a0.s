.section .text
.set noat
.set noreorder
glabel func_002bb0a0
    /* 1BB0A0 002BB0A0 3C1E0400 */  dsll32     $3, $4, 24
    /* 1BB0A4 002BB0A4 3F1E0300 */  dsra32     $3, $3, 24
    /* 1BB0A8 002BB0A8 80200300 */  sll        $4, $3, 2
    /* 1BB0AC 002BB0AC 8800033C */  lui        $3, %hi(D_00882F40)
    /* 1BB0B0 002BB0B0 402F6324 */  addiu      $3, $3, %lo(D_00882F40)
    /* 1BB0B4 002BB0B4 21186400 */  addu       $3, $3, $4
    /* 1BB0B8 002BB0B8 0000648C */  lw         $4, 0x0($3)
    /* 1BB0BC 002BB0BC 05008010 */  beqz       $4, .L002BB0D4
    /* 1BB0C0 002BB0C0 00000000 */   nop
    /* 1BB0C4 002BB0C4 0000838C */  lw         $3, 0x0($4)
    /* 1BB0C8 002BB0C8 02006004 */  bltz       $3, .L002BB0D4
    /* 1BB0CC 002BB0CC 00000000 */   nop
    /* 1BB0D0 002BB0D0 0C0085A0 */  sb         $5, 0xC($4)
  .L002BB0D4:
    /* 1BB0D4 002BB0D4 0800E003 */  jr         $31
    /* 1BB0D8 002BB0D8 00000000 */   nop
    /* 1BB0DC 002BB0DC 00000000 */  nop
.size func_002bb0a0, 0x40
