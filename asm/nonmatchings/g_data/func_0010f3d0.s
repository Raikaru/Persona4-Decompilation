.section .text
.set noat
.set noreorder
glabel func_0010f3d0
    /* F3D0 0010F3D0 FFFFA530 */  andi       $5, $5, 0xFFFF
    /* F3D4 0010F3D4 FFFF8330 */  andi       $3, $4, 0xFFFF
    /* F3D8 0010F3D8 C0180300 */  sll        $3, $3, 3
    /* F3DC 0010F3DC 2130A300 */  addu       $6, $5, $3
    /* F3E0 0010F3E0 1F00C430 */  andi       $4, $6, 0x1F
    /* F3E4 0010F3E4 01000324 */  addiu      $3, $0, 0x1
    /* F3E8 0010F3E8 04288300 */  sllv       $5, $3, $4
    /* F3EC 0010F3EC 42190600 */  srl        $3, $6, 5
    /* F3F0 0010F3F0 80200300 */  sll        $4, $3, 2
    /* F3F4 0010F3F4 7A00033C */  lui        $3, %hi(D_0079BCD8)
    /* F3F8 0010F3F8 D8BC6324 */  addiu      $3, $3, %lo(D_0079BCD8)
    /* F3FC 0010F3FC 21206400 */  addu       $4, $3, $4
    /* F400 0010F400 0000838C */  lw         $3, 0x0($4)
    /* F404 0010F404 25186500 */  or         $3, $3, $5
    /* F408 0010F408 000083AC */  sw         $3, 0x0($4)
    /* F40C 0010F40C 0800E003 */  jr         $31
    /* F410 0010F410 00000000 */   nop
    /* F414 0010F414 00000000 */  nop
    /* F418 0010F418 00000000 */  nop
    /* F41C 0010F41C 00000000 */  nop
.size func_0010f3d0, 0x50
