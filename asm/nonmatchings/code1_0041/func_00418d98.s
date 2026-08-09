.section .text
.set noat
.set noreorder
glabel func_00418d98
    /* 318D98 00418D98 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 318D9C 00418D9C 1000B1FF */  sd         $17, 0x10($29)
    /* 318DA0 00418DA0 2D888000 */  daddu      $17, $4, $0
    /* 318DA4 00418DA4 0000B0FF */  sd         $16, 0x0($29)
    /* 318DA8 00418DA8 0100B030 */  andi       $16, $5, 0x1
    /* 318DAC 00418DAC 28000424 */  addiu      $4, $0, 0x28
    /* 318DB0 00418DB0 18100402 */  mult       $2, $16, $4
    /* 318DB4 00418DB4 2000BFFF */  sd         $31, 0x20($29)
    /* 318DB8 00418DB8 D05E100C */  jal        func_00417b40
    /* 318DBC 00418DBC 21205100 */   addu      $4, $2, $17
    /* 318DC0 00418DC0 05000012 */  beqz       $16, .L00418DD8
    /* 318DC4 00418DC4 00000000 */   nop
    /* 318DC8 00418DC8 AC5F100C */  jal        func_00417eb0
    /* 318DCC 00418DCC C0012426 */   addiu     $4, $17, 0x1C0
    /* 318DD0 00418DD0 04000010 */  b          .L00418DE4
    /* 318DD4 00418DD4 2000BFDF */   ld        $31, 0x20($29)
  .L00418DD8:
    /* 318DD8 00418DD8 AC5F100C */  jal        func_00417eb0
    /* 318DDC 00418DDC 50002426 */   addiu     $4, $17, 0x50
    /* 318DE0 00418DE0 2000BFDF */  ld         $31, 0x20($29)
  .L00418DE4:
    /* 318DE4 00418DE4 1000B1DF */  ld         $17, 0x10($29)
    /* 318DE8 00418DE8 0000B0DF */  ld         $16, 0x0($29)
    /* 318DEC 00418DEC 0800E003 */  jr         $31
    /* 318DF0 00418DF0 3000BD27 */   addiu     $29, $29, 0x30
    /* 318DF4 00418DF4 00000000 */  nop
.size func_00418d98, 0x60
