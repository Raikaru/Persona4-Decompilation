#!/usr/bin/env python3
"""Assemble splat GAS with GNU binutils for the PS2 R5900 and keep the
output compatible with mwldps2.

This is intentionally boring and close to the standard splat/mwcc PS2 flow:
  splat asm -> mipsel-linux-gnu-as -march=r5900 -mabi=eabi -> mwldps2

The only project-specific help here is for bytes that splat currently emits as
code even though the retail image uses data in executable ranges.  The R5900
assembler rejects some of those words (for example ddiv/ddivu); valid-looking
wrong words are found by comparing non-relocated object bytes to the retail
image.  Those source lines are rewritten to `.word` using splat's byte comment.

usage: asm.py <in.s> <out.o> [reference.bin <vram_base_hex> <vram_lo_hex>]
"""
from __future__ import annotations

import json
import os
import re
import shlex
import struct
import subprocess
import sys
import tempfile
from dataclasses import dataclass
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]

BYTES_RE = re.compile(r"/\*\s*[0-9A-Fa-f]+\s+([0-9A-Fa-f]+)\s+([0-9A-Fa-f]{8})")
ERR_RE = re.compile(r"(?:^|:)(\d+):\s+(?:Error|Fatal error)|Line (\d+) # (?:Error|Fatal error)")
LOCAL_REF_RE = re.compile(r"\.L([0-9A-Fa-f]{8})\b")
RELOC_MASK_SIZE = {2: 4, 4: 4, 5: 4, 6: 4, 7: 4}
GNU_NOISE_SECTIONS = (".data", ".bss", ".reginfo", ".MIPS.abiflags", ".pdr", ".gnu.attributes")


@dataclass(frozen=True)
class Tool:
    argv: tuple[str, ...]
    wsl: bool = False


def _load_cfg() -> dict:
    cfg: dict = {}
    for name in ("verify_config.json", "verify_config.local.json"):
        p = REPO / "tools" / name
        if p.is_file():
            cfg.update(json.loads(p.read_text()))
    return cfg


def _is_windows_path(path: str) -> bool:
    return len(path) >= 3 and path[1] == ":" and path[2] in ("/", "\\")


def _wslpath(path: Path | str) -> str:
    p = subprocess.run(
        ["wsl", "-d", os.environ.get("P4_WSL_DISTRO", "Debian"), "--", "wslpath", "-a", str(path).replace("\\", "/")],
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
    )
    if p.returncode:
        raise RuntimeError(p.stdout)
    return p.stdout.strip()


def _which(cmd: str) -> bool:
    return subprocess.run(
        ["where" if os.name == "nt" else "which", cmd],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    ).returncode == 0


def _wsl_has(cmd: str) -> bool:
    return subprocess.run(
        ["wsl", "-d", os.environ.get("P4_WSL_DISTRO", "Debian"), "--", "sh", "-lc", f"command -v {shlex.quote(cmd)} >/dev/null"],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    ).returncode == 0


def find_gnu_tool(name: str, env_name: str) -> Tool:
    override = os.environ.get(env_name)
    if override:
        parts = tuple(shlex.split(override, posix=os.name != "nt"))
        if not parts:
            sys.exit(f"asm: {env_name} is empty")
        return Tool(parts, wsl=parts[0] == "wsl")
    cfg = _load_cfg()
    if cfg.get(env_name.lower()):
        return Tool((str(cfg[env_name.lower()]),))
    if _which(name):
        return Tool((name,))
    if _wsl_has(name):
        return Tool(("wsl", "-d", os.environ.get("P4_WSL_DISTRO", "Debian"), "--", name), wsl=True)
    sys.exit(
        f"asm: could not find {name}. Install binutils-mipsel-linux-gnu in WSL "
        f"or set {env_name}."
    )


def _tool_arg(tool: Tool, arg: str | Path) -> str:
    s = str(arg)
    if tool.wsl and (_is_windows_path(s) or "\\" in s):
        return _wslpath(s)
    return s


def _run_tool(tool: Tool, args: list[str | Path], *, stdin: bytes | None = None) -> subprocess.CompletedProcess:
    cmd = list(tool.argv) + [_tool_arg(tool, a) for a in args]
    return subprocess.run(cmd, input=stdin, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)


def byte_line(line: str) -> str | None:
    """Rewrite one instruction line to a .word directive from its byte comment."""
    s = line.lstrip()
    if s.startswith(".word") or s.startswith(".byte"):
        return None
    m = BYTES_RE.search(line)
    if not m:
        return None
    vram, hx = m.group(1), m.group(2)
    word = int(hx[6:8] + hx[4:6] + hx[2:4] + hx[0:2], 16)  # file bytes -> LE word
    indent = line[:len(line) - len(s)]
    return f"{indent}.word 0x{word:08X}  /* {vram}: data */\n"


def _assemble_once(asm_tool: Tool, objcopy_tool: Tool, lines: list[str], out_path: str | Path,
                   src_parent: Path, keep_text: bool) -> bytes:
    out = Path(out_path)
    with tempfile.NamedTemporaryFile("w", suffix=".s", delete=False, dir=str(out.parent)) as tf:
        tf.writelines(lines)
        tmp = Path(tf.name)
    try:
        proc = _run_tool(
            asm_tool,
            [
                "-EL",
                "-I", src_parent,
                "-I", REPO / "asm",
                "-G", "128",
                "-march=r5900",
                "-mabi=eabi",
                "-no-pad-sections",
                "-o", out,
                tmp,
            ],
        )
        log = proc.stdout.decode("utf-8", "replace")
        if proc.returncode:
            return log.encode()
        remove = list(GNU_NOISE_SECTIONS)
        if not keep_text:
            remove.insert(0, ".text")
        clean_args: list[str | Path] = []
        for sec in remove:
            clean_args += ["-R", sec]
        clean_args.append(out)
        clean = _run_tool(objcopy_tool, clean_args)
        if clean.returncode:
            return clean.stdout
        return b""
    finally:
        tmp.unlink(missing_ok=True)


def _elf_sections(path: str | Path):
    d = Path(path).read_bytes()
    if d[:4] != b"\x7fELF":
        return "<", [], d
    endian = "<" if d[5] == 1 else ">"
    shoff = struct.unpack_from(endian + "I", d, 0x20)[0]
    shentsize, shnum, shstrndx = struct.unpack_from(endian + "HHH", d, 0x2E)
    sections = []
    for i in range(shnum):
        off = shoff + i * shentsize
        fields = struct.unpack_from(endian + "IIIIIIIIII", d, off)
        sections.append({
            "idx": i,
            "name_off": fields[0],
            "type": fields[1],
            "flags": fields[2],
            "addr": fields[3],
            "offset": fields[4],
            "size": fields[5],
            "link": fields[6],
            "info": fields[7],
            "addralign": fields[8],
            "entsize": fields[9],
        })
    if sections:
        shstr = sections[shstrndx]
        blob = d[shstr["offset"]:shstr["offset"] + shstr["size"]]
        for s in sections:
            end = blob.find(b"\0", s["name_off"])
            s["name"] = blob[s["name_off"]:end if end >= 0 else len(blob)].decode("ascii", "replace")
    return endian, sections, d


def _section_bytes(path: str | Path, name: str) -> bytes:
    _endian, sections, d = _elf_sections(path)
    for s in sections:
        if s.get("name") == name:
            return d[s["offset"]:s["offset"] + s["size"]]
    return b""


def _relocated_words(path: str | Path, target_section: str = ".text") -> set[int]:
    endian, sections, d = _elf_sections(path)
    by_idx = {s["idx"]: s for s in sections}
    target_idx = next((s["idx"] for s in sections if s.get("name") == target_section), None)
    if target_idx is None:
        return set()
    out: set[int] = set()
    for s in sections:
        if s["type"] != 9 or s["info"] != target_idx:  # SHT_REL for target section
            continue
        entsize = s["entsize"] or 8
        for off in range(s["offset"], s["offset"] + s["size"], entsize):
            r_offset, r_info = struct.unpack_from(endian + "II", d, off)
            rtype = r_info & 0xFF
            mask = RELOC_MASK_SIZE.get(rtype)
            if mask is None:
                continue
            for i in range(0, mask, 4):
                out.add(((r_offset + i) // 4) * 4)
    return out


def _error_lines(log: bytes) -> list[int]:
    text = log.decode("utf-8", "replace")
    lines = []
    for m in ERR_RE.finditer(text):
        lines.append(int(m.group(1) or m.group(2)))
    return sorted(set(lines))

def ensure_local_labels(lines: list[str]) -> list[str]:
    """Keep local branch labels self-contained.

    If a missing `.Lxxxxxxxx` target is present in this asm file, add the label
    before that byte-comment address.  If the target is outside this file, the
    referencing line is data that only happened to decode as a branch; rewrite
    that branch to `.word` so GNU as does not emit an unresolvable relocation."""
    refs = {".L" + m.group(1).upper() for line in lines for m in LOCAL_REF_RE.finditer(line)}
    if not refs:
        return lines
    defined = set()
    addr_to_index = {}
    for idx, line in enumerate(lines):
        s = line.strip()
        if s.startswith(".L") and s.endswith(":"):
            defined.add(s[:-1])
        m = BYTES_RE.search(line)
        if m:
            addr_to_index[int(m.group(1), 16)] = idx
    missing = sorted(refs - defined, key=lambda x: int(x[2:], 16))
    if not missing:
        return lines
    out = list(lines)
    inserted = 0
    external = set()
    for label in missing:
        idx = addr_to_index.get(int(label[2:], 16))
        if idx is None:
            external.add(label)
            continue
        out.insert(idx + inserted, f"  {label}:\n")
        inserted += 1
    if external:
        out2 = []
        for line in out:
            if any(label in line for label in external):
                repl = byte_line(line)
                out2.append(repl if repl else line)
            else:
                out2.append(line)
        out = out2
    return out


def assemble(src_path: str | Path, out_path: str | Path, asm_tool: Tool, objcopy_tool: Tool,
             ref: bytes | None = None, vram: int = 0, ref_lo: int = 0, keep_text: bool = True):
    src = Path(src_path).resolve()
    out = Path(out_path).resolve()
    lines = ensure_local_labels(src.read_text().splitlines(keepends=True))
    # Pass 1: assembler-error-driven conversion of impossible R5900 words.
    log = b""
    for _ in range(128):
        log = _assemble_once(asm_tool, objcopy_tool, lines, out, src.parent, keep_text)
        bad = _error_lines(log)
        if not bad:
            break
        changed = False
        for ln in bad:
            i = ln - 1
            if 0 <= i < len(lines):
                repl = byte_line(lines[i])
                if repl and repl != lines[i]:
                    lines[i] = repl
                    changed = True
        if not changed:
            return False, log.decode("utf-8", "replace"), lines
    else:
        return False, "too many assembler repair passes", lines

    # Pass 2: compare non-relocated words to retail and convert valid-looking data.
    if ref is not None and keep_text:
        addr_line: dict[int, int] = {}
        for idx, line in enumerate(lines):
            m = BYTES_RE.search(line)
            if m and ": data" not in line:
                addr_line[int(m.group(1), 16)] = idx
        for _ in range(128):
            text = _section_bytes(out, ".text")
            orig = ref[ref_lo:ref_lo + len(text)]
            relocated = _relocated_words(out, ".text")
            diff_words = sorted({
                (i // 4) * 4
                for i in range(min(len(text), len(orig)))
                if text[i] != orig[i] and ((i // 4) * 4) not in relocated
            })
            if not diff_words:
                break
            changed = False
            for wo in diff_words:
                idx = addr_line.get(vram + wo)
                if idx is None:
                    continue
                repl = byte_line(lines[idx])
                if repl and repl != lines[idx]:
                    lines[idx] = repl
                    changed = True
            if not changed:
                return False, f"unresolved non-reloc diffs at {[hex(vram+w) for w in diff_words[:8]]}", lines
            log = _assemble_once(asm_tool, objcopy_tool, lines, out, src.parent, keep_text)
            if log:
                return False, log.decode("utf-8", "replace"), lines
        log = _assemble_once(asm_tool, objcopy_tool, lines, out, src.parent, keep_text)
        if log:
            return False, log.decode("utf-8", "replace"), lines
    return True, "", lines


if __name__ == "__main__":
    if len(sys.argv) < 3:
        sys.exit("usage: asm.py <in.s> <out.o> [reference.bin vram_base_hex vram_lo_hex]")
    ref = vram = lo = None
    if len(sys.argv) >= 6:
        ref = Path(sys.argv[3]).read_bytes()
        vram = int(sys.argv[4], 16)
        lo = int(sys.argv[5], 16)
    asm_tool = find_gnu_tool("mipsel-linux-gnu-as", "P4_AS")
    objcopy_tool = find_gnu_tool("mipsel-linux-gnu-objcopy", "P4_OBJCOPY")
    ok, log, lines = assemble(
        sys.argv[1],
        sys.argv[2],
        asm_tool,
        objcopy_tool,
        ref=ref,
        vram=vram or 0,
        ref_lo=lo or 0,
        keep_text=True,
    )
    Path(sys.argv[1]).write_text("".join(lines))
    if not ok:
        sys.stderr.write(log + "\n")
        sys.exit(1)
