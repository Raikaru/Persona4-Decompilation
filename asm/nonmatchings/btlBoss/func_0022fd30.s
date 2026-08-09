.section .text
.set noat
.set noreorder
glabel func_0022fd30
    /* 12FD30 0022FD30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 12FD34 0022FD34 0000BFFF */  sd         $31, 0x0($29)
    /* 12FD38 0022FD38 ACB3828F */  lw         $2, -0x4C54($28)
    /* 12FD3C 0022FD3C 0C00438C */  lw         $3, 0xC($2)
    /* 12FD40 0022FD40 2000023C */  lui        $2, (0x200000 >> 16)
    /* 12FD44 0022FD44 24106200 */  and        $2, $3, $2
    /* 12FD48 0022FD48 04004014 */  bnez       $2, .L0022FD5C
    /* 12FD4C 0022FD4C 00000000 */   nop
    /* 12FD50 0022FD50 01000224 */  addiu      $2, $0, 0x1
    /* 12FD54 0022FD54 13000010 */  b          .L0022FDA4
    /* 12FD58 0022FD58 00000000 */   nop
  .L0022FD5C:
    /* 12FD5C 0022FD5C 1A008294 */  lhu        $2, 0x1A($4)
    /* 12FD60 0022FD60 01004230 */  andi       $2, $2, 0x1
    /* 12FD64 0022FD64 04004014 */  bnez       $2, .L0022FD78
    /* 12FD68 0022FD68 00000000 */   nop
    /* 12FD6C 0022FD6C 01000224 */  addiu      $2, $0, 0x1
    /* 12FD70 0022FD70 0C000010 */  b          .L0022FDA4
    /* 12FD74 0022FD74 00000000 */   nop
  .L0022FD78:
    /* 12FD78 0022FD78 3000828C */  lw         $2, 0x30($4)
    /* 12FD7C 0022FD7C A2004390 */  lbu        $3, 0xA2($2)
    /* 12FD80 0022FD80 01000224 */  addiu      $2, $0, 0x1
    /* 12FD84 0022FD84 03006210 */  beq        $3, $2, .L0022FD94
    /* 12FD88 0022FD88 00000000 */   nop
    /* 12FD8C 0022FD8C 05000010 */  b          .L0022FDA4
    /* 12FD90 0022FD90 00000000 */   nop
  .L0022FD94:
    /* 12FD94 0022FD94 1C7F060C */  jal        func_0019fc70
    /* 12FD98 0022FD98 00000000 */   nop
    /* 12FD9C 0022FD9C 2B100200 */  sltu       $2, $0, $2
    /* 12FDA0 0022FDA0 01004238 */  xori       $2, $2, 0x1
  .L0022FDA4:
    /* 12FDA4 0022FDA4 0000BFDF */  ld         $31, 0x0($29)
    /* 12FDA8 0022FDA8 1000BD27 */  addiu      $29, $29, 0x10
    /* 12FDAC 0022FDAC 0800E003 */  jr         $31
    /* 12FDB0 0022FDB0 00000000 */   nop
    /* 12FDB4 0022FDB4 00000000 */  nop
    /* 12FDB8 0022FDB8 00000000 */  nop
    /* 12FDBC 0022FDBC 00000000 */  nop
.size func_0022fd30, 0x90
