.section .text
.set noat
.set noreorder
glabel func_001a1c80
    /* A1C80 001A1C80 C0FFBD27 */  addiu      $29, $29, -0x40
    /* A1C84 001A1C84 3000BFFF */  sd         $31, 0x30($29)
    /* A1C88 001A1C88 2000B27F */  sq         $18, 0x20($29)
    /* A1C8C 001A1C8C 1000B17F */  sq         $17, 0x10($29)
    /* A1C90 001A1C90 0000B07F */  sq         $16, 0x0($29)
    /* A1C94 001A1C94 2D908000 */  daddu      $18, $4, $0
    /* A1C98 001A1C98 6C008394 */  lhu        $3, 0x6C($4)
    /* A1C9C 001A1C9C 04000224 */  addiu      $2, $0, 0x4
    /* A1CA0 001A1CA0 03006210 */  beq        $3, $2, .L001A1CB0
    /* A1CA4 001A1CA4 00000000 */   nop
    /* A1CA8 001A1CA8 0D000010 */  b          .L001A1CE0
    /* A1CAC 001A1CAC 00000000 */   nop
  .L001A1CB0:
    /* A1CB0 001A1CB0 98004526 */  addiu      $5, $18, 0x98
    /* A1CB4 001A1CB4 02000624 */  addiu      $6, $0, 0x2
    /* A1CB8 001A1CB8 2D380000 */  daddu      $7, $0, $0
    /* A1CBC 001A1CBC 2D400000 */  daddu      $8, $0, $0
    /* A1CC0 001A1CC0 185F070C */  jal        func_001d7c60
    /* A1CC4 001A1CC4 00000000 */   nop
    /* A1CC8 001A1CC8 6E005096 */  lhu        $16, 0x6E($18)
    /* A1CCC 001A1CCC 02000016 */  bnez       $16, .L001A1CD8
    /* A1CD0 001A1CD0 00000000 */   nop
    /* A1CD4 001A1CD4 FFFF1024 */  addiu      $16, $0, -0x1
  .L001A1CD8:
    /* A1CD8 001A1CD8 23000010 */  b          .L001A1D68
    /* A1CDC 001A1CDC 00000000 */   nop
  .L001A1CE0:
    /* A1CE0 001A1CE0 6E005096 */  lhu        $16, 0x6E($18)
    /* A1CE4 001A1CE4 80101000 */  sll        $2, $16, 2
    /* A1CE8 001A1CE8 21105000 */  addu       $2, $2, $16
    /* A1CEC 001A1CEC C0180200 */  sll        $3, $2, 3
    /* A1CF0 001A1CF0 B8B3828F */  lw         $2, -0x4C48($28)
    /* A1CF4 001A1CF4 21106200 */  addu       $2, $3, $2
    /* A1CF8 001A1CF8 08004390 */  lbu        $3, 0x8($2)
    /* A1CFC 001A1CFC 02000224 */  addiu      $2, $0, 0x2
    /* A1D00 001A1D00 06006210 */  beq        $3, $2, .L001A1D1C
    /* A1D04 001A1D04 00000000 */   nop
    /* A1D08 001A1D08 01000224 */  addiu      $2, $0, 0x1
    /* A1D0C 001A1D0C 03006210 */  beq        $3, $2, .L001A1D1C
    /* A1D10 001A1D10 00000000 */   nop
    /* A1D14 001A1D14 0F000010 */  b          .L001A1D54
    /* A1D18 001A1D18 00000000 */   nop
  .L001A1D1C:
    /* A1D1C 001A1D1C 80101000 */  sll        $2, $16, 2
    /* A1D20 001A1D20 21105000 */  addu       $2, $2, $16
    /* A1D24 001A1D24 C0180200 */  sll        $3, $2, 3
    /* A1D28 001A1D28 B8B3828F */  lw         $2, -0x4C48($28)
    /* A1D2C 001A1D2C 21106200 */  addu       $2, $3, $2
    /* A1D30 001A1D30 2D204002 */  daddu      $4, $18, $0
    /* A1D34 001A1D34 98004526 */  addiu      $5, $18, 0x98
    /* A1D38 001A1D38 09004690 */  lbu        $6, 0x9($2)
    /* A1D3C 001A1D3C 0A004790 */  lbu        $7, 0xA($2)
    /* A1D40 001A1D40 2D400000 */  daddu      $8, $0, $0
    /* A1D44 001A1D44 185F070C */  jal        func_001d7c60
    /* A1D48 001A1D48 00000000 */   nop
    /* A1D4C 001A1D4C 06000010 */  b          .L001A1D68
    /* A1D50 001A1D50 00000000 */   nop
  .L001A1D54:
    /* A1D54 001A1D54 FFFF0632 */  andi       $6, $16, 0xFFFF
    /* A1D58 001A1D58 98004526 */  addiu      $5, $18, 0x98
    /* A1D5C 001A1D5C 2D380000 */  daddu      $7, $0, $0
    /* A1D60 001A1D60 C45F070C */  jal        func_001d7f10
    /* A1D64 001A1D64 00000000 */   nop
  .L001A1D68:
    /* A1D68 001A1D68 2D204002 */  daddu      $4, $18, $0
    /* A1D6C 001A1D6C 98004526 */  addiu      $5, $18, 0x98
    /* A1D70 001A1D70 2C63070C */  jal        func_001d8cb0
    /* A1D74 001A1D74 00000000 */   nop
    /* A1D78 001A1D78 6E004396 */  lhu        $3, 0x6E($18)
    /* A1D7C 001A1D7C 80100300 */  sll        $2, $3, 2
    /* A1D80 001A1D80 21104300 */  addu       $2, $2, $3
    /* A1D84 001A1D84 C0180200 */  sll        $3, $2, 3
    /* A1D88 001A1D88 B8B3828F */  lw         $2, -0x4C48($28)
    /* A1D8C 001A1D8C 21106200 */  addu       $2, $3, $2
    /* A1D90 001A1D90 08004390 */  lbu        $3, 0x8($2)
    /* A1D94 001A1D94 02000224 */  addiu      $2, $0, 0x2
    /* A1D98 001A1D98 06006210 */  beq        $3, $2, .L001A1DB4
    /* A1D9C 001A1D9C 00000000 */   nop
    /* A1DA0 001A1DA0 01000224 */  addiu      $2, $0, 0x1
    /* A1DA4 001A1DA4 03006210 */  beq        $3, $2, .L001A1DB4
    /* A1DA8 001A1DA8 00000000 */   nop
    /* A1DAC 001A1DAC 04000010 */  b          .L001A1DC0
    /* A1DB0 001A1DB0 00000000 */   nop
  .L001A1DB4:
    /* A1DB4 001A1DB4 2D880000 */  daddu      $17, $0, $0
    /* A1DB8 001A1DB8 05000010 */  b          .L001A1DD0
    /* A1DBC 001A1DBC 00000000 */   nop
  .L001A1DC0:
    /* A1DC0 001A1DC0 2D204002 */  daddu      $4, $18, $0
    /* A1DC4 001A1DC4 98004526 */  addiu      $5, $18, 0x98
    /* A1DC8 001A1DC8 9463070C */  jal        func_001d8e50
    /* A1DCC 001A1DCC 00000000 */   nop
  .L001A1DD0:
    /* A1DD0 001A1DD0 ACB3828F */  lw         $2, -0x4C54($28)
    /* A1DD4 001A1DD4 3C3C1000 */  dsll32     $7, $16, 16
    /* A1DD8 001A1DD8 3F3C0700 */  dsra32     $7, $7, 16
    /* A1DDC 001A1DDC D40D448C */  lw         $4, 0xDD4($2)
    /* A1DE0 001A1DE0 2D284002 */  daddu      $5, $18, $0
    /* A1DE4 001A1DE4 98004626 */  addiu      $6, $18, 0x98
    /* A1DE8 001A1DE8 B42D080C */  jal        func_0020b6d0
    /* A1DEC 001A1DEC 00000000 */   nop
    /* A1DF0 001A1DF0 2D204002 */  daddu      $4, $18, $0
    /* A1DF4 001A1DF4 22000524 */  addiu      $5, $0, 0x22
    /* A1DF8 001A1DF8 48F2060C */  jal        func_001bc920
    /* A1DFC 001A1DFC 00000000 */   nop
    /* A1E00 001A1E00 2D204000 */  daddu      $4, $2, $0
    /* A1E04 001A1E04 000043DE */  ld         $3, 0x0($18)
    /* A1E08 001A1E08 600043FC */  sd         $3, 0x60($2)
    /* A1E0C 001A1E0C 2D280000 */  daddu      $5, $0, $0
    /* A1E10 001A1E10 6451060C */  jal        func_00194590
    /* A1E14 001A1E14 00000000 */   nop
    /* A1E18 001A1E18 ACB3828F */  lw         $2, -0x4C54($28)
    /* A1E1C 001A1E1C D40D448C */  lw         $4, 0xDD4($2)
    /* A1E20 001A1E20 0448080C */  jal        func_00212010
    /* A1E24 001A1E24 00000000 */   nop
    /* A1E28 001A1E28 2D204002 */  daddu      $4, $18, $0
    /* A1E2C 001A1E2C BC7E060C */  jal        func_0019faf0
    /* A1E30 001A1E30 00000000 */   nop
    /* A1E34 001A1E34 12002012 */  beqz       $17, .L001A1E80
    /* A1E38 001A1E38 00000000 */   nop
    /* A1E3C 001A1E3C 2D200000 */  daddu      $4, $0, $0
    /* A1E40 001A1E40 3000258E */  lw         $5, 0x30($17)
    /* A1E44 001A1E44 01000624 */  addiu      $6, $0, 0x1
    /* A1E48 001A1E48 5479060C */  jal        func_0019e550
    /* A1E4C 001A1E4C 00000000 */   nop
    /* A1E50 001A1E50 2D204000 */  daddu      $4, $2, $0
    /* A1E54 001A1E54 01000524 */  addiu      $5, $0, 0x1
    /* A1E58 001A1E58 6451060C */  jal        func_00194590
    /* A1E5C 001A1E5C 00000000 */   nop
    /* A1E60 001A1E60 3000248E */  lw         $4, 0x30($17)
    /* A1E64 001A1E64 2D280000 */  daddu      $5, $0, $0
    /* A1E68 001A1E68 F079060C */  jal        func_0019e7c0
    /* A1E6C 001A1E6C 00000000 */   nop
    /* A1E70 001A1E70 2D204000 */  daddu      $4, $2, $0
    /* A1E74 001A1E74 01000524 */  addiu      $5, $0, 0x1
    /* A1E78 001A1E78 6451060C */  jal        func_00194590
    /* A1E7C 001A1E7C 00000000 */   nop
  .L001A1E80:
    /* A1E80 001A1E80 3000BFDF */  ld         $31, 0x30($29)
    /* A1E84 001A1E84 2000B27B */  lq         $18, 0x20($29)
    /* A1E88 001A1E88 1000B17B */  lq         $17, 0x10($29)
    /* A1E8C 001A1E8C 0000B07B */  lq         $16, 0x0($29)
    /* A1E90 001A1E90 4000BD27 */  addiu      $29, $29, 0x40
    /* A1E94 001A1E94 0800E003 */  jr         $31
    /* A1E98 001A1E98 00000000 */   nop
    /* A1E9C 001A1E9C 00000000 */  nop
.size func_001a1c80, 0x220
