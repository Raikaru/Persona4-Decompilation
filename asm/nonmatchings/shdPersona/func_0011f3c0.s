.section .text
.set noat
.set noreorder
glabel func_0011f3c0
    /* 1F3C0 0011F3C0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1F3C4 0011F3C4 1000BFFF */  sd         $31, 0x10($29)
    /* 1F3C8 0011F3C8 0000B07F */  sq         $16, 0x0($29)
    /* 1F3CC 0011F3CC 3800908C */  lw         $16, 0x38($4)
    /* 1F3D0 0011F3D0 1800048E */  lw         $4, 0x18($16)
    /* 1F3D4 0011F3D4 04008010 */  beqz       $4, .L0011F3E8
    /* 1F3D8 0011F3D8 00000000 */   nop
    /* 1F3DC 0011F3DC 447F040C */  jal        func_0011fd10
    /* 1F3E0 0011F3E0 00000000 */   nop
    /* 1F3E4 0011F3E4 180000AE */  sw         $0, 0x18($16)
  .L0011F3E8:
    /* 1F3E8 0011F3E8 2D200002 */  daddu      $4, $16, $0
    /* 1F3EC 0011F3EC 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 1F3F0 0011F3F0 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 1F3F4 0011F3F4 09F84000 */  jalr       $2
    /* 1F3F8 0011F3F8 00000000 */   nop
    /* 1F3FC 0011F3FC 1000BFDF */  ld         $31, 0x10($29)
    /* 1F400 0011F400 0000B07B */  lq         $16, 0x0($29)
    /* 1F404 0011F404 2000BD27 */  addiu      $29, $29, 0x20
    /* 1F408 0011F408 0800E003 */  jr         $31
    /* 1F40C 0011F40C 00000000 */   nop
.size func_0011f3c0, 0x50
