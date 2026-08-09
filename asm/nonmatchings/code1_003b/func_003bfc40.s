.section .text
.set noat
.set noreorder
glabel func_003bfc40
    /* 2BFC40 003BFC40 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2BFC44 003BFC44 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2BFC48 003BFC48 1000BFFF */  sd         $31, 0x10($29)
    /* 2BFC4C 003BFC4C 3C00053C */  lui        $5, %hi(func_003be800)
    /* 2BFC50 003BFC50 0000B07F */  sq         $16, 0x0($29)
    /* 2BFC54 003BFC54 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2BFC58 003BFC58 C0B6838F */  lw         $3, -0x4940($28)
    /* 2BFC5C 003BFC5C 2D808000 */  daddu      $16, $4, $0
    /* 2BFC60 003BFC60 00E8A524 */  addiu      $5, $5, %lo(func_003be800)
    /* 2BFC64 003BFC64 21104300 */  addu       $2, $2, $3
    /* 2BFC68 003BFC68 0400448C */  lw         $4, 0x4($2)
    /* 2BFC6C 003BFC6C 30860F0C */  jal        func_003e18c0
    /* 2BFC70 003BFC70 2D300000 */   daddu     $6, $0, $0
    /* 2BFC74 003BFC74 C0B6838F */  lw         $3, -0x4940($28)
    /* 2BFC78 003BFC78 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2BFC7C 003BFC7C E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2BFC80 003BFC80 3C00053C */  lui        $5, %hi(func_003be810)
    /* 2BFC84 003BFC84 10E8A524 */  addiu      $5, $5, %lo(func_003be810)
    /* 2BFC88 003BFC88 21104300 */  addu       $2, $2, $3
    /* 2BFC8C 003BFC8C 0000448C */  lw         $4, 0x0($2)
    /* 2BFC90 003BFC90 30860F0C */  jal        func_003e18c0
    /* 2BFC94 003BFC94 2D300000 */   daddu     $6, $0, $0
    /* 2BFC98 003BFC98 C0B6838F */  lw         $3, -0x4940($28)
    /* 2BFC9C 003BFC9C 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2BFCA0 003BFCA0 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2BFCA4 003BFCA4 21104300 */  addu       $2, $2, $3
    /* 2BFCA8 003BFCA8 BC840F0C */  jal        func_003e12f0
    /* 2BFCAC 003BFCAC 0000448C */   lw        $4, 0x0($2)
    /* 2BFCB0 003BFCB0 C0B6838F */  lw         $3, -0x4940($28)
    /* 2BFCB4 003BFCB4 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2BFCB8 003BFCB8 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2BFCBC 003BFCBC 21104300 */  addu       $2, $2, $3
    /* 2BFCC0 003BFCC0 BC840F0C */  jal        func_003e12f0
    /* 2BFCC4 003BFCC4 0400448C */   lw        $4, 0x4($2)
    /* 2BFCC8 003BFCC8 C0B6858F */  lw         $5, -0x4940($28)
    /* 2BFCCC 003BFCCC 8800043C */  lui        $4, %hi(D_008872E0)
    /* 2BFCD0 003BFCD0 C4B6838F */  lw         $3, -0x493C($28)
    /* 2BFCD4 003BFCD4 E0728424 */  addiu      $4, $4, %lo(D_008872E0)
    /* 2BFCD8 003BFCD8 2D100002 */  daddu      $2, $16, $0
    /* 2BFCDC 003BFCDC 21208500 */  addu       $4, $4, $5
    /* 2BFCE0 003BFCE0 FFFF6324 */  addiu      $3, $3, -0x1
    /* 2BFCE4 003BFCE4 000080AC */  sw         $0, 0x0($4)
    /* 2BFCE8 003BFCE8 040080AC */  sw         $0, 0x4($4)
    /* 2BFCEC 003BFCEC C4B683AF */  sw         $3, -0x493C($28)
    /* 2BFCF0 003BFCF0 1000BFDF */  ld         $31, 0x10($29)
    /* 2BFCF4 003BFCF4 0000B07B */  lq         $16, 0x0($29)
    /* 2BFCF8 003BFCF8 0800E003 */  jr         $31
    /* 2BFCFC 003BFCFC 2000BD27 */   addiu     $29, $29, 0x20
.size func_003bfc40, 0xc0
