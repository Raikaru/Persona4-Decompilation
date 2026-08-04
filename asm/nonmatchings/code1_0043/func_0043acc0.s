.section .text
.set noat
.set noreorder
glabel func_0043acc0
    /* 33ACC0 0043ACC0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 33ACC4 0043ACC4 8C00023C */  lui        $2, %hi(D_008BD9C0)
    /* 33ACC8 0043ACC8 1000B0FF */  sd         $16, 0x10($29)
    /* 33ACCC 0043ACCC 0080053C */  lui        $5, (0x80001304 >> 16)
    /* 33ACD0 0043ACD0 8C00103C */  lui        $16, %hi(D_008BDAC0)
    /* 33ACD4 0043ACD4 2000BFFF */  sd         $31, 0x20($29)
    /* 33ACD8 0043ACD8 C0DA0726 */  addiu      $7, $16, %lo(D_008BDAC0)
    /* 33ACDC 0043ACDC 0413A534 */  ori        $5, $5, (0x80001304 & 0xFFFF)
    /* 33ACE0 0043ACE0 0400E4AC */  sw         $4, 0x4($7)
    /* 33ACE4 0043ACE4 2D300000 */  daddu      $6, $0, $0
    /* 33ACE8 0043ACE8 C0D94424 */  addiu      $4, $2, %lo(D_008BD9C0)
    /* 33ACEC 0043ACEC 0000A0AF */  sw         $0, 0x0($29)
    /* 33ACF0 0043ACF0 90000824 */  addiu      $8, $0, 0x90
    /* 33ACF4 0043ACF4 2D48E000 */  daddu      $9, $7, $0
    /* 33ACF8 0043ACF8 90000A24 */  addiu      $10, $0, 0x90
    /* 33ACFC 0043ACFC 2C96100C */  jal        func_004258b0
    /* 33AD00 0043AD00 2D580000 */   daddu     $11, $0, $0
    /* 33AD04 0043AD04 05004104 */  bgez       $2, .L0043AD1C
    /* 33AD08 0043AD08 C0DA028E */   lw        $2, %lo(D_008BDAC0)($16)
    /* 33AD0C 0043AD0C 7500043C */  lui        $4, %hi(D_00754B00)
    /* 33AD10 0043AD10 D2EE100C */  jal        func_0043bb48
    /* 33AD14 0043AD14 004B8424 */   addiu     $4, $4, %lo(D_00754B00)
    /* 33AD18 0043AD18 2D100000 */  daddu      $2, $0, $0
  .L0043AD1C:
    /* 33AD1C 0043AD1C 2000BFDF */  ld         $31, 0x20($29)
    /* 33AD20 0043AD20 1000B0DF */  ld         $16, 0x10($29)
    /* 33AD24 0043AD24 0800E003 */  jr         $31
    /* 33AD28 0043AD28 3000BD27 */   addiu     $29, $29, 0x30
    /* 33AD2C 0043AD2C 00000000 */  nop
.size func_0043acc0, 0x70
