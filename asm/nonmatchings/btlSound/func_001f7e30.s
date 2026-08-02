.section .text
.set noat
.set noreorder
glabel func_001f7e30
    /* F7E30 001F7E30 30FFBD27 */  addiu      $29, $29, -0xD0
    /* F7E34 001F7E34 3000BFFF */  sd         $31, 0x30($29)
    /* F7E38 001F7E38 2000B27F */  sq         $18, 0x20($29)
    /* F7E3C 001F7E3C 1000B17F */  sq         $17, 0x10($29)
    /* F7E40 001F7E40 0000B07F */  sq         $16, 0x0($29)
    /* F7E44 001F7E44 2D808000 */  daddu      $16, $4, $0
    /* F7E48 001F7E48 0800828C */  lw         $2, 0x8($4)
    /* F7E4C 001F7E4C 13004014 */  bnez       $2, .L001F7E9C
    /* F7E50 001F7E50 00000000 */   nop
    /* F7E54 001F7E54 04000796 */  lhu        $7, 0x4($16)
    /* F7E58 001F7E58 4000A427 */  addiu      $4, $29, 0x40
    /* F7E5C 001F7E5C 6200053C */  lui        $5, %hi(D_00624F30)
    /* F7E60 001F7E60 304FA524 */  addiu      $5, $5, %lo(D_00624F30)
    /* F7E64 001F7E64 F8A48627 */  addiu      $6, $28, -0x5B08
    /* F7E68 001F7E68 2208110C */  jal        func_00442088
    /* F7E6C 001F7E6C 00000000 */   nop
    /* F7E70 001F7E70 F0A48427 */  addiu      $4, $28, -0x5B10
    /* F7E74 001F7E74 6200053C */  lui        $5, %hi(D_00624F20)
    /* F7E78 001F7E78 204FA524 */  addiu      $5, $5, %lo(D_00624F20)
    /* F7E7C 001F7E7C AA020624 */  addiu      $6, $0, 0x2AA
    /* F7E80 001F7E80 DA02110C */  jal        func_00440b68
    /* F7E84 001F7E84 00000000 */   nop
    /* F7E88 001F7E88 4000A427 */  addiu      $4, $29, 0x40
    /* F7E8C 001F7E8C 2D280000 */  daddu      $5, $0, $0
    /* F7E90 001F7E90 9852110C */  jal        func_00454a60
    /* F7E94 001F7E94 00000000 */   nop
    /* F7E98 001F7E98 080002AE */  sw         $2, 0x8($16)
  .L001F7E9C:
    /* F7E9C 001F7E9C 06000396 */  lhu        $3, 0x6($16)
    /* F7EA0 001F7EA0 02000424 */  addiu      $4, $0, 0x2
    /* F7EA4 001F7EA4 3C006410 */  beq        $3, $4, .L001F7F98
    /* F7EA8 001F7EA8 00000000 */   nop
    /* F7EAC 001F7EAC 01000224 */  addiu      $2, $0, 0x1
    /* F7EB0 001F7EB0 03006210 */  beq        $3, $2, .L001F7EC0
    /* F7EB4 001F7EB4 00000000 */   nop
    /* F7EB8 001F7EB8 44000010 */  b          .L001F7FCC
    /* F7EBC 001F7EBC 00000000 */   nop
  .L001F7EC0:
    /* F7EC0 001F7EC0 0800048E */  lw         $4, 0x8($16)
    /* F7EC4 001F7EC4 F054110C */  jal        func_004553c0
    /* F7EC8 001F7EC8 00000000 */   nop
    /* F7ECC 001F7ECC 04004014 */  bnez       $2, .L001F7EE0
    /* F7ED0 001F7ED0 00000000 */   nop
    /* F7ED4 001F7ED4 2D100000 */  daddu      $2, $0, $0
    /* F7ED8 001F7ED8 40000010 */  b          .L001F7FDC
    /* F7EDC 001F7EDC 00000000 */   nop
  .L001F7EE0:
    /* F7EE0 001F7EE0 02000424 */  addiu      $4, $0, 0x2
    /* F7EE4 001F7EE4 04000524 */  addiu      $5, $0, 0x4
    /* F7EE8 001F7EE8 A46A110C */  jal        func_0045aa90
    /* F7EEC 001F7EEC 00000000 */   nop
    /* F7EF0 001F7EF0 05001124 */  addiu      $17, $0, 0x5
    /* F7EF4 001F7EF4 07000010 */  b          .L001F7F14
    /* F7EF8 001F7EF8 00000000 */   nop
  .L001F7EFC:
    /* F7EFC 001F7EFC 3C2C1100 */  dsll32     $5, $17, 16
    /* F7F00 001F7F00 3F2C0500 */  dsra32     $5, $5, 16
    /* F7F04 001F7F04 02000424 */  addiu      $4, $0, 0x2
    /* F7F08 001F7F08 A46A110C */  jal        func_0045aa90
    /* F7F0C 001F7F0C 00000000 */   nop
    /* F7F10 001F7F10 01003126 */  addiu      $17, $17, 0x1
  .L001F7F14:
    /* F7F14 001F7F14 0A00212A */  slti       $1, $17, 0xA
    /* F7F18 001F7F18 F8FF2014 */  bnez       $1, .L001F7EFC
    /* F7F1C 001F7F1C 00000000 */   nop
    /* F7F20 001F7F20 0800048E */  lw         $4, 0x8($16)
    /* F7F24 001F7F24 2D280000 */  daddu      $5, $0, $0
    /* F7F28 001F7F28 CC00A627 */  addiu      $6, $29, 0xCC
    /* F7F2C 001F7F2C A857110C */  jal        func_00455ea0
    /* F7F30 001F7F30 00000000 */   nop
    /* F7F34 001F7F34 2D904000 */  daddu      $18, $2, $0
    /* F7F38 001F7F38 0800048E */  lw         $4, 0x8($16)
    /* F7F3C 001F7F3C 01000524 */  addiu      $5, $0, 0x1
    /* F7F40 001F7F40 C800A627 */  addiu      $6, $29, 0xC8
    /* F7F44 001F7F44 A857110C */  jal        func_00455ea0
    /* F7F48 001F7F48 00000000 */   nop
    /* F7F4C 001F7F4C 2D884000 */  daddu      $17, $2, $0
    /* F7F50 001F7F50 0800048E */  lw         $4, 0x8($16)
    /* F7F54 001F7F54 02000524 */  addiu      $5, $0, 0x2
    /* F7F58 001F7F58 C400A627 */  addiu      $6, $29, 0xC4
    /* F7F5C 001F7F5C A857110C */  jal        func_00455ea0
    /* F7F60 001F7F60 00000000 */   nop
    /* F7F64 001F7F64 02000424 */  addiu      $4, $0, 0x2
    /* F7F68 001F7F68 2D284002 */  daddu      $5, $18, $0
    /* F7F6C 001F7F6C CC00A68F */  lw         $6, 0xCC($29)
    /* F7F70 001F7F70 2D382002 */  daddu      $7, $17, $0
    /* F7F74 001F7F74 C800A88F */  lw         $8, 0xC8($29)
    /* F7F78 001F7F78 2D484000 */  daddu      $9, $2, $0
    /* F7F7C 001F7F7C C400AA8F */  lw         $10, 0xC4($29)
    /* F7F80 001F7F80 5C69110C */  jal        func_0045a570
    /* F7F84 001F7F84 00000000 */   nop
    /* F7F88 001F7F88 02000224 */  addiu      $2, $0, 0x2
    /* F7F8C 001F7F8C 060002A6 */  sh         $2, 0x6($16)
    /* F7F90 001F7F90 0E000010 */  b          .L001F7FCC
    /* F7F94 001F7F94 00000000 */   nop
  .L001F7F98:
    /* F7F98 001F7F98 246A110C */  jal        func_0045a890
    /* F7F9C 001F7F9C 00000000 */   nop
    /* F7FA0 001F7FA0 04004014 */  bnez       $2, .L001F7FB4
    /* F7FA4 001F7FA4 00000000 */   nop
    /* F7FA8 001F7FA8 2D100000 */  daddu      $2, $0, $0
    /* F7FAC 001F7FAC 0B000010 */  b          .L001F7FDC
    /* F7FB0 001F7FB0 00000000 */   nop
  .L001F7FB4:
    /* F7FB4 001F7FB4 0800048E */  lw         $4, 0x8($16)
    /* F7FB8 001F7FB8 F452110C */  jal        func_00454bd0
    /* F7FBC 001F7FBC 00000000 */   nop
    /* F7FC0 001F7FC0 01000224 */  addiu      $2, $0, 0x1
    /* F7FC4 001F7FC4 05000010 */  b          .L001F7FDC
    /* F7FC8 001F7FC8 00000000 */   nop
  .L001F7FCC:
    /* F7FCC 001F7FCC 0000028E */  lw         $2, 0x0($16)
    /* F7FD0 001F7FD0 01004224 */  addiu      $2, $2, 0x1
    /* F7FD4 001F7FD4 000002AE */  sw         $2, 0x0($16)
    /* F7FD8 001F7FD8 2D100000 */  daddu      $2, $0, $0
  .L001F7FDC:
    /* F7FDC 001F7FDC 3000BFDF */  ld         $31, 0x30($29)
    /* F7FE0 001F7FE0 2000B27B */  lq         $18, 0x20($29)
    /* F7FE4 001F7FE4 1000B17B */  lq         $17, 0x10($29)
    /* F7FE8 001F7FE8 0000B07B */  lq         $16, 0x0($29)
    /* F7FEC 001F7FEC D000BD27 */  addiu      $29, $29, 0xD0
    /* F7FF0 001F7FF0 0800E003 */  jr         $31
    /* F7FF4 001F7FF4 00000000 */   nop
    /* F7FF8 001F7FF8 00000000 */  nop
    /* F7FFC 001F7FFC 00000000 */  nop
.size func_001f7e30, 0x1d0
