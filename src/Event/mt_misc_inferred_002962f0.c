#include "h_cdvd_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "sdk_snd_internal.h"
#include "evt_record_collection_internal.h"
#include "evt_effect_internal.h"
typedef char *va_list;
#define va_start(ap, last) (ap = (va_list)__builtin_args_info(2))
#define va_end(ap) ((void)0)
extern u8 *iGpffffb510;
extern s32 iGpffffa7c8;

s32 mtMiscResourceValue(s32 source);


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
extern u32 yTimeTrackAppendKey(s32 source, s32 eventWork, s32 nodeData, s32 recordCount,
                          s32, f32, s32, s32,
                          s32);
extern f32 fGpffff8204;
extern void mtMiscDrawSpriteAt(s32 source, f32, f32, f32,
                          f32, s32 eventWork, s32 nodeData);
extern char D_0063C8F0[];
extern char D_0063C910[];
extern void memcpy(void *source, void *eventWork, s32 nodeData);
extern s32 D_0076462C;
extern u8 iGpffffa7e8;

extern u8 *iGpffffb540;
extern u8 D_0063E810[];
extern u16 D_008C024E[];
extern s32 D_0063E830[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0029; members 002962f0-00296850 */

extern void mtMiscCollectType1Records(u8 *source);
extern void mtMiscCollectType2Records(u8 *source);
extern void mtMiscBuildSceneNodes(u8 *source);
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
/* measured: typing each remaining packed child store individually loses MATCH;
 * source loads are typed while those alias-sensitive stores retain their access shape. */
// FUN_002962F0
void mtMiscCollectType4Records(MtMiscSceneSource *source, u8 *eventWork)
{
  extern s32 evtMessageWindowRecordCount(s32 *source); /* lint: allow H011 -- the caller compares the count as signed (<= 0); the definition returns the same bits as u32 */
  extern u8 *evtNodeAlloc(s32 source, u8 *eventWork);
  extern u8 *evtNodeCreate(u8 *source, s32 eventWork, u8 *nodeData);
  s32 recordData;
  u8 *parentNode;
  s32 recordIndex;
  u16 recordId;
  u16 recordType;
  u16 recordFlags;
  u8 *childNode;
  u8 *sourceRecord;
  if (evtMessageWindowIsOpen((u32 *)(eventWork + 0x678)) != 1)
  {
    return;
  }
  if (evtMessageWindowRecordCount((s32 *)(eventWork + 0x678)) <= 0)
  {
    return;
  }
  parentNode = evtNodeAlloc(4, eventWork);
  recordIndex = 0;
  for (; recordIndex < source->countAC; recordIndex += 1) {
    if (source->header->kind == 4)
    {
      recordType = mtMiscSceneRecord16At(source, recordIndex)->type;
    }
    else
    {
      recordType = evtSceneRecordAt(source, recordIndex)->type;
    }
    if ((recordType & 0xFFFF) != 4)
    {
      continue;
    }
    if (source->header->kind == 4)
    {
      recordId = mtMiscSceneRecord16At(source, recordIndex)->id;
    }
    else
    {
      recordId = evtSceneRecordAt(source, recordIndex)->id;
    }
    {
      EvtRecordPosition positionCopy;
      EvtRecordPosition position;
      s16 *firstSetting;
      u8 *secondSettingSource;
      u8 *firstByteSource;
      u8 *secondByteSource;
      u8 *thirdByteSource;
      childNode = evtNodeCreate(parentNode, recordId & 0xFFFF, eventWork);
      recordData = recordIndex * 0x3C;
      sourceRecord = (u8 *)source->records98 + recordData;
      positionCopy = *(EvtRecordPosition *)((EvtSceneRecord *)sourceRecord)->position;
      position = positionCopy;
      *(EvtRecordPosition *)((EvtChildNode *)childNode)->unk08 = position;
      if (source->header->kind == 4)
      {
        recordFlags = mtMiscSceneRecord16At(source, recordIndex)->unk_04;
      }
      else
      {
        recordFlags = ((EvtSceneRecord *)((u8 *)source->records98 + recordData))->unk_04;
      }
      ((EvtChildNode *)childNode)->unk02 = recordFlags;
      if (source->header->kind == 4)
      {
        firstSetting = &mtMiscSceneRecord16At(source, recordIndex)->unk_08;
      }
      else
      {
        firstSetting = (s16 *)((u8 *)source->records98 + recordData + 0x14);
      }
      ((EvtRecordParameters *)&((EvtChildNode *)childNode)->payload)->unk00.halfword = *firstSetting;
      if (source->header->kind == 4)
      {
        secondSettingSource = (u8 *)&mtMiscSceneRecord16At(source, recordIndex)->unk_08;
      }
      else
      {
        secondSettingSource = (u8 *)((u8 *)source->records98 + recordData + 0x14);
      }
      *((s16 *)(childNode + 0x12)) = ((EvtRecordParameters *)secondSettingSource)->unk00.halves.second;
      if (source->header->kind == 4)
      {
        firstByteSource = (u8 *)&mtMiscSceneRecord16At(source, recordIndex)->unk_08;
      }
      else
      {
        firstByteSource = (u8 *)((u8 *)source->records98 + recordData + 0x14);
      }
      *((s8 *)(childNode + 0x14)) = ((EvtRecordParameters *)firstByteSource)->unk04.bytes.first;
      if (source->header->kind == 4)
      {
        secondByteSource = (u8 *)&mtMiscSceneRecord16At(source, recordIndex)->unk_08;
      }
      else
      {
        secondByteSource = (u8 *)((u8 *)source->records98 + recordData + 0x14);
      }
      *((s8 *)(childNode + 0x15)) = ((EvtRecordParameters *)secondByteSource)->unk04.bytes.second;
      if (source->header->kind == 4)
      {
        thirdByteSource = (u8 *)&mtMiscSceneRecord16At(source, recordIndex)->unk_08;
      }
      else
      {
        thirdByteSource = (u8 *)((u8 *)source->records98 + recordData + 0x14);
      }
      *((s8 *)(childNode + 0x16)) = ((EvtRecordParameters *)thirdByteSource)->unk04.bytes.third;
    }
  }
  return;
}

// Collects type-5 records (0x3C-byte entries from the list at +0xA4). The count
// comes from +0xAC when the list kind is below 6, else from +0xA8.
// FUN_00296600
void mtMiscCollectType5Records(MtMiscSceneSource *source, u8 *eventWork)
{
  extern u8 *evtNodeCreate();
  extern u8 *evtNodeAlloc(s32 source);
  s32 recordOffset;
  u8 *positionTarget;
  u8 *payloadTarget;
  s32 recordCount;
  u8 *parentNode;
  s32 index;
  s16 positionX;
  s16 positionY;
  s16 positionZ;
  s16 positionW;
  u16 recordId;
  u8 *childNode;
  u8 *recordData;
  u8 *recordCursor;
  parentNode = evtNodeAlloc(5);
  if ((source->header->kind) < 6)
  {
    recordCount = source->countAC;
  }
  else
  {
    recordCount = source->countA8;
  }
  index = 0;
  for (; index < recordCount; index += 1) {
    recordCursor = (u8 *)source->recordsA4;

    recordOffset = index * 0x3C;
    recordCursor += recordOffset;
    if ((((EvtSceneRecord *)recordCursor)->type) != 5)
    {
      continue;
    }
    childNode = evtNodeCreate((recordId = ((EvtSceneRecord *)recordCursor)->id, parentNode), recordId, eventWork);
    recordData = ((u8 *)source->recordsA4) + recordOffset;
    positionX = ((EvtSceneRecord *)recordData)->position[0];
    positionY = ((EvtSceneRecord *)recordData)->position[1];
    positionZ = ((EvtSceneRecord *)recordData)->position[2];
    positionW = ((EvtSceneRecord *)recordData)->position[3];
    positionTarget = childNode;
    ((EvtRecordPosition *)((EvtChildNode *)childNode)->unk08)->x = positionX;
    ((EvtRecordPosition *)((EvtChildNode *)positionTarget)->unk08)->y = positionY;
    ((EvtRecordPosition *)((EvtChildNode *)positionTarget)->unk08)->z = positionZ;
    ((EvtRecordPosition *)((EvtChildNode *)((0, positionTarget)))->unk08)->w = positionW;
    payloadTarget = positionTarget;
    recordData = ((u8 *)source->recordsA4) + recordOffset;
    ((EvtRecordParameters *)&((EvtChildNode *)payloadTarget)->payload)->unk00.halfword = ((EvtRecordParameters *)&((EvtSceneRecord *)recordData)->unk_14)->unk00.halfword;
    recordData = ((u8 *)source->recordsA4) + recordOffset;
    ((EvtRecordParameters *)&((EvtChildNode *)payloadTarget)->payload)->unk00.bytes.third = ((EvtRecordParameters *)&((EvtSceneRecord *)recordData)->unk_14)->unk00.bytes.third;
    }

  return;
}

// Type-19 counterpart of mtMiscCollectType5Records: same loop and count choice,
// matching record type 0x13 and copying the settings halfwords at +0x14 to +0x18.
// FUN_00296720
void mtMiscCollectType19Records(MtMiscSceneSource *source, u8 *eventWork)
{
  extern u8 *evtNodeCreate();
  extern u8 *evtNodeAlloc(s32 source);
  s32 recordOffset;
  u8 *positionTarget;
  u8 *payloadTarget;
  s32 recordCount;
  u8 *parentNode;
  s32 index;
  s16 positionX;
  s16 positionY;
  s16 positionZ;
  s16 positionW;
  s16 settingFirst;
  s16 settingSecond;
  s16 settingThird;
  u16 recordId;
  u8 *childNode;
  u8 *recordData;
  u8 *recordCursor;
  parentNode = evtNodeAlloc(0x13);
  if ((source->header->kind) < 6)
  {
    recordCount = source->countAC;
  }
  else
  {
    recordCount = source->countA8;
  }
  index = 0;
  for (; index < recordCount; index += 1) {
    recordCursor = (u8 *)source->recordsA4;
    recordOffset = index * 0x3C;
    recordCursor += recordOffset;
    if ((((EvtSceneRecord *)recordCursor)->type) != 0x13)
    {
      continue;
    }
    childNode = evtNodeCreate((recordId = ((EvtSceneRecord *)recordCursor)->id, parentNode),
                            recordId, eventWork);
    recordData = ((u8 *)source->recordsA4) + recordOffset;
    positionX = ((EvtSceneRecord *)recordData)->position[0];
    positionY = ((EvtSceneRecord *)recordData)->position[1];
    positionZ = ((EvtSceneRecord *)recordData)->position[2];
    positionW = ((EvtSceneRecord *)recordData)->position[3];
    positionTarget = childNode;
    ((EvtRecordPosition *)((EvtChildNode *)childNode)->unk08)->x = positionX;
    ((EvtRecordPosition *)((EvtChildNode *)positionTarget)->unk08)->y = positionY;
    ((EvtRecordPosition *)((EvtChildNode *)positionTarget)->unk08)->z = positionZ;
    ((EvtRecordPosition *)((EvtChildNode *)((0, positionTarget)))->unk08)->w = positionW;
    payloadTarget = positionTarget;
    recordData = ((u8 *)source->recordsA4) + recordOffset;
    settingFirst = ((EvtRecordParameters *)&((EvtSceneRecord *)recordData)->unk_14)->unk00.halfword;
    ((EvtRecordParameters *)&((EvtChildNode *)payloadTarget)->payload)->unk00.halfword = settingFirst;
    recordData = ((u8 *)source->recordsA4) + recordOffset;
    settingSecond = ((EvtRecordParameters *)&((EvtSceneRecord *)recordData)->unk_14)->unk00.halves.second;
    ((EvtRecordParameters *)&((EvtChildNode *)payloadTarget)->payload)->unk00.halves.second = settingSecond;
    recordData = ((u8 *)source->recordsA4) + recordOffset;
    settingThird = ((EvtRecordParameters *)&((EvtSceneRecord *)recordData)->unk_14)->unk04.halfword;
    ((EvtRecordParameters *)&((EvtChildNode *)payloadTarget)->payload)->unk04.halfword = settingThird;
    }

  return;
}

/* Each filtered scan owns its resource and index. With opt_lifetimes on,
 * those local scopes reproduce all 6312 retail code bytes; the 6320-byte
 * function window ends in eight zero alignment bytes. */
#pragma push
/* measured: func_00296850 MATCH -> MISMATCH without this pragma. */
#pragma opt_lifetimes on
// Build the event scene from source: fixed nodes, filtered record sets, header words, and per-entry nodes.
/* The +0xD0 header word has no member in the shared EvtEventWork layout.
 * measured: each other remaining raw access loses MATCH when typed independently;
 * keep those frame/list reloads and packed-payload aliases at their original sites. */
// FUN_00296850
s32 mtMiscBuildScene(MtMiscSceneSource *source, u8 *eventWork)
{
  extern void mtMiscBuildSceneNodes(u8 *source);
  extern void mtMiscCollectType1Records(u8 *source);
  extern void mtMiscCollectType2Records(u8 *source);
  extern void evtNodeLoadRecordsByCount(u8 *source, u8 *eventWork, u8 *nodeData, u16 recordCount);
  extern void evtNodeLoadRecords2F(u8 *source, u8 *eventWork);
  extern void evtNodeLoadCameraRecords(u8 *source, u8 *eventWork);
  extern void evtNodeLoadRecords24(u8 *source, u8 *eventWork);
  extern void evtNodeLoadRecords30(u8 *source, u8 *eventWork);
  extern void evtNodeLoadRecords34(u8 *source, u8 *eventWork);
  extern void evtNodeLoadRecords0A(u8 *source, u8 *eventWork);
  extern void mtMiscCollectType4Records(MtMiscSceneSource *source, u8 *eventWork);
  extern void mtMiscCollectType5Records(MtMiscSceneSource *source, u8 *eventWork);
  extern void mtMiscCollectType19Records(MtMiscSceneSource *source, u8 *eventWork);
  extern void evtRefreshNodeResources(u8 *source);
  extern void evtResultSet(s32 source, s32 eventWork);
  extern u8 *evtNodeAlloc(s32 source, u8 *eventWork);
  extern u8 *evtNodeCreate(u8 *source, s32 eventWork, u8 *nodeData);
  extern void func_00440b68(char *fmt, ...);
  extern char D_0063CB00[];
  extern char D_0063CB18[];
  s32 index;
  s32 recordIndex;
  u8 *waitNode;
  u8 *node;
  s32 headerWord;
  s32 *sourceWords;
  s32 *destinationWords;
  s32 wordsRemaining;
  s32 recordOffset;
  u8 *childNode;
  u8 *recordParameters;
  u16 recordType;
  u16 recordId;
  u16 recordFlags;

  func_00440b68(D_0063CB00);
  mtMiscBuildSceneNodes(eventWork);
  mtMiscCollectType1Records(eventWork);
  mtMiscCollectType2Records(eventWork);
  index = 0;
  while (index < source->count58) {
      evtNodeAlloc(0x18, eventWork);
      index += 1;
  }

  func_00440b68(D_0063CB18);
  if (source->headerWords != NULL) {
    ((EvtEventWork *)eventWork)->frameCount = source->headerWords[2];
    ((EvtEventWork *)eventWork)->startFrame = source->headerWords[0];
    ((EvtEventWork *)eventWork)->frameLimit = source->headerWords[1];
    *((s32 *)(eventWork + 0xD0)) = source->headerWords[3];
    sourceWords = source->headerWords;
    destinationWords = (s32 *)(eventWork + 0x24);
    wordsRemaining = 9;
    do {
      headerWord = *sourceWords;
      sourceWords += 1;
      wordsRemaining -= 1;
      *destinationWords = headerWord;
      destinationWords += 1;
    } while (wordsRemaining > 0);
    ((EvtEventWork *)eventWork)->frame = *((s32 *)(eventWork + 0xC));
    ((EvtEventWork *)eventWork)->lastFrame = -1;
    if (((EvtEventWork *)eventWork)->frame < 0) {
      *((s32 *)(eventWork + 0x14)) = 0;
    }
    headerWord = *((s32 *)(eventWork + 8)) - 1;
    if (headerWord < *((s32 *)(eventWork + 0x14))) {
      *((s32 *)(eventWork + 0x14)) = headerWord;
    }
  }
  node = (u8 *)((EvtEventWork *)eventWork)->nodeList;
  while (node != NULL) {
      evtNodeLoadRecordsByCount((u8 *)source, eventWork, node, ((EvtNode *)node)->flags);
      node = *((u8 **)(node + 0x90));
  }

  evtNodeLoadRecords2F((u8 *)source, eventWork);
  {
    u8 *enableParent;
    s32 enableIndex;
    enableParent = evtNodeAlloc(0x31, eventWork);
    enableIndex = 0;
    for (; enableIndex < source->countAC; enableIndex += 1) {
      if (source->header->kind == 4)
      {
        recordType = mtMiscSceneRecord16At(source, enableIndex)->type;
      }
      else
      {
        recordType = evtSceneRecordAt(source, enableIndex)->type;
      }
      if ((recordType & 0xFFFF) != 0x31)
      {
        continue;
      }
      if (source->header->kind == 4)
      {
        recordId = mtMiscSceneRecord16At(source, enableIndex)->id;
      }
      else
      {
        recordId = evtSceneRecordAt(source, enableIndex)->id;
      }
      {
        EvtRecordPosition positionCopy;
        EvtRecordPosition position;
        childNode = evtNodeCreate(enableParent, recordId & 0xFFFF, eventWork);
        recordOffset = enableIndex * 0x3C;
        recordParameters = (u8 *)source->records98 + recordOffset;
        positionCopy = *(EvtRecordPosition *)((EvtSceneRecord *)recordParameters)->position;
        position = positionCopy;
        *(EvtRecordPosition *)((EvtChildNode *)childNode)->unk08 = position;
        if (source->header->kind == 4)
        {
          recordParameters = (u8 *)&mtMiscSceneRecord16At(source, enableIndex)->unk_08;
        }
        else
        {
          recordParameters = (u8 *)((u8 *)source->records98 + recordOffset + 0x14);
        }
        ((EvtRecordParameters *)&((EvtChildNode *)childNode)->payload)->unk00.word = ((EvtRecordParameters *)recordParameters)->unk00.word;
        if (source->header->kind == 4)
        {
          recordParameters = (u8 *)&mtMiscSceneRecord16At(source, enableIndex)->unk_08;
        }
        else
        {
          recordParameters = (u8 *)((u8 *)source->records98 + recordOffset + 0x14);
        }
        *((s32 *)(childNode + 0x14)) = ((EvtRecordParameters *)recordParameters)->unk04.word;
      }
      }
  }
  evtNodeLoadCameraRecords((u8 *)source, eventWork);
  waitNode = evtNodeAlloc(0x22, eventWork);
  ((EvtNode *)waitNode)->unk08 = -1;
  ((EvtNode *)waitNode)->res = 0;
  recordIndex = 0;
  for (; recordIndex < source->countAC; recordIndex += 1) {
    if (source->header->kind == 4)
    {
      recordType = mtMiscSceneRecord16At(source, recordIndex)->type;
    }
    else
    {
      recordType = evtSceneRecordAt(source, recordIndex)->type;
    }
    if ((recordType & 0xFFFF) != 0x22)
    {
      continue;
    }
    if (source->header->kind == 4)
    {
      recordId = mtMiscSceneRecord16At(source, recordIndex)->id;
    }
    else
    {
      recordId = evtSceneRecordAt(source, recordIndex)->id;
    }
    {
      EvtRecordPosition positionCopy;
      EvtRecordPosition position;
      childNode = evtNodeCreate(waitNode, recordId & 0xFFFF, eventWork);
      recordOffset = recordIndex * 0x3C;
      recordParameters = (u8 *)source->records98 + recordOffset;
      positionCopy = *(EvtRecordPosition *)((EvtSceneRecord *)recordParameters)->position;
      position = positionCopy;
      *(EvtRecordPosition *)((EvtChildNode *)childNode)->unk08 = position;
    }
  }
  evtNodeLoadRecords24((u8 *)source, eventWork);
  if (((EvtEffectTable *)((EvtEventWork *)eventWork)->effectTable)->count > 0) {
    {
      u8 *placementParent;
      s32 placementIndex;
      placementParent = evtNodeAlloc(0x25, eventWork);
      placementIndex = 0;
      for (; placementIndex < source->countAC; placementIndex += 1) {
        if (source->header->kind == 4)
        {
          recordType = mtMiscSceneRecord16At(source, placementIndex)->type;
        }
        else
        {
          recordType = evtSceneRecordAt(source, placementIndex)->type;
        }
        if ((recordType & 0xFFFF) != 0x25)
        {
          continue;
        }
        if (source->header->kind == 4)
        {
          recordId = mtMiscSceneRecord16At(source, placementIndex)->id;
        }
        else
        {
          recordId = evtSceneRecordAt(source, placementIndex)->id;
        }
        {
          EvtRecordPosition positionCopy;
          EvtRecordPosition position;
          childNode = evtNodeCreate(placementParent, recordId & 0xFFFF, eventWork);
          recordOffset = placementIndex * 0x3C;
          recordParameters = (u8 *)source->records98 + recordOffset;
          positionCopy = *(EvtRecordPosition *)((EvtSceneRecord *)recordParameters)->position;
          position = positionCopy;
          *(EvtRecordPosition *)((EvtChildNode *)childNode)->unk08 = position;
          if (source->header->kind == 4)
          {
            recordParameters = (u8 *)&mtMiscSceneRecord16At(source, placementIndex)->unk_08;
          }
          else
          {
            recordParameters = (u8 *)((u8 *)source->records98 + recordOffset + 0x14);
          }
          memcpy(childNode + 0x10, recordParameters, 0x28);
        }
        }
    }
  }
  {
    u8 *choiceParent;
    s32 choiceIndex;
    choiceParent = evtNodeAlloc(0x26, eventWork);
    choiceIndex = 0;
    for (; choiceIndex < source->countAC; choiceIndex += 1) {
      if (source->header->kind == 4)
      {
        recordType = mtMiscSceneRecord16At(source, choiceIndex)->type;
      }
      else
      {
        recordType = evtSceneRecordAt(source, choiceIndex)->type;
      }
      if ((recordType & 0xFFFF) != 0x26)
      {
        continue;
      }
      if (source->header->kind == 4)
      {
        recordId = mtMiscSceneRecord16At(source, choiceIndex)->id;
      }
      else
      {
        recordId = evtSceneRecordAt(source, choiceIndex)->id;
      }
      {
        EvtRecordPosition positionCopy;
        EvtRecordPosition position;
        childNode = evtNodeCreate(choiceParent, recordId & 0xFFFF, eventWork);
        recordOffset = choiceIndex * 0x3C;
        recordParameters = (u8 *)source->records98 + recordOffset;
        positionCopy = *(EvtRecordPosition *)((EvtSceneRecord *)recordParameters)->position;
        position = positionCopy;
        *(EvtRecordPosition *)((EvtChildNode *)childNode)->unk08 = position;
        if (source->header->kind == 4)
        {
          recordParameters = (u8 *)&mtMiscSceneRecord16At(source, choiceIndex)->unk_08;
        }
        else
        {
          recordParameters = (u8 *)((u8 *)source->records98 + recordOffset + 0x14);
        }
        ((EvtRecordParameters *)&((EvtChildNode *)childNode)->payload)->unk00.word = ((EvtRecordParameters *)recordParameters)->unk00.word;
        if (source->header->kind == 4)
        {
          recordParameters = (u8 *)&mtMiscSceneRecord16At(source, choiceIndex)->unk_08;
        }
        else
        {
          recordParameters = (u8 *)((u8 *)source->records98 + recordOffset + 0x14);
        }
        *((f32 *)(childNode + 0x14)) = ((EvtRecordParameters *)recordParameters)->unk04.scalar;
      }
      }
  }
  evtNodeLoadRecords30((u8 *)source, eventWork);
  {
    u8 *streamParent;
    s32 streamIndex;
    streamParent = evtNodeAlloc(0x32, eventWork);
    streamIndex = 0;
    for (; streamIndex < source->countAC; streamIndex += 1) {
      if (source->header->kind == 4)
      {
        recordType = mtMiscSceneRecord16At(source, streamIndex)->type;
      }
      else
      {
        recordType = evtSceneRecordAt(source, streamIndex)->type;
      }
      if ((recordType & 0xFFFF) != 0x32)
      {
        continue;
      }
      if (source->header->kind == 4)
      {
        recordId = mtMiscSceneRecord16At(source, streamIndex)->id;
      }
      else
      {
        recordId = evtSceneRecordAt(source, streamIndex)->id;
      }
      {
        EvtRecordPosition positionCopy;
        EvtRecordPosition position;
        childNode = evtNodeCreate(streamParent, recordId & 0xFFFF, eventWork);
        recordOffset = streamIndex * 0x3C;
        recordParameters = (u8 *)source->records98 + recordOffset;
        positionCopy = *(EvtRecordPosition *)((EvtSceneRecord *)recordParameters)->position;
        position = positionCopy;
        *(EvtRecordPosition *)((EvtChildNode *)childNode)->unk08 = position;
        if (source->header->kind == 4)
        {
          recordParameters = (u8 *)&mtMiscSceneRecord16At(source, streamIndex)->unk_08;
        }
        else
        {
          recordParameters = (u8 *)((u8 *)source->records98 + recordOffset + 0x14);
        }
        ((EvtRecordParameters *)&((EvtChildNode *)childNode)->payload)->unk00.word = ((EvtRecordParameters *)recordParameters)->unk00.word;
      }
      }
  }
  {
    u8 *labelParent;
    s32 labelIndex;
    labelParent = evtNodeAlloc(0x33, eventWork);
    labelIndex = 0;
    for (; labelIndex < source->countAC; labelIndex += 1) {
      if (source->header->kind == 4)
      {
        recordType = mtMiscSceneRecord16At(source, labelIndex)->type;
      }
      else
      {
        recordType = evtSceneRecordAt(source, labelIndex)->type;
      }
      if ((recordType & 0xFFFF) != 0x33)
      {
        continue;
      }
      if (source->header->kind == 4)
      {
        recordId = mtMiscSceneRecord16At(source, labelIndex)->id;
      }
      else
      {
        recordId = evtSceneRecordAt(source, labelIndex)->id;
      }
      {
        EvtRecordPosition positionCopy;
        EvtRecordPosition position;
        childNode = evtNodeCreate(labelParent, recordId & 0xFFFF, eventWork);
        recordOffset = labelIndex * 0x3C;
        recordParameters = (u8 *)source->records98 + recordOffset;
        positionCopy = *(EvtRecordPosition *)((EvtSceneRecord *)recordParameters)->position;
        position = positionCopy;
        *(EvtRecordPosition *)((EvtChildNode *)childNode)->unk08 = position;
        if (source->header->kind == 4)
        {
          recordParameters = (u8 *)&mtMiscSceneRecord16At(source, labelIndex)->unk_08;
        }
        else
        {
          recordParameters = (u8 *)((u8 *)source->records98 + recordOffset + 0x14);
        }
        memcpy(childNode + 0x10, recordParameters, 0x28);
      }
      }
  }
  evtNodeLoadRecords34((u8 *)source, eventWork);
  {
    u8 *environmentParent;
    s32 environmentIndex;
    environmentParent = evtNodeAlloc(0x35, eventWork);
    environmentIndex = 0;
    for (; environmentIndex < source->countAC; environmentIndex += 1) {
      if (source->header->kind == 4)
      {
        recordType = mtMiscSceneRecord16At(source, environmentIndex)->type;
      }
      else
      {
        recordType = evtSceneRecordAt(source, environmentIndex)->type;
      }
      if ((recordType & 0xFFFF) != 0x35)
      {
        continue;
      }
      if (source->header->kind == 4)
      {
        recordId = mtMiscSceneRecord16At(source, environmentIndex)->id;
      }
      else
      {
        recordId = evtSceneRecordAt(source, environmentIndex)->id;
      }
      {
        EvtRecordPosition positionCopy;
        EvtRecordPosition position;
        childNode = evtNodeCreate(environmentParent, recordId & 0xFFFF, eventWork);
        recordOffset = environmentIndex * 0x3C;
        recordParameters = (u8 *)source->records98 + recordOffset;
        positionCopy = *(EvtRecordPosition *)((EvtSceneRecord *)recordParameters)->position;
        position = positionCopy;
        *(EvtRecordPosition *)((EvtChildNode *)childNode)->unk08 = position;
        if (source->header->kind == 4)
        {
          recordFlags = mtMiscSceneRecord16At(source, environmentIndex)->unk_04;
        }
        else
        {
          recordFlags = ((EvtSceneRecord *)((u8 *)source->records98 + recordOffset))->unk_04;
        }
        ((EvtChildNode *)childNode)->unk02 = recordFlags;
        if (source->header->kind == 4)
        {
          recordParameters = (u8 *)&mtMiscSceneRecord16At(source, environmentIndex)->unk_08;
        }
        else
        {
          recordParameters = (u8 *)((u8 *)source->records98 + recordOffset + 0x14);
        }
        memcpy(childNode + 0x10, recordParameters, 0x28);
      }
      }
  }
  {
    u8 *screenColorParent;
    s32 screenColorIndex;
    screenColorParent = evtNodeAlloc(0x37, eventWork);
    screenColorIndex = 0;
    for (; screenColorIndex < source->countAC; screenColorIndex += 1) {
      if (source->header->kind == 4)
      {
        recordType = mtMiscSceneRecord16At(source, screenColorIndex)->type;
      }
      else
      {
        recordType = evtSceneRecordAt(source, screenColorIndex)->type;
      }
      if ((recordType & 0xFFFF) != 0x37)
      {
        continue;
      }
      if (source->header->kind == 4)
      {
        recordId = mtMiscSceneRecord16At(source, screenColorIndex)->id;
      }
      else
      {
        recordId = evtSceneRecordAt(source, screenColorIndex)->id;
      }
      {
        EvtRecordPosition positionCopy;
        EvtRecordPosition position;
        childNode = evtNodeCreate(screenColorParent, recordId & 0xFFFF, eventWork);
        recordOffset = screenColorIndex * 0x3C;
        recordParameters = (u8 *)source->records98 + recordOffset;
        positionCopy = *(EvtRecordPosition *)((EvtSceneRecord *)recordParameters)->position;
        position = positionCopy;
        *(EvtRecordPosition *)((EvtChildNode *)childNode)->unk08 = position;
        if (source->header->kind == 4)
        {
          recordFlags = mtMiscSceneRecord16At(source, screenColorIndex)->unk_04;
        }
        else
        {
          recordFlags = ((EvtSceneRecord *)((u8 *)source->records98 + recordOffset))->unk_04;
        }
        ((EvtChildNode *)childNode)->unk02 = recordFlags;
        if (source->header->kind == 4)
        {
          recordParameters = (u8 *)&mtMiscSceneRecord16At(source, screenColorIndex)->unk_08;
        }
        else
        {
          recordParameters = (u8 *)((u8 *)source->records98 + recordOffset + 0x14);
        }
        memcpy(childNode + 0x10, recordParameters, 0x28);
      }
      }
  }
  {
    u8 *taskHandleParent;
    s32 taskHandleIndex;
    taskHandleParent = evtNodeAlloc(0x38, eventWork);
    taskHandleIndex = 0;
    for (; taskHandleIndex < source->countAC; taskHandleIndex += 1) {
      if (source->header->kind == 4)
      {
        recordType = mtMiscSceneRecord16At(source, taskHandleIndex)->type;
      }
      else
      {
        recordType = evtSceneRecordAt(source, taskHandleIndex)->type;
      }
      if ((recordType & 0xFFFF) != 0x38)
      {
        continue;
      }
      if (source->header->kind == 4)
      {
        recordId = mtMiscSceneRecord16At(source, taskHandleIndex)->id;
      }
      else
      {
        recordId = evtSceneRecordAt(source, taskHandleIndex)->id;
      }
      {
        EvtRecordPosition positionCopy;
        EvtRecordPosition position;
        childNode = evtNodeCreate(taskHandleParent, recordId & 0xFFFF, eventWork);
        recordOffset = taskHandleIndex * 0x3C;
        recordParameters = (u8 *)source->records98 + recordOffset;
        positionCopy = *(EvtRecordPosition *)((EvtSceneRecord *)recordParameters)->position;
        position = positionCopy;
        *(EvtRecordPosition *)((EvtChildNode *)childNode)->unk08 = position;
        if (source->header->kind == 4)
        {
          recordFlags = mtMiscSceneRecord16At(source, taskHandleIndex)->unk_04;
        }
        else
        {
          recordFlags = ((EvtSceneRecord *)((u8 *)source->records98 + recordOffset))->unk_04;
        }
        ((EvtChildNode *)childNode)->unk02 = recordFlags;
        if (source->header->kind == 4)
        {
          recordParameters = (u8 *)&mtMiscSceneRecord16At(source, taskHandleIndex)->unk_08;
        }
        else
        {
          recordParameters = (u8 *)((u8 *)source->records98 + recordOffset + 0x14);
        }
        memcpy(childNode + 0x10, recordParameters, 0x28);
      }
      }
  }
  {
    u8 *cameraPositionParent;
    s32 cameraPositionIndex;
    cameraPositionParent = evtNodeAlloc(0x39, eventWork);
    cameraPositionIndex = 0;
    for (; cameraPositionIndex < source->countAC; cameraPositionIndex += 1) {
      if (source->header->kind == 4)
      {
        recordType = mtMiscSceneRecord16At(source, cameraPositionIndex)->type;
      }
      else
      {
        recordType = evtSceneRecordAt(source, cameraPositionIndex)->type;
      }
      if ((recordType & 0xFFFF) != 0x39)
      {
        continue;
      }
      if (source->header->kind == 4)
      {
        recordId = mtMiscSceneRecord16At(source, cameraPositionIndex)->id;
      }
      else
      {
        recordId = evtSceneRecordAt(source, cameraPositionIndex)->id;
      }
      {
        EvtRecordPosition positionCopy;
        EvtRecordPosition position;
        childNode = evtNodeCreate(cameraPositionParent, recordId & 0xFFFF, eventWork);
        recordOffset = cameraPositionIndex * 0x3C;
        recordParameters = (u8 *)source->records98 + recordOffset;
        positionCopy = *(EvtRecordPosition *)((EvtSceneRecord *)recordParameters)->position;
        position = positionCopy;
        *(EvtRecordPosition *)((EvtChildNode *)childNode)->unk08 = position;
        if (source->header->kind == 4)
        {
          recordFlags = mtMiscSceneRecord16At(source, cameraPositionIndex)->unk_04;
        }
        else
        {
          recordFlags = ((EvtSceneRecord *)((u8 *)source->records98 + recordOffset))->unk_04;
        }
        ((EvtChildNode *)childNode)->unk02 = recordFlags;
        if (source->header->kind == 4)
        {
          recordParameters = (u8 *)&mtMiscSceneRecord16At(source, cameraPositionIndex)->unk_08;
        }
        else
        {
          recordParameters = (u8 *)((u8 *)source->records98 + recordOffset + 0x14);
        }
        memcpy(childNode + 0x10, recordParameters, 0x28);
      }
      }
  }
  evtNodeLoadRecords0A((u8 *)source, eventWork);
  mtMiscCollectType4Records(source, eventWork);
  mtMiscCollectType5Records(source, eventWork);
  {
    u8 *soundTrackParent;
    s32 soundTrackIndex;
    soundTrackParent = evtNodeAlloc(0x36, eventWork);
    soundTrackIndex = 0;
    for (; soundTrackIndex < source->countAC; soundTrackIndex += 1) {
      if (source->header->kind == 4)
      {
        recordType = mtMiscSceneRecord16At(source, soundTrackIndex)->type;
      }
      else
      {
        recordType = evtSceneRecordAt(source, soundTrackIndex)->type;
      }
      if ((recordType & 0xFFFF) != 0x36)
      {
        continue;
      }
      if (source->header->kind == 4)
      {
        recordId = mtMiscSceneRecord16At(source, soundTrackIndex)->id;
      }
      else
      {
        recordId = evtSceneRecordAt(source, soundTrackIndex)->id;
      }
      {
        EvtRecordPosition positionCopy;
        EvtRecordPosition position;
        childNode = evtNodeCreate(soundTrackParent, recordId & 0xFFFF, eventWork);
        recordOffset = soundTrackIndex * 0x3C;
        recordParameters = (u8 *)source->records98 + recordOffset;
        positionCopy = *(EvtRecordPosition *)((EvtSceneRecord *)recordParameters)->position;
        position = positionCopy;
        *(EvtRecordPosition *)((EvtChildNode *)childNode)->unk08 = position;
        if (source->header->kind == 4)
        {
          recordParameters = (u8 *)&mtMiscSceneRecord16At(source, soundTrackIndex)->unk_08;
        }
        else
        {
          recordParameters = (u8 *)((u8 *)source->records98 + recordOffset + 0x14);
        }
        memcpy(childNode + 0x10, recordParameters, 0x28);
      }
      }
  }
  mtMiscCollectType19Records(source, eventWork);
  {
    u8 *commandParent;
    s32 commandIndex;
    commandParent = evtNodeAlloc(6, eventWork);
    commandIndex = 0;
    for (; commandIndex < source->countAC; commandIndex += 1) {
      if (source->header->kind == 4)
      {
        recordType = mtMiscSceneRecord16At(source, commandIndex)->type;
      }
      else
      {
        recordType = evtSceneRecordAt(source, commandIndex)->type;
      }
      if ((recordType & 0xFFFF) != 6)
      {
        continue;
      }
      if (source->header->kind == 4)
      {
        recordId = mtMiscSceneRecord16At(source, commandIndex)->id;
      }
      else
      {
        recordId = evtSceneRecordAt(source, commandIndex)->id;
      }
      {
        EvtRecordPosition positionCopy;
        EvtRecordPosition position;
        childNode = evtNodeCreate(commandParent, recordId & 0xFFFF, eventWork);
        recordOffset = commandIndex * 0x3C;
        recordParameters = (u8 *)source->records98 + recordOffset;
        positionCopy = *(EvtRecordPosition *)((EvtSceneRecord *)recordParameters)->position;
        position = positionCopy;
        *(EvtRecordPosition *)((EvtChildNode *)childNode)->unk08 = position;
        if (source->header->kind == 4)
        {
          recordFlags = mtMiscSceneRecord16At(source, commandIndex)->unk_04;
        }
        else
        {
          recordFlags = ((EvtSceneRecord *)((u8 *)source->records98 + recordOffset))->unk_04;
        }
        ((EvtChildNode *)childNode)->unk02 = recordFlags;
        if (source->header->kind == 4)
        {
          recordParameters = (u8 *)&mtMiscSceneRecord16At(source, commandIndex)->unk_08;
        }
        else
        {
          recordParameters = (u8 *)((u8 *)source->records98 + recordOffset + 0x14);
        }
        memcpy(childNode + 0x10, recordParameters, 0x28);
        if (((EvtRecordParameters *)&((EvtChildNode *)childNode)->payload)->unk00.halves.second == -1) {
          *((s16 *)(childNode + 0x12)) = 0;
        }
      }
      }
  }
  {
    u8 *rangeFlagParent;
    s32 rangeFlagIndex;
    rangeFlagParent = evtNodeAlloc(7, eventWork);
    rangeFlagIndex = 0;
    for (; rangeFlagIndex < source->countAC; rangeFlagIndex += 1) {
      if (source->header->kind == 4)
      {
        recordType = mtMiscSceneRecord16At(source, rangeFlagIndex)->type;
      }
      else
      {
        recordType = evtSceneRecordAt(source, rangeFlagIndex)->type;
      }
      if ((recordType & 0xFFFF) != 7)
      {
        continue;
      }
      if (source->header->kind == 4)
      {
        recordId = mtMiscSceneRecord16At(source, rangeFlagIndex)->id;
      }
      else
      {
        recordId = evtSceneRecordAt(source, rangeFlagIndex)->id;
      }
      {
        EvtRecordPosition positionCopy;
        EvtRecordPosition position;
        childNode = evtNodeCreate(rangeFlagParent, recordId & 0xFFFF, eventWork);
        recordOffset = rangeFlagIndex * 0x3C;
        recordParameters = (u8 *)source->records98 + recordOffset;
        positionCopy = *(EvtRecordPosition *)((EvtSceneRecord *)recordParameters)->position;
        position = positionCopy;
        *(EvtRecordPosition *)((EvtChildNode *)childNode)->unk08 = position;
        if (source->header->kind == 4)
        {
          recordFlags = mtMiscSceneRecord16At(source, rangeFlagIndex)->unk_04;
        }
        else
        {
          recordFlags = ((EvtSceneRecord *)((u8 *)source->records98 + recordOffset))->unk_04;
        }
        ((EvtChildNode *)childNode)->unk02 = recordFlags;
        if (source->header->kind == 4)
        {
          recordParameters = (u8 *)&mtMiscSceneRecord16At(source, rangeFlagIndex)->unk_08;
        }
        else
        {
          recordParameters = (u8 *)((u8 *)source->records98 + recordOffset + 0x14);
        }
        ((EvtRecordParameters *)&((EvtChildNode *)childNode)->payload)->unk00.halfword = ((EvtRecordParameters *)recordParameters)->unk00.halfword;
      }
      }
  }
  {
    u8 *drawParent;
    s32 drawIndex;
    drawParent = evtNodeAlloc(0x1C, eventWork);
    drawIndex = 0;
    for (; drawIndex < source->countAC; drawIndex += 1) {
      if (source->header->kind == 4)
      {
        recordType = mtMiscSceneRecord16At(source, drawIndex)->type;
      }
      else
      {
        recordType = evtSceneRecordAt(source, drawIndex)->type;
      }
      if ((recordType & 0xFFFF) != 0x1C)
      {
        continue;
      }
      if (source->header->kind == 4)
      {
        recordId = mtMiscSceneRecord16At(source, drawIndex)->id;
      }
      else
      {
        recordId = evtSceneRecordAt(source, drawIndex)->id;
      }
      {
        EvtRecordPosition positionCopy;
        EvtRecordPosition position;
        childNode = evtNodeCreate(drawParent, recordId & 0xFFFF, eventWork);
        recordOffset = drawIndex * 0x3C;
        recordParameters = (u8 *)source->records98 + recordOffset;
        positionCopy = *(EvtRecordPosition *)((EvtSceneRecord *)recordParameters)->position;
        position = positionCopy;
        *(EvtRecordPosition *)((EvtChildNode *)childNode)->unk08 = position;
        if (source->header->kind == 4)
        {
          recordFlags = mtMiscSceneRecord16At(source, drawIndex)->unk_04;
        }
        else
        {
          recordFlags = ((EvtSceneRecord *)((u8 *)source->records98 + recordOffset))->unk_04;
        }
        ((EvtChildNode *)childNode)->unk02 = recordFlags;
        if (source->header->kind == 4)
        {
          recordParameters = (u8 *)&mtMiscSceneRecord16At(source, drawIndex)->unk_08;
        }
        else
        {
          recordParameters = (u8 *)((u8 *)source->records98 + recordOffset + 0x14);
        }
        ((EvtRecordParameters *)&((EvtChildNode *)childNode)->payload)->unk00.word = ((EvtRecordParameters *)recordParameters)->unk00.word;
        if (source->header->kind == 4)
        {
          recordParameters = (u8 *)&mtMiscSceneRecord16At(source, drawIndex)->unk_08;
        }
        else
        {
          recordParameters = (u8 *)((u8 *)source->records98 + recordOffset + 0x14);
        }
        *((s32 *)(childNode + 0x14)) = ((EvtRecordParameters *)recordParameters)->unk04.word;
        if (source->header->kind == 4)
        {
          recordParameters = (u8 *)&mtMiscSceneRecord16At(source, drawIndex)->unk_08;
        }
        else
        {
          recordParameters = (u8 *)((u8 *)source->records98 + recordOffset + 0x14);
        }
        *((s32 *)(childNode + 0x18)) = ((EvtRecordParameters *)recordParameters)->unk08.word;
      }
      }
  }
  evtRefreshNodeResources(eventWork);
  index = 0;
  while (index < 10) {
      evtResultSet(index, -1);
      index += 1;
  }

  return 1;
}
/* Restore the scoped lifetime analysis after the scene builder. */
#pragma pop

