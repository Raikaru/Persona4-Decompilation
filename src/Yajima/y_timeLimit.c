#include "operand_order_internal.h"
#include "include_asm.h"
#include "type.h"
#include "name_entry_internal.h"

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


// Reset the time-limit globals: the two string buffers, the counters and the shared 0x12-byte
// tables. Called from nEntry.c.
// FUN_002A2340
void yTimeLimitReset(void)

{
  s32 i;

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


// Clear a track's state fields; returns 1 when the track pointer is null.
// FUN_002A2780
u8 yTimeTrackClear(s32 track)

{
  if (track == 0) {
    return 1;
  }
  ((NameTweenState *)track)->current = 0;
  ((NameTweenState *)track)->count = 0;
  ((NameTweenState *)track)->frame = 0;
  ((NameTweenState *)track)->flags = 0;
  ((NameTweenState *)track)->timer = 0;
  ((NameTweenState *)track)->total = 0;
  return 0;
}


/* Append a two-dimensional key, clamping duration to one frame and queueing
 * linear (zero rate), decaying (positive rate), or sine (negative rate) motion. */
// FUN_002A27C0
u32
yTimeTrackAppendKey(s32 track,s32 startX,s32 startY,s32 endX,s32 endY,f32 rate,
            u8 delay,u8 hold,s16 durationFrames)
{
  NameTweenState *state;
  NameTweenEntry *entry;
  f32 duration;

  if (track == 0) {
    return 1;
  }
  state = (NameTweenState *)track;
  if (state->count >= 4) {
    return 2;
  }
  entry = &state->entries[state->count];
  entry->duration = durationFrames;
  if (entry->duration < 1) {
    entry->duration = 1;
  }
  duration = (f32)entry->duration;
  entry->startX = (f32)startX;
  entry->startY = (f32)startY;
  entry->endX = (f32)endX;
  entry->endY = (f32)endY;
  entry->rate = rate;
  if (rate > 0.0f) {
    entry->stepX = rate * (entry->endX - entry->startX);
    entry->stepY = entry->rate * (entry->endY - entry->startY);
  }
  else if (rate < 0.0f) {
    entry->stepX = entry->startX;
    entry->stepY = entry->startY;
  }
  else {
    entry->stepX = (entry->endX - entry->startX) / duration;
    entry->stepY = (entry->endY - entry->startY) / duration;
  }
  entry->delay = delay;
  entry->hold = hold;
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


extern f32 sinf(f32 fparg0);
extern f32 fGpffff8110;
extern f32 fGpffff8094;
// Advance one frame through delay, interpolation and hold; return 2 when finished, 1 while
// advancing, 0 when inactive, or -1 for null.
// FUN_002A2980
u32 yTimeTrackAdvance(s32 track)
{
  s8 delay;
  s32 endFrame;
  s32 frame;
  NameTweenEntry *entry;
  NameTweenState *state;
  f32 blend;
  f32 angle;
  f32 start;

  if (track == 0) {
    return 0xffffffff;
  }
  state = (NameTweenState *)(uintptr_t)track;
  if ((state->flags & 2) != 0) {
    return 2;
  }
  if ((state->flags & 1) == 0) {
    return 0;
  }
  if ((state->current == 0) && (state->frame == 0)) {
    state->timer = 0;
  }
  entry = &state->entries[state->current];
  delay = entry->delay;
  frame = state->frame;
  if (!((frame) < (delay))) {
    endFrame = (s32)delay + (s32)entry->duration;
    if (frame < endFrame) {
      if (frame == endFrame + -1) {
        entry->startX = entry->endX;
        entry->startY = entry->endY;
      }
      else if (entry->rate < 0.0f) {
        angle = (fGpffff8094 * (f32)(state->frame - (s32)delay)) /
                (f32)(s32)entry->duration;
        start = entry->stepX;
        blend = sinf(angle);
        entry->startX = operandOrderAddProduct(start, entry->endX - start, blend) + 0.0f;
        start = entry->stepY;
        blend = sinf(angle);
        entry->startY = operandOrderAddProduct(start, entry->endY - start, blend) + 0.0f;
      }
      else {
        entry->startX = entry->startX + entry->stepX;
        entry->startY = entry->startY + entry->stepY;
        if (entry->rate > 0.0f) {
          entry->stepX = entry->rate * (entry->endX - entry->startX);
          entry->stepY = entry->rate * (entry->endY - entry->startY);
        }
      }
    }
    else if (!((frame) < (entry->hold + endFrame + -1))) {
      endFrame = state->current + 1;
      state->current = endFrame;
      if (!((endFrame) < (state->count))) {
        state->frame = 0;
        state->timer = 0;
        state->current = state->current + -1;
        state->flags = state->flags | 2;
        return 2;
      }
      state->frame = 0;
      return 1;
    }
  }
  state->frame = state->frame + 1;
  state->timer = state->timer + 1;
  return 1;
}
// Copy the current key's (x, y) pair into output; returns 1 for null track, 2 when there are no
// keys, 0 on success.
// FUN_002A2C10
u32 yTimeTrackCurrentKey(s32 track,f32 *output)
{
  struct Pair2 { f32 x; f32 y; };
  struct Pair2 *key;
  struct Pair2 *pair;

  if ((track == 0) || (output == (f32 *)0)) {
    return 1;
  }
  if (((NameTweenState *)track)->count < 1) {
    return 2;
  }
  key = (struct Pair2 *)&((NameTweenState *)track)->entries[((NameTweenState *)track)->current];
  pair = (struct Pair2 *)output;
  *pair = *key;
  return 0;
}


// Return 1 while the finished mask (0x2) is clear; a null track returns 0.
// FUN_002A2C70
s32 yTimeTrackIsNotDone(s32 track)

{
  s32 notDone;

  if (track == 0) {
    notDone = 0;
  }
  else {
    notDone = !((((NameTweenState *)track)->flags & 2) > 0);
  }
  return notDone;
}


// Return 1 when the track's active flag is clear; a null track counts as idle.
// FUN_002A2CA0
s32 yTimeTrackIsIdle(s32 track)

{
  s32 idle;

  if (track == 0) {
    idle = 1;
  }
  else {
    idle = !((((NameTweenState *)track)->flags & 1) > 0);
  }
  return idle;
}


// Return track progress in 0..1: 1.0 when done, 0.0 when inactive, else the fraction through its
// key table.
// FUN_002A2CD0
f32 yTimeTrackProgress(s32 track)
{
  s32 flags;
  s32 total;
  s32 start;
  s32 tableOffset;
  s32 endOffset;
  s32 current;
  s32 numerator;
  s32 denominator;
  f32 progress;

  if (track == 0) {
    return 0.0f;
  }
  flags = ((NameTweenState *)track)->flags;
  if ((flags & 2) != 0) {
    return 1.0f;
  }
  if ((flags & 1) == 0) {
    return 0.0f;
  }
  total = ((NameTweenState *)track)->total;
  if (total < 1) {
    return 0.0f;
  }
  start = ((NameTweenState *)track)->entries[0].delay;
  tableOffset = ((NameTweenState *)track)->count * 0x20;
  endOffset = ((NameTweenEntry *)(tableOffset + track - 0x20))->hold;
  current = ((NameTweenState *)track)->timer;
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
  progress = (f32)numerator / (f32)denominator;
  if (progress < 0.0f) {
    progress = 0.0f;
  }
  else if (progress > 1.0f) {
    progress = 1.0f;
  }
  return progress;
}
