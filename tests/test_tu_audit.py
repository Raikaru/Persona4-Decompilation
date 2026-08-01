"""Unit tests for tools/tu_audit.py's TU-boundary clustering logic.

All fixtures are synthetic: a tiny image, a tiny function map, and fabricated
P3 source evidence.  Nothing here depends on repo content, the retail image,
or the P3 checkout.
"""
from __future__ import annotations

import importlib.util
import struct
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "tu_audit.py"
SPEC = importlib.util.spec_from_file_location("p4_tu_audit", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
tu_audit = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(tu_audit)

BASE = 0x00100000
GP = 0x007690F0

# --- instruction builders -------------------------------------------------
LUI = 0x0F << 26  # opcode 0x0f
ADDIU = 0x09 << 26  # opcode 0x09
LW = 0x23 << 26  # opcode 0x23
JR_RA = 0x03E00008
NOP = 0x00000000


def lui(rt: int, hi: int) -> int:
    return LUI | (rt << 16) | (hi & 0xFFFF)


def addiu(rt: int, rs: int, lo: int) -> int:
    return ADDIU | (rs << 21) | (rt << 16) | (lo & 0xFFFF)


def lw(rt: int, rs: int, lo: int) -> int:
    return LW | (rs << 21) | (rt << 16) | (lo & 0xFFFF)


def jal(target: int, pc: int) -> int:
    return 0x0C000000 | (((target >> 2) & 0x03FFFFFF))


def addiu_sp(lo: int) -> int:
    return addiu(29, 29, lo)


def make_image(
    windows: dict[int, int], bodies: dict[int, list[int]], size: int | None = None
) -> bytes:
    """Build a byte image from {address: size} and {address: [words]}.

    Windows must be contiguous from the lowest address.  ``size`` overrides
    the image length so synthetic data references can land inside the image.
    """
    end = max(a + s for a, s in windows.items())
    if size is not None:
        end = BASE + size
    image = bytearray(end - BASE)
    for address, words in bodies.items():
        offset = address - BASE
        struct.pack_into("<%dI" % len(words), image, offset, *words)
    return bytes(image)


class DecodeTests(unittest.TestCase):
    def test_calls_refs_and_scheduler_flag(self) -> None:
        f0 = 0x100000  # lui/addiu rodata ref, jr+nop -> scheduler off
        f1 = 0x100010  # jal f0, jr+filled -> scheduler on
        f2 = 0x100020  # gp-relative load, jr+nop
        f3 = 0x100030  # lui + sw (load/store pairing), no jr
        windows = {f0: 0x10, f1: 0x10, f2: 0x10, f3: 0x10}
        bodies = {
            f0: [lui(2, 0x0010), addiu(2, 2, 0x0200), JR_RA, NOP],
            f1: [jal(f0, f1), addiu_sp(0xFFE0), JR_RA, addiu_sp(0x20)],
            f2: [lw(2, 28, 0x70), JR_RA, NOP, NOP],
            f3: [lui(4, 0x0010), lw(2, 4, 0x0238), addiu(2, 2, 0x10), NOP],
        }
        image = make_image(windows, bodies, size=0x1000)
        # A small gp keeps the gp-relative reference inside the synthetic image.
        small_gp = 0x100050
        decoded = tu_audit.decode_functions(image, windows, small_gp, BASE)

        self.assertEqual(decoded[f0]["calls"], set())
        self.assertEqual(decoded[f0]["refs"], {0x00100200})
        self.assertEqual(decoded[f0]["sched"], 0.0)
        self.assertEqual(decoded[f0]["end"], 0x100010)

        self.assertEqual(decoded[f1]["calls"], {f0})
        self.assertEqual(decoded[f1]["sched"], 1.0)  # 1 of 1 jr filled

        self.assertEqual(decoded[f2]["refs"], {small_gp + 0x70})
        self.assertEqual(decoded[f2]["sched"], 0.0)

        self.assertEqual(decoded[f3]["refs"], {0x00100238})
        self.assertIsNone(decoded[f3]["sched"])  # no jr $ra

    def test_code_region_and_out_of_image_refs_filtered(self) -> None:
        f0 = 0x100000
        f1 = 0x100010
        windows = {f0: 0x10, f1: 0x10}
        # lui/addiu to a sibling function (function pointer) and to an IO port
        # far above the image: neither is owned data, neither may appear.
        bodies = {
            f0: [lui(2, 0x0010), addiu(2, 2, 0x0010), JR_RA, NOP],
            f1: [lui(2, 0x1F80), addiu(2, 2, 0x1000), JR_RA, NOP],
        }
        image = make_image(windows, bodies, size=0x1000)
        decoded = tu_audit.decode_functions(image, windows, GP, BASE)
        self.assertEqual(decoded[f0]["refs"], set())
        self.assertEqual(decoded[f1]["refs"], set())


class PairEvidenceTests(unittest.TestCase):
    def _decoded(self, sched_a, sched_b, calls_a=None, refs_a=None, refs_b=None):
        a, b = 0x100000, 0x100010
        return a, b, {
            a: {"calls": set(calls_a or ()), "refs": set(refs_a or ()),
                "sched": sched_a, "end": 0x100010},
            b: {"calls": set(), "refs": set(refs_b or ()),
                "sched": sched_b, "end": 0x100020},
        }

    def test_p3_file_closes_high(self) -> None:
        a, b, decoded = self._decoded(1.0, 1.0)
        order = [a, b]
        boundaries, _ = tu_audit.build_pair_evidence(
            order, decoded, {a: {"src/x.c"}, b: {"src/x.c"}})
        self.assertTrue(boundaries[0]["closed"])
        self.assertEqual(boundaries[0]["score"], tu_audit.SCORE_P3_FILE)
        self.assertEqual(boundaries[0]["signals"]["p3_file"], ["src/x.c"])

    def test_p3_conflict_vetoes_even_with_call(self) -> None:
        a, b = 0x100000, 0x100010
        _, _, decoded = self._decoded(1.0, 1.0, calls_a=[b])
        order = [a, b]
        boundaries, _ = tu_audit.build_pair_evidence(
            order, decoded, {a: {"src/x.c"}, b: {"src/y.c"}})
        self.assertTrue(boundaries[0]["conflict"])
        self.assertFalse(boundaries[0]["closed"])

    def test_call_plus_rare_data_is_high(self) -> None:
        a, b = 0x100000, 0x100010
        _, _, decoded = self._decoded(1.0, 1.0, calls_a=[b],
                                      refs_a=[0x00760000], refs_b=[0x00760000])
        order = [a, b]
        boundaries, freq = tu_audit.build_pair_evidence(order, decoded, {})
        # The shared ref is used by exactly these two functions: rare.
        self.assertEqual(freq[0x00760000], 2)
        self.assertEqual(boundaries[0]["score"],
                         tu_audit.SCORE_CALL + tu_audit.SCORE_DATA_RARE)
        self.assertTrue(boundaries[0]["closed"])

    def test_call_plus_common_data_stays_medium(self) -> None:
        # The shared ref is used by 8 functions across the image, so it is a
        # hot global: it contributes nothing and the pair stays MEDIUM.
        ref = 0x00760000
        a, b = 0x100000, 0x100010
        decoded = {
            a: {"calls": {b}, "refs": {ref}, "sched": 1.0, "end": 0x100010},
            b: {"calls": set(), "refs": {ref}, "sched": 1.0, "end": 0x100020},
        }
        # 6 unrelated functions also touch the hot global.
        for index in range(6):
            addr = 0x200000 + 0x10 * index
            decoded[addr] = {"calls": set(), "refs": {ref},
                             "sched": 1.0, "end": addr + 0x10}
        order = [a, b]
        boundaries, _ = tu_audit.build_pair_evidence(order, decoded, {})
        self.assertEqual(boundaries[0]["score"], tu_audit.SCORE_CALL)
        self.assertTrue(boundaries[0]["closed"])  # MEDIUM tier

    def test_sched_signal_recorded_but_zero_weight(self) -> None:
        a, b, decoded = self._decoded(0.0, 0.0)
        order = [a, b]
        boundaries, _ = tu_audit.build_pair_evidence(order, decoded, {})
        self.assertEqual(boundaries[0]["signals"]["sched"], 0.0)
        self.assertEqual(boundaries[0]["score"], 0)
        self.assertFalse(boundaries[0]["closed"])

    def test_differing_sched_gives_no_signal(self) -> None:
        a, b, decoded = self._decoded(1.0, 0.0)
        order = [a, b]
        boundaries, _ = tu_audit.build_pair_evidence(order, decoded, {})
        self.assertNotIn("sched", boundaries[0]["signals"])

    def test_one_sided_p3_is_neutral(self) -> None:
        a, b, decoded = self._decoded(1.0, 1.0)
        order = [a, b]
        boundaries, _ = tu_audit.build_pair_evidence(
            order, decoded, {a: {"src/x.c"}})
        self.assertNotIn("p3_file", boundaries[0]["signals"])
        self.assertFalse(boundaries[0]["closed"])

    def test_gap_boundary_never_closes(self) -> None:
        # Windows across the one real hole in the map are not adjacent in
        # memory; even shared P3 files must not merge them.
        a, b = 0x100000, 0x200000
        decoded = {
            a: {"calls": set(), "refs": set(), "sched": 1.0, "end": 0x100010},
            b: {"calls": set(), "refs": set(), "sched": 1.0, "end": 0x200010},
        }
        boundaries, _ = tu_audit.build_pair_evidence(
            [a, b], decoded, {a: {"src/x.c"}, b: {"src/x.c"}})
        self.assertEqual(boundaries[0]["signals"], {"gap": True})
        self.assertFalse(boundaries[0]["closed"])


def _boundary(a: int, b: int, closed: bool, score: int) -> dict:
    return {"a": a, "b": b, "signals": {}, "score": score,
            "closed": closed, "conflict": False}


class GroupExtractionTests(unittest.TestCase):
    def test_maximal_runs_and_tiers(self) -> None:
        order = [0x100000 + 0x10 * i for i in range(7)]
        boundaries = [
            _boundary(order[0], order[1], True, 5),   # 0-1 HIGH
            _boundary(order[1], order[2], False, 0),  # 1-2 open
            _boundary(order[2], order[3], True, 2),   # 2-3
            _boundary(order[3], order[4], True, 2),   # 3-4 MEDIUM run
            _boundary(order[4], order[5], False, 0),  # 4-5 open
            _boundary(order[5], order[6], True, 5),   # 5-6 HIGH
        ]
        groups = tu_audit.extract_groups(order, boundaries)
        self.assertEqual([g["members"] for g in groups],
                         [[0x100000, 0x100010],
                          [0x100020, 0x100030, 0x100040],
                          [0x100050, 0x100060]])
        self.assertEqual([g["tier"] for g in groups],
                         ["HIGH", "MEDIUM", "HIGH"])
        self.assertEqual([g["min_score"] for g in groups], [5, 2, 5])

    def test_open_boundary_never_dangles_a_member(self) -> None:
        # Regression: the member connected only by an OPEN boundary used to be
        # appended to the previous run, dragging its score to 0.
        order = [0x100000, 0x100010, 0x100020, 0x100030]
        boundaries = [
            _boundary(order[0], order[1], True, 5),   # 0-1 HIGH
            _boundary(order[1], order[2], False, 0),  # 1-2 open
            _boundary(order[2], order[3], True, 5),   # 2-3 HIGH
        ]
        groups = tu_audit.extract_groups(order, boundaries)
        self.assertEqual([g["members"] for g in groups],
                         [[0x100000, 0x100010], [0x100020, 0x100030]])
        self.assertTrue(all(g["min_score"] == 5 for g in groups))

    def test_singletons_are_not_groups(self) -> None:
        order = [0x100000, 0x100010, 0x100020]
        boundaries = [
            _boundary(order[0], order[1], False, 0),
            _boundary(order[1], order[2], True, 5),
        ]
        groups = tu_audit.extract_groups(order, boundaries)
        # f0 is an isolated singleton; only the closed f1-f2 boundary forms.
        self.assertEqual([g["members"] for g in groups], [[order[1], order[2]]])


class SchedulerStretchTests(unittest.TestCase):
    def test_stretches_are_maximal_same_flag_runs(self) -> None:
        order = [0x100000 + 0x10 * i for i in range(7)]
        flags = [1.0, 1.0, None, 0.0, 0.0, 0.0, 1.0]
        decoded = {a: {"sched": f} for a, f in zip(order, flags)}
        stretches = tu_audit.scheduler_stretches(order, decoded)
        self.assertEqual(
            [(s["members"], s["flag"]) for s in stretches],
            [([0x100000, 0x100010], 1.0), ([0x100030, 0x100040, 0x100050], 0.0)],
        )


class FileAgreementTests(unittest.TestCase):
    def test_single_file_and_split_files(self) -> None:
        g1 = {"members": [0x100000, 0x100010]}
        g2 = {"members": [0x100020, 0x100030]}
        current_files = {
            0x100000: ["src/a.c"],
            0x100010: ["src/a.c"],
            0x100020: ["src/a.c", "src/b.c"],
            0x100030: ["src/b.c"],
        }
        single, split, with_markers = tu_audit.file_agreement(
            [g1, g2], current_files)
        self.assertEqual(single, 1)  # g1 sits entirely in src/a.c
        self.assertEqual(split, ["src/a.c"])  # a.c spans g1 and g2
        self.assertEqual(with_markers, 2)


class BuildAuditTests(unittest.TestCase):
    def _fixture(self):
        f0, f1, f2, f3 = (0x100000, 0x100010, 0x100020, 0x100030)
        windows = {f0: 0x10, f1: 0x10, f2: 0x10, f3: 0x10}
        bodies = {
            f0: [lui(2, 0x0010), addiu(2, 2, 0x0200), JR_RA, NOP],
            f1: [jal(f0, f1), addiu_sp(0xFFE0), JR_RA, addiu_sp(0x20)],
            f2: [lui(2, 0x0010), addiu(2, 2, 0x0200), JR_RA, NOP],
            # f3 calls f2 AND shares the same rare rodata ref as f2: together
            # those signals earn HIGH without any P3 evidence.
            f3: [jal(f2, f3), lui(2, 0x0010), addiu(2, 2, 0x0200), JR_RA],
        }
        image = make_image(windows, bodies, size=0x1000)
        # f0/f1 share a P3 file; the f1-f2 boundary has no evidence at all.
        p3_files = {f0: {"src/x.c"}, f1: {"src/x.c"}}
        current_files = {
            f0: ["src/a.c"],
            f1: ["src/a.c"],
            f2: ["src/b.c"],
            f3: ["src/b.c"],
        }
        return windows, image, p3_files, current_files

    def test_end_to_end_audit(self) -> None:
        windows, image, p3_files, current_files = self._fixture()
        audit = tu_audit.build_audit(windows, image, GP, p3_files, current_files)
        self.assertEqual(audit["functions"], 4)
        self.assertEqual(audit["summary"]["groups"]["high"], 2)
        self.assertEqual(audit["summary"]["groups"]["medium"], 0)
        self.assertEqual(audit["summary"]["groups"]["members"], 4)
        self.assertEqual(audit["summary"]["groups"]["unassigned"], 0)

        members = [g["members"] for g in audit["groups"]]
        self.assertEqual(members, [[0x100000, 0x100010], [0x100020, 0x100030]])

        by_start = {g["members"][0]: g for g in audit["groups"]}
        first = by_start[0x100000]
        self.assertEqual(first["tier"], "HIGH")
        self.assertEqual(first["p3_files"], [("src/x.c", 2)])
        self.assertEqual(first["current_files"], [("src/a.c", 2)])
        self.assertEqual(first["internal_calls"], 1)  # f1 calls f0
        self.assertEqual(first["callers_local"], "1/1")  # caller f1 is in-span

        self.assertEqual(audit["summary"]["groups"]["single_file_groups"], 2)
        self.assertEqual(audit["summary"]["files"]["split_across_groups"], 0)


if __name__ == "__main__":
    unittest.main()
