.section .text
.set noat
.set noreorder
glabel func_001dd1c0
    /* DD1C0 001DD1C0 50FFBD27 */  addiu      $29, $29, -0xB0
    /* DD1C4 001DD1C4 9000BFFF */  sd         $31, 0x90($29)
    /* DD1C8 001DD1C8 8000BE7F */  sq         $30, 0x80($29)
    /* DD1CC 001DD1CC 7000B77F */  sq         $23, 0x70($29)
    /* DD1D0 001DD1D0 6000B67F */  sq         $22, 0x60($29)
    /* DD1D4 001DD1D4 5000B57F */  sq         $21, 0x50($29)
    /* DD1D8 001DD1D8 4000B47F */  sq         $20, 0x40($29)
    /* DD1DC 001DD1DC 3000B37F */  sq         $19, 0x30($29)
    /* DD1E0 001DD1E0 2000B27F */  sq         $18, 0x20($29)
    /* DD1E4 001DD1E4 1000B17F */  sq         $17, 0x10($29)
    /* DD1E8 001DD1E8 0000B07F */  sq         $16, 0x0($29)
    /* DD1EC 001DD1EC 2DA08000 */  daddu      $20, $4, $0
    /* DD1F0 001DD1F0 2DA8A000 */  daddu      $21, $5, $0
    /* DD1F4 001DD1F4 2DF0C000 */  daddu      $30, $6, $0
    /* DD1F8 001DD1F8 2DB8E000 */  daddu      $23, $7, $0
    /* DD1FC 001DD1FC 2D800001 */  daddu      $16, $8, $0
    /* DD200 001DD200 3000A28C */  lw         $2, 0x30($5)
    /* DD204 001DD204 640A448C */  lw         $4, 0xA64($2)
    /* DD208 001DD208 B4C7080C */  jal        func_00231ed0
    /* DD20C 001DD20C 00000000 */   nop
    /* DD210 001DD210 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* DD214 001DD214 A000A27F */  sq         $2, 0xA0($29)
    /* DD218 001DD218 FFFF1224 */  addiu      $18, $0, -0x1
    /* DD21C 001DD21C FF00023C */  lui        $2, (0xFFFFFF >> 16)
    /* DD220 001DD220 FFFF5334 */  ori        $19, $2, (0xFFFFFF & 0xFFFF)
    /* DD224 001DD224 2D880000 */  daddu      $17, $0, $0
    /* DD228 001DD228 FFFF1632 */  andi       $22, $16, 0xFFFF
    /* DD22C 001DD22C FFFFF732 */  andi       $23, $23, 0xFFFF
    /* DD230 001DD230 40000010 */  b          .L001DD334
    /* DD234 001DD234 00000000 */   nop
  .L001DD238:
    /* DD238 001DD238 FFFF2232 */  andi       $2, $17, 0xFFFF
    /* DD23C 001DD23C 40100200 */  sll        $2, $2, 1
    /* DD240 001DD240 2180C203 */  addu       $16, $30, $2
    /* DD244 001DD244 00000496 */  lhu        $4, 0x0($16)
    /* DD248 001DD248 04008014 */  bnez       $4, .L001DD25C
    /* DD24C 001DD24C 00000000 */   nop
    /* DD250 001DD250 2D100000 */  daddu      $2, $0, $0
    /* DD254 001DD254 07000010 */  b          .L001DD274
    /* DD258 001DD258 00000000 */   nop
  .L001DD25C:
    /* DD25C 001DD25C 80100400 */  sll        $2, $4, 2
    /* DD260 001DD260 21104400 */  addu       $2, $2, $4
    /* DD264 001DD264 C0180200 */  sll        $3, $2, 3
    /* DD268 001DD268 B8B3828F */  lw         $2, -0x4C48($28)
    /* DD26C 001DD26C 21104300 */  addu       $2, $2, $3
    /* DD270 001DD270 08004290 */  lbu        $2, 0x8($2)
  .L001DD274:
    /* DD274 001DD274 FF004530 */  andi       $5, $2, 0xFF
    /* DD278 001DD278 0500C016 */  bnez       $22, .L001DD290
    /* DD27C 001DD27C 00000000 */   nop
    /* DD280 001DD280 FF00A330 */  andi       $3, $5, 0xFF
    /* DD284 001DD284 01000224 */  addiu      $2, $0, 0x1
    /* DD288 001DD288 28006214 */  bne        $3, $2, .L001DD32C
    /* DD28C 001DD28C 00000000 */   nop
  .L001DD290:
    /* DD290 001DD290 01000224 */  addiu      $2, $0, 0x1
    /* DD294 001DD294 0400C216 */  bne        $22, $2, .L001DD2A8
    /* DD298 001DD298 00000000 */   nop
    /* DD29C 001DD29C FF00A230 */  andi       $2, $5, 0xFF
    /* DD2A0 001DD2A0 22004014 */  bnez       $2, .L001DD32C
    /* DD2A4 001DD2A4 00000000 */   nop
  .L001DD2A8:
    /* DD2A8 001DD2A8 3000838E */  lw         $3, 0x30($20)
    /* DD2AC 001DD2AC 3000A28E */  lw         $2, 0x30($21)
    /* DD2B0 001DD2B0 640A658C */  lw         $5, 0xA64($3)
    /* DD2B4 001DD2B4 640A468C */  lw         $6, 0xA64($2)
    /* DD2B8 001DD2B8 01000724 */  addiu      $7, $0, 0x1
    /* DD2BC 001DD2BC 2D40E000 */  daddu      $8, $7, $0
    /* DD2C0 001DD2C0 2D48E000 */  daddu      $9, $7, $0
    /* DD2C4 001DD2C4 2D500000 */  daddu      $10, $0, $0
    /* DD2C8 001DD2C8 2D58E000 */  daddu      $11, $7, $0
    /* DD2CC 001DD2CC 48D5080C */  jal        func_00235520
    /* DD2D0 001DD2D0 00000000 */   nop
    /* DD2D4 001DD2D4 A000A37B */  lq         $3, 0xA0($29)
    /* DD2D8 001DD2D8 21106200 */  addu       $2, $3, $2
    /* DD2DC 001DD2DC 0A004018 */  blez       $2, .L001DD308
    /* DD2E0 001DD2E0 00000000 */   nop
    /* DD2E4 001DD2E4 0800601A */  blez       $19, .L001DD308
    /* DD2E8 001DD2E8 00000000 */   nop
    /* DD2EC 001DD2EC 2A085300 */  slt        $1, $2, $19
    /* DD2F0 001DD2F0 0E002010 */  beqz       $1, .L001DD32C
    /* DD2F4 001DD2F4 00000000 */   nop
    /* DD2F8 001DD2F8 00001296 */  lhu        $18, 0x0($16)
    /* DD2FC 001DD2FC 2D984000 */  daddu      $19, $2, $0
    /* DD300 001DD300 0A000010 */  b          .L001DD32C
    /* DD304 001DD304 00000000 */   nop
  .L001DD308:
    /* DD308 001DD308 0800401C */  bgtz       $2, .L001DD32C
    /* DD30C 001DD30C 00000000 */   nop
    /* DD310 001DD310 0400601E */  bgtz       $19, .L001DD324
    /* DD314 001DD314 00000000 */   nop
    /* DD318 001DD318 2A086202 */  slt        $1, $19, $2
    /* DD31C 001DD31C 03002010 */  beqz       $1, .L001DD32C
    /* DD320 001DD320 00000000 */   nop
  .L001DD324:
    /* DD324 001DD324 00001296 */  lhu        $18, 0x0($16)
    /* DD328 001DD328 2D984000 */  daddu      $19, $2, $0
  .L001DD32C:
    /* DD32C 001DD32C 01002226 */  addiu      $2, $17, 0x1
    /* DD330 001DD330 FFFF5130 */  andi       $17, $2, 0xFFFF
  .L001DD334:
    /* DD334 001DD334 FFFF2232 */  andi       $2, $17, 0xFFFF
    /* DD338 001DD338 2A105700 */  slt        $2, $2, $23
    /* DD33C 001DD33C BEFF4014 */  bnez       $2, .L001DD238
    /* DD340 001DD340 00000000 */   nop
    /* DD344 001DD344 3000828E */  lw         $2, 0x30($20)
    /* DD348 001DD348 640A448C */  lw         $4, 0xA64($2)
    /* DD34C 001DD34C ECCE080C */  jal        func_00233bb0
    /* DD350 001DD350 00000000 */   nop
    /* DD354 001DD354 3000A28E */  lw         $2, 0x30($21)
    /* DD358 001DD358 640A448C */  lw         $4, 0xA64($2)
    /* DD35C 001DD35C ECCE080C */  jal        func_00233bb0
    /* DD360 001DD360 00000000 */   nop
    /* DD364 001DD364 2D104002 */  daddu      $2, $18, $0
    /* DD368 001DD368 9000BFDF */  ld         $31, 0x90($29)
    /* DD36C 001DD36C 8000BE7B */  lq         $30, 0x80($29)
    /* DD370 001DD370 7000B77B */  lq         $23, 0x70($29)
    /* DD374 001DD374 6000B67B */  lq         $22, 0x60($29)
    /* DD378 001DD378 5000B57B */  lq         $21, 0x50($29)
    /* DD37C 001DD37C 4000B47B */  lq         $20, 0x40($29)
    /* DD380 001DD380 3000B37B */  lq         $19, 0x30($29)
    /* DD384 001DD384 2000B27B */  lq         $18, 0x20($29)
    /* DD388 001DD388 1000B17B */  lq         $17, 0x10($29)
    /* DD38C 001DD38C 0000B07B */  lq         $16, 0x0($29)
    /* DD390 001DD390 B000BD27 */  addiu      $29, $29, 0xB0
    /* DD394 001DD394 0800E003 */  jr         $31
    /* DD398 001DD398 00000000 */   nop
    /* DD39C 001DD39C 00000000 */  nop
.size func_001dd1c0, 0x1e0
