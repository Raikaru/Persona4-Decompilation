.section .text
.set noat
.set noreorder
glabel func_001db160
    /* DB160 001DB160 70FFBD27 */  addiu      $29, $29, -0x90
    /* DB164 001DB164 8000BFFF */  sd         $31, 0x80($29)
    /* DB168 001DB168 7000B77F */  sq         $23, 0x70($29)
    /* DB16C 001DB16C 6000B67F */  sq         $22, 0x60($29)
    /* DB170 001DB170 5000B57F */  sq         $21, 0x50($29)
    /* DB174 001DB174 4000B47F */  sq         $20, 0x40($29)
    /* DB178 001DB178 3000B37F */  sq         $19, 0x30($29)
    /* DB17C 001DB17C 2000B27F */  sq         $18, 0x20($29)
    /* DB180 001DB180 1000B17F */  sq         $17, 0x10($29)
    /* DB184 001DB184 0000B07F */  sq         $16, 0x0($29)
    /* DB188 001DB188 2DA88000 */  daddu      $21, $4, $0
    /* DB18C 001DB18C 2DA0A000 */  daddu      $20, $5, $0
    /* DB190 001DB190 3000918C */  lw         $17, 0x30($4)
    /* DB194 001DB194 640A248E */  lw         $4, 0xA64($17)
    /* DB198 001DB198 2D280000 */  daddu      $5, $0, $0
    /* DB19C 001DB19C 38F6080C */  jal        func_0023d8e0
    /* DB1A0 001DB1A0 00000000 */   nop
    /* DB1A4 001DB1A4 3C140200 */  dsll32     $2, $2, 16
    /* DB1A8 001DB1A8 3F140200 */  dsra32     $2, $2, 16
    /* DB1AC 001DB1AC 04005414 */  bne        $2, $20, .L001DB1C0
    /* DB1B0 001DB1B0 00000000 */   nop
    /* DB1B4 001DB1B4 01000224 */  addiu      $2, $0, 0x1
    /* DB1B8 001DB1B8 5C000010 */  b          .L001DB32C
    /* DB1BC 001DB1BC 00000000 */   nop
  .L001DB1C0:
    /* DB1C0 001DB1C0 640A248E */  lw         $4, 0xA64($17)
    /* DB1C4 001DB1C4 4CF8080C */  jal        func_0023e130
    /* DB1C8 001DB1C8 00000000 */   nop
    /* DB1CC 001DB1CC FFFF5030 */  andi       $16, $2, 0xFFFF
    /* DB1D0 001DB1D0 640A248E */  lw         $4, 0xA64($17)
    /* DB1D4 001DB1D4 50F8080C */  jal        func_0023e140
    /* DB1D8 001DB1D8 00000000 */   nop
    /* DB1DC 001DB1DC 2DB04000 */  daddu      $22, $2, $0
    /* DB1E0 001DB1E0 2D980000 */  daddu      $19, $0, $0
    /* DB1E4 001DB1E4 FFFF1732 */  andi       $23, $16, 0xFFFF
    /* DB1E8 001DB1E8 4B000010 */  b          .L001DB318
    /* DB1EC 001DB1EC 00000000 */   nop
  .L001DB1F0:
    /* DB1F0 001DB1F0 FFFF6232 */  andi       $2, $19, 0xFFFF
    /* DB1F4 001DB1F4 40100200 */  sll        $2, $2, 1
    /* DB1F8 001DB1F8 2180C202 */  addu       $16, $22, $2
    /* DB1FC 001DB1FC 00000596 */  lhu        $5, 0x0($16)
    /* DB200 001DB200 4300A010 */  beqz       $5, .L001DB310
    /* DB204 001DB204 00000000 */   nop
    /* DB208 001DB208 B801A128 */  slti       $1, $5, 0x1B8
    /* DB20C 001DB20C 40002010 */  beqz       $1, .L001DB310
    /* DB210 001DB210 00000000 */   nop
    /* DB214 001DB214 640A248E */  lw         $4, 0xA64($17)
    /* DB218 001DB218 38F6080C */  jal        func_0023d8e0
    /* DB21C 001DB21C 00000000 */   nop
    /* DB220 001DB220 3C140200 */  dsll32     $2, $2, 16
    /* DB224 001DB224 3F140200 */  dsra32     $2, $2, 16
    /* DB228 001DB228 39005414 */  bne        $2, $20, .L001DB310
    /* DB22C 001DB22C 00000000 */   nop
    /* DB230 001DB230 00001296 */  lhu        $18, 0x0($16)
    /* DB234 001DB234 4002422A */  slti       $2, $18, 0x240
    /* DB238 001DB238 06004014 */  bnez       $2, .L001DB254
    /* DB23C 001DB23C 00000000 */   nop
    /* DB240 001DB240 6100043C */  lui        $4, %hi(D_006095E0)
    /* DB244 001DB244 E0958424 */  addiu      $4, $4, %lo(D_006095E0)
    /* DB248 001DB248 5F040524 */  addiu      $5, $0, 0x45F
    /* DB24C 001DB24C CCB5110C */  jal        func_0046d730
    /* DB250 001DB250 00000000 */   nop
  .L001DB254:
    /* DB254 001DB254 3000B08E */  lw         $16, 0x30($21)
    /* DB258 001DB258 B801412A */  slti       $1, $18, 0x1B8
    /* DB25C 001DB25C 1D002010 */  beqz       $1, .L001DB2D4
    /* DB260 001DB260 00000000 */   nop
    /* DB264 001DB264 640A048E */  lw         $4, 0xA64($16)
    /* DB268 001DB268 0800023C */  lui        $2, (0x80008 >> 16)
    /* DB26C 001DB26C 08004534 */  ori        $5, $2, (0x80008 & 0xFFFF)
    /* DB270 001DB270 C4C9080C */  jal        func_00232710
    /* DB274 001DB274 00000000 */   nop
    /* DB278 001DB278 04004010 */  beqz       $2, .L001DB28C
    /* DB27C 001DB27C 00000000 */   nop
    /* DB280 001DB280 2D100000 */  daddu      $2, $0, $0
    /* DB284 001DB284 1D000010 */  b          .L001DB2FC
    /* DB288 001DB288 00000000 */   nop
  .L001DB28C:
    /* DB28C 001DB28C 640A048E */  lw         $4, 0xA64($16)
    /* DB290 001DB290 2D284002 */  daddu      $5, $18, $0
    /* DB294 001DB294 CCC9080C */  jal        func_00232730
    /* DB298 001DB298 00000000 */   nop
    /* DB29C 001DB29C 04004014 */  bnez       $2, .L001DB2B0
    /* DB2A0 001DB2A0 00000000 */   nop
    /* DB2A4 001DB2A4 2D100000 */  daddu      $2, $0, $0
    /* DB2A8 001DB2A8 14000010 */  b          .L001DB2FC
    /* DB2AC 001DB2AC 00000000 */   nop
  .L001DB2B0:
    /* DB2B0 001DB2B0 640A048E */  lw         $4, 0xA64($16)
    /* DB2B4 001DB2B4 2D284002 */  daddu      $5, $18, $0
    /* DB2B8 001DB2B8 70F7080C */  jal        func_0023ddc0
    /* DB2BC 001DB2BC 00000000 */   nop
    /* DB2C0 001DB2C0 0D004010 */  beqz       $2, .L001DB2F8
    /* DB2C4 001DB2C4 00000000 */   nop
    /* DB2C8 001DB2C8 2D100000 */  daddu      $2, $0, $0
    /* DB2CC 001DB2CC 0B000010 */  b          .L001DB2FC
    /* DB2D0 001DB2D0 00000000 */   nop
  .L001DB2D4:
    /* DB2D4 001DB2D4 640A048E */  lw         $4, 0xA64($16)
    /* DB2D8 001DB2D8 2D284002 */  daddu      $5, $18, $0
    /* DB2DC 001DB2DC CCC9080C */  jal        func_00232730
    /* DB2E0 001DB2E0 00000000 */   nop
    /* DB2E4 001DB2E4 04004014 */  bnez       $2, .L001DB2F8
    /* DB2E8 001DB2E8 00000000 */   nop
    /* DB2EC 001DB2EC 2D100000 */  daddu      $2, $0, $0
    /* DB2F0 001DB2F0 02000010 */  b          .L001DB2FC
    /* DB2F4 001DB2F4 00000000 */   nop
  .L001DB2F8:
    /* DB2F8 001DB2F8 01000224 */  addiu      $2, $0, 0x1
  .L001DB2FC:
    /* DB2FC 001DB2FC 04004010 */  beqz       $2, .L001DB310
    /* DB300 001DB300 00000000 */   nop
    /* DB304 001DB304 01000224 */  addiu      $2, $0, 0x1
    /* DB308 001DB308 08000010 */  b          .L001DB32C
    /* DB30C 001DB30C 00000000 */   nop
  .L001DB310:
    /* DB310 001DB310 01006226 */  addiu      $2, $19, 0x1
    /* DB314 001DB314 FFFF5330 */  andi       $19, $2, 0xFFFF
  .L001DB318:
    /* DB318 001DB318 FFFF6232 */  andi       $2, $19, 0xFFFF
    /* DB31C 001DB31C 2A105700 */  slt        $2, $2, $23
    /* DB320 001DB320 B3FF4014 */  bnez       $2, .L001DB1F0
    /* DB324 001DB324 00000000 */   nop
    /* DB328 001DB328 2D100000 */  daddu      $2, $0, $0
  .L001DB32C:
    /* DB32C 001DB32C 8000BFDF */  ld         $31, 0x80($29)
    /* DB330 001DB330 7000B77B */  lq         $23, 0x70($29)
    /* DB334 001DB334 6000B67B */  lq         $22, 0x60($29)
    /* DB338 001DB338 5000B57B */  lq         $21, 0x50($29)
    /* DB33C 001DB33C 4000B47B */  lq         $20, 0x40($29)
    /* DB340 001DB340 3000B37B */  lq         $19, 0x30($29)
    /* DB344 001DB344 2000B27B */  lq         $18, 0x20($29)
    /* DB348 001DB348 1000B17B */  lq         $17, 0x10($29)
    /* DB34C 001DB34C 0000B07B */  lq         $16, 0x0($29)
    /* DB350 001DB350 9000BD27 */  addiu      $29, $29, 0x90
    /* DB354 001DB354 0800E003 */  jr         $31
    /* DB358 001DB358 00000000 */   nop
    /* DB35C 001DB35C 00000000 */  nop
.size func_001db160, 0x200
