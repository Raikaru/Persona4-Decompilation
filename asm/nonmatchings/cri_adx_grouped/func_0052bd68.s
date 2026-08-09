.section .text
.set noat
.set noreorder
glabel func_0052bd68
    /* 42BD68 0052BD68 C2170500 */  srl        $2, $5, 31
    /* 42BD6C 0052BD6C 21104500 */  addu       $2, $2, $5
    /* 42BD70 0052BD70 43100200 */  sra        $2, $2, 1
    /* 42BD74 0052BD74 40100200 */  sll        $2, $2, 1
    /* 42BD78 0052BD78 43180200 */  sra        $3, $2, 1
    /* 42BD7C 0052BD7C 0C0082AC */  sw         $2, 0xC($4)
    /* 42BD80 0052BD80 2C0083AC */  sw         $3, 0x2C($4)
    /* 42BD84 0052BD84 0800E003 */  jr         $31
    /* 42BD88 0052BD88 1C0083AC */   sw        $3, 0x1C($4)
    /* 42BD8C 0052BD8C 00000000 */  nop
.size func_0052bd68, 0x28
