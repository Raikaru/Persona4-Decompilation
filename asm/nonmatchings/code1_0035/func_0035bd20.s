.section .text
.set noat
.set noreorder
glabel func_0035bd20
    /* 25BD20 0035BD20 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 25BD24 0035BD24 1000BFFF */  sd         $31, 0x10($29)
    /* 25BD28 0035BD28 0C00B7E7 */  swc1       $f23, 0xC($29)
    /* 25BD2C 0035BD2C 0800B6E7 */  swc1       $f22, 0x8($29)
    /* 25BD30 0035BD30 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 25BD34 0035BD34 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 25BD38 0035BD38 2800A4FF */  sd         $4, 0x28($29)
    /* 25BD3C 0035BD3C 3000A5FF */  sd         $5, 0x30($29)
    /* 25BD40 0035BD40 3800A6FF */  sd         $6, 0x38($29)
    /* 25BD44 0035BD44 3C00B7C7 */  lwc1       $f23, 0x3C($29)
    /* 25BD48 0035BD48 6500023C */  lui        $2, %hi(D_0064CD30)
    /* 25BD4C 0035BD4C 30CD43DC */  ld         $3, %lo(D_0064CD30)($2)
    /* 25BD50 0035BD50 6500023C */  lui        $2, %hi(D_0064CD38)
    /* 25BD54 0035BD54 38CD40C4 */  lwc1       $f0, %lo(D_0064CD38)($2)
    /* 25BD58 0035BD58 5000A3FF */  sd         $3, 0x50($29)
    /* 25BD5C 0035BD5C 5800A0E7 */  swc1       $f0, 0x58($29)
    /* 25BD60 0035BD60 00A08044 */  mtc1       $0, $f20
    /* 25BD64 0035BD64 2800A1C7 */  lwc1       $f1, 0x28($29)
    /* 25BD68 0035BD68 3800A0C7 */  lwc1       $f0, 0x38($29)
    /* 25BD6C 0035BD6C 01080046 */  sub.s      $f0, $f1, $f0
    /* 25BD70 0035BD70 4000A0E7 */  swc1       $f0, 0x40($29)
    /* 25BD74 0035BD74 2C00A0C7 */  lwc1       $f0, 0x2C($29)
    /* 25BD78 0035BD78 01001746 */  sub.s      $f0, $f0, $f23
    /* 25BD7C 0035BD7C 4400A0E7 */  swc1       $f0, 0x44($29)
    /* 25BD80 0035BD80 A041023C */  lui        $2, (0x41A00000 >> 16)
    /* 25BD84 0035BD84 4800A2AF */  sw         $2, 0x48($29)
    /* 25BD88 0035BD88 4000A427 */  addiu      $4, $29, 0x40
    /* 25BD8C 0035BD8C 2D288000 */  daddu      $5, $4, $0
    /* 25BD90 0035BD90 2C900F0C */  jal        func_003e40b0
    /* 25BD94 0035BD94 00000000 */   nop
    /* 25BD98 0035BD98 5400B6C7 */  lwc1       $f22, 0x54($29)
    /* 25BD9C 0035BD9C 5800B5C7 */  lwc1       $f21, 0x58($29)
    /* 25BDA0 0035BDA0 4800A4C7 */  lwc1       $f4, 0x48($29)
    /* 25BDA4 0035BDA4 4000A3C7 */  lwc1       $f3, 0x40($29)
    /* 25BDA8 0035BDA8 5000A1C7 */  lwc1       $f1, 0x50($29)
    /* 25BDAC 0035BDAC 4400A0C7 */  lwc1       $f0, 0x44($29)
    /* 25BDB0 0035BDB0 1A001646 */  mula.s     $f0, $f22
    /* 25BDB4 0035BDB4 86A00046 */  mov.s      $f2, $f20
    /* 25BDB8 0035BDB8 1E180146 */  madda.s    $f3, $f1
    /* 25BDBC 0035BDBC 5C201546 */  madd.s     $f1, $f4, $f21
    /* 25BDC0 0035BDC0 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 25BDC4 0035BDC4 00008244 */  mtc1       $2, $f0
    /* 25BDC8 0035BDC8 18101446 */  adda.s     $f2, $f20
    /* 25BDCC 0035BDCC 1C050146 */  madd.s     $f20, $f0, $f1
    /* 25BDD0 0035BDD0 3000A1C7 */  lwc1       $f1, 0x30($29)
    /* 25BDD4 0035BDD4 3800A0C7 */  lwc1       $f0, 0x38($29)
    /* 25BDD8 0035BDD8 01080046 */  sub.s      $f0, $f1, $f0
    /* 25BDDC 0035BDDC 4000A0E7 */  swc1       $f0, 0x40($29)
    /* 25BDE0 0035BDE0 3400A0C7 */  lwc1       $f0, 0x34($29)
    /* 25BDE4 0035BDE4 01001746 */  sub.s      $f0, $f0, $f23
    /* 25BDE8 0035BDE8 4400A0E7 */  swc1       $f0, 0x44($29)
    /* 25BDEC 0035BDEC A041023C */  lui        $2, (0x41A00000 >> 16)
    /* 25BDF0 0035BDF0 4800A2AF */  sw         $2, 0x48($29)
    /* 25BDF4 0035BDF4 4000A427 */  addiu      $4, $29, 0x40
    /* 25BDF8 0035BDF8 2D288000 */  daddu      $5, $4, $0
    /* 25BDFC 0035BDFC 2C900F0C */  jal        func_003e40b0
    /* 25BE00 0035BE00 00000000 */   nop
    /* 25BE04 0035BE04 4800A4C7 */  lwc1       $f4, 0x48($29)
    /* 25BE08 0035BE08 4000A3C7 */  lwc1       $f3, 0x40($29)
    /* 25BE0C 0035BE0C 5000A1C7 */  lwc1       $f1, 0x50($29)
    /* 25BE10 0035BE10 4400A0C7 */  lwc1       $f0, 0x44($29)
    /* 25BE14 0035BE14 1A001646 */  mula.s     $f0, $f22
    /* 25BE18 0035BE18 00108044 */  mtc1       $0, $f2
    /* 25BE1C 0035BE1C 00000000 */  nop
    /* 25BE20 0035BE20 1E180146 */  madda.s    $f3, $f1
    /* 25BE24 0035BE24 5C201546 */  madd.s     $f1, $f4, $f21
    /* 25BE28 0035BE28 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 25BE2C 0035BE2C 00008244 */  mtc1       $2, $f0
    /* 25BE30 0035BE30 18101446 */  adda.s     $f2, $f20
    /* 25BE34 0035BE34 1C050146 */  madd.s     $f20, $f0, $f1
    /* 25BE38 0035BE38 36A00046 */  c.le.s     $f20, $f0
    /* 25BE3C 0035BE3C 02000145 */  bc1t       .L0035BE48
    /* 25BE40 0035BE40 00000000 */   nop
    /* 25BE44 0035BE44 06050046 */  mov.s      $f20, $f0
  .L0035BE48:
    /* 25BE48 0035BE48 06A00046 */  mov.s      $f0, $f20
    /* 25BE4C 0035BE4C 1000BFDF */  ld         $31, 0x10($29)
    /* 25BE50 0035BE50 0C00B7C7 */  lwc1       $f23, 0xC($29)
    /* 25BE54 0035BE54 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* 25BE58 0035BE58 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 25BE5C 0035BE5C 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 25BE60 0035BE60 6000BD27 */  addiu      $29, $29, 0x60
    /* 25BE64 0035BE64 0800E003 */  jr         $31
    /* 25BE68 0035BE68 00000000 */   nop
    /* 25BE6C 0035BE6C 00000000 */  nop
.size func_0035bd20, 0x150
