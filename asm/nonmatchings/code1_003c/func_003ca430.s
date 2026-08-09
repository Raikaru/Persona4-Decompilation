.section .text
.set noat
.set noreorder
glabel func_003ca430
    /* 2CA430 003CA430 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2CA434 003CA434 3C00063C */  lui        $6, %hi(func_003c4040)
    /* 2CA438 003CA438 1000BFFF */  sd         $31, 0x10($29)
    /* 2CA43C 003CA43C 3C00073C */  lui        $7, %hi(func_003c40d0)
    /* 2CA440 003CA440 0000B07F */  sq         $16, 0x0($29)
    /* 2CA444 003CA444 04000424 */  addiu      $4, $0, 0x4
    /* 2CA448 003CA448 01050524 */  addiu      $5, $0, 0x501
    /* 2CA44C 003CA44C 4040C624 */  addiu      $6, $6, %lo(func_003c4040)
    /* 2CA450 003CA450 D040E724 */  addiu      $7, $7, %lo(func_003c40d0)
    /* 2CA454 003CA454 4CA20F0C */  jal        func_003e8930
    /* 2CA458 003CA458 2D800000 */   daddu     $16, $0, $0
    /* 2CA45C 003CA45C 3C00063C */  lui        $6, %hi(func_003c5510)
    /* 2CA460 003CA460 3C00073C */  lui        $7, %hi(func_003c54a0 + 0x20)
    /* 2CA464 003CA464 25800202 */  or         $16, $16, $2
    /* 2CA468 003CA468 30000424 */  addiu      $4, $0, 0x30
    /* 2CA46C 003CA46C 02050524 */  addiu      $5, $0, 0x502
    /* 2CA470 003CA470 1055C624 */  addiu      $6, $6, %lo(func_003c5510)
    /* 2CA474 003CA474 4CA20F0C */  jal        func_003e8930
    /* 2CA478 003CA478 C054E724 */   addiu     $7, $7, %lo(func_003c54a0 + 0x20)
    /* 2CA47C 003CA47C 3C00063C */  lui        $6, %hi(func_003c1d00)
    /* 2CA480 003CA480 3C00073C */  lui        $7, %hi(func_003c1d20)
    /* 2CA484 003CA484 25800202 */  or         $16, $16, $2
    /* 2CA488 003CA488 04000424 */  addiu      $4, $0, 0x4
    /* 2CA48C 003CA48C 03050524 */  addiu      $5, $0, 0x503
    /* 2CA490 003CA490 001DC624 */  addiu      $6, $6, %lo(func_003c1d00)
    /* 2CA494 003CA494 4CA20F0C */  jal        func_003e8930
    /* 2CA498 003CA498 201DE724 */   addiu     $7, $7, %lo(func_003c1d20)
    /* 2CA49C 003CA49C 3C00063C */  lui        $6, %hi(func_003bfd00)
    /* 2CA4A0 003CA4A0 3C00073C */  lui        $7, %hi(func_003bfc40)
    /* 2CA4A4 003CA4A4 25800202 */  or         $16, $16, $2
    /* 2CA4A8 003CA4A8 08000424 */  addiu      $4, $0, 0x8
    /* 2CA4AC 003CA4AC 04050524 */  addiu      $5, $0, 0x504
    /* 2CA4B0 003CA4B0 00FDC624 */  addiu      $6, $6, %lo(func_003bfd00)
    /* 2CA4B4 003CA4B4 4CA20F0C */  jal        func_003e8930
    /* 2CA4B8 003CA4B8 40FCE724 */   addiu     $7, $7, %lo(func_003bfc40)
    /* 2CA4BC 003CA4BC 3C00063C */  lui        $6, %hi(func_003c3e90)
    /* 2CA4C0 003CA4C0 3C00073C */  lui        $7, %hi(func_003c3e10)
    /* 2CA4C4 003CA4C4 25800202 */  or         $16, $16, $2
    /* 2CA4C8 003CA4C8 04000424 */  addiu      $4, $0, 0x4
    /* 2CA4CC 003CA4CC 05050524 */  addiu      $5, $0, 0x505
    /* 2CA4D0 003CA4D0 903EC624 */  addiu      $6, $6, %lo(func_003c3e90)
    /* 2CA4D4 003CA4D4 4CA20F0C */  jal        func_003e8930
    /* 2CA4D8 003CA4D8 103EE724 */   addiu     $7, $7, %lo(func_003c3e10)
    /* 2CA4DC 003CA4DC 3D00063C */  lui        $6, %hi(func_003c8ca0)
    /* 2CA4E0 003CA4E0 3D00073C */  lui        $7, %hi(func_003c8cc0)
    /* 2CA4E4 003CA4E4 25800202 */  or         $16, $16, $2
    /* 2CA4E8 003CA4E8 2D200000 */  daddu      $4, $0, $0
    /* 2CA4EC 003CA4EC 0A050524 */  addiu      $5, $0, 0x50A
    /* 2CA4F0 003CA4F0 A08CC624 */  addiu      $6, $6, %lo(func_003c8ca0)
    /* 2CA4F4 003CA4F4 4CA20F0C */  jal        func_003e8930
    /* 2CA4F8 003CA4F8 C08CE724 */   addiu     $7, $7, %lo(func_003c8cc0)
    /* 2CA4FC 003CA4FC 3D00063C */  lui        $6, %hi(func_003c95a0)
    /* 2CA500 003CA500 3D00073C */  lui        $7, %hi(func_003c9530)
    /* 2CA504 003CA504 25800202 */  or         $16, $16, $2
    /* 2CA508 003CA508 0C000424 */  addiu      $4, $0, 0xC
    /* 2CA50C 003CA50C 07050524 */  addiu      $5, $0, 0x507
    /* 2CA510 003CA510 A095C624 */  addiu      $6, $6, %lo(func_003c95a0)
    /* 2CA514 003CA514 4CA20F0C */  jal        func_003e8930
    /* 2CA518 003CA518 3095E724 */   addiu     $7, $7, %lo(func_003c9530)
    /* 2CA51C 003CA51C 3C00063C */  lui        $6, %hi(func_003be7e0)
    /* 2CA520 003CA520 3C00073C */  lui        $7, %hi(func_003be7c0)
    /* 2CA524 003CA524 25800202 */  or         $16, $16, $2
    /* 2CA528 003CA528 2D200000 */  daddu      $4, $0, $0
    /* 2CA52C 003CA52C 0B050524 */  addiu      $5, $0, 0x50B
    /* 2CA530 003CA530 E0E7C624 */  addiu      $6, $6, %lo(func_003be7e0)
    /* 2CA534 003CA534 4CA20F0C */  jal        func_003e8930
    /* 2CA538 003CA538 C0E7E724 */   addiu     $7, $7, %lo(func_003be7c0)
    /* 2CA53C 003CA53C 25100202 */  or         $2, $16, $2
    /* 2CA540 003CA540 03004104 */  bgez       $2, .L003CA550
    /* 2CA544 003CA544 00000000 */   nop
    /* 2CA548 003CA548 10000010 */  b          .L003CA58C
    /* 2CA54C 003CA54C 2D100000 */   daddu     $2, $0, $0
  .L003CA550:
    /* 2CA550 003CA550 402E0F0C */  jal        func_003cb900
    /* 2CA554 003CA554 00000000 */   nop
    /* 2CA558 003CA558 03004014 */  bnez       $2, .L003CA568
    /* 2CA55C 003CA55C 00000000 */   nop
    /* 2CA560 003CA560 0A000010 */  b          .L003CA58C
    /* 2CA564 003CA564 2D100000 */   daddu     $2, $0, $0
  .L003CA568:
    /* 2CA568 003CA568 7CFF0E0C */  jal        func_003bfdf0
    /* 2CA56C 003CA56C 00000000 */   nop
    /* 2CA570 003CA570 03004014 */  bnez       $2, .L003CA580
    /* 2CA574 003CA574 00000000 */   nop
    /* 2CA578 003CA578 04000010 */  b          .L003CA58C
    /* 2CA57C 003CA57C 2D100000 */   daddu     $2, $0, $0
  .L003CA580:
    /* 2CA580 003CA580 1C530F0C */  jal        func_003d4c70
    /* 2CA584 003CA584 00000000 */   nop
    /* 2CA588 003CA588 2B100200 */  sltu       $2, $0, $2
  .L003CA58C:
    /* 2CA58C 003CA58C 1000BFDF */  ld         $31, 0x10($29)
    /* 2CA590 003CA590 0000B07B */  lq         $16, 0x0($29)
    /* 2CA594 003CA594 0800E003 */  jr         $31
    /* 2CA598 003CA598 2000BD27 */   addiu     $29, $29, 0x20
    /* 2CA59C 003CA59C 00000000 */  nop
.size func_003ca430, 0x170
