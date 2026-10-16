#include "include_asm.h"
#include "Kosaka/k_clump_property_internal.h"
#include "sdk_task_registration.h"
/* Original translation unit k_texStrip.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

extern void func_00428618(s32 arg0);
extern void chkmemAllocSiteTag(const void *file, u32 line);
extern void func_00440b68(const char *fmt, ...);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void *func_003ef650(void *arg0, const char *arg1);
extern void func_003ef610(s32 arg0);
extern void func_003ef5b0(s32 arg0, s32 arg1);

extern s32 func_00468170(void *arg0, const char *arg1);
extern s32 func_004680f0(s32 arg0, void *arg1);
extern void K_Clump_LogCodeCounts(void *arg0);
extern void kwlnTaskDestroyWithHierarchy(s32 handle);
extern char D_005F6168[];
extern char D_005F6178[];
extern char D_005F6190[];
extern char D_005F61B0[];
extern char D_005F63E0[];
extern char D_005F6490[];
extern char D_005F64A8[];

extern s32 func_003e2f60(s32 a, s32 b, s32 *c);
extern s32 func_003df3c0(s32 a, s32 *b);
extern void func_003e2910(s32 a, void *b, s32 c);
extern void func_003deff0(s32 a, s32 b, s32 c, s32 d, s32 e);
extern void func_003e2ab0(s32 a, void *b, s32 c);
extern void func_003e2ce0(s32 a, s32 b);
extern void func_003e2e40(s32 a, s32 b);
extern s32 func_003e6a90(s32 a);
extern s32 sprintf(char *buf, const char *fmt, ...);
extern s32 func_004288d8(void *a, void *b);
extern u8 *H_Cdvd_AcquireDirectory(void *path, s32 flags);
extern void H_Cdvd_ReadSync(void *handle);
extern void H_Cdvd_Destroy(void *handle);
extern char *strcat(char *dst, const char *src);
extern void func_003ef1b0(s32 arg0);
extern void func_003ef260(s32 arg0, s32 (*arg1)(s32, s32), s32 arg2);
extern void func_003e6870(void *arg0, void *arg1);
extern s32 K_TexStripNameInsert(s32 arg0, s32 arg1);
extern char D_005F63F0[];
extern char D_005F6430[];
extern char D_005F6450[];
extern char D_005F6470[];
extern char D_00763128;
extern char D_00763130;
extern char D_00763138;
extern char D_0076313C;
extern char D_00763140;
extern char D_00763148;
extern char D_00763150;
extern char D_00763158;
extern s32 D_00764498;

extern s32 func_00428550(const char *path);
extern s32 func_00428780(s32 handle, void *out);
extern s32 strcmp(const char *a, const char *b);
extern char *strcpy(char *dst, const char *src);
extern u8 *FldResource_Create(void *path);
extern s32 FldResource_IsFileLoaded(void *hdr);
extern void FldResource_ParseChunks(void *hdr);
extern s32 FldResource_PollLoads(void *hdr);
extern s32 K_Clump_CountIntUsrData(void *object, const char *name);
extern s32 func_00426cf0(void *path, s32 a, s32 b);
extern size_t strlen(const char *buf);
extern s32 func_00427338(s32 fd, void *buf, s32 n);
extern s32 func_004275a8(s32 fd, void *buf, s32 n);
extern void func_00426f80(s32 fd);
extern void func_00428f08(void *a, s32 b);
extern void FldResource_Destroy(void *hdr);
extern void K_Clump_FreeTextureNameList(void *a);
extern char D_005F61D0[];
extern char D_005F61F8[];
extern char D_005F6210[];
extern char D_005F6230[];
extern char D_005F6250[];
extern char D_005F6270[];
extern char D_005F62A0[];
extern char D_005F62B0[];
extern char D_005F62C0[];
extern char D_005F62D0[];
extern char D_005F6310[];
extern char D_005F6350[];
extern char D_005F6370[];
extern char D_005F63B0[];

s32 K_TexStripLoadRecords(u8 *arg0, void *arg1);
void K_TexStripApplyNames(u8 *arg0, void *arg1, u8 *arg2);
s32 K_TexStripBuildUpdate(u8 *arg0);
s32 K_TexStripRecordCount(u8 *arg0, void *arg1);
s32 K_TexStripLoadUpdate(u8 *arg0);

/* Source unit: src/promoted/k_texStrip.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/k_texStrip.c; members 00190680-00191d90 */

// measured: nd 115 after 4 attempts (best). Spill-slot rule as K_TexStripRecordCount:
// func_003df3c0 writes four signed header words in spill.s. Switch `case 0x16 / case 0xF0F000E0 /
// default` compiles the dispatch comparison in the correct order (0xF0F000E0 first, then 0x16)
// and matches retail exactly. Residual nd 115 is dominated by register allocation: retail keeps
// sp60/sp64/sp68 (the 0x14-byte func_003e2910 buffer + sp64/sp68) on the STACK at 0x60/0x64/
// 0x68, but mwcc promotes sp64/sp68 to $s5/$s6 (sp68 folded with `sll $s6,2` / `addu $s0,$s6,$s6`)
// adding a 5th/6th saved reg, so the whole allocation shifts (retail wants var_16->$s0, arg1/
// temp_2->$s1, temp_18->$s2, temp_19->$s3, var_20->$s4). Making sp60/sp64/sp68 overlap via a
// 5-word array (nd 138) or a 3-field struct (nd 141) is worse. Core regs are otherwise right.
// QTEX lane: plain-C candidate object 668/window 672; baseline fndiff was nd 20
// (six differing instruction words plus one zero-padding tail word), with both
// func_003deff0 calls materializing move $a0 before the spill.s[0]/spill.s[1] loads.
// The targeted `(u32)` casts on spill.s[0] and spill.s[1] at both calls produce nd 0.
// s32 sp[2], the 16-byte spill union, and buffer[5] reproduce the 0xA0 frame and saved-register
// coloring. Shared-callee probe: retail func_003deff0 first-uses a0 as a forwarded
// pointer, saves a1/a2, and masks a3/t0, proving five args `(void *,s32,s32,s32,s32)`;
// existing calls already pass all five, so no prototype change was needed.
// FUN_00190680
s32 K_TexStripLoadRecords(u8 *arg0, void *arg1) {
    s32 sp[2];
    union { s32 s[4]; u32 u[4]; } spill;
    s32 buffer[5];
    s32 var_20;
    s32 temp_19;
    s32 temp_18;
    u8 *temp_2;
    u8 *var_16;

    var_20 = 0;
    sp[0] = *(s32 *)(arg0 + 0x110);
    sp[1] = *(s32 *)(arg0 + 0x118);
    temp_19 = func_003e2f60(3, 1, &sp[0]);
    temp_18 = func_003e2f60(2, 2, (s32 *)arg1);
    if ((temp_19 != 0) && (temp_18 != 0)) {
        goto loop_check;
loop_body:
        switch (spill.s[0]) {
        case 0x16:
            var_20 = func_003e6a90(temp_19);
            break;
        case 0xF0F000E0:
            func_003e2910(temp_19, &buffer[0], 0x14);
            func_003deff0(temp_18, (u32)spill.s[0], (u32)spill.s[1], spill.s[2], spill.s[3]);
            func_003e2ab0(temp_18, &buffer[0], 0x14);
            func_003e2ce0(temp_19, buffer[2]);
            chkmemAllocSiteTag(D_005F6168, 0xBB);
            temp_2 = D_008873F4[0](1, buffer[1] + buffer[2], 0x40000);
            func_003e2910(temp_19, temp_2 + buffer[2], buffer[1]);
            func_003e2ab0(temp_18, temp_2, buffer[1] + buffer[2]);
            jtbl_008873EC[0](temp_2);
            break;
        default:
            if (spill.s[1] != 0) {
                chkmemAllocSiteTag(D_005F6168, 0xCA);
                var_16 = D_008873F4[0](1, spill.u[1], 0x40000);
                func_003e2910(temp_19, var_16, spill.s[1]);
            }
            func_003deff0(temp_18, (u32)spill.s[0], (u32)spill.s[1], spill.s[2], spill.s[3]);
            if (spill.s[1] != 0) {
                func_003e2ab0(temp_18, var_16, spill.s[1]);
                jtbl_008873EC[0](var_16);
            }
            break;
        }
loop_check:
        if (func_003df3c0(temp_19, &spill.s[0]) != 0) {
            goto loop_body;
        }
        func_003e2e40(temp_19, 0);
        func_003e2e40(temp_18, 0);
    }
    return var_20;
}

/* Look up the texture name, detach and insert it when absent, then report
   the lookup result. Pointer-typed lookup/print arguments and disabled CSE
   preserve retail's first-argument-before-name-address materialization.
   measured: object 196B/window 208B; exact instructions, 12B zero tail. */
/* measured: K_TexStripNameInsert MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
// FUN_00190920
s32 K_TexStripNameInsert(s32 arg0, s32 arg1) {
    if (func_003ef650((void *)arg1, (char *)arg0 + 0x10) == 0) {
        func_003ef610(arg0);
        func_003ef5b0(arg1, arg0);
        func_00440b68(D_005F6178, (char *)arg0 + 0x10);
        if (func_003ef650((void *)arg1, (char *)arg0 + 0x10) != 0) {
            func_00440b68(D_005F6190, (char *)arg0 + 0x10);
        }
    } else {
        func_00440b68(D_005F61B0, (char *)arg0 + 0x10);
    }
    return arg0;
}

/* measured: restore CSE after the exact 00190920 call sequence. */
/* measured: K_TexStripApplyNames, K_TexStripBuildUpdate, K_TexStripRecordCount, K_TexStripLoadUpdate MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs on
// measured: candidate frame, spill arrays, saved-register order, switch/goto layout, and
// shared-callee five-argument signature reached object 532/window 544 with normalized_diff 10.
// fndiff isolated the residual to func_003deff0 setup: retail loads spill.s[0] and spill.s[1]
// into $a1/$a2 before moving temp_19 into $a0, while b210 materializes the first argument
// first. Casting those two stack values to u32 reproduces the retail order and closes this
// function (normalized_diff 0).
// FUN_001909F0
void K_TexStripApplyNames(u8 *arg0, void *arg1, u8 *arg2) {
    s32 sp[2];
    union { s32 s[4]; u32 u[4]; } spill;
    s32 temp_20;
    s32 temp_19;
    s32 temp_18;
    s32 temp_4;
    u32 var_17;
    u8 *var_16;

    sp[0] = *(s32 *)(arg0 + 0x110);
    sp[1] = *(s32 *)(arg0 + 0x118);
    temp_20 = func_003e2f60(3, 1, &sp[0]);
    temp_19 = func_003e2f60(2, 2, (s32 *)arg1);
    if ((temp_20 != 0) && (temp_19 != 0)) {
        goto loop_check;
loop_body:
        switch (spill.s[0]) {
        case 0x16:
            temp_18 = func_003e6a90(temp_20);
            var_17 = 0;
            goto item_check;
item_body:
            temp_4 = *(s32 *)(arg2 + var_17 * 4 + 0x658);
            if (temp_4 != 0) {
                func_003ef260(temp_4, K_TexStripNameInsert, temp_18);
            }
            var_17++;
item_check:
            if (var_17 < *(u32 *)(arg2 + 0x254)) {
                goto item_body;
            }
            func_003e6870((void *)temp_18, (void *)temp_19);
            func_003ef1b0(temp_18);
            break;
        default:
            if (spill.s[1] != 0) {
                chkmemAllocSiteTag(D_005F6168, 0x141);
                var_16 = D_008873F4[0](1, spill.u[1], 0x40000);
                func_003e2910(temp_20, var_16, spill.s[1]);
            }
            func_003deff0(temp_19, (u32)spill.s[0], (u32)spill.s[1], spill.s[2], spill.s[3]);
            if (spill.s[1] != 0) {
                func_003e2ab0(temp_19, var_16, spill.s[1]);
                jtbl_008873EC[0](var_16);
            }
            break;
        }
loop_check:
        if (func_003df3c0(temp_20, &spill.s[0]) != 0) {
            goto loop_body;
        }
        func_003e2e40(temp_20, 0);
        func_003e2e40(temp_19, 0);
    }
}

/* measured: complete file-stat records, per-state loop lifetimes, and live
   resource reloads reproduce retail. See docs/probe_archive/
   TexStrip_00190c10_20261005.md for owner and relocation evidence. */
// FUN_00190C10
#pragma push
/* measured: K_TexStripBuildUpdate MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
s32 K_TexStripBuildUpdate(u8 *task)
{
    /* sceGetstat owns each complete 64-byte record. Only its size word is
       interpreted here; the other thirteen trailing words remain opaque. */
    typedef struct {
        u32 fields00[2];
        u32 size;
        u32 fields0C[13];
    } TexStripFileStat;
    TexStripFileStat fileStat;
    char sourcePath[0x100];
    char manifestLine[0x100];
    char targetPath[0x100];
    char modelPath[0x100];
    char texturePath[0x100];
    char resourcePath[0x100];
    TexStripFileStat copyStat;
    KClumpIntPropertyResult kindProperty;
    KClumpIntPropertyResult idProperty;
    s32 *work;

    work = *(s32 **)(task + 0x38);
    switch (work[0]) {
    case 0:
        work[1] = func_00428550(D_005F61D0);
        if (work[1] < 0) {
            return -1;
        }
        work[0]++;
        break;
    case 1: {
        s32 tmp;
        char *p;
        tmp = func_00428780(work[1], (void *)&work[2]);
        if (tmp > 0) {
            if (strcmp((void *)&work[0x12], &D_00763138) != 0 &&
                strcmp((void *)&work[0x12], &D_0076313C) != 0) {
                for (p = (char *)&work[0x12]; *p != '.' && *p != 0; p++) {
                }
                if (strcmp(p, &D_00763140) == 0) {
                    strcpy((void *)&work[0x53], D_005F61F8);
                    strcat((void *)&work[0x53], (void *)&work[0x12]);
                    work[0x93] = (s32)FldResource_Create((void *)&work[0x53]);
                    func_00440b68(D_005F6210, &work[0x53]);
                    work[0] = 2;
                }
            }
        } else {
            work[0] = 8;
        }
        break;
    }
    case 2:
        if (FldResource_IsFileLoaded((void *)work[0x93]) != 0) {
            FldResource_ParseChunks((void *)work[0x93]);
            work[0] = 3;
        }
        break;
    case 3: {
        u32 resourceIndex;
        s32 propertyIndex;
        if (FldResource_PollLoads((void *)work[0x93]) != 0) {
            work[0x95] = 0;
            work[0x296] = 0;
            for (resourceIndex = 0; resourceIndex < ((u32 *)work[0x93])[6]; resourceIndex++) {
                u32 resourceOffset = resourceIndex * 4;
                s32 propertyCount = K_Clump_CountIntUsrData((void *)((s32 *)((u32)work[0x93] + resourceOffset))[7], D_005F6230);
                for (propertyIndex = 0; propertyIndex < propertyCount; propertyIndex++) {
                    K_Clump_GetIntUsrDataAt(&kindProperty, (void *)((s32 *)(resourceOffset + (u32)work[0x93]))[7], D_005F6230, propertyIndex);
                    if (kindProperty.value == 0) {
                        K_Clump_GetIntUsrDataAt(&idProperty, (void *)((s32 *)(resourceOffset + (u32)work[0x93]))[7], D_005F6250, propertyIndex);
                        work[work[0x95] + 0x96] = idProperty.value;
                        work[0x95]++;
                    } else if (kindProperty.value == 1) {
                        K_Clump_GetIntUsrDataAt(&idProperty, (void *)((s32 *)(resourceOffset + (u32)work[0x93]))[7], D_005F6250, propertyIndex);
                        work[work[0x296] + 0x297] = idProperty.value;
                        work[0x296]++;
                    }
                }
            }
            work[0] = 4;
        }
        break;
    }
    case 4: {
        char *p;
        char *q;
        u32 textureIndex;
        u32 fileIndex;
        s32 descriptor;
        strcpy(sourcePath, D_005F6270);
        for (p = (char *)&work[0x53]; *p != 0; p++) {
        }
        for (; *p != '/'; p--) {
        }
        strcat(sourcePath, p + 1);
        for (q = (char *)sourcePath; *q != '.'; q++) {
        }
        strcpy(q, &D_00763148);
        D_00764498 = func_00426cf0(sourcePath, 0x603, 0x1FF);
        if (D_00764498 >= 0) {
            work[0x399] = 0;
            work[0x39A] = 0;
            sprintf(manifestLine, D_005F62A0, ((s16 *)work[0x93])[2], ((s16 *)work[0x93])[3]);
            func_004275a8(D_00764498, manifestLine, strlen(manifestLine));
            for (textureIndex = 0; textureIndex < (u32)work[0x95]; textureIndex++) {
                if (work[textureIndex + 0x96] != 0) {
                    sprintf(manifestLine, D_005F62B0, ((s16 *)work[0x93])[2], work[textureIndex + 0x96]);
                    func_004275a8(D_00764498, manifestLine, strlen(manifestLine));
                }
            }
            for (fileIndex = 0; fileIndex < (u32)work[0x296]; fileIndex++) {
                u8 *copyBuffer;
                s32 *item = (s32 *)((u8 *)&work[fileIndex] + 0xA5C);
                sprintf(manifestLine, D_005F62C0, ((s16 *)work[0x93])[2], *item);
                func_004275a8(D_00764498, manifestLine, strlen(manifestLine));
                sprintf(sourcePath, D_005F62D0, ((s16 *)work[0x93])[2], *item);
                func_004288d8(sourcePath, &fileStat);
                sprintf(targetPath, D_005F6310, ((s16 *)work[0x93])[2], *item);
                func_004288d8(sourcePath, &copyStat);
                chkmemAllocSiteTag(D_005F6168, 0x166);
                copyBuffer = D_008873F4[0](1, copyStat.size, 0x40000);
                if (copyBuffer != 0) {
                    if ((descriptor = func_00426cf0(sourcePath, 1, 0x1FF)) >= 0) {
                        func_00427338(descriptor, (void *)copyBuffer, copyStat.size);
                        func_00426f80(descriptor);
                        func_00428f08(&D_00763130, 0);
                    }
                    if ((descriptor = func_00426cf0(targetPath, 0x603, 0x1FF)) >= 0) {
                        func_004275a8(descriptor, (void *)copyBuffer, copyStat.size);
                        func_00426f80(descriptor);
                        func_00428f08(&D_00763130, 0);
                    }
                    jtbl_008873EC[0]((void *)copyBuffer);
                }
            }
        }
        work[0x397] = 0;
        work[0] = 5;
        break;
    }
    case 5: {
        char *p;
        s32 *hdr;
        if ((u32)work[0x397] < (u32)work[0x95]) {
            if (work[work[0x397] + 0x96] != 0) {
                sprintf(modelPath, D_005F6350, ((s16 *)((s32 *)work[0x93]))[2], work[work[0x397] + 0x96]);
                func_00440b68(&D_00763150, D_005F6168, 0x263);
                p = (char *)H_Cdvd_AcquireDirectory(modelPath, 0);
                work[0x398] = (s32)p;
                H_Cdvd_ReadSync(p);
                work[0] = 6;
            } else {
                work[0x397]++;
            }
        } else {
            FldResource_Destroy((void *)work[0x93]);
            hdr = (s32 *)work[0x93];
            hdr = (s32 *)hdr[0x291];
            K_Clump_FreeTextureNameList((void *)hdr[0x4A]);
            hdr = (s32 *)work[0x93];
            jtbl_008873EC[0]((void *)hdr[0x291]);
            hdr = (s32 *)work[0x93];
            hdr[0x291] = 0;
            work[0x93] = 0;
            work[0] = 7;
        }
        break;
    }
    case 6: {
        s32 tmp;
        sprintf(texturePath, D_005F6370, ((s16 *)work[0x93])[2], work[work[0x397] + 0x96]);
        tmp = K_TexStripLoadRecords((u8 *)work[0x398], texturePath);
        work[work[0x397] + 0x196] = tmp;
        H_Cdvd_Destroy((void *)work[0x398]);
        work[0x398] = 0;
        work[0x397]++;
        work[0] = 5;
        break;
    }
    case 7: {
        char *p;
        u8 *resource;
        u32 cleanupIndex;
        func_00440b68(&D_00763150, D_005F6168, 0x2A0);
        resource = H_Cdvd_AcquireDirectory((void *)&work[0x53], 0);
        work[0x94] = (s32)resource;
        H_Cdvd_ReadSync(resource);
        strcpy(resourcePath, D_005F63B0);
        for (p = (char *)&work[0x53]; *p != 0; p++) {
        }
        for (; *p != '/'; p--) {
        }
        strcat(resourcePath, p + 1);
        K_TexStripApplyNames((u8 *)work[0x94], resourcePath, (u8 *)work);
        H_Cdvd_Destroy((void *)work[0x94]);
        strcpy(resourcePath, D_005F63B0);
        for (p = (char *)&work[0x53]; *p != 0; p++) {
        }
        for (; *p != '/'; p--) {
        }
        strcat(resourcePath, p + 1);
        func_004288d8(resourcePath, &fileStat);
        work[0x39A] += fileStat.size;
        for (cleanupIndex = 0; cleanupIndex < (u32)work[0x95]; cleanupIndex++) {
            s32 *item = (s32 *)((u8 *)&work[cleanupIndex] + 0x658);
            if (*item != 0) {
                func_003ef1b0(*item);
                *item = 0;
            }
        }
        func_00426f80(D_00764498);
        work[0] = 1;
        break;
    }
    case 8:
        return -1;
    }
    return 0;
}

#pragma pop
// FUN_001915C0
void K_TexStripBuildTaskDestroy(u8 *arg0)
{
    s32 handle;

    handle = *(s32 *)(*(u8 **)(arg0 + 0x38) + 4);
    if (handle >= 0)
    {
        func_00428618(handle);
    }
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00191610
s32 K_TexStripBuildTaskCreate(void)
{
    void *mem;

    chkmemAllocSiteTag(D_005F6168, 0x2ED);
    mem = D_008873F4[0](1, 0xE74, 0x40000);
    if (mem == NULL)
    {
        return 0;
    }
    return (s32)kwlnTaskCreateChild((void *)(0), (const void *)(D_005F63E0), 0xF, 0, 0, K_TexStripBuildUpdate, K_TexStripBuildTaskDestroy, (u8 *)(mem));
}

// measured: MATCH (object 420/window 432). The four func_003df3c0 spill slots
// use a 16-byte union: producer &spill.s[0], signed reads spill.s[1..3],
// and unsigned allocation length spill.u[1]. The stack slots at 0x50-0x5C
// and retail saved-register allocation are unchanged.
// The `(u32)` casts on spill.s[0] and spill.s[1] in func_003deff0 reproduce retail's
// argument-materialization order (loads before the first-argument move).
// FUN_001916A0
s32 K_TexStripRecordCount(u8 *arg0, void *arg1)
{
    s32 sp[2];
    union { s32 s[4]; u32 u[4]; } spill;
    s32 var_19;
    s32 temp_18;
    s32 temp_17;
    u8 *var_16;

    var_19 = 0;
    sp[0] = *(s32 *)(arg0 + 0x110);
    sp[1] = *(s32 *)(arg0 + 0x118);
    temp_18 = func_003e2f60(3, 1, &sp[0]);
    temp_17 = func_003e2f60(2, 2, (s32 *)arg1);
    if ((temp_18 != 0) && (temp_17 != 0)) {
        goto loop_check;
loop_body:
        switch (spill.s[0]) {
        case 0x16:
            var_19 = func_003e6a90(temp_18);
            break;
        default:
            if (spill.s[1] != 0) {
                chkmemAllocSiteTag(D_005F6168, 0x330);
                var_16 = D_008873F4[0](1, spill.u[1], 0x40000);
                func_003e2910(temp_18, var_16, spill.s[1]);
            }
            func_003deff0(temp_17, (u32)spill.s[0], (u32)spill.s[1], spill.s[2], spill.s[3]);
            if (spill.s[1] != 0) {
                func_003e2ab0(temp_17, var_16, spill.s[1]);
                jtbl_008873EC[0](var_16);
            }
            break;
        }
loop_check:
        if (func_003df3c0(temp_18, &spill.s[0]) != 0) {
            goto loop_body;
        }
        func_003e2e40(temp_18, 0);
        func_003e2e40(temp_17, 0);
    }
    return var_19;
}

// FUN_00191850
s32 K_TexStripLoadUpdate(u8 *arg0)
{
    char buf240[0x40];
    char buf140[0x100];
    char buf40[0x100];
    s32 *work;
    s32 i;
    u8 *temp1;
    u8 *temp2;

    work = *(s32 **)(arg0 + 0x38);
    switch (work[0])
    {
    case 0:
        work[0x39C] = 2;
        work[0x95] = 0;
        work[0] = work[0] + 1;
        /* fallthrough */
    case 1:
        sprintf((char *)&work[0x53], D_005F63F0, work[0x39B], work[0x39C]);
        if (func_004288d8(&work[0x53], buf240) == 0)
        {
            sprintf((char *)&work[0x53], D_005F6430, work[0x39B], work[0x39C]);
            func_00440b68(&D_00763150, D_005F6168, 0x36E);
            temp1 = (u8 *)H_Cdvd_AcquireDirectory(&work[0x53], 0);
            work[0x94] = (s32)temp1;
            H_Cdvd_ReadSync(temp1);
            work[0] = 2;
            work[0x39C] = work[0x39C] + 1;
            func_00440b68(&D_00763128, &work[0x53]);
        }
        else
        {
            work[0x39C] = work[0x39C] + 1;
            if (work[0x39C] > 0xF)
            {
                work[0] = 3;
            }
        }
        break;
    case 2:
        sprintf(buf140, D_005F6450);
        strcat(buf140, (char *)&work[0x53]);
        strcat(buf140, &D_00763158);
        work[work[0x95] + 0x196] = K_TexStripRecordCount((u8 *)work[0x94], buf140);
        H_Cdvd_Destroy((u8 *)work[0x94]);
        work[0x94] = 0;
        work[0x95] = work[0x95] + 1;
        work[0] = 1;
        break;
    case 3:
        sprintf((char *)&work[0x53], D_005F6470, work[0x39B]);
        func_00440b68(&D_00763150, D_005F6168, 0x39B);
        temp2 = (u8 *)H_Cdvd_AcquireDirectory(&work[0x53], 0);
        work[0x94] = (s32)temp2;
        H_Cdvd_ReadSync(temp2);
        sprintf(buf40, D_005F6450);
        strcat(buf40, (char *)&work[0x53]);
        strcat(buf40, &D_00763158);
        K_TexStripApplyNames((u8 *)work[0x94], buf40, (u8 *)work);
        for (i = 0; i < (u32)work[0x95]; i++)
        {
            s32 *elem = (s32 *)((u8 *)work + i * 4 + 0x658);
            if (*(s32 *)((u8 *)work + i * 4 + 0x658) != 0)
            {
                func_003ef1b0(*(s32 *)((u8 *)work + i * 4 + 0x658));
                *elem = 0;
            }
        }
        H_Cdvd_Destroy((u8 *)work[0x94]);
        work[0x94] = 0;
        work[0x39B] = work[0x39B] + 1;
        if (work[0x39B] > 0x30)
        {
            work[0] = 4;
        }
        else
        {
            work[0] = 0;
        }
        break;
    case 4:
        return -1;
    default:
        break;
    }
    return 0;
}

// FUN_00191B70
void K_TexStripLoadDestroy(u8 *arg0)
{
    s32 handle;

    handle = *(s32 *)(*(u8 **)(arg0 + 0x38) + 4);
    if (handle >= 0)
    {
        func_00428618(handle);
    }
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00191BC0
s32 K_TexStripLoadTaskCreate(void)
{
    s32 ret;
    void *mem;

    chkmemAllocSiteTag(D_005F6168, 0x3D4);
    mem = D_008873F4[0](1, 0xE74, 0x40000);
    if (mem == NULL)
    {
        return 0;
    }
    ret = (s32)kwlnTaskCreateChild((void *)(0), (const void *)(D_005F63E0), 0xF, 0, 0, K_TexStripLoadUpdate, K_TexStripLoadDestroy, (u8 *)(mem));
    *(s32 *)((u8 *)mem + 0xE6C) = 0x28;
    *(s32 *)((u8 *)mem + 0xE70) = 1;
    return ret;
}

// FUN_00191C70
s32 K_TexStripCodeLogUpdate(u8 *arg0)
{
    s32 *work;
    char buf[0x80];

    work = *(s32 **)(arg0 + 0x38);
    switch (work[0])
    {
    case 0:
        work[1] = func_00468170(arg0, D_005F6490);
        work[0] = work[0] + 1;
        break;
    case 1:
        if (func_004680f0(work[1], buf) == 1)
        {
            if (buf[0] == 0)
            {
                work[0] = 2;
            }
            else
            {
                K_Clump_LogCodeCounts(buf);
            }
            kwlnTaskDestroyWithHierarchy(work[1]);
            work[0] = 0;
        }
        break;
    case 2:
        return -1;
    }
    return 0;
}

// FUN_00191D60
void K_TexStripCodeLogDestroy(u8 *arg0) {
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00191D90
s32 K_TexStripCodeLogTaskCreate(void)
{
    void *mem;

    chkmemAllocSiteTag(D_005F6168, 0x435);
    mem = D_008873F4[0](1, 0x8, 0x40000);
    if (mem == NULL)
    {
        return 0;
    }
    return (s32)kwlnTaskCreateChild((void *)(0), (const void *)(D_005F64A8), 0xF, 0, 0, K_TexStripCodeLogUpdate, K_TexStripCodeLogDestroy, (u8 *)(mem));
}

