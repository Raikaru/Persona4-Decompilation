.section .text
.set noat
.set noreorder
glabel func_003c3920
    /* 2C3920 003C3920 2D10A000 */  daddu      $2, $5, $0
    /* 2C3924 003C3924 2D18C000 */  daddu      $3, $6, $0
    /* 2C3928 003C3928 2D288000 */  daddu      $5, $4, $0
    /* 2C392C 003C392C 2D304000 */  daddu      $6, $2, $0
    /* 2C3930 003C3930 2D10E000 */  daddu      $2, $7, $0
    /* 2C3934 003C3934 2D480001 */  daddu      $9, $8, $0
    /* 2C3938 003C3938 7100043C */  lui        $4, %hi(D_0070AFD0)
    /* 2C393C 003C393C 2D386000 */  daddu      $7, $3, $0
    /* 2C3940 003C3940 2D404000 */  daddu      $8, $2, $0
    /* 2C3944 003C3944 1C8E0F08 */  j          func_003e3870
    /* 2C3948 003C3948 D0AF8424 */   addiu     $4, $4, %lo(D_0070AFD0)
    /* 2C394C 003C394C 00000000 */  nop
.size func_003c3920, 0x30
