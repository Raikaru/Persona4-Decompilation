.section .text
.set noat
.set noreorder
glabel func_004f3d28
    /* 3F3D28 004F3D28 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F3D2C 004F3D2C 0000B0FF */  sd         $16, 0x0($29)
    /* 3F3D30 004F3D30 2D808000 */  daddu      $16, $4, $0
    /* 3F3D34 004F3D34 0800BFFF */  sd         $31, 0x8($29)
    /* 3F3D38 004F3D38 0300A010 */  beqz       $5, .L004F3D48
    /* 3F3D3C 004F3D3C 2D20A000 */   daddu     $4, $5, $0
    /* 3F3D40 004F3D40 30CC130C */  jal        func_004f30c0
    /* 3F3D44 004F3D44 00000000 */   nop
  .L004F3D48:
    /* 3F3D48 004F3D48 04000052 */  beql       $16, $0, .L004F3D5C
    /* 3F3D4C 004F3D4C 0000B0DF */   ld        $16, 0x0($29)
    /* 3F3D50 004F3D50 14C6130C */  jal        func_004f1850
    /* 3F3D54 004F3D54 2D200002 */   daddu     $4, $16, $0
    /* 3F3D58 004F3D58 0000B0DF */  ld         $16, 0x0($29)
  .L004F3D5C:
    /* 3F3D5C 004F3D5C 0800BFDF */  ld         $31, 0x8($29)
    /* 3F3D60 004F3D60 1CDA1308 */  j          func_004f6870
    /* 3F3D64 004F3D64 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f3d28, 0x40
