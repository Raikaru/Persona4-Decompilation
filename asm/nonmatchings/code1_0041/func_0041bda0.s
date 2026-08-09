.section .text
.set noat
.set noreorder
glabel func_0041bda0
    /* 31BDA0 0041BDA0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 31BDA4 0041BDA4 1000B1FF */  sd         $17, 0x10($29)
    /* 31BDA8 0041BDA8 0000B0FF */  sd         $16, 0x0($29)
    /* 31BDAC 0041BDAC 2000BFFF */  sd         $31, 0x20($29)
    /* 31BDB0 0041BDB0 2D808000 */  daddu      $16, $4, $0
    /* 31BDB4 0041BDB4 2808028E */  lw         $2, 0x828($16)
    /* 31BDB8 0041BDB8 05004014 */  bnez       $2, .L0041BDD0
    /* 31BDBC 0041BDBC 2D88A000 */   daddu     $17, $5, $0
    /* 31BDC0 0041BDC0 4C08028E */  lw         $2, 0x84C($16)
    /* 31BDC4 0041BDC4 2A105100 */  slt        $2, $2, $17
    /* 31BDC8 0041BDC8 11004050 */  beql       $2, $0, .L0041BE10
    /* 31BDCC 0041BDCC 4808038E */   lw        $3, 0x848($16)
  .L0041BDD0:
    /* 31BDD0 0041BDD0 B26F100C */  jal        func_0041bec8
    /* 31BDD4 0041BDD4 2D200002 */   daddu     $4, $16, $0
    /* 31BDD8 0041BDD8 0010023C */  lui        $2, (0x10002000 >> 16)
    /* 31BDDC 0041BDDC 0040033C */  lui        $3, (0x40000000 >> 16)
    /* 31BDE0 0041BDE0 00204234 */  ori        $2, $2, (0x10002000 & 0xFFFF)
    /* 31BDE4 0041BDE4 2D200002 */  daddu      $4, $16, $0
    /* 31BDE8 0041BDE8 000043AC */  sw         $3, 0x0($2)
    /* 31BDEC 0041BDEC 280800AE */  sw         $0, 0x828($16)
    /* 31BDF0 0041BDF0 CE6E100C */  jal        func_0041bb38
    /* 31BDF4 0041BDF4 2C0803AE */   sw        $3, 0x82C($16)
    /* 31BDF8 0041BDF8 3C100200 */  dsll32     $2, $2, 0
    /* 31BDFC 0041BDFC 3F100200 */  dsra32     $2, $2, 0
    /* 31BE00 0041BE00 20000324 */  addiu      $3, $0, 0x20
    /* 31BE04 0041BE04 480802AE */  sw         $2, 0x848($16)
    /* 31BE08 0041BE08 4C0803AE */  sw         $3, 0x84C($16)
    /* 31BE0C 0041BE0C 4808038E */  lw         $3, 0x848($16)
  .L0041BE10:
    /* 31BE10 0041BE10 23101100 */  negu       $2, $17
    /* 31BE14 0041BE14 2000BFDF */  ld         $31, 0x20($29)
    /* 31BE18 0041BE18 1000B1DF */  ld         $17, 0x10($29)
    /* 31BE1C 0041BE1C 06104300 */  srlv       $2, $3, $2
    /* 31BE20 0041BE20 0000B0DF */  ld         $16, 0x0($29)
    /* 31BE24 0041BE24 0800E003 */  jr         $31
    /* 31BE28 0041BE28 3000BD27 */   addiu     $29, $29, 0x30
    /* 31BE2C 0041BE2C 00000000 */  nop
.size func_0041bda0, 0x90
