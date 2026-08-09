.section .text
.set noat
.set noreorder
glabel func_001d3ba0
    /* D3BA0 001D3BA0 70FFBD27 */  addiu      $29, $29, -0x90
    /* D3BA4 001D3BA4 2000BFFF */  sd         $31, 0x20($29)
    /* D3BA8 001D3BA8 1000B17F */  sq         $17, 0x10($29)
    /* D3BAC 001D3BAC 0000B07F */  sq         $16, 0x0($29)
    /* D3BB0 001D3BB0 ACB3828F */  lw         $2, -0x4C54($28)
    /* D3BB4 001D3BB4 7001428C */  lw         $2, 0x170($2)
    /* D3BB8 001D3BB8 3000508C */  lw         $16, 0x30($2)
    /* D3BBC 001D3BBC 2D200002 */  daddu      $4, $16, $0
    /* D3BC0 001D3BC0 7000A527 */  addiu      $5, $29, 0x70
    /* D3BC4 001D3BC4 3000A627 */  addiu      $6, $29, 0x30
    /* D3BC8 001D3BC8 2D380000 */  daddu      $7, $0, $0
    /* D3BCC 001D3BCC FC53060C */  jal        func_00194ff0
    /* D3BD0 001D3BD0 00000000 */   nop
    /* D3BD4 001D3BD4 2D200002 */  daddu      $4, $16, $0
    /* D3BD8 001D3BD8 DC5A060C */  jal        func_00196b70
    /* D3BDC 001D3BDC 00000000 */   nop
    /* D3BE0 001D3BE0 2D200002 */  daddu      $4, $16, $0
    /* D3BE4 001D3BE4 E85A060C */  jal        func_00196ba0
    /* D3BE8 001D3BE8 00000000 */   nop
    /* D3BEC 001D3BEC 2D200002 */  daddu      $4, $16, $0
    /* D3BF0 001D3BF0 7000A527 */  addiu      $5, $29, 0x70
    /* D3BF4 001D3BF4 B853060C */  jal        func_00194ee0
    /* D3BF8 001D3BF8 00000000 */   nop
    /* D3BFC 001D3BFC 2D200002 */  daddu      $4, $16, $0
    /* D3C00 001D3C00 3000A527 */  addiu      $5, $29, 0x30
    /* D3C04 001D3C04 C453060C */  jal        func_00194f10
    /* D3C08 001D3C08 00000000 */   nop
    /* D3C0C 001D3C0C 4000A427 */  addiu      $4, $29, 0x40
    /* D3C10 001D3C10 6100053C */  lui        $5, %hi(D_00609470)
    /* D3C14 001D3C14 7094A524 */  addiu      $5, $5, %lo(D_00609470)
    /* D3C18 001D3C18 03000624 */  addiu      $6, $0, 0x3
    /* D3C1C 001D3C1C 3000A727 */  addiu      $7, $29, 0x30
    /* D3C20 001D3C20 D0720F0C */  jal        func_003dcb40
    /* D3C24 001D3C24 00000000 */   nop
    /* D3C28 001D3C28 2D880000 */  daddu      $17, $0, $0
    /* D3C2C 001D3C2C 27000010 */  b          .L001D3CCC
    /* D3C30 001D3C30 00000000 */   nop
  .L001D3C34:
    /* D3C34 001D3C34 FFFF2332 */  andi       $3, $17, 0xFFFF
    /* D3C38 001D3C38 80100300 */  sll        $2, $3, 2
    /* D3C3C 001D3C3C 21108200 */  addu       $2, $4, $2
    /* D3C40 001D3C40 480C428C */  lw         $2, 0xC48($2)
    /* D3C44 001D3C44 3000508C */  lw         $16, 0x30($2)
    /* D3C48 001D3C48 40100300 */  sll        $2, $3, 1
    /* D3C4C 001D3C4C 21104300 */  addu       $2, $2, $3
    /* D3C50 001D3C50 80100200 */  sll        $2, $2, 2
    /* D3C54 001D3C54 21105D00 */  addu       $2, $2, $29
    /* D3C58 001D3C58 40004224 */  addiu      $2, $2, 0x40
    /* D3C5C 001D3C5C 7000A1C7 */  lwc1       $f1, 0x70($29)
    /* D3C60 001D3C60 000040C4 */  lwc1       $f0, 0x0($2)
    /* D3C64 001D3C64 00080046 */  add.s      $f0, $f1, $f0
    /* D3C68 001D3C68 8000A0E7 */  swc1       $f0, 0x80($29)
    /* D3C6C 001D3C6C 040041C4 */  lwc1       $f1, 0x4($2)
    /* D3C70 001D3C70 7400A0C7 */  lwc1       $f0, 0x74($29)
    /* D3C74 001D3C74 00000146 */  add.s      $f0, $f0, $f1
    /* D3C78 001D3C78 8400A0E7 */  swc1       $f0, 0x84($29)
    /* D3C7C 001D3C7C 080041C4 */  lwc1       $f1, 0x8($2)
    /* D3C80 001D3C80 7800A0C7 */  lwc1       $f0, 0x78($29)
    /* D3C84 001D3C84 00000146 */  add.s      $f0, $f0, $f1
    /* D3C88 001D3C88 8800A0E7 */  swc1       $f0, 0x88($29)
    /* D3C8C 001D3C8C 2D200002 */  daddu      $4, $16, $0
    /* D3C90 001D3C90 DC5A060C */  jal        func_00196b70
    /* D3C94 001D3C94 00000000 */   nop
    /* D3C98 001D3C98 2D200002 */  daddu      $4, $16, $0
    /* D3C9C 001D3C9C E85A060C */  jal        func_00196ba0
    /* D3CA0 001D3CA0 00000000 */   nop
    /* D3CA4 001D3CA4 2D200002 */  daddu      $4, $16, $0
    /* D3CA8 001D3CA8 8000A527 */  addiu      $5, $29, 0x80
    /* D3CAC 001D3CAC B853060C */  jal        func_00194ee0
    /* D3CB0 001D3CB0 00000000 */   nop
    /* D3CB4 001D3CB4 2D200002 */  daddu      $4, $16, $0
    /* D3CB8 001D3CB8 3000A527 */  addiu      $5, $29, 0x30
    /* D3CBC 001D3CBC C453060C */  jal        func_00194f10
    /* D3CC0 001D3CC0 00000000 */   nop
    /* D3CC4 001D3CC4 01002226 */  addiu      $2, $17, 0x1
    /* D3CC8 001D3CC8 FFFF5130 */  andi       $17, $2, 0xFFFF
  .L001D3CCC:
    /* D3CCC 001D3CCC ACB3848F */  lw         $4, -0x4C54($28)
    /* D3CD0 001D3CD0 FFFF2332 */  andi       $3, $17, 0xFFFF
    /* D3CD4 001D3CD4 580C8294 */  lhu        $2, 0xC58($4)
    /* D3CD8 001D3CD8 2A106200 */  slt        $2, $3, $2
    /* D3CDC 001D3CDC D5FF4014 */  bnez       $2, .L001D3C34
    /* D3CE0 001D3CE0 00000000 */   nop
    /* D3CE4 001D3CE4 01000224 */  addiu      $2, $0, 0x1
    /* D3CE8 001D3CE8 2000BFDF */  ld         $31, 0x20($29)
    /* D3CEC 001D3CEC 1000B17B */  lq         $17, 0x10($29)
    /* D3CF0 001D3CF0 0000B07B */  lq         $16, 0x0($29)
    /* D3CF4 001D3CF4 9000BD27 */  addiu      $29, $29, 0x90
    /* D3CF8 001D3CF8 0800E003 */  jr         $31
    /* D3CFC 001D3CFC 00000000 */   nop
.size func_001d3ba0, 0x160
