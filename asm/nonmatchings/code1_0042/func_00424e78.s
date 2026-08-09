.section .text
.set noat
.set noreorder
glabel func_00424e78
    /* 324E78 00424E78 FFFF193C */  lui        $25, (0xFFFFFFC0 >> 16)
    /* 324E7C 00424E7C C0FF3937 */  ori        $25, $25, (0xFFFFFFC0 & 0xFFFF)
    /* 324E80 00424E80 2600A018 */  blez       $5, .L00424F1C
    /* 324E84 00424E84 21508500 */   addu      $10, $4, $5
    /* 324E88 00424E88 24409900 */  and        $8, $4, $25
    /* 324E8C 00424E8C FFFF4A25 */  addiu      $10, $10, -0x1
    /* 324E90 00424E90 24485901 */  and        $9, $10, $25
    /* 324E94 00424E94 23502801 */  subu       $10, $9, $8
    /* 324E98 00424E98 82590A00 */  srl        $11, $10, 6
    /* 324E9C 00424E9C 01006B25 */  addiu      $11, $11, 0x1
    /* 324EA0 00424EA0 07006931 */  andi       $9, $11, 0x7
    /* 324EA4 00424EA4 08002011 */  beqz       $9, .L00424EC8
    /* 324EA8 00424EA8 C2500B00 */   srl       $10, $11, 3
  .L00424EAC:
    /* 324EAC 00424EAC 0F000000 */  sync
    /* 324EB0 00424EB0 000018BD */  cache      0x18, 0x0($8) /* handwritten instruction */
    /* 324EB4 00424EB4 0F000000 */  sync
    /* 324EB8 00424EB8 00000000 */  nop
    /* 324EBC 00424EBC FFFF2925 */  addiu      $9, $9, -0x1
    /* 324EC0 00424EC0 FAFF201D */  bgtz       $9, .L00424EAC
    /* 324EC4 00424EC4 40000825 */   addiu     $8, $8, 0x40
  .L00424EC8:
    /* 324EC8 00424EC8 14004011 */  beqz       $10, .L00424F1C
  .L00424ECC:
    /* 324ECC 00424ECC FFFF4A25 */   addiu     $10, $10, -0x1
    /* 324ED0 00424ED0 0F000000 */  sync
    /* 324ED4 00424ED4 000018BD */  cache      0x18, 0x0($8) /* handwritten instruction */
    /* 324ED8 00424ED8 0F000000 */  sync
    /* 324EDC 00424EDC 400018BD */  cache      0x18, 0x40($8) /* handwritten instruction */
    /* 324EE0 00424EE0 0F000000 */  sync
    /* 324EE4 00424EE4 800018BD */  cache      0x18, 0x80($8) /* handwritten instruction */
    /* 324EE8 00424EE8 0F000000 */  sync
    /* 324EEC 00424EEC C00018BD */  cache      0x18, 0xC0($8) /* handwritten instruction */
    /* 324EF0 00424EF0 0F000000 */  sync
    /* 324EF4 00424EF4 000118BD */  cache      0x18, 0x100($8) /* handwritten instruction */
    /* 324EF8 00424EF8 0F000000 */  sync
    /* 324EFC 00424EFC 400118BD */  cache      0x18, 0x140($8) /* handwritten instruction */
    /* 324F00 00424F00 0F000000 */  sync
    /* 324F04 00424F04 800118BD */  cache      0x18, 0x180($8) /* handwritten instruction */
    /* 324F08 00424F08 0F000000 */  sync
    /* 324F0C 00424F0C C00118BD */  cache      0x18, 0x1C0($8) /* handwritten instruction */
    /* 324F10 00424F10 0F000000 */  sync
    /* 324F14 00424F14 EDFF401D */  bgtz       $10, .L00424ECC
    /* 324F18 00424F18 00020825 */   addiu     $8, $8, 0x200
  .L00424F1C:
    /* 324F1C 00424F1C 0800E003 */  jr         $31
    /* 324F20 00424F20 00000000 */   nop
.size func_00424e78, 0xac
