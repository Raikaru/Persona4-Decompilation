.section .text
.set noat
.set noreorder
glabel func_004ea0b8
    /* 3EA0B8 004EA0B8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EA0BC 004EA0BC 00080224 */  addiu      $2, $0, 0x800
    /* 3EA0C0 004EA0C0 0000B0FF */  sd         $16, 0x0($29)
    /* 3EA0C4 004EA0C4 2D808000 */  daddu      $16, $4, $0
    /* 3EA0C8 004EA0C8 0800BFFF */  sd         $31, 0x8($29)
    /* 3EA0CC 004EA0CC 1C000426 */  addiu      $4, $16, 0x1C
    /* 3EA0D0 004EA0D0 08A8130C */  jal        func_004ea020
    /* 3EA0D4 004EA0D4 040002AE */   sw        $2, 0x4($16)
    /* 3EA0D8 004EA0D8 0400038E */  lw         $3, 0x4($16)
    /* 3EA0DC 004EA0DC 080002AE */  sw         $2, 0x8($16)
    /* 3EA0E0 004EA0E0 01000424 */  addiu      $4, $0, 0x1
    /* 3EA0E4 004EA0E4 21104300 */  addu       $2, $2, $3
    /* 3EA0E8 004EA0E8 01006050 */  beql       $3, $0, .L004EA0F0
    /* 3EA0EC 004EA0EC CD010000 */   break     0, 7
  .L004EA0F0:
    /* 3EA0F0 004EA0F0 FFFF4224 */  addiu      $2, $2, -0x1
    /* 3EA0F4 004EA0F4 000004A2 */  sb         $4, 0x0($16)
    /* 3EA0F8 004EA0F8 1A004300 */  div        $0, $2, $3
    /* 3EA0FC 004EA0FC 100000AE */  sw         $0, 0x10($16)
    /* 3EA100 004EA100 180000AE */  sw         $0, 0x18($16)
    /* 3EA104 004EA104 140000AE */  sw         $0, 0x14($16)
    /* 3EA108 004EA108 010000A2 */  sb         $0, 0x1($16)
    /* 3EA10C 004EA10C 0800BFDF */  ld         $31, 0x8($29)
    /* 3EA110 004EA110 12100000 */  mflo       $2
    /* 3EA114 004EA114 0C0002AE */  sw         $2, 0xC($16)
    /* 3EA118 004EA118 0000B0DF */  ld         $16, 0x0($29)
    /* 3EA11C 004EA11C 0800E003 */  jr         $31
    /* 3EA120 004EA120 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EA124 004EA124 00000000 */  nop
.size func_004ea0b8, 0x70
