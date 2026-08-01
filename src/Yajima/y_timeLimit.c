/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_002A2780)
/* Source unit: src/Yajima/y_timeLimit_002a2780.c */
#include "type.h"

// FUN_002A2780
u8 func_002A2780(int param_1)

{
  if (param_1 != 0) goto clear;
  return 1;
clear:
  *(u32 *)(param_1 + 0x80) = 0;
  *(u32 *)(param_1 + 0x84) = 0;
  *(u32 *)(param_1 + 0x88) = 0;
  *(u32 *)(param_1 + 0x8c) = 0;
  *(u32 *)(param_1 + 0x90) = 0;
  *(u32 *)(param_1 + 0x94) = 0;
  return 0;
}
#endif /* P4_UNIT_002A2780 */

#if defined(P4_UNIT_002A27C0)
/* Source unit: src/Yajima/y_timeLimit_002a27c0.c */
#include "type.h"

// FUN_002A27C0
u32
func_002A27C0(float param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            u8 param_7,u8 param_8,short param_9)
{
  struct TweenEntry {
    float startX;
    float startY;
    float endX;
    float endY;
    float stepX;
    float stepY;
    float rate;
    s8 delay;
    s8 hold;
    s16 duration;
  };
  struct TweenState {
    struct TweenEntry entries[4];
    s32 current;
    s32 count;
    s32 frame;
    u32 flags;
    s32 timer;
    s32 total;
  };
  struct TweenState *state;
  struct TweenEntry *entry;
  float duration;

  if (param_2 == 0) {
    return 1;
  }
  state = (struct TweenState *)param_2;
  if (state->count >= 4) {
    return 2;
  }
  entry = &state->entries[state->count];
  entry->duration = param_9;
  if (entry->duration < 1) {
    entry->duration = 1;
  }
  duration = (float)entry->duration;
  entry->startX = (float)param_3;
  entry->startY = (float)param_4;
  entry->endX = (float)param_5;
  entry->endY = (float)param_6;
  entry->rate = param_1;
  if (param_1 > 0.0f) {
    entry->stepX = param_1 * (entry->endX - entry->startX);
    entry->stepY = entry->rate * (entry->endY - entry->startY);
  }
  else if (param_1 < 0.0f) {
    entry->stepX = entry->startX;
    entry->stepY = entry->startY;
  }
  else {
    entry->stepX = (entry->endX - entry->startX) / duration;
    entry->stepY = (entry->endY - entry->startY) / duration;
  }
  entry->delay = param_7;
  entry->hold = param_8;
  if (entry->delay < 0) {
    entry->delay = 0;
  }
  if (entry->hold < 0) {
    entry->hold = 0;
  }
  state->current = 0;
  state->count = state->count + 1;
  state->frame = 0;
  state->timer = 0;
  state->total += entry->duration + entry->delay + entry->hold;
  state->flags |= 1;
  state->flags &= 0xfffffffd;
  return 0;
}
#endif /* P4_UNIT_002A27C0 */

#if defined(P4_UNIT_002A2C10)
/* Source unit: src/Yajima/y_timeLimit_002a2c10.c */
#include "type.h"

// FUN_002A2C10
u32 func_002A2C10(int param_1,float *param_2)
{
  struct Pair2 { float x; float y; };
  struct Pair2 *puVar1;
  struct Pair2 *puVar2;

  if ((param_1 == 0) || (param_2 == (float *)0)) {
    return 1;
  }
  if (*(int *)(param_1 + 0x84) < 1) {
    return 2;
  }
  puVar1 = (struct Pair2 *)(param_1 + (*(int *)(param_1 + 0x80) << 5));
  puVar2 = (struct Pair2 *)param_2;
  *puVar2 = *puVar1;
  return 0;
}
#endif /* P4_UNIT_002A2C10 */

#if defined(P4_UNIT_002A2C70)
/* Source unit: src/Yajima/y_timeLimit_002a2c70.c */
#include "type.h"

// FUN_002A2C70
int func_002A2C70(int param_1)

{
  int bVar1;

  if (param_1 == 0) {
    bVar1 = 0;
  }
  else {
    bVar1 = !((*(u32 *)((int)param_1 + 0x8c) & 2) > 0);
  }
  return bVar1;
}
#endif /* P4_UNIT_002A2C70 */

#if defined(P4_UNIT_002A2CA0)
/* Source unit: src/Yajima/y_timeLimit_002a2ca0.c */
#include "type.h"

// FUN_002A2CA0
int func_002A2CA0(int param_1)

{
  int bVar1;

  if (param_1 == 0) {
    bVar1 = 1;
  }
  else {
    bVar1 = !((*(u32 *)((int)param_1 + 0x8c) & 1) > 0);
  }
  return bVar1;
}
#endif /* P4_UNIT_002A2CA0 */

#if defined(P4_UNIT_002A2CD0)
/* Source unit: src/Yajima/y_timeLimit_002a2cd0.c */
#include "type.h"

// FUN_002A2CD0
float func_002A2CD0(int param_1)
{
  int flags;
  int total;
  int start;
  int tableOffset;
  int endOffset;
  int current;
  int numerator;
  int denominator;
  float progress;

  if (param_1 == 0) {
    return 0.0f;
  }
  flags = *(u32 *)(param_1 + 0x8c);
  if ((flags & 2) != 0) {
    return 1.0f;
  }
  if ((flags & 1) == 0) {
    return 0.0f;
  }
  total = *(int *)(param_1 + 0x94);
  if (total < 1) {
    return 0.0f;
  }
  start = *(char *)(param_1 + 0x1c);
  tableOffset = *(int *)(param_1 + 0x84) * 0x20;
  endOffset = *(char *)(tableOffset + param_1 - 3);
  current = *(int *)(param_1 + 0x90);
  if (current < start) {
    return 0.0f;
  }
  if (current >= total - endOffset) {
    return 1.0f;
  }
  numerator = current - start;
  denominator = total - start - endOffset;
  if ((numerator < 1) || (denominator < 1)) {
    return 0.0f;
  }
  progress = (float)numerator / (float)denominator;
  if (progress < 0.0f) {
    progress = 0.0f;
  }
  else if (progress > 1.0f) {
    progress = 1.0f;
  }
  return progress;
}
#endif /* P4_UNIT_002A2CD0 */

#if defined(P4_UNIT_002A2340)
/* Source unit: src/Yajima/y_timeLimit_002a2340.c */
#include "type.h"

extern u32 D_00882F08[];
extern u32 D_00882F0C[];
extern u32 D_00882F10[];
extern u32 D_00764630;
extern u8 D_00882EF0[];
extern u8 D_00882ED0[];
extern u32 D_007638D8;
extern u32 D_0076462C;
extern u32 D_00764628;
extern u32 D_00764624;
extern void *memset(void *dst, int value, u32 size);
extern char *strcat(char *dst, const char *src);

// FUN_002A2340
void func_002A2340(void)

{
  int i;

  D_00882F08[0] = 0;
  D_00882F0C[0] = 0;
  D_00882F10[0] = 0;
  D_00764630 = 0;
  memset(D_00882EF0, 0, 0x12);
  memset(D_00882ED0, 0, 0x12);
  for (i = 0; i < 8; i = i + 1) {
    strcat((char *)D_00882EF0, (char *)&D_007638D8);
  }
  for (i = 0; i < 8; i = i + 1) {
    strcat((char *)D_00882ED0, (char *)&D_007638D8);
  }
  D_0076462C = 0;
  D_00764628 = 0;
  D_00764624 = 0;
  return;
}
#endif /* P4_UNIT_002A2340 */
