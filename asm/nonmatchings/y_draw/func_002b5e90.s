.section .text
.set noat
.set noreorder
glabel func_002b5e90
    /* 1B5E90 002B5E90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1B5E94 002B5E94 0000A5FF */  sd         $5, 0x0($29)
    /* 1B5E98 002B5E98 0800A6FF */  sd         $6, 0x8($29)
    /* 1B5E9C 002B5E9C 3800848C */  lw         $4, 0x38($4)
    /* 1B5EA0 002B5EA0 4C0180A4 */  sh         $0, 0x14C($4)
    /* 1B5EA4 002B5EA4 500187AC */  sw         $7, 0x150($4)
    /* 1B5EA8 002B5EA8 0000A1C7 */  lwc1       $f1, 0x0($29)
    /* 1B5EAC 002B5EAC 0400A0C7 */  lwc1       $f0, 0x4($29)
    /* 1B5EB0 002B5EB0 3C0181E4 */  swc1       $f1, 0x13C($4)
    /* 1B5EB4 002B5EB4 400180E4 */  swc1       $f0, 0x140($4)
    /* 1B5EB8 002B5EB8 0800A1C7 */  lwc1       $f1, 0x8($29)
    /* 1B5EBC 002B5EBC 0C00A0C7 */  lwc1       $f0, 0xC($29)
    /* 1B5EC0 002B5EC0 440181E4 */  swc1       $f1, 0x144($4)
    /* 1B5EC4 002B5EC4 480180E4 */  swc1       $f0, 0x148($4)
    /* 1B5EC8 002B5EC8 02000324 */  addiu      $3, $0, 0x2
    /* 1B5ECC 002B5ECC 560183A4 */  sh         $3, 0x156($4)
    /* 1B5ED0 002B5ED0 540180A0 */  sb         $0, 0x154($4)
    /* 1B5ED4 002B5ED4 000083A0 */  sb         $3, 0x0($4)
    /* 1B5ED8 002B5ED8 1000BD27 */  addiu      $29, $29, 0x10
    /* 1B5EDC 002B5EDC 0800E003 */  jr         $31
    /* 1B5EE0 002B5EE0 00000000 */   nop
    /* 1B5EE4 002B5EE4 00000000 */  nop
    /* 1B5EE8 002B5EE8 00000000 */  nop
    /* 1B5EEC 002B5EEC 00000000 */  nop
.size func_002b5e90, 0x60
