.section .text
.set noat
.set noreorder
glabel func_001daf40
    /* DAF40 001DAF40 D0FFBD27 */  addiu      $29, $29, -0x30
    /* DAF44 001DAF44 2000BFFF */  sd         $31, 0x20($29)
    /* DAF48 001DAF48 1000B17F */  sq         $17, 0x10($29)
    /* DAF4C 001DAF4C 0000B07F */  sq         $16, 0x0($29)
    /* DAF50 001DAF50 2D808000 */  daddu      $16, $4, $0
    /* DAF54 001DAF54 FFFFB130 */  andi       $17, $5, 0xFFFF
    /* DAF58 001DAF58 4002222A */  slti       $2, $17, 0x240
    /* DAF5C 001DAF5C 06004014 */  bnez       $2, .L001DAF78
    /* DAF60 001DAF60 00000000 */   nop
    /* DAF64 001DAF64 6100043C */  lui        $4, %hi(D_006095E0)
    /* DAF68 001DAF68 E0958424 */  addiu      $4, $4, %lo(D_006095E0)
    /* DAF6C 001DAF6C 5F040524 */  addiu      $5, $0, 0x45F
    /* DAF70 001DAF70 CCB5110C */  jal        func_0046d730
    /* DAF74 001DAF74 00000000 */   nop
  .L001DAF78:
    /* DAF78 001DAF78 3000108E */  lw         $16, 0x30($16)
    /* DAF7C 001DAF7C B801212A */  slti       $1, $17, 0x1B8
    /* DAF80 001DAF80 1D002010 */  beqz       $1, .L001DAFF8
    /* DAF84 001DAF84 00000000 */   nop
    /* DAF88 001DAF88 640A048E */  lw         $4, 0xA64($16)
    /* DAF8C 001DAF8C 0800023C */  lui        $2, (0x80008 >> 16)
    /* DAF90 001DAF90 08004534 */  ori        $5, $2, (0x80008 & 0xFFFF)
    /* DAF94 001DAF94 C4C9080C */  jal        func_00232710
    /* DAF98 001DAF98 00000000 */   nop
    /* DAF9C 001DAF9C 04004010 */  beqz       $2, .L001DAFB0
    /* DAFA0 001DAFA0 00000000 */   nop
    /* DAFA4 001DAFA4 2D100000 */  daddu      $2, $0, $0
    /* DAFA8 001DAFA8 1D000010 */  b          .L001DB020
    /* DAFAC 001DAFAC 00000000 */   nop
  .L001DAFB0:
    /* DAFB0 001DAFB0 640A048E */  lw         $4, 0xA64($16)
    /* DAFB4 001DAFB4 2D282002 */  daddu      $5, $17, $0
    /* DAFB8 001DAFB8 CCC9080C */  jal        func_00232730
    /* DAFBC 001DAFBC 00000000 */   nop
    /* DAFC0 001DAFC0 04004014 */  bnez       $2, .L001DAFD4
    /* DAFC4 001DAFC4 00000000 */   nop
    /* DAFC8 001DAFC8 2D100000 */  daddu      $2, $0, $0
    /* DAFCC 001DAFCC 14000010 */  b          .L001DB020
    /* DAFD0 001DAFD0 00000000 */   nop
  .L001DAFD4:
    /* DAFD4 001DAFD4 640A048E */  lw         $4, 0xA64($16)
    /* DAFD8 001DAFD8 2D282002 */  daddu      $5, $17, $0
    /* DAFDC 001DAFDC 70F7080C */  jal        func_0023ddc0
    /* DAFE0 001DAFE0 00000000 */   nop
    /* DAFE4 001DAFE4 0D004010 */  beqz       $2, .L001DB01C
    /* DAFE8 001DAFE8 00000000 */   nop
    /* DAFEC 001DAFEC 2D100000 */  daddu      $2, $0, $0
    /* DAFF0 001DAFF0 0B000010 */  b          .L001DB020
    /* DAFF4 001DAFF4 00000000 */   nop
  .L001DAFF8:
    /* DAFF8 001DAFF8 640A048E */  lw         $4, 0xA64($16)
    /* DAFFC 001DAFFC 2D282002 */  daddu      $5, $17, $0
    /* DB000 001DB000 CCC9080C */  jal        func_00232730
    /* DB004 001DB004 00000000 */   nop
    /* DB008 001DB008 04004014 */  bnez       $2, .L001DB01C
    /* DB00C 001DB00C 00000000 */   nop
    /* DB010 001DB010 2D100000 */  daddu      $2, $0, $0
    /* DB014 001DB014 02000010 */  b          .L001DB020
    /* DB018 001DB018 00000000 */   nop
  .L001DB01C:
    /* DB01C 001DB01C 01000224 */  addiu      $2, $0, 0x1
  .L001DB020:
    /* DB020 001DB020 2000BFDF */  ld         $31, 0x20($29)
    /* DB024 001DB024 1000B17B */  lq         $17, 0x10($29)
    /* DB028 001DB028 0000B07B */  lq         $16, 0x0($29)
    /* DB02C 001DB02C 3000BD27 */  addiu      $29, $29, 0x30
    /* DB030 001DB030 0800E003 */  jr         $31
    /* DB034 001DB034 00000000 */   nop
    /* DB038 001DB038 00000000 */  nop
    /* DB03C 001DB03C 00000000 */  nop
.size func_001daf40, 0x100
