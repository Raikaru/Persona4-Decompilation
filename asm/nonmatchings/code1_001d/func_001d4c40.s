.section .text
.set noat
.set noreorder
glabel func_001d4c40
    /* D4C40 001D4C40 B0FFBD27 */  addiu      $29, $29, -0x50
    /* D4C44 001D4C44 2000BFFF */  sd         $31, 0x20($29)
    /* D4C48 001D4C48 1000B17F */  sq         $17, 0x10($29)
    /* D4C4C 001D4C4C 0000B07F */  sq         $16, 0x0($29)
    /* D4C50 001D4C50 2D88E000 */  daddu      $17, $7, $0
    /* D4C54 001D4C54 0800D024 */  addiu      $16, $6, 0x8
    /* D4C58 001D4C58 03000424 */  addiu      $4, $0, 0x3
    /* D4C5C 001D4C5C 2D280000 */  daddu      $5, $0, $0
    /* D4C60 001D4C60 4000A627 */  addiu      $6, $29, 0x40
    /* D4C64 001D4C64 4C00A727 */  addiu      $7, $29, 0x4C
    /* D4C68 001D4C68 2D400000 */  daddu      $8, $0, $0
    /* D4C6C 001D4C6C 2D480000 */  daddu      $9, $0, $0
    /* D4C70 001D4C70 1058060C */  jal        func_00196040
    /* D4C74 001D4C74 00000000 */   nop
    /* D4C78 001D4C78 04000296 */  lhu        $2, 0x4($16)
    /* D4C7C 001D4C7C 03004014 */  bnez       $2, .L001D4C8C
    /* D4C80 001D4C80 00000000 */   nop
    /* D4C84 001D4C84 04000010 */  b          .L001D4C98
    /* D4C88 001D4C88 00000000 */   nop
  .L001D4C8C:
    /* D4C8C 001D4C8C 00008244 */  mtc1       $2, $f0
    /* D4C90 001D4C90 00000000 */  nop
    /* D4C94 001D4C94 20008046 */  cvt.s.w    $f0, $f0
  .L001D4C98:
    /* D4C98 001D4C98 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* D4C9C 001D4C9C 3C00A2AF */  sw         $2, 0x3C($29)
    /* D4CA0 001D4CA0 3000A0AF */  sw         $0, 0x30($29)
    /* D4CA4 001D4CA4 3400A0AF */  sw         $0, 0x34($29)
    /* D4CA8 001D4CA8 3800A0AF */  sw         $0, 0x38($29)
    /* D4CAC 001D4CAC 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* D4CB0 001D4CB0 00108244 */  mtc1       $2, $f2
    /* D4CB4 001D4CB4 4C00A1C7 */  lwc1       $f1, 0x4C($29)
    /* D4CB8 001D4CB8 42130146 */  mul.s      $f13, $f2, $f1
    /* D4CBC 001D4CBC 06030046 */  mov.s      $f12, $f0
    /* D4CC0 001D4CC0 4000A427 */  addiu      $4, $29, 0x40
    /* D4CC4 001D4CC4 3000A527 */  addiu      $5, $29, 0x30
    /* D4CC8 001D4CC8 2D300002 */  daddu      $6, $16, $0
    /* D4CCC 001D4CCC 2D382002 */  daddu      $7, $17, $0
    /* D4CD0 001D4CD0 2851070C */  jal        func_001d44a0
    /* D4CD4 001D4CD4 00000000 */   nop
    /* D4CD8 001D4CD8 2000BFDF */  ld         $31, 0x20($29)
    /* D4CDC 001D4CDC 1000B17B */  lq         $17, 0x10($29)
    /* D4CE0 001D4CE0 0000B07B */  lq         $16, 0x0($29)
    /* D4CE4 001D4CE4 5000BD27 */  addiu      $29, $29, 0x50
    /* D4CE8 001D4CE8 0800E003 */  jr         $31
    /* D4CEC 001D4CEC 00000000 */   nop
.size func_001d4c40, 0xb0
