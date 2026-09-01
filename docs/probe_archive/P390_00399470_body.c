/* object 188B / window 192B / normalized_diff 97 / differing offsets 4,8,12,16,20,24,28,36,40,48,56,64,68,72,80,88,92,96,100,104,108,112,116,120,128,132,136,140,144,148,152,156,160,164,168,172,180; classification: source-shape near-miss; remeasured archived signed-byte stream/pointer-materialisation candidate in current declaration environment; levers ruled out: signed-byte loads, integer pointer materialisation, O1, schedule-on, no-branch-likely, explicit control-flow labels, pointer-local declaration order, split outer/inner pointer locals, arg2 reuse. */
void func_00399470(s8 *arg0, u8 *arg1, u8 *arg2)
{
    s8 *streams[2];
    s32 var_10;
    s32 var_9;
    s8 **var_6;
    s8 *var_4;
    s32 temp_3_2;

    var_4 = arg0;
    var_10 = 0;
    if (arg1 == NULL) {
        goto null_init;
    }
    streams[0] = (s8 *)(arg1 + 0x10);
    streams[1] = (s8 *)(arg2 + 0x10);
loop_3:
    arg2 = (u8 *)streams;
test:
    if (var_10 >= 0x1E) {
        goto end;
    }
    if (((s8 **)arg2)[0][0] == 0) {
        goto second_check;
    }
body_outer:
    var_9 = 0;
    var_6 = (s8 **)arg2;
inner_loop:
    arg1 = (u8 *)*var_6;
    if (*(s8 *)arg1 != 0) {
        goto inner_body;
    }
inner_increment:
    var_9 += 1;
    var_6 += 1;
    if (var_9 < 2) {
        goto inner_loop;
    }
    goto test;
null_init:
    streams[1] = (s8 *)(arg2 + 0x10);
    streams[0] = streams[1];
    goto loop_3;
inner_body:
    *var_4 = *(s8 *)arg1;
    var_10 += 1;
    var_4 += 1;
    *var_6 = (s8 *)arg1 + 1;
second_check:
    if (*streams[1] != 0) {
        goto body_outer;
    }
end:
    *var_4 = 0;
}
