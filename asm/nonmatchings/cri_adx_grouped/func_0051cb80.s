.section .text
.set noat
.set noreorder
glabel func_0051cb80
    /* 41CB80 0051CB80 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 41CB84 0051CB84 3000B0FF */  sd         $16, 0x30($29)
    /* 41CB88 0051CB88 3800B1FF */  sd         $17, 0x38($29)
    /* 41CB8C 0051CB8C 2D888000 */  daddu      $17, $4, $0
    /* 41CB90 0051CB90 4000BFFF */  sd         $31, 0x40($29)
    /* 41CB94 0051CB94 6C0D3026 */  addiu      $16, $17, 0xD6C
    /* 41CB98 0051CB98 0000028E */  lw         $2, 0x0($16)
    /* 41CB9C 0051CB9C 2B004014 */  bnez       $2, .L0051CC4C
    /* 41CBA0 0051CBA0 2D20A003 */   daddu     $4, $29, $0
    /* 41CBA4 0051CBA4 2000A527 */  addiu      $5, $29, 0x20
    /* 41CBA8 0051CBA8 2400A627 */  addiu      $6, $29, 0x24
    /* 41CBAC 0051CBAC 530D226A */  ldl        $2, 0xD53($17)
    /* 41CBB0 0051CBB0 4C0D226E */  ldr        $2, 0xD4C($17)
    /* 41CBB4 0051CBB4 5B0D236A */  ldl        $3, 0xD5B($17)
    /* 41CBB8 0051CBB8 540D236E */  ldr        $3, 0xD54($17)
    /* 41CBBC 0051CBBC 630D276A */  ldl        $7, 0xD63($17)
    /* 41CBC0 0051CBC0 5C0D276E */  ldr        $7, 0xD5C($17)
    /* 41CBC4 0051CBC4 6B0D286A */  ldl        $8, 0xD6B($17)
    /* 41CBC8 0051CBC8 640D286E */  ldr        $8, 0xD64($17)
    /* 41CBCC 0051CBCC 0700A2B3 */  sdl        $2, 0x7($29)
    /* 41CBD0 0051CBD0 0000A2B7 */  sdr        $2, 0x0($29)
    /* 41CBD4 0051CBD4 0F00A3B3 */  sdl        $3, 0xF($29)
    /* 41CBD8 0051CBD8 0800A3B7 */  sdr        $3, 0x8($29)
    /* 41CBDC 0051CBDC 1700A7B3 */  sdl        $7, 0x17($29)
    /* 41CBE0 0051CBE0 1000A7B7 */  sdr        $7, 0x10($29)
    /* 41CBE4 0051CBE4 1F00A8B3 */  sdl        $8, 0x1F($29)
    /* 41CBE8 0051CBE8 1800A8B7 */  sdr        $8, 0x18($29)
    /* 41CBEC 0051CBEC 4099140C */  jal        func_00526500
    /* 41CBF0 0051CBF0 1800A0AF */   sw        $0, 0x18($29)
    /* 41CBF4 0051CBF4 2000A28F */  lw         $2, 0x20($29)
    /* 41CBF8 0051CBF8 01000324 */  addiu      $3, $0, 0x1
    /* 41CBFC 0051CBFC 2400A48F */  lw         $4, 0x24($29)
    /* 41CC00 0051CC00 0700A56B */  ldl        $5, 0x7($29)
    /* 41CC04 0051CC04 0000A56F */  ldr        $5, 0x0($29)
    /* 41CC08 0051CC08 0F00A66B */  ldl        $6, 0xF($29)
    /* 41CC0C 0051CC0C 0800A66F */  ldr        $6, 0x8($29)
    /* 41CC10 0051CC10 1700A76B */  ldl        $7, 0x17($29)
    /* 41CC14 0051CC14 1000A76F */  ldr        $7, 0x10($29)
    /* 41CC18 0051CC18 1F00A86B */  ldl        $8, 0x1F($29)
    /* 41CC1C 0051CC1C 1800A86F */  ldr        $8, 0x18($29)
    /* 41CC20 0051CC20 770D25B2 */  sdl        $5, 0xD77($17)
    /* 41CC24 0051CC24 700D25B6 */  sdr        $5, 0xD70($17)
    /* 41CC28 0051CC28 7F0D26B2 */  sdl        $6, 0xD7F($17)
    /* 41CC2C 0051CC2C 780D26B6 */  sdr        $6, 0xD78($17)
    /* 41CC30 0051CC30 870D27B2 */  sdl        $7, 0xD87($17)
    /* 41CC34 0051CC34 800D27B6 */  sdr        $7, 0xD80($17)
    /* 41CC38 0051CC38 8F0D28B2 */  sdl        $8, 0xD8F($17)
    /* 41CC3C 0051CC3C 880D28B6 */  sdr        $8, 0xD88($17)
    /* 41CC40 0051CC40 000003AE */  sw         $3, 0x0($16)
    /* 41CC44 0051CC44 240002AE */  sw         $2, 0x24($16)
    /* 41CC48 0051CC48 280004AE */  sw         $4, 0x28($16)
  .L0051CC4C:
    /* 41CC4C 0051CC4C 3000B0DF */  ld         $16, 0x30($29)
    /* 41CC50 0051CC50 3800B1DF */  ld         $17, 0x38($29)
    /* 41CC54 0051CC54 4000BFDF */  ld         $31, 0x40($29)
    /* 41CC58 0051CC58 0800E003 */  jr         $31
    /* 41CC5C 0051CC5C 5000BD27 */   addiu     $29, $29, 0x50
.size func_0051cb80, 0xe0
