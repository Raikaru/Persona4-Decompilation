.section .text
.set noat
.set noreorder
glabel func_004f5cd0
    /* 3F5CD0 004F5CD0 01000224 */  addiu      $2, $0, 0x1
    /* 3F5CD4 004F5CD4 0C00A210 */  beq        $5, $2, .L004F5D08
    /* 3F5CD8 004F5CD8 7400023C */   lui       $2, %hi(D_00743A50)
    /* 3F5CDC 004F5CDC 0600A010 */  beqz       $5, .L004F5CF8
    /* 3F5CE0 004F5CE0 503A448C */   lw        $4, %lo(D_00743A50)($2)
    /* 3F5CE4 004F5CE4 02000224 */  addiu      $2, $0, 0x2
    /* 3F5CE8 004F5CE8 0B00A250 */  beql       $5, $2, .L004F5D18
    /* 3F5CEC 004F5CEC 7400023C */   lui       $2, %hi(D_00743A50)
    /* 3F5CF0 004F5CF0 0800E003 */  jr         $31
    /* 3F5CF4 004F5CF4 9CFF0224 */   addiu     $2, $0, -0x64
  .L004F5CF8:
    /* 3F5CF8 004F5CF8 1800838C */  lw         $3, 0x18($4)
    /* 3F5CFC 004F5CFC 09000010 */  b          .L004F5D24
    /* 3F5D00 004F5D00 00046330 */   andi      $3, $3, 0x400
    /* 3F5D04 004F5D04 00000000 */  nop
  .L004F5D08:
    /* 3F5D08 004F5D08 503A448C */  lw         $4, %lo(D_00743A50)($2)
    /* 3F5D0C 004F5D0C 1800838C */  lw         $3, 0x18($4)
    /* 3F5D10 004F5D10 05000010 */  b          .L004F5D28
    /* 3F5D14 004F5D14 01006330 */   andi      $3, $3, 0x1
  .L004F5D18:
    /* 3F5D18 004F5D18 503A448C */  lw         $4, %lo(D_00743A50)($2)
    /* 3F5D1C 004F5D1C 1800838C */  lw         $3, 0x18($4)
    /* 3F5D20 004F5D20 02006330 */  andi       $3, $3, 0x2
  .L004F5D24:
    /* 3F5D24 004F5D24 2B180300 */  sltu       $3, $0, $3
  .L004F5D28:
    /* 3F5D28 004F5D28 0000C3AC */  sw         $3, 0x0($6)
    /* 3F5D2C 004F5D2C 0800E003 */  jr         $31
    /* 3F5D30 004F5D30 2D100000 */   daddu     $2, $0, $0
    /* 3F5D34 004F5D34 00000000 */  nop
.size func_004f5cd0, 0x68
