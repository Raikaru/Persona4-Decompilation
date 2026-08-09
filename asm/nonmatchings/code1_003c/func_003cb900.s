.section .text
.set noat
.set noreorder
glabel func_003cb900
    /* 2CB900 003CB900 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2CB904 003CB904 3D00063C */  lui        $6, %hi(func_003ca5a0)
    /* 2CB908 003CB908 3D00073C */  lui        $7, %hi(func_003ca6a0)
    /* 2CB90C 003CB90C 1000BFFF */  sd         $31, 0x10($29)
    /* 2CB910 003CB910 0C000424 */  addiu      $4, $0, 0xC
    /* 2CB914 003CB914 09050524 */  addiu      $5, $0, 0x509
    /* 2CB918 003CB918 A0A5C624 */  addiu      $6, $6, %lo(func_003ca5a0)
    /* 2CB91C 003CB91C A0A6E724 */  addiu      $7, $7, %lo(func_003ca6a0)
    /* 2CB920 003CB920 4CA20F0C */  jal        func_003e8930
    /* 2CB924 003CB924 0000B07F */   sq        $16, 0x0($29)
    /* 2CB928 003CB928 3D00063C */  lui        $6, %hi(func_003ca830)
    /* 2CB92C 003CB92C 3D00073C */  lui        $7, %hi(func_003ca8e0)
    /* 2CB930 003CB930 3D00083C */  lui        $8, %hi(func_003ca890)
    /* 2CB934 003CB934 2D804000 */  daddu      $16, $2, $0
    /* 2CB938 003CB938 1C000424 */  addiu      $4, $0, 0x1C
    /* 2CB93C 003CB93C 09050524 */  addiu      $5, $0, 0x509
    /* 2CB940 003CB940 30A8C624 */  addiu      $6, $6, %lo(func_003ca830)
    /* 2CB944 003CB944 E0A8E724 */  addiu      $7, $7, %lo(func_003ca8e0)
    /* 2CB948 003CB948 04A10F0C */  jal        func_003e8410
    /* 2CB94C 003CB94C 90A80825 */   addiu     $8, $8, %lo(func_003ca890)
    /* 2CB950 003CB950 3D00063C */  lui        $6, %hi(func_003cad40)
    /* 2CB954 003CB954 3D00073C */  lui        $7, %hi(func_003cad90)
    /* 2CB958 003CB958 3D00083C */  lui        $8, %hi(func_003cad80)
    /* 2CB95C 003CB95C 25800202 */  or         $16, $16, $2
    /* 2CB960 003CB960 08B782AF */  sw         $2, -0x48F8($28)
    /* 2CB964 003CB964 08000424 */  addiu      $4, $0, 0x8
    /* 2CB968 003CB968 09050524 */  addiu      $5, $0, 0x509
    /* 2CB96C 003CB96C 40ADC624 */  addiu      $6, $6, %lo(func_003cad40)
    /* 2CB970 003CB970 90ADE724 */  addiu      $7, $7, %lo(func_003cad90)
    /* 2CB974 003CB974 AC060F0C */  jal        func_003c1ab0
    /* 2CB978 003CB978 80AD0825 */   addiu     $8, $8, %lo(func_003cad80)
    /* 2CB97C 003CB97C 3D00063C */  lui        $6, %hi(func_003cae70)
    /* 2CB980 003CB980 3D00073C */  lui        $7, %hi(func_003caee0)
    /* 2CB984 003CB984 3D00083C */  lui        $8, %hi(func_003caea0)
    /* 2CB988 003CB988 25800202 */  or         $16, $16, $2
    /* 2CB98C 003CB98C 0CB782AF */  sw         $2, -0x48F4($28)
    /* 2CB990 003CB990 08000424 */  addiu      $4, $0, 0x8
    /* 2CB994 003CB994 09050524 */  addiu      $5, $0, 0x509
    /* 2CB998 003CB998 70AEC624 */  addiu      $6, $6, %lo(func_003cae70)
    /* 2CB99C 003CB99C E0AEE724 */  addiu      $7, $7, %lo(func_003caee0)
    /* 2CB9A0 003CB9A0 B8060F0C */  jal        func_003c1ae0
    /* 2CB9A4 003CB9A4 A0AE0825 */   addiu     $8, $8, %lo(func_003caea0)
    /* 2CB9A8 003CB9A8 3D00063C */  lui        $6, %hi(func_003cb1e0)
    /* 2CB9AC 003CB9AC 3D00073C */  lui        $7, %hi(func_003cb250)
    /* 2CB9B0 003CB9B0 3D00083C */  lui        $8, %hi(func_003cb210)
    /* 2CB9B4 003CB9B4 25800202 */  or         $16, $16, $2
    /* 2CB9B8 003CB9B8 10B782AF */  sw         $2, -0x48F0($28)
    /* 2CB9BC 003CB9BC 08000424 */  addiu      $4, $0, 0x8
    /* 2CB9C0 003CB9C0 09050524 */  addiu      $5, $0, 0x509
    /* 2CB9C4 003CB9C4 E0B1C624 */  addiu      $6, $6, %lo(func_003cb1e0)
    /* 2CB9C8 003CB9C8 50B2E724 */  addiu      $7, $7, %lo(func_003cb250)
    /* 2CB9CC 003CB9CC 480E0F0C */  jal        func_003c3920
    /* 2CB9D0 003CB9D0 10B20825 */   addiu     $8, $8, %lo(func_003cb210)
    /* 2CB9D4 003CB9D4 25800202 */  or         $16, $16, $2
    /* 2CB9D8 003CB9D8 14B782AF */  sw         $2, -0x48EC($28)
    /* 2CB9DC 003CB9DC 2D200000 */  daddu      $4, $0, $0
    /* 2CB9E0 003CB9E0 0E050524 */  addiu      $5, $0, 0x50E
    /* 2CB9E4 003CB9E4 2D300000 */  daddu      $6, $0, $0
    /* 2CB9E8 003CB9E8 2D380000 */  daddu      $7, $0, $0
    /* 2CB9EC 003CB9EC DC0A0F0C */  jal        func_003c2b70
    /* 2CB9F0 003CB9F0 2D400000 */   daddu     $8, $0, $0
    /* 2CB9F4 003CB9F4 25800202 */  or         $16, $16, $2
    /* 2CB9F8 003CB9F8 2D200000 */  daddu      $4, $0, $0
    /* 2CB9FC 003CB9FC 0E050524 */  addiu      $5, $0, 0x50E
    /* 2CBA00 003CBA00 2D300000 */  daddu      $6, $0, $0
    /* 2CBA04 003CBA04 2D380000 */  daddu      $7, $0, $0
    /* 2CBA08 003CBA08 40230F0C */  jal        func_003c8d00
    /* 2CBA0C 003CBA0C 2D400000 */   daddu     $8, $0, $0
    /* 2CBA10 003CBA10 3D00053C */  lui        $5, %hi(func_003cb720)
    /* 2CBA14 003CBA14 3D00063C */  lui        $6, %hi(func_003cb700)
    /* 2CBA18 003CBA18 3D00073C */  lui        $7, %hi(func_003cb770)
    /* 2CBA1C 003CBA1C 25800202 */  or         $16, $16, $2
    /* 2CBA20 003CBA20 0E050424 */  addiu      $4, $0, 0x50E
    /* 2CBA24 003CBA24 20B7A524 */  addiu      $5, $5, %lo(func_003cb720)
    /* 2CBA28 003CBA28 00B7C624 */  addiu      $6, $6, %lo(func_003cb700)
    /* 2CBA2C 003CBA2C E80A0F0C */  jal        func_003c2ba0
    /* 2CBA30 003CBA30 70B7E724 */   addiu     $7, $7, %lo(func_003cb770)
    /* 2CBA34 003CBA34 3D00053C */  lui        $5, %hi(func_003cb870)
    /* 2CBA38 003CBA38 3D00063C */  lui        $6, %hi(func_003cb820)
    /* 2CBA3C 003CBA3C 3D00073C */  lui        $7, %hi(func_003cb8d0)
    /* 2CBA40 003CBA40 25800202 */  or         $16, $16, $2
    /* 2CBA44 003CBA44 0E050424 */  addiu      $4, $0, 0x50E
    /* 2CBA48 003CBA48 70B8A524 */  addiu      $5, $5, %lo(func_003cb870)
    /* 2CBA4C 003CBA4C 20B8C624 */  addiu      $6, $6, %lo(func_003cb820)
    /* 2CBA50 003CBA50 4C230F0C */  jal        func_003c8d30
    /* 2CBA54 003CBA54 D0B8E724 */   addiu     $7, $7, %lo(func_003cb8d0)
    /* 2CBA58 003CBA58 25800202 */  or         $16, $16, $2
    /* 2CBA5C 003CBA5C 2D200000 */  daddu      $4, $0, $0
    /* 2CBA60 003CBA60 10050524 */  addiu      $5, $0, 0x510
    /* 2CBA64 003CBA64 2D300000 */  daddu      $6, $0, $0
    /* 2CBA68 003CBA68 2D380000 */  daddu      $7, $0, $0
    /* 2CBA6C 003CBA6C DC0A0F0C */  jal        func_003c2b70
    /* 2CBA70 003CBA70 2D400000 */   daddu     $8, $0, $0
    /* 2CBA74 003CBA74 25800202 */  or         $16, $16, $2
    /* 2CBA78 003CBA78 2D200000 */  daddu      $4, $0, $0
    /* 2CBA7C 003CBA7C 10050524 */  addiu      $5, $0, 0x510
    /* 2CBA80 003CBA80 2D300000 */  daddu      $6, $0, $0
    /* 2CBA84 003CBA84 2D380000 */  daddu      $7, $0, $0
    /* 2CBA88 003CBA88 40230F0C */  jal        func_003c8d00
    /* 2CBA8C 003CBA8C 2D400000 */   daddu     $8, $0, $0
    /* 2CBA90 003CBA90 3D00053C */  lui        $5, %hi(func_003cb790)
    /* 2CBA94 003CBA94 3D00063C */  lui        $6, %hi(func_003cb780)
    /* 2CBA98 003CBA98 3D00073C */  lui        $7, %hi(func_003cb7c0)
    /* 2CBA9C 003CBA9C 25800202 */  or         $16, $16, $2
    /* 2CBAA0 003CBAA0 10050424 */  addiu      $4, $0, 0x510
    /* 2CBAA4 003CBAA4 90B7A524 */  addiu      $5, $5, %lo(func_003cb790)
    /* 2CBAA8 003CBAA8 80B7C624 */  addiu      $6, $6, %lo(func_003cb780)
    /* 2CBAAC 003CBAAC E80A0F0C */  jal        func_003c2ba0
    /* 2CBAB0 003CBAB0 C0B7E724 */   addiu     $7, $7, %lo(func_003cb7c0)
    /* 2CBAB4 003CBAB4 3D00053C */  lui        $5, %hi(func_003cb7e0)
    /* 2CBAB8 003CBAB8 3D00063C */  lui        $6, %hi(func_003cb7d0)
    /* 2CBABC 003CBABC 3D00073C */  lui        $7, %hi(func_003cb810)
    /* 2CBAC0 003CBAC0 25800202 */  or         $16, $16, $2
    /* 2CBAC4 003CBAC4 10050424 */  addiu      $4, $0, 0x510
    /* 2CBAC8 003CBAC8 E0B7A524 */  addiu      $5, $5, %lo(func_003cb7e0)
    /* 2CBACC 003CBACC D0B7C624 */  addiu      $6, $6, %lo(func_003cb7d0)
    /* 2CBAD0 003CBAD0 4C230F0C */  jal        func_003c8d30
    /* 2CBAD4 003CBAD4 10B8E724 */   addiu     $7, $7, %lo(func_003cb810)
    /* 2CBAD8 003CBAD8 25800202 */  or         $16, $16, $2
    /* 2CBADC 003CBADC 2D200000 */  daddu      $4, $0, $0
    /* 2CBAE0 003CBAE0 1F000524 */  addiu      $5, $0, 0x1F
    /* 2CBAE4 003CBAE4 2D300000 */  daddu      $6, $0, $0
    /* 2CBAE8 003CBAE8 2D380000 */  daddu      $7, $0, $0
    /* 2CBAEC 003CBAEC AC060F0C */  jal        func_003c1ab0
    /* 2CBAF0 003CBAF0 2D400000 */   daddu     $8, $0, $0
    /* 2CBAF4 003CBAF4 3C00053C */  lui        $5, %hi(func_003be820)
    /* 2CBAF8 003CBAF8 3C00063C */  lui        $6, %hi(func_003be8a0)
    /* 2CBAFC 003CBAFC 3C00073C */  lui        $7, %hi(func_003be910)
    /* 2CBB00 003CBB00 25800202 */  or         $16, $16, $2
    /* 2CBB04 003CBB04 1F000424 */  addiu      $4, $0, 0x1F
    /* 2CBB08 003CBB08 20E8A524 */  addiu      $5, $5, %lo(func_003be820)
    /* 2CBB0C 003CBB0C A0E8C624 */  addiu      $6, $6, %lo(func_003be8a0)
    /* 2CBB10 003CBB10 C4060F0C */  jal        func_003c1b10
    /* 2CBB14 003CBB14 10E9E724 */   addiu     $7, $7, %lo(func_003be910)
    /* 2CBB18 003CBB18 25800202 */  or         $16, $16, $2
    /* 2CBB1C 003CBB1C 2D200000 */  daddu      $4, $0, $0
    /* 2CBB20 003CBB20 1F000524 */  addiu      $5, $0, 0x1F
    /* 2CBB24 003CBB24 2D300000 */  daddu      $6, $0, $0
    /* 2CBB28 003CBB28 2D380000 */  daddu      $7, $0, $0
    /* 2CBB2C 003CBB2C F4280F0C */  jal        func_003ca3d0
    /* 2CBB30 003CBB30 2D400000 */   daddu     $8, $0, $0
    /* 2CBB34 003CBB34 3C00053C */  lui        $5, %hi(func_003bd470)
    /* 2CBB38 003CBB38 3C00063C */  lui        $6, %hi(func_003bd4f0)
    /* 2CBB3C 003CBB3C 3C00073C */  lui        $7, %hi(func_003bd560)
    /* 2CBB40 003CBB40 25800202 */  or         $16, $16, $2
    /* 2CBB44 003CBB44 1F000424 */  addiu      $4, $0, 0x1F
    /* 2CBB48 003CBB48 70D4A524 */  addiu      $5, $5, %lo(func_003bd470)
    /* 2CBB4C 003CBB4C F0D4C624 */  addiu      $6, $6, %lo(func_003bd4f0)
    /* 2CBB50 003CBB50 00290F0C */  jal        func_003ca400
    /* 2CBB54 003CBB54 60D5E724 */   addiu     $7, $7, %lo(func_003bd560)
    /* 2CBB58 003CBB58 25800202 */  or         $16, $16, $2
    /* 2CBB5C 003CBB5C 2D200000 */  daddu      $4, $0, $0
    /* 2CBB60 003CBB60 1F000524 */  addiu      $5, $0, 0x1F
    /* 2CBB64 003CBB64 2D300000 */  daddu      $6, $0, $0
    /* 2CBB68 003CBB68 2D380000 */  daddu      $7, $0, $0
    /* 2CBB6C 003CBB6C 40230F0C */  jal        func_003c8d00
    /* 2CBB70 003CBB70 2D400000 */   daddu     $8, $0, $0
    /* 2CBB74 003CBB74 3C00053C */  lui        $5, %hi(func_003bd590)
    /* 2CBB78 003CBB78 3C00063C */  lui        $6, %hi(func_003bd610)
    /* 2CBB7C 003CBB7C 3C00073C */  lui        $7, %hi(func_003bd680)
    /* 2CBB80 003CBB80 25800202 */  or         $16, $16, $2
    /* 2CBB84 003CBB84 1F000424 */  addiu      $4, $0, 0x1F
    /* 2CBB88 003CBB88 90D5A524 */  addiu      $5, $5, %lo(func_003bd590)
    /* 2CBB8C 003CBB8C 10D6C624 */  addiu      $6, $6, %lo(func_003bd610)
    /* 2CBB90 003CBB90 4C230F0C */  jal        func_003c8d30
    /* 2CBB94 003CBB94 80D6E724 */   addiu     $7, $7, %lo(func_003bd680)
    /* 2CBB98 003CBB98 25800202 */  or         $16, $16, $2
    /* 2CBB9C 003CBB9C 2D200000 */  daddu      $4, $0, $0
    /* 2CBBA0 003CBBA0 1F000524 */  addiu      $5, $0, 0x1F
    /* 2CBBA4 003CBBA4 2D300000 */  daddu      $6, $0, $0
    /* 2CBBA8 003CBBA8 2D380000 */  daddu      $7, $0, $0
    /* 2CBBAC 003CBBAC C4100F0C */  jal        func_003c4310
    /* 2CBBB0 003CBBB0 2D400000 */   daddu     $8, $0, $0
    /* 2CBBB4 003CBBB4 3C00053C */  lui        $5, %hi(func_003c3f20)
    /* 2CBBB8 003CBBB8 3C00063C */  lui        $6, %hi(func_003c3fa0)
    /* 2CBBBC 003CBBBC 3C00073C */  lui        $7, %hi(func_003c4010)
    /* 2CBBC0 003CBBC0 25800202 */  or         $16, $16, $2
    /* 2CBBC4 003CBBC4 1F000424 */  addiu      $4, $0, 0x1F
    /* 2CBBC8 003CBBC8 203FA524 */  addiu      $5, $5, %lo(func_003c3f20)
    /* 2CBBCC 003CBBCC A03FC624 */  addiu      $6, $6, %lo(func_003c3fa0)
    /* 2CBBD0 003CBBD0 D0100F0C */  jal        func_003c4340
    /* 2CBBD4 003CBBD4 1040E724 */   addiu     $7, $7, %lo(func_003c4010)
    /* 2CBBD8 003CBBD8 25100202 */  or         $2, $16, $2
    /* 2CBBDC 003CBBDC 03004104 */  bgez       $2, .L003CBBEC
    /* 2CBBE0 003CBBE0 00000000 */   nop
    /* 2CBBE4 003CBBE4 04000010 */  b          .L003CBBF8
    /* 2CBBE8 003CBBE8 2D100000 */   daddu     $2, $0, $0
  .L003CBBEC:
    /* 2CBBEC 003CBBEC 90300F0C */  jal        func_003cc240
    /* 2CBBF0 003CBBF0 00000000 */   nop
    /* 2CBBF4 003CBBF4 2B100200 */  sltu       $2, $0, $2
  .L003CBBF8:
    /* 2CBBF8 003CBBF8 1000BFDF */  ld         $31, 0x10($29)
    /* 2CBBFC 003CBBFC 0000B07B */  lq         $16, 0x0($29)
    /* 2CBC00 003CBC00 0800E003 */  jr         $31
    /* 2CBC04 003CBC04 2000BD27 */   addiu     $29, $29, 0x20
    /* 2CBC08 003CBC08 00000000 */  nop
    /* 2CBC0C 003CBC0C 00000000 */  nop
.size func_003cb900, 0x310
