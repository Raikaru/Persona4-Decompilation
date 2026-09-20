# Skill menu state machine: 0013ea20

Recovered with configured MWCCPS2 b210 `-O2`: **2724 executable bytes in the
2736-byte retail window**, all **94 code relocations resolved**, and twelve
verified zero alignment bytes. The compiler-owned **56-byte switch table** at
`0x00746AD0` also matches retail after resolving all fourteen entries.

## Source reconstruction

The character selected from `work + 0xF4` is a signed-halfword skill API value.
The recipient has a second, promoted word value used by the menu helper.
Keeping both values in an assignment chain reproduces their separate lifetimes
without changing the loaded value. The two stored controller-mask results are
ordinary promoted integers with values zero or `0x40`, rather than halfword
objects. Both positive query results are assigned inside their tests before
their later uses.

The four list queries pass their five actual arguments. The old trailing
register values were decompiler artifacts. All fourteen outer cases, the two
skill-result switches, the four query paths, fade behavior, and call ordering
remain intact. The existing integer-address helper replaces the old constructed
pointer arithmetic. No new compiler pragma, synthetic side effect, assembly,
or instruction padding is needed.

## Required contracts

`cmpSkill.c:0013a040` takes a word selection value and stores its low halfword.
Its third argument is never tested or otherwise consumed. The matching
definition, its declaration, and the nine source call sites now agree; the
provider still emits the exact same 32 bytes and returns one.

`cmpMain.c` declares the state argument of `0013ea20` as `u32 *`, matching the
actual word state and unsigned switch. Its one call converts the aligned
`p + 4` state pointer explicitly. The caller's emitted code is unchanged.

`00354030` explicitly returns the signed UI-state word obtained from
`nLine.c:0034bb10`. All 26 callers already consume that signed result. The
wrapper preserves its four calls and all 80 instruction bytes; the downstream
definition returns `D_00884670[0]`. This change preserves the earlier
`00354010` predicate recovery.

The target's list-query declarations now match `sdkListState.c`; its selection,
transition, animation, and sound calls were checked against their actual
providers. The `0013a530` and `0034bd60` result types are corrected without
changing calls that ignore those results.

## Measurements and proof

| Candidate | Bytes / window | Resolved differing words | Aligned edits |
| --- | ---: | ---: | ---: |
| Frozen saved body | 2752 / 2736 | 448 | 73 |
| Query arity and dead-character contract | 2756 / 2736 | 541 | 75 |
| Signed-halfword characters | 2736 / 2736 | 472 | 93 |
| Query result test | 2736 / 2736 | 472 | 92 |
| Promoted recipient carrier | 2732 / 2736 | 464 | 49 |
| Promoted controller masks | 2724 / 2736 | 0 | 0 |

Raw differing-word counts are not comparable across shifted instruction streams;
the aligned residuals identified the source mechanisms. Two already-dispatched
follow-up spellings reproduced the zero and are retained as diagnostic history.

Eight fresh formal compilations across four complete owners report
**133 MATCH / 14 ASM -> 134 MATCH / 13 ASM**, with `0013ea20` the only status
change. All **146 other functions** preserve instruction bytes and canonical
relocations. All **twelve preexisting allocated data sections** are unchanged.
The only added allocated section is the independently proved target switch
table. Its fourteen relative labels resolve to the actual retail destinations.

The earlier `0013f720`, `0013fb50`, `0013c700`, `0013f4d0`, and `00354010`
functions remain fully resolved and exact. Scoped lint reports zero errors and
the same four existing warnings. `git apply --check --whitespace=error-all`
passes. No production owner changed during the worker's proof.

Evidence: `build/first-party-resume-now/camp/skill3ea20/`. The immutable proposed
owners, source patch, compiler history, and `proof/` are under `release/`;
eight compiler receipts, logs, objects, and verifier outputs are under `formal/`.
