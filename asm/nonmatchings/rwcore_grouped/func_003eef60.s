.section .text
.set noat
.set noreorder
glabel func_003eef60
    /* 2EEF60 003EEF60 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2EEF64 003EEF64 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EEF68 003EEF68 3000BFFF */  sd         $31, 0x30($29)
    /* 2EEF6C 003EEF6C E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EEF70 003EEF70 2000B27F */  sq         $18, 0x20($29)
    /* 2EEF74 003EEF74 1000B17F */  sq         $17, 0x10($29)
    /* 2EEF78 003EEF78 0000B07F */  sq         $16, 0x0($29)
    /* 2EEF7C 003EEF7C E0B7838F */  lw         $3, -0x4820($28)
    /* 2EEF80 003EEF80 2D808000 */  daddu      $16, $4, $0
    /* 2EEF84 003EEF84 21884300 */  addu       $17, $2, $3
    /* 2EEF88 003EEF88 1000248E */  lw         $4, 0x10($17)
    /* 2EEF8C 003EEF8C 05008010 */  beqz       $4, .L003EEFA4
    /* 2EEF90 003EEF90 00000000 */   nop
    /* 2EEF94 003EEF94 94BD0F0C */  jal        func_003ef650
    /* 2EEF98 003EEF98 2D280002 */   daddu     $5, $16, $0
    /* 2EEF9C 003EEF9C 12000010 */  b          .L003EEFE8
    /* 2EEFA0 003EEFA0 3000BFDF */   ld        $31, 0x30($29)
  .L003EEFA4:
    /* 2EEFA4 003EEFA4 0000328E */  lw         $18, 0x0($17)
    /* 2EEFA8 003EEFA8 0D005112 */  beq        $18, $17, .L003EEFE0
    /* 2EEFAC 003EEFAC 00000000 */   nop
  .L003EEFB0:
    /* 2EEFB0 003EEFB0 F0FF4426 */  addiu      $4, $18, -0x10
    /* 2EEFB4 003EEFB4 94BD0F0C */  jal        func_003ef650
    /* 2EEFB8 003EEFB8 2D280002 */   daddu     $5, $16, $0
    /* 2EEFBC 003EEFBC 2B180200 */  sltu       $3, $0, $2
    /* 2EEFC0 003EEFC0 01006338 */  xori       $3, $3, 0x1
    /* 2EEFC4 003EEFC4 03006014 */  bnez       $3, .L003EEFD4
    /* 2EEFC8 003EEFC8 00000000 */   nop
    /* 2EEFCC 003EEFCC 05000010 */  b          .L003EEFE4
    /* 2EEFD0 003EEFD0 00000000 */   nop
  .L003EEFD4:
    /* 2EEFD4 003EEFD4 0000528E */  lw         $18, 0x0($18)
    /* 2EEFD8 003EEFD8 F5FF5116 */  bne        $18, $17, .L003EEFB0
    /* 2EEFDC 003EEFDC 00000000 */   nop
  .L003EEFE0:
    /* 2EEFE0 003EEFE0 2D100000 */  daddu      $2, $0, $0
  .L003EEFE4:
    /* 2EEFE4 003EEFE4 3000BFDF */  ld         $31, 0x30($29)
  .L003EEFE8:
    /* 2EEFE8 003EEFE8 2000B27B */  lq         $18, 0x20($29)
    /* 2EEFEC 003EEFEC 1000B17B */  lq         $17, 0x10($29)
    /* 2EEFF0 003EEFF0 0000B07B */  lq         $16, 0x0($29)
    /* 2EEFF4 003EEFF4 0800E003 */  jr         $31
    /* 2EEFF8 003EEFF8 4000BD27 */   addiu     $29, $29, 0x40
    /* 2EEFFC 003EEFFC 00000000 */  nop
.size func_003eef60, 0xa0
