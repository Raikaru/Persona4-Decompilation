.section .text
.set noat
.set noreorder
glabel func_003dd620
    /* 2DD620 003DD620 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2DD624 003DD624 2000BFFF */  sd         $31, 0x20($29)
    /* 2DD628 003DD628 1000B17F */  sq         $17, 0x10($29)
    /* 2DD62C 003DD62C 0000B07F */  sq         $16, 0x0($29)
    /* 2DD630 003DD630 2D888000 */  daddu      $17, $4, $0
    /* 2DD634 003DD634 2D80A000 */  daddu      $16, $5, $0
    /* 2DD638 003DD638 08770F0C */  jal        func_003ddc20
    /* 2DD63C 003DD63C 2D200002 */   daddu     $4, $16, $0
    /* 2DD640 003DD640 03004010 */  beqz       $2, .L003DD650
    /* 2DD644 003DD644 00000000 */   nop
    /* 2DD648 003DD648 1A000010 */  b          .L003DD6B4
    /* 2DD64C 003DD64C 07000224 */   addiu     $2, $0, 0x7
  .L003DD650:
    /* 2DD650 003DD650 0C00248E */  lw         $4, 0xC($17)
    /* 2DD654 003DD654 05008010 */  beqz       $4, .L003DD66C
    /* 2DD658 003DD658 00000000 */   nop
    /* 2DD65C 003DD65C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2DD660 003DD660 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2DD664 003DD664 09F84000 */  jalr       $2
    /* 2DD668 003DD668 00000000 */   nop
  .L003DD66C:
    /* 2DD66C 003DD66C 8800023C */  lui        $2, %hi(D_008873D4)
    /* 2DD670 003DD670 D473428C */  lw         $2, %lo(D_008873D4)($2)
    /* 2DD674 003DD674 09F84000 */  jalr       $2
    /* 2DD678 003DD678 2D200002 */   daddu     $4, $16, $0
    /* 2DD67C 003DD67C 01004424 */  addiu      $4, $2, 0x1
    /* 2DD680 003DD680 0400023C */  lui        $2, (0x401BE >> 16)
    /* 2DD684 003DD684 BE014534 */  ori        $5, $2, (0x401BE & 0xFFFF)
    /* 2DD688 003DD688 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 2DD68C 003DD68C E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 2DD690 003DD690 09F84000 */  jalr       $2
    /* 2DD694 003DD694 00000000 */   nop
    /* 2DD698 003DD698 0C0022AE */  sw         $2, 0xC($17)
    /* 2DD69C 003DD69C 8800023C */  lui        $2, %hi(D_008873AC)
    /* 2DD6A0 003DD6A0 0C00248E */  lw         $4, 0xC($17)
    /* 2DD6A4 003DD6A4 AC73428C */  lw         $2, %lo(D_008873AC)($2)
    /* 2DD6A8 003DD6A8 09F84000 */  jalr       $2
    /* 2DD6AC 003DD6AC 2D280002 */   daddu     $5, $16, $0
    /* 2DD6B0 003DD6B0 01000224 */  addiu      $2, $0, 0x1
  .L003DD6B4:
    /* 2DD6B4 003DD6B4 2000BFDF */  ld         $31, 0x20($29)
    /* 2DD6B8 003DD6B8 1000B17B */  lq         $17, 0x10($29)
    /* 2DD6BC 003DD6BC 0000B07B */  lq         $16, 0x0($29)
    /* 2DD6C0 003DD6C0 0800E003 */  jr         $31
    /* 2DD6C4 003DD6C4 3000BD27 */   addiu     $29, $29, 0x30
    /* 2DD6C8 003DD6C8 00000000 */  nop
    /* 2DD6CC 003DD6CC 00000000 */  nop
.size func_003dd620, 0xb0
