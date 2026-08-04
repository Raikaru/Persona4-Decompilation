.section .text
.set noat
.set noreorder
glabel func_003cc0d0
    /* 2CC0D0 003CC0D0 08008010 */  beqz       $4, .L003CC0F4
    /* 2CC0D4 003CC0D4 00000000 */   nop
  .L003CC0D8:
    /* 2CC0D8 003CC0D8 B8B9858F */  lw         $5, -0x4648($28)
  .L003CC0DC:
    /* 2CC0DC 003CC0DC 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2CC0E0 003CC0E0 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2CC0E4 003CC0E4 2D108000 */  daddu      $2, $4, $0
    /* 2CC0E8 003CC0E8 21186500 */  addu       $3, $3, $5
    /* 2CC0EC 003CC0EC 0C000010 */  b          .L003CC120
    /* 2CC0F0 003CC0F0 440064AC */   sw        $4, 0x44($3)
  .L003CC0F4:
    /* 2CC0F4 003CC0F4 B8B9838F */  lw         $3, -0x4648($28)
    /* 2CC0F8 003CC0F8 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2CC0FC 003CC0FC E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2CC100 003CC100 21104300 */  addu       $2, $2, $3
    /* 2CC104 003CC104 5C00448C */  lw         $4, 0x5C($2)
    /* 2CC108 003CC108 03008010 */  beqz       $4, .L003CC118
    /* 2CC10C 003CC10C 00000000 */   nop
    /* 2CC110 003CC110 F2FF0010 */  b          .L003CC0DC
    /* 2CC114 003CC114 B8B9858F */   lw        $5, -0x4648($28)
  .L003CC118:
    /* 2CC118 003CC118 EFFF0010 */  b          .L003CC0D8
    /* 2CC11C 003CC11C 2D200000 */   daddu     $4, $0, $0
  .L003CC120:
    /* 2CC120 003CC120 0800E003 */  jr         $31
    /* 2CC124 003CC124 00000000 */   nop
    /* 2CC128 003CC128 00000000 */  nop
    /* 2CC12C 003CC12C 00000000 */  nop
.size func_003cc0d0, 0x60
