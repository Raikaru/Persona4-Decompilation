/* measured: object 660B; retail window 656B; normalized_diff 280; differing offsets 40,68,92,152,172,208,232,280,284,288,292,296,304,308,312,316,320,324,328,332,336,340,344,348,360,364,368,372,376,380,384,388,392,396,400,404,408,412,416,420,424,428,432,436,440,444,448,452,456,460,464,468,472,476,480,484,488,492,496,500,504,508,512,516,520,524,528,532,536,540,544,548,552,556,560,564,568,572,576,580,584,588,592,596,600,608,612,616,620,624,628,632,636,640,644,648,652,656. Ruled out: int parameter width (retail entry is pointer consumed in $a0); corrected block-scope f32 func_0044b7b0 and f32 iGpffff8094 declarations; struct/aggregate field layout; s16 duration and s8 delay/hold widths; plain-C loop/goto and branch shapes; pointer versus typed struct access; function-local declaration order; no viable source shape reached the 656-byte window. Retail contains COP1 accumulator chain (adda.s/madd.s), a known compiler floor; no inline asm used.
*/
u32 func_002A2980(int param_1)
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
  float factor;
  float value;

  if (param_1 == 0) {
    return 0xffffffff;
  }
  state = (struct TweenState *)param_1;
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
  if (state->frame < entry->delay) {
    goto advance;
  }
  if (state->frame < entry->delay + entry->duration) {
    if (state->frame == entry->delay + entry->duration - 1) {
      entry->startX = entry->endX;
      entry->startY = entry->endY;
      goto advance;
    }
    if (entry->rate < 0.0f) {
      factor = (iGpffff8094 * (float)(state->frame - entry->delay)) /
               (float)entry->duration;
      value = entry->stepX;
      entry->startX = entry->endX - value;
      entry->startX = entry->startX * func_0044b7b0(factor) + value + 0.0f;
      value = entry->stepY;
      entry->startY = entry->endY - value;
      entry->startY = entry->startY * func_0044b7b0(factor) + value + 0.0f;
      goto advance;
    }
    entry->startX = entry->startX + entry->stepX;
    entry->startY = entry->startY + entry->stepY;
    if (!(entry->rate <= 0.0f)) {
      entry->stepX = entry->rate * (entry->endX - entry->startX);
      entry->stepY = entry->rate * (entry->endY - entry->startY);
    }
    goto advance;
  }
  if (state->frame < entry->delay + entry->duration + entry->hold - 1) {
    goto advance;
  }
  state->current = state->current + 1;
  if (state->current >= state->count) {
    state->frame = 0;
    state->timer = 0;
    state->current = state->current - 1;
    state->flags = state->flags | 2;
    return 2;
  }
  state->frame = 0;
  return 1;
advance:
  state->frame = state->frame + 1;
  state->timer = state->timer + 1;
  return 1;
}
