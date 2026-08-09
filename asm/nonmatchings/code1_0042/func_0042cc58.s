.section .text
.set noat
.set noreorder
glabel func_0042cc58
    /* 32CC58 0042CC58 7100023C */  lui        $2, %hi(D_0070DC88)
    /* 32CC5C 0042CC5C 88DC4724 */  addiu      $7, $2, %lo(D_0070DC88)
    /* 32CC60 0042CC60 1400E68C */  lw         $6, 0x14($7)
    /* 32CC64 0042CC64 0400C014 */  bnez       $6, .L0042CC78
    /* 32CC68 0042CC68 00000000 */   nop
    /* 32CC6C 0042CC6C 0080023C */  lui        $2, (0x80008005 >> 16)
    /* 32CC70 0042CC70 0800E003 */  jr         $31
    /* 32CC74 0042CC74 05804234 */   ori       $2, $2, (0x80008005 & 0xFFFF)
  .L0042CC78:
    /* 32CC78 0042CC78 1000E28C */  lw         $2, 0x10($7)
    /* 32CC7C 0042CC7C 00290600 */  sll        $5, $6, 4
    /* 32CC80 0042CC80 0000C48C */  lw         $4, 0x0($6)
    /* 32CC84 0042CC84 01004224 */  addiu      $2, $2, 0x1
    /* 32CC88 0042CC88 2800C0AC */  sw         $0, 0x28($6)
    /* 32CC8C 0042CC8C 1000E2AC */  sw         $2, 0x10($7)
    /* 32CC90 0042CC90 0C00C0AC */  sw         $0, 0xC($6)
    /* 32CC94 0042CC94 1400E4AC */  sw         $4, 0x14($7)
    /* 32CC98 0042CC98 0C00E38C */  lw         $3, 0xC($7)
    /* 32CC9C 0042CC9C 1800C0FC */  sd         $0, 0x18($6)
    /* 32CCA0 0042CCA0 01006324 */  addiu      $3, $3, 0x1
    /* 32CCA4 0042CCA4 0C00E3AC */  sw         $3, 0xC($7)
    /* 32CCA8 0042CCA8 0C00E28C */  lw         $2, 0xC($7)
    /* 32CCAC 0042CCAC 40100200 */  sll        $2, $2, 1
    /* 32CCB0 0042CCB0 FE034230 */  andi       $2, $2, 0x3FE
    /* 32CCB4 0042CCB4 01004234 */  ori        $2, $2, 0x1
    /* 32CCB8 0042CCB8 0800C2AC */  sw         $2, 0x8($6)
    /* 32CCBC 0042CCBC 0800C28C */  lw         $2, 0x8($6)
    /* 32CCC0 0042CCC0 0800E003 */  jr         $31
    /* 32CCC4 0042CCC4 2510A200 */   or        $2, $5, $2
.size func_0042cc58, 0x70
