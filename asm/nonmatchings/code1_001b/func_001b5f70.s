.section .text
.set noat
.set noreorder
glabel func_001b5f70
    /* B5F70 001B5F70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* B5F74 001B5F74 0000BFFF */  sd         $31, 0x0($29)
    /* B5F78 001B5F78 ACB3828F */  lw         $2, -0x4C54($28)
    /* B5F7C 001B5F7C FC0244AC */  sw         $4, 0x2FC($2)
    /* B5F80 001B5F80 ACB3828F */  lw         $2, -0x4C54($28)
    /* B5F84 001B5F84 040340AC */  sw         $0, 0x304($2)
    /* B5F88 001B5F88 ACB3828F */  lw         $2, -0x4C54($28)
    /* B5F8C 001B5F8C FC024424 */  addiu      $4, $2, 0x2FC
    /* B5F90 001B5F90 FC02438C */  lw         $3, 0x2FC($2)
    /* B5F94 001B5F94 40100300 */  sll        $2, $3, 1
    /* B5F98 001B5F98 21104300 */  addu       $2, $2, $3
    /* B5F9C 001B5F9C 80180200 */  sll        $3, $2, 2
    /* B5FA0 001B5FA0 5F00023C */  lui        $2, %hi(D_005F7180)
    /* B5FA4 001B5FA4 80714224 */  addiu      $2, $2, %lo(D_005F7180)
    /* B5FA8 001B5FA8 21104300 */  addu       $2, $2, $3
    /* B5FAC 001B5FAC 0000428C */  lw         $2, 0x0($2)
    /* B5FB0 001B5FB0 09F84000 */  jalr       $2
    /* B5FB4 001B5FB4 00000000 */   nop
    /* B5FB8 001B5FB8 0000BFDF */  ld         $31, 0x0($29)
    /* B5FBC 001B5FBC 1000BD27 */  addiu      $29, $29, 0x10
    /* B5FC0 001B5FC0 0800E003 */  jr         $31
    /* B5FC4 001B5FC4 00000000 */   nop
    /* B5FC8 001B5FC8 00000000 */  nop
    /* B5FCC 001B5FCC 00000000 */  nop
.size func_001b5f70, 0x60
