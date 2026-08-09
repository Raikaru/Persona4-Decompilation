.section .text
.set noat
.set noreorder
glabel func_0050cb68
    /* 40CB68 0050CB68 2D10A000 */  daddu      $2, $5, $0
    /* 40CB6C 0050CB6C 0070013C */  lui        $1, (0x70000000 >> 16)
    /* 40CB70 0050CB70 21202400 */  addu       $4, $1, $4
    /* 40CB74 0050CB74 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40CB78 0050CB78 2D288000 */  daddu      $5, $4, $0
    /* 40CB7C 0050CB7C 2D20C000 */  daddu      $4, $6, $0
    /* 40CB80 0050CB80 0000BFFF */  sd         $31, 0x0($29)
    /* 40CB84 0050CB84 04FE100C */  jal        func_0043f810
    /* 40CB88 0050CB88 2D304000 */   daddu     $6, $2, $0
    /* 40CB8C 0050CB8C 0000BFDF */  ld         $31, 0x0($29)
    /* 40CB90 0050CB90 2D100000 */  daddu      $2, $0, $0
    /* 40CB94 0050CB94 0800E003 */  jr         $31
    /* 40CB98 0050CB98 1000BD27 */   addiu     $29, $29, 0x10
    /* 40CB9C 0050CB9C 00000000 */  nop
.size func_0050cb68, 0x38
