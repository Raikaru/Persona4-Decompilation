.section .text
.set noat
.set noreorder
glabel func_0039b4b0
    /* 29B4B0 0039B4B0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 29B4B4 0039B4B4 8800033C */  lui        $3, %hi(D_00884AC8)
    /* 29B4B8 0039B4B8 1000BFFF */  sd         $31, 0x10($29)
    /* 29B4BC 0039B4BC 8800023C */  lui        $2, %hi(D_00884AC8)
    /* 29B4C0 0039B4C0 0000B07F */  sq         $16, 0x0($29)
    /* 29B4C4 0039B4C4 C84A638C */  lw         $3, %lo(D_00884AC8)($3)
    /* 29B4C8 0039B4C8 2D808000 */  daddu      $16, $4, $0
    /* 29B4CC 0039B4CC FFFF6324 */  addiu      $3, $3, -0x1
    /* 29B4D0 0039B4D0 03006010 */  beqz       $3, .L0039B4E0
    /* 29B4D4 0039B4D4 C84A43AC */   sw        $3, %lo(D_00884AC8)($2)
  .L0039B4D8:
    /* 29B4D8 0039B4D8 06000010 */  b          .L0039B4F4
    /* 29B4DC 0039B4DC 2D100002 */   daddu     $2, $16, $0
  .L0039B4E0:
    /* 29B4E0 0039B4E0 8800043C */  lui        $4, %hi(D_00884ACC)
    /* 29B4E4 0039B4E4 0C6E0E0C */  jal        func_0039b830
    /* 29B4E8 0039B4E8 CC4A8424 */   addiu     $4, $4, %lo(D_00884ACC)
    /* 29B4EC 0039B4EC FAFF0010 */  b          .L0039B4D8
    /* 29B4F0 0039B4F0 00000000 */   nop
  .L0039B4F4:
    /* 29B4F4 0039B4F4 1000BFDF */  ld         $31, 0x10($29)
    /* 29B4F8 0039B4F8 0000B07B */  lq         $16, 0x0($29)
    /* 29B4FC 0039B4FC 0800E003 */  jr         $31
    /* 29B500 0039B500 2000BD27 */   addiu     $29, $29, 0x20
    /* 29B504 0039B504 00000000 */  nop
    /* 29B508 0039B508 00000000 */  nop
    /* 29B50C 0039B50C 00000000 */  nop
.size func_0039b4b0, 0x60
