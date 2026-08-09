.section .text
.set noat
.set noreorder
glabel func_0043dc60
    /* 33DC60 0043DC60 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 33DC64 0043DC64 71000F3C */  lui        $15, %hi(D_00710070)
    /* 33DC68 0043DC68 1800B3FF */  sd         $19, 0x18($29)
    /* 33DC6C 0043DC6C 0000B0FF */  sd         $16, 0x0($29)
    /* 33DC70 0043DC70 0800B1FF */  sd         $17, 0x8($29)
    /* 33DC74 0043DC74 1000B2FF */  sd         $18, 0x10($29)
    /* 33DC78 0043DC78 2000BFFF */  sd         $31, 0x20($29)
    /* 33DC7C 0043DC7C 7000EE8D */  lw         $14, %lo(D_00710070)($15)
    /* 33DC80 0043DC80 4801D28D */  lw         $18, 0x148($14)
    /* 33DC84 0043DC84 10004012 */  beqz       $18, .L0043DCC8
    /* 33DC88 0043DC88 2D988000 */   daddu     $19, $4, $0
    /* 33DC8C 0043DC8C 0400518E */  lw         $17, 0x4($18)
  .L0043DC90:
    /* 33DC90 0043DC90 FFFF3126 */  addiu      $17, $17, -0x1
    /* 33DC94 0043DC94 08002006 */  bltz       $17, .L0043DCB8
    /* 33DC98 0043DC98 80781100 */   sll       $15, $17, 2
    /* 33DC9C 0043DC9C 2178F201 */  addu       $15, $15, $18
    /* 33DCA0 0043DCA0 0800F025 */  addiu      $16, $15, 0x8
  .L0043DCA4:
    /* 33DCA4 0043DCA4 00000F8E */  lw         $15, 0x0($16)
    /* 33DCA8 0043DCA8 09F8E001 */  jalr       $15
    /* 33DCAC 0043DCAC FFFF3126 */   addiu     $17, $17, -0x1
    /* 33DCB0 0043DCB0 FCFF2106 */  bgez       $17, .L0043DCA4
    /* 33DCB4 0043DCB4 FCFF1026 */   addiu     $16, $16, -0x4
  .L0043DCB8:
    /* 33DCB8 0043DCB8 0000528E */  lw         $18, 0x0($18)
    /* 33DCBC 0043DCBC F4FF4056 */  bnel       $18, $0, .L0043DC90
    /* 33DCC0 0043DCC0 0400518E */   lw        $17, 0x4($18)
    /* 33DCC4 0043DCC4 71000F3C */  lui        $15, %hi(D_00710070)
  .L0043DCC8:
    /* 33DCC8 0043DCC8 7000E48D */  lw         $4, %lo(D_00710070)($15)
    /* 33DCCC 0043DCCC 3C008F8C */  lw         $15, 0x3C($4)
    /* 33DCD0 0043DCD0 0300E011 */  beqz       $15, .L0043DCE0
    /* 33DCD4 0043DCD4 00000000 */   nop
    /* 33DCD8 0043DCD8 09F8E001 */  jalr       $15
    /* 33DCDC 0043DCDC 00000000 */   nop
  .L0043DCE0:
    /* 33DCE0 0043DCE0 8600040C */  jal        func_00100218
    /* 33DCE4 0043DCE4 2D206002 */   daddu     $4, $19, $0
.size func_0043dc60, 0x88
