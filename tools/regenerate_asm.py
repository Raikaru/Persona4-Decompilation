#!/usr/bin/env python3
"""Reconstruct the audited fallback corpus from an isolated, pinned retail split.

The manifest is a byte-preservation contract, not a list of current consumers.
Recipes retain historical spelling and spans explicitly; they never ingest an
existing fallback. Hand-maintained exceptions stay tracked and are only checked.
"""
from __future__ import annotations

import argparse
import hashlib
import importlib.metadata
import json
import os
from pathlib import Path, PurePosixPath
import re
import shutil
import subprocess
import sys
import tempfile

import extract_nonmatching_asm as extractor
import verify

REPO = Path(__file__).resolve().parents[1]
MANIFEST = "config/generated_asm.json"


class RegenerationError(RuntimeError):
    pass


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def checked_path(root: Path, relative: str) -> Path:
    parts = PurePosixPath(relative).parts
    if (not parts or PurePosixPath(relative).is_absolute() or ".." in parts
            or "\\" in relative or "/".join(parts) != relative):
        raise RegenerationError(f"unsafe manifest path: {relative}")
    path = root.joinpath(*parts)
    for parent in (path, *path.parents):
        if parent == root:
            break
        if parent.is_symlink():
            raise RegenerationError(f"{relative}: symlink is not a generated regular file")
    return path


def load_manifest(root: Path) -> dict:
    manifest = json.loads((root / MANIFEST).read_text(encoding="utf-8"))
    if manifest.get("version") != 1:
        raise RegenerationError(f"{MANIFEST}: unsupported manifest version")
    seen = set()
    for kind in ("generated", "retained"):
        for entry in manifest[kind]:
            relative = entry["path"]
            checked_path(root, relative)
            if not relative.startswith("asm/nonmatchings/") or not relative.endswith(".s"):
                raise RegenerationError(f"{relative}: outside the fallback corpus")
            if relative in seen:
                raise RegenerationError(f"{relative}: duplicate manifest classification")
            seen.add(relative)
            if not re.fullmatch(r"[0-9a-f]{64}", entry["sha256"]):
                raise RegenerationError(f"{relative}: invalid SHA256")
    return manifest


def check_inputs(root: Path, manifest: dict) -> None:
    for relative, expected in manifest["inputs"].items():
        actual = digest(checked_path(root, relative).read_bytes())
        if actual != expected:
            raise RegenerationError(
                f"{relative}: generator input changed (expected {expected}, got {actual}); "
                "audit the drift and update the manifest deliberately")
    requirements = (root / "requirements-python.txt").read_text(encoding="utf-8")
    for package, expected in re.findall(r"^([\w-]+)(?:\[[^]]+\])?==([^\s#]+)", requirements, re.M):
        try:
            actual = importlib.metadata.version(package)
        except importlib.metadata.PackageNotFoundError:
            actual = "not installed"
        if actual != expected:
            raise RegenerationError(
                f"{package}: expected {expected}, got {actual}; run "
                f"{sys.executable} -m pip install -r requirements-python.txt")


def preflight(root: Path, manifest: dict, *, require_generated: bool) -> None:
    """Check the complete classification before removing or replacing any output."""
    expected = {entry["path"] for kind in ("generated", "retained") for entry in manifest[kind]}
    for directory, directories, files in os.walk(root / "asm/nonmatchings", followlinks=False):
        for name in directories:
            path = Path(directory) / name
            if path.is_symlink():
                raise RegenerationError(f"{path.relative_to(root)}: symlink directory in fallback corpus")
        for name in files:
            path = Path(directory) / name
            relative = path.relative_to(root).as_posix()
            if relative not in expected:
                raise RegenerationError(f"{relative}: unclassified file; retain or audit it explicitly")
    for kind in ("generated", "retained"):
        for entry in manifest[kind]:
            relative = entry["path"]
            path = checked_path(root, relative)
            if not path.exists():
                if kind == "retained" or require_generated:
                    raise RegenerationError(f"{relative}: missing {kind} file")
                continue
            if not path.is_file():
                raise RegenerationError(f"{relative}: not a regular file")
            actual = digest(path.read_bytes())
            if actual != entry["sha256"]:
                raise RegenerationError(
                    f"{relative}: unexpected local bytes (expected {entry['sha256']}, got {actual}); "
                    "preserve your edit and audit it before regeneration")


class SplitIndex:
    """One linear scan of each split; each function is subsequently sliced once."""
    def __init__(self, asm_dir: Path):
        self.functions: dict[int, tuple[list[str], int, int]] = {}
        for name in extractor.SPLAT_FILES:
            path = asm_dir / name
            if not path.is_file():
                continue
            lines = path.read_text(encoding="utf-8").splitlines(keepends=True)
            starts = [i for i, line in enumerate(lines) if extractor.GLABEL_RE.match(line)]
            for start, end in zip(starts, starts[1:] + [len(lines)]):
                for index in range(start + 1, end):
                    match = extractor.VRAM_RE.search(lines[index])
                    if match:
                        self.functions.setdefault(int(match[1], 16), (lines, start, end))
                        break

    def slice(self, address: int) -> list[str]:
        if address not in self.functions:
            raise RegenerationError(f"0x{address:08x}: no glabel in fresh split")
        lines, start, end = self.functions[address]
        return extractor.clean_slice(lines[start:end])


def canonical_names(root: Path, windows: dict) -> tuple[re.Pattern, dict[str, str]]:
    text = (root / "config/symbol_addrs.txt").read_text(encoding="utf-8")
    names = {}
    for name, value in re.findall(r"^([\w.$]+)\s*=\s*0x([0-9a-fA-F]+)", text, re.M):
        address = f"{int(value, 16):08x}"
        if address in windows and name != f"func_{address}":
            names[name] = f"func_{address}"
    alternatives = "|".join(re.escape(name) for name in sorted(names, key=len, reverse=True))
    return re.compile(r"(?<![\w.$])(" + alternatives + r")(?![\w.$])"), names


def render(entry: dict, index: SplitIndex, retail: verify.RetailElf,
           windows: dict, names: tuple[re.Pattern, dict[str, str]]) -> bytes:
    relative = entry["path"]
    match = re.fullmatch(r"func_([0-9a-f]{8})", PurePosixPath(relative).stem)
    if not match or match[1] not in windows:
        raise RegenerationError(f"{relative}: not a canonical function path")
    address = int(match[1], 16)
    canonical_size = windows[match[1]]
    correction = entry.get("correction", {})
    size = correction.get("legacy_size", canonical_size)
    recipe = entry["recipe"]
    if recipe == "synthesis":
        lines = extractor.synthesise(address, size, retail.bytes_at(address, size), windows)
    elif recipe in ("slice", "slice-canonical"):
        lines = index.slice(address)
        if size != canonical_size:
            # Eight archived extractions predate splitting off an adjacent nullsub.
            # Recover that instruction span from fresh splat, not saved .s text.
            if size != canonical_size + 16 or windows.get(f"{address + canonical_size:08x}") != 16:
                raise RegenerationError(f"{relative}: legacy adjacent-nullsub contract changed")
            adjacent = index.slice(address + canonical_size)
            lines += [line for line in adjacent if not extractor.GLABEL_RE.match(line)]
    else:
        raise RegenerationError(f"{relative}: unknown recipe {recipe!r}")
    lines = extractor.HEADER_LINES + lines + [f".size func_{address:08x}, 0x{size:x}\n"]
    if extractor.count_placeholder_words(lines) * 4 != size:
        raise RegenerationError(f"{relative}: fresh slice does not fill recorded 0x{size:x}-byte span")
    text = "".join(lines)
    if recipe == "slice-canonical":
        pattern, replacements = names
        text = pattern.sub(lambda m: replacements[m[0]], text)
    for old, new in correction.get("symbol_spellings", []):
        pattern = r"(?<![\w.$])" + re.escape(old) + r"(?![\w.$])"
        text, count = re.subn(pattern, lambda m: new, text)
        if not count:
            raise RegenerationError(f"{relative}: historical symbol {old} no longer occurs")
    if "glabel" in correction:
        text, count = re.subn(r"^glabel \S+$", "glabel " + correction["glabel"], text, flags=re.M)
        if count != 1:
            raise RegenerationError(f"{relative}: expected exactly one glabel")
    repairs = {int(value, 16) for value in correction.get("word_repairs", [])}
    if repairs:
        lines = text.splitlines(keepends=True)
        for i, line in enumerate(lines):
            match = extractor.BYTES_RE.search(line)
            if match and int(match[1], 16) in repairs:
                replacement = extractor.byte_line(line)
                if replacement is None:
                    raise RegenerationError(f"{relative}: retail-word repair lost its byte comment")
                lines[i] = replacement
                repairs.remove(int(match[1], 16))
        if repairs:
            raise RegenerationError(f"{relative}: missing retail-word repair addresses {sorted(repairs)}")
        text = "".join(lines)
    output = text.encode("utf-8")
    actual = digest(output)
    if actual != entry["sha256"]:
        raise RegenerationError(
            f"{relative}: unexplained regenerated text drift (expected {entry['sha256']}, got {actual}); "
            "do not overwrite the baseline; inspect pinned split inputs and recorded corrections")
    return output


def regenerate(root: Path, manifest: dict, retail_path: Path, *, check: bool, fresh: bool) -> None:
    check_inputs(root, manifest)
    target = json.loads((root / "config/target.json").read_text(encoding="utf-8"))
    windows_doc = json.loads((root / "tools/slus21782_functions.json").read_text(encoding="utf-8"))
    if windows_doc["program"] != "SLUS_217.82" or windows_doc["sha1"] != target["elf"]["sha1"]:
        raise RegenerationError("canonical function map does not describe the configured retail ELF")
    retail = verify.RetailElf(str(retail_path), target, windows_doc["sha1"])
    image = retail.bytes_at(int(target["elf"]["load_vram"], 16), int(target["elf"]["load_size"], 16))
    if hashlib.sha1(image).hexdigest() != target["image"]["sha1"]:
        raise RegenerationError("retail loadable image SHA1 mismatch")
    preflight(root, manifest, require_generated=check)
    if fresh:
        for entry in manifest["generated"]:
            checked_path(root, entry["path"]).unlink(missing_ok=True)
        print(f"Removed {len(manifest['generated'])} classified outputs before fresh generation", flush=True)
    with tempfile.TemporaryDirectory(prefix="p4-regenerate-asm-") as temporary:
        scratch = Path(temporary)
        (scratch / "config").mkdir()
        for relative in ("config/slus21782.yaml", "config/symbol_addrs.txt"):
            shutil.copyfile(root / relative, scratch / relative)
        (scratch / "image.bin").write_bytes(image)
        process = subprocess.run(
            [sys.executable, "-m", "splat", "split", "config/slus21782.yaml"],
            cwd=scratch, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
        if process.returncode:
            raise RegenerationError(f"fresh splat split failed ({process.returncode}):\n{process.stdout}")
        index = SplitIndex(scratch / "asm")
        names = canonical_names(root, windows_doc["windows"])
        output_root = scratch / "outputs"
        for entry in manifest["generated"]:
            output = render(entry, index, retail, windows_doc["windows"], names)
            path = output_root / entry["path"]
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(output)
        # A concurrent editor during the split must not lose their changes either.
        preflight(root, manifest, require_generated=check)
        if not check:
            for entry in manifest["generated"]:
                path = checked_path(root, entry["path"])
                path.parent.mkdir(parents=True, exist_ok=True)
                if not path.exists():
                    # Exclusive creation avoids overwriting a file appearing after preflight.
                    with path.open("xb") as handle:
                        handle.write((output_root / entry["path"]).read_bytes())
        print(f"{'Checked' if check else 'Regenerated'} {len(manifest['generated'])} exact fallback files; "
              f"retained {len(manifest['retained'])} hand-maintained files unchanged")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    mode = parser.add_mutually_exclusive_group()
    mode.add_argument("--check", action="store_true", help="generate in scratch and require every existing baseline byte")
    mode.add_argument("--fresh", action="store_true", help="guard local edits, remove classified outputs, then regenerate from scratch")
    parser.add_argument("--retail", type=Path, default=Path(os.environ.get("P4_RETAIL_ELF", REPO / "orig/SLUS_217.82")),
                        help="private retail ELF (default: P4_RETAIL_ELF or orig/SLUS_217.82)")
    args = parser.parse_args()
    try:
        regenerate(REPO, load_manifest(REPO), args.retail, check=args.check, fresh=args.fresh)
    except (RegenerationError, OSError, ValueError, KeyError) as error:
        parser.exit(1, f"regenerate-asm: {error}\n")


if __name__ == "__main__":
    main()
