.section .text
.set noat
.set noreorder
glabel func_001d6c10
    /* D6C10 001D6C10 C0FFBD27 */  addiu      $29, $29, -0x40
    /* D6C14 001D6C14 3000BFFF */  sd         $31, 0x30($29)
    /* D6C18 001D6C18 2000B27F */  sq         $18, 0x20($29)
    /* D6C1C 001D6C1C 1000B17F */  sq         $17, 0x10($29)
    /* D6C20 001D6C20 0000B07F */  sq         $16, 0x0($29)
    /* D6C24 001D6C24 2D908000 */  daddu      $18, $4, $0
    /* D6C28 001D6C28 2D880000 */  daddu      $17, $0, $0
    /* D6C2C 001D6C2C 1C000010 */  b          .L001D6CA0
    /* D6C30 001D6C30 00000000 */   nop
  .L001D6C34:
    /* D6C34 001D6C34 80101100 */  sll        $2, $17, 2
    /* D6C38 001D6C38 21104202 */  addu       $2, $18, $2
    /* D6C3C 001D6C3C 0000508C */  lw         $16, 0x0($2)
    /* D6C40 001D6C40 2D200002 */  daddu      $4, $16, $0
    /* D6C44 001D6C44 205A070C */  jal        func_001d6880
    /* D6C48 001D6C48 00000000 */   nop
    /* D6C4C 001D6C4C 2000038E */  lw         $3, 0x20($16)
    /* D6C50 001D6C50 03006010 */  beqz       $3, .L001D6C60
    /* D6C54 001D6C54 00000000 */   nop
    /* D6C58 001D6C58 1C00028E */  lw         $2, 0x1C($16)
    /* D6C5C 001D6C5C 1C0062AC */  sw         $2, 0x1C($3)
  .L001D6C60:
    /* D6C60 001D6C60 1C00038E */  lw         $3, 0x1C($16)
    /* D6C64 001D6C64 05006010 */  beqz       $3, .L001D6C7C
    /* D6C68 001D6C68 00000000 */   nop
    /* D6C6C 001D6C6C 2000028E */  lw         $2, 0x20($16)
    /* D6C70 001D6C70 200062AC */  sw         $2, 0x20($3)
    /* D6C74 001D6C74 04000010 */  b          .L001D6C88
    /* D6C78 001D6C78 00000000 */   nop
  .L001D6C7C:
    /* D6C7C 001D6C7C 2000038E */  lw         $3, 0x20($16)
    /* D6C80 001D6C80 ACB3828F */  lw         $2, -0x4C54($28)
    /* D6C84 001D6C84 B80143AC */  sw         $3, 0x1B8($2)
  .L001D6C88:
    /* D6C88 001D6C88 2D200002 */  daddu      $4, $16, $0
    /* D6C8C 001D6C8C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* D6C90 001D6C90 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* D6C94 001D6C94 09F84000 */  jalr       $2
    /* D6C98 001D6C98 00000000 */   nop
    /* D6C9C 001D6C9C 01003126 */  addiu      $17, $17, 0x1
  .L001D6CA0:
    /* D6CA0 001D6CA0 3000222E */  sltiu      $2, $17, 0x30
    /* D6CA4 001D6CA4 E3FF4014 */  bnez       $2, .L001D6C34
    /* D6CA8 001D6CA8 00000000 */   nop
    /* D6CAC 001D6CAC 2D204002 */  daddu      $4, $18, $0
    /* D6CB0 001D6CB0 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* D6CB4 001D6CB4 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* D6CB8 001D6CB8 09F84000 */  jalr       $2
    /* D6CBC 001D6CBC 00000000 */   nop
    /* D6CC0 001D6CC0 3000BFDF */  ld         $31, 0x30($29)
    /* D6CC4 001D6CC4 2000B27B */  lq         $18, 0x20($29)
    /* D6CC8 001D6CC8 1000B17B */  lq         $17, 0x10($29)
    /* D6CCC 001D6CCC 0000B07B */  lq         $16, 0x0($29)
    /* D6CD0 001D6CD0 4000BD27 */  addiu      $29, $29, 0x40
    /* D6CD4 001D6CD4 0800E003 */  jr         $31
    /* D6CD8 001D6CD8 00000000 */   nop
    /* D6CDC 001D6CDC 00000000 */  nop
.size func_001d6c10, 0xd0
