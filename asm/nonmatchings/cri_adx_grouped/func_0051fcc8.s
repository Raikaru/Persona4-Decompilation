.section .text
.set noat
.set noreorder
glabel func_0051fcc8
    /* 41FCC8 0051FCC8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41FCCC 0051FCCC 0000B0FF */  sd         $16, 0x0($29)
    /* 41FCD0 0051FCD0 0800BFFF */  sd         $31, 0x8($29)
    /* 41FCD4 0051FCD4 88AE100C */  jal        func_0042ba20
    /* 41FCD8 0051FCD8 2D808000 */   daddu     $16, $4, $0
    /* 41FCDC 0051FCDC 0010053C */  lui        $5, (0x1000F520 >> 16)
    /* 41FCE0 0051FCE0 0100073C */  lui        $7, (0x10000 >> 16)
    /* 41FCE4 0051FCE4 20F5A534 */  ori        $5, $5, (0x1000F520 & 0xFFFF)
    /* 41FCE8 0051FCE8 0010063C */  lui        $6, (0x1000F590 >> 16)
    /* 41FCEC 0051FCEC 0000A28C */  lw         $2, 0x0($5)
    /* 41FCF0 0051FCF0 0010043C */  lui        $4, (0x1000B000 >> 16)
    /* 41FCF4 0051FCF4 90F5C634 */  ori        $6, $6, (0x1000F590 & 0xFFFF)
    /* 41FCF8 0051FCF8 00B08434 */  ori        $4, $4, (0x1000B000 & 0xFFFF)
    /* 41FCFC 0051FCFC 25104700 */  or         $2, $2, $7
    /* 41FD00 0051FD00 FEFF033C */  lui        $3, (0xFFFEFFFF >> 16)
    /* 41FD04 0051FD04 0000C2AC */  sw         $2, 0x0($6)
    /* 41FD08 0051FD08 FFFF6334 */  ori        $3, $3, (0xFFFEFFFF & 0xFFFF)
    /* 41FD0C 0051FD0C 000090AC */  sw         $16, 0x0($4)
    /* 41FD10 0051FD10 0800BFDF */  ld         $31, 0x8($29)
    /* 41FD14 0051FD14 0000A28C */  lw         $2, 0x0($5)
    /* 41FD18 0051FD18 0000B0DF */  ld         $16, 0x0($29)
    /* 41FD1C 0051FD1C 24104300 */  and        $2, $2, $3
    /* 41FD20 0051FD20 0000C2AC */  sw         $2, 0x0($6)
    /* 41FD24 0051FD24 9CAE1008 */  j          func_0042ba70
    /* 41FD28 0051FD28 1000BD27 */   addiu     $29, $29, 0x10
    /* 41FD2C 0051FD2C 00000000 */  nop
.size func_0051fcc8, 0x68
