.section .text
.set noat
.set noreorder
glabel func_003adc40
    /* 2ADC40 003ADC40 E0FEBD27 */  addiu      $29, $29, -0x120
    /* 2ADC44 003ADC44 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 2ADC48 003ADC48 A000BFFF */  sd         $31, 0xA0($29)
    /* 2ADC4C 003ADC4C 00108244 */  mtc1       $2, $f2
    /* 2ADC50 003ADC50 9000BE7F */  sq         $30, 0x90($29)
    /* 2ADC54 003ADC54 8000B77F */  sq         $23, 0x80($29)
    /* 2ADC58 003ADC58 7000B67F */  sq         $22, 0x70($29)
    /* 2ADC5C 003ADC5C 6000B57F */  sq         $21, 0x60($29)
    /* 2ADC60 003ADC60 2DB0A000 */  daddu      $22, $5, $0
    /* 2ADC64 003ADC64 5000B47F */  sq         $20, 0x50($29)
    /* 2ADC68 003ADC68 2DA8C000 */  daddu      $21, $6, $0
    /* 2ADC6C 003ADC6C 4000B37F */  sq         $19, 0x40($29)
    /* 2ADC70 003ADC70 2DA0E000 */  daddu      $20, $7, $0
    /* 2ADC74 003ADC74 3000B27F */  sq         $18, 0x30($29)
    /* 2ADC78 003ADC78 2D980001 */  daddu      $19, $8, $0
    /* 2ADC7C 003ADC7C 2000B17F */  sq         $17, 0x20($29)
    /* 2ADC80 003ADC80 1000B07F */  sq         $16, 0x10($29)
    /* 2ADC84 003ADC84 0C00B7E7 */  swc1       $f23, 0xC($29)
    /* 2ADC88 003ADC88 0800B6E7 */  swc1       $f22, 0x8($29)
    /* 2ADC8C 003ADC8C 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 2ADC90 003ADC90 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 2ADC94 003ADC94 700001C5 */  lwc1       $f1, 0x70($8)
    /* 2ADC98 003ADC98 0400828C */  lw         $2, 0x4($4)
    /* 2ADC9C 003ADC9C 740000C5 */  lwc1       $f0, 0x74($8)
    /* 2ADCA0 003ADCA0 0800178D */  lw         $23, 0x8($8)
    /* 2ADCA4 003ADCA4 0400128D */  lw         $18, 0x4($8)
    /* 2ADCA8 003ADCA8 3400118D */  lw         $17, 0x34($8)
    /* 2ADCAC 003ADCAC 38001E8D */  lw         $30, 0x38($8)
    /* 2ADCB0 003ADCB0 0000908C */  lw         $16, 0x0($4)
    /* 2ADCB4 003ADCB4 C2150146 */  mul.s      $f23, $f2, $f1
    /* 2ADCB8 003ADCB8 B000A27F */  sq         $2, 0xB0($29)
    /* 2ADCBC 003ADCBC 3403E216 */  bne        $23, $2, .L003AE990
    /* 2ADCC0 003ADCC0 82150046 */   mul.s     $f22, $f2, $f0
    /* 2ADCC4 003ADCC4 9886100C */  jal        func_00421a60
    /* 2ADCC8 003ADCC8 2D200000 */   daddu     $4, $0, $0
    /* 2ADCCC 003ADCCC 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2ADCD0 003ADCD0 00D0648C */  lw         $4, -0x3000($3)
    /* 2ADCD4 003ADCD4 00018430 */  andi       $4, $4, 0x100
    /* 2ADCD8 003ADCD8 0C008010 */  beqz       $4, .L003ADD0C
    /* 2ADCDC 003ADCDC 00000000 */   nop
    /* 2ADCE0 003ADCE0 00010424 */  addiu      $4, $0, 0x100
    /* 2ADCE4 003ADCE4 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2ADCE8 003ADCE8 0F000000 */  sync
    /* 2ADCEC 003ADCEC 0F040000 */  sync.p
  .L003ADCF0:
    /* 2ADCF0 003ADCF0 00000000 */  nop
    /* 2ADCF4 003ADCF4 00000000 */  nop
    /* 2ADCF8 003ADCF8 00000000 */  nop
    /* 2ADCFC 003ADCFC 00000000 */  nop
    /* 2ADD00 003ADD00 00000000 */  nop
    /* 2ADD04 003ADD04 FAFF0041 */  bc0f       .L003ADCF0 /* handwritten instruction */
    /* 2ADD08 003ADD08 00000000 */   nop
  .L003ADD0C:
    /* 2ADD0C 003ADD0C 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2ADD10 003ADD10 00D4648C */  lw         $4, -0x2C00($3)
    /* 2ADD14 003ADD14 00018430 */  andi       $4, $4, 0x100
    /* 2ADD18 003ADD18 15008010 */  beqz       $4, .L003ADD70
    /* 2ADD1C 003ADD1C 00000000 */   nop
    /* 2ADD20 003ADD20 00020424 */  addiu      $4, $0, 0x200
    /* 2ADD24 003ADD24 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2ADD28 003ADD28 0F000000 */  sync
    /* 2ADD2C 003ADD2C 0F040000 */  sync.p
  .L003ADD30:
    /* 2ADD30 003ADD30 00000000 */  nop
    /* 2ADD34 003ADD34 00000000 */  nop
    /* 2ADD38 003ADD38 00000000 */  nop
    /* 2ADD3C 003ADD3C 00000000 */  nop
    /* 2ADD40 003ADD40 00000000 */  nop
    /* 2ADD44 003ADD44 FAFF0041 */  bc0f       .L003ADD30 /* handwritten instruction */
    /* 2ADD48 003ADD48 00000000 */   nop
    /* 2ADD4C 003ADD4C 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003ADD50:
    /* 2ADD50 003ADD50 00D4648C */  lw         $4, -0x2C00($3)
    /* 2ADD54 003ADD54 00018430 */  andi       $4, $4, 0x100
    /* 2ADD58 003ADD58 00000000 */  nop
    /* 2ADD5C 003ADD5C 00000000 */  nop
    /* 2ADD60 003ADD60 00000000 */  nop
    /* 2ADD64 003ADD64 FAFF8014 */  bnez       $4, .L003ADD50
    /* 2ADD68 003ADD68 00000000 */   nop
    /* 2ADD6C 003ADD6C 00000000 */  nop
  .L003ADD70:
    /* 2ADD70 003ADD70 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 2ADD74 003ADD74 00208344 */  mtc1       $3, $f4
    /* 2ADD78 003ADD78 0070083C */  lui        $8, (0x70003F7C >> 16)
    /* 2ADD7C 003ADD7C 680060C6 */  lwc1       $f0, 0x68($19)
    /* 2ADD80 003ADD80 003F0635 */  ori        $6, $8, (0x70003F00 & 0xFFFF)
    /* 2ADD84 003ADD84 C3201746 */  div.s      $f3, $f4, $f23
    /* 2ADD88 003ADD88 103F0535 */  ori        $5, $8, (0x70003F10 & 0xFFFF)
    /* 2ADD8C 003ADD8C 703F0435 */  ori        $4, $8, (0x70003F70 & 0xFFFF)
    /* 2ADD90 003ADD90 203F0335 */  ori        $3, $8, (0x70003F20 & 0xFFFF)
    /* 2ADD94 003ADD94 303F0A35 */  ori        $10, $8, (0x70003F30 & 0xFFFF)
    /* 2ADD98 003ADD98 403F0935 */  ori        $9, $8, (0x70003F40 & 0xFFFF)
    /* 2ADD9C 003ADD9C 0100073C */  lui        $7, (0x10000 >> 16)
    /* 2ADDA0 003ADDA0 02000346 */  mul.s      $f0, $f0, $f3
    /* 2ADDA4 003ADDA4 01000446 */  sub.s      $f0, $f0, $f4
    /* 2ADDA8 003ADDA8 703F00E5 */  swc1       $f0, (0x70003F70 & 0xFFFF)($8)
    /* 2ADDAC 003ADDAC 83201646 */  div.s      $f2, $f4, $f22
    /* 2ADDB0 003ADDB0 6C0061C6 */  lwc1       $f1, 0x6C($19)
    /* 2ADDB4 003ADDB4 00008044 */  mtc1       $0, $f0
    /* 2ADDB8 003ADDB8 00000000 */  nop
    /* 2ADDBC 003ADDBC 18000446 */  adda.s     $f0, $f4
    /* 2ADDC0 003ADDC0 42080246 */  mul.s      $f1, $f1, $f2
    /* 2ADDC4 003ADDC4 41080446 */  sub.s      $f1, $f1, $f4
    /* 2ADDC8 003ADDC8 743F01E5 */  swc1       $f1, (0x70003F74 & 0xFFFF)($8)
    /* 2ADDCC 003ADDCC 680061C6 */  lwc1       $f1, 0x68($19)
    /* 2ADDD0 003ADDD0 5C080346 */  madd.s     $f1, $f1, $f3
    /* 2ADDD4 003ADDD4 18000446 */  adda.s     $f0, $f4
    /* 2ADDD8 003ADDD8 783F01E5 */  swc1       $f1, (0x70003F78 & 0xFFFF)($8)
    /* 2ADDDC 003ADDDC 6C0060C6 */  lwc1       $f0, 0x6C($19)
    /* 2ADDE0 003ADDE0 1C000246 */  madd.s     $f0, $f0, $f2
    /* 2ADDE4 003ADDE4 7C3F00E5 */  swc1       $f0, (0x70003F7C & 0xFFFF)($8)
    /* 2ADDE8 003ADDE8 0000C2C6 */  lwc1       $f2, 0x0($22)
    /* 2ADDEC 003ADDEC 0400C1C6 */  lwc1       $f1, 0x4($22)
    /* 2ADDF0 003ADDF0 0800C0C6 */  lwc1       $f0, 0x8($22)
    /* 2ADDF4 003ADDF4 0000C2E4 */  swc1       $f2, 0x0($6)
    /* 2ADDF8 003ADDF8 0400C1E4 */  swc1       $f1, 0x4($6)
    /* 2ADDFC 003ADDFC 0800C0E4 */  swc1       $f0, 0x8($6)
    /* 2ADE00 003ADE00 0000A2C6 */  lwc1       $f2, 0x0($21)
    /* 2ADE04 003ADE04 0400A1C6 */  lwc1       $f1, 0x4($21)
    /* 2ADE08 003ADE08 0800A0C6 */  lwc1       $f0, 0x8($21)
    /* 2ADE0C 003ADE0C 0000A2E4 */  swc1       $f2, 0x0($5)
    /* 2ADE10 003ADE10 0400A1E4 */  swc1       $f1, 0x4($5)
    /* 2ADE14 003ADE14 0800A0E4 */  swc1       $f0, 0x8($5)
  .L003ADE18:
    /* 2ADE18 003ADE18 39000042 */  di /* handwritten instruction */
    /* 2ADE1C 003ADE1C 0F040000 */  sync.p
    /* 2ADE20 003ADE20 00600840 */  mfc0       $8, $12 /* handwritten instruction */
    /* 2ADE24 003ADE24 24400701 */  and        $8, $8, $7
    /* 2ADE28 003ADE28 00000000 */  nop
    /* 2ADE2C 003ADE2C FAFF0015 */  bnez       $8, .L003ADE18
    /* 2ADE30 003ADE30 00000000 */   nop
    /* 2ADE34 003ADE34 C93F013C */  lui        $1, (0x3FC90FDB >> 16)
    /* 2ADE38 003ADE38 DB0F2734 */  ori        $7, $1, (0x3FC90FDB & 0xFFFF)
    /* 2ADE3C 003ADE3C 00008744 */  mtc1       $7, $f0
    /* 2ADE40 003ADE40 00000744 */  mfc1       $7, $f0
    /* 2ADE44 003ADE44 00A8C748 */  ctc2.ni    $7, $vi21
    /* 2ADE48 003ADE48 FF02004A */  vnop
    /* 2ADE4C 003ADE4C FF02004A */  vnop
    /* 2ADE50 003ADE50 A202004B */  vaddi.x    $vf10, $vf0, $I
    /* 2ADE54 003ADE54 4940013C */  lui        $1, (0x40490FDB >> 16)
    /* 2ADE58 003ADE58 DB0F2834 */  ori        $8, $1, (0x40490FDB & 0xFFFF)
    /* 2ADE5C 003ADE5C 00008844 */  mtc1       $8, $f0
    /* 2ADE60 003ADE60 00000744 */  mfc1       $7, $f0
    /* 2ADE64 003ADE64 00A8C748 */  ctc2.ni    $7, $vi21
    /* 2ADE68 003ADE68 FF02004A */  vnop
    /* 2ADE6C 003ADE6C FF02004A */  vnop
    /* 2ADE70 003ADE70 A202804A */  vaddi.y    $vf10, $vf0, $I
    /* 2ADE74 003ADE74 0940013C */  lui        $1, (0x40090FDB >> 16)
    /* 2ADE78 003ADE78 DB0F2734 */  ori        $7, $1, (0x40090FDB & 0xFFFF)
    /* 2ADE7C 003ADE7C 00008744 */  mtc1       $7, $f0
    /* 2ADE80 003ADE80 00000744 */  mfc1       $7, $f0
    /* 2ADE84 003ADE84 00A8C748 */  ctc2.ni    $7, $vi21
    /* 2ADE88 003ADE88 FF02004A */  vnop
    /* 2ADE8C 003ADE8C FF02004A */  vnop
    /* 2ADE90 003ADE90 A202404A */  vaddi.z    $vf10, $vf0, $I
    /* 2ADE94 003ADE94 00008844 */  mtc1       $8, $f0
    /* 2ADE98 003ADE98 07000046 */  neg.s      $f0, $f0
    /* 2ADE9C 003ADE9C 00000744 */  mfc1       $7, $f0
    /* 2ADEA0 003ADEA0 00A8C748 */  ctc2.ni    $7, $vi21
    /* 2ADEA4 003ADEA4 FF02004A */  vnop
    /* 2ADEA8 003ADEA8 FF02004A */  vnop
    /* 2ADEAC 003ADEAC E202004B */  vaddi.x    $vf11, $vf0, $I
    /* 2ADEB0 003ADEB0 8440013C */  lui        $1, (0x408487ED >> 16)
    /* 2ADEB4 003ADEB4 ED872734 */  ori        $7, $1, (0x408487ED & 0xFFFF)
    /* 2ADEB8 003ADEB8 00008744 */  mtc1       $7, $f0
    /* 2ADEBC 003ADEBC 07000046 */  neg.s      $f0, $f0
    /* 2ADEC0 003ADEC0 00000744 */  mfc1       $7, $f0
    /* 2ADEC4 003ADEC4 00A8C748 */  ctc2.ni    $7, $vi21
    /* 2ADEC8 003ADEC8 FF02004A */  vnop
    /* 2ADECC 003ADECC FF02004A */  vnop
    /* 2ADED0 003ADED0 E202804A */  vaddi.y    $vf11, $vf0, $I
    /* 2ADED4 003ADED4 00000734 */  ori        $7, $0, 0x0
    /* 2ADED8 003ADED8 383C0700 */  dsll       $7, $7, 16
    /* 2ADEDC 003ADEDC 383C0700 */  dsll       $7, $7, 16
    /* 2ADEE0 003ADEE0 4FB9E734 */  ori        $7, $7, 0xB94F
    /* 2ADEE4 003ADEE4 383C0700 */  dsll       $7, $7, 16
    /* 2ADEE8 003ADEE8 1FB2E734 */  ori        $7, $7, 0xB21F
    /* 2ADEEC 003ADEEC 00A8C748 */  ctc2.ni    $7, $vi21
    /* 2ADEF0 003ADEF0 FF02004A */  vnop
    /* 2ADEF4 003ADEF4 FF02004A */  vnop
    /* 2ADEF8 003ADEF8 E202404A */  vaddi.z    $vf11, $vf0, $I
    /* 2ADEFC 003ADEFC 00000734 */  ori        $7, $0, 0x0
    /* 2ADF00 003ADF00 383C0700 */  dsll       $7, $7, 16
    /* 2ADF04 003ADF04 383C0700 */  dsll       $7, $7, 16
    /* 2ADF08 003ADF08 2ABEE734 */  ori        $7, $7, 0xBE2A
    /* 2ADF0C 003ADF0C 383C0700 */  dsll       $7, $7, 16
    /* 2ADF10 003ADF10 A4AAE734 */  ori        $7, $7, 0xAAA4
    /* 2ADF14 003ADF14 00A8C748 */  ctc2.ni    $7, $vi21
    /* 2ADF18 003ADF18 FF02004A */  vnop
    /* 2ADF1C 003ADF1C FF02004A */  vnop
    /* 2ADF20 003ADF20 2203004B */  vaddi.x    $vf12, $vf0, $I
    /* 2ADF24 003ADF24 083C013C */  lui        $1, (0x3C08873E >> 16)
    /* 2ADF28 003ADF28 3E872734 */  ori        $7, $1, (0x3C08873E & 0xFFFF)
    /* 2ADF2C 003ADF2C 00A8C748 */  ctc2.ni    $7, $vi21
    /* 2ADF30 003ADF30 FF02004A */  vnop
    /* 2ADF34 003ADF34 FF02004A */  vnop
    /* 2ADF38 003ADF38 2203804A */  vaddi.y    $vf12, $vf0, $I
    /* 2ADF3C 003ADF3C 2E36013C */  lui        $1, (0x362E9C14 >> 16)
    /* 2ADF40 003ADF40 149C2734 */  ori        $7, $1, (0x362E9C14 & 0xFFFF)
    /* 2ADF44 003ADF44 00A8C748 */  ctc2.ni    $7, $vi21
    /* 2ADF48 003ADF48 FF02004A */  vnop
    /* 2ADF4C 003ADF4C FF02004A */  vnop
    /* 2ADF50 003ADF50 2203404A */  vaddi.z    $vf12, $vf0, $I
    /* 2ADF54 003ADF54 803F073C */  lui        $7, (0x3F800000 >> 16)
    /* 2ADF58 003ADF58 00A8C748 */  ctc2.ni    $7, $vi21
    /* 2ADF5C 003ADF5C FF02004A */  vnop
    /* 2ADF60 003ADF60 FF02004A */  vnop
    /* 2ADF64 003ADF64 6203004B */  vaddi.x    $vf13, $vf0, $I
    /* 2ADF68 003ADF68 38000042 */  ei /* handwritten instruction */
    /* 2ADF6C 003ADF6C 0070073C */  lui        $7, (0x70003F40 >> 16)
    /* 2ADF70 003ADF70 3C3FF7E4 */  swc1       $f23, (0x70003F3C & 0xFFFF)($7)
    /* 2ADF74 003ADF74 0100083C */  lui        $8, (0x10000 >> 16)
    /* 2ADF78 003ADF78 383FF7E4 */  swc1       $f23, (0x70003F38 & 0xFFFF)($7)
    /* 2ADF7C 003ADF7C 343FF7E4 */  swc1       $f23, (0x70003F34 & 0xFFFF)($7)
    /* 2ADF80 003ADF80 303FF7E4 */  swc1       $f23, (0x70003F30 & 0xFFFF)($7)
    /* 2ADF84 003ADF84 4C3FF6E4 */  swc1       $f22, (0x70003F4C & 0xFFFF)($7)
    /* 2ADF88 003ADF88 483FF6E4 */  swc1       $f22, (0x70003F48 & 0xFFFF)($7)
    /* 2ADF8C 003ADF8C 443FF6E4 */  swc1       $f22, (0x70003F44 & 0xFFFF)($7)
    /* 2ADF90 003ADF90 403FF6E4 */  swc1       $f22, (0x70003F40 & 0xFFFF)($7)
  .L003ADF94:
    /* 2ADF94 003ADF94 39000042 */  di /* handwritten instruction */
    /* 2ADF98 003ADF98 0F040000 */  sync.p
    /* 2ADF9C 003ADF9C 00600740 */  mfc0       $7, $12 /* handwritten instruction */
    /* 2ADFA0 003ADFA0 2438E800 */  and        $7, $7, $8
    /* 2ADFA4 003ADFA4 00000000 */  nop
    /* 2ADFA8 003ADFA8 FAFFE014 */  bnez       $7, .L003ADF94
    /* 2ADFAC 003ADFAC 00000000 */   nop
    /* 2ADFB0 003ADFB0 0000C2D8 */  lqc2       $vf2, 0x0($6)
    /* 2ADFB4 003ADFB4 000044D9 */  lqc2       $vf4, 0x0($10)
    /* 2ADFB8 003ADFB8 0000A3D8 */  lqc2       $vf3, 0x0($5)
    /* 2ADFBC 003ADFBC 000025D9 */  lqc2       $vf5, 0x0($9)
    /* 2ADFC0 003ADFC0 00008ED8 */  lqc2       $vf14, 0x0($4)
    /* 2ADFC4 003ADFC4 2A12E44B */  vmul.xyzw  $vf8, $vf2, $vf4
    /* 2ADFC8 003ADFC8 2A1CE44B */  vmul.xyzw  $vf16, $vf3, $vf4
    /* 2ADFCC 003ADFCC 6A12E54B */  vmul.xyzw  $vf9, $vf2, $vf5
    /* 2ADFD0 003ADFD0 6A1CE54B */  vmul.xyzw  $vf17, $vf3, $vf5
    /* 2ADFD4 003ADFD4 38000042 */  ei /* handwritten instruction */
    /* 2ADFD8 003ADFD8 C000842A */  slti       $4, $20, 0xC0
    /* 2ADFDC 003ADFDC 06018014 */  bnez       $4, .L003AE3F8
    /* 2ADFE0 003ADFE0 00000000 */   nop
    /* 2ADFE4 003ADFE4 00700E3C */  lui        $14, (0x70000F00 >> 16)
    /* 2ADFE8 003ADFE8 0110083C */  lui        $8, (0x10010000 >> 16)
    /* 2ADFEC 003ADFEC 01000B3C */  lui        $11, (0x10000 >> 16)
    /* 2ADFF0 003ADFF0 00011824 */  addiu      $24, $0, 0x100
    /* 2ADFF4 003ADFF4 00021624 */  addiu      $22, $0, 0x200
    /* 2ADFF8 003ADFF8 30001524 */  addiu      $21, $0, 0x30
    /* 2ADFFC 003ADFFC 00031324 */  addiu      $19, $0, 0x300
    /* 2AE000 003AE000 C0000F24 */  addiu      $15, $0, 0xC0
    /* 2AE004 003AE004 0003CD35 */  ori        $13, $14, (0x70000300 & 0xFFFF)
    /* 2AE008 003AE008 000FCC35 */  ori        $12, $14, (0x70000F00 & 0xFFFF)
    /* 2AE00C 003AE00C 000F0924 */  addiu      $9, $0, 0xF00
  .L003AE010:
    /* 2AE010 003AE010 00D0048D */  lw         $4, -0x3000($8)
    /* 2AE014 003AE014 00018430 */  andi       $4, $4, 0x100
    /* 2AE018 003AE018 0D008010 */  beqz       $4, .L003AE050
    /* 2AE01C 003AE01C 00000000 */   nop
    /* 2AE020 003AE020 20E018AD */  sw         $24, -0x1FE0($8)
    /* 2AE024 003AE024 0F000000 */  sync
    /* 2AE028 003AE028 0F040000 */  sync.p
    /* 2AE02C 003AE02C 00000000 */  nop
  .L003AE030:
    /* 2AE030 003AE030 00000000 */  nop
    /* 2AE034 003AE034 00000000 */  nop
    /* 2AE038 003AE038 00000000 */  nop
    /* 2AE03C 003AE03C 00000000 */  nop
    /* 2AE040 003AE040 00000000 */  nop
    /* 2AE044 003AE044 FAFF0041 */  bc0f       .L003AE030 /* handwritten instruction */
    /* 2AE048 003AE048 00000000 */   nop
    /* 2AE04C 003AE04C 00000000 */  nop
  .L003AE050:
    /* 2AE050 003AE050 00D4048D */  lw         $4, -0x2C00($8)
    /* 2AE054 003AE054 00018430 */  andi       $4, $4, 0x100
    /* 2AE058 003AE058 15008010 */  beqz       $4, .L003AE0B0
    /* 2AE05C 003AE05C 00000000 */   nop
    /* 2AE060 003AE060 20E016AD */  sw         $22, -0x1FE0($8)
    /* 2AE064 003AE064 0F000000 */  sync
    /* 2AE068 003AE068 0F040000 */  sync.p
    /* 2AE06C 003AE06C 00000000 */  nop
  .L003AE070:
    /* 2AE070 003AE070 00000000 */  nop
    /* 2AE074 003AE074 00000000 */  nop
    /* 2AE078 003AE078 00000000 */  nop
    /* 2AE07C 003AE07C 00000000 */  nop
    /* 2AE080 003AE080 00000000 */  nop
    /* 2AE084 003AE084 FAFF0041 */  bc0f       .L003AE070 /* handwritten instruction */
    /* 2AE088 003AE088 00000000 */   nop
    /* 2AE08C 003AE08C 00000000 */  nop
  .L003AE090:
    /* 2AE090 003AE090 00D4048D */  lw         $4, -0x2C00($8)
    /* 2AE094 003AE094 00018430 */  andi       $4, $4, 0x100
    /* 2AE098 003AE098 00000000 */  nop
    /* 2AE09C 003AE09C 00000000 */  nop
    /* 2AE0A0 003AE0A0 00000000 */  nop
    /* 2AE0A4 003AE0A4 FAFF8014 */  bnez       $4, .L003AE090
    /* 2AE0A8 003AE0A8 00000000 */   nop
    /* 2AE0AC 003AE0AC 00000000 */  nop
  .L003AE0B0:
    /* 2AE0B0 003AE0B0 10E016AD */  sw         $22, -0x1FF0($8)
    /* 2AE0B4 003AE0B4 80D400AD */  sw         $0, -0x2B80($8)
    /* 2AE0B8 003AE0B8 10D411AD */  sw         $17, -0x2BF0($8)
    /* 2AE0BC 003AE0BC 20D415AD */  sw         $21, -0x2BE0($8)
    /* 2AE0C0 003AE0C0 00D418AD */  sw         $24, -0x2C00($8)
    /* 2AE0C4 003AE0C4 0F000000 */  sync
    /* 2AE0C8 003AE0C8 0F040000 */  sync.p
    /* 2AE0CC 003AE0CC 00D4048D */  lw         $4, -0x2C00($8)
    /* 2AE0D0 003AE0D0 00018430 */  andi       $4, $4, 0x100
    /* 2AE0D4 003AE0D4 14008010 */  beqz       $4, .L003AE128
    /* 2AE0D8 003AE0D8 00000000 */   nop
    /* 2AE0DC 003AE0DC 20E016AD */  sw         $22, -0x1FE0($8)
    /* 2AE0E0 003AE0E0 0F000000 */  sync
    /* 2AE0E4 003AE0E4 0F040000 */  sync.p
  .L003AE0E8:
    /* 2AE0E8 003AE0E8 00000000 */  nop
    /* 2AE0EC 003AE0EC 00000000 */  nop
    /* 2AE0F0 003AE0F0 00000000 */  nop
    /* 2AE0F4 003AE0F4 00000000 */  nop
    /* 2AE0F8 003AE0F8 00000000 */  nop
    /* 2AE0FC 003AE0FC FAFF0041 */  bc0f       .L003AE0E8 /* handwritten instruction */
    /* 2AE100 003AE100 00000000 */   nop
    /* 2AE104 003AE104 00000000 */  nop
  .L003AE108:
    /* 2AE108 003AE108 00D4048D */  lw         $4, -0x2C00($8)
    /* 2AE10C 003AE10C 00018430 */  andi       $4, $4, 0x100
    /* 2AE110 003AE110 00000000 */  nop
    /* 2AE114 003AE114 00000000 */  nop
    /* 2AE118 003AE118 00000000 */  nop
    /* 2AE11C 003AE11C FAFF8014 */  bnez       $4, .L003AE108
    /* 2AE120 003AE120 00000000 */   nop
    /* 2AE124 003AE124 00000000 */  nop
  .L003AE128:
    /* 2AE128 003AE128 10E016AD */  sw         $22, -0x1FF0($8)
    /* 2AE12C 003AE12C 80D413AD */  sw         $19, -0x2B80($8)
    /* 2AE130 003AE130 10D412AD */  sw         $18, -0x2BF0($8)
    /* 2AE134 003AE134 20D40FAD */  sw         $15, -0x2BE0($8)
    /* 2AE138 003AE138 00D418AD */  sw         $24, -0x2C00($8)
    /* 2AE13C 003AE13C 0F000000 */  sync
    /* 2AE140 003AE140 0F040000 */  sync.p
    /* 2AE144 003AE144 00D4048D */  lw         $4, -0x2C00($8)
    /* 2AE148 003AE148 00018430 */  andi       $4, $4, 0x100
    /* 2AE14C 003AE14C 14008010 */  beqz       $4, .L003AE1A0
    /* 2AE150 003AE150 00000000 */   nop
    /* 2AE154 003AE154 20E016AD */  sw         $22, -0x1FE0($8)
    /* 2AE158 003AE158 0F000000 */  sync
    /* 2AE15C 003AE15C 0F040000 */  sync.p
  .L003AE160:
    /* 2AE160 003AE160 00000000 */  nop
    /* 2AE164 003AE164 00000000 */  nop
    /* 2AE168 003AE168 00000000 */  nop
    /* 2AE16C 003AE16C 00000000 */  nop
    /* 2AE170 003AE170 00000000 */  nop
    /* 2AE174 003AE174 FAFF0041 */  bc0f       .L003AE160 /* handwritten instruction */
    /* 2AE178 003AE178 00000000 */   nop
    /* 2AE17C 003AE17C 00000000 */  nop
  .L003AE180:
    /* 2AE180 003AE180 00D4048D */  lw         $4, -0x2C00($8)
    /* 2AE184 003AE184 00018430 */  andi       $4, $4, 0x100
    /* 2AE188 003AE188 00000000 */  nop
    /* 2AE18C 003AE18C 00000000 */  nop
    /* 2AE190 003AE190 00000000 */  nop
    /* 2AE194 003AE194 FAFF8014 */  bnez       $4, .L003AE180
    /* 2AE198 003AE198 00000000 */   nop
    /* 2AE19C 003AE19C 00000000 */  nop
  .L003AE1A0:
    /* 2AE1A0 003AE1A0 2D30C001 */  daddu      $6, $14, $0
    /* 2AE1A4 003AE1A4 2D28A001 */  daddu      $5, $13, $0
    /* 2AE1A8 003AE1A8 2D208001 */  daddu      $4, $12, $0
    /* 2AE1AC 003AE1AC 2D380000 */  daddu      $7, $0, $0
  .L003AE1B0:
    /* 2AE1B0 003AE1B0 0000C0C4 */  lwc1       $f0, (0x70000000 & 0xFFFF)($6)
    /* 2AE1B4 003AE1B4 000060E4 */  swc1       $f0, 0x0($3)
    /* 2AE1B8 003AE1B8 0400C0C4 */  lwc1       $f0, (0x70000004 & 0xFFFF)($6)
    /* 2AE1BC 003AE1BC 040060E4 */  swc1       $f0, 0x4($3)
    /* 2AE1C0 003AE1C0 0000C0C4 */  lwc1       $f0, (0x70000000 & 0xFFFF)($6)
    /* 2AE1C4 003AE1C4 080060E4 */  swc1       $f0, 0x8($3)
    /* 2AE1C8 003AE1C8 0400C0C4 */  lwc1       $f0, (0x70000004 & 0xFFFF)($6)
    /* 2AE1CC 003AE1CC 0C0060E4 */  swc1       $f0, 0xC($3)
  .L003AE1D0:
    /* 2AE1D0 003AE1D0 39000042 */  di /* handwritten instruction */
    /* 2AE1D4 003AE1D4 0F040000 */  sync.p
    /* 2AE1D8 003AE1D8 00600A40 */  mfc0       $10, $12 /* handwritten instruction */
    /* 2AE1DC 003AE1DC 24504B01 */  and        $10, $10, $11
    /* 2AE1E0 003AE1E0 00000000 */  nop
    /* 2AE1E4 003AE1E4 FAFF4015 */  bnez       $10, .L003AE1D0
    /* 2AE1E8 003AE1E8 00000000 */   nop
    /* 2AE1EC 003AE1EC 000061D8 */  lqc2       $vf1, 0x0($3)
    /* 2AE1F0 003AE1F0 0000B4D8 */  lqc2       $vf20, 0x0($5)
    /* 2AE1F4 003AE1F4 1000BBD8 */  lqc2       $vf27, 0x10($5)
    /* 2AE1F8 003AE1F8 FD09874B */  vabs.xy    $vf7, $vf1
    /* 2AE1FC 003AE1FC 3C00EA4B */  vaddax.xyzw $ACC, $vf0, $vf10x
    /* 2AE200 003AE200 CF39804B */  vmsubw.xy  $vf7, $vf7, $vf0w
    /* 2AE204 003AE204 3D00CA4B */  vadday.xyz $ACC, $vf0, $vf10y
    /* 2AE208 003AE208 3E002A4A */  vaddaz.w   $ACC, $vf0, $vf10z
    /* 2AE20C 003AE20C 8F08604A */  vmsubw.zw  $vf2, $vf1, $vf0w
    /* 2AE210 003AE210 3C00CB4B */  vaddax.xyz $ACC, $vf0, $vf11x
    /* 2AE214 003AE214 3D002B4A */  vadday.w   $ACC, $vf0, $vf11y
    /* 2AE218 003AE218 CF08604A */  vmsubw.zw  $vf3, $vf1, $vf0w
    /* 2AE21C 003AE21C AF08624A */  vmini.zw   $vf2, $vf1, $vf2
    /* 2AE220 003AE220 EB11634A */  vmax.zw    $vf7, $vf2, $vf3
    /* 2AE224 003AE224 AA38E74B */  vmul.xyzw  $vf2, $vf7, $vf7
    /* 2AE228 003AE228 9A39EB4B */  vmulz.xyzw $vf6, $vf7, $vf11z
    /* 2AE22C 003AE22C 1839EC4B */  vmulx.xyzw $vf4, $vf7, $vf12x
    /* 2AE230 003AE230 5939EC4B */  vmuly.xyzw $vf5, $vf7, $vf12y
    /* 2AE234 003AE234 EA10E24B */  vmul.xyzw  $vf3, $vf2, $vf2
    /* 2AE238 003AE238 AA31E24B */  vmul.xyzw  $vf6, $vf6, $vf2
    /* 2AE23C 003AE23C BE22E24B */  vmula.xyzw $ACC, $vf4, $vf2
    /* 2AE240 003AE240 1A39EC4B */  vmulz.xyzw $vf4, $vf7, $vf12z
    /* 2AE244 003AE244 AA18E34B */  vmul.xyzw  $vf2, $vf3, $vf3
    /* 2AE248 003AE248 BD32E34B */  vmadda.xyzw $ACC, $vf6, $vf3
    /* 2AE24C 003AE24C BD2AE34B */  vmadda.xyzw $ACC, $vf5, $vf3
    /* 2AE250 003AE250 BC38ED4B */  vmaddax.xyzw $ACC, $vf7, $vf13x
    /* 2AE254 003AE254 E921E24B */  vmadd.xyzw $vf7, $vf4, $vf2
    /* 2AE258 003AE258 9840C74B */  vmulx.xyz  $vf2, $vf8, $vf7x
    /* 2AE25C 003AE25C DA80C74B */  vmulz.xyz  $vf3, $vf16, $vf7z
    /* 2AE260 003AE260 1A49C74B */  vmulz.xyz  $vf4, $vf9, $vf7z
    /* 2AE264 003AE264 5889C74B */  vmulx.xyz  $vf5, $vf17, $vf7x
    /* 2AE268 003AE268 AC14E34B */  vsub.xyzw  $vf18, $vf2, $vf3
    /* 2AE26C 003AE26C 9940C74B */  vmuly.xyz  $vf2, $vf8, $vf7y
    /* 2AE270 003AE270 DB80C74B */  vmulw.xyz  $vf3, $vf16, $vf7w
    /* 2AE274 003AE274 E824E54B */  vadd.xyzw  $vf19, $vf4, $vf5
    /* 2AE278 003AE278 1B49C74B */  vmulw.xyz  $vf4, $vf9, $vf7w
    /* 2AE27C 003AE27C 5989C74B */  vmuly.xyz  $vf5, $vf17, $vf7y
    /* 2AE280 003AE280 6C16E34B */  vsub.xyzw  $vf25, $vf2, $vf3
    /* 2AE284 003AE284 BD99EE4B */  vmulay.xyzw $ACC, $vf19, $vf14y
    /* 2AE288 003AE288 BC90EE4B */  vmaddax.xyzw $ACC, $vf18, $vf14x
    /* 2AE28C 003AE28C 4BA5E04B */  vmaddw.xyzw $vf21, $vf20, $vf0w
    /* 2AE290 003AE290 A826E54B */  vadd.xyzw  $vf26, $vf4, $vf5
    /* 2AE294 003AE294 BD99EE4B */  vmulay.xyzw $ACC, $vf19, $vf14y
    /* 2AE298 003AE298 BE90EE4B */  vmaddaz.xyzw $ACC, $vf18, $vf14z
    /* 2AE29C 003AE29C 8BA5E04B */  vmaddw.xyzw $vf22, $vf20, $vf0w
    /* 2AE2A0 003AE2A0 BF99EE4B */  vmulaw.xyzw $ACC, $vf19, $vf14w
    /* 2AE2A4 003AE2A4 BE90EE4B */  vmaddaz.xyzw $ACC, $vf18, $vf14z
    /* 2AE2A8 003AE2A8 CBA5E04B */  vmaddw.xyzw $vf23, $vf20, $vf0w
    /* 2AE2AC 003AE2AC BF99EE4B */  vmulaw.xyzw $ACC, $vf19, $vf14w
    /* 2AE2B0 003AE2B0 BC90EE4B */  vmaddax.xyzw $ACC, $vf18, $vf14x
    /* 2AE2B4 003AE2B4 0BA6E04B */  vmaddw.xyzw $vf24, $vf20, $vf0w
    /* 2AE2B8 003AE2B8 BDD1EE4B */  vmulay.xyzw $ACC, $vf26, $vf14y
    /* 2AE2BC 003AE2BC BCC8EE4B */  vmaddax.xyzw $ACC, $vf25, $vf14x
    /* 2AE2C0 003AE2C0 0BDFE04B */  vmaddw.xyzw $vf28, $vf27, $vf0w
    /* 2AE2C4 003AE2C4 BDD1EE4B */  vmulay.xyzw $ACC, $vf26, $vf14y
    /* 2AE2C8 003AE2C8 BEC8EE4B */  vmaddaz.xyzw $ACC, $vf25, $vf14z
    /* 2AE2CC 003AE2CC 4BDFE04B */  vmaddw.xyzw $vf29, $vf27, $vf0w
    /* 2AE2D0 003AE2D0 BFD1EE4B */  vmulaw.xyzw $ACC, $vf26, $vf14w
    /* 2AE2D4 003AE2D4 BEC8EE4B */  vmaddaz.xyzw $ACC, $vf25, $vf14z
    /* 2AE2D8 003AE2D8 8BDFE04B */  vmaddw.xyzw $vf30, $vf27, $vf0w
    /* 2AE2DC 003AE2DC BFD1EE4B */  vmulaw.xyzw $ACC, $vf26, $vf14w
    /* 2AE2E0 003AE2E0 BCC8EE4B */  vmaddax.xyzw $ACC, $vf25, $vf14x
    /* 2AE2E4 003AE2E4 CBDFE04B */  vmaddw.xyzw $vf31, $vf27, $vf0w
    /* 2AE2E8 003AE2E8 000095F8 */  sqc2       $vf21, 0x0($4)
    /* 2AE2EC 003AE2EC 100096F8 */  sqc2       $vf22, 0x10($4)
    /* 2AE2F0 003AE2F0 200097F8 */  sqc2       $vf23, 0x20($4)
    /* 2AE2F4 003AE2F4 300098F8 */  sqc2       $vf24, 0x30($4)
    /* 2AE2F8 003AE2F8 40009CF8 */  sqc2       $vf28, 0x40($4)
    /* 2AE2FC 003AE2FC 50009DF8 */  sqc2       $vf29, 0x50($4)
    /* 2AE300 003AE300 60009EF8 */  sqc2       $vf30, 0x60($4)
    /* 2AE304 003AE304 70009FF8 */  sqc2       $vf31, 0x70($4)
    /* 2AE308 003AE308 38000042 */  ei /* handwritten instruction */
    /* 2AE30C 003AE30C 0200E724 */  addiu      $7, $7, 0x2
    /* 2AE310 003AE310 C000EA28 */  slti       $10, $7, 0xC0
    /* 2AE314 003AE314 2000A524 */  addiu      $5, $5, 0x20
    /* 2AE318 003AE318 0800C624 */  addiu      $6, $6, %lo(D_70000008)
    /* 2AE31C 003AE31C A4FF4015 */  bnez       $10, .L003AE1B0
    /* 2AE320 003AE320 80008424 */   addiu     $4, $4, 0x80
    /* 2AE324 003AE324 00D0048D */  lw         $4, -0x3000($8)
    /* 2AE328 003AE328 00018430 */  andi       $4, $4, 0x100
    /* 2AE32C 003AE32C 0C008010 */  beqz       $4, .L003AE360
    /* 2AE330 003AE330 00000000 */   nop
    /* 2AE334 003AE334 20E018AD */  sw         $24, -0x1FE0($8)
    /* 2AE338 003AE338 0F000000 */  sync
    /* 2AE33C 003AE33C 0F040000 */  sync.p
  .L003AE340:
    /* 2AE340 003AE340 00000000 */  nop
    /* 2AE344 003AE344 00000000 */  nop
    /* 2AE348 003AE348 00000000 */  nop
    /* 2AE34C 003AE34C 00000000 */  nop
    /* 2AE350 003AE350 00000000 */  nop
    /* 2AE354 003AE354 FAFF0041 */  bc0f       .L003AE340 /* handwritten instruction */
    /* 2AE358 003AE358 00000000 */   nop
    /* 2AE35C 003AE35C 00000000 */  nop
  .L003AE360:
    /* 2AE360 003AE360 00D4048D */  lw         $4, -0x2C00($8)
    /* 2AE364 003AE364 00018430 */  andi       $4, $4, 0x100
    /* 2AE368 003AE368 15008010 */  beqz       $4, .L003AE3C0
    /* 2AE36C 003AE36C 00000000 */   nop
    /* 2AE370 003AE370 20E016AD */  sw         $22, -0x1FE0($8)
    /* 2AE374 003AE374 0F000000 */  sync
    /* 2AE378 003AE378 0F040000 */  sync.p
    /* 2AE37C 003AE37C 00000000 */  nop
  .L003AE380:
    /* 2AE380 003AE380 00000000 */  nop
    /* 2AE384 003AE384 00000000 */  nop
    /* 2AE388 003AE388 00000000 */  nop
    /* 2AE38C 003AE38C 00000000 */  nop
    /* 2AE390 003AE390 00000000 */  nop
    /* 2AE394 003AE394 FAFF0041 */  bc0f       .L003AE380 /* handwritten instruction */
    /* 2AE398 003AE398 00000000 */   nop
    /* 2AE39C 003AE39C 00000000 */  nop
  .L003AE3A0:
    /* 2AE3A0 003AE3A0 00D4048D */  lw         $4, -0x2C00($8)
    /* 2AE3A4 003AE3A4 00018430 */  andi       $4, $4, 0x100
    /* 2AE3A8 003AE3A8 00000000 */  nop
    /* 2AE3AC 003AE3AC 00000000 */  nop
    /* 2AE3B0 003AE3B0 00000000 */  nop
    /* 2AE3B4 003AE3B4 FAFF8014 */  bnez       $4, .L003AE3A0
    /* 2AE3B8 003AE3B8 00000000 */   nop
    /* 2AE3BC 003AE3BC 00000000 */  nop
  .L003AE3C0:
    /* 2AE3C0 003AE3C0 10E018AD */  sw         $24, -0x1FF0($8)
    /* 2AE3C4 003AE3C4 80D009AD */  sw         $9, -0x2F80($8)
    /* 2AE3C8 003AE3C8 10D010AD */  sw         $16, -0x2FF0($8)
    /* 2AE3CC 003AE3CC 20D013AD */  sw         $19, -0x2FE0($8)
    /* 2AE3D0 003AE3D0 00D018AD */  sw         $24, -0x3000($8)
    /* 2AE3D4 003AE3D4 0F000000 */  sync
    /* 2AE3D8 003AE3D8 0F040000 */  sync.p
    /* 2AE3DC 003AE3DC 40FF9426 */  addiu      $20, $20, -0xC0
    /* 2AE3E0 003AE3E0 000C5226 */  addiu      $18, $18, 0xC00
    /* 2AE3E4 003AE3E4 C000812A */  slti       $1, $20, 0xC0
    /* 2AE3E8 003AE3E8 00301026 */  addiu      $16, $16, 0x3000
    /* 2AE3EC 003AE3EC 08FF2010 */  beqz       $1, .L003AE010
    /* 2AE3F0 003AE3F0 00033126 */   addiu     $17, $17, 0x300
    /* 2AE3F4 003AE3F4 00000000 */  nop
  .L003AE3F8:
    /* 2AE3F8 003AE3F8 0400812A */  slti       $1, $20, 0x4
    /* 2AE3FC 003AE3FC 1A012014 */  bnez       $1, .L003AE868
    /* 2AE400 003AE400 00000000 */   nop
    /* 2AE404 003AE404 03008106 */  bgez       $20, .L003AE414
    /* 2AE408 003AE408 83201400 */   sra       $4, $20, 2
    /* 2AE40C 003AE40C 03008426 */  addiu      $4, $20, 0x3
    /* 2AE410 003AE410 83200400 */  sra        $4, $4, 2
  .L003AE414:
    /* 2AE414 003AE414 80300400 */  sll        $6, $4, 2
    /* 2AE418 003AE418 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AE41C 003AE41C 00D0858C */  lw         $5, -0x3000($4)
    /* 2AE420 003AE420 0001A530 */  andi       $5, $5, 0x100
    /* 2AE424 003AE424 0C00A010 */  beqz       $5, .L003AE458
    /* 2AE428 003AE428 00000000 */   nop
    /* 2AE42C 003AE42C 00010524 */  addiu      $5, $0, 0x100
    /* 2AE430 003AE430 20E085AC */  sw         $5, -0x1FE0($4)
    /* 2AE434 003AE434 0F000000 */  sync
    /* 2AE438 003AE438 0F040000 */  sync.p
  .L003AE43C:
    /* 2AE43C 003AE43C 00000000 */  nop
    /* 2AE440 003AE440 00000000 */  nop
    /* 2AE444 003AE444 00000000 */  nop
    /* 2AE448 003AE448 00000000 */  nop
    /* 2AE44C 003AE44C 00000000 */  nop
    /* 2AE450 003AE450 FAFF0041 */  bc0f       .L003AE43C /* handwritten instruction */
    /* 2AE454 003AE454 00000000 */   nop
  .L003AE458:
    /* 2AE458 003AE458 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AE45C 003AE45C 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AE460 003AE460 0001A530 */  andi       $5, $5, 0x100
    /* 2AE464 003AE464 1400A010 */  beqz       $5, .L003AE4B8
    /* 2AE468 003AE468 00000000 */   nop
    /* 2AE46C 003AE46C 00020524 */  addiu      $5, $0, 0x200
    /* 2AE470 003AE470 20E085AC */  sw         $5, -0x1FE0($4)
    /* 2AE474 003AE474 0F000000 */  sync
    /* 2AE478 003AE478 0F040000 */  sync.p
  .L003AE47C:
    /* 2AE47C 003AE47C 00000000 */  nop
    /* 2AE480 003AE480 00000000 */  nop
    /* 2AE484 003AE484 00000000 */  nop
    /* 2AE488 003AE488 00000000 */  nop
    /* 2AE48C 003AE48C 00000000 */  nop
    /* 2AE490 003AE490 FAFF0041 */  bc0f       .L003AE47C /* handwritten instruction */
    /* 2AE494 003AE494 00000000 */   nop
    /* 2AE498 003AE498 0110043C */  lui        $4, (0x10010000 >> 16)
  .L003AE49C:
    /* 2AE49C 003AE49C 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AE4A0 003AE4A0 0001A530 */  andi       $5, $5, 0x100
    /* 2AE4A4 003AE4A4 00000000 */  nop
    /* 2AE4A8 003AE4A8 00000000 */  nop
    /* 2AE4AC 003AE4AC 00000000 */  nop
    /* 2AE4B0 003AE4B0 FAFFA014 */  bnez       $5, .L003AE49C
    /* 2AE4B4 003AE4B4 00000000 */   nop
  .L003AE4B8:
    /* 2AE4B8 003AE4B8 00020524 */  addiu      $5, $0, 0x200
    /* 2AE4BC 003AE4BC 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AE4C0 003AE4C0 83380600 */  sra        $7, $6, 2
    /* 2AE4C4 003AE4C4 10E085AC */  sw         $5, -0x1FF0($4)
    /* 2AE4C8 003AE4C8 80D480AC */  sw         $0, -0x2B80($4)
    /* 2AE4CC 003AE4CC 0300C104 */  bgez       $6, .L003AE4DC
    /* 2AE4D0 003AE4D0 10D491AC */   sw        $17, -0x2BF0($4)
    /* 2AE4D4 003AE4D4 0300C424 */  addiu      $4, $6, 0x3
    /* 2AE4D8 003AE4D8 83380400 */  sra        $7, $4, 2
  .L003AE4DC:
    /* 2AE4DC 003AE4DC 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AE4E0 003AE4E0 00010524 */  addiu      $5, $0, 0x100
    /* 2AE4E4 003AE4E4 20D487AC */  sw         $7, -0x2BE0($4)
    /* 2AE4E8 003AE4E8 00D485AC */  sw         $5, -0x2C00($4)
    /* 2AE4EC 003AE4EC 0F000000 */  sync
    /* 2AE4F0 003AE4F0 0F040000 */  sync.p
    /* 2AE4F4 003AE4F4 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AE4F8 003AE4F8 0001A530 */  andi       $5, $5, 0x100
    /* 2AE4FC 003AE4FC 1400A010 */  beqz       $5, .L003AE550
    /* 2AE500 003AE500 00000000 */   nop
    /* 2AE504 003AE504 00020524 */  addiu      $5, $0, 0x200
    /* 2AE508 003AE508 20E085AC */  sw         $5, -0x1FE0($4)
    /* 2AE50C 003AE50C 0F000000 */  sync
    /* 2AE510 003AE510 0F040000 */  sync.p
  .L003AE514:
    /* 2AE514 003AE514 00000000 */  nop
    /* 2AE518 003AE518 00000000 */  nop
    /* 2AE51C 003AE51C 00000000 */  nop
    /* 2AE520 003AE520 00000000 */  nop
    /* 2AE524 003AE524 00000000 */  nop
    /* 2AE528 003AE528 FAFF0041 */  bc0f       .L003AE514 /* handwritten instruction */
    /* 2AE52C 003AE52C 00000000 */   nop
    /* 2AE530 003AE530 0110043C */  lui        $4, (0x10010000 >> 16)
  .L003AE534:
    /* 2AE534 003AE534 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AE538 003AE538 0001A530 */  andi       $5, $5, 0x100
    /* 2AE53C 003AE53C 00000000 */  nop
    /* 2AE540 003AE540 00000000 */  nop
    /* 2AE544 003AE544 00000000 */  nop
    /* 2AE548 003AE548 FAFFA014 */  bnez       $5, .L003AE534
    /* 2AE54C 003AE54C 00000000 */   nop
  .L003AE550:
    /* 2AE550 003AE550 00020824 */  addiu      $8, $0, 0x200
    /* 2AE554 003AE554 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AE558 003AE558 00030724 */  addiu      $7, $0, 0x300
    /* 2AE55C 003AE55C 10E088AC */  sw         $8, -0x1FF0($4)
    /* 2AE560 003AE560 00010524 */  addiu      $5, $0, 0x100
    /* 2AE564 003AE564 80D487AC */  sw         $7, -0x2B80($4)
    /* 2AE568 003AE568 10D492AC */  sw         $18, -0x2BF0($4)
    /* 2AE56C 003AE56C 20D486AC */  sw         $6, -0x2BE0($4)
    /* 2AE570 003AE570 00D485AC */  sw         $5, -0x2C00($4)
    /* 2AE574 003AE574 0F000000 */  sync
    /* 2AE578 003AE578 0F040000 */  sync.p
    /* 2AE57C 003AE57C 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AE580 003AE580 0001A530 */  andi       $5, $5, 0x100
    /* 2AE584 003AE584 1400A010 */  beqz       $5, .L003AE5D8
    /* 2AE588 003AE588 00000000 */   nop
    /* 2AE58C 003AE58C 20E088AC */  sw         $8, -0x1FE0($4)
    /* 2AE590 003AE590 0F000000 */  sync
    /* 2AE594 003AE594 0F040000 */  sync.p
  .L003AE598:
    /* 2AE598 003AE598 00000000 */  nop
    /* 2AE59C 003AE59C 00000000 */  nop
    /* 2AE5A0 003AE5A0 00000000 */  nop
    /* 2AE5A4 003AE5A4 00000000 */  nop
    /* 2AE5A8 003AE5A8 00000000 */  nop
    /* 2AE5AC 003AE5AC FAFF0041 */  bc0f       .L003AE598 /* handwritten instruction */
    /* 2AE5B0 003AE5B0 00000000 */   nop
    /* 2AE5B4 003AE5B4 0110043C */  lui        $4, (0x10010000 >> 16)
  .L003AE5B8:
    /* 2AE5B8 003AE5B8 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AE5BC 003AE5BC 0001A530 */  andi       $5, $5, 0x100
    /* 2AE5C0 003AE5C0 00000000 */  nop
    /* 2AE5C4 003AE5C4 00000000 */  nop
    /* 2AE5C8 003AE5C8 00000000 */  nop
    /* 2AE5CC 003AE5CC FAFFA014 */  bnez       $5, .L003AE5B8
    /* 2AE5D0 003AE5D0 00000000 */   nop
    /* 2AE5D4 003AE5D4 00000000 */  nop
  .L003AE5D8:
    /* 2AE5D8 003AE5D8 00700A3C */  lui        $10, (0x70000F00 >> 16)
    /* 2AE5DC 003AE5DC 2A080600 */  slt        $1, $0, $6
    /* 2AE5E0 003AE5E0 00034535 */  ori        $5, $10, (0x70000300 & 0xFFFF)
    /* 2AE5E4 003AE5E4 000F4435 */  ori        $4, $10, (0x70000F00 & 0xFFFF)
    /* 2AE5E8 003AE5E8 61002010 */  beqz       $1, .L003AE770
    /* 2AE5EC 003AE5EC 2D480000 */   daddu     $9, $0, $0
    /* 2AE5F0 003AE5F0 0100083C */  lui        $8, (0x10000 >> 16)
  .L003AE5F4:
    /* 2AE5F4 003AE5F4 000040C5 */  lwc1       $f0, (0x70000000 & 0xFFFF)($10)
    /* 2AE5F8 003AE5F8 000060E4 */  swc1       $f0, 0x0($3)
    /* 2AE5FC 003AE5FC 040040C5 */  lwc1       $f0, (0x70000004 & 0xFFFF)($10)
    /* 2AE600 003AE600 040060E4 */  swc1       $f0, 0x4($3)
    /* 2AE604 003AE604 000040C5 */  lwc1       $f0, (0x70000000 & 0xFFFF)($10)
    /* 2AE608 003AE608 080060E4 */  swc1       $f0, 0x8($3)
    /* 2AE60C 003AE60C 040040C5 */  lwc1       $f0, (0x70000004 & 0xFFFF)($10)
    /* 2AE610 003AE610 0C0060E4 */  swc1       $f0, 0xC($3)
    /* 2AE614 003AE614 00000000 */  nop
  .L003AE618:
    /* 2AE618 003AE618 39000042 */  di /* handwritten instruction */
    /* 2AE61C 003AE61C 0F040000 */  sync.p
    /* 2AE620 003AE620 00600740 */  mfc0       $7, $12 /* handwritten instruction */
    /* 2AE624 003AE624 2438E800 */  and        $7, $7, $8
    /* 2AE628 003AE628 00000000 */  nop
    /* 2AE62C 003AE62C FAFFE014 */  bnez       $7, .L003AE618
    /* 2AE630 003AE630 00000000 */   nop
    /* 2AE634 003AE634 000061D8 */  lqc2       $vf1, 0x0($3)
    /* 2AE638 003AE638 0000B4D8 */  lqc2       $vf20, 0x0($5)
    /* 2AE63C 003AE63C 1000BBD8 */  lqc2       $vf27, 0x10($5)
    /* 2AE640 003AE640 FD09874B */  vabs.xy    $vf7, $vf1
    /* 2AE644 003AE644 3C00EA4B */  vaddax.xyzw $ACC, $vf0, $vf10x
    /* 2AE648 003AE648 CF39804B */  vmsubw.xy  $vf7, $vf7, $vf0w
    /* 2AE64C 003AE64C 3D00CA4B */  vadday.xyz $ACC, $vf0, $vf10y
    /* 2AE650 003AE650 3E002A4A */  vaddaz.w   $ACC, $vf0, $vf10z
    /* 2AE654 003AE654 8F08604A */  vmsubw.zw  $vf2, $vf1, $vf0w
    /* 2AE658 003AE658 3C00CB4B */  vaddax.xyz $ACC, $vf0, $vf11x
    /* 2AE65C 003AE65C 3D002B4A */  vadday.w   $ACC, $vf0, $vf11y
    /* 2AE660 003AE660 CF08604A */  vmsubw.zw  $vf3, $vf1, $vf0w
    /* 2AE664 003AE664 AF08624A */  vmini.zw   $vf2, $vf1, $vf2
    /* 2AE668 003AE668 EB11634A */  vmax.zw    $vf7, $vf2, $vf3
    /* 2AE66C 003AE66C AA38E74B */  vmul.xyzw  $vf2, $vf7, $vf7
    /* 2AE670 003AE670 9A39EB4B */  vmulz.xyzw $vf6, $vf7, $vf11z
    /* 2AE674 003AE674 1839EC4B */  vmulx.xyzw $vf4, $vf7, $vf12x
    /* 2AE678 003AE678 5939EC4B */  vmuly.xyzw $vf5, $vf7, $vf12y
    /* 2AE67C 003AE67C EA10E24B */  vmul.xyzw  $vf3, $vf2, $vf2
    /* 2AE680 003AE680 AA31E24B */  vmul.xyzw  $vf6, $vf6, $vf2
    /* 2AE684 003AE684 BE22E24B */  vmula.xyzw $ACC, $vf4, $vf2
    /* 2AE688 003AE688 1A39EC4B */  vmulz.xyzw $vf4, $vf7, $vf12z
    /* 2AE68C 003AE68C AA18E34B */  vmul.xyzw  $vf2, $vf3, $vf3
    /* 2AE690 003AE690 BD32E34B */  vmadda.xyzw $ACC, $vf6, $vf3
    /* 2AE694 003AE694 BD2AE34B */  vmadda.xyzw $ACC, $vf5, $vf3
    /* 2AE698 003AE698 BC38ED4B */  vmaddax.xyzw $ACC, $vf7, $vf13x
    /* 2AE69C 003AE69C E921E24B */  vmadd.xyzw $vf7, $vf4, $vf2
    /* 2AE6A0 003AE6A0 9840C74B */  vmulx.xyz  $vf2, $vf8, $vf7x
    /* 2AE6A4 003AE6A4 DA80C74B */  vmulz.xyz  $vf3, $vf16, $vf7z
    /* 2AE6A8 003AE6A8 1A49C74B */  vmulz.xyz  $vf4, $vf9, $vf7z
    /* 2AE6AC 003AE6AC 5889C74B */  vmulx.xyz  $vf5, $vf17, $vf7x
    /* 2AE6B0 003AE6B0 AC14E34B */  vsub.xyzw  $vf18, $vf2, $vf3
    /* 2AE6B4 003AE6B4 9940C74B */  vmuly.xyz  $vf2, $vf8, $vf7y
    /* 2AE6B8 003AE6B8 DB80C74B */  vmulw.xyz  $vf3, $vf16, $vf7w
    /* 2AE6BC 003AE6BC E824E54B */  vadd.xyzw  $vf19, $vf4, $vf5
    /* 2AE6C0 003AE6C0 1B49C74B */  vmulw.xyz  $vf4, $vf9, $vf7w
    /* 2AE6C4 003AE6C4 5989C74B */  vmuly.xyz  $vf5, $vf17, $vf7y
    /* 2AE6C8 003AE6C8 6C16E34B */  vsub.xyzw  $vf25, $vf2, $vf3
    /* 2AE6CC 003AE6CC BD99EE4B */  vmulay.xyzw $ACC, $vf19, $vf14y
    /* 2AE6D0 003AE6D0 BC90EE4B */  vmaddax.xyzw $ACC, $vf18, $vf14x
    /* 2AE6D4 003AE6D4 4BA5E04B */  vmaddw.xyzw $vf21, $vf20, $vf0w
    /* 2AE6D8 003AE6D8 A826E54B */  vadd.xyzw  $vf26, $vf4, $vf5
    /* 2AE6DC 003AE6DC BD99EE4B */  vmulay.xyzw $ACC, $vf19, $vf14y
    /* 2AE6E0 003AE6E0 BE90EE4B */  vmaddaz.xyzw $ACC, $vf18, $vf14z
    /* 2AE6E4 003AE6E4 8BA5E04B */  vmaddw.xyzw $vf22, $vf20, $vf0w
    /* 2AE6E8 003AE6E8 BF99EE4B */  vmulaw.xyzw $ACC, $vf19, $vf14w
    /* 2AE6EC 003AE6EC BE90EE4B */  vmaddaz.xyzw $ACC, $vf18, $vf14z
    /* 2AE6F0 003AE6F0 CBA5E04B */  vmaddw.xyzw $vf23, $vf20, $vf0w
    /* 2AE6F4 003AE6F4 BF99EE4B */  vmulaw.xyzw $ACC, $vf19, $vf14w
    /* 2AE6F8 003AE6F8 BC90EE4B */  vmaddax.xyzw $ACC, $vf18, $vf14x
    /* 2AE6FC 003AE6FC 0BA6E04B */  vmaddw.xyzw $vf24, $vf20, $vf0w
    /* 2AE700 003AE700 BDD1EE4B */  vmulay.xyzw $ACC, $vf26, $vf14y
    /* 2AE704 003AE704 BCC8EE4B */  vmaddax.xyzw $ACC, $vf25, $vf14x
    /* 2AE708 003AE708 0BDFE04B */  vmaddw.xyzw $vf28, $vf27, $vf0w
    /* 2AE70C 003AE70C BDD1EE4B */  vmulay.xyzw $ACC, $vf26, $vf14y
    /* 2AE710 003AE710 BEC8EE4B */  vmaddaz.xyzw $ACC, $vf25, $vf14z
    /* 2AE714 003AE714 4BDFE04B */  vmaddw.xyzw $vf29, $vf27, $vf0w
    /* 2AE718 003AE718 BFD1EE4B */  vmulaw.xyzw $ACC, $vf26, $vf14w
    /* 2AE71C 003AE71C BEC8EE4B */  vmaddaz.xyzw $ACC, $vf25, $vf14z
    /* 2AE720 003AE720 8BDFE04B */  vmaddw.xyzw $vf30, $vf27, $vf0w
    /* 2AE724 003AE724 BFD1EE4B */  vmulaw.xyzw $ACC, $vf26, $vf14w
    /* 2AE728 003AE728 BCC8EE4B */  vmaddax.xyzw $ACC, $vf25, $vf14x
    /* 2AE72C 003AE72C CBDFE04B */  vmaddw.xyzw $vf31, $vf27, $vf0w
    /* 2AE730 003AE730 000095F8 */  sqc2       $vf21, 0x0($4)
    /* 2AE734 003AE734 100096F8 */  sqc2       $vf22, 0x10($4)
    /* 2AE738 003AE738 200097F8 */  sqc2       $vf23, 0x20($4)
    /* 2AE73C 003AE73C 300098F8 */  sqc2       $vf24, 0x30($4)
    /* 2AE740 003AE740 40009CF8 */  sqc2       $vf28, 0x40($4)
    /* 2AE744 003AE744 50009DF8 */  sqc2       $vf29, 0x50($4)
    /* 2AE748 003AE748 60009EF8 */  sqc2       $vf30, 0x60($4)
    /* 2AE74C 003AE74C 70009FF8 */  sqc2       $vf31, 0x70($4)
    /* 2AE750 003AE750 38000042 */  ei /* handwritten instruction */
    /* 2AE754 003AE754 02002925 */  addiu      $9, $9, 0x2
    /* 2AE758 003AE758 2A382601 */  slt        $7, $9, $6
    /* 2AE75C 003AE75C 2000A524 */  addiu      $5, $5, 0x20
    /* 2AE760 003AE760 08004A25 */  addiu      $10, $10, %lo(D_70000008)
    /* 2AE764 003AE764 A3FFE014 */  bnez       $7, .L003AE5F4
    /* 2AE768 003AE768 80008424 */   addiu     $4, $4, 0x80
    /* 2AE76C 003AE76C 00000000 */  nop
  .L003AE770:
    /* 2AE770 003AE770 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AE774 003AE774 00D0858C */  lw         $5, -0x3000($4)
    /* 2AE778 003AE778 0001A530 */  andi       $5, $5, 0x100
    /* 2AE77C 003AE77C 0C00A010 */  beqz       $5, .L003AE7B0
    /* 2AE780 003AE780 00000000 */   nop
    /* 2AE784 003AE784 00010524 */  addiu      $5, $0, 0x100
    /* 2AE788 003AE788 20E085AC */  sw         $5, -0x1FE0($4)
    /* 2AE78C 003AE78C 0F000000 */  sync
    /* 2AE790 003AE790 0F040000 */  sync.p
  .L003AE794:
    /* 2AE794 003AE794 00000000 */  nop
    /* 2AE798 003AE798 00000000 */  nop
    /* 2AE79C 003AE79C 00000000 */  nop
    /* 2AE7A0 003AE7A0 00000000 */  nop
    /* 2AE7A4 003AE7A4 00000000 */  nop
    /* 2AE7A8 003AE7A8 FAFF0041 */  bc0f       .L003AE794 /* handwritten instruction */
    /* 2AE7AC 003AE7AC 00000000 */   nop
  .L003AE7B0:
    /* 2AE7B0 003AE7B0 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AE7B4 003AE7B4 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AE7B8 003AE7B8 0001A530 */  andi       $5, $5, 0x100
    /* 2AE7BC 003AE7BC 1400A010 */  beqz       $5, .L003AE810
    /* 2AE7C0 003AE7C0 00000000 */   nop
    /* 2AE7C4 003AE7C4 00020524 */  addiu      $5, $0, 0x200
    /* 2AE7C8 003AE7C8 20E085AC */  sw         $5, -0x1FE0($4)
    /* 2AE7CC 003AE7CC 0F000000 */  sync
    /* 2AE7D0 003AE7D0 0F040000 */  sync.p
  .L003AE7D4:
    /* 2AE7D4 003AE7D4 00000000 */  nop
    /* 2AE7D8 003AE7D8 00000000 */  nop
    /* 2AE7DC 003AE7DC 00000000 */  nop
    /* 2AE7E0 003AE7E0 00000000 */  nop
    /* 2AE7E4 003AE7E4 00000000 */  nop
    /* 2AE7E8 003AE7E8 FAFF0041 */  bc0f       .L003AE7D4 /* handwritten instruction */
    /* 2AE7EC 003AE7EC 00000000 */   nop
    /* 2AE7F0 003AE7F0 0110043C */  lui        $4, (0x10010000 >> 16)
  .L003AE7F4:
    /* 2AE7F4 003AE7F4 00D4858C */  lw         $5, -0x2C00($4)
    /* 2AE7F8 003AE7F8 0001A530 */  andi       $5, $5, 0x100
    /* 2AE7FC 003AE7FC 00000000 */  nop
    /* 2AE800 003AE800 00000000 */  nop
    /* 2AE804 003AE804 00000000 */  nop
    /* 2AE808 003AE808 FAFFA014 */  bnez       $5, .L003AE7F4
    /* 2AE80C 003AE80C 00000000 */   nop
  .L003AE810:
    /* 2AE810 003AE810 00010824 */  addiu      $8, $0, 0x100
    /* 2AE814 003AE814 0110043C */  lui        $4, (0x10010000 >> 16)
    /* 2AE818 003AE818 000F0724 */  addiu      $7, $0, 0xF00
    /* 2AE81C 003AE81C 10E088AC */  sw         $8, -0x1FF0($4)
    /* 2AE820 003AE820 80280600 */  sll        $5, $6, 2
    /* 2AE824 003AE824 80D087AC */  sw         $7, -0x2F80($4)
    /* 2AE828 003AE828 10D090AC */  sw         $16, -0x2FF0($4)
    /* 2AE82C 003AE82C 20D085AC */  sw         $5, -0x2FE0($4)
    /* 2AE830 003AE830 00D088AC */  sw         $8, -0x3000($4)
    /* 2AE834 003AE834 0F000000 */  sync
    /* 2AE838 003AE838 0F040000 */  sync.p
    /* 2AE83C 003AE83C 00210500 */  sll        $4, $5, 4
    /* 2AE840 003AE840 00290600 */  sll        $5, $6, 4
    /* 2AE844 003AE844 21800402 */  addu       $16, $16, $4
    /* 2AE848 003AE848 21904502 */  addu       $18, $18, $5
    /* 2AE84C 003AE84C 0300C104 */  bgez       $6, .L003AE85C
    /* 2AE850 003AE850 83200600 */   sra       $4, $6, 2
    /* 2AE854 003AE854 0300C424 */  addiu      $4, $6, 0x3
    /* 2AE858 003AE858 83200400 */  sra        $4, $4, 2
  .L003AE85C:
    /* 2AE85C 003AE85C 00210400 */  sll        $4, $4, 4
    /* 2AE860 003AE860 23A08602 */  subu       $20, $20, $6
    /* 2AE864 003AE864 21882402 */  addu       $17, $17, $4
  .L003AE868:
    /* 2AE868 003AE868 2A081400 */  slt        $1, $0, $20
    /* 2AE86C 003AE86C 2A012010 */  beqz       $1, .L003AED18
    /* 2AE870 003AE870 2D380000 */   daddu     $7, $0, $0
    /* 2AE874 003AE874 B000A47B */  lq         $4, 0xB0($29)
    /* 2AE878 003AE878 0100063C */  lui        $6, (0x10000 >> 16)
    /* 2AE87C 003AE87C 80280400 */  sll        $5, $4, 2
  .L003AE880:
    /* 2AE880 003AE880 000020C6 */  lwc1       $f0, 0x0($17)
    /* 2AE884 003AE884 000060E4 */  swc1       $f0, 0x0($3)
    /* 2AE888 003AE888 000020C6 */  lwc1       $f0, 0x0($17)
    /* 2AE88C 003AE88C 080060E4 */  swc1       $f0, 0x8($3)
  .L003AE890:
    /* 2AE890 003AE890 39000042 */  di /* handwritten instruction */
    /* 2AE894 003AE894 0F040000 */  sync.p
    /* 2AE898 003AE898 00600440 */  mfc0       $4, $12 /* handwritten instruction */
    /* 2AE89C 003AE89C 24208600 */  and        $4, $4, $6
    /* 2AE8A0 003AE8A0 00000000 */  nop
    /* 2AE8A4 003AE8A4 FAFF8014 */  bnez       $4, .L003AE890
    /* 2AE8A8 003AE8A8 00000000 */   nop
    /* 2AE8AC 003AE8AC 000061D8 */  lqc2       $vf1, 0x0($3)
    /* 2AE8B0 003AE8B0 000054DA */  lqc2       $vf20, 0x0($18)
    /* 2AE8B4 003AE8B4 FD09874B */  vabs.xy    $vf7, $vf1
    /* 2AE8B8 003AE8B8 3C00EA4B */  vaddax.xyzw $ACC, $vf0, $vf10x
    /* 2AE8BC 003AE8BC CF39804B */  vmsubw.xy  $vf7, $vf7, $vf0w
    /* 2AE8C0 003AE8C0 3D00CA4B */  vadday.xyz $ACC, $vf0, $vf10y
    /* 2AE8C4 003AE8C4 3E002A4A */  vaddaz.w   $ACC, $vf0, $vf10z
    /* 2AE8C8 003AE8C8 8F08604A */  vmsubw.zw  $vf2, $vf1, $vf0w
    /* 2AE8CC 003AE8CC 3C00CB4B */  vaddax.xyz $ACC, $vf0, $vf11x
    /* 2AE8D0 003AE8D0 3D002B4A */  vadday.w   $ACC, $vf0, $vf11y
    /* 2AE8D4 003AE8D4 CF08604A */  vmsubw.zw  $vf3, $vf1, $vf0w
    /* 2AE8D8 003AE8D8 AF08624A */  vmini.zw   $vf2, $vf1, $vf2
    /* 2AE8DC 003AE8DC EB11634A */  vmax.zw    $vf7, $vf2, $vf3
    /* 2AE8E0 003AE8E0 AA38E74B */  vmul.xyzw  $vf2, $vf7, $vf7
    /* 2AE8E4 003AE8E4 9A39EB4B */  vmulz.xyzw $vf6, $vf7, $vf11z
    /* 2AE8E8 003AE8E8 1839EC4B */  vmulx.xyzw $vf4, $vf7, $vf12x
    /* 2AE8EC 003AE8EC 5939EC4B */  vmuly.xyzw $vf5, $vf7, $vf12y
    /* 2AE8F0 003AE8F0 EA10E24B */  vmul.xyzw  $vf3, $vf2, $vf2
    /* 2AE8F4 003AE8F4 AA31E24B */  vmul.xyzw  $vf6, $vf6, $vf2
    /* 2AE8F8 003AE8F8 BE22E24B */  vmula.xyzw $ACC, $vf4, $vf2
    /* 2AE8FC 003AE8FC 1A39EC4B */  vmulz.xyzw $vf4, $vf7, $vf12z
    /* 2AE900 003AE900 AA18E34B */  vmul.xyzw  $vf2, $vf3, $vf3
    /* 2AE904 003AE904 BD32E34B */  vmadda.xyzw $ACC, $vf6, $vf3
    /* 2AE908 003AE908 BD2AE34B */  vmadda.xyzw $ACC, $vf5, $vf3
    /* 2AE90C 003AE90C BC38ED4B */  vmaddax.xyzw $ACC, $vf7, $vf13x
    /* 2AE910 003AE910 E921E24B */  vmadd.xyzw $vf7, $vf4, $vf2
    /* 2AE914 003AE914 9840C74B */  vmulx.xyz  $vf2, $vf8, $vf7x
    /* 2AE918 003AE918 DA80C74B */  vmulz.xyz  $vf3, $vf16, $vf7z
    /* 2AE91C 003AE91C 1A49C74B */  vmulz.xyz  $vf4, $vf9, $vf7z
    /* 2AE920 003AE920 5889C74B */  vmulx.xyz  $vf5, $vf17, $vf7x
    /* 2AE924 003AE924 AC14E34B */  vsub.xyzw  $vf18, $vf2, $vf3
    /* 2AE928 003AE928 E824E54B */  vadd.xyzw  $vf19, $vf4, $vf5
    /* 2AE92C 003AE92C BD99EE4B */  vmulay.xyzw $ACC, $vf19, $vf14y
    /* 2AE930 003AE930 BC90EE4B */  vmaddax.xyzw $ACC, $vf18, $vf14x
    /* 2AE934 003AE934 4BA5E04B */  vmaddw.xyzw $vf21, $vf20, $vf0w
    /* 2AE938 003AE938 BD99EE4B */  vmulay.xyzw $ACC, $vf19, $vf14y
    /* 2AE93C 003AE93C BE90EE4B */  vmaddaz.xyzw $ACC, $vf18, $vf14z
    /* 2AE940 003AE940 8BA5E04B */  vmaddw.xyzw $vf22, $vf20, $vf0w
    /* 2AE944 003AE944 BF99EE4B */  vmulaw.xyzw $ACC, $vf19, $vf14w
    /* 2AE948 003AE948 BE90EE4B */  vmaddaz.xyzw $ACC, $vf18, $vf14z
    /* 2AE94C 003AE94C CBA5E04B */  vmaddw.xyzw $vf23, $vf20, $vf0w
    /* 2AE950 003AE950 BF99EE4B */  vmulaw.xyzw $ACC, $vf19, $vf14w
    /* 2AE954 003AE954 BC90EE4B */  vmaddax.xyzw $ACC, $vf18, $vf14x
    /* 2AE958 003AE958 0BA6E04B */  vmaddw.xyzw $vf24, $vf20, $vf0w
    /* 2AE95C 003AE95C 000015FA */  sqc2       $vf21, 0x0($16)
    /* 2AE960 003AE960 100016FA */  sqc2       $vf22, 0x10($16)
    /* 2AE964 003AE964 200017FA */  sqc2       $vf23, 0x20($16)
    /* 2AE968 003AE968 300018FA */  sqc2       $vf24, 0x30($16)
    /* 2AE96C 003AE96C 38000042 */  ei /* handwritten instruction */
    /* 2AE970 003AE970 0100E724 */  addiu      $7, $7, 0x1
    /* 2AE974 003AE974 2A20F400 */  slt        $4, $7, $20
    /* 2AE978 003AE978 21905702 */  addu       $18, $18, $23
    /* 2AE97C 003AE97C 21883E02 */  addu       $17, $17, $30
    /* 2AE980 003AE980 BFFF8014 */  bnez       $4, .L003AE880
    /* 2AE984 003AE984 21800502 */   addu      $16, $16, $5
    /* 2AE988 003AE988 E3000010 */  b          .L003AED18
    /* 2AE98C 003AE98C 00000000 */   nop
  .L003AE990:
    /* 2AE990 003AE990 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 2AE994 003AE994 1401B627 */  addiu      $22, $29, 0x114
    /* 2AE998 003AE998 00088244 */  mtc1       $2, $f1
    /* 2AE99C 003AE99C 0001A427 */  addiu      $4, $29, 0x100
    /* 2AE9A0 003AE9A0 680060C6 */  lwc1       $f0, 0x68($19)
    /* 2AE9A4 003AE9A4 0C000624 */  addiu      $6, $0, 0xC
    /* 2AE9A8 003AE9A8 430D1746 */  div.s      $f21, $f1, $f23
    /* 2AE9AC 003AE9AC 02001546 */  mul.s      $f0, $f0, $f21
    /* 2AE9B0 003AE9B0 1001A0E7 */  swc1       $f0, 0x110($29)
    /* 2AE9B4 003AE9B4 030D1646 */  div.s      $f20, $f1, $f22
    /* 2AE9B8 003AE9B8 6C0060C6 */  lwc1       $f0, 0x6C($19)
    /* 2AE9BC 003AE9BC 02001446 */  mul.s      $f0, $f0, $f20
    /* 2AE9C0 003AE9C0 04FE100C */  jal        func_0043f810
    /* 2AE9C4 003AE9C4 0000C0E6 */   swc1      $f0, 0x0($22)
    /* 2AE9C8 003AE9C8 2D28A002 */  daddu      $5, $21, $0
    /* 2AE9CC 003AE9CC F000A427 */  addiu      $4, $29, 0xF0
    /* 2AE9D0 003AE9D0 04FE100C */  jal        func_0043f810
    /* 2AE9D4 003AE9D4 0C000624 */   addiu     $6, $0, 0xC
    /* 2AE9D8 003AE9D8 680061C6 */  lwc1       $f1, 0x68($19)
    /* 2AE9DC 003AE9DC 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 2AE9E0 003AE9E0 00188344 */  mtc1       $3, $f3
    /* 2AE9E4 003AE9E4 00008044 */  mtc1       $0, $f0
    /* 2AE9E8 003AE9E8 6C0062C6 */  lwc1       $f2, 0x6C($19)
    /* 2AE9EC 003AE9EC 0100033C */  lui        $3, (0x10000 >> 16)
    /* 2AE9F0 003AE9F0 18000346 */  adda.s     $f0, $f3
    /* 2AE9F4 003AE9F4 02091546 */  mul.s      $f4, $f1, $f21
    /* 2AE9F8 003AE9F8 5C081546 */  madd.s     $f1, $f1, $f21
    /* 2AE9FC 003AE9FC 18000346 */  adda.s     $f0, $f3
    /* 2AEA00 003AEA00 01200346 */  sub.s      $f0, $f4, $f3
    /* 2AEA04 003AEA04 1001A0E7 */  swc1       $f0, 0x110($29)
    /* 2AEA08 003AEA08 02101446 */  mul.s      $f0, $f2, $f20
    /* 2AEA0C 003AEA0C 01000346 */  sub.s      $f0, $f0, $f3
    /* 2AEA10 003AEA10 0000C0E6 */  swc1       $f0, 0x0($22)
    /* 2AEA14 003AEA14 1C101446 */  madd.s     $f0, $f2, $f20
    /* 2AEA18 003AEA18 1801A1E7 */  swc1       $f1, 0x118($29)
    /* 2AEA1C 003AEA1C 1C01A0E7 */  swc1       $f0, 0x11C($29)
  .L003AEA20:
    /* 2AEA20 003AEA20 39000042 */  di /* handwritten instruction */
    /* 2AEA24 003AEA24 0F040000 */  sync.p
    /* 2AEA28 003AEA28 00600440 */  mfc0       $4, $12 /* handwritten instruction */
    /* 2AEA2C 003AEA2C 24208300 */  and        $4, $4, $3
    /* 2AEA30 003AEA30 00000000 */  nop
    /* 2AEA34 003AEA34 FAFF8014 */  bnez       $4, .L003AEA20
    /* 2AEA38 003AEA38 00000000 */   nop
    /* 2AEA3C 003AEA3C C93F013C */  lui        $1, (0x3FC90FDB >> 16)
    /* 2AEA40 003AEA40 DB0F2334 */  ori        $3, $1, (0x3FC90FDB & 0xFFFF)
    /* 2AEA44 003AEA44 00008344 */  mtc1       $3, $f0
    /* 2AEA48 003AEA48 00000344 */  mfc1       $3, $f0
    /* 2AEA4C 003AEA4C 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AEA50 003AEA50 FF02004A */  vnop
    /* 2AEA54 003AEA54 FF02004A */  vnop
    /* 2AEA58 003AEA58 A202004B */  vaddi.x    $vf10, $vf0, $I
    /* 2AEA5C 003AEA5C 4940013C */  lui        $1, (0x40490FDB >> 16)
    /* 2AEA60 003AEA60 DB0F2434 */  ori        $4, $1, (0x40490FDB & 0xFFFF)
    /* 2AEA64 003AEA64 00008444 */  mtc1       $4, $f0
    /* 2AEA68 003AEA68 00000344 */  mfc1       $3, $f0
    /* 2AEA6C 003AEA6C 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AEA70 003AEA70 FF02004A */  vnop
    /* 2AEA74 003AEA74 FF02004A */  vnop
    /* 2AEA78 003AEA78 A202804A */  vaddi.y    $vf10, $vf0, $I
    /* 2AEA7C 003AEA7C 0940013C */  lui        $1, (0x40090FDB >> 16)
    /* 2AEA80 003AEA80 DB0F2334 */  ori        $3, $1, (0x40090FDB & 0xFFFF)
    /* 2AEA84 003AEA84 00008344 */  mtc1       $3, $f0
    /* 2AEA88 003AEA88 00000344 */  mfc1       $3, $f0
    /* 2AEA8C 003AEA8C 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AEA90 003AEA90 FF02004A */  vnop
    /* 2AEA94 003AEA94 FF02004A */  vnop
    /* 2AEA98 003AEA98 A202404A */  vaddi.z    $vf10, $vf0, $I
    /* 2AEA9C 003AEA9C 00008444 */  mtc1       $4, $f0
    /* 2AEAA0 003AEAA0 07000046 */  neg.s      $f0, $f0
    /* 2AEAA4 003AEAA4 00000344 */  mfc1       $3, $f0
    /* 2AEAA8 003AEAA8 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AEAAC 003AEAAC FF02004A */  vnop
    /* 2AEAB0 003AEAB0 FF02004A */  vnop
    /* 2AEAB4 003AEAB4 E202004B */  vaddi.x    $vf11, $vf0, $I
    /* 2AEAB8 003AEAB8 8440013C */  lui        $1, (0x408487ED >> 16)
    /* 2AEABC 003AEABC ED872334 */  ori        $3, $1, (0x408487ED & 0xFFFF)
    /* 2AEAC0 003AEAC0 00008344 */  mtc1       $3, $f0
    /* 2AEAC4 003AEAC4 07000046 */  neg.s      $f0, $f0
    /* 2AEAC8 003AEAC8 00000344 */  mfc1       $3, $f0
    /* 2AEACC 003AEACC 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AEAD0 003AEAD0 FF02004A */  vnop
    /* 2AEAD4 003AEAD4 FF02004A */  vnop
    /* 2AEAD8 003AEAD8 E202804A */  vaddi.y    $vf11, $vf0, $I
    /* 2AEADC 003AEADC 00000334 */  ori        $3, $0, 0x0
    /* 2AEAE0 003AEAE0 381C0300 */  dsll       $3, $3, 16
    /* 2AEAE4 003AEAE4 381C0300 */  dsll       $3, $3, 16
    /* 2AEAE8 003AEAE8 4FB96334 */  ori        $3, $3, 0xB94F
    /* 2AEAEC 003AEAEC 381C0300 */  dsll       $3, $3, 16
    /* 2AEAF0 003AEAF0 1FB26334 */  ori        $3, $3, 0xB21F
    /* 2AEAF4 003AEAF4 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AEAF8 003AEAF8 FF02004A */  vnop
    /* 2AEAFC 003AEAFC FF02004A */  vnop
    /* 2AEB00 003AEB00 E202404A */  vaddi.z    $vf11, $vf0, $I
    /* 2AEB04 003AEB04 00000334 */  ori        $3, $0, 0x0
    /* 2AEB08 003AEB08 381C0300 */  dsll       $3, $3, 16
    /* 2AEB0C 003AEB0C 381C0300 */  dsll       $3, $3, 16
    /* 2AEB10 003AEB10 2ABE6334 */  ori        $3, $3, 0xBE2A
    /* 2AEB14 003AEB14 381C0300 */  dsll       $3, $3, 16
    /* 2AEB18 003AEB18 A4AA6334 */  ori        $3, $3, 0xAAA4
    /* 2AEB1C 003AEB1C 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AEB20 003AEB20 FF02004A */  vnop
    /* 2AEB24 003AEB24 FF02004A */  vnop
    /* 2AEB28 003AEB28 2203004B */  vaddi.x    $vf12, $vf0, $I
    /* 2AEB2C 003AEB2C 083C013C */  lui        $1, (0x3C08873E >> 16)
    /* 2AEB30 003AEB30 3E872334 */  ori        $3, $1, (0x3C08873E & 0xFFFF)
    /* 2AEB34 003AEB34 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AEB38 003AEB38 FF02004A */  vnop
    /* 2AEB3C 003AEB3C FF02004A */  vnop
    /* 2AEB40 003AEB40 2203804A */  vaddi.y    $vf12, $vf0, $I
    /* 2AEB44 003AEB44 2E36013C */  lui        $1, (0x362E9C14 >> 16)
    /* 2AEB48 003AEB48 149C2334 */  ori        $3, $1, (0x362E9C14 & 0xFFFF)
    /* 2AEB4C 003AEB4C 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AEB50 003AEB50 FF02004A */  vnop
    /* 2AEB54 003AEB54 FF02004A */  vnop
    /* 2AEB58 003AEB58 2203404A */  vaddi.z    $vf12, $vf0, $I
    /* 2AEB5C 003AEB5C 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 2AEB60 003AEB60 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2AEB64 003AEB64 FF02004A */  vnop
    /* 2AEB68 003AEB68 FF02004A */  vnop
    /* 2AEB6C 003AEB6C 6203004B */  vaddi.x    $vf13, $vf0, $I
    /* 2AEB70 003AEB70 38000042 */  ei /* handwritten instruction */
    /* 2AEB74 003AEB74 0100033C */  lui        $3, (0x10000 >> 16)
    /* 2AEB78 003AEB78 EC00B7E7 */  swc1       $f23, 0xEC($29)
    /* 2AEB7C 003AEB7C E800B7E7 */  swc1       $f23, 0xE8($29)
    /* 2AEB80 003AEB80 E400B7E7 */  swc1       $f23, 0xE4($29)
    /* 2AEB84 003AEB84 E000B7E7 */  swc1       $f23, 0xE0($29)
    /* 2AEB88 003AEB88 DC00B6E7 */  swc1       $f22, 0xDC($29)
    /* 2AEB8C 003AEB8C D800B6E7 */  swc1       $f22, 0xD8($29)
    /* 2AEB90 003AEB90 D400B6E7 */  swc1       $f22, 0xD4($29)
    /* 2AEB94 003AEB94 D000B6E7 */  swc1       $f22, 0xD0($29)
  .L003AEB98:
    /* 2AEB98 003AEB98 39000042 */  di /* handwritten instruction */
    /* 2AEB9C 003AEB9C 0F040000 */  sync.p
    /* 2AEBA0 003AEBA0 00600440 */  mfc0       $4, $12 /* handwritten instruction */
    /* 2AEBA4 003AEBA4 24208300 */  and        $4, $4, $3
    /* 2AEBA8 003AEBA8 00000000 */  nop
    /* 2AEBAC 003AEBAC FAFF8014 */  bnez       $4, .L003AEB98
    /* 2AEBB0 003AEBB0 00000000 */   nop
    /* 2AEBB4 003AEBB4 0001A727 */  addiu      $7, $29, 0x100
    /* 2AEBB8 003AEBB8 F000A627 */  addiu      $6, $29, 0xF0
    /* 2AEBBC 003AEBBC E000A527 */  addiu      $5, $29, 0xE0
    /* 2AEBC0 003AEBC0 D000A427 */  addiu      $4, $29, 0xD0
    /* 2AEBC4 003AEBC4 1001A327 */  addiu      $3, $29, 0x110
    /* 2AEBC8 003AEBC8 0000E2D8 */  lqc2       $vf2, 0x0($7)
    /* 2AEBCC 003AEBCC 0000A4D8 */  lqc2       $vf4, 0x0($5)
    /* 2AEBD0 003AEBD0 0000C3D8 */  lqc2       $vf3, 0x0($6)
    /* 2AEBD4 003AEBD4 000085D8 */  lqc2       $vf5, 0x0($4)
    /* 2AEBD8 003AEBD8 00006ED8 */  lqc2       $vf14, 0x0($3)
    /* 2AEBDC 003AEBDC 2A12E44B */  vmul.xyzw  $vf8, $vf2, $vf4
    /* 2AEBE0 003AEBE0 2A1CE44B */  vmul.xyzw  $vf16, $vf3, $vf4
    /* 2AEBE4 003AEBE4 6A12E54B */  vmul.xyzw  $vf9, $vf2, $vf5
    /* 2AEBE8 003AEBE8 6A1CE54B */  vmul.xyzw  $vf17, $vf3, $vf5
    /* 2AEBEC 003AEBEC 38000042 */  ei /* handwritten instruction */
    /* 2AEBF0 003AEBF0 2A081400 */  slt        $1, $0, $20
    /* 2AEBF4 003AEBF4 48002010 */  beqz       $1, .L003AED18
    /* 2AEBF8 003AEBF8 2D400000 */   daddu     $8, $0, $0
    /* 2AEBFC 003AEBFC B000A37B */  lq         $3, 0xB0($29)
    /* 2AEC00 003AEC00 C800A727 */  addiu      $7, $29, 0xC8
    /* 2AEC04 003AEC04 C000A527 */  addiu      $5, $29, 0xC0
    /* 2AEC08 003AEC08 0100063C */  lui        $6, (0x10000 >> 16)
    /* 2AEC0C 003AEC0C 80200300 */  sll        $4, $3, 2
  .L003AEC10:
    /* 2AEC10 003AEC10 000020C6 */  lwc1       $f0, 0x0($17)
    /* 2AEC14 003AEC14 C000A0E7 */  swc1       $f0, 0xC0($29)
    /* 2AEC18 003AEC18 0000E0E4 */  swc1       $f0, 0x0($7)
    /* 2AEC1C 003AEC1C 00000000 */  nop
  .L003AEC20:
    /* 2AEC20 003AEC20 39000042 */  di /* handwritten instruction */
    /* 2AEC24 003AEC24 0F040000 */  sync.p
    /* 2AEC28 003AEC28 00600340 */  mfc0       $3, $12 /* handwritten instruction */
    /* 2AEC2C 003AEC2C 24186600 */  and        $3, $3, $6
    /* 2AEC30 003AEC30 00000000 */  nop
    /* 2AEC34 003AEC34 FAFF6014 */  bnez       $3, .L003AEC20
    /* 2AEC38 003AEC38 00000000 */   nop
    /* 2AEC3C 003AEC3C 0000A1D8 */  lqc2       $vf1, 0x0($5)
    /* 2AEC40 003AEC40 000054DA */  lqc2       $vf20, 0x0($18)
    /* 2AEC44 003AEC44 FD09874B */  vabs.xy    $vf7, $vf1
    /* 2AEC48 003AEC48 3C00EA4B */  vaddax.xyzw $ACC, $vf0, $vf10x
    /* 2AEC4C 003AEC4C CF39804B */  vmsubw.xy  $vf7, $vf7, $vf0w
    /* 2AEC50 003AEC50 3D00CA4B */  vadday.xyz $ACC, $vf0, $vf10y
    /* 2AEC54 003AEC54 3E002A4A */  vaddaz.w   $ACC, $vf0, $vf10z
    /* 2AEC58 003AEC58 8F08604A */  vmsubw.zw  $vf2, $vf1, $vf0w
    /* 2AEC5C 003AEC5C 3C00CB4B */  vaddax.xyz $ACC, $vf0, $vf11x
    /* 2AEC60 003AEC60 3D002B4A */  vadday.w   $ACC, $vf0, $vf11y
    /* 2AEC64 003AEC64 CF08604A */  vmsubw.zw  $vf3, $vf1, $vf0w
    /* 2AEC68 003AEC68 AF08624A */  vmini.zw   $vf2, $vf1, $vf2
    /* 2AEC6C 003AEC6C EB11634A */  vmax.zw    $vf7, $vf2, $vf3
    /* 2AEC70 003AEC70 AA38E74B */  vmul.xyzw  $vf2, $vf7, $vf7
    /* 2AEC74 003AEC74 9A39EB4B */  vmulz.xyzw $vf6, $vf7, $vf11z
    /* 2AEC78 003AEC78 1839EC4B */  vmulx.xyzw $vf4, $vf7, $vf12x
    /* 2AEC7C 003AEC7C 5939EC4B */  vmuly.xyzw $vf5, $vf7, $vf12y
    /* 2AEC80 003AEC80 EA10E24B */  vmul.xyzw  $vf3, $vf2, $vf2
    /* 2AEC84 003AEC84 AA31E24B */  vmul.xyzw  $vf6, $vf6, $vf2
    /* 2AEC88 003AEC88 BE22E24B */  vmula.xyzw $ACC, $vf4, $vf2
    /* 2AEC8C 003AEC8C 1A39EC4B */  vmulz.xyzw $vf4, $vf7, $vf12z
    /* 2AEC90 003AEC90 AA18E34B */  vmul.xyzw  $vf2, $vf3, $vf3
    /* 2AEC94 003AEC94 BD32E34B */  vmadda.xyzw $ACC, $vf6, $vf3
    /* 2AEC98 003AEC98 BD2AE34B */  vmadda.xyzw $ACC, $vf5, $vf3
    /* 2AEC9C 003AEC9C BC38ED4B */  vmaddax.xyzw $ACC, $vf7, $vf13x
    /* 2AECA0 003AECA0 E921E24B */  vmadd.xyzw $vf7, $vf4, $vf2
    /* 2AECA4 003AECA4 9840C74B */  vmulx.xyz  $vf2, $vf8, $vf7x
    /* 2AECA8 003AECA8 DA80C74B */  vmulz.xyz  $vf3, $vf16, $vf7z
    /* 2AECAC 003AECAC 1A49C74B */  vmulz.xyz  $vf4, $vf9, $vf7z
    /* 2AECB0 003AECB0 5889C74B */  vmulx.xyz  $vf5, $vf17, $vf7x
    /* 2AECB4 003AECB4 AC14E34B */  vsub.xyzw  $vf18, $vf2, $vf3
    /* 2AECB8 003AECB8 E824E54B */  vadd.xyzw  $vf19, $vf4, $vf5
    /* 2AECBC 003AECBC BD99EE4B */  vmulay.xyzw $ACC, $vf19, $vf14y
    /* 2AECC0 003AECC0 BC90EE4B */  vmaddax.xyzw $ACC, $vf18, $vf14x
    /* 2AECC4 003AECC4 4BA5E04B */  vmaddw.xyzw $vf21, $vf20, $vf0w
    /* 2AECC8 003AECC8 BD99EE4B */  vmulay.xyzw $ACC, $vf19, $vf14y
    /* 2AECCC 003AECCC BE90EE4B */  vmaddaz.xyzw $ACC, $vf18, $vf14z
    /* 2AECD0 003AECD0 8BA5E04B */  vmaddw.xyzw $vf22, $vf20, $vf0w
    /* 2AECD4 003AECD4 BF99EE4B */  vmulaw.xyzw $ACC, $vf19, $vf14w
    /* 2AECD8 003AECD8 BE90EE4B */  vmaddaz.xyzw $ACC, $vf18, $vf14z
    /* 2AECDC 003AECDC CBA5E04B */  vmaddw.xyzw $vf23, $vf20, $vf0w
    /* 2AECE0 003AECE0 BF99EE4B */  vmulaw.xyzw $ACC, $vf19, $vf14w
    /* 2AECE4 003AECE4 BC90EE4B */  vmaddax.xyzw $ACC, $vf18, $vf14x
    /* 2AECE8 003AECE8 0BA6E04B */  vmaddw.xyzw $vf24, $vf20, $vf0w
    /* 2AECEC 003AECEC 000015FA */  sqc2       $vf21, 0x0($16)
    /* 2AECF0 003AECF0 100016FA */  sqc2       $vf22, 0x10($16)
    /* 2AECF4 003AECF4 200017FA */  sqc2       $vf23, 0x20($16)
    /* 2AECF8 003AECF8 300018FA */  sqc2       $vf24, 0x30($16)
    /* 2AECFC 003AECFC 38000042 */  ei /* handwritten instruction */
    /* 2AED00 003AED00 01000825 */  addiu      $8, $8, 0x1
    /* 2AED04 003AED04 2A181401 */  slt        $3, $8, $20
    /* 2AED08 003AED08 21905702 */  addu       $18, $18, $23
    /* 2AED0C 003AED0C 21883E02 */  addu       $17, $17, $30
    /* 2AED10 003AED10 BFFF6014 */  bnez       $3, .L003AEC10
    /* 2AED14 003AED14 21800402 */   addu      $16, $16, $4
  .L003AED18:
    /* 2AED18 003AED18 A000BFDF */  ld         $31, 0xA0($29)
    /* 2AED1C 003AED1C 9000BE7B */  lq         $30, 0x90($29)
    /* 2AED20 003AED20 0C00B7C7 */  lwc1       $f23, 0xC($29)
    /* 2AED24 003AED24 8000B77B */  lq         $23, 0x80($29)
    /* 2AED28 003AED28 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* 2AED2C 003AED2C 7000B67B */  lq         $22, 0x70($29)
    /* 2AED30 003AED30 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 2AED34 003AED34 6000B57B */  lq         $21, 0x60($29)
    /* 2AED38 003AED38 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 2AED3C 003AED3C 5000B47B */  lq         $20, 0x50($29)
    /* 2AED40 003AED40 4000B37B */  lq         $19, 0x40($29)
    /* 2AED44 003AED44 3000B27B */  lq         $18, 0x30($29)
    /* 2AED48 003AED48 2000B17B */  lq         $17, 0x20($29)
    /* 2AED4C 003AED4C 1000B07B */  lq         $16, 0x10($29)
    /* 2AED50 003AED50 0800E003 */  jr         $31
    /* 2AED54 003AED54 2001BD27 */   addiu     $29, $29, 0x120
    /* 2AED58 003AED58 00000000 */  nop
    /* 2AED5C 003AED5C 00000000 */  nop
.size func_003adc40, 0x1120
