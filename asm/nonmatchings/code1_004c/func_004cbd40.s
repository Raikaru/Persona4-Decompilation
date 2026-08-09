.section .text
.set noat
.set noreorder
glabel func_004cbd40
    /* 3CBD40 004CBD40 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3CBD44 004CBD44 3000B0FF */  sd         $16, 0x30($29)
    /* 3CBD48 004CBD48 2D808000 */  daddu      $16, $4, $0
    /* 3CBD4C 004CBD4C 3800B1FF */  sd         $17, 0x38($29)
    /* 3CBD50 004CBD50 2D880000 */  daddu      $17, $0, $0
    /* 3CBD54 004CBD54 0D000012 */  beqz       $16, .L004CBD8C
    /* 3CBD58 004CBD58 4000BFFF */   sd        $31, 0x40($29)
    /* 3CBD5C 004CBD5C B885100C */  jal        func_004216e0
    /* 3CBD60 004CBD60 2D28A003 */   daddu     $5, $29, $0
    /* 3CBD64 004CBD64 2D200002 */  daddu      $4, $16, $0
    /* 3CBD68 004CBD68 0000A38F */  lw         $3, 0x0($29)
    /* 3CBD6C 004CBD6C 08000224 */  addiu      $2, $0, 0x8
    /* 3CBD70 004CBD70 03006210 */  beq        $3, $2, .L004CBD80
    /* 3CBD74 004CBD74 0C000524 */   addiu     $5, $0, 0xC
    /* 3CBD78 004CBD78 05006514 */  bne        $3, $5, .L004CBD90
    /* 3CBD7C 004CBD7C 2D102002 */   daddu     $2, $17, $0
  .L004CBD80:
    /* 3CBD80 004CBD80 DC85100C */  jal        func_00421770
    /* 3CBD84 004CBD84 00000000 */   nop
    /* 3CBD88 004CBD88 2D884000 */  daddu      $17, $2, $0
  .L004CBD8C:
    /* 3CBD8C 004CBD8C 2D102002 */  daddu      $2, $17, $0
  .L004CBD90:
    /* 3CBD90 004CBD90 3000B0DF */  ld         $16, 0x30($29)
    /* 3CBD94 004CBD94 3800B1DF */  ld         $17, 0x38($29)
    /* 3CBD98 004CBD98 4000BFDF */  ld         $31, 0x40($29)
    /* 3CBD9C 004CBD9C 0800E003 */  jr         $31
    /* 3CBDA0 004CBDA0 5000BD27 */   addiu     $29, $29, 0x50
    /* 3CBDA4 004CBDA4 00000000 */  nop
.size func_004cbd40, 0x68
