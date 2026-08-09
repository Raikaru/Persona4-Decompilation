.section .text
.set noat
.set noreorder
glabel func_004ecee8
    /* 3ECEE8 004ECEE8 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ECEEC 004ECEEC E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3ECEF0 004ECEF0 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ECEF4 004ECEF4 01000624 */  addiu      $6, $0, 0x1
    /* 3ECEF8 004ECEF8 0000B0FF */  sd         $16, 0x0($29)
    /* 3ECEFC 004ECEFC 2D80A000 */  daddu      $16, $5, $0
    /* 3ECF00 004ECF00 0800B1FF */  sd         $17, 0x8($29)
    /* 3ECF04 004ECF04 2D888000 */  daddu      $17, $4, $0
    /* 3ECF08 004ECF08 05006614 */  bne        $3, $6, .L004ECF20
    /* 3ECF0C 004ECF0C 1000BFFF */   sd        $31, 0x10($29)
    /* 3ECF10 004ECF10 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3ECF14 004ECF14 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3ECF18 004ECF18 0D006058 */  blezl      $3, .L004ECF50
    /* 3ECF1C 004ECF1C 0000B0DF */   ld        $16, 0x0($29)
  .L004ECF20:
    /* 3ECF20 004ECF20 80BB0234 */  ori        $2, $0, 0xBB80
    /* 3ECF24 004ECF24 01000052 */  beql       $16, $0, .L004ECF2C
    /* 3ECF28 004ECF28 CD010000 */   break     0, 7
  .L004ECF2C:
    /* 3ECF2C 004ECF2C 1A005000 */  div        $0, $2, $16
    /* 3ECF30 004ECF30 10180000 */  mfhi       $3
    /* 3ECF34 004ECF34 05006050 */  beql       $3, $0, .L004ECF4C
    /* 3ECF38 004ECF38 300030AE */   sw        $16, 0x30($17)
    /* 3ECF3C 004ECF3C 7600043C */  lui        $4, %hi(D_0075CAA8)
    /* 3ECF40 004ECF40 DE34130C */  jal        func_004cd378
    /* 3ECF44 004ECF44 A8CA8424 */   addiu     $4, $4, %lo(D_0075CAA8)
    /* 3ECF48 004ECF48 300030AE */  sw         $16, 0x30($17)
  .L004ECF4C:
    /* 3ECF4C 004ECF4C 0000B0DF */  ld         $16, 0x0($29)
  .L004ECF50:
    /* 3ECF50 004ECF50 0800B1DF */  ld         $17, 0x8($29)
    /* 3ECF54 004ECF54 1000BFDF */  ld         $31, 0x10($29)
    /* 3ECF58 004ECF58 0800E003 */  jr         $31
    /* 3ECF5C 004ECF5C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004ecee8, 0x78
