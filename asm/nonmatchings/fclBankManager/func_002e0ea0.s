.section .text
.set noat
.set noreorder
glabel func_002e0ea0
    /* 1E0EA0 002E0EA0 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 1E0EA4 002E0EA4 0000BFFF */  sd         $31, 0x0($29)
    /* 1E0EA8 002E0EA8 1800A4AF */  sw         $4, 0x18($29)
    /* 1E0EAC 002E0EAC 2800A5FF */  sd         $5, 0x28($29)
    /* 1E0EB0 002E0EB0 3000A6FF */  sd         $6, 0x30($29)
    /* 1E0EB4 002E0EB4 3800A7FF */  sd         $7, 0x38($29)
    /* 1E0EB8 002E0EB8 4000A8FF */  sd         $8, 0x40($29)
    /* 1E0EBC 002E0EBC 4800A9FF */  sd         $9, 0x48($29)
    /* 1E0EC0 002E0EC0 5000AAFF */  sd         $10, 0x50($29)
    /* 1E0EC4 002E0EC4 5800ABFF */  sd         $11, 0x58($29)
    /* 1E0EC8 002E0EC8 01000324 */  addiu      $3, $0, 0x1
    /* 1E0ECC 002E0ECC 08006228 */  slti       $2, $3, 0x8
    /* 1E0ED0 002E0ED0 04004014 */  bnez       $2, .L002E0EE4
    /* 1E0ED4 002E0ED4 00000000 */   nop
    /* 1E0ED8 002E0ED8 2D180000 */  daddu      $3, $0, $0
    /* 1E0EDC 002E0EDC 04000010 */  b          .L002E0EF0
    /* 1E0EE0 002E0EE0 00000000 */   nop
  .L002E0EE4:
    /* 1E0EE4 002E0EE4 08000224 */  addiu      $2, $0, 0x8
    /* 1E0EE8 002E0EE8 23104300 */  subu       $2, $2, $3
    /* 1E0EEC 002E0EEC C0180200 */  sll        $3, $2, 3
  .L002E0EF0:
    /* 1E0EF0 002E0EF0 6000A227 */  addiu      $2, $29, 0x60
    /* 1E0EF4 002E0EF4 23284300 */  subu       $5, $2, $3
    /* 1E0EF8 002E0EF8 1800A48F */  lw         $4, 0x18($29)
    /* 1E0EFC 002E0EFC A21B110C */  jal        func_00446e88
    /* 1E0F00 002E0F00 00000000 */   nop
    /* 1E0F04 002E0F04 0000BFDF */  ld         $31, 0x0($29)
    /* 1E0F08 002E0F08 6000BD27 */  addiu      $29, $29, 0x60
    /* 1E0F0C 002E0F0C 0800E003 */  jr         $31
    /* 1E0F10 002E0F10 00000000 */   nop
    /* 1E0F14 002E0F14 00000000 */  nop
    /* 1E0F18 002E0F18 00000000 */  nop
    /* 1E0F1C 002E0F1C 00000000 */  nop
.size func_002e0ea0, 0x80
