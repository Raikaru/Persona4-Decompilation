.section .text
.set noat
.set noreorder
glabel func_003efd20
    /* 2EFD20 003EFD20 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2EFD24 003EFD24 0000BFFF */  sd         $31, 0x0($29)
    /* 2EFD28 003EFD28 0400838C */  lw         $3, 0x4($4)
    /* 2EFD2C 003EFD2C 0F006014 */  bnez       $3, .L003EFD6C
    /* 2EFD30 003EFD30 00000000 */   nop
  .L003EFD34:
    /* 2EFD34 003EFD34 1400A010 */  beqz       $5, .L003EFD88
    /* 2EFD38 003EFD38 040085AC */   sw        $5, 0x4($4)
    /* 2EFD3C 003EFD3C 9000A68C */  lw         $6, 0x90($5)
    /* 2EFD40 003EFD40 9000A224 */  addiu      $2, $5, 0x90
    /* 2EFD44 003EFD44 08008324 */  addiu      $3, $4, 0x8
    /* 2EFD48 003EFD48 080086AC */  sw         $6, 0x8($4)
    /* 2EFD4C 003EFD4C 0C0082AC */  sw         $2, 0xC($4)
    /* 2EFD50 003EFD50 9000A28C */  lw         $2, 0x90($5)
    /* 2EFD54 003EFD54 2D20A000 */  daddu      $4, $5, $0
    /* 2EFD58 003EFD58 040043AC */  sw         $3, 0x4($2)
    /* 2EFD5C 003EFD5C A0A50F0C */  jal        func_003e9680
    /* 2EFD60 003EFD60 9000A3AC */   sw        $3, 0x90($5)
    /* 2EFD64 003EFD64 09000010 */  b          .L003EFD8C
    /* 2EFD68 003EFD68 0000BFDF */   ld        $31, 0x0($29)
  .L003EFD6C:
    /* 2EFD6C 003EFD6C 0800868C */  lw         $6, 0x8($4)
    /* 2EFD70 003EFD70 0C00838C */  lw         $3, 0xC($4)
    /* 2EFD74 003EFD74 000066AC */  sw         $6, 0x0($3)
    /* 2EFD78 003EFD78 0C00868C */  lw         $6, 0xC($4)
    /* 2EFD7C 003EFD7C 0800838C */  lw         $3, 0x8($4)
    /* 2EFD80 003EFD80 ECFF0010 */  b          .L003EFD34
    /* 2EFD84 003EFD84 040066AC */   sw        $6, 0x4($3)
  .L003EFD88:
    /* 2EFD88 003EFD88 0000BFDF */  ld         $31, 0x0($29)
  .L003EFD8C:
    /* 2EFD8C 003EFD8C 0800E003 */  jr         $31
    /* 2EFD90 003EFD90 1000BD27 */   addiu     $29, $29, 0x10
    /* 2EFD94 003EFD94 00000000 */  nop
    /* 2EFD98 003EFD98 00000000 */  nop
    /* 2EFD9C 003EFD9C 00000000 */  nop
.size func_003efd20, 0x80
