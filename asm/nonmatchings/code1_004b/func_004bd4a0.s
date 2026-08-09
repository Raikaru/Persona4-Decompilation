.section .text
.set noat
.set noreorder
glabel func_004bd4a0
    /* 3BD4A0 004BD4A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3BD4A4 004BD4A4 000083C4 */  lwc1       $f3, 0x0($4)
    /* 3BD4A8 004BD4A8 040082C4 */  lwc1       $f2, 0x4($4)
    /* 3BD4AC 004BD4AC 080081C4 */  lwc1       $f1, 0x8($4)
    /* 3BD4B0 004BD4B0 0C0080C4 */  lwc1       $f0, 0xC($4)
    /* 3BD4B4 004BD4B4 1000A3E7 */  swc1       $f3, 0x10($29)
    /* 3BD4B8 004BD4B8 1400A2E7 */  swc1       $f2, 0x14($29)
    /* 3BD4BC 004BD4BC 1800A1E7 */  swc1       $f1, 0x18($29)
    /* 3BD4C0 004BD4C0 1C00A0E7 */  swc1       $f0, 0x1C($29)
    /* 3BD4C4 004BD4C4 0000A3C4 */  lwc1       $f3, 0x0($5)
    /* 3BD4C8 004BD4C8 0400A2C4 */  lwc1       $f2, 0x4($5)
    /* 3BD4CC 004BD4CC 0800A1C4 */  lwc1       $f1, 0x8($5)
    /* 3BD4D0 004BD4D0 0C00A0C4 */  lwc1       $f0, 0xC($5)
    /* 3BD4D4 004BD4D4 0000A3E7 */  swc1       $f3, 0x0($29)
    /* 3BD4D8 004BD4D8 0400A2E7 */  swc1       $f2, 0x4($29)
    /* 3BD4DC 004BD4DC 0800A1E7 */  swc1       $f1, 0x8($29)
    /* 3BD4E0 004BD4E0 0C00A0E7 */  swc1       $f0, 0xC($29)
    /* 3BD4E4 004BD4E4 1400A5C7 */  lwc1       $f5, 0x14($29)
    /* 3BD4E8 004BD4E8 1800A4C7 */  lwc1       $f4, 0x18($29)
    /* 3BD4EC 004BD4EC 1C00A3C7 */  lwc1       $f3, 0x1C($29)
    /* 3BD4F0 004BD4F0 1000A2C7 */  lwc1       $f2, 0x10($29)
    /* 3BD4F4 004BD4F4 1A280546 */  mula.s     $f5, $f5
    /* 3BD4F8 004BD4F8 00008044 */  mtc1       $0, $f0
    /* 3BD4FC 004BD4FC 1E100246 */  madda.s    $f2, $f2
    /* 3BD500 004BD500 1E200446 */  madda.s    $f4, $f4
    /* 3BD504 004BD504 5C180346 */  madd.s     $f1, $f3, $f3
    /* 3BD508 004BD508 44000146 */  c1         0x10044
    /* 3BD50C 004BD50C 83120146 */  div.s      $f10, $f2, $f1
    /* 3BD510 004BD510 1000AAE7 */  swc1       $f10, 0x10($29)
    /* 3BD514 004BD514 432A0146 */  div.s      $f9, $f5, $f1
    /* 3BD518 004BD518 1400A9E7 */  swc1       $f9, 0x14($29)
    /* 3BD51C 004BD51C 03220146 */  div.s      $f8, $f4, $f1
    /* 3BD520 004BD520 1800A8E7 */  swc1       $f8, 0x18($29)
    /* 3BD524 004BD524 C3190146 */  div.s      $f7, $f3, $f1
    /* 3BD528 004BD528 1C00A7E7 */  swc1       $f7, 0x1C($29)
    /* 3BD52C 004BD52C 0400A3C7 */  lwc1       $f3, 0x4($29)
    /* 3BD530 004BD530 0800A6C7 */  lwc1       $f6, 0x8($29)
    /* 3BD534 004BD534 0C00A5C7 */  lwc1       $f5, 0xC($29)
    /* 3BD538 004BD538 0000A2C7 */  lwc1       $f2, 0x0($29)
    /* 3BD53C 004BD53C 1A180346 */  mula.s     $f3, $f3
    /* 3BD540 004BD540 1E100246 */  madda.s    $f2, $f2
    /* 3BD544 004BD544 1E300646 */  madda.s    $f6, $f6
    /* 3BD548 004BD548 5C280546 */  madd.s     $f1, $f5, $f5
    /* 3BD54C 004BD54C 44000146 */  c1         0x10044
    /* 3BD550 004BD550 03110146 */  div.s      $f4, $f2, $f1
    /* 3BD554 004BD554 0000A4E7 */  swc1       $f4, 0x0($29)
    /* 3BD558 004BD558 C3180146 */  div.s      $f3, $f3, $f1
    /* 3BD55C 004BD55C 0400A3E7 */  swc1       $f3, 0x4($29)
    /* 3BD560 004BD560 83300146 */  div.s      $f2, $f6, $f1
    /* 3BD564 004BD564 0800A2E7 */  swc1       $f2, 0x8($29)
    /* 3BD568 004BD568 43280146 */  div.s      $f1, $f5, $f1
    /* 3BD56C 004BD56C 00000000 */  nop
    /* 3BD570 004BD570 0C00A1E7 */  swc1       $f1, 0xC($29)
    /* 3BD574 004BD574 32500446 */  c.eq.s     $f10, $f4
    /* 3BD578 004BD578 0C000045 */  bc1f       .L004BD5AC
    /* 3BD57C 004BD57C 00000000 */   nop
    /* 3BD580 004BD580 32480346 */  c.eq.s     $f9, $f3
    /* 3BD584 004BD584 09000045 */  bc1f       .L004BD5AC
    /* 3BD588 004BD588 00000000 */   nop
    /* 3BD58C 004BD58C 32400246 */  c.eq.s     $f8, $f2
    /* 3BD590 004BD590 06000045 */  bc1f       .L004BD5AC
    /* 3BD594 004BD594 00000000 */   nop
    /* 3BD598 004BD598 32380146 */  c.eq.s     $f7, $f1
    /* 3BD59C 004BD59C 03000045 */  bc1f       .L004BD5AC
    /* 3BD5A0 004BD5A0 00000000 */   nop
    /* 3BD5A4 004BD5A4 1D000010 */  b          .L004BD61C
    /* 3BD5A8 004BD5A8 00000000 */   nop
  .L004BD5AC:
    /* 3BD5AC 004BD5AC 1C00A7C7 */  lwc1       $f7, 0x1C($29)
    /* 3BD5B0 004BD5B0 0C00A6C7 */  lwc1       $f6, 0xC($29)
    /* 3BD5B4 004BD5B4 1800A5C7 */  lwc1       $f5, 0x18($29)
    /* 3BD5B8 004BD5B8 0800A4C7 */  lwc1       $f4, 0x8($29)
    /* 3BD5BC 004BD5BC 1000A3C7 */  lwc1       $f3, 0x10($29)
    /* 3BD5C0 004BD5C0 0000A2C7 */  lwc1       $f2, 0x0($29)
    /* 3BD5C4 004BD5C4 1400A1C7 */  lwc1       $f1, 0x14($29)
    /* 3BD5C8 004BD5C8 0400A0C7 */  lwc1       $f0, 0x4($29)
    /* 3BD5CC 004BD5CC 1A080046 */  mula.s     $f1, $f0
    /* 3BD5D0 004BD5D0 1E180246 */  madda.s    $f3, $f2
    /* 3BD5D4 004BD5D4 1E280446 */  madda.s    $f5, $f4
    /* 3BD5D8 004BD5D8 1C380646 */  madd.s     $f0, $f7, $f6
    /* 3BD5DC 004BD5DC 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3BD5E0 004BD5E0 00088244 */  mtc1       $2, $f1
    /* 3BD5E4 004BD5E4 00000000 */  nop
    /* 3BD5E8 004BD5E8 36000146 */  c.le.s     $f0, $f1
    /* 3BD5EC 004BD5EC 04000145 */  bc1t       .L004BD600
    /* 3BD5F0 004BD5F0 00000000 */   nop
    /* 3BD5F4 004BD5F4 06080046 */  mov.s      $f0, $f1
    /* 3BD5F8 004BD5F8 08000010 */  b          .L004BD61C
    /* 3BD5FC 004BD5FC 00000000 */   nop
  .L004BD600:
    /* 3BD600 004BD600 80BF023C */  lui        $2, (0xBF800000 >> 16)
    /* 3BD604 004BD604 00088244 */  mtc1       $2, $f1
    /* 3BD608 004BD608 00000000 */  nop
    /* 3BD60C 004BD60C 34000146 */  c.lt.s     $f0, $f1
    /* 3BD610 004BD610 02000045 */  bc1f       .L004BD61C
    /* 3BD614 004BD614 00000000 */   nop
    /* 3BD618 004BD618 06080046 */  mov.s      $f0, $f1
  .L004BD61C:
    /* 3BD61C 004BD61C 2000BD27 */  addiu      $29, $29, 0x20
    /* 3BD620 004BD620 0800E003 */  jr         $31
    /* 3BD624 004BD624 00000000 */   nop
.size func_004bd4a0, 0x188
