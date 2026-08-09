.section .text
.set noat
.set noreorder
glabel func_0051fd30
    /* 41FD30 0051FD30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41FD34 0051FD34 0000B0FF */  sd         $16, 0x0($29)
    /* 41FD38 0051FD38 0800BFFF */  sd         $31, 0x8($29)
    /* 41FD3C 0051FD3C 88AE100C */  jal        func_0042ba20
    /* 41FD40 0051FD40 2D808000 */   daddu     $16, $4, $0
    /* 41FD44 0051FD44 0010053C */  lui        $5, (0x1000F520 >> 16)
    /* 41FD48 0051FD48 0100073C */  lui        $7, (0x10000 >> 16)
    /* 41FD4C 0051FD4C 20F5A534 */  ori        $5, $5, (0x1000F520 & 0xFFFF)
    /* 41FD50 0051FD50 0010063C */  lui        $6, (0x1000F590 >> 16)
    /* 41FD54 0051FD54 0000A28C */  lw         $2, 0x0($5)
    /* 41FD58 0051FD58 0010043C */  lui        $4, (0x1000B400 >> 16)
    /* 41FD5C 0051FD5C 90F5C634 */  ori        $6, $6, (0x1000F590 & 0xFFFF)
    /* 41FD60 0051FD60 00B48434 */  ori        $4, $4, (0x1000B400 & 0xFFFF)
    /* 41FD64 0051FD64 25104700 */  or         $2, $2, $7
    /* 41FD68 0051FD68 FEFF033C */  lui        $3, (0xFFFEFFFF >> 16)
    /* 41FD6C 0051FD6C 0000C2AC */  sw         $2, 0x0($6)
    /* 41FD70 0051FD70 FFFF6334 */  ori        $3, $3, (0xFFFEFFFF & 0xFFFF)
    /* 41FD74 0051FD74 000090AC */  sw         $16, 0x0($4)
    /* 41FD78 0051FD78 0800BFDF */  ld         $31, 0x8($29)
    /* 41FD7C 0051FD7C 0000A28C */  lw         $2, 0x0($5)
    /* 41FD80 0051FD80 0000B0DF */  ld         $16, 0x0($29)
    /* 41FD84 0051FD84 24104300 */  and        $2, $2, $3
    /* 41FD88 0051FD88 0000C2AC */  sw         $2, 0x0($6)
    /* 41FD8C 0051FD8C 9CAE1008 */  j          func_0042ba70
    /* 41FD90 0051FD90 1000BD27 */   addiu     $29, $29, 0x10
    /* 41FD94 0051FD94 00000000 */  nop
.size func_0051fd30, 0x68
