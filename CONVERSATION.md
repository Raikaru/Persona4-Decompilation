# This folder is linked to an ongoing conversation

Session id: `01a002a5-f866-7000-a28e-dea7a2f78d1a`

The full transcript is registered in this machine's omp session store under
the working-directory key `-Projects-Persona 3 Decomp`. Running `omp
--continue` from `~/Projects/Persona 3 Decomp` (or a subdirectory) resumes
this exact conversation, with full history of the campaign below.

## What this session did

Continued the Persona 4 USA (`SLUS_217.82`) matching decompilation campaign.
Landed four commits on `main`, moving first-party MATCH from 6101 to 6104 of
7866 (77.6%), all gate-clean with both output SHA1s unchanged:

- `15523fd3` -- reconstructed 3 never-attempted first-party functions.
- `9e109717` -- `tools/recon_dis.py` disassembles through a headless Ghidra
  running `ghidra-emotionengine-reloaded`, which decodes Emotion Engine FPU
  multiply-accumulate ops (`mula.s`/`madda.s`/`madd.s`/...) that rabbitizer
  cannot; established the 256-byte cliff (every match this campaign has
  produced came from a retail window <= 256B).
- `213e897d` -- `tools/hw_access_census.py` and `tools/reachability_census.py`
  found 21 unimplemented functions genuinely touch hardware (need real
  `volatile`) and showed 98% of remaining first-party work is reachable from
  plain C (only `movz`/`movn` never appears in any matched function).
- `33dc7013` -- corrected the never-attempted census three times in one
  session, each time downward (2274 -> 1186 -> 1061 -> effectively ~0 under
  256B); a fourth reconstruction wave closed nothing, confirming the cheap
  cold-reconstruction tail is exhausted.

Two `volatile`-abuse matches were caught and reverted mid-session: bodies
that reached `nd 0` only by casting a non-hardware pointer to `volatile` to
defeat MWCCPS2 b210's CSE. Both are archived under `build/*_REJECTED*` with
the reasoning. `decomp_lint`'s H001 rule had two real holes found and fixed
in the same investigation: it missed a volatile CAST expression (only
matched declarations), and its function-scope waiver let a `measured:` note
written for a pragma silently license an unrelated `volatile` in the same
body.

## This machine's environment (set up this session)

- Git clone of `github.com/Raikaru/Persona4-Decompilation`, co-located with
  `jj` (`jj git init --colocate`; installed via `cargo install --locked
  jj-cli` since no package was available).
- `orig/SLUS_217.82` (retail ELF, sha1 `4eeec036...`, matches
  `config/target.json`) plus `SYSTEM.CNF`, copied from the workstation.
- The full archive corpus under `build/` (near-miss bodies, attempt records,
  campaign tooling) and the `ee-gcc` toolchain under `build/toolchain/g296`.
- MWCCPS2 3.0.1 build 210, run through `wibo` (`~/.local/bin/wibo`) via
  wrapper scripts at `~/opt/mwcc-wrapper.sh` / `~/opt/mwld-wrapper.sh`.
  Verified byte-exact against the workstation: a full `tools/verify.py` run
  here reproduces 6104/7866 first-party MATCH exactly.
  `tools/verify_config.local.json` (gitignored) points at these wrappers.
- IDA Pro 9.4 at `~/ida-pro-9.4`, with a headless `idalib` Python venv at
  `~/idavenv`. Its stock MIPS module has NATIVE `r5900l`/`r5900b` (EE)
  support -- no community extension needed, unlike Ghidra. Its Hex-Rays
  decompiler (`hexmips.so`) correctly disassembles every EE FPU-MAC and MMI
  opcode but cannot LOWER the accumulator-chain ones to C; they surface as
  `__asm { ... }` islands in otherwise-correct pseudocode.

**Push works.** `gh` (GitHub CLI) is installed at `~/.local/bin/gh` and
already authenticated (keyring-backed, `repo`+`workflow` scopes), and git's
`credential.helper` is set to `!gh auth git-credential`, so both `git push`
and `jj git push` work over HTTPS without any extra setup. An earlier draft
of this file claimed otherwise; that was wrong -- `which gh` failed only
because `~/.local/bin` was not yet on `PATH` in the shell that checked it,
while git itself invokes the credential helper by absolute path regardless.

## `tools/ida_headstart.py` and `docs/ida_headstart/`

New this session: batch-decompiles every still-unmatched first-party
function through Hex-Rays and writes the pseudocode under
`docs/ida_headstart/<mirrored src path>`, specifically OUTSIDE `src/` so
`decomp_lint`'s source walk never sees it (confirmed: file count unchanged
at 326 after adding it). Reference only, never compiled. 1756 of 1762
targets decompiled successfully in one 5.6-minute run.

Verified against real campaign targets, not synthetic examples: on a fresh
never-attempted 224B function it produced code needing essentially no
further work; on an 848B DMA routine it correctly reconstructed nested
unrolled loops that `src/generated/`'s existing m2c output is documented to
mis-render, and rendered retail's hardware addresses as `MEMORY[0x1000D000]`
etc. -- independently corroborating `tools/hw_access_census.py`'s findings
from a completely separate tool.

## Later session: two reconstruction waves, verified 6122/7866 MATCH

Pivoted off a user question ("is there a point to continuing?") by measuring
that residual-polishing avenues (permuter, flag sweeps, twin joins) were
exhausted at ~0.6% yield, while cold reconstruction of never-attempted
functions with an already-MATCH sibling in the same file was untested at
this scale. Two 10-lane waves against `build/recon_queue.json` /
`build/recon_queue_fresh.json` (ranked never-attempted functions, filtered to
real full-length attempts) plus one hand reconstruction
(`func_0036aa20`) ahead of wave 5 closed 12 + 5 = 17 functions total,
ending at a verified 6122/7866 first-party MATCH, 0 MISMATCH. Sizes
432-956B, well above the previously-recorded 256-byte
cliff -- the real predictor turned out to be a same-file MATCHed sibling
giving a struct-layout/calling-convention anchor, not absolute size. See
`docs/matching.md`'s "Wave 5 breaks the cliff" section for the full writeup.

Two lane-reported "matches" from wave 5 were actually `decomp_lint`
H001/H009 violations (a `volatile` compiler-steering cast, and a
hand-written `__asm__` block) caught during independent post-wave
verification and reverted to honest `INCLUDE_ASM`, net -2 before the
corrected commit. `build/recon_methodology.md` (the standing per-lane
instruction set for this kind of wave) now has a pitfall entry telling
future lanes not to reach for either idiom. One live MISMATCH left by a
wave-6 lane in `k_fldFrame.c` was likewise caught and reverted before commit
-- always re-verify every lane-touched file yourself; do not trust a lane's
self-reported MATCH/SKIPPED status.

Commits: `e9b07c44` (wave 5, +11 after reverting 2 violations),
`cc178a78` (wave 6, +5). Both gate-clean, both output SHA1s unchanged
(`3d1d3d2b...`, `4eeec036...`), CI green.
