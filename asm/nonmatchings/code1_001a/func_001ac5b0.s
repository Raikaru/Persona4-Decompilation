.section .text
.set noat
.set noreorder
glabel func_001ac5b0
    /* AC5B0 001AC5B0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* AC5B4 001AC5B4 1000BFFF */  sd         $31, 0x10($29)
    /* AC5B8 001AC5B8 0000B07F */  sq         $16, 0x0($29)
    /* AC5BC 001AC5BC 2D808000 */  daddu      $16, $4, $0
    /* AC5C0 001AC5C0 06050424 */  addiu      $4, $0, 0x506
    /* AC5C4 001AC5C4 344F060C */  jal        func_00193cd0
    /* AC5C8 001AC5C8 00000000 */   nop
    /* AC5CC 001AC5CC 0D004014 */  bnez       $2, .L001AC604
    /* AC5D0 001AC5D0 00000000 */   nop
    /* AC5D4 001AC5D4 00080424 */  addiu      $4, $0, 0x800
    /* AC5D8 001AC5D8 344F060C */  jal        func_00193cd0
    /* AC5DC 001AC5DC 00000000 */   nop
    /* AC5E0 001AC5E0 08004014 */  bnez       $2, .L001AC604
    /* AC5E4 001AC5E4 00000000 */   nop
    /* AC5E8 001AC5E8 18000296 */  lhu        $2, 0x18($16)
    /* AC5EC 001AC5EC 00014234 */  ori        $2, $2, 0x100
    /* AC5F0 001AC5F0 180002A6 */  sh         $2, 0x18($16)
    /* AC5F4 001AC5F4 2D200002 */  daddu      $4, $16, $0
    /* AC5F8 001AC5F8 0F000524 */  addiu      $5, $0, 0xF
    /* AC5FC 001AC5FC 00C2060C */  jal        func_001b0800
    /* AC600 001AC600 00000000 */   nop
  .L001AC604:
    /* AC604 001AC604 1000BFDF */  ld         $31, 0x10($29)
    /* AC608 001AC608 0000B07B */  lq         $16, 0x0($29)
    /* AC60C 001AC60C 2000BD27 */  addiu      $29, $29, 0x20
    /* AC610 001AC610 0800E003 */  jr         $31
    /* AC614 001AC614 00000000 */   nop
    /* AC618 001AC618 00000000 */  nop
    /* AC61C 001AC61C 00000000 */  nop
.size func_001ac5b0, 0x70
