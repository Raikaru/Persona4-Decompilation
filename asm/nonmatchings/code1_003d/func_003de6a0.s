.section .text
.set noat
.set noreorder
glabel func_003de6a0
    /* 2DE6A0 003DE6A0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2DE6A4 003DE6A4 03000224 */  addiu      $2, $0, 0x3
    /* 2DE6A8 003DE6A8 2000BFFF */  sd         $31, 0x20($29)
    /* 2DE6AC 003DE6AC 1000B17F */  sq         $17, 0x10($29)
    /* 2DE6B0 003DE6B0 0000B07F */  sq         $16, 0x0($29)
    /* 2DE6B4 003DE6B4 2D808000 */  daddu      $16, $4, $0
    /* 2DE6B8 003DE6B8 380082AC */  sw         $2, 0x38($4)
    /* 2DE6BC 003DE6BC 6000848C */  lw         $4, 0x60($4)
    /* 2DE6C0 003DE6C0 6A9D100C */  jal        sceWrite
    /* 2DE6C4 003DE6C4 2D88C000 */   daddu     $17, $6, $0
    /* 2DE6C8 003DE6C8 3000038E */  lw         $3, 0x30($16)
    /* 2DE6CC 003DE6CC 05006010 */  beqz       $3, .L003DE6E4
    /* 2DE6D0 003DE6D0 00000000 */   nop
    /* 2DE6D4 003DE6D4 02004104 */  bgez       $2, .L003DE6E0
    /* 2DE6D8 003DE6D8 00000000 */   nop
    /* 2DE6DC 003DE6DC 2D880000 */  daddu      $17, $0, $0
  .L003DE6E0:
    /* 2DE6E0 003DE6E0 2D102002 */  daddu      $2, $17, $0
  .L003DE6E4:
    /* 2DE6E4 003DE6E4 02000324 */  addiu      $3, $0, 0x2
    /* 2DE6E8 003DE6E8 0F004018 */  blez       $2, .L003DE728
    /* 2DE6EC 003DE6EC 380003AE */   sw        $3, 0x38($16)
    /* 2DE6F0 003DE6F0 100003DE */  ld         $3, 0x10($16)
    /* 2DE6F4 003DE6F4 3C200200 */  dsll32     $4, $2, 0
    /* 2DE6F8 003DE6F8 3F200400 */  dsra32     $4, $4, 0
    /* 2DE6FC 003DE6FC 2D186400 */  daddu      $3, $3, $4
    /* 2DE700 003DE700 100003FE */  sd         $3, 0x10($16)
    /* 2DE704 003DE704 100004DE */  ld         $4, 0x10($16)
    /* 2DE708 003DE708 000003DE */  ld         $3, 0x0($16)
    /* 2DE70C 003DE70C 2A086400 */  slt        $1, $3, $4
    /* 2DE710 003DE710 03002014 */  bnez       $1, .L003DE720
    /* 2DE714 003DE714 00000000 */   nop
  .L003DE718:
    /* 2DE718 003DE718 05000010 */  b          .L003DE730
    /* 2DE71C 003DE71C 2000BFDF */   ld        $31, 0x20($29)
  .L003DE720:
    /* 2DE720 003DE720 FDFF0010 */  b          .L003DE718
    /* 2DE724 003DE724 000004FE */   sd        $4, 0x0($16)
  .L003DE728:
    /* 2DE728 003DE728 2D100000 */  daddu      $2, $0, $0
    /* 2DE72C 003DE72C 2000BFDF */  ld         $31, 0x20($29)
  .L003DE730:
    /* 2DE730 003DE730 1000B17B */  lq         $17, 0x10($29)
    /* 2DE734 003DE734 0000B07B */  lq         $16, 0x0($29)
    /* 2DE738 003DE738 0800E003 */  jr         $31
    /* 2DE73C 003DE73C 3000BD27 */   addiu     $29, $29, 0x30
.size func_003de6a0, 0xa0
