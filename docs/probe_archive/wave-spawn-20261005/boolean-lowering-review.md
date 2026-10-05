# Wave Boolean lowering review — 2026-10-05

## Result

There is no `daddiu reg,zero,1` precedent among the 63 compiled, unguarded C functions in `proof/capture/public.o`. The sole `daddiu` in that set is a useful narrow-to-wide conversion precedent: `func_0048a980+0xec` emits `daddiu a2,zero,2` for a `u8` local assigned to a wider live variable. This is a concrete source-based hypothesis for the final Wave residual, not a measured Wave fix.

No MWCC compilation, source changes, upload, or search of stopped domains was performed. Compiler help was invoked without input files.

## Scope and evidence

- Read `repo/docs/STYLE.md` first
- Enumerated the markers using `tools.verify.scan_markers` in both the current owner and its captured public source: 73 markers, 63 unguarded C definitions, 10 guarded definitions
- Scanned only the 63 unguarded functions extracted from `proof/capture/public.o`; decoded every instruction word and selected major opcode 0x19 (`daddiu`)
- Captured public object SHA-256: `95770a0cb1f1858d32831694b1bfd1e9a08fdec1d0f650ecc3db29d6494f4b74`
- Existing capture audit associates the object with public base `90f7c9c8321347f7fa6b572183a7edc33205a7de`; no fresh whole-owner compile was run

## Exact compiled-source predecessor

`repo/src/promoted/code1_0048.c:2103–2104` scopes `opt_common_subs off` and `opt_propagation off`. Its `func_0048a980` source region is identical to `proof/capture/public.c`.

At lines 2128 and 2140–2144:

```c
u32 selected = (((xx > yy) ? 1 : 0) ^ 1) & 0xFF;
/* other declarations */
if (!(zz <= *(f32 *)((u8 *)arg0 + selected * 16 + selected * 4))) {
    u8 third = 2;
    selected = third;
}
i = (u8)selected;
```

The capture has these instructions:

```text
+b0  c.ole.s f2,f3
+b4  addiu v1,zero,1       [word 0x24030001]
+b8  bc1f +c4
+bc  nop
+c0  move v1,zero
+c4  xori v1,v1,1
+c8  andi a2,v1,0xff
... selected-element lookup ...
+e0  c.ole.s f4,f0
+e4  bc1t +f0
+e8  nop
+ec  daddiu a2,zero,2      [word 0x64060002]
+f0  andi a3,a2,0xff
+f4  addiu v1,a3,1
+f8  addiu a2,zero,3
```

A fresh read-only comparison established that the entire 584-byte function from the captured object equals retail at 0x0048a980, with zero relocations. Both the `daddiu` and the neighboring ordinary `addiu` instructions are exact retail bytes.

The narrow local is the relevant distinction: a logical condition within the same function still materializes one through `addiu`, while the narrow local copied into a wider variable uses `daddiu`. The opcode alone does not prove causality, but it is a real compiled-source predecessor, unlike an assumed Boolean rule.

## Bounded proposed experiment

The direct predecessor suggests replacing the already-required `preroll = 1` branch assignment by a narrow Boolean lifetime copied into the existing live flag, while keeping the live flag and all uses truthful:

```c
u8 initialPreroll = 1;
preroll = initialPreroll;
```

This differs from declaring the long-lived `preroll` variable itself `u8`. Start under the current propagation-off setting; the donor also has common-subexpression elimination off, which is a separately grounded setting to consider only if measured. Do not assume the two pragmas or later explicit `(u8)` conversion are necessary without testing. Do not add the donor’s mask or arithmetic merely to reproduce bytes. If the temporary adds an instruction, changes other control flow, or lacks a defensible source lifetime, retain the residual rather than forcing it.

## Compiler help

The installed b210 wrapper’s `-help all` describes `-bool on|off` solely as enabling the C++ `bool` type and `true`/`false` constants. It is not a C Boolean-lowering switch, and `STYLE.md` explicitly calls for project integer predicate types. The help advertises broad optimization levels and intrinsics, but no setting selecting `addiu` versus `daddiu` for Boolean constants. No unsupported pragma is proposed.

## Remaining limits

The submitted Wave baseline is still the parent-reported one-instruction residual at +228, `addiu s6,zero,1` versus retail `daddiu s6,zero,1`. This review did not compile a replacement or rerun its gates. Native and whole-owner verification remain the parent’s responsibility for any accepted experiment.
