"""Guards on requirements-python.txt.

The byte-exact build depends on splat's disassembly, so the Python toolchain
has to be reproducible rather than "whatever PyPI serves today".  Both checks
here correspond to CI failures that were invisible locally:

  * an unpinned ``splat64>=0.39`` resolved to 0.50.0 in a fresh container;
  * splat64 declares spimdisasm/rabbitizer as OPTIONAL extras, so installing
    it without ``[mips]`` produces a splat that cannot import.
"""

from __future__ import annotations

import re
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
REQUIREMENTS = REPO / "requirements-python.txt"

# name, optional [extras], then the version specifier.
REQUIREMENT_RE = re.compile(
    r"^(?P<name>[A-Za-z0-9._-]+)"
    r"(?:\[(?P<extras>[^\]]*)\])?"
    r"(?P<spec>.*)$"
)


def requirement_lines() -> list[str]:
    text = REQUIREMENTS.read_text(encoding="utf-8")
    lines = []
    for raw in text.splitlines():
        line = raw.split("#", 1)[0].strip()
        if line:
            lines.append(line)
    return lines


def parse(line: str) -> tuple[str, set[str], str]:
    match = REQUIREMENT_RE.match(line)
    assert match is not None, line
    extras = match.group("extras") or ""
    return (
        match.group("name"),
        {e.strip() for e in extras.split(",") if e.strip()},
        match.group("spec").strip(),
    )


class RequirementPinningTests(unittest.TestCase):
    def test_every_requirement_is_pinned_exactly(self) -> None:
        lines = requirement_lines()
        self.assertTrue(lines, "requirements-python.txt has no requirements")
        for line in lines:
            name, _extras, spec = parse(line)
            with self.subTest(requirement=name):
                self.assertIsNotNone(
                    re.fullmatch(r"==[A-Za-z0-9][A-Za-z0-9.!+_-]*", spec),
                    f"{name} must name one concrete version with ==, got {spec!r}",
                )

    def test_splat_requests_the_mips_extra(self) -> None:
        """Without [mips], splat installs but cannot import spimdisasm."""
        for line in requirement_lines():
            name, extras, _spec = parse(line)
            if name == "splat64":
                self.assertIn(
                    "mips",
                    extras,
                    "splat64 must be installed as splat64[mips]; spimdisasm and "
                    "rabbitizer are optional extras, not hard dependencies",
                )
                return
        self.fail("splat64 is not listed in requirements-python.txt")

    def test_disassembler_versions_are_stated_explicitly(self) -> None:
        """The [mips] extra's ranges would drift; these decide emitted bytes."""
        pinned = {parse(line)[0] for line in requirement_lines()}
        for package in ("spimdisasm", "rabbitizer"):
            self.assertIn(
                package,
                pinned,
                f"{package} affects disassembly output and must be pinned "
                "directly, not left to splat64's version range",
            )




if __name__ == "__main__":
    unittest.main()
