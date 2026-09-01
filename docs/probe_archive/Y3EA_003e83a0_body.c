/* object_size=108 window=112 normalized_diff=22 differing_offsets=8,10,11,12,13,14,15,16,18,19,22,23,24,25,26,27; casts_written=none; levers_ruled_out=schedule+no_branch_likely (the b210 prologue order remains), typed RwCamera/RwV2d declarations, explicit input locals, K&R declarations, integer/pointer parameter widths and signedness, and optimization_level 3 (object 108, normalized_diff 27); optimization_level 1 exceeded the 112-byte window. */
u8 *func_003e83a0(u8 *arg0, u8 *arg1) {
 typedef struct {
 u8 pad[0x68];
 f32 value0;
 f32 value1;
 f32 reciprocal0;
 f32 reciprocal1;
 } Obj83a0;
 typedef struct {
 f32 value0;
 f32 value1;
 } Params83a0;

 ((Obj83a0 *)arg0)->value0 = ((Params83a0 *)arg1)->value0;
 ((Obj83a0 *)arg0)->value1 = ((Params83a0 *)arg1)->value1;
 ((Obj83a0 *)arg0)->reciprocal0 = 1.0f / ((Obj83a0 *)arg0)->value0;
 ((Obj83a0 *)arg0)->reciprocal1 = 1.0f / ((Obj83a0 *)arg0)->value1;
 if (*(void **)(arg0 + 4) != NULL) {
 func_003e9680(*(void **)(arg0 + 4));
 }
 return arg0;
}
