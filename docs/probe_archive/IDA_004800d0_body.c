/* Integration prerequisites and input-domain evidence are in IDA_model_subsystems.json. */
#include "type.h"

typedef struct RwStream RwStream;
typedef struct {
    u32 count;
    f32 duration;
    u32 stride;
    u32 nameLength;
    u32 unknown10;
} MdlMatAnimChunkHeader;

extern u32 func_003e2910(RwStream *stream, void *buffer, u32 length);
extern RwStream *func_003e2ce0(RwStream *stream, u32 length);
extern u16 func_00480800(u64 clump, u32 name);
extern u8 *func_00480840(s32 capacity);
extern u64 func_00480630(u64 clump, u64 search);
extern u32 func_004808f0(s32 table);
extern void func_004808b0(s32 table);
extern void func_0044ea90(u8 *file, s32 line);
extern void func_0043f9c8(void *dest, s32 value, s32 size);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *memory);
extern u8 D_00713260[];

// FUN_004800D0
s32 func_004800d0(RwStream *stream, u8 **list, u32 kind, u64 clump)
{
    u8 nameBuffer[0x80];
    MdlMatAnimChunkHeader header;
    u32 search[2];
    u8 *name;
    s32 allocatedName;
    u8 *table;
    u8 *node;
    u8 *channel;
    u8 *material;
    u32 i;
    u32 dataSize;
    u8 red, green, blue, alpha;
    f32 ambient, specular, diffuse;

    func_003e2910(stream, &header, 0x14);
    if (header.nameLength < 0x80U) {
        name = nameBuffer;
        allocatedName = 0;
    } else {
        func_0044ea90(D_00713260, 0x307);
        name = jtbl_008873E8[0](header.nameLength + 1, 0x40000);
        allocatedName = 1;
    }
    func_003e2910(stream, name, header.nameLength);
    name[header.nameLength] = 0;
    search[0] = (u32)func_00480840(func_00480800(clump, (u32)name));
    search[1] = (u32)name;
    func_00480630(clump, (u64)(u32)search);
    if (allocatedName != 0) {
        jtbl_008873EC[0](name);
    }

    table = (u8 *)search[0];
    for (node = *list; node != NULL; node = *(u8 **)(node + 0x54)) {
        if (*(u8 **)(node + 0x50) == table) {
            goto found;
        }
    }
    node = NULL;
found:
    if (node == NULL) {
        func_0044ea90(D_00713260, 0x19C);
        node = jtbl_008873E8[0](0x58, 0x40000);
        func_0043f9c8(node, 0, 0x58);
        for (i = 0; i < 4; i++) {
            *(u32 *)(node + i * 0x10) = 0;
            *(u32 *)(node + i * 0x10 + 4) = 0;
            *(u32 *)(node + i * 0x10 + 8) = 0;
            *(u32 *)(node + i * 0x10 + 0xC) = 0;
        }
        *(u8 **)(node + 0x54) = NULL;
        *(u32 *)(node + 0x50) = func_004808f0((s32)table);
        material = **(u8 ***)(*(u8 **)(node + 0x50));
        red = material[4];
        green = material[5];
        blue = material[6];
        alpha = material[7];
        node[0x40] = red;
        node[0x41] = green;
        node[0x42] = blue;
        node[0x43] = alpha;
        ambient = *(f32 *)(material + 0xC);
        specular = *(f32 *)(material + 0x10);
        diffuse = *(f32 *)(material + 0x14);
        *(f32 *)(node + 0x44) = ambient;
        *(f32 *)(node + 0x48) = specular;
        *(f32 *)(node + 0x4C) = diffuse;
        if (*list == NULL) {
            *(u8 **)(node + 0x54) = NULL;
            *list = node;
        } else {
            *(u8 **)(node + 0x54) = *list;
            *list = node;
        }
    }
    func_004808b0((s32)search[0]);

    /* The loader's material-channel domain is 0xF0F00080..0xF0F00083.
       Express selection as its real four-entry layout, not an uninitialized
       pointer on the retail switch's invalid-tag fallthrough. */
    channel = node + (kind - 0xF0F00080U) * 0x10;
    dataSize = header.count * header.stride;
    if (*(u8 **)(channel + 0xC) == NULL) {
        *(u32 *)channel = header.count;
        *(f32 *)(channel + 4) = header.duration;
        *(u32 *)(channel + 8) = header.stride;
        func_0044ea90(D_00713260, 0x349);
        *(void **)(channel + 0xC) = jtbl_008873E8[0](dataSize, 0x40000);
        func_003e2910(stream, *(void **)(channel + 0xC), dataSize);
    } else {
        func_003e2ce0(stream, dataSize);
    }
    return 1;
}
