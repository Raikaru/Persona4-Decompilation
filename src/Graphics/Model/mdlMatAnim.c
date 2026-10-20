/* Original translation unit mdlMatAnim.c (from __FILE__ assert strings). */
#include "type.h"
#include "include_asm.h"
#include "Kosaka/k_clump_internal.h"
#include "rw_atomic_layout_internal.h"

/* SDK material and geometry offsets are defined in rw/world/bamateri.h
 * and bageomet.h. Only the fields this unit touches are exposed here. */
struct RpMaterial {
    void *texture;
    u8 color[4];
    void *pipeline;
    f32 surface[3];
};
struct RpGeometry {
    u8 object[8];
    u32 flags;
    u8 pad0C[0x14];
    u8 *materials;
    s32 materialCount;
};

typedef s32 (*code)();
extern code DAT_008873ec_abs[];
extern void mdlReleaseU16Ref(s32 wrapper);
extern void chkmemAllocSiteTag(u8 *file, s32 line);
extern void mdlDispatchTrackRows(u8 *leftTrack, u8 *leftTime, f32 rightTrack, f32 rightTime, f32 weight);
extern u8 D_00713260[];
extern u32 D_00713220[];

typedef struct {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_C;
} MdlFrameDispatch;

/* Nodes are allocated as 0x58 bytes. Four 0x10-byte tracks precede the
 * material snapshot; the final words hold the retained collector and link. */
typedef union MdlMatAnimAddress {
    u32 word;
    s32 signedWord;
    u8 *bytes;
} MdlMatAnimAddress;
typedef struct MdlMatAnimChannel {
    u32 count;
    union { u32 word; f32 value; } duration;
    u32 stride;
    MdlMatAnimAddress data;
} MdlMatAnimChannel;
typedef struct MdlMatAnimNode {
    MdlMatAnimChannel channels[4];
    u8 color[4];
    f32 surface[3];
    MdlMatAnimAddress table;
    MdlMatAnimAddress next;
} MdlMatAnimNode;
typedef struct MdlMatAnimCollector {
    u8 *entries;
    u16 count;
    u16 capacity;
    u16 references;
    u16 unk0A;
} MdlMatAnimCollector;
typedef struct MdlMatAnimMatchCount {
    u32 name;
    u16 count;
} MdlMatAnimMatchCount;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void memset(void *dest, s32 value, s32 size);
extern s32 func_003bd0b0(u8 *userData, s32 index);
extern s32 strcmp(const char *left, const char *right);
extern void mdlAppendU32Entry(s32 *wrapper,u32 value);
extern u8 DAT_007641e0;

extern void *mdlMatAnimCollectMaterial(void *object, void *context);

extern void *mdlMatAnimFlagMatchedAtomic(void *object, void *context);

extern void *mdlMatAnimCountAtomicMatch(void *atomic, void *context);


/* Allocates an empty material-animation list: a single head word set to null. */
// FUN_0047F9F0
s32 *mdlMatAnimCreateList(void)
{
    s32 *anim;

    chkmemAllocSiteTag(D_00713260, 0x22C);
    anim = (s32 *)jtbl_008873E8[0](4, 0x40000);
    memset(anim, 0, 4);
    *anim = 0;
    return anim;
}

/* Frees a material-animation list: each node releases its four channel slots and its table reference, then the list head. */
// FUN_0047FA60
void mdlMatAnimFreeList(s32 list)
{
  s32 node;
  s32 nextNode;
  u32 channelIndex;
  MdlMatAnimChannel *channel;

  node = *(s32 *)list;
  while (node != 0) {
    nextNode = ((MdlMatAnimNode *)node)->next.signedWord;
    for (channelIndex = 0; channelIndex < 4; channelIndex = channelIndex + 1) {
      channel = (MdlMatAnimChannel *)(node + channelIndex * 0x10);
      if (channel->data.word != 0) {
        ((void (*)())DAT_008873ec_abs[0])(channel->data.word);
        channel->data.word = 0;
      }
      channel->count = 0;
      channel->duration.word = 0;
      channel->stride = 0;
    }
    mdlReleaseU16Ref(((MdlMatAnimNode *)node)->table.word);
    ((void (*)())DAT_008873ec_abs[0])(node);
    node = nextNode;
  }
  ((void (*)())DAT_008873ec_abs[0])(list);
  return;
}


/* Finds the node whose table is arg1, or whose table holds the same leading u32 entries (count at +4); NULL when none matches. */
// FUN_0047FB50
u8 *mdlMatAnimFindNodeByTable(u8 **list, s32 *table)
{
    s32 entryOffset;
    s32 entryIndex;
    s32 entryCount;
    u8 *nodeTable;
    u8 *node;
    u32 *leftEntry;
    u32 *rightEntry;

    entryCount = ((MdlMatAnimCollector *)table)->count;
    node = (u8 *)(*list);
    while (node != NULL) {
        nodeTable = (u8 *)(((MdlMatAnimNode *)node)->table.bytes);
        if (nodeTable == (u8 *)table) {
            return node;
        }
        if (((MdlMatAnimCollector *)nodeTable)->count == entryCount) {
            entryIndex = 0;
            while (entryIndex < entryCount) {
                entryOffset = (entryIndex & 0xFFFF) * 4;
                /* measured: retail indexes entries by byte offset, not by word index. */
                leftEntry = (u32 *)(*(u8 **)nodeTable + entryOffset);
                rightEntry = (u32 *)(*(u8 **)table + entryOffset);
                if (*leftEntry == *rightEntry) {
                    entryIndex += 1;
                } else {
                    break;
                }
            }
            if (entryIndex == entryCount) {
                return node;
            }
        }
        node = (u8 *)(((MdlMatAnimNode *)node)->next.bytes);
    }
    return NULL;
}


/* Scaled apply: for each node, initialises each enabled channel with the scale, then applies every table entry to that channel's working object. */
// FUN_0047FBF0
void mdlMatAnimApplyScaled(u8 **list, f32 scale)
{
    u8 *node;
    u8 *tbl;
    u8 *entry;
    u32 i;
    u32 j;
    u8 *work;
    u32 count;
    u8 *(*init)(u8 *, f32);
    void (*apply)(u8 *, u32);

    node = *list;
    while (node != NULL) {
        tbl = ((MdlMatAnimNode *)node)->table.bytes;
        count = ((MdlMatAnimCollector *)tbl)->count;
        for (i = 0; i < 4; i++) {
            if (((MdlFrameDispatch *)((u8 *)D_00713220 + i * 0x10))->field_C == 0) continue;
            if (((MdlMatAnimChannel *)(node + i * 0x10))->data.word == 0) continue;
            init = (u8 *(*)(u8 *, f32))((MdlFrameDispatch *)((u8 *)D_00713220 + i * 0x10))->field_0;
            work = init(node + i * 0x10, scale);
            entry = (u8 *)D_00713220 + i * 0x10;
            for (j = 0; j < count; j++) {
                apply = (void (*)(u8 *, u32))((MdlFrameDispatch *)entry)->field_C;
                apply(work, ((u32 *)*(u8 **)tbl)[j]);
            }
        }
        node = ((MdlMatAnimNode *)node)->next.bytes;
    }
}


/* For each node, dispatches the track rows when the second list has a matching table; otherwise
 * applies every enabled channel with the node pivot and the scales. */
// FUN_0047FD10
void mdlMatAnimUpdateList(u8 **list, f32 scale1, u8 **referenceList, f32 scale2, f32 scale3)
{
    u8 *node;
    u8 *match;
    u8 *tbl;
    u8 *entry;
    u32 i;
    u32 j;
    u8 *work;
    u32 count;
    u8 *(*init)(u8 *, f32, u8 *, f32);
    void (*apply)(u8 *, u32);
    MdlMatAnimNode *materialNode;

    node = *list;
    while (node != NULL) {
        materialNode = (MdlMatAnimNode *)node;
        match = mdlMatAnimFindNodeByTable(referenceList, (s32 *)materialNode->table.bytes);
        if (match != NULL) {
            mdlDispatchTrackRows(node, match, scale1, scale2, scale3);
        } else {
            tbl = materialNode->table.bytes;
            count = ((MdlMatAnimCollector *)tbl)->count;
            for (i = 0; i < 4; i++) {
                if (((MdlFrameDispatch *)((u8 *)D_00713220 + i * 0x10))->field_C == 0) continue;
                if (((MdlMatAnimChannel *)(node + i * 0x10))->data.word == 0) continue;
                init = (u8 *(*)(u8 *, f32, u8 *, f32))((MdlFrameDispatch *)((u8 *)D_00713220 + i * 0x10))->field_8;
                work = init(node + i * 0x10, scale1, node + 0x40, scale3);
                entry = (u8 *)D_00713220 + i * 0x10;
                for (j = 0; j < count; j++) {
                    apply = (void (*)(u8 *, u32))((MdlFrameDispatch *)entry)->field_C;
                    apply(work, ((u32 *)*(u8 **)tbl)[j]);
                }
            }
        }
        node = ((MdlMatAnimNode *)node)->next.bytes;
    }
}


/* For each node, applies every enabled channel's init callback with scale1, the node pivot and
 * scale2, then applies each table entry to the working object. */
// FUN_0047FE90
void mdlMatAnimApplyWithPivot(u8 **list, f32 scale1, f32 scale2)
{
    u8 *node;
    u8 *tbl;
    u8 *entry;
    u32 i;
    u32 j;
    u8 *work;
    u32 count;
    u8 *(*init)(u8 *, f32, u8 *, f32);
    void (*apply)(u8 *, u32);

    node = *list;
    while (node != NULL) {
        tbl = ((MdlMatAnimNode *)node)->table.bytes;
        count = ((MdlMatAnimCollector *)tbl)->count;
        for (i = 0; i < 4; i++) {
            if (((MdlFrameDispatch *)((u8 *)D_00713220 + i * 0x10))->field_C == 0) continue;
            if (((MdlMatAnimChannel *)(node + i * 0x10))->data.word == 0) continue;
            init = (u8 *(*)(u8 *, f32, u8 *, f32))((MdlFrameDispatch *)((u8 *)D_00713220 + i * 0x10))->field_8;
            work = init(node + i * 0x10, scale1, node + 0x40, scale2);
            entry = (u8 *)D_00713220 + i * 0x10;
            for (j = 0; j < count; j++) {
                apply = (void (*)(u8 *, u32))((MdlFrameDispatch *)entry)->field_C;
                apply(work, ((u32 *)*(u8 **)tbl)[j]);
            }
        }
        node = ((MdlMatAnimNode *)node)->next.bytes;
    }
}


/* Copies each node's packed colour and three surface floats into every entry of its track table.
 * The reads are volatile, per the measured note in the body. */
// FUN_0047FFC0
void mdlMatAnimCopyNodeMaterial(s32 *object)
{
  u8 red;

  u8 green;

  u8 blue;

  u8 alpha;

  u32 entryCount;

  s32 *table;

  s32 material;

  s32 node;

  u32 entryIndex;

  f32 ambient;

  f32 diffuse;
  f32 specular;

  node = *object;
  for (; node != 0; node = ((MdlMatAnimNode *)node)->next.signedWord) {

    table = (s32 *)((MdlMatAnimNode *)node)->table.bytes;

    entryCount = ((MdlMatAnimCollector *)table)->count;

    for (entryIndex = 0; entryIndex < entryCount; entryIndex = entryIndex + 1) {
      material = ((s32 *)*table)[entryIndex];
      red = ((volatile MdlMatAnimNode *)node)->color[0];
      green = ((volatile MdlMatAnimNode *)node)->color[1];
      blue = ((volatile MdlMatAnimNode *)node)->color[2];
      alpha = ((volatile MdlMatAnimNode *)node)->color[3];
      ((RpMaterial *)material)->color[0] = red;
      ((RpMaterial *)material)->color[1] = green;
      ((RpMaterial *)material)->color[2] = blue;
      ((RpMaterial *)material)->color[3] = alpha;
      material = ((s32 *)*table)[entryIndex];
      ambient = ((volatile MdlMatAnimNode *)node)->surface[0];
      specular = ((volatile MdlMatAnimNode *)node)->surface[1];
      diffuse = ((volatile MdlMatAnimNode *)node)->surface[2];
      ((RpMaterial *)material)->surface[0] = ambient;
      ((RpMaterial *)material)->surface[1] = specular;
      ((RpMaterial *)material)->surface[2] = diffuse;
    }


  }

  return;

}


/* Returns the largest channel duration across all nodes whose channel data pointer is set; zero if
 * none. */
// FUN_00480060
f32 mdlMatAnimMaxDuration(u8 **list)
{
    f32 maximumDuration;
    f32 duration;
    u8 *node;
    u32 channelIndex;

    maximumDuration = 0.0f;
    node = (u8 *)(*list);
    while (node != NULL) {
        channelIndex = 0;
        while (channelIndex < 4U) {
            if (((MdlMatAnimChannel *)(node + channelIndex * 0x10))->data.signedWord != 0) {
                duration = ((MdlMatAnimChannel *)(node + channelIndex * 0x10))->duration.value;
                if (duration > maximumDuration) {
                    maximumDuration = duration;
                }
            }
            channelIndex += 1;
        }
        node = (u8 *)(((MdlMatAnimNode *)node)->next.bytes);
    }
    return maximumDuration;
}


/* Reads one material-animation chunk: header, material name, the matching materials in the clump,
 * the track node for the first match (created if absent), and the channel selected by chunk tag
 * 0xF0F00080..83. Both loader paths supply only those four chunk tags. */
// FUN_004800D0
s32 mdlMatAnimLoadChunk(void *stream, u8 **list, u32 chunkTag, void *clump)
{
    typedef struct { u32 count; f32 duration; u32 stride; u32 nameLength; u32 unk10; } Hdr;
    typedef struct { u8 r, g, b, a; } MatColor;
    typedef struct { f32 ambient, specular, diffuse; } MatSurface;
    Hdr header;
    u32 search[2];
    u8 nameBuf[0x80];
    u8 *channel;
    u8 *name;
    s32 allocated;
    u8 *node;
    u8 *table;
    u32 i;
    u8 *entry;
    u8 *mat;
    u8 *tmp;
    MdlMatAnimNode *materialNode;
    MdlMatAnimChannel *materialChannel;
    RpMaterial *material;
    extern u32 func_003e2910(void *a, void *b, u32 c);
    extern void *func_003e2ce0(void *a, u32 b);
    extern u16 mdlMatAnimCountClumpMatches(void *object, u32 nameAddress);
    extern u8 *mdlMatAnimAllocCollector(s32 capacity);
    extern void *mdlMatAnimFlagClumpMatches(void *object, void *context);
    extern u32 mdlRetainU16Ref(s32 wrapper);

    func_003e2910(stream, &header, 0x14);
    if (header.nameLength < 0x80U) {
        name = nameBuf;
        allocated = 0;
    } else {
        chkmemAllocSiteTag(D_00713260, 0x307);
        name = jtbl_008873E8[0](header.nameLength + 1, 0x40000);
        allocated = 1;
    }
    i = header.nameLength;
    func_003e2910(stream, name, i);
    name[header.nameLength] = 0;
    search[0] = (u32)mdlMatAnimAllocCollector(mdlMatAnimCountClumpMatches(clump, (u32)name) & 0xFFFFU);
    search[1] = (u32)name;
    mdlMatAnimFlagClumpMatches(clump, search);
    if (allocated != 0) {
        DAT_008873ec_abs[0](name);
    }
    table = (u8 *)search[0];
    for (tmp = *list; tmp != NULL; tmp = ((MdlMatAnimNode *)tmp)->next.bytes) {
        if (((MdlMatAnimNode *)tmp)->table.bytes == table) {
            node = tmp;
            goto found;
        }
    }
    node = NULL;
found:
    if (node == NULL) {
        chkmemAllocSiteTag(D_00713260, 0x19C);
        node = jtbl_008873E8[0](0x58, 0x40000);
        memset(node, 0, 0x58);
        i = 0;
        goto looptest2;
loop2:
        tmp = node + (i * 0x10);
        ((MdlMatAnimChannel *)tmp)->count = 0;
        ((MdlMatAnimChannel *)tmp)->duration.word = 0;
        ((MdlMatAnimChannel *)tmp)->stride = 0;
        ((MdlMatAnimChannel *)tmp)->data.word = 0;
        i += 1;
looptest2:
        if (i < 4U) {
            goto loop2;
        }
        materialNode = (MdlMatAnimNode *)node;
        materialNode->next.bytes = NULL;
        entry = (u8 *)mdlRetainU16Ref((s32)table);
        ((MdlMatAnimNode *)node)->table.bytes = entry;
        mat = *(u8 **)entry;
        mat = *(u8 **)mat;
        material = (RpMaterial *)mat;
        *(MatColor *)materialNode->color = *(MatColor *)material->color;
        *(MatSurface *)materialNode->surface = *(MatSurface *)material->surface;
        tmp = *list;
        if (tmp == NULL) {
            materialNode->next.bytes = NULL;
            *list = node;
        } else {
            materialNode->next.bytes = tmp;
            *list = node;
        }
    }
    mdlReleaseU16Ref((s32)search[0]);
    switch (chunkTag) {
    case 0xF0F00080:
        channel = node;
        break;
    case 0xF0F00081:
        channel = node + 0x10;
        break;
    case 0xF0F00082:
        channel = node + 0x20;
        break;
    case 0xF0F00083:
        channel = node + 0x30;
        break;
    }
    {
        u32 dataSize = header.count * header.stride;
        materialChannel = (MdlMatAnimChannel *)channel;
        if (materialChannel->data.bytes == NULL) {
            ((MdlMatAnimChannel *)channel)->count = header.count;
            ((MdlMatAnimChannel *)channel)->duration.value = header.duration;
            ((MdlMatAnimChannel *)channel)->stride = header.stride;
            chkmemAllocSiteTag(D_00713260, 0x349);
            materialChannel->data.bytes = jtbl_008873E8[0](dataSize, 0x40000);
            func_003e2910(stream, materialChannel->data.bytes, dataSize);
        } else {
            func_003e2ce0(stream, dataSize);
        }
    }
    return 1;
}


/* Material callback: appends the material to the collector and returns NULL when one of its user-data strings (type 3) equals the collector's name; otherwise returns the material so the walk continues. */
// FUN_00480430
void *mdlMatAnimCollectMaterial(void *object, void *context)
{
  u32 *collector = context;
  s32 arrayCount;
  s32 dataCount;
  s32 arrayIndex;
  s32 dataIndex;
  RpUserDataArray *userData;
  char *name;
  char *data;

  arrayCount = func_003bcfb0(object);

  arrayIndex = 0;
  while (arrayIndex < arrayCount) {
    userData = func_003bd000(object,arrayIndex);
    name = func_003bd040(userData);
    if (strcmp(name,(char *)&DAT_007641e0) == 0) {
      dataCount = func_003bd060(userData);
      dataIndex = 0;
      while (dataIndex < dataCount) {
        if (func_003bd050(userData) == 3) {
          data = (char *)func_003bd0b0((u8 *)userData,dataIndex);
          if (strcmp((char *)collector[1],data) == 0) {
            mdlAppendU32Entry((s32 *)*collector,(u32)object);
            return 0;
          }
        }
        dataIndex++;
      }
    }
    arrayIndex++;
  }
  return object;
}


/* Atomic callback: the first material collected for this atomic sets flag 0x40 on the atomic's geometry and stops the material walk. */
// FUN_00480580
void *mdlMatAnimFlagMatchedAtomic(void *object, void *context)
{
  u8 *geometry;
  s32 materialCount;
  void *result;
  s32 materialIndex;

  geometry = (u8 *)((struct RpAtomic *)object)->geometry;
  materialCount = ((struct RpGeometry *)geometry)->materialCount;
  materialIndex = 0;
  goto check;
loop:
  result = mdlMatAnimCollectMaterial((void *)(((u32 *)((struct RpGeometry *)geometry)->materials)[materialIndex]),context);
  if (result != 0) {
    goto increment;
  }
  ((struct RpGeometry *)geometry)->flags = ((struct RpGeometry *)geometry)->flags | 0x40;
  goto done;
increment:
  materialIndex = materialIndex + 1;
check:
  if (materialIndex < materialCount) {
    goto loop;
  }
done:
  return object;
}


/* Flags every atomic in the clump whose materials match the collector's name. */
// FUN_00480630
void *mdlMatAnimFlagClumpMatches(void *object, void *context)
{
  RpClumpForAllAtomics(object,mdlMatAnimFlagMatchedAtomic,context);
  return object;
}


/* Atomic callback: for each material of the atomic, adds one to the counter at +4 of the stack result when a user-data string matches the name; each material counts once. Returns the atomic. */
// FUN_00480670
void *mdlMatAnimCountAtomicMatch(void *atomic, void *context)
{
    s32 arrayCount;
    s32 dataCount;
    RpMaterial *material;
    RpUserDataArray *userData;
    s32 materialCount;
    s32 i;
    s32 j;
    s32 k;
    u8 *list;

    list = (u8 *)((struct RpAtomic *)atomic)->geometry;
    materialCount = ((struct RpGeometry *)list)->materialCount;
    i = 0;
    while (i < materialCount) {
        material = (RpMaterial *)((u32 *)((struct RpGeometry *)list)->materials)[i];
        arrayCount = func_003bcfb0(material);
        j = 0;
        while (j < arrayCount) {
            userData = func_003bd000(material, j);
            if (strcmp((char *)func_003bd040(userData), (char *)&DAT_007641e0) == 0) {
                dataCount = func_003bd060(userData);
                k = 0;
                while (k < dataCount) {
                    if (func_003bd050(userData) == 3 &&
                        strcmp((char *)((MdlMatAnimMatchCount *)context)->name,
                               (char *)func_003bd0b0((u8 *)userData, k)) == 0) {
                        ((MdlMatAnimMatchCount *)context)->count = ((MdlMatAnimMatchCount *)context)->count + 1;
                        break;
                    } else {
                        k++;
                    }
                }
            }
            j++;
        }
        i++;
    }
    return atomic;
}

/* Returns how many materials in the clump carry the given name, found by a clump-wide walk with the atomic count callback. */
// FUN_00480800
u16 mdlMatAnimCountClumpMatches(void *object,u32 nameAddress)
{
  struct {
    u32 input;
    u16 output;
  } stack;

  stack.input = nameAddress;
  stack.output = 0;
  RpClumpForAllAtomics(object,mdlMatAnimCountAtomicMatch,&stack);
  return stack.output;
}


/* Allocates a material collector for capacity entries: the entry pointer targets the inline array
 * after the header, count starts at zero, and references is one. */
// FUN_00480840
u8 *mdlMatAnimAllocCollector(s32 capacity)
{
    u8 *anim;

    chkmemAllocSiteTag(D_00713260, 0x3E1);
    anim = (u8 *)jtbl_008873E8[0]((u16)capacity * 4 + 0xC, 0x40000);
    *(s32 *)anim = (s32)(anim + 0xC);
    ((MdlMatAnimCollector *)anim)->count = 0;
    ((MdlMatAnimCollector *)anim)->references = 1;
    ((MdlMatAnimCollector *)anim)->capacity = capacity;
    return anim;
}
