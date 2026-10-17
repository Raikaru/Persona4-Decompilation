#include "h_cdvd_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "sdk_snd_internal.h"
typedef char *va_list;
#define va_start(ap, last) (ap = (va_list)__builtin_args_info(2))
#define va_end(ap) ((void)0)
extern u8 *iGpffffb510;
extern s32 iGpffffa7c8;

s32 mtMiscResourceValue(s32 arg0);


extern s32 iGpffffb538;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 D_00882EDE[];
extern u8 D_00882EFE[];
extern char D_0063CB30[];
extern char D_0063D050[];



extern s32 D_0063CB50[];
extern u8 D_0063CFA0[];
static inline u8 *code29AddOff(s32 offset, u8 *base) {
    return (u8 *)((u32)offset + (u32)base);
}
/* Element addresses for the scene source tables. The helpers keep the
   base + index * stride arithmetic of the original reads: indexing the
   typed array instead reorders the table-base load against the shift. */
static inline MtMiscSceneRecord16 *mtMiscSceneRecord16At(MtMiscSceneSource *source, s32 index) {
    return (MtMiscSceneRecord16 *)((u8 *)source->records94 + index * 0x10);
}
static inline EvtSceneRecord *evtSceneRecordAt(MtMiscSceneSource *source, s32 index) {
    return (EvtSceneRecord *)((u8 *)source->records98 + index * 0x3C);
}
// lint: allow H011 -- measured: u16 prototype regresses func_00291a60 (145 diff, wide id args)
extern u32 func_002a27c0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, f32 farg0, s32 arg5, s32 arg6,
                          s32 arg7);
extern f32 fGpffff8204;
extern void mtMiscDrawSpriteAt(s32 arg0, f32 farg0, f32 farg1, f32 farg2,
                          f32 farg3, s32 arg1, s32 arg2);
extern char D_0063C8F0[];
extern char D_0063C910[];
extern void memcpy(void *arg0, void *arg1, s32 arg2);
extern s32 D_0076462C;
extern u8 iGpffffa7e8;

extern u8 *iGpffffb540;
extern u8 D_0063E810[];
extern u16 D_008C024E[];
extern s32 D_0063E830[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0029; members 002962f0-00296850 */

extern void mtMiscCollectType1Records(u8 *arg0);
extern void mtMiscCollectType2Records(u8 *arg0);
extern void mtMiscBuildSceneNodes(u8 *arg0);
/* measured probe: preserve local constant with opt_propagation off. */
/* measured probe: close opt_propagation bracket after func_00291530. */
/* measured: opt_propagation off keeps `weapon` materialised between the index
   shift and the base add (retail sll/andi/addu); with propagation on the CSE'd
   address is finished before any argument. The index/five locals must stay
   literal under this pragma or they take a sixth saved register. Attachment
   helpers retain block-scoped u16 parameters for per-call masks. */
/* measured: restore propagation for the rest of the unit. */
/* measured probe: preserve the retail type constant and close bracket below. */
/* measured probe: close opt_propagation bracket after func_00291810. */
/* measured: O1 float-local register mapping probe for func_00293710. */
/* measured: closes O1 float-local register mapping probe for func_00293710. */
/* 776/784 bytes; four resolved relocations and eight zero alignment bytes.
 * Preserve the signed readiness gate, callback-visible record reloads, and
 * the complete four-halfword position aggregate. */
// Collects type-4 records of the current scene into event nodes. Returns early
// unless the readiness check at +0x678 passes and evtMessageWindowRecordCount reports a
// positive count.
// FUN_002962F0
void mtMiscCollectType4Records(MtMiscSceneSource *arg0, u8 *arg1)
{
  extern s32 evtMessageWindowRecordCount(s32 *arg0); /* lint: allow H011 -- the caller compares the count as signed (<= 0); the definition returns the same bits as u32 */
  extern u8 *evtNodeAlloc(s32 arg0, u8 *arg1);
  extern u8 *evtNodeCreate(u8 *arg0, s32 arg1, u8 *arg2);
  typedef struct { s16 x, y, z, w; } Pos4_962f0;
  s32 temp_3;
  u8 *temp_17;
  s32 var_16;
  u16 var_2;
  u16 var_3;
  u16 var_4;
  u8 *temp_2;
  u8 *temp_7;
  if (evtMessageWindowIsOpen((u32 *)(arg1 + 0x678)) != 1)
  {
    return;
  }
  if (evtMessageWindowRecordCount((s32 *)(arg1 + 0x678)) <= 0)
  {
    return;
  }
  temp_17 = evtNodeAlloc(4, arg1);
  var_16 = 0;
  goto loop_test;
loop_body:
  if (arg0->header->kind == 4)
  {
    var_3 = mtMiscSceneRecord16At(arg0, var_16)->type;
  }
  else
  {
    var_3 = evtSceneRecordAt(arg0, var_16)->type;
  }
  if ((var_3 & 0xFFFF) != 4)
  {
    goto loop_increment;
  }
  if (arg0->header->kind == 4)
  {
    var_2 = mtMiscSceneRecord16At(arg0, var_16)->id;
  }
  else
  {
    var_2 = evtSceneRecordAt(arg0, var_16)->id;
  }
  {
    Pos4_962f0 tmp;
    Pos4_962f0 pos;
    s16 *p10;
    u8 *p12;
    u8 *p14;
    u8 *p15;
    u8 *p16;
    temp_2 = evtNodeCreate(temp_17, var_2 & 0xFFFF, arg1);
    temp_3 = var_16 * 0x3C;
    temp_7 = (u8 *)arg0->records98 + temp_3;
    tmp = *((Pos4_962f0 *)(temp_7 + 0xC));
    pos = tmp;
    *((Pos4_962f0 *)(temp_2 + 8)) = pos;
    if (arg0->header->kind == 4)
    {
      var_4 = mtMiscSceneRecord16At(arg0, var_16)->unk_04;
    }
    else
    {
      var_4 = *((u16 *)((u8 *)arg0->records98 + temp_3 + 4));
    }
    *((u16 *)(temp_2 + 2)) = var_4;
    if (arg0->header->kind == 4)
    {
      p10 = &mtMiscSceneRecord16At(arg0, var_16)->unk_08;
    }
    else
    {
      p10 = (s16 *)((u8 *)arg0->records98 + temp_3 + 0x14);
    }
    *((s16 *)(temp_2 + 0x10)) = *p10;
    if (arg0->header->kind == 4)
    {
      p12 = (u8 *)&mtMiscSceneRecord16At(arg0, var_16)->unk_08;
    }
    else
    {
      p12 = (u8 *)((u8 *)arg0->records98 + temp_3 + 0x14);
    }
    *((s16 *)(temp_2 + 0x12)) = *((s16 *)(p12 + 2));
    if (arg0->header->kind == 4)
    {
      p14 = (u8 *)&mtMiscSceneRecord16At(arg0, var_16)->unk_08;
    }
    else
    {
      p14 = (u8 *)((u8 *)arg0->records98 + temp_3 + 0x14);
    }
    *((s8 *)(temp_2 + 0x14)) = *((s8 *)(p14 + 4));
    if (arg0->header->kind == 4)
    {
      p15 = (u8 *)&mtMiscSceneRecord16At(arg0, var_16)->unk_08;
    }
    else
    {
      p15 = (u8 *)((u8 *)arg0->records98 + temp_3 + 0x14);
    }
    *((s8 *)(temp_2 + 0x15)) = *((s8 *)(p15 + 5));
    if (arg0->header->kind == 4)
    {
      p16 = (u8 *)&mtMiscSceneRecord16At(arg0, var_16)->unk_08;
    }
    else
    {
      p16 = (u8 *)((u8 *)arg0->records98 + temp_3 + 0x14);
    }
    *((s8 *)(temp_2 + 0x16)) = *((s8 *)(p16 + 6));
  }
loop_increment:
  var_16 += 1;
loop_test:
  if (var_16 < arg0->countAC)
  {
    goto loop_body;
  }
  return;
}

// Collects type-5 records (0x3C-byte entries from the list at +0xA4). The count
// comes from +0xAC when the list kind is below 6, else from +0xA8.
// FUN_00296600
void mtMiscCollectType5Records(MtMiscSceneSource *arg0, u8 *arg1)
{
  extern u8 *evtNodeCreate();
  extern u8 *evtNodeAlloc(s32 arg0);
  s32 temp_16;
  u8 *new_var3;
  u8 *new_var;
  s32 var_17;
  u8 *temp_19;
  s32 var_18;
  s16 field_c;
  s16 field_e;
  s16 field_10;
  s16 field_12;
  u16 temp_6;
  u8 *temp_2;
  u8 *temp_3;
  u8 *temp_5;
  temp_19 = evtNodeAlloc(5);
  if ((arg0->header->kind) < 6)
  {
    var_17 = arg0->countAC;
  }
  else
  {
    var_17 = arg0->countA8;
  }
  var_18 = 0;
  goto loop_7_test;
  loop_7_body:
  temp_5 = (u8 *)arg0->recordsA4;

  temp_16 = var_18 * 0x3C;
  temp_5 += temp_16;
  if ((*((u16 *) temp_5)) != 5)
  {
    goto loop_7_increment;
  }
  temp_2 = evtNodeCreate((temp_6 = *((u16 *) (temp_5 + 2)), temp_19), temp_6, arg1);
  temp_3 = ((u8 *)arg0->recordsA4) + temp_16;
  field_c = *((s16 *) (temp_3 + 0xC));
  field_e = *((s16 *) (temp_3 + 0xE));
  field_10 = *((s16 *) (temp_3 + 0x10));
  field_12 = *((s16 *) (temp_3 + 0x12));
  new_var3 = temp_2;
  *((s16 *) (temp_2 + 8)) = field_c;
  *((s16 *) (new_var3 + 0xA)) = field_e;
  *((s16 *) (new_var3 + 0xC)) = field_10;
  *((s16 *) (((0, new_var3)) + 0xE)) = field_12;
  new_var = new_var3;
  temp_3 = ((u8 *)arg0->recordsA4) + temp_16;
  *((s16 *) (new_var + 0x10)) = *((s16 *) (temp_3 + 0x14));
  temp_3 = ((u8 *)arg0->recordsA4) + temp_16;
  *((s8 *) (new_var + 0x12)) = *((s8 *) (temp_3 + 0x16));
  loop_7_increment:
  var_18 += 1;

  loop_7_test:
  if (var_18 < var_17)
  {
    goto loop_7_body;
  }

  return;
}

// Type-19 counterpart of mtMiscCollectType5Records: same loop and count choice,
// matching record type 0x13 and copying the settings halfwords at +0x14 to +0x18.
// FUN_00296720
void mtMiscCollectType19Records(MtMiscSceneSource *arg0, u8 *arg1)
{
  extern u8 *evtNodeCreate();
  extern u8 *evtNodeAlloc(s32 arg0);
  s32 temp_16;
  u8 *new_var3;
  u8 *new_var;
  s32 var_17;
  u8 *temp_19;
  s32 var_18;
  s16 field_c;
  s16 field_e;
  s16 field_10;
  s16 field_12;
  s16 field_14;
  s16 field_16;
  s16 field_18;
  u16 temp_6;
  u8 *temp_2;
  u8 *temp_3;
  u8 *temp_5;
  temp_19 = evtNodeAlloc(0x13);
  if ((arg0->header->kind) < 6)
  {
    var_17 = arg0->countAC;
  }
  else
  {
    var_17 = arg0->countA8;
  }
  var_18 = 0;
  goto loop_7_test;
  loop_7_body:
  temp_5 = (u8 *)arg0->recordsA4;
  temp_16 = var_18 * 0x3C;
  temp_5 += temp_16;
  if ((*((u16 *) temp_5)) != 0x13)
  {
    goto loop_7_increment;
  }
  temp_2 = evtNodeCreate((temp_6 = *((u16 *) (temp_5 + 2)), temp_19),
                          temp_6, arg1);
  temp_3 = ((u8 *)arg0->recordsA4) + temp_16;
  field_c = *((s16 *) (temp_3 + 0xC));
  field_e = *((s16 *) (temp_3 + 0xE));
  field_10 = *((s16 *) (temp_3 + 0x10));
  field_12 = *((s16 *) (temp_3 + 0x12));
  new_var3 = temp_2;
  *((s16 *) (temp_2 + 8)) = field_c;
  *((s16 *) (new_var3 + 0xA)) = field_e;
  *((s16 *) (new_var3 + 0xC)) = field_10;
  *((s16 *) (((0, new_var3)) + 0xE)) = field_12;
  new_var = new_var3;
  temp_3 = ((u8 *)arg0->recordsA4) + temp_16;
  field_14 = *((s16 *) (temp_3 + 0x14));
  *((s16 *) (new_var + 0x10)) = field_14;
  temp_3 = ((u8 *)arg0->recordsA4) + temp_16;
  field_16 = *((s16 *) (temp_3 + 0x16));
  *((s16 *) (new_var + 0x12)) = field_16;
  temp_3 = ((u8 *)arg0->recordsA4) + temp_16;
  field_18 = *((s16 *) (temp_3 + 0x18));
  *((s16 *) (new_var + 0x14)) = field_18;
  loop_7_increment:
  var_18 += 1;

  loop_7_test:
  if (var_18 < var_17)
  {
    goto loop_7_body;
  }

  return;
}

/* Each filtered scan owns its resource and index. With opt_lifetimes on,
 * those local scopes reproduce all 6312 retail code bytes; the 6320-byte
 * function window ends in eight zero alignment bytes. */
#pragma push
/* measured: func_00296850 MATCH -> MISMATCH without this pragma. */
#pragma opt_lifetimes on
// Builds the mt_misc scene for arg1 from the source record arg0: scene nodes, the type 1, 2, 4, 5, and 19 record sets, the header words copied from arg0+0x90, and the per-entry nodes counted at arg0+0x58.
// FUN_00296850
s32 mtMiscBuildScene(MtMiscSceneSource *arg0, u8 *arg1)
{
  extern void mtMiscBuildSceneNodes(u8 *arg0);
  extern void mtMiscCollectType1Records(u8 *arg0);
  extern void mtMiscCollectType2Records(u8 *arg0);
  extern void evtNodeLoadRecordsByCount(u8 *arg0, u8 *arg1, u8 *arg2, u16 arg3);
  extern void evtNodeLoadRecords2F(u8 *arg0, u8 *arg1);
  extern void evtNodeLoadCameraRecords(u8 *arg0, u8 *arg1);
  extern void evtNodeLoadRecords24(u8 *arg0, u8 *arg1);
  extern void evtNodeLoadRecords30(u8 *arg0, u8 *arg1);
  extern void evtNodeLoadRecords34(u8 *arg0, u8 *arg1);
  extern void evtNodeLoadRecords0A(u8 *arg0, u8 *arg1);
  extern void mtMiscCollectType4Records(MtMiscSceneSource *arg0, u8 *arg1);
  extern void mtMiscCollectType5Records(MtMiscSceneSource *arg0, u8 *arg1);
  extern void mtMiscCollectType19Records(MtMiscSceneSource *arg0, u8 *arg1);
  extern void evtRefreshNodeResources(u8 *arg0);
  extern void evtResultSet(s32 arg0, s32 arg1);
  extern u8 *evtNodeAlloc(s32 arg0, u8 *arg1);
  extern u8 *evtNodeCreate(u8 *arg0, s32 arg1, u8 *arg2);
  extern void func_00440b68(char *fmt, ...);
  extern char D_0063CB00[];
  extern char D_0063CB18[];
  typedef struct { s16 x, y, z, w; } Pos4;
  s32 var_18;
  s32 var_19;
  u8 *temp_18;
  u8 *node;
  s32 tmpc;
  s32 *srcw;
  s32 *dstw;
  s32 ncopy;
  s32 off;
  u8 *dest;
  u8 *q;
  u16 id;
  u16 id2;
  u16 var_4h;

  func_00440b68(D_0063CB00);
  mtMiscBuildSceneNodes(arg1);
  mtMiscCollectType1Records(arg1);
  mtMiscCollectType2Records(arg1);
  var_18 = 0;
  goto loop18_test;
loop18_body:
  evtNodeAlloc(0x18, arg1);
  var_18 += 1;
loop18_test:
  if (var_18 < arg0->count58) {
    goto loop18_body;
  }
  func_00440b68(D_0063CB18);
  if (arg0->headerWords != NULL) {
    *((s32 *)(arg1 + 8)) = arg0->headerWords[2];
    *((s32 *)(arg1 + 0xC)) = arg0->headerWords[0];
    *((s32 *)(arg1 + 0x10)) = arg0->headerWords[1];
    *((s32 *)(arg1 + 0xD0)) = arg0->headerWords[3];
    srcw = arg0->headerWords;
    dstw = (s32 *)(arg1 + 0x24);
    ncopy = 9;
do_copy:
    tmpc = *srcw;
    srcw += 1;
    ncopy -= 1;
    *dstw = tmpc;
    dstw += 1;
    if (ncopy > 0) {
      goto do_copy;
    }
    *((s32 *)(arg1 + 0x14)) = *((s32 *)(arg1 + 0xC));
    *((s32 *)(arg1 + 0x18)) = -1;
    if (*((s32 *)(arg1 + 0x14)) < 0) {
      *((s32 *)(arg1 + 0x14)) = 0;
    }
    tmpc = *((s32 *)(arg1 + 8)) - 1;
    if (tmpc < *((s32 *)(arg1 + 0x14))) {
      *((s32 *)(arg1 + 0x14)) = tmpc;
    }
  }
  node = *((u8 **)(arg1 + 0x4C));
  goto ll_test;
ll_body:
  evtNodeLoadRecordsByCount((u8 *)arg0, arg1, node, *((u16 *)(node + 0xC)));
  node = *((u8 **)(node + 0x90));
ll_test:
  if (node != NULL) {
    goto ll_body;
  }
  evtNodeLoadRecords2F((u8 *)arg0, arg1);
  {
    u8 *resource_31;
    s32 index_31;
    resource_31 = evtNodeAlloc(0x31, arg1);
    index_31 = 0;
    goto loop31_test;
  loop31_body:
    if (arg0->header->kind == 4)
    {
      id = mtMiscSceneRecord16At(arg0, index_31)->type;
    }
    else
    {
      id = evtSceneRecordAt(arg0, index_31)->type;
    }
    if ((id & 0xFFFF) != 0x31)
    {
      goto loop31_inc;
    }
    if (arg0->header->kind == 4)
    {
      id2 = mtMiscSceneRecord16At(arg0, index_31)->id;
    }
    else
    {
      id2 = evtSceneRecordAt(arg0, index_31)->id;
    }
    {
      Pos4 tmp;
      Pos4 pos;
      dest = evtNodeCreate(resource_31, id2 & 0xFFFF, arg1);
      off = index_31 * 0x3C;
      q = (u8 *)arg0->records98 + off;
      tmp = *((Pos4 *)(q + 0xC));
      pos = tmp;
      *((Pos4 *)(dest + 8)) = pos;
      if (arg0->header->kind == 4)
      {
        q = (u8 *)&mtMiscSceneRecord16At(arg0, index_31)->unk_08;
      }
      else
      {
        q = (u8 *)((u8 *)arg0->records98 + off + 0x14);
      }
      *((s32 *)(dest + 0x10)) = *((s32 *)q);
      if (arg0->header->kind == 4)
      {
        q = (u8 *)&mtMiscSceneRecord16At(arg0, index_31)->unk_08;
      }
      else
      {
        q = (u8 *)((u8 *)arg0->records98 + off + 0x14);
      }
      *((s32 *)(dest + 0x14)) = *((s32 *)(q + 4));
    }
  loop31_inc:
    index_31 += 1;
  loop31_test:
    if (index_31 < arg0->countAC)
    {
      goto loop31_body;
    }
  }
  evtNodeLoadCameraRecords((u8 *)arg0, arg1);
  temp_18 = evtNodeAlloc(0x22, arg1);
  *((s32 *)(temp_18 + 8)) = -1;
  *((s32 *)(temp_18 + 0x34)) = 0;
  var_19 = 0;
  goto loop22_test;
loop22_body:
  if (arg0->header->kind == 4)
  {
    id = mtMiscSceneRecord16At(arg0, var_19)->type;
  }
  else
  {
    id = evtSceneRecordAt(arg0, var_19)->type;
  }
  if ((id & 0xFFFF) != 0x22)
  {
    goto loop22_inc;
  }
  if (arg0->header->kind == 4)
  {
    id2 = mtMiscSceneRecord16At(arg0, var_19)->id;
  }
  else
  {
    id2 = evtSceneRecordAt(arg0, var_19)->id;
  }
  {
    Pos4 tmp;
    Pos4 pos;
    dest = evtNodeCreate(temp_18, id2 & 0xFFFF, arg1);
    off = var_19 * 0x3C;
    q = (u8 *)arg0->records98 + off;
    tmp = *((Pos4 *)(q + 0xC));
    pos = tmp;
    *((Pos4 *)(dest + 8)) = pos;
  }
loop22_inc:
  var_19 += 1;
loop22_test:
  if (var_19 < arg0->countAC)
  {
    goto loop22_body;
  }
  evtNodeLoadRecords24((u8 *)arg0, arg1);
  if (*((s32 *)(*((u8 **)(arg1 + 0x5D0)) + 4)) > 0) {
    {
      u8 *resource_25;
      s32 index_25;
      resource_25 = evtNodeAlloc(0x25, arg1);
      index_25 = 0;
      goto loop25_test;
  loop25_body:
      if (arg0->header->kind == 4)
      {
        id = mtMiscSceneRecord16At(arg0, index_25)->type;
      }
      else
      {
        id = evtSceneRecordAt(arg0, index_25)->type;
      }
      if ((id & 0xFFFF) != 0x25)
      {
        goto loop25_inc;
      }
      if (arg0->header->kind == 4)
      {
        id2 = mtMiscSceneRecord16At(arg0, index_25)->id;
      }
      else
      {
        id2 = evtSceneRecordAt(arg0, index_25)->id;
      }
      {
        Pos4 tmp;
        Pos4 pos;
        dest = evtNodeCreate(resource_25, id2 & 0xFFFF, arg1);
        off = index_25 * 0x3C;
        q = (u8 *)arg0->records98 + off;
        tmp = *((Pos4 *)(q + 0xC));
        pos = tmp;
        *((Pos4 *)(dest + 8)) = pos;
        if (arg0->header->kind == 4)
        {
          q = (u8 *)&mtMiscSceneRecord16At(arg0, index_25)->unk_08;
        }
        else
        {
          q = (u8 *)((u8 *)arg0->records98 + off + 0x14);
        }
        memcpy(dest + 0x10, q, 0x28);
      }
  loop25_inc:
      index_25 += 1;
  loop25_test:
      if (index_25 < arg0->countAC)
      {
        goto loop25_body;
      }
    }
  }
  {
    u8 *resource_26;
    s32 index_26;
    resource_26 = evtNodeAlloc(0x26, arg1);
    index_26 = 0;
    goto loop26_test;
  loop26_body:
    if (arg0->header->kind == 4)
    {
      id = mtMiscSceneRecord16At(arg0, index_26)->type;
    }
    else
    {
      id = evtSceneRecordAt(arg0, index_26)->type;
    }
    if ((id & 0xFFFF) != 0x26)
    {
      goto loop26_inc;
    }
    if (arg0->header->kind == 4)
    {
      id2 = mtMiscSceneRecord16At(arg0, index_26)->id;
    }
    else
    {
      id2 = evtSceneRecordAt(arg0, index_26)->id;
    }
    {
      Pos4 tmp;
      Pos4 pos;
      dest = evtNodeCreate(resource_26, id2 & 0xFFFF, arg1);
      off = index_26 * 0x3C;
      q = (u8 *)arg0->records98 + off;
      tmp = *((Pos4 *)(q + 0xC));
      pos = tmp;
      *((Pos4 *)(dest + 8)) = pos;
      if (arg0->header->kind == 4)
      {
        q = (u8 *)&mtMiscSceneRecord16At(arg0, index_26)->unk_08;
      }
      else
      {
        q = (u8 *)((u8 *)arg0->records98 + off + 0x14);
      }
      *((s32 *)(dest + 0x10)) = *((s32 *)q);
      if (arg0->header->kind == 4)
      {
        q = (u8 *)&mtMiscSceneRecord16At(arg0, index_26)->unk_08;
      }
      else
      {
        q = (u8 *)((u8 *)arg0->records98 + off + 0x14);
      }
      *((f32 *)(dest + 0x14)) = *((f32 *)(q + 4));
    }
  loop26_inc:
    index_26 += 1;
  loop26_test:
    if (index_26 < arg0->countAC)
    {
      goto loop26_body;
    }
  }
  evtNodeLoadRecords30((u8 *)arg0, arg1);
  {
    u8 *resource_32;
    s32 index_32;
    resource_32 = evtNodeAlloc(0x32, arg1);
    index_32 = 0;
    goto loop32_test;
  loop32_body:
    if (arg0->header->kind == 4)
    {
      id = mtMiscSceneRecord16At(arg0, index_32)->type;
    }
    else
    {
      id = evtSceneRecordAt(arg0, index_32)->type;
    }
    if ((id & 0xFFFF) != 0x32)
    {
      goto loop32_inc;
    }
    if (arg0->header->kind == 4)
    {
      id2 = mtMiscSceneRecord16At(arg0, index_32)->id;
    }
    else
    {
      id2 = evtSceneRecordAt(arg0, index_32)->id;
    }
    {
      Pos4 tmp;
      Pos4 pos;
      dest = evtNodeCreate(resource_32, id2 & 0xFFFF, arg1);
      off = index_32 * 0x3C;
      q = (u8 *)arg0->records98 + off;
      tmp = *((Pos4 *)(q + 0xC));
      pos = tmp;
      *((Pos4 *)(dest + 8)) = pos;
      if (arg0->header->kind == 4)
      {
        q = (u8 *)&mtMiscSceneRecord16At(arg0, index_32)->unk_08;
      }
      else
      {
        q = (u8 *)((u8 *)arg0->records98 + off + 0x14);
      }
      *((s32 *)(dest + 0x10)) = *((s32 *)q);
    }
  loop32_inc:
    index_32 += 1;
  loop32_test:
    if (index_32 < arg0->countAC)
    {
      goto loop32_body;
    }
  }
  {
    u8 *resource_33;
    s32 index_33;
    resource_33 = evtNodeAlloc(0x33, arg1);
    index_33 = 0;
    goto loop33_test;
  loop33_body:
    if (arg0->header->kind == 4)
    {
      id = mtMiscSceneRecord16At(arg0, index_33)->type;
    }
    else
    {
      id = evtSceneRecordAt(arg0, index_33)->type;
    }
    if ((id & 0xFFFF) != 0x33)
    {
      goto loop33_inc;
    }
    if (arg0->header->kind == 4)
    {
      id2 = mtMiscSceneRecord16At(arg0, index_33)->id;
    }
    else
    {
      id2 = evtSceneRecordAt(arg0, index_33)->id;
    }
    {
      Pos4 tmp;
      Pos4 pos;
      dest = evtNodeCreate(resource_33, id2 & 0xFFFF, arg1);
      off = index_33 * 0x3C;
      q = (u8 *)arg0->records98 + off;
      tmp = *((Pos4 *)(q + 0xC));
      pos = tmp;
      *((Pos4 *)(dest + 8)) = pos;
      if (arg0->header->kind == 4)
      {
        q = (u8 *)&mtMiscSceneRecord16At(arg0, index_33)->unk_08;
      }
      else
      {
        q = (u8 *)((u8 *)arg0->records98 + off + 0x14);
      }
      memcpy(dest + 0x10, q, 0x28);
    }
  loop33_inc:
    index_33 += 1;
  loop33_test:
    if (index_33 < arg0->countAC)
    {
      goto loop33_body;
    }
  }
  evtNodeLoadRecords34((u8 *)arg0, arg1);
  {
    u8 *resource_35;
    s32 index_35;
    resource_35 = evtNodeAlloc(0x35, arg1);
    index_35 = 0;
    goto loop35_test;
  loop35_body:
    if (arg0->header->kind == 4)
    {
      id = mtMiscSceneRecord16At(arg0, index_35)->type;
    }
    else
    {
      id = evtSceneRecordAt(arg0, index_35)->type;
    }
    if ((id & 0xFFFF) != 0x35)
    {
      goto loop35_inc;
    }
    if (arg0->header->kind == 4)
    {
      id2 = mtMiscSceneRecord16At(arg0, index_35)->id;
    }
    else
    {
      id2 = evtSceneRecordAt(arg0, index_35)->id;
    }
    {
      Pos4 tmp;
      Pos4 pos;
      dest = evtNodeCreate(resource_35, id2 & 0xFFFF, arg1);
      off = index_35 * 0x3C;
      q = (u8 *)arg0->records98 + off;
      tmp = *((Pos4 *)(q + 0xC));
      pos = tmp;
      *((Pos4 *)(dest + 8)) = pos;
      if (arg0->header->kind == 4)
      {
        var_4h = mtMiscSceneRecord16At(arg0, index_35)->unk_04;
      }
      else
      {
        var_4h = *((u16 *)((u8 *)arg0->records98 + off + 4));
      }
      *((u16 *)(dest + 2)) = var_4h;
      if (arg0->header->kind == 4)
      {
        q = (u8 *)&mtMiscSceneRecord16At(arg0, index_35)->unk_08;
      }
      else
      {
        q = (u8 *)((u8 *)arg0->records98 + off + 0x14);
      }
      memcpy(dest + 0x10, q, 0x28);
    }
  loop35_inc:
    index_35 += 1;
  loop35_test:
    if (index_35 < arg0->countAC)
    {
      goto loop35_body;
    }
  }
  {
    u8 *resource_37;
    s32 index_37;
    resource_37 = evtNodeAlloc(0x37, arg1);
    index_37 = 0;
    goto loop37_test;
  loop37_body:
    if (arg0->header->kind == 4)
    {
      id = mtMiscSceneRecord16At(arg0, index_37)->type;
    }
    else
    {
      id = evtSceneRecordAt(arg0, index_37)->type;
    }
    if ((id & 0xFFFF) != 0x37)
    {
      goto loop37_inc;
    }
    if (arg0->header->kind == 4)
    {
      id2 = mtMiscSceneRecord16At(arg0, index_37)->id;
    }
    else
    {
      id2 = evtSceneRecordAt(arg0, index_37)->id;
    }
    {
      Pos4 tmp;
      Pos4 pos;
      dest = evtNodeCreate(resource_37, id2 & 0xFFFF, arg1);
      off = index_37 * 0x3C;
      q = (u8 *)arg0->records98 + off;
      tmp = *((Pos4 *)(q + 0xC));
      pos = tmp;
      *((Pos4 *)(dest + 8)) = pos;
      if (arg0->header->kind == 4)
      {
        var_4h = mtMiscSceneRecord16At(arg0, index_37)->unk_04;
      }
      else
      {
        var_4h = *((u16 *)((u8 *)arg0->records98 + off + 4));
      }
      *((u16 *)(dest + 2)) = var_4h;
      if (arg0->header->kind == 4)
      {
        q = (u8 *)&mtMiscSceneRecord16At(arg0, index_37)->unk_08;
      }
      else
      {
        q = (u8 *)((u8 *)arg0->records98 + off + 0x14);
      }
      memcpy(dest + 0x10, q, 0x28);
    }
  loop37_inc:
    index_37 += 1;
  loop37_test:
    if (index_37 < arg0->countAC)
    {
      goto loop37_body;
    }
  }
  {
    u8 *resource_38;
    s32 index_38;
    resource_38 = evtNodeAlloc(0x38, arg1);
    index_38 = 0;
    goto loop38_test;
  loop38_body:
    if (arg0->header->kind == 4)
    {
      id = mtMiscSceneRecord16At(arg0, index_38)->type;
    }
    else
    {
      id = evtSceneRecordAt(arg0, index_38)->type;
    }
    if ((id & 0xFFFF) != 0x38)
    {
      goto loop38_inc;
    }
    if (arg0->header->kind == 4)
    {
      id2 = mtMiscSceneRecord16At(arg0, index_38)->id;
    }
    else
    {
      id2 = evtSceneRecordAt(arg0, index_38)->id;
    }
    {
      Pos4 tmp;
      Pos4 pos;
      dest = evtNodeCreate(resource_38, id2 & 0xFFFF, arg1);
      off = index_38 * 0x3C;
      q = (u8 *)arg0->records98 + off;
      tmp = *((Pos4 *)(q + 0xC));
      pos = tmp;
      *((Pos4 *)(dest + 8)) = pos;
      if (arg0->header->kind == 4)
      {
        var_4h = mtMiscSceneRecord16At(arg0, index_38)->unk_04;
      }
      else
      {
        var_4h = *((u16 *)((u8 *)arg0->records98 + off + 4));
      }
      *((u16 *)(dest + 2)) = var_4h;
      if (arg0->header->kind == 4)
      {
        q = (u8 *)&mtMiscSceneRecord16At(arg0, index_38)->unk_08;
      }
      else
      {
        q = (u8 *)((u8 *)arg0->records98 + off + 0x14);
      }
      memcpy(dest + 0x10, q, 0x28);
    }
  loop38_inc:
    index_38 += 1;
  loop38_test:
    if (index_38 < arg0->countAC)
    {
      goto loop38_body;
    }
  }
  {
    u8 *resource_39;
    s32 index_39;
    resource_39 = evtNodeAlloc(0x39, arg1);
    index_39 = 0;
    goto loop39_test;
  loop39_body:
    if (arg0->header->kind == 4)
    {
      id = mtMiscSceneRecord16At(arg0, index_39)->type;
    }
    else
    {
      id = evtSceneRecordAt(arg0, index_39)->type;
    }
    if ((id & 0xFFFF) != 0x39)
    {
      goto loop39_inc;
    }
    if (arg0->header->kind == 4)
    {
      id2 = mtMiscSceneRecord16At(arg0, index_39)->id;
    }
    else
    {
      id2 = evtSceneRecordAt(arg0, index_39)->id;
    }
    {
      Pos4 tmp;
      Pos4 pos;
      dest = evtNodeCreate(resource_39, id2 & 0xFFFF, arg1);
      off = index_39 * 0x3C;
      q = (u8 *)arg0->records98 + off;
      tmp = *((Pos4 *)(q + 0xC));
      pos = tmp;
      *((Pos4 *)(dest + 8)) = pos;
      if (arg0->header->kind == 4)
      {
        var_4h = mtMiscSceneRecord16At(arg0, index_39)->unk_04;
      }
      else
      {
        var_4h = *((u16 *)((u8 *)arg0->records98 + off + 4));
      }
      *((u16 *)(dest + 2)) = var_4h;
      if (arg0->header->kind == 4)
      {
        q = (u8 *)&mtMiscSceneRecord16At(arg0, index_39)->unk_08;
      }
      else
      {
        q = (u8 *)((u8 *)arg0->records98 + off + 0x14);
      }
      memcpy(dest + 0x10, q, 0x28);
    }
  loop39_inc:
    index_39 += 1;
  loop39_test:
    if (index_39 < arg0->countAC)
    {
      goto loop39_body;
    }
  }
  evtNodeLoadRecords0A((u8 *)arg0, arg1);
  mtMiscCollectType4Records(arg0, arg1);
  mtMiscCollectType5Records(arg0, arg1);
  {
    u8 *resource_36;
    s32 index_36;
    resource_36 = evtNodeAlloc(0x36, arg1);
    index_36 = 0;
    goto loop36_test;
  loop36_body:
    if (arg0->header->kind == 4)
    {
      id = mtMiscSceneRecord16At(arg0, index_36)->type;
    }
    else
    {
      id = evtSceneRecordAt(arg0, index_36)->type;
    }
    if ((id & 0xFFFF) != 0x36)
    {
      goto loop36_inc;
    }
    if (arg0->header->kind == 4)
    {
      id2 = mtMiscSceneRecord16At(arg0, index_36)->id;
    }
    else
    {
      id2 = evtSceneRecordAt(arg0, index_36)->id;
    }
    {
      Pos4 tmp;
      Pos4 pos;
      dest = evtNodeCreate(resource_36, id2 & 0xFFFF, arg1);
      off = index_36 * 0x3C;
      q = (u8 *)arg0->records98 + off;
      tmp = *((Pos4 *)(q + 0xC));
      pos = tmp;
      *((Pos4 *)(dest + 8)) = pos;
      if (arg0->header->kind == 4)
      {
        q = (u8 *)&mtMiscSceneRecord16At(arg0, index_36)->unk_08;
      }
      else
      {
        q = (u8 *)((u8 *)arg0->records98 + off + 0x14);
      }
      memcpy(dest + 0x10, q, 0x28);
    }
  loop36_inc:
    index_36 += 1;
  loop36_test:
    if (index_36 < arg0->countAC)
    {
      goto loop36_body;
    }
  }
  mtMiscCollectType19Records(arg0, arg1);
  {
    u8 *resource_06;
    s32 index_06;
    resource_06 = evtNodeAlloc(6, arg1);
    index_06 = 0;
    goto loop06_test;
  loop06_body:
    if (arg0->header->kind == 4)
    {
      id = mtMiscSceneRecord16At(arg0, index_06)->type;
    }
    else
    {
      id = evtSceneRecordAt(arg0, index_06)->type;
    }
    if ((id & 0xFFFF) != 6)
    {
      goto loop06_inc;
    }
    if (arg0->header->kind == 4)
    {
      id2 = mtMiscSceneRecord16At(arg0, index_06)->id;
    }
    else
    {
      id2 = evtSceneRecordAt(arg0, index_06)->id;
    }
    {
      Pos4 tmp;
      Pos4 pos;
      dest = evtNodeCreate(resource_06, id2 & 0xFFFF, arg1);
      off = index_06 * 0x3C;
      q = (u8 *)arg0->records98 + off;
      tmp = *((Pos4 *)(q + 0xC));
      pos = tmp;
      *((Pos4 *)(dest + 8)) = pos;
      if (arg0->header->kind == 4)
      {
        var_4h = mtMiscSceneRecord16At(arg0, index_06)->unk_04;
      }
      else
      {
        var_4h = *((u16 *)((u8 *)arg0->records98 + off + 4));
      }
      *((u16 *)(dest + 2)) = var_4h;
      if (arg0->header->kind == 4)
      {
        q = (u8 *)&mtMiscSceneRecord16At(arg0, index_06)->unk_08;
      }
      else
      {
        q = (u8 *)((u8 *)arg0->records98 + off + 0x14);
      }
      memcpy(dest + 0x10, q, 0x28);
      if (*((s16 *)(dest + 0x12)) == -1) {
        *((s16 *)(dest + 0x12)) = 0;
      }
    }
  loop06_inc:
    index_06 += 1;
  loop06_test:
    if (index_06 < arg0->countAC)
    {
      goto loop06_body;
    }
  }
  {
    u8 *resource_07;
    s32 index_07;
    resource_07 = evtNodeAlloc(7, arg1);
    index_07 = 0;
    goto loop07_test;
  loop07_body:
    if (arg0->header->kind == 4)
    {
      id = mtMiscSceneRecord16At(arg0, index_07)->type;
    }
    else
    {
      id = evtSceneRecordAt(arg0, index_07)->type;
    }
    if ((id & 0xFFFF) != 7)
    {
      goto loop07_inc;
    }
    if (arg0->header->kind == 4)
    {
      id2 = mtMiscSceneRecord16At(arg0, index_07)->id;
    }
    else
    {
      id2 = evtSceneRecordAt(arg0, index_07)->id;
    }
    {
      Pos4 tmp;
      Pos4 pos;
      dest = evtNodeCreate(resource_07, id2 & 0xFFFF, arg1);
      off = index_07 * 0x3C;
      q = (u8 *)arg0->records98 + off;
      tmp = *((Pos4 *)(q + 0xC));
      pos = tmp;
      *((Pos4 *)(dest + 8)) = pos;
      if (arg0->header->kind == 4)
      {
        var_4h = mtMiscSceneRecord16At(arg0, index_07)->unk_04;
      }
      else
      {
        var_4h = *((u16 *)((u8 *)arg0->records98 + off + 4));
      }
      *((u16 *)(dest + 2)) = var_4h;
      if (arg0->header->kind == 4)
      {
        q = (u8 *)&mtMiscSceneRecord16At(arg0, index_07)->unk_08;
      }
      else
      {
        q = (u8 *)((u8 *)arg0->records98 + off + 0x14);
      }
      *((s16 *)(dest + 0x10)) = *((s16 *)q);
    }
  loop07_inc:
    index_07 += 1;
  loop07_test:
    if (index_07 < arg0->countAC)
    {
      goto loop07_body;
    }
  }
  {
    u8 *resource_1C;
    s32 index_1C;
    resource_1C = evtNodeAlloc(0x1C, arg1);
    index_1C = 0;
    goto loop1C_test;
  loop1C_body:
    if (arg0->header->kind == 4)
    {
      id = mtMiscSceneRecord16At(arg0, index_1C)->type;
    }
    else
    {
      id = evtSceneRecordAt(arg0, index_1C)->type;
    }
    if ((id & 0xFFFF) != 0x1C)
    {
      goto loop1C_inc;
    }
    if (arg0->header->kind == 4)
    {
      id2 = mtMiscSceneRecord16At(arg0, index_1C)->id;
    }
    else
    {
      id2 = evtSceneRecordAt(arg0, index_1C)->id;
    }
    {
      Pos4 tmp;
      Pos4 pos;
      dest = evtNodeCreate(resource_1C, id2 & 0xFFFF, arg1);
      off = index_1C * 0x3C;
      q = (u8 *)arg0->records98 + off;
      tmp = *((Pos4 *)(q + 0xC));
      pos = tmp;
      *((Pos4 *)(dest + 8)) = pos;
      if (arg0->header->kind == 4)
      {
        var_4h = mtMiscSceneRecord16At(arg0, index_1C)->unk_04;
      }
      else
      {
        var_4h = *((u16 *)((u8 *)arg0->records98 + off + 4));
      }
      *((u16 *)(dest + 2)) = var_4h;
      if (arg0->header->kind == 4)
      {
        q = (u8 *)&mtMiscSceneRecord16At(arg0, index_1C)->unk_08;
      }
      else
      {
        q = (u8 *)((u8 *)arg0->records98 + off + 0x14);
      }
      *((s32 *)(dest + 0x10)) = *((s32 *)q);
      if (arg0->header->kind == 4)
      {
        q = (u8 *)&mtMiscSceneRecord16At(arg0, index_1C)->unk_08;
      }
      else
      {
        q = (u8 *)((u8 *)arg0->records98 + off + 0x14);
      }
      *((s32 *)(dest + 0x14)) = *((s32 *)(q + 4));
      if (arg0->header->kind == 4)
      {
        q = (u8 *)&mtMiscSceneRecord16At(arg0, index_1C)->unk_08;
      }
      else
      {
        q = (u8 *)((u8 *)arg0->records98 + off + 0x14);
      }
      *((s32 *)(dest + 0x18)) = *((s32 *)(q + 8));
    }
  loop1C_inc:
    index_1C += 1;
  loop1C_test:
    if (index_1C < arg0->countAC)
    {
      goto loop1C_body;
    }
  }
  evtRefreshNodeResources(arg1);
  var_18 = 0;
  goto loopA_test;
loopA_body:
  evtResultSet(var_18, -1);
  var_18 += 1;
loopA_test:
  if (var_18 < 10)
  {
    goto loopA_body;
  }
  return 1;
}

