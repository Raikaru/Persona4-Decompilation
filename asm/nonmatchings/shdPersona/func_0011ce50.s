.section .text
.set noat
.set noreorder
glabel func_0011ce50
    /* 1CE50 0011CE50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1CE54 0011CE54 0000BFFF */  sd         $31, 0x0($29)
    /* 1CE58 0011CE58 3405858C */  lw         $5, 0x534($4)
    /* 1CE5C 0011CE5C 0100033C */  lui        $3, (0x10000 >> 16)
    /* 1CE60 0011CE60 2418A300 */  and        $3, $5, $3
    /* 1CE64 0011CE64 0C006010 */  beqz       $3, .L0011CE98
    /* 1CE68 0011CE68 00000000 */   nop
    /* 1CE6C 0011CE6C 20058484 */  lh         $4, 0x520($4)
    /* 1CE70 0011CE70 0A000324 */  addiu      $3, $0, 0xA
    /* 1CE74 0011CE74 13008314 */  bne        $4, $3, .L0011CEC4
    /* 1CE78 0011CE78 00000000 */   nop
    /* 1CE7C 0011CE7C 02000424 */  addiu      $4, $0, 0x2
    /* 1CE80 0011CE80 5E00053C */  lui        $5, %hi(D_005E4E20)
    /* 1CE84 0011CE84 204EA524 */  addiu      $5, $5, %lo(D_005E4E20)
    /* 1CE88 0011CE88 AC6B110C */  jal        func_0045aeb0
    /* 1CE8C 0011CE8C 00000000 */   nop
    /* 1CE90 0011CE90 0C000010 */  b          .L0011CEC4
    /* 1CE94 0011CE94 00000000 */   nop
  .L0011CE98:
    /* 1CE98 0011CE98 0200033C */  lui        $3, (0x20000 >> 16)
    /* 1CE9C 0011CE9C 2418A300 */  and        $3, $5, $3
    /* 1CEA0 0011CEA0 08006010 */  beqz       $3, .L0011CEC4
    /* 1CEA4 0011CEA4 00000000 */   nop
    /* 1CEA8 0011CEA8 20058384 */  lh         $3, 0x520($4)
    /* 1CEAC 0011CEAC 32006328 */  slti       $3, $3, 0x32
    /* 1CEB0 0011CEB0 04006014 */  bnez       $3, .L0011CEC4
    /* 1CEB4 0011CEB4 00000000 */   nop
    /* 1CEB8 0011CEB8 FFFD0324 */  addiu      $3, $0, -0x201
    /* 1CEBC 0011CEBC 2418A300 */  and        $3, $5, $3
    /* 1CEC0 0011CEC0 340583AC */  sw         $3, 0x534($4)
  .L0011CEC4:
    /* 1CEC4 0011CEC4 0000BFDF */  ld         $31, 0x0($29)
    /* 1CEC8 0011CEC8 1000BD27 */  addiu      $29, $29, 0x10
    /* 1CECC 0011CECC 0800E003 */  jr         $31
    /* 1CED0 0011CED0 00000000 */   nop
    /* 1CED4 0011CED4 00000000 */  nop
    /* 1CED8 0011CED8 00000000 */  nop
    /* 1CEDC 0011CEDC 00000000 */  nop
.size func_0011ce50, 0x90
