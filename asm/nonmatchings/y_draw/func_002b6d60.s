.section .text
.set noat
.set noreorder
glabel func_002b6d60
    /* 1B6D60 002B6D60 74B5838F */  lw         $3, -0x4A8C($28)
    /* 1B6D64 002B6D64 3800668C */  lw         $6, 0x38($3)
    /* 1B6D68 002B6D68 3C1C0400 */  dsll32     $3, $4, 16
    /* 1B6D6C 002B6D6C 3F1C0300 */  dsra32     $3, $3, 16
    /* 1B6D70 002B6D70 002A0300 */  sll        $5, $3, 8
    /* 1B6D74 002B6D74 803F043C */  lui        $4, (0x3F800000 >> 16)
    /* 1B6D78 002B6D78 2118C500 */  addu       $3, $6, $5
    /* 1B6D7C 002B6D7C B00064AC */  sw         $4, 0xB0($3)
    /* 1B6D80 002B6D80 A40064AC */  sw         $4, 0xA4($3)
    /* 1B6D84 002B6D84 74B5838F */  lw         $3, -0x4A8C($28)
    /* 1B6D88 002B6D88 3800638C */  lw         $3, 0x38($3)
    /* 1B6D8C 002B6D8C FF000424 */  addiu      $4, $0, 0xFF
    /* 1B6D90 002B6D90 21186500 */  addu       $3, $3, $5
    /* 1B6D94 002B6D94 720064A0 */  sb         $4, 0x72($3)
    /* 1B6D98 002B6D98 0800E003 */  jr         $31
    /* 1B6D9C 002B6D9C 00000000 */   nop
.size func_002b6d60, 0x40
