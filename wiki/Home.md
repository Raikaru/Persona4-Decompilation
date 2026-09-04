# Persona 4 (PS2) Decompilation

A byte-exact reconstruction of *Shin Megami Tensei: Persona 4* (USA,
`SLUS_217.82`) in C. This wiki is the long-form documentation; the
[README](https://github.com/Raikaru/Persona4-Decompilation#readme) is the short
version.

## Pages

- [Getting Started](Getting-Started) - toolchain, setup, the first build.
- [How Matching Works](How-Matching-Works) - markers, the verifier, what
  `MATCH` proves and what it does not, the SHA-1 gates.
- [Matching a Function](Matching-a-Function) - the measure/iterate loop with
  `fndiff.py`, picking a target, when to stop.
- [The Retail Build](The-Retail-Build) - which compiler and flags built which
  part of the executable, and how the tree reproduces that per unit.
- [RenderWare](RenderWare) - the RenderWare Graphics 3.7 block, the verbatim
  port, the vendored headers, and the mapping tools.
- [Repository Layout](Repository-Layout) - what every directory and config file
  is for.
- [Tools](Tools) - every script under `tools/` and `build/` in one place.
- [Compiler Floors](Compiler-Floors) - residuals that are compiler state, not
  source shape; do not fight these.
- [Rules](Rules) - the invariants every commit keeps (markers, pragmas, no
  inline asm, symbol checks) and why each one exists.

## Where things stand

The README's status table is regenerated from the verifier on every push and
the badges come from [decomp.dev](https://decomp.dev/Raikaru/Persona4-Decompilation).
In prose: Atlus's own code ("first-party", 6,861 functions once the
RenderWare span is filed under middleware) is about 88% byte-exact; the remainder is retail assembly linked verbatim so the
image still reproduces. The RenderWare, CRI, Sony SDK and C-runtime windows
are tracked separately - the RenderWare part is being recovered from source,
the rest is prebuilt vendor code that stays as assembly.
