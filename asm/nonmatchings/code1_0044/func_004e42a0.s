.section .text
.set noat
.set noreorder
glabel func_004e42a0
    /* 3E42A0 004E42A0 7300023C */  lui        $2, %hi(D_00731C50)
    /* 3E42A4 004E42A4 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E42A8 004E42A8 501C4224 */  addiu      $2, $2, %lo(D_00731C50)
    /* 3E42AC 004E42AC 0000BFFF */  sd         $31, 0x0($29)
    /* 3E42B0 004E42B0 000040AC */  sw         $0, 0x0($2)
    /* 3E42B4 004E42B4 7300083C */  lui        $8, %hi(D_00731C3C)
    /* 3E42B8 004E42B8 01000724 */  addiu      $7, $0, 0x1
    /* 3E42BC 004E42BC 2D284000 */  daddu      $5, $2, $0
    /* 3E42C0 004E42C0 6419063C */  lui        $6, (0x19640000 >> 16)
    /* 3E42C4 004E42C4 7600043C */  lui        $4, %hi(D_0075ABC8)
    /* 3E42C8 004E42C8 3C1C028D */  lw         $2, %lo(D_00731C3C)($8)
    /* 3E42CC 004E42CC 00000000 */  nop
  .L004E42D0:
    /* 3E42D0 004E42D0 0B004714 */  bne        $2, $7, .L004E4300
    /* 3E42D4 004E42D4 0000BFDF */   ld        $31, 0x0($29)
    /* 3E42D8 004E42D8 0000A28C */  lw         $2, 0x0($5)
    /* 3E42DC 004E42DC 01004224 */  addiu      $2, $2, 0x1
    /* 3E42E0 004E42E0 0000A2AC */  sw         $2, 0x0($5)
    /* 3E42E4 004E42E4 0000A38C */  lw         $3, 0x0($5)
    /* 3E42E8 004E42E8 2B18C300 */  sltu       $3, $6, $3
    /* 3E42EC 004E42EC F8FF6050 */  beql       $3, $0, .L004E42D0
    /* 3E42F0 004E42F0 3C1C028D */   lw        $2, %lo(D_00731C3C)($8)
    /* 3E42F4 004E42F4 3291100C */  jal        func_004244c8
    /* 3E42F8 004E42F8 C8AB8424 */   addiu     $4, $4, %lo(D_0075ABC8)
    /* 3E42FC 004E42FC 0000BFDF */  ld         $31, 0x0($29)
  .L004E4300:
    /* 3E4300 004E4300 0800E003 */  jr         $31
    /* 3E4304 004E4304 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e42a0, 0x68
