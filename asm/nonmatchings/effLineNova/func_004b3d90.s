.section .text
.set noat
.set noreorder
glabel func_004b3d90
    /* 3B3D90 004B3D90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3B3D94 004B3D94 1000BFFF */  sd         $31, 0x10($29)
    /* 3B3D98 004B3D98 0000B07F */  sq         $16, 0x0($29)
    /* 3B3D9C 004B3D9C 2400868C */  lw         $6, 0x24($4)
    /* 3B3DA0 004B3DA0 2000838C */  lw         $3, 0x20($4)
    /* 3B3DA4 004B3DA4 0400708C */  lw         $16, 0x4($3)
    /* 3B3DA8 004B3DA8 3400C58C */  lw         $5, 0x34($6)
    /* 3B3DAC 004B3DAC 1400838C */  lw         $3, 0x14($4)
    /* 3B3DB0 004B3DB0 2B08A300 */  sltu       $1, $5, $3
    /* 3B3DB4 004B3DB4 03002010 */  beqz       $1, .L004B3DC4
    /* 3B3DB8 004B3DB8 00000000 */   nop
    /* 3B3DBC 004B3DBC 1A00A014 */  bnez       $5, .L004B3E28
    /* 3B3DC0 004B3DC0 00000000 */   nop
  .L004B3DC4:
    /* 3B3DC4 004B3DC4 6800C290 */  lbu        $2, 0x68($6)
    /* 3B3DC8 004B3DC8 03004010 */  beqz       $2, .L004B3DD8
    /* 3B3DCC 004B3DCC 00000000 */   nop
    /* 3B3DD0 004B3DD0 0C000010 */  b          .L004B3E04
    /* 3B3DD4 004B3DD4 00000000 */   nop
  .L004B3DD8:
    /* 3B3DD8 004B3DD8 2800C494 */  lhu        $4, 0x28($6)
    /* 3B3DDC 004B3DDC 5005120C */  jal        func_00481540
    /* 3B3DE0 004B3DE0 00000000 */   nop
    /* 3B3DE4 004B3DE4 180000AE */  sw         $0, 0x18($16)
    /* 3B3DE8 004B3DE8 1C0000AE */  sw         $0, 0x1C($16)
    /* 3B3DEC 004B3DEC 2D204000 */  daddu      $4, $2, $0
    /* 3B3DF0 004B3DF0 18000526 */  addiu      $5, $16, 0x18
    /* 3B3DF4 004B3DF4 B082110C */  jal        func_00460ac0
    /* 3B3DF8 004B3DF8 00000000 */   nop
    /* 3B3DFC 004B3DFC 0A000010 */  b          .L004B3E28
    /* 3B3E00 004B3E00 00000000 */   nop
  .L004B3E04:
    /* 3B3E04 004B3E04 2800C494 */  lhu        $4, 0x28($6)
    /* 3B3E08 004B3E08 1805120C */  jal        func_00481460
    /* 3B3E0C 004B3E0C 00000000 */   nop
    /* 3B3E10 004B3E10 180000AE */  sw         $0, 0x18($16)
    /* 3B3E14 004B3E14 1C0000AE */  sw         $0, 0x1C($16)
    /* 3B3E18 004B3E18 2D204000 */  daddu      $4, $2, $0
    /* 3B3E1C 004B3E1C 18000526 */  addiu      $5, $16, 0x18
    /* 3B3E20 004B3E20 B082110C */  jal        func_00460ac0
    /* 3B3E24 004B3E24 00000000 */   nop
  .L004B3E28:
    /* 3B3E28 004B3E28 1000BFDF */  ld         $31, 0x10($29)
    /* 3B3E2C 004B3E2C 0000B07B */  lq         $16, 0x0($29)
    /* 3B3E30 004B3E30 2000BD27 */  addiu      $29, $29, 0x20
    /* 3B3E34 004B3E34 0800E003 */  jr         $31
    /* 3B3E38 004B3E38 00000000 */   nop
    /* 3B3E3C 004B3E3C 00000000 */  nop
.size func_004b3d90, 0xb0
