.section .text
.set noat
.set noreorder
glabel func_0019beb0
    /* 9BEB0 0019BEB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 9BEB4 0019BEB4 1000BFFF */  sd         $31, 0x10($29)
    /* 9BEB8 0019BEB8 0000B07F */  sq         $16, 0x0($29)
    /* 9BEBC 0019BEBC 2D808000 */  daddu      $16, $4, $0
    /* 9BEC0 0019BEC0 1B010424 */  addiu      $4, $0, 0x11B
    /* 9BEC4 0019BEC4 04000524 */  addiu      $5, $0, 0x4
    /* 9BEC8 0019BEC8 1C51060C */  jal        func_00194470
    /* 9BECC 0019BECC 00000000 */   nop
    /* 9BED0 0019BED0 1A00033C */  lui        $3, %hi(func_0019be30)
    /* 9BED4 0019BED4 30BE6324 */  addiu      $3, $3, %lo(func_0019be30)
    /* 9BED8 0019BED8 680043AC */  sw         $3, 0x68($2)
    /* 9BEDC 0019BEDC 1A00033C */  lui        $3, %hi(func_0019be50)
    /* 9BEE0 0019BEE0 50BE6324 */  addiu      $3, $3, %lo(func_0019be50)
    /* 9BEE4 0019BEE4 6C0043AC */  sw         $3, 0x6C($2)
    /* 9BEE8 0019BEE8 1A00033C */  lui        $3, %hi(func_0019be90)
    /* 9BEEC 0019BEEC 90BE6324 */  addiu      $3, $3, %lo(func_0019be90)
    /* 9BEF0 0019BEF0 700043AC */  sw         $3, 0x70($2)
    /* 9BEF4 0019BEF4 7800438C */  lw         $3, 0x78($2)
    /* 9BEF8 0019BEF8 000070AC */  sw         $16, 0x0($3)
    /* 9BEFC 0019BEFC 1000BFDF */  ld         $31, 0x10($29)
    /* 9BF00 0019BF00 0000B07B */  lq         $16, 0x0($29)
    /* 9BF04 0019BF04 2000BD27 */  addiu      $29, $29, 0x20
    /* 9BF08 0019BF08 0800E003 */  jr         $31
    /* 9BF0C 0019BF0C 00000000 */   nop
.size func_0019beb0, 0x60
