.section .text
.set noat
.set noreorder
glabel func_004d1b88
    /* 3D1B88 004D1B88 72000D3C */  lui        $13, %hi(D_00723F18)
    /* 3D1B8C 004D1B8C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D1B90 004D1B90 183FA98D */  lw         $9, %lo(D_00723F18)($13)
    /* 3D1B94 004D1B94 2D50A000 */  daddu      $10, $5, $0
    /* 3D1B98 004D1B98 0000B0FF */  sd         $16, 0x0($29)
    /* 3D1B9C 004D1B9C 2D800000 */  daddu      $16, $0, $0
    /* 3D1BA0 004D1BA0 0800BFFF */  sd         $31, 0x8($29)
    /* 3D1BA4 004D1BA4 2D608000 */  daddu      $12, $4, $0
    /* 3D1BA8 004D1BA8 2D58C000 */  daddu      $11, $6, $0
    /* 3D1BAC 004D1BAC 2D40E000 */  daddu      $8, $7, $0
    /* 3D1BB0 004D1BB0 1B002019 */  blez       $9, .L004D1C20
    /* 3D1BB4 004D1BB4 2D280000 */   daddu     $5, $0, $0
    /* 3D1BB8 004D1BB8 7200023C */  lui        $2, %hi(D_00723F14)
    /* 3D1BBC 004D1BBC 7200043C */  lui        $4, %hi(D_00723F28)
    /* 3D1BC0 004D1BC0 143F4724 */  addiu      $7, $2, %lo(D_00723F14)
    /* 3D1BC4 004D1BC4 283F8424 */  addiu      $4, $4, %lo(D_00723F28)
    /* 3D1BC8 004D1BC8 0000E38C */  lw         $3, 0x0($7)
    /* 3D1BCC 004D1BCC 40100300 */  sll        $2, $3, 1
    /* 3D1BD0 004D1BD0 21104300 */  addu       $2, $2, $3
    /* 3D1BD4 004D1BD4 40110200 */  sll        $2, $2, 5
    /* 3D1BD8 004D1BD8 21804400 */  addu       $16, $2, $4
    /* 3D1BDC 004D1BDC 00000382 */  lb         $3, 0x0($16)
    /* 3D1BE0 004D1BE0 10006010 */  beqz       $3, .L004D1C24
    /* 3D1BE4 004D1BE4 183FA38D */   lw        $3, %lo(D_00723F18)($13)
    /* 3D1BE8 004D1BE8 2D302001 */  daddu      $6, $9, $0
    /* 3D1BEC 004D1BEC 0100A524 */  addiu      $5, $5, 0x1
  .L004D1BF0:
    /* 3D1BF0 004D1BF0 2A10A600 */  slt        $2, $5, $6
    /* 3D1BF4 004D1BF4 0B004010 */  beqz       $2, .L004D1C24
    /* 3D1BF8 004D1BF8 183FA38D */   lw        $3, %lo(D_00723F18)($13)
    /* 3D1BFC 004D1BFC 0000E28C */  lw         $2, 0x0($7)
    /* 3D1C00 004D1C00 21104500 */  addu       $2, $2, $5
    /* 3D1C04 004D1C04 40180200 */  sll        $3, $2, 1
    /* 3D1C08 004D1C08 21186200 */  addu       $3, $3, $2
    /* 3D1C0C 004D1C0C 40190300 */  sll        $3, $3, 5
    /* 3D1C10 004D1C10 21806400 */  addu       $16, $3, $4
    /* 3D1C14 004D1C14 00000282 */  lb         $2, 0x0($16)
    /* 3D1C18 004D1C18 F5FF4054 */  bnel       $2, $0, .L004D1BF0
    /* 3D1C1C 004D1C1C 0100A524 */   addiu     $5, $5, 0x1
  .L004D1C20:
    /* 3D1C20 004D1C20 183FA38D */  lw         $3, %lo(D_00723F18)($13)
  .L004D1C24:
    /* 3D1C24 004D1C24 0800A310 */  beq        $5, $3, .L004D1C48
    /* 3D1C28 004D1C28 2D100000 */   daddu     $2, $0, $0
    /* 3D1C2C 004D1C2C 2D288001 */  daddu      $5, $12, $0
    /* 3D1C30 004D1C30 2D304001 */  daddu      $6, $10, $0
    /* 3D1C34 004D1C34 2D386001 */  daddu      $7, $11, $0
    /* 3D1C38 004D1C38 6A46130C */  jal        func_004d19a8
    /* 3D1C3C 004D1C3C 2D200002 */   daddu     $4, $16, $0
    /* 3D1C40 004D1C40 030000A2 */  sb         $0, 0x3($16)
    /* 3D1C44 004D1C44 2D100002 */  daddu      $2, $16, $0
  .L004D1C48:
    /* 3D1C48 004D1C48 0000B0DF */  ld         $16, 0x0($29)
    /* 3D1C4C 004D1C4C 0800BFDF */  ld         $31, 0x8($29)
    /* 3D1C50 004D1C50 0800E003 */  jr         $31
    /* 3D1C54 004D1C54 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d1b88, 0xd0
