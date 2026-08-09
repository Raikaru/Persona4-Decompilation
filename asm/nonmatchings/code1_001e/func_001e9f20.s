.section .text
.set noat
.set noreorder
glabel func_001e9f20
    /* E9F20 001E9F20 B0FFBD27 */  addiu      $29, $29, -0x50
    /* E9F24 001E9F24 4000BFFF */  sd         $31, 0x40($29)
    /* E9F28 001E9F28 3000B37F */  sq         $19, 0x30($29)
    /* E9F2C 001E9F2C 2000B27F */  sq         $18, 0x20($29)
    /* E9F30 001E9F30 1000B17F */  sq         $17, 0x10($29)
    /* E9F34 001E9F34 0000B07F */  sq         $16, 0x0($29)
    /* E9F38 001E9F38 2D200000 */  daddu      $4, $0, $0
    /* E9F3C 001E9F3C 00730A0C */  jal        func_0029cc00
    /* E9F40 001E9F40 00000000 */   nop
    /* E9F44 001E9F44 2D804000 */  daddu      $16, $2, $0
    /* E9F48 001E9F48 2D900000 */  daddu      $18, $0, $0
    /* E9F4C 001E9F4C 2D880000 */  daddu      $17, $0, $0
    /* E9F50 001E9F50 ACB3828F */  lw         $2, -0x4C54($28)
    /* E9F54 001E9F54 7401538C */  lw         $19, 0x174($2)
    /* E9F58 001E9F58 25000010 */  b          .L001E9FF0
    /* E9F5C 001E9F5C 00000000 */   nop
  .L001E9F60:
    /* E9F60 001E9F60 1A006396 */  lhu        $3, 0x1A($19)
    /* E9F64 001E9F64 01006230 */  andi       $2, $3, 0x1
    /* E9F68 001E9F68 20004010 */  beqz       $2, .L001E9FEC
    /* E9F6C 001E9F6C 00000000 */   nop
    /* E9F70 001E9F70 08006230 */  andi       $2, $3, 0x8
    /* E9F74 001E9F74 1D004010 */  beqz       $2, .L001E9FEC
    /* E9F78 001E9F78 00000000 */   nop
    /* E9F7C 001E9F7C 3000648E */  lw         $4, 0x30($19)
    /* E9F80 001E9F80 A2008390 */  lbu        $3, 0xA2($4)
    /* E9F84 001E9F84 01000224 */  addiu      $2, $0, 0x1
    /* E9F88 001E9F88 18006214 */  bne        $3, $2, .L001E9FEC
    /* E9F8C 001E9F8C 00000000 */   nop
    /* E9F90 001E9F90 640A848C */  lw         $4, 0xA64($4)
    /* E9F94 001E9F94 2D280002 */  daddu      $5, $16, $0
    /* E9F98 001E9F98 C4C9080C */  jal        func_00232710
    /* E9F9C 001E9F9C 00000000 */   nop
    /* E9FA0 001E9FA0 12004010 */  beqz       $2, .L001E9FEC
    /* E9FA4 001E9FA4 00000000 */   nop
    /* E9FA8 001E9FA8 3000628E */  lw         $2, 0x30($19)
    /* E9FAC 001E9FAC 640A448C */  lw         $4, 0xA64($2)
    /* E9FB0 001E9FB0 2D280000 */  daddu      $5, $0, $0
    /* E9FB4 001E9FB4 3C0A090C */  jal        func_002428f0
    /* E9FB8 001E9FB8 00000000 */   nop
    /* E9FBC 001E9FBC 0B004014 */  bnez       $2, .L001E9FEC
    /* E9FC0 001E9FC0 00000000 */   nop
    /* E9FC4 001E9FC4 3000628E */  lw         $2, 0x30($19)
    /* E9FC8 001E9FC8 640A448C */  lw         $4, 0xA64($2)
    /* E9FCC 001E9FCC B4C7080C */  jal        func_00231ed0
    /* E9FD0 001E9FD0 00000000 */   nop
    /* E9FD4 001E9FD4 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* E9FD8 001E9FD8 2B082202 */  sltu       $1, $17, $2
    /* E9FDC 001E9FDC 03002010 */  beqz       $1, .L001E9FEC
    /* E9FE0 001E9FE0 00000000 */   nop
    /* E9FE4 001E9FE4 2D906002 */  daddu      $18, $19, $0
    /* E9FE8 001E9FE8 2D884000 */  daddu      $17, $2, $0
  .L001E9FEC:
    /* E9FEC 001E9FEC 5004738E */  lw         $19, 0x450($19)
  .L001E9FF0:
    /* E9FF0 001E9FF0 DBFF6016 */  bnez       $19, .L001E9F60
    /* E9FF4 001E9FF4 00000000 */   nop
    /* E9FF8 001E9FF8 08004012 */  beqz       $18, .L001EA01C
    /* E9FFC 001E9FFC 00000000 */   nop
    /* EA000 001EA000 0800438E */  lw         $3, 0x8($18)
    /* EA004 001EA004 0080023C */  lui        $2, (0x80000000 >> 16)
    /* EA008 001EA008 25206200 */  or         $4, $3, $2
    /* EA00C 001EA00C D4730A0C */  jal        func_0029cf50
    /* EA010 001EA010 00000000 */   nop
    /* EA014 001EA014 04000010 */  b          .L001EA028
    /* EA018 001EA018 00000000 */   nop
  .L001EA01C:
    /* EA01C 001EA01C FFFF0424 */  addiu      $4, $0, -0x1
    /* EA020 001EA020 D4730A0C */  jal        func_0029cf50
    /* EA024 001EA024 00000000 */   nop
  .L001EA028:
    /* EA028 001EA028 01000224 */  addiu      $2, $0, 0x1
    /* EA02C 001EA02C 4000BFDF */  ld         $31, 0x40($29)
    /* EA030 001EA030 3000B37B */  lq         $19, 0x30($29)
    /* EA034 001EA034 2000B27B */  lq         $18, 0x20($29)
    /* EA038 001EA038 1000B17B */  lq         $17, 0x10($29)
    /* EA03C 001EA03C 0000B07B */  lq         $16, 0x0($29)
    /* EA040 001EA040 5000BD27 */  addiu      $29, $29, 0x50
    /* EA044 001EA044 0800E003 */  jr         $31
    /* EA048 001EA048 00000000 */   nop
    /* EA04C 001EA04C 00000000 */  nop
.size func_001e9f20, 0x130
