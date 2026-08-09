.section .text
.set noat
.set noreorder
glabel func_001a2c70
    /* A2C70 001A2C70 E0FFBD27 */  addiu      $29, $29, -0x20
    /* A2C74 001A2C74 1000BFFF */  sd         $31, 0x10($29)
    /* A2C78 001A2C78 0000B07F */  sq         $16, 0x0($29)
    /* A2C7C 001A2C7C 2D808000 */  daddu      $16, $4, $0
    /* A2C80 001A2C80 01000224 */  addiu      $2, $0, 0x1
    /* A2C84 001A2C84 6C0082A4 */  sh         $2, 0x6C($4)
    /* A2C88 001A2C88 3000828C */  lw         $2, 0x30($4)
    /* A2C8C 001A2C8C 640A448C */  lw         $4, 0xA64($2)
    /* A2C90 001A2C90 F8F7080C */  jal        func_0023dfe0
    /* A2C94 001A2C94 00000000 */   nop
    /* A2C98 001A2C98 6E0002A6 */  sh         $2, 0x6E($16)
    /* A2C9C 001A2C9C 98000426 */  addiu      $4, $16, 0x98
    /* A2CA0 001A2CA0 F062070C */  jal        func_001d8bc0
    /* A2CA4 001A2CA4 00000000 */   nop
    /* A2CA8 001A2CA8 380002AE */  sw         $2, 0x38($16)
    /* A2CAC 001A2CAC 01000224 */  addiu      $2, $0, 0x1
    /* A2CB0 001A2CB0 6A0002A6 */  sh         $2, 0x6A($16)
    /* A2CB4 001A2CB4 98000426 */  addiu      $4, $16, 0x98
    /* A2CB8 001A2CB8 3800058E */  lw         $5, 0x38($16)
    /* A2CBC 001A2CBC F862070C */  jal        func_001d8be0
    /* A2CC0 001A2CC0 00000000 */   nop
    /* A2CC4 001A2CC4 3000038E */  lw         $3, 0x30($16)
    /* A2CC8 001A2CC8 A2006290 */  lbu        $2, 0xA2($3)
    /* A2CCC 001A2CCC 0F004014 */  bnez       $2, .L001A2D0C
    /* A2CD0 001A2CD0 00000000 */   nop
    /* A2CD4 001A2CD4 A4006294 */  lhu        $2, 0xA4($3)
    /* A2CD8 001A2CD8 01000524 */  addiu      $5, $0, 0x1
    /* A2CDC 001A2CDC 0B004514 */  bne        $2, $5, .L001A2D0C
    /* A2CE0 001A2CE0 00000000 */   nop
    /* A2CE4 001A2CE4 2D200002 */  daddu      $4, $16, $0
    /* A2CE8 001A2CE8 2D300000 */  daddu      $6, $0, $0
    /* A2CEC 001A2CEC 2D380000 */  daddu      $7, $0, $0
    /* A2CF0 001A2CF0 2D400000 */  daddu      $8, $0, $0
    /* A2CF4 001A2CF4 DCD7070C */  jal        func_001f5f70
    /* A2CF8 001A2CF8 00000000 */   nop
    /* A2CFC 001A2CFC 2D204000 */  daddu      $4, $2, $0
    /* A2D00 001A2D00 01000524 */  addiu      $5, $0, 0x1
    /* A2D04 001A2D04 6451060C */  jal        func_00194590
    /* A2D08 001A2D08 00000000 */   nop
  .L001A2D0C:
    /* A2D0C 001A2D0C ACB3828F */  lw         $2, -0x4C54($28)
    /* A2D10 001A2D10 0C00438C */  lw         $3, 0xC($2)
    /* A2D14 001A2D14 0004023C */  lui        $2, (0x4000000 >> 16)
    /* A2D18 001A2D18 24106200 */  and        $2, $3, $2
    /* A2D1C 001A2D1C 04004010 */  beqz       $2, .L001A2D30
    /* A2D20 001A2D20 00000000 */   nop
    /* A2D24 001A2D24 18000296 */  lhu        $2, 0x18($16)
    /* A2D28 001A2D28 00404234 */  ori        $2, $2, 0x4000
    /* A2D2C 001A2D2C 180002A6 */  sh         $2, 0x18($16)
  .L001A2D30:
    /* A2D30 001A2D30 18000296 */  lhu        $2, 0x18($16)
    /* A2D34 001A2D34 02004234 */  ori        $2, $2, 0x2
    /* A2D38 001A2D38 180002A6 */  sh         $2, 0x18($16)
    /* A2D3C 001A2D3C 2D200002 */  daddu      $4, $16, $0
    /* A2D40 001A2D40 0F000524 */  addiu      $5, $0, 0xF
    /* A2D44 001A2D44 00C2060C */  jal        func_001b0800
    /* A2D48 001A2D48 00000000 */   nop
    /* A2D4C 001A2D4C 1000BFDF */  ld         $31, 0x10($29)
    /* A2D50 001A2D50 0000B07B */  lq         $16, 0x0($29)
    /* A2D54 001A2D54 2000BD27 */  addiu      $29, $29, 0x20
    /* A2D58 001A2D58 0800E003 */  jr         $31
    /* A2D5C 001A2D5C 00000000 */   nop
    /* A2D60 001A2D60 0800E003 */  jr         $31
    /* A2D64 001A2D64 00000000 */   nop
    /* A2D68 001A2D68 00000000 */  nop
    /* A2D6C 001A2D6C 00000000 */  nop
.size func_001a2c70, 0x100
