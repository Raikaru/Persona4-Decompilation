.section .text
.set noat
.set noreorder
glabel func_0013c6d0
    /* 3C6D0 0013C6D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C6D4 0013C6D4 0000BFFF */  sd         $31, 0x0($29)
    /* 3C6D8 0013C6D8 081A040C */  jal        func_00106820
    /* 3C6DC 0013C6DC 00000000 */   nop
    /* 3C6E0 0013C6E0 24004494 */  lhu        $4, 0x24($2)
    /* 3C6E4 0013C6E4 503D040C */  jal        func_0010f540
    /* 3C6E8 0013C6E8 00000000 */   nop
    /* 3C6EC 0013C6EC 2B100200 */  sltu       $2, $0, $2
    /* 3C6F0 0013C6F0 0000BFDF */  ld         $31, 0x0($29)
    /* 3C6F4 0013C6F4 1000BD27 */  addiu      $29, $29, 0x10
    /* 3C6F8 0013C6F8 0800E003 */  jr         $31
    /* 3C6FC 0013C6FC 00000000 */   nop
.size func_0013c6d0, 0x30
