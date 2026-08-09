.section .text
.set noat
.set noreorder
glabel func_003ca3d0
    /* 2CA3D0 003CA3D0 2D10A000 */  daddu      $2, $5, $0
    /* 2CA3D4 003CA3D4 2D18C000 */  daddu      $3, $6, $0
    /* 2CA3D8 003CA3D8 2D288000 */  daddu      $5, $4, $0
    /* 2CA3DC 003CA3DC 2D304000 */  daddu      $6, $2, $0
    /* 2CA3E0 003CA3E0 2D10E000 */  daddu      $2, $7, $0
    /* 2CA3E4 003CA3E4 2D480001 */  daddu      $9, $8, $0
    /* 2CA3E8 003CA3E8 7100043C */  lui        $4, %hi(D_0070B060)
    /* 2CA3EC 003CA3EC 2D386000 */  daddu      $7, $3, $0
    /* 2CA3F0 003CA3F0 2D404000 */  daddu      $8, $2, $0
    /* 2CA3F4 003CA3F4 1C8E0F08 */  j          func_003e3870
    /* 2CA3F8 003CA3F8 60B08424 */   addiu     $4, $4, %lo(D_0070B060)
    /* 2CA3FC 003CA3FC 00000000 */  nop
.size func_003ca3d0, 0x30
