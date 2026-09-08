/* ORDINARY_C_SOURCE_SHAPE_FLOOR: object_size=896; window=896;
 * normalized_diff=1; fully_resolved_differing_bytes=1;
 * fully_resolved_differing_words=1; code_relocations=17; zero_tail=0.
 * Production ASM retained. Complete ordinary C, not an exact match.
 *
 * Sole discrepancy, offset 0x13F (opcode byte of instruction at 00222E5C):
 * source: addiu  s1, zero, 255
 * retail: daddiu s1, zero, 255
 * All other bytes match with all 17 relocations resolved, including the
 * return delay slot. The measured floor is not an impossibility claim.
 *
 * Closing changes from the initial fresh candidate: fused u16 frame
 * increment; direct float-to-u8 casts (not float-to-u32-to-u8); origin
 * before the two real two-float arrays; staged opacity multiplication;
 * float-first quad-renderer declaration preserving all eleven ABI slots.
 * The 0.8 coefficient is fGpffff838c, not the old archive's wrong scalar.
 * Base alpha stays separate from overlay alpha and reaches descriptor draw.
 *
 * Tested without closing the last byte: signed/unsigned literal forms,
 * explicit narrow and float constants, named byte constants, u8/u16/u64
 * and unsigned-long storage, corresponding byte provider declarations,
 * GNU byte mode, and scoped propagation controls. The b119 compiler gives
 * 920 bytes / 629 normalized differences. No padding, pinned registers,
 * inline asm, no-op arithmetic or hidden phase argument was introduced.
 *
 * Before integration, replace the callback declaration and constructor
 * storage cast with void(u8*,s32,void*) to match the actual dispatcher.
 * Remove the descriptor provider's stale fifth input throughout active C;
 * do not manufacture an a3 argument. Those edits are not yet installed.
 * func_00222210 retains its independent incoming-f20 blocker and stays ASM.
 */
#include "shd_misc_internal.h"

/* Replace the owner's unprototyped declaration. This matches the current
 * func_004623a0 callback type; all three machine slots are proven below. */
extern void func_00222d20(u8 *drawData, s32 workAddress, void *callback);
extern void func_00222210(u8 *work, u32 alpha);
extern void func_0034f1e0(void);
extern void func_0034c270(Vec2f origin, f32 depth, u32 alpha, s32 line);
extern void func_00354ba0(u8 *task);
extern s32 func_00355430(u8 *task);
extern void func_00355310(u8 *task, f32 *start, f32 *current, f32 *end);
extern void func_003553b0(u8 *task, f32 *scale);
extern f32 func_00373cb0(f32 frame, f32 start, f32 end, s32 mode);
extern void func_00364680(f32 depth, f32 x, f32 y, f32 shadowX, f32 shadowY, f32 width, f32 height,
    s32 color, s32 texture, s32 shadow, s32 mode);
extern void func_00367210(Vec2f origin, f32 depth, u32 alpha, s16 *descriptor);
extern s32 func_003f6440(s32 state, s32 value);
extern s32 func_0045aeb0(s16 channel, const char *name);
extern char D_00629680[];
extern f32 fGpffff838c;

void func_00222d20(u8 *drawData, s32 workAddress, void *callback)
{
    u8 *work = (u8 *)workAddress;
    u32 alpha;
    s32 texture;
    f32 phase;
    Vec2f origin;
    f32 position[2];
    f32 scale[2];

    if ((*(u16 *)work & 2) != 0) {
        if ((*(u16 *)work & 8) == 0) {
            if (++*(u16 *)(work + 0x46) >= 54) {
                *(u16 *)work |= 8;
            }
            alpha = (u8)(255.0f * func_00373cb0(
                (f32)(u32)*(u16 *)(work + 0x46), 0.0f, 5.0f, 1));
            if (*(u16 *)(work + 0x46) == 14) {
                func_0045aeb0(2, D_00629680);
            }
        } else {
            alpha = 255U;
        }

        func_0034f1e0();
        origin.x = 0.0f;
        origin.y = 0.0f;
        func_0034c270(origin, 0.0f, alpha, 0x16);
        func_00222210(work, alpha);
        func_00354ba0(*(u8 **)(work + 0x4C));

        origin.x = 0.0f;
        origin.y = 0.0f;
        texture = func_00355430(*(u8 **)(work + 0x4C));
        if (texture != 0) {
            if (*(u16 *)(work + 0x46) >= 24) {
                u32 overlayAlpha;
                f32 opacity;

                phase = func_00373cb0(
                    (f32)(u32)*(u16 *)(work + 0x46), 27.0f, 54.0f, 2);
                func_00355310(*(u8 **)(work + 0x4C), 0, position, 0);
                func_003553b0(*(u8 **)(work + 0x4C), scale);
                opacity = fGpffff838c * (f32)alpha;
                overlayAlpha = (u8)(opacity * (1.0f - phase));
                func_00364680(0.0f, position[0], position[1], position[0], position[1],
                    256.0f * scale[0], 512.0f * scale[1],
                    (s32)(overlayAlpha | 0xFFFFFF00U), texture, 0, 1);
                func_003f6440(3, 0x717FB);
                func_003f6440(2, 0x44);
            }
        }
        func_00367210(origin, 0.0f, alpha, (s16 *)(work + 0x58));
    }
}

/*
SOURCE STATUS
Complete ordinary-C wrapper candidate only; no compile, build, tests, formatting or other validation run. Repository unmodified. Current source overrides stale CSP/archive snippets. body.c is intended for src/promoted/code1_0022.c with declarations.h additions. No matching claim.

ACTUAL CALLBACK ABI (not a task update callback)
Constructor asm/nonmatchings/code1_0022/func_002230e0.s complete lines 1..69:
00223110/1C allocator gets size 0x74 and alignment/category 0x40000; 00223134 clears all 0x74 bytes.
00223168 creates task with updater func_00221f40, destructor func_002230a0 and work as eighth GP argument.
00223194 clears embedded order-table node [work+0x0C,work+0x3C), 0x30 bytes.
002231A4 stores callback func_00222d20 at work+0x14 = node+8.
002231A8 stores work at work+0x1C = node+0x10.
Current updater src/Battle/btlResultHeroLvUp.c:202..275 clears work+0C/+10 and calls func_00460ac0(D_00795F20, work+0C) every update. func_00460ac0 ASM 00460AC0..00460B5C and src/sdkOt.c:15..35 link the node, without touching callback or callback-data fields.
Real draw dispatcher is func_004623a0, NOT func_00461390 or func_004604d0. Complete current source src/promoted/code1_0046.c:708..856 and complete retail ASM asm/code1.s:981130..981387 were read.
At 004623B8 it loads node+8 into a2; after optional node-flag gating, 004623E0 sets a0=node+1C, 004623E4 loads a1=node+10, 004623E8 jalr a2. Thus target receives:
  a0 = work+0x28 (actual embedded draw-data address, ignored by wrapper);
  a1 = work (consumed, copied to s2 at 00222D38);
  a2 = target callback address (the jalr register, ignored by wrapper).
Current C dispatcher explicitly models this as void (*)(u8 *, s32, void *) and passes the callback address third. Candidate uses that exact existing callback type, including its existing third slot, rather than inventing a new convention. The third slot is NOT a phase, alpha, or draw-state input. Neither unused parameter is manufactured to manipulate codegen. workAddress is cast to u8* under this project's 32-bit PS2 pointer/address convention.
Constructor's current src/promoted/code1_0022.c:326 cast to void (*)(u8*) is stale. Main should replace that storage with *(void (**)(u8 *, s32, void *))(temp_2+0x14) = func_00222d20; this preserves the retail stored bits while making the current dispatcher/definition function types agree.
Callback return ignored: instruction after jalr delay slot, 004623F0, loads node+18 into v1 and dispatches its type; no v0 read. Type0 (constructor-cleared) falls to 00462728 via retail table. End callback node+C and data node+14 are zero. Dispatcher then loads next pointer. No return value is fabricated.

WRAPPER INPUT/LOCAL DEFINEDNESS
work points to constructor-cleared 0x74-byte object. Wrapper reads/writes u16 flags at +0, u16 frame at +46, task pointer at +4C, and passes +58 as descriptor. Updater case0 creates task via func_00354a50, sets it up, initializes descriptor, then enables flag2; therefore inactive branch exits before task dereference. Counter remains zero until first draw. Work/frame reads after opaque calls are intentionally reloaded.
Only GP input with semantic use is a1/work. f20 is saved at 00222D34 and restored at 00223090. Its ONLY wrapper-local arithmetic use is after assigning phase from easing f0 at 00222F28. All f12..f18 call arguments are explicitly defined by constants, zeroed origin, provider outputs, base alpha, and this initialized phase. No wrapper-local undefined input found.
Callee func_00222210 still takes work in a0 and alpha in a1 only. It reads low alpha byte (e.g. 002225C8 stores s3 into vertex-alpha byte); u32 alpha accurately preserves the caller's zero-extended value. Do not use signed s8 declaration from old archive. Its known incoming-f20 blocker is unchanged; see docs/probe_archive/P022_00222210_body.c. Wrapper does not set f20 before 00222E90 and must not repair, pass, initialize, or suppress that callee's missing phase.
Local origin is existing Vec2f from include/shd_misc_internal.h: 8 bytes, two float fields. Both fields explicitly zeroed at both retail sites. Both by-value calls consume a0's entire 64-bit pair; f12 is independent depth. No reinterpret cast between unrelated scalar locals.
Local position[2] is EXACTLY 8 bytes, target sp+60/+64. func_00355310 (complete ASM 00355310..0035536C) reads task+38; optional a1 copies state+18/+1C, optional a2 copies state+10/+14, optional a3 copies state+20/+24. Here a1=a3=0 and a2=position, so it definitely writes BOTH floats; no other output bytes, no task mutation, no return value used.
Local scale[2] is EXACTLY 8 bytes, target sp+58/+5C. Current src/promoted/code1_0035.c:734..744 writes scale[0]=state+38 and scale[1]=state+3C after asserting non-null destination. Destination is real array, so both reads after call are defined. No dummy initialization or treating adjacent unrelated scalars as an array.
origin is target sp+68/+6C, disjoint from both arrays. Target frame allocation 0x70 includes saved f20/s0/s1/s2/ra and alignment; do not introduce C padding to reproduce that.

PROVIDERS / OUTPUTS / MUTATIONS
func_00373cb0: complete asm/nonmatchings/btlShuffleCalc/func_00373cb0.s. Actual f12=frame, f13=start, f14=end, a0=mode. Returns f32 f0. Before start returns +0; at/after end returns 1; mode1 interior sin(pi/2*(frame-start)/(end-start)); mode2 interior 1-cos(same). Duration positive at both wrapper calls (5 and 27). Retail pi/2 scalar 00761470 is 0x3FC90FDB. Both phases lie in [0,1] for wrapper's initialized unsigned frame; casts are within unsigned representable bounds.
func_0045aeb0: current src/sdkSnd.c:1033..1049 and complete retail ASM prove s32 return=1, first input sign-extended s16 channel and second const char* name. Wrapper calls channel2 only at frame14, ignores result. Mutates channel2 stream fields, copies name, invokes 00459ad0. No hidden third/fourth caller inputs: provider itself creates a2/a3 for its nested string operation.
func_0034f1e0: complete ASM calls RenderWare state setter for (6,0),(7,2),(8,0),(9,2),(12,1),(11,6),(10,5),(2,4),(14,0), then 003f6440(3,0x717FB),(2,0x44). No arguments/no meaningful return. Wrapper preserves this single call.
func_0034c270: complete nLine ASM 0034C270..0034C49C. a0=8-byte float pair, a1=alpha, a2=line index, f12=depth. Sets global depth, zeroes own 0x16A0 local object, indexes line data at 00749CC0+960*line, builds 20 points and calls 0034c500, then clears global depth. Does not mutate wrapper pair (passed by value); uses all 8 bytes, so origin must be a real pair. Line0x16 lies inside provider's valid 1..35 interval. No return consumed.
func_00354ba0: complete ASM 00354BA0..0035506C. Task pointer a0, state=*(task+38); saves/restores f20/f21. When state+40 and state+8 are nonzero, increments state+4 up to100, writes interpolated current position at +10/+14, writes smoothed position at +30/+34, draws texture from +150, resets render states and draws additional quad. Scale +38/+3C is read, not written. Guard-false exits without these mutations. Important: call must precede both current-position and texture queries; it is not a getter.
func_00355430: current src/promoted/code1_0035.c:765..774 plus full ASM. s32 return is state+150 if state+40 nonzero, else zero. The word is used as a texture pointer by 00364680 (it loads *(a1+0) for raster). No mutation. Retain current owner s32 contract rather than invent opaque texture owner type.
func_00364680: full shdMisc ASM 00364680..00364C4C. a0=color, a1=texture, a2=shadow flag, a3=mode; f12=depth,f13/f14=current x/y,f15/f16=shadow x/y,f17/f18=width/height. Wrapper supplies all eleven slots; no additional live-ins. Builds own vertices and draws, may set alpha/test/raster state. With shadow0 skips shadow pass; mode1 sets state2=0x58; wrapper then explicitly restores state3/state2 as in retail. No return consumed, no pointer-output argument, no work mutation.
func_003f6440 is retail RpSkyRenderStateSet, complete ASM 003F6440..003F668C. It actually returns s32 boolean success; declarations.h corrects old void callers locally without consuming result. State3 writes GS TEST bits and state2 writes ALPHA bits and advances DMA packet pointer. The wrapper calls (3,0x717FB) then (2,0x44), no altered order.
func_00367210: complete ASM 00367210..003672CC. a0=8-byte origin, a1=alpha, a2=descriptor pointer, f12=depth. It masks alpha low8 and exits if0, checks signed descriptor selector as unsigned<7, then dispatches exactly the four live parameters to selector providers. Current C's fifth s32 argument is not read anywhere in the retail dispatcher and MUST NOT be supplied just to zero a3. a3 is overwritten with jump-table base before any selected call. Candidate declaration therefore has only real parameters; Main may treat current definition's unused arg3 as a separate stale declaration contract when integrating.
Descriptor local extent is 0x1C bytes from work+58 through work+73: 003671d0 clears descriptor+4..+1B (0x18 bytes) and sets selector0, constructor already zeroed bytes2/3. 003672d0 writes all live hero input fields inside +4..+19. Actual initial selector0 calls 00367420, which composes six panels and never writes selector. Other selectors1..6 remain supported, not suppressed. Retail table at 00752900 contains targets 00367254,64,74,84,94,A4,B4 for providers 00367420,003675F0,003676F0,00367940,003679C0,00367B80,00367D00 respectively.
Corrected descriptor release remains void func_0046d280(void *node), current src/Kernel/sdkSpr.c:333..336 passes node to allocator release. Wrapper adds no release calls; underlying panel providers retain this corrected contract. No obsolete zero-argument release declaration added.

EXACT RETAIL DATA (read from image.bin, offset = address - 0x100000 per config/slus21782.yaml)
0076147C bytes CD CC 4C 3F = fGpffff838c = float bits 0x3F4CCCCD = 0.800000011920929, target gp offset -0x7C74.
00629680 bytes 73 6F 75 6E 64 2F 45 56 45 4E 54 2F 45 56 45 5F 31 36 36 2E 41 44 58 00 = "sound/EVENT/EVE_166.ADX".
The archived V022 candidate's fGpffff809c use is wrong: that symbol maps to 0076118C / gp-0x7F64, not this instruction.

*/
