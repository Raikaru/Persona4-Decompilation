.section .text
.set noat
.set noreorder
glabel func_001a3d50
    /* A3D50 001A3D50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* A3D54 001A3D54 1000BFFF */  sd         $31, 0x10($29)
    /* A3D58 001A3D58 0000B07F */  sq         $16, 0x0($29)
    /* A3D5C 001A3D5C 2D808000 */  daddu      $16, $4, $0
    /* A3D60 001A3D60 000084DC */  ld         $4, 0x0($4)
    /* A3D64 001A3D64 FF3F023C */  lui        $2, (0x3FFFFFFF >> 16)
    /* A3D68 001A3D68 FFFF4234 */  ori        $2, $2, (0x3FFFFFFF & 0xFFFF)
    /* A3D6C 001A3D6C 3C180200 */  dsll32     $3, $2, 0
    /* A3D70 001A3D70 FFFF0234 */  ori        $2, $0, 0xFFFF
    /* A3D74 001A3D74 38140200 */  dsll       $2, $2, 16
    /* A3D78 001A3D78 FFFF4234 */  ori        $2, $2, 0xFFFF
    /* A3D7C 001A3D7C 25284300 */  or         $5, $2, $3
    /* A3D80 001A3D80 FC4E060C */  jal        func_00193bf0
    /* A3D84 001A3D84 00000000 */   nop
    /* A3D88 001A3D88 10004014 */  bnez       $2, .L001A3DCC
    /* A3D8C 001A3D8C 00000000 */   nop
    /* A3D90 001A3D90 FFFF0224 */  addiu      $2, $0, -0x1
    /* A3D94 001A3D94 480402A6 */  sh         $2, 0x448($16)
    /* A3D98 001A3D98 ACB3848F */  lw         $4, -0x4C54($28)
    /* A3D9C 001A3D9C 0C00838C */  lw         $3, 0xC($4)
    /* A3DA0 001A3DA0 4000023C */  lui        $2, (0x400000 >> 16)
    /* A3DA4 001A3DA4 25106200 */  or         $2, $3, $2
    /* A3DA8 001A3DA8 0C0082AC */  sw         $2, 0xC($4)
    /* A3DAC 001A3DAC ACB3838F */  lw         $3, -0x4C54($28)
    /* A3DB0 001A3DB0 18006294 */  lhu        $2, 0x18($3)
    /* A3DB4 001A3DB4 07004234 */  ori        $2, $2, 0x7
    /* A3DB8 001A3DB8 180062A4 */  sh         $2, 0x18($3)
    /* A3DBC 001A3DBC 2D200002 */  daddu      $4, $16, $0
    /* A3DC0 001A3DC0 20000524 */  addiu      $5, $0, 0x20
    /* A3DC4 001A3DC4 00C2060C */  jal        func_001b0800
    /* A3DC8 001A3DC8 00000000 */   nop
  .L001A3DCC:
    /* A3DCC 001A3DCC 1000BFDF */  ld         $31, 0x10($29)
    /* A3DD0 001A3DD0 0000B07B */  lq         $16, 0x0($29)
    /* A3DD4 001A3DD4 2000BD27 */  addiu      $29, $29, 0x20
    /* A3DD8 001A3DD8 0800E003 */  jr         $31
    /* A3DDC 001A3DDC 00000000 */   nop
.size func_001a3d50, 0x90
