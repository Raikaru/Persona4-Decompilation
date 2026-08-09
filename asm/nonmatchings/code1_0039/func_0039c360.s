.section .text
.set noat
.set noreorder
glabel func_0039c360
    /* 29C360 0039C360 D0FEBD27 */  addiu      $29, $29, -0x130
    /* 29C364 0039C364 8800033C */  lui        $3, %hi(D_00886494)
    /* 29C368 0039C368 6000BFFF */  sd         $31, 0x60($29)
    /* 29C36C 0039C36C 8800023C */  lui        $2, %hi(D_0088649C)
    /* 29C370 0039C370 5000B57F */  sq         $21, 0x50($29)
    /* 29C374 0039C374 4000B47F */  sq         $20, 0x40($29)
    /* 29C378 0039C378 3000B37F */  sq         $19, 0x30($29)
    /* 29C37C 0039C37C 2000B27F */  sq         $18, 0x20($29)
    /* 29C380 0039C380 1000B17F */  sq         $17, 0x10($29)
    /* 29C384 0039C384 2D908000 */  daddu      $18, $4, $0
    /* 29C388 0039C388 0000B07F */  sq         $16, 0x0($29)
    /* 29C38C 0039C38C 9464638C */  lw         $3, %lo(D_00886494)($3)
    /* 29C390 0039C390 9C64518C */  lw         $17, %lo(D_0088649C)($2)
    /* 29C394 0039C394 21104302 */  addu       $2, $18, $3
    /* 29C398 0039C398 0000558C */  lw         $21, 0x0($2)
    /* 29C39C 0039C39C BD00A012 */  beqz       $21, .L0039C694
    /* 29C3A0 0039C3A0 00000000 */   nop
    /* 29C3A4 0039C3A4 0400B48E */  lw         $20, 0x4($21)
    /* 29C3A8 0039C3A8 0800B38E */  lw         $19, 0x8($21)
    /* 29C3AC 0039C3AC 44E10E0C */  jal        func_003b8510
    /* 29C3B0 0039C3B0 2D20A000 */   daddu     $4, $5, $0
    /* 29C3B4 0039C3B4 0000A38E */  lw         $3, 0x0($21)
    /* 29C3B8 0039C3B8 2D804000 */  daddu      $16, $2, $0
    /* 29C3BC 0039C3BC 02006230 */  andi       $2, $3, 0x2
    /* 29C3C0 0039C3C0 4D004010 */  beqz       $2, .L0039C4F8
    /* 29C3C4 0039C3C4 00000000 */   nop
    /* 29C3C8 0039C3C8 1000B38E */  lw         $19, 0x10($21)
    /* 29C3CC 0039C3CC FC00A0AF */  sw         $0, 0xFC($29)
    /* 29C3D0 0039C3D0 0400448E */  lw         $4, 0x4($18)
    /* 29C3D4 0039C3D4 C0A50F0C */  jal        func_003e9700
    /* 29C3D8 0039C3D8 BC00A0AF */   sw        $0, 0xBC($29)
    /* 29C3DC 0039C3DC 2D284000 */  daddu      $5, $2, $0
    /* 29C3E0 0039C3E0 58820F0C */  jal        func_003e0960
    /* 29C3E4 0039C3E4 F000A427 */   addiu     $4, $29, 0xF0
    /* 29C3E8 0039C3E8 2A081400 */  slt        $1, $0, $20
    /* 29C3EC 0039C3EC C4002010 */  beqz       $1, .L0039C700
    /* 29C3F0 0039C3F0 2D900000 */   daddu     $18, $0, $0
  .L0039C3F4:
    /* 29C3F4 0039C3F4 00111200 */  sll        $2, $18, 4
    /* 29C3F8 0039C3F8 21106202 */  addu       $2, $19, $2
    /* 29C3FC 0039C3FC C0A50F0C */  jal        func_003e9700
    /* 29C400 0039C400 0C00448C */   lw        $4, 0xC($2)
    /* 29C404 0039C404 80291200 */  sll        $5, $18, 6
    /* 29C408 0039C408 B000A427 */  addiu      $4, $29, 0xB0
    /* 29C40C 0039C40C 21180502 */  addu       $3, $16, $5
    /* 29C410 0039C410 000061D8 */  lqc2       $vf1, 0x0($3)
    /* 29C414 0039C414 100062D8 */  lqc2       $vf2, 0x10($3)
    /* 29C418 0039C418 200063D8 */  lqc2       $vf3, 0x20($3)
    /* 29C41C 0039C41C 300064D8 */  lqc2       $vf4, 0x30($3)
    /* 29C420 0039C420 000045D8 */  lqc2       $vf5, 0x0($2)
    /* 29C424 0039C424 100046D8 */  lqc2       $vf6, 0x10($2)
    /* 29C428 0039C428 200047D8 */  lqc2       $vf7, 0x20($2)
    /* 29C42C 0039C42C 300048D8 */  lqc2       $vf8, 0x30($2)
    /* 29C430 0039C430 BC29E14B */  vmulax.xyzw $ACC, $vf5, $vf1x
    /* 29C434 0039C434 BD30E14B */  vmadday.xyzw $ACC, $vf6, $vf1y
    /* 29C438 0039C438 4A3AE14B */  vmaddz.xyzw $vf9, $vf7, $vf1z
    /* 29C43C 0039C43C BC29E24B */  vmulax.xyzw $ACC, $vf5, $vf2x
    /* 29C440 0039C440 BD30E24B */  vmadday.xyzw $ACC, $vf6, $vf2y
    /* 29C444 0039C444 8A3AE24B */  vmaddz.xyzw $vf10, $vf7, $vf2z
    /* 29C448 0039C448 BC29E34B */  vmulax.xyzw $ACC, $vf5, $vf3x
    /* 29C44C 0039C44C BD30E34B */  vmadday.xyzw $ACC, $vf6, $vf3y
    /* 29C450 0039C450 CA3AE34B */  vmaddz.xyzw $vf11, $vf7, $vf3z
    /* 29C454 0039C454 BC29E44B */  vmulax.xyzw $ACC, $vf5, $vf4x
    /* 29C458 0039C458 BD30E44B */  vmadday.xyzw $ACC, $vf6, $vf4y
    /* 29C45C 0039C45C BE38E44B */  vmaddaz.xyzw $ACC, $vf7, $vf4z
    /* 29C460 0039C460 0B43E04B */  vmaddw.xyzw $vf12, $vf8, $vf0w
    /* 29C464 0039C464 000089F8 */  sqc2       $vf9, 0x0($4)
    /* 29C468 0039C468 10008AF8 */  sqc2       $vf10, 0x10($4)
    /* 29C46C 0039C46C 20008BF8 */  sqc2       $vf11, 0x20($4)
    /* 29C470 0039C470 30008CF8 */  sqc2       $vf12, 0x30($4)
    /* 29C474 0039C474 21102502 */  addu       $2, $17, $5
    /* 29C478 0039C478 F000A327 */  addiu      $3, $29, 0xF0
    /* 29C47C 0039C47C 000081D8 */  lqc2       $vf1, 0x0($4)
    /* 29C480 0039C480 100082D8 */  lqc2       $vf2, 0x10($4)
    /* 29C484 0039C484 200083D8 */  lqc2       $vf3, 0x20($4)
    /* 29C488 0039C488 300084D8 */  lqc2       $vf4, 0x30($4)
    /* 29C48C 0039C48C 000065D8 */  lqc2       $vf5, 0x0($3)
    /* 29C490 0039C490 100066D8 */  lqc2       $vf6, 0x10($3)
    /* 29C494 0039C494 200067D8 */  lqc2       $vf7, 0x20($3)
    /* 29C498 0039C498 300068D8 */  lqc2       $vf8, 0x30($3)
    /* 29C49C 0039C49C BC29E14B */  vmulax.xyzw $ACC, $vf5, $vf1x
    /* 29C4A0 0039C4A0 BD30E14B */  vmadday.xyzw $ACC, $vf6, $vf1y
    /* 29C4A4 0039C4A4 4A3AE14B */  vmaddz.xyzw $vf9, $vf7, $vf1z
    /* 29C4A8 0039C4A8 BC29E24B */  vmulax.xyzw $ACC, $vf5, $vf2x
    /* 29C4AC 0039C4AC BD30E24B */  vmadday.xyzw $ACC, $vf6, $vf2y
    /* 29C4B0 0039C4B0 8A3AE24B */  vmaddz.xyzw $vf10, $vf7, $vf2z
    /* 29C4B4 0039C4B4 BC29E34B */  vmulax.xyzw $ACC, $vf5, $vf3x
    /* 29C4B8 0039C4B8 BD30E34B */  vmadday.xyzw $ACC, $vf6, $vf3y
    /* 29C4BC 0039C4BC CA3AE34B */  vmaddz.xyzw $vf11, $vf7, $vf3z
    /* 29C4C0 0039C4C0 BC29E44B */  vmulax.xyzw $ACC, $vf5, $vf4x
    /* 29C4C4 0039C4C4 BD30E44B */  vmadday.xyzw $ACC, $vf6, $vf4y
    /* 29C4C8 0039C4C8 BE38E44B */  vmaddaz.xyzw $ACC, $vf7, $vf4z
    /* 29C4CC 0039C4CC 0B43E04B */  vmaddw.xyzw $vf12, $vf8, $vf0w
    /* 29C4D0 0039C4D0 000049F8 */  sqc2       $vf9, 0x0($2)
    /* 29C4D4 0039C4D4 10004AF8 */  sqc2       $vf10, 0x10($2)
    /* 29C4D8 0039C4D8 20004BF8 */  sqc2       $vf11, 0x20($2)
    /* 29C4DC 0039C4DC 30004CF8 */  sqc2       $vf12, 0x30($2)
    /* 29C4E0 0039C4E0 01005226 */  addiu      $18, $18, 0x1
    /* 29C4E4 0039C4E4 2A105402 */  slt        $2, $18, $20
    /* 29C4E8 0039C4E8 C2FF4014 */  bnez       $2, .L0039C3F4
    /* 29C4EC 0039C4EC 00000000 */   nop
    /* 29C4F0 0039C4F0 83000010 */  b          .L0039C700
    /* 29C4F4 0039C4F4 00000000 */   nop
  .L0039C4F8:
    /* 29C4F8 0039C4F8 00406230 */  andi       $2, $3, 0x4000
    /* 29C4FC 0039C4FC 27004010 */  beqz       $2, .L0039C59C
    /* 29C500 0039C500 00000000 */   nop
    /* 29C504 0039C504 40000224 */  addiu      $2, $0, 0x40
    /* 29C508 0039C508 18088202 */  mult       $1, $20, $2
    /* 29C50C 0039C50C 20280002 */  add        $5, $16, $0 /* handwritten instruction */
    /* 29C510 0039C510 20206002 */  add        $4, $19, $0 /* handwritten instruction */
    /* 29C514 0039C514 20182002 */  add        $3, $17, $0 /* handwritten instruction */
    /* 29C518 0039C518 20086100 */  add        $1, $3, $1 /* handwritten instruction */
  .L0039C51C:
    /* 29C51C 0039C51C 0000A1D8 */  lqc2       $vf1, 0x0($5)
    /* 29C520 0039C520 1000A2D8 */  lqc2       $vf2, 0x10($5)
    /* 29C524 0039C524 2000A3D8 */  lqc2       $vf3, 0x20($5)
    /* 29C528 0039C528 3000A4D8 */  lqc2       $vf4, 0x30($5)
    /* 29C52C 0039C52C 000085D8 */  lqc2       $vf5, 0x0($4)
    /* 29C530 0039C530 100086D8 */  lqc2       $vf6, 0x10($4)
    /* 29C534 0039C534 200087D8 */  lqc2       $vf7, 0x20($4)
    /* 29C538 0039C538 300088D8 */  lqc2       $vf8, 0x30($4)
    /* 29C53C 0039C53C BC29E14B */  vmulax.xyzw $ACC, $vf5, $vf1x
    /* 29C540 0039C540 BD30E14B */  vmadday.xyzw $ACC, $vf6, $vf1y
    /* 29C544 0039C544 4A3AE14B */  vmaddz.xyzw $vf9, $vf7, $vf1z
    /* 29C548 0039C548 BC29E24B */  vmulax.xyzw $ACC, $vf5, $vf2x
    /* 29C54C 0039C54C BD30E24B */  vmadday.xyzw $ACC, $vf6, $vf2y
    /* 29C550 0039C550 8A3AE24B */  vmaddz.xyzw $vf10, $vf7, $vf2z
    /* 29C554 0039C554 BC29E34B */  vmulax.xyzw $ACC, $vf5, $vf3x
    /* 29C558 0039C558 BD30E34B */  vmadday.xyzw $ACC, $vf6, $vf3y
    /* 29C55C 0039C55C CA3AE34B */  vmaddz.xyzw $vf11, $vf7, $vf3z
    /* 29C560 0039C560 BC29E44B */  vmulax.xyzw $ACC, $vf5, $vf4x
    /* 29C564 0039C564 BD30E44B */  vmadday.xyzw $ACC, $vf6, $vf4y
    /* 29C568 0039C568 BE38E44B */  vmaddaz.xyzw $ACC, $vf7, $vf4z
    /* 29C56C 0039C56C 0B43E04B */  vmaddw.xyzw $vf12, $vf8, $vf0w
    /* 29C570 0039C570 000069F8 */  sqc2       $vf9, 0x0($3)
    /* 29C574 0039C574 10006AF8 */  sqc2       $vf10, 0x10($3)
    /* 29C578 0039C578 20006BF8 */  sqc2       $vf11, 0x20($3)
    /* 29C57C 0039C57C 30006CF8 */  sqc2       $vf12, 0x30($3)
    /* 29C580 0039C580 40006320 */  addi       $3, $3, 0x40 /* handwritten instruction */
    /* 29C584 0039C584 2028A200 */  add        $5, $5, $2 /* handwritten instruction */
    /* 29C588 0039C588 20208200 */  add        $4, $4, $2 /* handwritten instruction */
    /* 29C58C 0039C58C E3FF2314 */  bne        $1, $3, .L0039C51C
    /* 29C590 0039C590 00000000 */   nop
    /* 29C594 0039C594 5A000010 */  b          .L0039C700
    /* 29C598 0039C598 00000000 */   nop
  .L0039C59C:
    /* 29C59C 0039C59C 7C00A0AF */  sw         $0, 0x7C($29)
    /* 29C5A0 0039C5A0 C0A50F0C */  jal        func_003e9700
    /* 29C5A4 0039C5A4 0400448E */   lw        $4, 0x4($18)
    /* 29C5A8 0039C5A8 2D284000 */  daddu      $5, $2, $0
    /* 29C5AC 0039C5AC 58820F0C */  jal        func_003e0960
    /* 29C5B0 0039C5B0 7000A427 */   addiu     $4, $29, 0x70
    /* 29C5B4 0039C5B4 7000A327 */  addiu      $3, $29, 0x70
    /* 29C5B8 0039C5B8 40000224 */  addiu      $2, $0, 0x40
    /* 29C5BC 0039C5BC 18088202 */  mult       $1, $20, $2
    /* 29C5C0 0039C5C0 20300002 */  add        $6, $16, $0 /* handwritten instruction */
    /* 29C5C4 0039C5C4 20286002 */  add        $5, $19, $0 /* handwritten instruction */
    /* 29C5C8 0039C5C8 20202002 */  add        $4, $17, $0 /* handwritten instruction */
    /* 29C5CC 0039C5CC 00006DD8 */  lqc2       $vf13, 0x0($3)
    /* 29C5D0 0039C5D0 10006ED8 */  lqc2       $vf14, 0x10($3)
    /* 29C5D4 0039C5D4 20006FD8 */  lqc2       $vf15, 0x20($3)
    /* 29C5D8 0039C5D8 300070D8 */  lqc2       $vf16, 0x30($3)
    /* 29C5DC 0039C5DC 20088100 */  add        $1, $4, $1 /* handwritten instruction */
  .L0039C5E0:
    /* 29C5E0 0039C5E0 0000C1D8 */  lqc2       $vf1, 0x0($6)
    /* 29C5E4 0039C5E4 1000C2D8 */  lqc2       $vf2, 0x10($6)
    /* 29C5E8 0039C5E8 2000C3D8 */  lqc2       $vf3, 0x20($6)
    /* 29C5EC 0039C5EC 3000C4D8 */  lqc2       $vf4, 0x30($6)
    /* 29C5F0 0039C5F0 0000A5D8 */  lqc2       $vf5, 0x0($5)
    /* 29C5F4 0039C5F4 1000A6D8 */  lqc2       $vf6, 0x10($5)
    /* 29C5F8 0039C5F8 2000A7D8 */  lqc2       $vf7, 0x20($5)
    /* 29C5FC 0039C5FC 3000A8D8 */  lqc2       $vf8, 0x30($5)
    /* 29C600 0039C600 BC29E14B */  vmulax.xyzw $ACC, $vf5, $vf1x
    /* 29C604 0039C604 BD30E14B */  vmadday.xyzw $ACC, $vf6, $vf1y
    /* 29C608 0039C608 4A3AE14B */  vmaddz.xyzw $vf9, $vf7, $vf1z
    /* 29C60C 0039C60C BC29E24B */  vmulax.xyzw $ACC, $vf5, $vf2x
    /* 29C610 0039C610 BD30E24B */  vmadday.xyzw $ACC, $vf6, $vf2y
    /* 29C614 0039C614 8A3AE24B */  vmaddz.xyzw $vf10, $vf7, $vf2z
    /* 29C618 0039C618 BC29E34B */  vmulax.xyzw $ACC, $vf5, $vf3x
    /* 29C61C 0039C61C BD30E34B */  vmadday.xyzw $ACC, $vf6, $vf3y
    /* 29C620 0039C620 CA3AE34B */  vmaddz.xyzw $vf11, $vf7, $vf3z
    /* 29C624 0039C624 BC29E44B */  vmulax.xyzw $ACC, $vf5, $vf4x
    /* 29C628 0039C628 BD30E44B */  vmadday.xyzw $ACC, $vf6, $vf4y
    /* 29C62C 0039C62C BE38E44B */  vmaddaz.xyzw $ACC, $vf7, $vf4z
    /* 29C630 0039C630 0B43E04B */  vmaddw.xyzw $vf12, $vf8, $vf0w
    /* 29C634 0039C634 BC69E94B */  vmulax.xyzw $ACC, $vf13, $vf9x
    /* 29C638 0039C638 BD70E94B */  vmadday.xyzw $ACC, $vf14, $vf9y
    /* 29C63C 0039C63C 4A78E94B */  vmaddz.xyzw $vf1, $vf15, $vf9z
    /* 29C640 0039C640 BC69EA4B */  vmulax.xyzw $ACC, $vf13, $vf10x
    /* 29C644 0039C644 BD70EA4B */  vmadday.xyzw $ACC, $vf14, $vf10y
    /* 29C648 0039C648 8A78EA4B */  vmaddz.xyzw $vf2, $vf15, $vf10z
    /* 29C64C 0039C64C BC69EB4B */  vmulax.xyzw $ACC, $vf13, $vf11x
    /* 29C650 0039C650 BD70EB4B */  vmadday.xyzw $ACC, $vf14, $vf11y
    /* 29C654 0039C654 CA78EB4B */  vmaddz.xyzw $vf3, $vf15, $vf11z
    /* 29C658 0039C658 BC69EC4B */  vmulax.xyzw $ACC, $vf13, $vf12x
    /* 29C65C 0039C65C BD70EC4B */  vmadday.xyzw $ACC, $vf14, $vf12y
    /* 29C660 0039C660 BE78EC4B */  vmaddaz.xyzw $ACC, $vf15, $vf12z
    /* 29C664 0039C664 0B81E04B */  vmaddw.xyzw $vf4, $vf16, $vf0w
    /* 29C668 0039C668 000081F8 */  sqc2       $vf1, 0x0($4)
    /* 29C66C 0039C66C 100082F8 */  sqc2       $vf2, 0x10($4)
    /* 29C670 0039C670 200083F8 */  sqc2       $vf3, 0x20($4)
    /* 29C674 0039C674 300084F8 */  sqc2       $vf4, 0x30($4)
    /* 29C678 0039C678 40008420 */  addi       $4, $4, 0x40 /* handwritten instruction */
    /* 29C67C 0039C67C 2030C200 */  add        $6, $6, $2 /* handwritten instruction */
    /* 29C680 0039C680 2028A200 */  add        $5, $5, $2 /* handwritten instruction */
    /* 29C684 0039C684 D6FF2414 */  bne        $1, $4, .L0039C5E0
    /* 29C688 0039C688 00000000 */   nop
    /* 29C68C 0039C68C 1C000010 */  b          .L0039C700
    /* 29C690 0039C690 00000000 */   nop
  .L0039C694:
    /* 29C694 0039C694 0000A68C */  lw         $6, 0x0($5)
    /* 29C698 0039C698 2B080600 */  sltu       $1, $0, $6
    /* 29C69C 0039C69C 18002010 */  beqz       $1, .L0039C700
    /* 29C6A0 0039C6A0 2D400000 */   daddu     $8, $0, $0
    /* 29C6A4 0039C6A4 0200023C */  lui        $2, (0x20003 >> 16)
    /* 29C6A8 0039C6A8 2D382002 */  daddu      $7, $17, $0
    /* 29C6AC 0039C6AC 803F053C */  lui        $5, (0x3F800000 >> 16)
    /* 29C6B0 0039C6B0 03004434 */  ori        $4, $2, (0x20003 & 0xFFFF)
  .L0039C6B4:
    /* 29C6B4 0039C6B4 2800E5AC */  sw         $5, 0x28($7)
    /* 29C6B8 0039C6B8 01000825 */  addiu      $8, $8, 0x1
    /* 29C6BC 0039C6BC 1400E5AC */  sw         $5, 0x14($7)
    /* 29C6C0 0039C6C0 2B100601 */  sltu       $2, $8, $6
    /* 29C6C4 0039C6C4 0000E5AC */  sw         $5, 0x0($7)
    /* 29C6C8 0039C6C8 1000E0AC */  sw         $0, 0x10($7)
    /* 29C6CC 0039C6CC 0800E0AC */  sw         $0, 0x8($7)
    /* 29C6D0 0039C6D0 0400E0AC */  sw         $0, 0x4($7)
    /* 29C6D4 0039C6D4 2400E0AC */  sw         $0, 0x24($7)
    /* 29C6D8 0039C6D8 2000E0AC */  sw         $0, 0x20($7)
    /* 29C6DC 0039C6DC 1800E0AC */  sw         $0, 0x18($7)
    /* 29C6E0 0039C6E0 3800E0AC */  sw         $0, 0x38($7)
    /* 29C6E4 0039C6E4 3400E0AC */  sw         $0, 0x34($7)
    /* 29C6E8 0039C6E8 3000E0AC */  sw         $0, 0x30($7)
    /* 29C6EC 0039C6EC 0C00E38C */  lw         $3, 0xC($7)
    /* 29C6F0 0039C6F0 25186400 */  or         $3, $3, $4
    /* 29C6F4 0039C6F4 0C00E3AC */  sw         $3, 0xC($7)
    /* 29C6F8 0039C6F8 EEFF4014 */  bnez       $2, .L0039C6B4
    /* 29C6FC 0039C6FC 4000E724 */   addiu     $7, $7, 0x40
  .L0039C700:
    /* 29C700 0039C700 2D102002 */  daddu      $2, $17, $0
    /* 29C704 0039C704 6000BFDF */  ld         $31, 0x60($29)
    /* 29C708 0039C708 5000B57B */  lq         $21, 0x50($29)
    /* 29C70C 0039C70C 4000B47B */  lq         $20, 0x40($29)
    /* 29C710 0039C710 3000B37B */  lq         $19, 0x30($29)
    /* 29C714 0039C714 2000B27B */  lq         $18, 0x20($29)
    /* 29C718 0039C718 1000B17B */  lq         $17, 0x10($29)
    /* 29C71C 0039C71C 0000B07B */  lq         $16, 0x0($29)
    /* 29C720 0039C720 0800E003 */  jr         $31
    /* 29C724 0039C724 3001BD27 */   addiu     $29, $29, 0x130
    /* 29C728 0039C728 00000000 */  nop
    /* 29C72C 0039C72C 00000000 */  nop
.size func_0039c360, 0x3d0
