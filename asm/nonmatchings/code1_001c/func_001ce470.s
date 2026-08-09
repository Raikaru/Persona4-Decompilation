.section .text
.set noat
.set noreorder
glabel func_001ce470
    /* CE470 001CE470 B0FFBD27 */  addiu      $29, $29, -0x50
    /* CE474 001CE474 0000BFFF */  sd         $31, 0x0($29)
    /* CE478 001CE478 D800848C */  lw         $4, 0xD8($4)
    /* CE47C 001CE47C 30008014 */  bnez       $4, .L001CE540
    /* CE480 001CE480 00000000 */   nop
    /* CE484 001CE484 1C00A427 */  addiu      $4, $29, 0x1C
    /* CE488 001CE488 6000053C */  lui        $5, %hi(D_00607DD0)
    /* CE48C 001CE48C D07DA524 */  addiu      $5, $5, %lo(D_00607DD0)
    /* CE490 001CE490 6000063C */  lui        $6, %hi(D_00607DF0)
    /* CE494 001CE494 F07DC624 */  addiu      $6, $6, %lo(D_00607DF0)
    /* CE498 001CE498 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CE49C 001CE49C E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CE4A0 001CE4A0 E0F5060C */  jal        func_001bd780
    /* CE4A4 001CE4A4 00000000 */   nop
    /* CE4A8 001CE4A8 6000023C */  lui        $2, %hi(D_00607DD0)
    /* CE4AC 001CE4AC D07D43DC */  ld         $3, %lo(D_00607DD0)($2)
    /* CE4B0 001CE4B0 6000023C */  lui        $2, %hi(D_00607DD8)
    /* CE4B4 001CE4B4 D87D40C4 */  lwc1       $f0, %lo(D_00607DD8)($2)
    /* CE4B8 001CE4B8 1000A3FF */  sd         $3, 0x10($29)
    /* CE4BC 001CE4BC 1800A0E7 */  swc1       $f0, 0x18($29)
    /* CE4C0 001CE4C0 3800A427 */  addiu      $4, $29, 0x38
    /* CE4C4 001CE4C4 6000053C */  lui        $5, %hi(D_00607E10)
    /* CE4C8 001CE4C8 107EA524 */  addiu      $5, $5, %lo(D_00607E10)
    /* CE4CC 001CE4CC 6000063C */  lui        $6, %hi(D_00607E30)
    /* CE4D0 001CE4D0 307EC624 */  addiu      $6, $6, %lo(D_00607E30)
    /* CE4D4 001CE4D4 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CE4D8 001CE4D8 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CE4DC 001CE4DC E0F5060C */  jal        func_001bd780
    /* CE4E0 001CE4E0 00000000 */   nop
    /* CE4E4 001CE4E4 2C00A627 */  addiu      $6, $29, 0x2C
    /* CE4E8 001CE4E8 6000023C */  lui        $2, %hi(D_00607E10)
    /* CE4EC 001CE4EC 107E42C4 */  lwc1       $f2, %lo(D_00607E10)($2)
    /* CE4F0 001CE4F0 6000023C */  lui        $2, %hi(D_00607E14)
    /* CE4F4 001CE4F4 147E41C4 */  lwc1       $f1, %lo(D_00607E14)($2)
    /* CE4F8 001CE4F8 6000023C */  lui        $2, %hi(D_00607E18)
    /* CE4FC 001CE4FC 187E40C4 */  lwc1       $f0, %lo(D_00607E18)($2)
    /* CE500 001CE500 2C00A2E7 */  swc1       $f2, 0x2C($29)
    /* CE504 001CE504 3000A1E7 */  swc1       $f1, 0x30($29)
    /* CE508 001CE508 3400A0E7 */  swc1       $f0, 0x34($29)
    /* CE50C 001CE50C ACB3828F */  lw         $2, -0x4C54($28)
    /* CE510 001CE510 24004424 */  addiu      $4, $2, 0x24
    /* CE514 001CE514 1000A527 */  addiu      $5, $29, 0x10
    /* CE518 001CE518 01000724 */  addiu      $7, $0, 0x1
    /* CE51C 001CE51C 08EB060C */  jal        func_001bac20
    /* CE520 001CE520 00000000 */   nop
    /* CE524 001CE524 ACB3828F */  lw         $2, -0x4C54($28)
    /* CE528 001CE528 24004424 */  addiu      $4, $2, 0x24
    /* CE52C 001CE52C 9C818CC7 */  lwc1       $f12, -0x7E64($28)
    /* CE530 001CE530 BCEF060C */  jal        func_001bbef0
    /* CE534 001CE534 00000000 */   nop
    /* CE538 001CE538 34000010 */  b          .L001CE60C
    /* CE53C 001CE53C 00000000 */   nop
  .L001CE540:
    /* CE540 001CE540 25000324 */  addiu      $3, $0, 0x25
    /* CE544 001CE544 31008314 */  bne        $4, $3, .L001CE60C
    /* CE548 001CE548 00000000 */   nop
    /* CE54C 001CE54C 1C00A427 */  addiu      $4, $29, 0x1C
    /* CE550 001CE550 6000053C */  lui        $5, %hi(D_00607DDC)
    /* CE554 001CE554 DC7DA524 */  addiu      $5, $5, %lo(D_00607DDC)
    /* CE558 001CE558 6000063C */  lui        $6, %hi(D_00607DFC)
    /* CE55C 001CE55C FC7DC624 */  addiu      $6, $6, %lo(D_00607DFC)
    /* CE560 001CE560 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CE564 001CE564 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CE568 001CE568 E0F5060C */  jal        func_001bd780
    /* CE56C 001CE56C 00000000 */   nop
    /* CE570 001CE570 6000023C */  lui        $2, %hi(D_00607DDC)
    /* CE574 001CE574 DC7D42C4 */  lwc1       $f2, %lo(D_00607DDC)($2)
    /* CE578 001CE578 6000023C */  lui        $2, %hi(D_00607DE0)
    /* CE57C 001CE57C E07D41C4 */  lwc1       $f1, %lo(D_00607DE0)($2)
    /* CE580 001CE580 6000023C */  lui        $2, %hi(D_00607DE4)
    /* CE584 001CE584 E47D40C4 */  lwc1       $f0, %lo(D_00607DE4)($2)
    /* CE588 001CE588 1000A2E7 */  swc1       $f2, 0x10($29)
    /* CE58C 001CE58C 1400A1E7 */  swc1       $f1, 0x14($29)
    /* CE590 001CE590 1800A0E7 */  swc1       $f0, 0x18($29)
    /* CE594 001CE594 3800A427 */  addiu      $4, $29, 0x38
    /* CE598 001CE598 6000053C */  lui        $5, %hi(D_00607E1C)
    /* CE59C 001CE59C 1C7EA524 */  addiu      $5, $5, %lo(D_00607E1C)
    /* CE5A0 001CE5A0 6000063C */  lui        $6, %hi(D_00607E3C)
    /* CE5A4 001CE5A4 3C7EC624 */  addiu      $6, $6, %lo(D_00607E3C)
    /* CE5A8 001CE5A8 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CE5AC 001CE5AC E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CE5B0 001CE5B0 E0F5060C */  jal        func_001bd780
    /* CE5B4 001CE5B4 00000000 */   nop
    /* CE5B8 001CE5B8 2C00A627 */  addiu      $6, $29, 0x2C
    /* CE5BC 001CE5BC 6000023C */  lui        $2, %hi(D_00607E1C)
    /* CE5C0 001CE5C0 1C7E42C4 */  lwc1       $f2, %lo(D_00607E1C)($2)
    /* CE5C4 001CE5C4 6000023C */  lui        $2, %hi(D_00607E20)
    /* CE5C8 001CE5C8 207E41C4 */  lwc1       $f1, %lo(D_00607E20)($2)
    /* CE5CC 001CE5CC 6000023C */  lui        $2, %hi(D_00607E24)
    /* CE5D0 001CE5D0 247E40C4 */  lwc1       $f0, %lo(D_00607E24)($2)
    /* CE5D4 001CE5D4 2C00A2E7 */  swc1       $f2, 0x2C($29)
    /* CE5D8 001CE5D8 3000A1E7 */  swc1       $f1, 0x30($29)
    /* CE5DC 001CE5DC 3400A0E7 */  swc1       $f0, 0x34($29)
    /* CE5E0 001CE5E0 ACB3828F */  lw         $2, -0x4C54($28)
    /* CE5E4 001CE5E4 24004424 */  addiu      $4, $2, 0x24
    /* CE5E8 001CE5E8 1000A527 */  addiu      $5, $29, 0x10
    /* CE5EC 001CE5EC 01000724 */  addiu      $7, $0, 0x1
    /* CE5F0 001CE5F0 08EB060C */  jal        func_001bac20
    /* CE5F4 001CE5F4 00000000 */   nop
    /* CE5F8 001CE5F8 ACB3828F */  lw         $2, -0x4C54($28)
    /* CE5FC 001CE5FC 24004424 */  addiu      $4, $2, 0x24
    /* CE600 001CE600 9C808CC7 */  lwc1       $f12, -0x7F64($28)
    /* CE604 001CE604 BCEF060C */  jal        func_001bbef0
    /* CE608 001CE608 00000000 */   nop
  .L001CE60C:
    /* CE60C 001CE60C 0000BFDF */  ld         $31, 0x0($29)
    /* CE610 001CE610 5000BD27 */  addiu      $29, $29, 0x50
    /* CE614 001CE614 0800E003 */  jr         $31
    /* CE618 001CE618 00000000 */   nop
    /* CE61C 001CE61C 00000000 */  nop
.size func_001ce470, 0x1b0
