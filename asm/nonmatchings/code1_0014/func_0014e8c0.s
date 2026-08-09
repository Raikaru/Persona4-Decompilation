.section .text
.set noat
.set noreorder
glabel func_0014e8c0
    /* 4E8C0 0014E8C0 3800838C */  lw         $3, 0x38($4)
    /* 4E8C4 0014E8C4 0600A004 */  bltz       $5, .L0014E8E0
    /* 4E8C8 0014E8C8 00000000 */   nop
    /* 4E8CC 0014E8CC 80100500 */  sll        $2, $5, 2
    /* 4E8D0 0014E8D0 21104300 */  addu       $2, $2, $3
    /* 4E8D4 0014E8D4 4400428C */  lw         $2, 0x44($2)
    /* 4E8D8 0014E8D8 02000010 */  b          .L0014E8E4
    /* 4E8DC 0014E8DC 00000000 */   nop
  .L0014E8E0:
    /* 4E8E0 0014E8E0 1800628C */  lw         $2, 0x18($3)
  .L0014E8E4:
    /* 4E8E4 0014E8E4 0800E003 */  jr         $31
    /* 4E8E8 0014E8E8 00000000 */   nop
    /* 4E8EC 0014E8EC 00000000 */  nop
.size func_0014e8c0, 0x30
