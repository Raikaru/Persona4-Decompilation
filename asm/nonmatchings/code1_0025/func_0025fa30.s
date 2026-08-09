.section .text
.set noat
.set noreorder
glabel func_0025fa30
    /* 15FA30 0025FA30 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 15FA34 0025FA34 1000BFFF */  sd         $31, 0x10($29)
    /* 15FA38 0025FA38 0000B07F */  sq         $16, 0x0($29)
    /* 15FA3C 0025FA3C 5849110C */  jal        func_00452560
    /* 15FA40 0025FA40 00000000 */   nop
    /* 15FA44 0025FA44 2D804000 */  daddu      $16, $2, $0
    /* 15FA48 0025FA48 0000438C */  lw         $3, 0x0($2)
    /* 15FA4C 0025FA4C 01000224 */  addiu      $2, $0, 0x1
    /* 15FA50 0025FA50 0A006210 */  beq        $3, $2, .L0025FA7C
    /* 15FA54 0025FA54 00000000 */   nop
    /* 15FA58 0025FA58 03006010 */  beqz       $3, .L0025FA68
    /* 15FA5C 0025FA5C 00000000 */   nop
    /* 15FA60 0025FA60 09000010 */  b          .L0025FA88
    /* 15FA64 0025FA64 00000000 */   nop
  .L0025FA68:
    /* 15FA68 0025FA68 0400048E */  lw         $4, 0x4($16)
    /* 15FA6C 0025FA6C A0AD120C */  jal        func_004ab680
    /* 15FA70 0025FA70 00000000 */   nop
    /* 15FA74 0025FA74 04000010 */  b          .L0025FA88
    /* 15FA78 0025FA78 00000000 */   nop
  .L0025FA7C:
    /* 15FA7C 0025FA7C 0400048E */  lw         $4, 0x4($16)
    /* 15FA80 0025FA80 50AC120C */  jal        func_004ab140
    /* 15FA84 0025FA84 00000000 */   nop
  .L0025FA88:
    /* 15FA88 0025FA88 2D200002 */  daddu      $4, $16, $0
    /* 15FA8C 0025FA8C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 15FA90 0025FA90 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 15FA94 0025FA94 09F84000 */  jalr       $2
    /* 15FA98 0025FA98 00000000 */   nop
    /* 15FA9C 0025FA9C 1000BFDF */  ld         $31, 0x10($29)
    /* 15FAA0 0025FAA0 0000B07B */  lq         $16, 0x0($29)
    /* 15FAA4 0025FAA4 2000BD27 */  addiu      $29, $29, 0x20
    /* 15FAA8 0025FAA8 0800E003 */  jr         $31
    /* 15FAAC 0025FAAC 00000000 */   nop
.size func_0025fa30, 0x80
