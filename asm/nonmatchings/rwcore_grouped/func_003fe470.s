.section .text
.set noat
.set noreorder
glabel func_003fe470
    /* 2FE470 003FE470 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2FE474 003FE474 58B9828F */  lw         $2, -0x46A8($28)
    /* 2FE478 003FE478 2B100200 */  sltu       $2, $0, $2
    /* 2FE47C 003FE47C 01004238 */  xori       $2, $2, 0x1
    /* 2FE480 003FE480 02004010 */  beqz       $2, .L003FE48C
    /* 2FE484 003FE484 00000000 */   nop
    /* 2FE488 003FE488 5A008228 */  slti       $2, $4, 0x5A
  .L003FE48C:
    /* 2FE48C 003FE48C 03004010 */  beqz       $2, .L003FE49C
    /* 2FE490 003FE490 00000000 */   nop
    /* 2FE494 003FE494 FFFF8228 */  slti       $2, $4, -0x1
    /* 2FE498 003FE498 01004238 */  xori       $2, $2, 0x1
  .L003FE49C:
    /* 2FE49C 003FE49C 5E004010 */  beqz       $2, .L003FE618
    /* 2FE4A0 003FE4A0 00000000 */   nop
    /* 2FE4A4 003FE4A4 FFFF0324 */  addiu      $3, $0, -0x1
    /* 2FE4A8 003FE4A8 0D008314 */  bne        $4, $3, .L003FE4E0
    /* 2FE4AC 003FE4AC 60B984AF */   sw        $4, -0x46A0($28)
  .L003FE4B0:
    /* 2FE4B0 003FE4B0 8900033C */  lui        $3, %hi(D_0088C9B8)
    /* 2FE4B4 003FE4B4 20000424 */  addiu      $4, $0, 0x20
    /* 2FE4B8 003FE4B8 B8C9638C */  lw         $3, %lo(D_0088C9B8)($3)
    /* 2FE4BC 003FE4BC 04006414 */  bne        $3, $4, .L003FE4D0
    /* 2FE4C0 003FE4C0 00000000 */   nop
    /* 2FE4C4 003FE4C4 00050324 */  addiu      $3, $0, 0x500
    /* 2FE4C8 003FE4C8 03000010 */  b          .L003FE4D8
    /* 2FE4CC 003FE4CC 5CB983AF */   sw        $3, -0x46A4($28)
  .L003FE4D0:
    /* 2FE4D0 003FE4D0 00010324 */  addiu      $3, $0, 0x100
    /* 2FE4D4 003FE4D4 5CB983AF */  sw         $3, -0x46A4($28)
  .L003FE4D8:
    /* 2FE4D8 003FE4D8 50000010 */  b          .L003FE61C
    /* 2FE4DC 003FE4DC 2000BD27 */   addiu     $29, $29, 0x20
  .L003FE4E0:
    /* 2FE4E0 003FE4E0 40280400 */  sll        $5, $4, 1
    /* 2FE4E4 003FE4E4 7100033C */  lui        $3, %hi(D_0070B840)
    /* 2FE4E8 003FE4E8 2120A400 */  addu       $4, $5, $4
    /* 2FE4EC 003FE4EC 40B86324 */  addiu      $3, $3, %lo(D_0070B840)
    /* 2FE4F0 003FE4F0 C0200400 */  sll        $4, $4, 3
    /* 2FE4F4 003FE4F4 8900063C */  lui        $6, %hi(D_0088C9D4)
    /* 2FE4F8 003FE4F8 21186400 */  addu       $3, $3, $4
    /* 2FE4FC 003FE4FC 8900093C */  lui        $9, %hi(D_0088C9C8)
    /* 2FE500 003FE500 0C0062C4 */  lwc1       $f2, 0xC($3)
    /* 2FE504 003FE504 8900083C */  lui        $8, %hi(D_0088C9CC)
    /* 2FE508 003FE508 000065C4 */  lwc1       $f5, 0x0($3)
    /* 2FE50C 003FE50C 89000B3C */  lui        $11, %hi(D_0088C9B0)
    /* 2FE510 003FE510 040064C4 */  lwc1       $f4, 0x4($3)
    /* 2FE514 003FE514 89000A3C */  lui        $10, %hi(D_0088C9C0)
    /* 2FE518 003FE518 100061C4 */  lwc1       $f1, 0x10($3)
    /* 2FE51C 003FE51C 8900073C */  lui        $7, %hi(D_0088C9D0)
    /* 2FE520 003FE520 140060C4 */  lwc1       $f0, 0x14($3)
    /* 2FE524 003FE524 8900053C */  lui        $5, %hi(D_0088C9D8)
    /* 2FE528 003FE528 080063C4 */  lwc1       $f3, 0x8($3)
    /* 2FE52C 003FE52C 8900043C */  lui        $4, %hi(D_0088C9DC)
    /* 2FE530 003FE530 0C00A2E7 */  swc1       $f2, 0xC($29)
    /* 2FE534 003FE534 0C00A2C7 */  lwc1       $f2, 0xC($29)
    /* 2FE538 003FE538 0000A5E7 */  swc1       $f5, 0x0($29)
    /* 2FE53C 003FE53C 1000A1E7 */  swc1       $f1, 0x10($29)
    /* 2FE540 003FE540 1400A0E7 */  swc1       $f0, 0x14($29)
    /* 2FE544 003FE544 0400A4E7 */  swc1       $f4, 0x4($29)
    /* 2FE548 003FE548 1000ACDF */  ld         $12, 0x10($29)
    /* 2FE54C 003FE54C 0000A1C7 */  lwc1       $f1, 0x0($29)
    /* 2FE550 003FE550 8900033C */  lui        $3, %hi(D_0088C9D4)
    /* 2FE554 003FE554 0400A0C7 */  lwc1       $f0, 0x4($29)
    /* 2FE558 003FE558 0800A3E7 */  swc1       $f3, 0x8($29)
    /* 2FE55C 003FE55C D4C9C2E4 */  swc1       $f2, %lo(D_0088C9D4)($6)
    /* 2FE560 003FE560 0000AD7B */  lq         $13, 0x0($29)
    /* 2FE564 003FE564 D4C9638C */  lw         $3, %lo(D_0088C9D4)($3)
    /* 2FE568 003FE568 0800A3C7 */  lwc1       $f3, 0x8($29)
    /* 2FE56C 003FE56C C0C94CFD */  sd         $12, %lo(D_0088C9C0)($10)
    /* 2FE570 003FE570 C8C921E5 */  swc1       $f1, %lo(D_0088C9C8)($9)
    /* 2FE574 003FE574 CCC900E5 */  swc1       $f0, %lo(D_0088C9CC)($8)
    /* 2FE578 003FE578 1000A1C7 */  lwc1       $f1, 0x10($29)
    /* 2FE57C 003FE57C 1400A0C7 */  lwc1       $f0, 0x14($29)
    /* 2FE580 003FE580 B0C96D7D */  sq         $13, %lo(D_0088C9B0)($11)
    /* 2FE584 003FE584 00016330 */  andi       $3, $3, 0x100
    /* 2FE588 003FE588 D0C9E3E4 */  swc1       $f3, %lo(D_0088C9D0)($7)
    /* 2FE58C 003FE58C D8C9A1E4 */  swc1       $f1, %lo(D_0088C9D8)($5)
    /* 2FE590 003FE590 12006010 */  beqz       $3, .L003FE5DC
    /* 2FE594 003FE594 DCC980E4 */   swc1      $f0, %lo(D_0088C9DC)($4)
    /* 2FE598 003FE598 01000424 */  addiu      $4, $0, 0x1
    /* 2FE59C 003FE59C 8900033C */  lui        $3, %hi(D_0088C9E0)
    /* 2FE5A0 003FE5A0 E0C964A0 */  sb         $4, %lo(D_0088C9E0)($3)
    /* 2FE5A4 003FE5A4 8900033C */  lui        $3, %hi(D_0088C9E1)
    /* 2FE5A8 003FE5A8 E1C964A0 */  sb         $4, %lo(D_0088C9E1)($3)
    /* 2FE5AC 003FE5AC 8900033C */  lui        $3, %hi(D_0088C9CC)
    /* 2FE5B0 003FE5B0 20B9848F */  lw         $4, -0x46E0($28)
    /* 2FE5B4 003FE5B4 CCC9658C */  lw         $5, %lo(D_0088C9CC)($3)
    /* 2FE5B8 003FE5B8 8900033C */  lui        $3, %hi(D_0088C9CC)
    /* 2FE5BC 003FE5BC 43280500 */  sra        $5, $5, 1
    /* 2FE5C0 003FE5C0 11008010 */  beqz       $4, .L003FE608
    /* 2FE5C4 003FE5C4 CCC965AC */   sw        $5, %lo(D_0088C9CC)($3)
    /* 2FE5C8 003FE5C8 8900033C */  lui        $3, %hi(D_0088C9C8)
    /* 2FE5CC 003FE5CC C8C964AC */  sw         $4, %lo(D_0088C9C8)($3)
  .L003FE5D0:
    /* 2FE5D0 003FE5D0 8900033C */  lui        $3, %hi(D_0088C9E3)
    /* 2FE5D4 003FE5D4 09000010 */  b          .L003FE5FC
    /* 2FE5D8 003FE5D8 E3C960A0 */   sb        $0, %lo(D_0088C9E3)($3)
  .L003FE5DC:
    /* 2FE5DC 003FE5DC 02000424 */  addiu      $4, $0, 0x2
    /* 2FE5E0 003FE5E0 8900033C */  lui        $3, %hi(D_0088C9E0)
    /* 2FE5E4 003FE5E4 E0C964A0 */  sb         $4, %lo(D_0088C9E0)($3)
    /* 2FE5E8 003FE5E8 8900033C */  lui        $3, %hi(D_0088C9E1)
    /* 2FE5EC 003FE5EC E1C964A0 */  sb         $4, %lo(D_0088C9E1)($3)
    /* 2FE5F0 003FE5F0 01000424 */  addiu      $4, $0, 0x1
    /* 2FE5F4 003FE5F4 8900033C */  lui        $3, %hi(D_0088C9E3)
    /* 2FE5F8 003FE5F8 E3C964A0 */  sb         $4, %lo(D_0088C9E3)($3)
  .L003FE5FC:
    /* 2FE5FC 003FE5FC 8900033C */  lui        $3, %hi(D_0088C9E2)
    /* 2FE600 003FE600 ABFF0010 */  b          .L003FE4B0
    /* 2FE604 003FE604 E2C960A0 */   sb        $0, %lo(D_0088C9E2)($3)
  .L003FE608:
    /* 2FE608 003FE608 8900033C */  lui        $3, %hi(D_0088C9C8)
    /* 2FE60C 003FE60C C8C9638C */  lw         $3, %lo(D_0088C9C8)($3)
    /* 2FE610 003FE610 EFFF0010 */  b          .L003FE5D0
    /* 2FE614 003FE614 20B983AF */   sw        $3, -0x46E0($28)
  .L003FE618:
    /* 2FE618 003FE618 2000BD27 */  addiu      $29, $29, 0x20
  .L003FE61C:
    /* 2FE61C 003FE61C 0800E003 */  jr         $31
    /* 2FE620 003FE620 00000000 */   nop
    /* 2FE624 003FE624 00000000 */  nop
    /* 2FE628 003FE628 00000000 */  nop
    /* 2FE62C 003FE62C 00000000 */  nop
.size func_003fe470, 0x1c0
