.section .text
.set noat
.set noreorder
glabel func_003f79b0
    /* 2F79B0 003F79B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2F79B4 003F79B4 0000BFFF */  sd         $31, 0x0($29)
    /* 2F79B8 003F79B8 B0B882DF */  ld         $2, -0x4750($28)
    /* 2F79BC 003F79BC 1E004014 */  bnez       $2, .L003F7A38
    /* 2F79C0 003F79C0 00000000 */   nop
  .L003F79C4:
    /* 2F79C4 003F79C4 6C3C100C */  jal        func_0040f1b0
    /* 2F79C8 003F79C8 00000000 */   nop
    /* 2F79CC 003F79CC 08B9838F */  lw         $3, -0x46F8($28)
    /* 2F79D0 003F79D0 8900043C */  lui        $4, %hi(D_0088BC00)
    /* 2F79D4 003F79D4 00BC8424 */  addiu      $4, $4, %lo(D_0088BC00)
    /* 2F79D8 003F79D8 01006224 */  addiu      $2, $3, 0x1
    /* 2F79DC 003F79DC FF006530 */  andi       $5, $3, 0xFF
    /* 2F79E0 003F79E0 D4CD0F0C */  jal        func_003f3750
    /* 2F79E4 003F79E4 08B982AF */   sw        $2, -0x46F8($28)
    /* 2F79E8 003F79E8 1805100C */  jal        func_00401460
    /* 2F79EC 003F79EC 00000000 */   nop
    /* 2F79F0 003F79F0 8900023C */  lui        $2, %hi(D_0088BFC0)
    /* 2F79F4 003F79F4 C0BF428C */  lw         $2, %lo(D_0088BFC0)($2)
    /* 2F79F8 003F79F8 12004014 */  bnez       $2, .L003F7A44
    /* 2F79FC 003F79FC 00000000 */   nop
    /* 2F7A00 003F7A00 8900023C */  lui        $2, %hi(D_0088BFC4)
    /* 2F7A04 003F7A04 C4BF428C */  lw         $2, %lo(D_0088BFC4)($2)
    /* 2F7A08 003F7A08 0E004014 */  bnez       $2, .L003F7A44
    /* 2F7A0C 003F7A0C 00000000 */   nop
    /* 2F7A10 003F7A10 8900023C */  lui        $2, %hi(D_0088BFC8)
    /* 2F7A14 003F7A14 C8BF428C */  lw         $2, %lo(D_0088BFC8)($2)
    /* 2F7A18 003F7A18 0A004014 */  bnez       $2, .L003F7A44
    /* 2F7A1C 003F7A1C 00000000 */   nop
    /* 2F7A20 003F7A20 8900023C */  lui        $2, %hi(D_0088BFCC)
    /* 2F7A24 003F7A24 CCBF428C */  lw         $2, %lo(D_0088BFCC)($2)
    /* 2F7A28 003F7A28 06004014 */  bnez       $2, .L003F7A44
    /* 2F7A2C 003F7A2C 00000000 */   nop
  .L003F7A30:
    /* 2F7A30 003F7A30 07000010 */  b          .L003F7A50
    /* 2F7A34 003F7A34 01000224 */   addiu     $2, $0, 0x1
  .L003F7A38:
    /* 2F7A38 003F7A38 B0B880FF */  sd         $0, -0x4750($28)
    /* 2F7A3C 003F7A3C E1FF0010 */  b          .L003F79C4
    /* 2F7A40 003F7A40 B8B880AF */   sw        $0, -0x4748($28)
  .L003F7A44:
    /* 2F7A44 003F7A44 01000224 */  addiu      $2, $0, 0x1
    /* 2F7A48 003F7A48 F9FF0010 */  b          .L003F7A30
    /* 2F7A4C 003F7A4C 24B982AF */   sw        $2, -0x46DC($28)
  .L003F7A50:
    /* 2F7A50 003F7A50 0000BFDF */  ld         $31, 0x0($29)
    /* 2F7A54 003F7A54 0800E003 */  jr         $31
    /* 2F7A58 003F7A58 1000BD27 */   addiu     $29, $29, 0x10
    /* 2F7A5C 003F7A5C 00000000 */  nop
.size func_003f79b0, 0xb0
