.section .text
.set noat
.set noreorder
glabel func_0026dd60
    /* 16DD60 0026DD60 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 16DD64 0026DD64 3000BFFF */  sd         $31, 0x30($29)
    /* 16DD68 0026DD68 2000B27F */  sq         $18, 0x20($29)
    /* 16DD6C 0026DD6C 1000B17F */  sq         $17, 0x10($29)
    /* 16DD70 0026DD70 0000B07F */  sq         $16, 0x0($29)
    /* 16DD74 0026DD74 2D880000 */  daddu      $17, $0, $0
    /* 16DD78 0026DD78 2D808000 */  daddu      $16, $4, $0
    /* 16DD7C 0026DD7C 0F000010 */  b          .L0026DDBC
    /* 16DD80 0026DD80 00000000 */   nop
  .L0026DD84:
    /* 16DD84 0026DD84 2800838C */  lw         $3, 0x28($4)
    /* 16DD88 0026DD88 02006330 */  andi       $3, $3, 0x2
    /* 16DD8C 0026DD8C 0A006010 */  beqz       $3, .L0026DDB8
    /* 16DD90 0026DD90 00000000 */   nop
    /* 16DD94 0026DD94 4401838C */  lw         $3, 0x144($4)
    /* 16DD98 0026DD98 07006010 */  beqz       $3, .L0026DDB8
    /* 16DD9C 0026DD9C 00000000 */   nop
    /* 16DDA0 0026DDA0 40018380 */  lb         $3, 0x140($4)
    /* 16DDA4 0026DDA4 03006010 */  beqz       $3, .L0026DDB4
    /* 16DDA8 0026DDA8 00000000 */   nop
    /* 16DDAC 0026DDAC 02000010 */  b          .L0026DDB8
    /* 16DDB0 0026DDB0 00000000 */   nop
  .L0026DDB4:
    /* 16DDB4 0026DDB4 01003126 */  addiu      $17, $17, 0x1
  .L0026DDB8:
    /* 16DDB8 0026DDB8 3801848C */  lw         $4, 0x138($4)
  .L0026DDBC:
    /* 16DDBC 0026DDBC F1FF8014 */  bnez       $4, .L0026DD84
    /* 16DDC0 0026DDC0 00000000 */   nop
    /* 16DDC4 0026DDC4 3F002012 */  beqz       $17, .L0026DEC4
    /* 16DDC8 0026DDC8 00000000 */   nop
    /* 16DDCC 0026DDCC 6400043C */  lui        $4, %hi(D_0063B580)
    /* 16DDD0 0026DDD0 80B58424 */  addiu      $4, $4, %lo(D_0063B580)
    /* 16DDD4 0026DDD4 96000524 */  addiu      $5, $0, 0x96
    /* 16DDD8 0026DDD8 A43A110C */  jal        func_0044ea90
    /* 16DDDC 0026DDDC 00000000 */   nop
    /* 16DDE0 0026DDE0 80201100 */  sll        $4, $17, 2
    /* 16DDE4 0026DDE4 0400053C */  lui        $5, (0x40000 >> 16)
    /* 16DDE8 0026DDE8 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 16DDEC 0026DDEC E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 16DDF0 0026DDF0 09F84000 */  jalr       $2
    /* 16DDF4 0026DDF4 00000000 */   nop
    /* 16DDF8 0026DDF8 2D904000 */  daddu      $18, $2, $0
    /* 16DDFC 0026DDFC 2D180000 */  daddu      $3, $0, $0
    /* 16DE00 0026DE00 2D200002 */  daddu      $4, $16, $0
    /* 16DE04 0026DE04 12000010 */  b          .L0026DE50
    /* 16DE08 0026DE08 00000000 */   nop
  .L0026DE0C:
    /* 16DE0C 0026DE0C 2800828C */  lw         $2, 0x28($4)
    /* 16DE10 0026DE10 02004230 */  andi       $2, $2, 0x2
    /* 16DE14 0026DE14 0D004010 */  beqz       $2, .L0026DE4C
    /* 16DE18 0026DE18 00000000 */   nop
    /* 16DE1C 0026DE1C 4401828C */  lw         $2, 0x144($4)
    /* 16DE20 0026DE20 0A004010 */  beqz       $2, .L0026DE4C
    /* 16DE24 0026DE24 00000000 */   nop
    /* 16DE28 0026DE28 40018280 */  lb         $2, 0x140($4)
    /* 16DE2C 0026DE2C 03004010 */  beqz       $2, .L0026DE3C
    /* 16DE30 0026DE30 00000000 */   nop
    /* 16DE34 0026DE34 05000010 */  b          .L0026DE4C
    /* 16DE38 0026DE38 00000000 */   nop
  .L0026DE3C:
    /* 16DE3C 0026DE3C 80100300 */  sll        $2, $3, 2
    /* 16DE40 0026DE40 21104202 */  addu       $2, $18, $2
    /* 16DE44 0026DE44 000044AC */  sw         $4, 0x0($2)
    /* 16DE48 0026DE48 01006324 */  addiu      $3, $3, 0x1
  .L0026DE4C:
    /* 16DE4C 0026DE4C 3801848C */  lw         $4, 0x138($4)
  .L0026DE50:
    /* 16DE50 0026DE50 EEFF8014 */  bnez       $4, .L0026DE0C
    /* 16DE54 0026DE54 00000000 */   nop
    /* 16DE58 0026DE58 2D204002 */  daddu      $4, $18, $0
    /* 16DE5C 0026DE5C 2D282002 */  daddu      $5, $17, $0
    /* 16DE60 0026DE60 04000624 */  addiu      $6, $0, 0x4
    /* 16DE64 0026DE64 2700073C */  lui        $7, %hi(func_0026dc50)
    /* 16DE68 0026DE68 50DCE724 */  addiu      $7, $7, %lo(func_0026dc50)
    /* 16DE6C 0026DE6C EE02110C */  jal        func_00440bb8
    /* 16DE70 0026DE70 00000000 */   nop
    /* 16DE74 0026DE74 2D800000 */  daddu      $16, $0, $0
    /* 16DE78 0026DE78 0A000010 */  b          .L0026DEA4
    /* 16DE7C 0026DE7C 00000000 */   nop
  .L0026DE80:
    /* 16DE80 0026DE80 80101000 */  sll        $2, $16, 2
    /* 16DE84 0026DE84 21104202 */  addu       $2, $18, $2
    /* 16DE88 0026DE88 0000428C */  lw         $2, 0x0($2)
    /* 16DE8C 0026DE8C 5E00043C */  lui        $4, %hi(D_005DC7D0)
    /* 16DE90 0026DE90 D0C78424 */  addiu      $4, $4, %lo(D_005DC7D0)
    /* 16DE94 0026DE94 4401458C */  lw         $5, 0x144($2)
    /* 16DE98 0026DE98 74C4120C */  jal        func_004b11d0
    /* 16DE9C 0026DE9C 00000000 */   nop
    /* 16DEA0 0026DEA0 01001026 */  addiu      $16, $16, 0x1
  .L0026DEA4:
    /* 16DEA4 0026DEA4 2A101102 */  slt        $2, $16, $17
    /* 16DEA8 0026DEA8 F5FF4014 */  bnez       $2, .L0026DE80
    /* 16DEAC 0026DEAC 00000000 */   nop
    /* 16DEB0 0026DEB0 2D204002 */  daddu      $4, $18, $0
    /* 16DEB4 0026DEB4 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 16DEB8 0026DEB8 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 16DEBC 0026DEBC 09F84000 */  jalr       $2
    /* 16DEC0 0026DEC0 00000000 */   nop
  .L0026DEC4:
    /* 16DEC4 0026DEC4 3000BFDF */  ld         $31, 0x30($29)
    /* 16DEC8 0026DEC8 2000B27B */  lq         $18, 0x20($29)
    /* 16DECC 0026DECC 1000B17B */  lq         $17, 0x10($29)
    /* 16DED0 0026DED0 0000B07B */  lq         $16, 0x0($29)
    /* 16DED4 0026DED4 4000BD27 */  addiu      $29, $29, 0x40
    /* 16DED8 0026DED8 0800E003 */  jr         $31
    /* 16DEDC 0026DEDC 00000000 */   nop
.size func_0026dd60, 0x180
