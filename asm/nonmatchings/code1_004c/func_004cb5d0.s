.section .text
.set noat
.set noreorder
glabel func_004cb5d0
    /* 3CB5D0 004CB5D0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3CB5D4 004CB5D4 7200033C */  lui        $3, %hi(D_007199D0)
    /* 3CB5D8 004CB5D8 0800B1FF */  sd         $17, 0x8($29)
    /* 3CB5DC 004CB5DC D0997124 */  addiu      $17, $3, %lo(D_007199D0)
    /* 3CB5E0 004CB5E0 0000228E */  lw         $2, 0x0($17)
    /* 3CB5E4 004CB5E4 0000B0FF */  sd         $16, 0x0($29)
    /* 3CB5E8 004CB5E8 FFFF4224 */  addiu      $2, $2, -0x1
    /* 3CB5EC 004CB5EC 1000BFFF */  sd         $31, 0x10($29)
    /* 3CB5F0 004CB5F0 0B004014 */  bnez       $2, .L004CB620
    /* 3CB5F4 004CB5F4 000022AE */   sw        $2, 0x0($17)
    /* 3CB5F8 004CB5F8 7200103C */  lui        $16, %hi(D_00719A28)
    /* 3CB5FC 004CB5FC 289A1026 */  addiu      $16, $16, %lo(D_00719A28)
    /* 3CB600 004CB600 6A2F130C */  jal        func_004cbda8
    /* 3CB604 004CB604 0000048E */   lw        $4, 0x0($16)
    /* 3CB608 004CB608 B485100C */  jal        func_004216d0
    /* 3CB60C 004CB60C 0000038E */   lw        $3, 0x0($16)
    /* 3CB610 004CB610 7200033C */  lui        $3, %hi(D_007212C0)
    /* 3CB614 004CB614 C012658C */  lw         $5, %lo(D_007212C0)($3)
    /* 3CB618 004CB618 9C85100C */  jal        func_00421670
    /* 3CB61C 004CB61C 2D204000 */   daddu     $4, $2, $0
  .L004CB620:
    /* 3CB620 004CB620 0000228E */  lw         $2, 0x0($17)
    /* 3CB624 004CB624 01004204 */  bltzl      $2, .L004CB62C
    /* 3CB628 004CB628 000020AE */   sw        $0, 0x0($17)
  .L004CB62C:
    /* 3CB62C 004CB62C 0000B0DF */  ld         $16, 0x0($29)
    /* 3CB630 004CB630 0800B1DF */  ld         $17, 0x8($29)
    /* 3CB634 004CB634 1000BFDF */  ld         $31, 0x10($29)
    /* 3CB638 004CB638 0800E003 */  jr         $31
    /* 3CB63C 004CB63C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004cb5d0, 0x70
