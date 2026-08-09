.section .text
.set noat
.set noreorder
glabel func_004ecb08
    /* 3ECB08 004ECB08 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ECB0C 004ECB0C 01000424 */  addiu      $4, $0, 0x1
    /* 3ECB10 004ECB10 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ECB14 004ECB14 05006414 */  bne        $3, $4, .L004ECB2C
    /* 3ECB18 004ECB18 80BB0234 */   ori       $2, $0, 0xBB80
    /* 3ECB1C 004ECB1C 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3ECB20 004ECB20 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3ECB24 004ECB24 03006018 */  blez       $3, .L004ECB34
    /* 3ECB28 004ECB28 80BB0234 */   ori       $2, $0, 0xBB80
  .L004ECB2C:
    /* 3ECB2C 004ECB2C 0000A0AC */  sw         $0, 0x0($5)
    /* 3ECB30 004ECB30 0000C2AC */  sw         $2, 0x0($6)
  .L004ECB34:
    /* 3ECB34 004ECB34 0800E003 */  jr         $31
    /* 3ECB38 004ECB38 00000000 */   nop
    /* 3ECB3C 004ECB3C 00000000 */  nop
.size func_004ecb08, 0x38
