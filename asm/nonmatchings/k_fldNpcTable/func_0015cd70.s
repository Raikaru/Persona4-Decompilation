.section .text
.set noat
.set noreorder
glabel func_0015cd70
    /* 5CD70 0015CD70 80FFBD27 */  addiu      $29, $29, -0x80
    /* 5CD74 0015CD74 2000BFFF */  sd         $31, 0x20($29)
    /* 5CD78 0015CD78 1000B17F */  sq         $17, 0x10($29)
    /* 5CD7C 0015CD7C 0000B07F */  sq         $16, 0x0($29)
    /* 5CD80 0015CD80 2D888000 */  daddu      $17, $4, $0
    /* 5CD84 0015CD84 04002016 */  bnez       $17, .L0015CD98
    /* 5CD88 0015CD88 00000000 */   nop
    /* 5CD8C 0015CD8C 01000224 */  addiu      $2, $0, 0x1
    /* 5CD90 0015CD90 59000010 */  b          .L0015CEF8
    /* 5CD94 0015CD94 00000000 */   nop
  .L0015CD98:
    /* 5CD98 0015CD98 B03B050C */  jal        func_0014eec0
    /* 5CD9C 0015CD9C 00000000 */   nop
    /* 5CDA0 0015CDA0 27004014 */  bnez       $2, .L0015CE40
    /* 5CDA4 0015CDA4 00000000 */   nop
    /* 5CDA8 0015CDA8 2D202002 */  daddu      $4, $17, $0
    /* 5CDAC 0015CDAC F054110C */  jal        func_004553c0
    /* 5CDB0 0015CDB0 00000000 */   nop
    /* 5CDB4 0015CDB4 4F004010 */  beqz       $2, .L0015CEF4
    /* 5CDB8 0015CDB8 00000000 */   nop
    /* 5CDBC 0015CDBC 5F00043C */  lui        $4, %hi(D_005F07C0)
    /* 5CDC0 0015CDC0 C0078424 */  addiu      $4, $4, %lo(D_005F07C0)
    /* 5CDC4 0015CDC4 58010524 */  addiu      $5, $0, 0x158
    /* 5CDC8 0015CDC8 A43A110C */  jal        func_0044ea90
    /* 5CDCC 0015CDCC 00000000 */   nop
    /* 5CDD0 0015CDD0 1801258E */  lw         $5, 0x118($17)
    /* 5CDD4 0015CDD4 01000424 */  addiu      $4, $0, 0x1
    /* 5CDD8 0015CDD8 0400063C */  lui        $6, (0x40000 >> 16)
    /* 5CDDC 0015CDDC 8800023C */  lui        $2, %hi(D_008873F4)
    /* 5CDE0 0015CDE0 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 5CDE4 0015CDE4 09F84000 */  jalr       $2
    /* 5CDE8 0015CDE8 00000000 */   nop
    /* 5CDEC 0015CDEC 2D804000 */  daddu      $16, $2, $0
    /* 5CDF0 0015CDF0 A054050C */  jal        func_00155280
    /* 5CDF4 0015CDF4 00000000 */   nop
    /* 5CDF8 0015CDF8 E01850AC */  sw         $16, 0x18E0($2)
    /* 5CDFC 0015CDFC 1801308E */  lw         $16, 0x118($17)
    /* 5CE00 0015CE00 A054050C */  jal        func_00155280
    /* 5CE04 0015CE04 00000000 */   nop
    /* 5CE08 0015CE08 E41850AC */  sw         $16, 0x18E4($2)
    /* 5CE0C 0015CE0C A054050C */  jal        func_00155280
    /* 5CE10 0015CE10 00000000 */   nop
    /* 5CE14 0015CE14 1801268E */  lw         $6, 0x118($17)
    /* 5CE18 0015CE18 E018448C */  lw         $4, 0x18E0($2)
    /* 5CE1C 0015CE1C 1001258E */  lw         $5, 0x110($17)
    /* 5CE20 0015CE20 04FE100C */  jal        func_0043f810
    /* 5CE24 0015CE24 00000000 */   nop
    /* 5CE28 0015CE28 2D202002 */  daddu      $4, $17, $0
    /* 5CE2C 0015CE2C F452110C */  jal        func_00454bd0
    /* 5CE30 0015CE30 00000000 */   nop
    /* 5CE34 0015CE34 01000224 */  addiu      $2, $0, 0x1
    /* 5CE38 0015CE38 2F000010 */  b          .L0015CEF8
    /* 5CE3C 0015CE3C 00000000 */   nop
  .L0015CE40:
    /* 5CE40 0015CE40 B09D828F */  lw         $2, -0x6250($28)
    /* 5CE44 0015CE44 3000A427 */  addiu      $4, $29, 0x30
    /* 5CE48 0015CE48 5F00053C */  lui        $5, %hi(D_005F0810)
    /* 5CE4C 0015CE4C 1008A524 */  addiu      $5, $5, %lo(D_005F0810)
    /* 5CE50 0015CE50 0000468C */  lw         $6, 0x0($2)
    /* 5CE54 0015CE54 0400478C */  lw         $7, 0x4($2)
    /* 5CE58 0015CE58 2208110C */  jal        func_00442088
    /* 5CE5C 0015CE5C 00000000 */   nop
    /* 5CE60 0015CE60 3000A427 */  addiu      $4, $29, 0x30
    /* 5CE64 0015CE64 7C00A527 */  addiu      $5, $29, 0x7C
    /* 5CE68 0015CE68 DC57110C */  jal        func_00455f70
    /* 5CE6C 0015CE6C 00000000 */   nop
    /* 5CE70 0015CE70 2D884000 */  daddu      $17, $2, $0
    /* 5CE74 0015CE74 1C002012 */  beqz       $17, .L0015CEE8
    /* 5CE78 0015CE78 00000000 */   nop
    /* 5CE7C 0015CE7C 5F00043C */  lui        $4, %hi(D_005F07C0)
    /* 5CE80 0015CE80 C0078424 */  addiu      $4, $4, %lo(D_005F07C0)
    /* 5CE84 0015CE84 72010524 */  addiu      $5, $0, 0x172
    /* 5CE88 0015CE88 A43A110C */  jal        func_0044ea90
    /* 5CE8C 0015CE8C 00000000 */   nop
    /* 5CE90 0015CE90 7C00A58F */  lw         $5, 0x7C($29)
    /* 5CE94 0015CE94 01000424 */  addiu      $4, $0, 0x1
    /* 5CE98 0015CE98 0400063C */  lui        $6, (0x40000 >> 16)
    /* 5CE9C 0015CE9C 8800023C */  lui        $2, %hi(D_008873F4)
    /* 5CEA0 0015CEA0 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 5CEA4 0015CEA4 09F84000 */  jalr       $2
    /* 5CEA8 0015CEA8 00000000 */   nop
    /* 5CEAC 0015CEAC 2D804000 */  daddu      $16, $2, $0
    /* 5CEB0 0015CEB0 A054050C */  jal        func_00155280
    /* 5CEB4 0015CEB4 00000000 */   nop
    /* 5CEB8 0015CEB8 E01850AC */  sw         $16, 0x18E0($2)
    /* 5CEBC 0015CEBC 7C00B08F */  lw         $16, 0x7C($29)
    /* 5CEC0 0015CEC0 A054050C */  jal        func_00155280
    /* 5CEC4 0015CEC4 00000000 */   nop
    /* 5CEC8 0015CEC8 E41850AC */  sw         $16, 0x18E4($2)
    /* 5CECC 0015CECC A054050C */  jal        func_00155280
    /* 5CED0 0015CED0 00000000 */   nop
    /* 5CED4 0015CED4 7C00A68F */  lw         $6, 0x7C($29)
    /* 5CED8 0015CED8 E018448C */  lw         $4, 0x18E0($2)
    /* 5CEDC 0015CEDC 2D282002 */  daddu      $5, $17, $0
    /* 5CEE0 0015CEE0 04FE100C */  jal        func_0043f810
    /* 5CEE4 0015CEE4 00000000 */   nop
  .L0015CEE8:
    /* 5CEE8 0015CEE8 01000224 */  addiu      $2, $0, 0x1
    /* 5CEEC 0015CEEC 02000010 */  b          .L0015CEF8
    /* 5CEF0 0015CEF0 00000000 */   nop
  .L0015CEF4:
    /* 5CEF4 0015CEF4 2D100000 */  daddu      $2, $0, $0
  .L0015CEF8:
    /* 5CEF8 0015CEF8 2000BFDF */  ld         $31, 0x20($29)
    /* 5CEFC 0015CEFC 1000B17B */  lq         $17, 0x10($29)
    /* 5CF00 0015CF00 0000B07B */  lq         $16, 0x0($29)
    /* 5CF04 0015CF04 8000BD27 */  addiu      $29, $29, 0x80
    /* 5CF08 0015CF08 0800E003 */  jr         $31
    /* 5CF0C 0015CF0C 00000000 */   nop
.size func_0015cd70, 0x1a0
