.section .text
.set noat
.set noreorder
glabel func_00149db0
    /* 49DB0 00149DB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 49DB4 00149DB4 1000BFFF */  sd         $31, 0x10($29)
    /* 49DB8 00149DB8 0000B07F */  sq         $16, 0x0($29)
    /* 49DBC 00149DBC 2D808000 */  daddu      $16, $4, $0
    /* 49DC0 00149DC0 0C000424 */  addiu      $4, $0, 0xC
    /* 49DC4 00149DC4 AC14050C */  jal        func_001452b0
    /* 49DC8 00149DC8 00000000 */   nop
    /* 49DCC 00149DCC B09D828F */  lw         $2, -0x6250($28)
    /* 49DD0 00149DD0 2000448C */  lw         $4, 0x20($2)
    /* 49DD4 00149DD4 2D280002 */  daddu      $5, $16, $0
    /* 49DD8 00149DD8 D84E050C */  jal        func_00153b60
    /* 49DDC 00149DDC 00000000 */   nop
    /* 49DE0 00149DE0 1000BFDF */  ld         $31, 0x10($29)
    /* 49DE4 00149DE4 0000B07B */  lq         $16, 0x0($29)
    /* 49DE8 00149DE8 2000BD27 */  addiu      $29, $29, 0x20
    /* 49DEC 00149DEC 0800E003 */  jr         $31
    /* 49DF0 00149DF0 00000000 */   nop
    /* 49DF4 00149DF4 00000000 */  nop
    /* 49DF8 00149DF8 00000000 */  nop
    /* 49DFC 00149DFC 00000000 */  nop
.size func_00149db0, 0x50
