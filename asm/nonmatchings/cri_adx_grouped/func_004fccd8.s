.section .text
.set noat
.set noreorder
glabel func_004fccd8
    /* 3FCCD8 004FCCD8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FCCDC 004FCCDC 48018724 */  addiu      $7, $4, 0x148
    /* 3FCCE0 004FCCE0 0000BFFF */  sd         $31, 0x0($29)
    /* 3FCCE4 004FCCE4 2D40C000 */  daddu      $8, $6, $0
    /* 3FCCE8 004FCCE8 0800E28C */  lw         $2, 0x8($7)
    /* 3FCCEC 004FCCEC 0400E68C */  lw         $6, 0x4($7)
    /* 3FCCF0 004FCCF0 0000E48C */  lw         $4, 0x0($7)
    /* 3FCCF4 004FCCF4 2330C200 */  subu       $6, $6, $2
    /* 3FCCF8 004FCCF8 0000BFDF */  ld         $31, 0x0($29)
    /* 3FCCFC 004FCCFC 2A180601 */  slt        $3, $8, $6
    /* 3FCD00 004FCD00 21208200 */  addu       $4, $4, $2
    /* 3FCD04 004FCD04 0B300301 */  movn       $6, $8, $3
    /* 3FCD08 004FCD08 21104600 */  addu       $2, $2, $6
    /* 3FCD0C 004FCD0C 0800E2AC */  sw         $2, 0x8($7)
    /* 3FCD10 004FCD10 04FE1008 */  j          func_0043f810
    /* 3FCD14 004FCD14 1000BD27 */   addiu     $29, $29, 0x10
.size func_004fccd8, 0x40
