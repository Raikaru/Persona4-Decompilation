.section .text
.set noat
.set noreorder
glabel func_003e3f80
    /* 2E3F80 003E3F80 1A008010 */  beqz       $4, .L003E3FEC
    /* 2E3F84 003E3F84 00000000 */   nop
  .L003E3F88:
    /* 2E3F88 003E3F88 A0B7838F */  lw         $3, -0x4860($28)
    /* 2E3F8C 003E3F8C 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2E3F90 003E3F90 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2E3F94 003E3F94 21104300 */  addu       $2, $2, $3
    /* 2E3F98 003E3F98 1700A010 */  beqz       $5, .L003E3FF8
    /* 2E3F9C 003E3F9C 080044AC */   sw        $4, 0x8($2)
  .L003E3FA0:
    /* 2E3FA0 003E3FA0 A0B7838F */  lw         $3, -0x4860($28)
    /* 2E3FA4 003E3FA4 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2E3FA8 003E3FA8 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2E3FAC 003E3FAC 21104300 */  addu       $2, $2, $3
    /* 2E3FB0 003E3FB0 1400C010 */  beqz       $6, .L003E4004
    /* 2E3FB4 003E3FB4 0C0045AC */   sw        $5, 0xC($2)
  .L003E3FB8:
    /* 2E3FB8 003E3FB8 A0B7838F */  lw         $3, -0x4860($28)
    /* 2E3FBC 003E3FBC 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2E3FC0 003E3FC0 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2E3FC4 003E3FC4 21104300 */  addu       $2, $2, $3
    /* 2E3FC8 003E3FC8 1100E010 */  beqz       $7, .L003E4010
    /* 2E3FCC 003E3FCC 100046AC */   sw        $6, 0x10($2)
  .L003E3FD0:
    /* 2E3FD0 003E3FD0 A0B7848F */  lw         $4, -0x4860($28)
    /* 2E3FD4 003E3FD4 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2E3FD8 003E3FD8 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2E3FDC 003E3FDC 01000224 */  addiu      $2, $0, 0x1
    /* 2E3FE0 003E3FE0 21186400 */  addu       $3, $3, $4
    /* 2E3FE4 003E3FE4 0D000010 */  b          .L003E401C
    /* 2E3FE8 003E3FE8 140067AC */   sw        $7, 0x14($3)
  .L003E3FEC:
    /* 2E3FEC 003E3FEC 3E00043C */  lui        $4, %hi(func_003e3dc0)
    /* 2E3FF0 003E3FF0 E5FF0010 */  b          .L003E3F88
    /* 2E3FF4 003E3FF4 C03D8424 */   addiu     $4, $4, %lo(func_003e3dc0)
  .L003E3FF8:
    /* 2E3FF8 003E3FF8 3E00053C */  lui        $5, %hi(func_003e3d00)
    /* 2E3FFC 003E3FFC E8FF0010 */  b          .L003E3FA0
    /* 2E4000 003E4000 003DA524 */   addiu     $5, $5, %lo(func_003e3d00)
  .L003E4004:
    /* 2E4004 003E4004 3E00063C */  lui        $6, %hi(func_003e3f00)
    /* 2E4008 003E4008 EBFF0010 */  b          .L003E3FB8
    /* 2E400C 003E400C 003FC624 */   addiu     $6, $6, %lo(func_003e3f00)
  .L003E4010:
    /* 2E4010 003E4010 3E00073C */  lui        $7, %hi(func_003e3e60)
    /* 2E4014 003E4014 EEFF0010 */  b          .L003E3FD0
    /* 2E4018 003E4018 603EE724 */   addiu     $7, $7, %lo(func_003e3e60)
  .L003E401C:
    /* 2E401C 003E401C 0800E003 */  jr         $31
    /* 2E4020 003E4020 00000000 */   nop
    /* 2E4024 003E4024 00000000 */  nop
    /* 2E4028 003E4028 00000000 */  nop
    /* 2E402C 003E402C 00000000 */  nop
.size func_003e3f80, 0xb0
