# Calendar panel 0027bf30: native C match

The 2026-09-26 rewrite is now recovered in `src/promoted/code1_0027.c`.
The configured b210 compiler produces all 2,992 retail bytes, and the whole
owner verifies at 60 MATCH with no ASM or regressions.

Three source shapes closed the remaining gap:

* Assigning `(CalendarRectangle){0, 0, 640, 480}` to the renderer's rectangle
  retains the compound literal's temporary at stack offset `0xC0` and the
  destination at `0xF0`. Two named initialized rectangles let the compiler
  discard the first copy; the compound literal accounts for the retail copy
  without dummy storage or an unused source statement.
* Keeping the rectangle declaration before the six appearance delays gives
  those delays offset `0xD0`. The color union describes the byte components
  and their raw single-word transport; copying that value prepares the
  renderer's color address before the copy, as retail does.
* Explicit byte-clear loops give each buffer a cursor and a count. Their
  initialization order reproduces retail's pointer-before-count setup.

The date declarations are corrected as a group. `func_001060b0` returns
`s16`; `func_001104d0`, `func_001105b0`, and `func_00110d60` consume `s32`
dates. Correcting only the getter regressed two existing callers because
their consumers still had narrow declarations. Correcting both ends
preserves every existing match and removes the inconsistent contracts.

Evidence is retained under `build/first-party-finish-20260929/worker5`:
`calendar-owner-verify.json`, the calendar candidate/object/diff directory,
and the measurement scripts `calendar_finish.py` and `install_calendar.py`.
The original archived rewrite remains as the historical 22-edit baseline.
