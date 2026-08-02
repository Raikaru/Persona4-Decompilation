.section .text
.set noat
.set noreorder
glabel func_004ac170
    /* 3AC170 004AC170 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3AC174 004AC174 2000BFFF */  sd         $31, 0x20($29)
    /* 3AC178 004AC178 1000B17F */  sq         $17, 0x10($29)
    /* 3AC17C 004AC17C 0000B07F */  sq         $16, 0x0($29)
    /* 3AC180 004AC180 2D808000 */  daddu      $16, $4, $0
    /* 3AC184 004AC184 2D88A000 */  daddu      $17, $5, $0
    /* 3AC188 004AC188 9400A28C */  lw         $2, 0x94($5)
    /* 3AC18C 004AC18C 06004014 */  bnez       $2, .L004AC1A8
    /* 3AC190 004AC190 00000000 */   nop
    /* 3AC194 004AC194 7100043C */  lui        $4, %hi(D_007144A8)
    /* 3AC198 004AC198 A8448424 */  addiu      $4, $4, %lo(D_007144A8)
    /* 3AC19C 004AC19C BB000524 */  addiu      $5, $0, 0xBB
    /* 3AC1A0 004AC1A0 CCB5110C */  jal        func_0046d730
    /* 3AC1A4 004AC1A4 00000000 */   nop
  .L004AC1A8:
    /* 3AC1A8 004AC1A8 9400048E */  lw         $4, 0x94($16)
    /* 3AC1AC 004AC1AC 03008010 */  beqz       $4, .L004AC1BC
    /* 3AC1B0 004AC1B0 00000000 */   nop
    /* 3AC1B4 004AC1B4 F8E1110C */  jal        func_004787e0
    /* 3AC1B8 004AC1B8 00000000 */   nop
  .L004AC1BC:
    /* 3AC1BC 004AC1BC 9400228E */  lw         $2, 0x94($17)
    /* 3AC1C0 004AC1C0 D4004494 */  lhu        $4, 0xD4($2)
    /* 3AC1C4 004AC1C4 D6004594 */  lhu        $5, 0xD6($2)
    /* 3AC1C8 004AC1C8 2D300000 */  daddu      $6, $0, $0
    /* 3AC1CC 004AC1CC 50E0110C */  jal        func_00478140
    /* 3AC1D0 004AC1D0 00000000 */   nop
    /* 3AC1D4 004AC1D4 2D884000 */  daddu      $17, $2, $0
    /* 3AC1D8 004AC1D8 06002016 */  bnez       $17, .L004AC1F4
    /* 3AC1DC 004AC1DC 00000000 */   nop
    /* 3AC1E0 004AC1E0 7100043C */  lui        $4, %hi(D_007144A8)
    /* 3AC1E4 004AC1E4 A8448424 */  addiu      $4, $4, %lo(D_007144A8)
    /* 3AC1E8 004AC1E8 C5000524 */  addiu      $5, $0, 0xC5
    /* 3AC1EC 004AC1EC CCB5110C */  jal        func_0046d730
    /* 3AC1F0 004AC1F0 00000000 */   nop
  .L004AC1F4:
    /* 3AC1F4 004AC1F4 2D202002 */  daddu      $4, $17, $0
    /* 3AC1F8 004AC1F8 A8E8110C */  jal        func_0047a2a0
    /* 3AC1FC 004AC1FC 00000000 */   nop
    /* 3AC200 004AC200 2D202002 */  daddu      $4, $17, $0
    /* 3AC204 004AC204 2D280000 */  daddu      $5, $0, $0
    /* 3AC208 004AC208 28E7110C */  jal        func_00479ca0
    /* 3AC20C 004AC20C 00000000 */   nop
    /* 3AC210 004AC210 0E004010 */  beqz       $2, .L004AC24C
    /* 3AC214 004AC214 00000000 */   nop
    /* 3AC218 004AC218 2D202002 */  daddu      $4, $17, $0
    /* 3AC21C 004AC21C 2D280000 */  daddu      $5, $0, $0
    /* 3AC220 004AC220 2D300000 */  daddu      $6, $0, $0
    /* 3AC224 004AC224 2D380000 */  daddu      $7, $0, $0
    /* 3AC228 004AC228 2D400000 */  daddu      $8, $0, $0
    /* 3AC22C 004AC22C 50E6110C */  jal        func_00479940
    /* 3AC230 004AC230 00000000 */   nop
    /* 3AC234 004AC234 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3AC238 004AC238 00608244 */  mtc1       $2, $f12
    /* 3AC23C 004AC23C 2D202002 */  daddu      $4, $17, $0
    /* 3AC240 004AC240 2D280000 */  daddu      $5, $0, $0
    /* 3AC244 004AC244 38E8110C */  jal        func_0047a0e0
    /* 3AC248 004AC248 00000000 */   nop
  .L004AC24C:
    /* 3AC24C 004AC24C D800238E */  lw         $3, 0xD8($17)
    /* 3AC250 004AC250 FDFF0224 */  addiu      $2, $0, -0x3
    /* 3AC254 004AC254 24106200 */  and        $2, $3, $2
    /* 3AC258 004AC258 D80022AE */  sw         $2, 0xD8($17)
    /* 3AC25C 004AC25C 2D202002 */  daddu      $4, $17, $0
    /* 3AC260 004AC260 4B00053C */  lui        $5, %hi(func_004abe60)
    /* 3AC264 004AC264 60BEA524 */  addiu      $5, $5, %lo(func_004abe60)
    /* 3AC268 004AC268 2D302002 */  daddu      $6, $17, $0
    /* 3AC26C 004AC26C ACE3110C */  jal        func_00478eb0
    /* 3AC270 004AC270 00000000 */   nop
    /* 3AC274 004AC274 940011AE */  sw         $17, 0x94($16)
    /* 3AC278 004AC278 2000BFDF */  ld         $31, 0x20($29)
    /* 3AC27C 004AC27C 1000B17B */  lq         $17, 0x10($29)
    /* 3AC280 004AC280 0000B07B */  lq         $16, 0x0($29)
    /* 3AC284 004AC284 3000BD27 */  addiu      $29, $29, 0x30
    /* 3AC288 004AC288 0800E003 */  jr         $31
    /* 3AC28C 004AC28C 00000000 */   nop
.size func_004ac170, 0x120
