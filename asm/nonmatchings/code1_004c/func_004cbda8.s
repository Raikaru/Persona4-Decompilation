.section .text
.set noat
.set noreorder
glabel func_004cbda8
    /* 3CBDA8 004CBDA8 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3CBDAC 004CBDAC 3000B0FF */  sd         $16, 0x30($29)
    /* 3CBDB0 004CBDB0 2D808000 */  daddu      $16, $4, $0
    /* 3CBDB4 004CBDB4 3800B1FF */  sd         $17, 0x38($29)
    /* 3CBDB8 004CBDB8 2D880000 */  daddu      $17, $0, $0
    /* 3CBDBC 004CBDBC 0C000012 */  beqz       $16, .L004CBDF0
    /* 3CBDC0 004CBDC0 4000BFFF */   sd        $31, 0x40($29)
    /* 3CBDC4 004CBDC4 B885100C */  jal        func_004216e0
    /* 3CBDC8 004CBDC8 2D28A003 */   daddu     $5, $29, $0
    /* 3CBDCC 004CBDCC 0000A38F */  lw         $3, 0x0($29)
    /* 3CBDD0 004CBDD0 08000224 */  addiu      $2, $0, 0x8
    /* 3CBDD4 004CBDD4 06006210 */  beq        $3, $2, .L004CBDF0
    /* 3CBDD8 004CBDD8 0C000424 */   addiu     $4, $0, 0xC
    /* 3CBDDC 004CBDDC 05006450 */  beql       $3, $4, .L004CBDF4
    /* 3CBDE0 004CBDE0 2D102002 */   daddu     $2, $17, $0
    /* 3CBDE4 004CBDE4 D485100C */  jal        func_00421750
    /* 3CBDE8 004CBDE8 2D200002 */   daddu     $4, $16, $0
    /* 3CBDEC 004CBDEC 2D884000 */  daddu      $17, $2, $0
  .L004CBDF0:
    /* 3CBDF0 004CBDF0 2D102002 */  daddu      $2, $17, $0
  .L004CBDF4:
    /* 3CBDF4 004CBDF4 3000B0DF */  ld         $16, 0x30($29)
    /* 3CBDF8 004CBDF8 3800B1DF */  ld         $17, 0x38($29)
    /* 3CBDFC 004CBDFC 4000BFDF */  ld         $31, 0x40($29)
    /* 3CBE00 004CBE00 0800E003 */  jr         $31
    /* 3CBE04 004CBE04 5000BD27 */   addiu     $29, $29, 0x50
.size func_004cbda8, 0x60
