#!/usr/bin/env python3
"""Persona 4 USA matching build driver.

Pipeline:
  verified retail ELF --extract--> image.bin
  matched src/*.c --mwccgap (locally configured MWCC + GNU R5900 assembler)--> objects
  unmatched ranges --GNU R5900 assembler--> objects, carved around linked C
  data ranges --.incbin image.bin--> objects
  all objects --mwldps2--> a loadable image, then byte/hash checked against retail.

Machine-specific paths belong in tools/build_config.local.json (gitignored) or
the P4_MWCC, P4_RETAIL_ELF, P4_AS, and P4_OBJCOPY environment variables.  The
retail target identity and memory layout come from config/target.json.
"""
import argparse
import hashlib
import json
import os
import re
import struct
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
BUILD = REPO / "build"
ASM = REPO / "asm"
OBJ = BUILD / "obj"
IMAGE = REPO / "image.bin"
TARGET_PATH = REPO / "config" / "target.json"
sys.path.insert(0, str(REPO / "tools"))
import verify as V  # noqa: E402
import asm as A  # noqa: E402


def parse_int(value):
    return int(value, 0) if isinstance(value, str) else int(value)


def load_target():
    try:
        target = json.loads(TARGET_PATH.read_text(encoding="utf-8"))
        elf, image = target["elf"], target["image"]
        segments = target["segments"]
    except (OSError, ValueError, KeyError, TypeError) as exc:
        sys.exit(f"build: invalid {TARGET_PATH.relative_to(REPO)}: {exc}")
    required = ("filename", "size", "sha1", "entry", "gp", "load_offset", "load_vram", "load_size")
    if any(key not in elf for key in required) or any(key not in image for key in ("size", "sha1")):
        sys.exit("build: target.json is missing required ELF or image metadata")
    normalized = []
    for segment in segments:
        try:
            start, end = parse_int(segment["start"]), parse_int(segment["end"])
            name = segment["name"]
        except (KeyError, TypeError, ValueError) as exc:
            sys.exit(f"build: invalid target segment: {exc}")
        if not isinstance(name, str) or start >= end:
            sys.exit("build: target.json has an invalid segment range")
        normalized.append((name, "code" if name.startswith("code") else "data", start, end))
    vram, image_size = parse_int(elf["load_vram"]), parse_int(image["size"])
    if parse_int(elf["load_size"]) != image_size:
        sys.exit("build: target.json ELF and image sizes disagree")
    if not normalized or normalized[0][2] != vram or normalized[-1][3] - vram != image_size:
        sys.exit("build: target.json segments do not cover exactly the loadable image")
    if any(a[3] != b[2] for a, b in zip(normalized, normalized[1:])):
        sys.exit("build: target.json segments are not contiguous")
    return target, normalized


TARGET, TARGET_SEGMENTS = load_target()
ELF_TARGET = TARGET["elf"]
IMAGE_TARGET = TARGET["image"]
VRAM = parse_int(ELF_TARGET["load_vram"])
IMAGE_SIZE = parse_int(IMAGE_TARGET["size"])
IMAGE_SHA1 = IMAGE_TARGET["sha1"]
RETAIL_SHA1 = ELF_TARGET["sha1"]
# (name, kind, file-offset lo, file-offset hi); code regions get carved for C.
SEGMENTS = [(name, kind, start - VRAM, end - VRAM)
            for name, kind, start, end in TARGET_SEGMENTS]
BYTES_RE = re.compile(r"/\*\s*[0-9A-Fa-f]+\s+([0-9A-Fa-f]+)\s+[0-9A-Fa-f]{8}")


def cfg():
    c = {}
    for name in ("build_config.json", "build_config.local.json"):
        path = REPO / "tools" / name
        if path.is_file():
            try:
                c.update(json.loads(path.read_text(encoding="utf-8")))
            except ValueError as exc:
                sys.exit(f"build: invalid {path.relative_to(REPO)}: {exc}")
    c["mwcc"] = os.environ.get("P4_MWCC", c.get("mwcc"))
    c["retail_elf"] = os.environ.get("P4_RETAIL_ELF", c.get("retail_elf"))
    c["ld_exe"] = c.get("ld_exe") or (
        str(Path(c["mwcc"]).with_name("mwldps2.exe")) if c.get("mwcc") else None
    )
    default_optimization = TARGET.get("compiler", {}).get("optimization", "-O2")
    c["cflags"] = c.get("cflags", [default_optimization])
    if not isinstance(c["cflags"], list) or not all(isinstance(flag, str) for flag in c["cflags"]):
        sys.exit("build: cflags in tools/build_config*.json must be a JSON string list")
    c["compile_flags"] = [*c["cflags"], "-Iinclude"]
    return c


def sh(cmd, **kw):
    p = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, **kw)
    if p.returncode:
        sys.stderr.write(p.stdout)
        sys.exit(f"build: command failed: {cmd[0]}")
    return p.stdout


def retail_load(c):
    path_value = c.get("retail_elf")
    if not path_value:
        sys.exit("build: set retail_elf in tools/build_config.local.json or P4_RETAIL_ELF")
    path = Path(path_value)
    try:
        elf = path.read_bytes()
    except OSError as exc:
        sys.exit(f"build: cannot read retail ELF {path}: {exc}")
    if len(elf) != parse_int(ELF_TARGET["size"]):
        sys.exit(f"build: retail ELF size mismatch (expected {ELF_TARGET['size']})")
    if hashlib.sha1(elf).hexdigest() != RETAIL_SHA1:
        sys.exit("build: retail ELF SHA-1 mismatch")
    if len(elf) < 52 or elf[:4] != b"\x7fELF" or elf[4:6] != b"\x01\x01":
        sys.exit("build: retail ELF is not a 32-bit little-endian ELF")
    elf_type, machine, _version, entry, phoff, *_rest = struct.unpack_from("<HHIIIIIHHHHHH", elf, 16)
    if elf_type != 2 or machine != 8 or entry != parse_int(ELF_TARGET["entry"]):
        sys.exit("build: retail ELF header does not match config/target.json")
    phentsize, phnum = struct.unpack_from("<HH", elf, 0x2A)
    candidates = []
    for index in range(phnum):
        header = phoff + index * phentsize
        if header + 32 > len(elf):
            sys.exit("build: retail ELF program header table is truncated")
        fields = struct.unpack_from("<IIIIIIII", elf, header)
        segment = dict(zip(
            ("type", "offset", "vaddr", "paddr", "filesz", "memsz", "flags", "align"), fields
        ))
        if segment["type"] == 1 and segment["filesz"] and (segment["flags"] & 1):
            candidates.append(segment)
    loads = [item for item in candidates
             if item["vaddr"] <= entry < item["vaddr"] + item["memsz"]]
    if len(loads) != 1:
        sys.exit("build: expected exactly one executable PT_LOAD containing entry point")
    load = loads[0]
    expected = {
        "offset": parse_int(ELF_TARGET["load_offset"]),
        "vaddr": VRAM,
        "filesz": IMAGE_SIZE,
    }
    if any(load[key] != value for key, value in expected.items()):
        sys.exit("build: retail ELF PT_LOAD layout does not match config/target.json")
    end = load["offset"] + load["filesz"]
    if end > len(elf):
        sys.exit("build: retail ELF PT_LOAD extends beyond the file")
    payload = elf[load["offset"]:end]
    if hashlib.sha1(payload).hexdigest() != IMAGE_SHA1:
        sys.exit("build: retail ELF loadable image SHA-1 mismatch")
    return elf, load, payload


def validate_image():
    try:
        image = IMAGE.read_bytes()
    except OSError as exc:
        sys.exit(f"build: cannot read image.bin: {exc}")
    if len(image) != IMAGE_SIZE or hashlib.sha1(image).hexdigest() != IMAGE_SHA1:
        sys.exit("build: image.bin does not match config/target.json")
    return image


def extract_image(c):
    _elf, _load, image = retail_load(c)
    temporary = IMAGE.with_name(f".{IMAGE.name}.tmp")
    temporary.write_bytes(image)
    temporary.replace(IMAGE)


def patch_align1(path, sec):
    d = bytearray(path.read_bytes())
    shoff = struct.unpack_from("<I", d, 0x20)[0]
    she, shn, shx = struct.unpack_from("<HHH", d, 0x2e)
    sto = struct.unpack_from("<IIIIII", d, shoff + shx * she)[4]

    def nm(n):
        e = d.find(b"\0", sto + n)
        return d[sto + n:e].decode()
    for i in range(shn):
        o = shoff + i * she
        if nm(struct.unpack_from("<I", d, o)[0]) == sec:
            struct.pack_into("<I", d, o + 0x20, 1)
    path.write_bytes(d)


def progbitsify(path, names=(".sbss", ".bss")):
    """Convert a compiled object's NOBITS data sections (.sbss/.bss) to PROGBITS
    backed by real zero bytes. Retail keeps these small-bss regions inside the
    loadable image as zeros, so linking them as zero-filled PROGBITS reproduces
    the bytes and keeps file-offset == vaddr through the linked image (mwldps2
    will not advance the file offset across a NOBITS section placed mid-image)."""
    d = bytearray(path.read_bytes())
    shoff = struct.unpack_from("<I", d, 0x20)[0]
    she, shn, shx = struct.unpack_from("<HHH", d, 0x2e)
    sto = struct.unpack_from("<IIIIII", d, shoff + shx * she)[4]

    def nm(n):
        e = d.find(b"\0", sto + n)
        return d[sto + n:e].decode()
    for i in range(shn):
        o = shoff + i * she
        name_off, s_type = struct.unpack_from("<II", d, o)
        size = struct.unpack_from("<I", d, o + 0x14)[0]
        if s_type == 8 and size and nm(name_off) in names:  # SHT_NOBITS
            zoff = len(d)
            d += b"\x00" * size
            struct.pack_into("<I", d, o + 0x04, 1)      # sh_type -> PROGBITS
            struct.pack_into("<I", d, o + 0x10, zoff)   # sh_offset -> the zeros
    path.write_bytes(d)


# ---------------------------------------------------------------- symbol table

def load_lcf_symbols():
    """Symbols the linker must DEFINE: _gp, recovered data symbols, and splat's
    auto undefined lists. Recovered *function* symbols are defined by the asm
    objects, so they are intentionally excluded here to avoid duplicates."""
    gp = parse_int(ELF_TARGET["gp"])
    defs = {}  # name -> addr
    rec = REPO / "config" / "symbols_recovered.txt"
    if rec.is_file():
        for line in rec.read_text().splitlines():
            m = re.match(r"\s*([A-Za-z_.$][\w.$]*)\s*=\s*(0x[0-9A-Fa-f]+).*?type:(\w+)", line)
            if not m:
                continue
            name, addr, kind = m.group(1), int(m.group(2), 16), m.group(3)
            if kind == "gp":
                if addr != gp:
                    sys.exit("build: recovered _gp conflicts with config/target.json")
            elif kind == "data":
                defs[name] = addr
    for fname in ("undefined_syms_auto.txt", "undefined_funcs_auto.txt"):
        p = REPO / fname
        if not p.is_file():
            continue
        for line in p.read_text().splitlines():
            m = re.match(r"\s*([A-Za-z_.$][\w.$]*)\s*=\s*(0x[0-9A-Fa-f]+|\d+)", line)
            if m and m.group(1) not in defs:
                defs[m.group(1)] = int(m.group(2), 0)
    return gp, defs


def load_symbol_names():
    names = set()
    p = REPO / "config" / "symbol_addrs.txt"
    if p.is_file():
        for line in p.read_text().splitlines():
            m = re.match(r"\s*([A-Za-z_.$][\w.$]*)\s*=", line)
            if m:
                names.add(m.group(1))
    return names


def load_symbol_addr_map():
    """name -> address for every entry in config/symbol_addrs.txt."""
    out = {}
    p = REPO / "config" / "symbol_addrs.txt"
    if p.is_file():
        for line in p.read_text().splitlines():
            m = re.match(r"\s*([A-Za-z_.$][\w.$]*)\s*=\s*(0[xX][0-9A-Fa-f]+|\d+)\s*;", line)
            if m:
                out[m.group(1)] = int(m.group(2), 0)
    return out


def c_object_exports(obj_path):
    """Global defined symbol names exported by a compiled C object."""
    obj = V.ObjectFile(obj_path)
    return {s["name"] for s in obj.symbols
            if s["name"] and s.get("shndx", 0) != 0}


def load_windows():
    path = REPO / "tools" / "slus21782_functions.json"
    try:
        data = json.loads(path.read_text(encoding="utf-8"))
        if data["sha1"] != RETAIL_SHA1:
            raise ValueError("retail SHA-1 mismatch")
        return sorted(int(address, 16) for address in data["windows"])
    except (OSError, ValueError, KeyError, TypeError) as exc:
        sys.exit(f"build: invalid authoritative function windows {path.name}: {exc}")


# ---------------------------------------------------------------- C-object choice

DATA_SECTIONS = (".rodata", ".data", ".sdata", ".sbss", ".bss")


def _s16(x):
    x &= 0xFFFF
    return x - 0x10000 if x & 0x8000 else x


def section_relocs(obj, target_idx):
    """(offset, r_type, symbol_name) for relocations targeting a section."""
    out = []
    for s in obj.sh:
        if s["type"] == 9 and s["info"] == target_idx:  # SHT_REL for this section
            syms = obj.symtabs[s["link"]]
            ent = s["entsize"] or 8
            for j in range(s["size"] // ent):
                ro, ri = struct.unpack_from("<II", obj.data, s["offset"] + j * ent)
                nm = syms[ri >> 8]["name"] if (ri >> 8) < len(syms) else None
                out.append((ro, ri & 0xFF, nm))
    return out


def recover_section_bases(obj, real, retail, gp):
    """shndx -> recovered base address (from matched functions' relocs to the
    object's own data symbols). Only sections with a single consistent vote."""
    import collections
    sym = {}
    for s in obj.symbols:
        if s["name"]:
            sym.setdefault(s["name"], (s.get("shndx", 0), s["value"]))
    secname = {s["idx"]: s.get("name", "") for s in obj.sh}
    votes = collections.defaultdict(collections.Counter)
    for m in real:
        try:
            body, rels = obj.function(m["name"])
        except KeyError:
            continue
        win = retail.bytes_at(m["addr"], len(body))
        pend = collections.defaultdict(list)
        for r in rels:
            off, t, nm = r["offset"], r["r_type"], r["symbol"]
            if not nm or nm not in sym or off + 4 > len(win):
                continue
            shndx, stval = sym[nm]
            if shndx == 0 or secname.get(shndx) not in DATA_SECTIONS:
                continue
            wc, wr = struct.unpack_from("<I", body, off)[0], struct.unpack_from("<I", win, off)[0]
            if t == 4:
                a = (((wr & 0x03FFFFFF) << 2) | ((m["addr"] + off) & 0xF0000000)) - ((wc & 0x03FFFFFF) << 2)
                votes[shndx][a - stval] += 1
            elif t == 5:
                pend[nm].append((wc, wr))
            elif t == 6:
                for hc, hr in pend[nm]:
                    a = (((hr & 0xFFFF) << 16) + _s16(wr)) - (((hc & 0xFFFF) << 16) + _s16(wc))
                    votes[shndx][a - stval] += 1
                pend[nm] = []
            elif t == 7:
                votes[shndx][gp + (_s16(wr) - _s16(wc))] += 1
    return {idx: c.most_common(1)[0][0] for idx, c in votes.items() if len(c) == 1}


def plan_data_sections(obj, real, retail, gp, resolvable):
    """Decide whether all of a TU's owned data sections can be placed byte-exact.
    Returns (ok, {section_name: (base, size)}).

    mwldps2 concatenates same-name sections in object order, aligning each to its
    addralign, so the region size is that simulated layout length -- not just the
    span of recovered symbol addresses (which can disagree when the source indexes
    an array out of bounds). The region base comes from the first section whose
    address is reliably recovered; each section is then checked at base+offset:
    reloc-free PROGBITS must byte-match retail, reloc-bearing sections need every
    target resolvable, and NOBITS regions must be zero in retail."""
    import collections
    local_syms = {s["name"] for s in obj.symbols if s["name"] and s.get("shndx", 0) != 0}
    bases = recover_section_bases(obj, real, retail, gp)
    by_name = collections.defaultdict(list)
    for s in obj.sh:
        if s.get("name") in DATA_SECTIONS and s["size"]:
            by_name[s["name"]].append(s)
    per_name = {}
    for name, secs in by_name.items():
        secs.sort(key=lambda s: s["idx"])  # mwld concatenates same-name sections in shndx order
        offsets = []
        off = 0
        for s in secs:
            align = s["addralign"] or 1
            off = (off + align - 1) & ~(align - 1)
            offsets.append(off)
            off += s["size"]
        total = off
        base = None
        for s, o in zip(secs, offsets):
            if s["idx"] in bases:
                base = bases[s["idx"]] - o
                break
        if base is None:
            return False, {}
        for s, o in zip(secs, offsets):
            addr = base + o
            # a recovered address that disagrees with the concat layout means the
            # source's data model does not reproduce retail (e.g. aliased arrays);
            # refuse rather than emit a wrong image.
            if s["idx"] in bases and bases[s["idx"]] != addr:
                return False, {}
            if s["type"] == 8:  # NOBITS -> zero-filled PROGBITS; retail must be zero
                if any(retail.bytes_at(addr, s["size"])):
                    return False, {}
            else:
                relocs = section_relocs(obj, s["idx"])
                if relocs:
                    if any(nm and nm not in local_syms and nm not in resolvable
                           for _o, _t, nm in relocs):
                        return False, {}
                elif obj.data[s["offset"]:s["offset"] + s["size"]] != retail.bytes_at(addr, s["size"]):
                    return False, {}
        per_name[name] = (base, total)
    return True, per_name


def eligible_c_objects(c, resolvable, boundaries, gp):
    """Select decompiled TUs to link as real C objects: all markers match,
    contiguous function range, every external ref resolvable, and every owned
    data section placeable byte-exact. Returns dicts with .text range + data
    section placements, sorted by function start address."""
    import bisect
    retail = V.RetailElf(c["retail_elf"], TARGET, RETAIL_SHA1)
    out = []
    for cpath in sorted((REPO / "src").rglob("*.c")):
        markers = V.scan_markers(cpath)
        real = [m for m in markers if m["name"]]
        if not real or any(m["stub"] or m["nonmatching"] for m in real):
            continue
        obj, _ = V.compile_object(cpath, c)
        if obj is None:
            continue
        symtab = {s["name"]: s.get("shndx", 0) for s in obj.symbols}
        ok = True
        addrs = []
        for m in real:
            try:
                body, rels = obj.function(m["name"])
            except KeyError:
                ok = False
                break
            i = bisect.bisect_right(boundaries, m["addr"])
            win = boundaries[i] - m["addr"] if i < len(boundaries) else None
            if not win or win > 0x10000:
                ok = False
                break
            wb = retail.bytes_at(m["addr"], win)
            if V.compare(body, rels, wb[:len(body)])[0] != 0 or len(body) > win or any(wb[len(body):]):
                ok = False
                break
            for r in rels:
                nm = r["symbol"]
                if nm and symtab.get(nm, 0) == 0 and nm not in resolvable:
                    ok = False
                    break
            if not ok:
                break
            addrs.append((m["addr"], win))
        if not ok or not addrs:
            continue
        addrs.sort()
        if not all(addrs[k][0] + addrs[k][1] == addrs[k + 1][0] for k in range(len(addrs) - 1)):
            continue
        data_ok, sections = plan_data_sections(obj, real, retail, gp, resolvable)
        if not data_ok:
            continue
        out.append(dict(src=cpath, start=addrs[0][0], end=addrs[-1][0] + addrs[-1][1],
                        funcs=real, sections=sections))
    out.sort(key=lambda d: d["start"])
    return out


# ---------------------------------------------------------------- asm carving

def split_blocks(text):
    """Split a splat asm file into (preamble, [(addr, lines)]). A block begins
    at a `nonmatching`/`glabel` line; its address is the first byte comment."""
    lines = text.splitlines(keepends=True)
    i = 0
    while i < len(lines) and not re.match(r"\s*(nonmatching|glabel)\b", lines[i]):
        i += 1
    preamble = lines[:i]
    blocks = []
    cur = []
    for ln in lines[i:]:
        if re.match(r"\s*nonmatching\b", ln) and cur:
            blocks.append(cur)
            cur = []
        cur.append(ln)
    if cur:
        blocks.append(cur)
    parsed = []
    for blk in blocks:
        addr = None
        for ln in blk:
            m = BYTES_RE.search(ln)
            if m:
                addr = int(m.group(1), 16)
                break
        parsed.append((addr, blk))
    return preamble, parsed


def build_code_carved(c, name, lo, hi, cobjs, entries):
    """Assemble the splat asm for a code region, split into chunk objects around
    the C-owned ranges, and register each chunk + C object as a link entry."""
    src = ASM / f"{name}.s"
    preamble, blocks = split_blocks(src.read_text())
    seg_lo, seg_hi = VRAM + lo, VRAM + hi
    ranges = [(o["start"], o["end"], o) for o in cobjs if seg_lo <= o["start"] < seg_hi]
    ranges.sort()
    starts = [r[0] for r in ranges]
    import bisect
    chunks = {}  # chunk index -> list of block lines (order preserved)
    cur_idx = None
    for addr, blk in blocks:
        if addr is None:
            # carry address-less fragment forward with the current chunk
            tgt = cur_idx if cur_idx is not None else 0
            chunks.setdefault(tgt, []).extend(blk)
            continue
        if any(s <= addr < e for s, e, _ in ranges):
            continue  # carved: provided by a C object
        idx = bisect.bisect_right(starts, addr)
        cur_idx = idx
        chunks.setdefault(idx, []).extend(blk)
    # emit + assemble each chunk, compute its start address
    chunk_dir = ASM / "chunks"
    chunk_dir.mkdir(parents=True, exist_ok=True)
    for idx, body in sorted(chunks.items()):
        first = None
        for ln in body:
            m = BYTES_RE.search(ln)
            if m:
                first = int(m.group(1), 16)
                break
        if first is None:
            continue
        cpath = chunk_dir / f"{name}_{idx}.s"
        cpath.write_text("".join(preamble) + "".join(body))
        obj = OBJ / f"{name}_{idx}.o"
        ok, log, lines = A.assemble(cpath, obj, AS_TOOL, OBJCOPY_TOOL,
                                    ref=IMAGE.read_bytes(), vram=first, ref_lo=first - VRAM,
                                    keep_text=True)
        cpath.write_text("".join(lines))
        if not ok:
            sys.stderr.write(log + "\n")
            sys.exit(f"build: failed to assemble {cpath.name}")
        patch_align1(obj, ".text")
        entries.append((first, obj, ".text"))


def build_code_plain(c, name, lo, hi, entries):
    src = ASM / f"{name}.s"
    obj = OBJ / f"{name}.o"
    ok, log, lines = A.assemble(src, obj, AS_TOOL, OBJCOPY_TOOL,
                                ref=IMAGE.read_bytes(), vram=VRAM + lo, ref_lo=lo, keep_text=True)
    src.write_text("".join(lines))
    if not ok:
        sys.stderr.write(log + "\n")
        sys.exit(f"build: failed to assemble {name}")
    patch_align1(obj, ".text")
    entries.append((VRAM + lo, obj, ".text"))


def build_data_carved(name, lo, hi, data_carves, entries):
    """Emit the data blob as .incbin pieces around the C-owned data ranges."""
    seg_lo, seg_hi = VRAM + lo, VRAM + hi
    carves = sorted((s, e) for s, e in data_carves if seg_lo <= s < seg_hi)
    pieces = []
    cur = lo
    for s, e in carves:
        s_off, e_off = s - VRAM, e - VRAM
        if s_off > cur:
            pieces.append((cur, s_off))
        cur = max(cur, e_off)
    if cur < hi:
        pieces.append((cur, hi))
    chunk_dir = ASM / "chunks"
    chunk_dir.mkdir(parents=True, exist_ok=True)
    for i, (a, b) in enumerate(pieces):
        src = chunk_dir / f"{name}_{i}.s"
        obj = OBJ / f"{name}_{i}.o"
        src.write_text(f'.section .{name}, "aw"\n.incbin "../image.bin", {hex(a)}, {hex(b - a)}\n')
        ok, log, _ = A.assemble(src, obj, AS_TOOL, OBJCOPY_TOOL, keep_text=False)
        if not ok:
            sys.stderr.write(log + "\n")
            sys.exit(f"build: failed to assemble {name}_{i}")
        patch_align1(obj, f".{name}")
        entries.append((VRAM + a, obj, f".{name}"))


def compile_c(c, src, obj):
    obj.parent.mkdir(parents=True, exist_ok=True)
    mwccgap = REPO / "tools" / "mwccgap" / "mwccgap.py"
    sh([sys.executable, str(mwccgap), str(src), str(obj),
        "--mwcc-path", c["mwcc"], "--macro-inc-path", str(ASM / "macro.inc"),
        "--as-march", "r5900", "--as-mabi", "eabi", *c["cflags"], "-Iinclude"],
       cwd=str(REPO))
    progbitsify(obj)


# ---------------------------------------------------------------- link

def write_lcf(entries, gp, defs):
    body = []
    if gp is not None:
        body.append(f"    _gp = {gp:#010x};")
    for nm, addr in sorted(defs.items(), key=lambda kv: kv[1]):
        body.append(f"    {nm} = {addr:#010x};")
    placed = []
    for start, obj, sec in sorted(entries, key=lambda e: e[0]):
        if sec == ".text":
            placed.append("        . = ALIGN(0x10);")
        placed.append(f"        {obj.name} ({sec})")
    lcf = (
        "MEMORY {\n"
        f"    image : ORIGIN = {VRAM:#x}, LENGTH = {IMAGE_SIZE:#x}\n"
        "}\n"
        "SECTIONS {\n"
        + "\n".join(body) + "\n"
        "    .image : {\n" + "\n".join(placed) + "\n    } > image\n"
        "}\n"
    )
    (BUILD / "slus21782.lcf").write_text(lcf)


def link(c, entries):
    objs, seen = [], set()
    for _a, obj, _s in sorted(entries, key=lambda e: e[0]):
        if str(obj) not in seen:
            seen.add(str(obj))
            objs.append(str(obj))
    entry_symbol = ELF_TARGET.get("entry_symbol", f"func_{parse_int(ELF_TARGET['entry']):08x}")
    sh([c["ld_exe"], "-nostdlib", "-nodeadstrip", "-m", entry_symbol,
        "-o", str(BUILD / "slus21782.elf"), str(BUILD / "slus21782.lcf")] + objs)



def linked_function_records(cobjs, windows):
    """Return unique C-owned functions at authoritative window starts.

    ``scan_markers`` normally provides integer addresses, but progress-verifier
    rows encode them as hexadecimal strings. Normalize either representation
    before comparing against the integer window map loaded for this build.
    """
    authoritative_addresses = set(windows)
    by_address = {}
    for obj in cobjs:
        source = obj["src"].relative_to(REPO).as_posix()
        for func in obj["funcs"]:
            marker_address = func["addr"]
            try:
                address = (int(marker_address, 16)
                           if isinstance(marker_address, str) else int(marker_address))
            except (TypeError, ValueError):
                sys.exit(
                    f"build: invalid marker address {marker_address!r} "
                    f"for {func['name']} in {source}"
                )
            if address not in authoritative_addresses:
                sys.exit(
                    f"build: marker address {address:#010x} for {func['name']} "
                    f"in {source} is not an authoritative function window"
                )
            record = (func["name"], source)
            previous = by_address.get(address)
            if previous is not None and previous != record:
                sys.exit(
                    f"build: conflicting markers at {address:#010x}: "
                    f"{previous[0]} in {previous[1]} vs {record[0]} in {record[1]}"
                )
            by_address[address] = record
    return [
        {"address": f"{address:08x}", "name": name, "file": source}
        for address, (name, source) in sorted(by_address.items())
    ]


def write_progress_report(path, image_sha1, retail_sha1, function_total, cobjs, linked_functions):
    """Atomically publish successful real-C linkage information."""
    import tempfile

    path = Path(path)
    report = {
        "schema_version": 1,
        "build_succeeded": True,
        "image_sha1": image_sha1,
        "retail_sha1": retail_sha1,
        "function_total": function_total,
        "linked_tu_count": len(cobjs),
        "linked_function_count": len(linked_functions),
        "linked_functions": linked_functions,
    }
    path.parent.mkdir(parents=True, exist_ok=True)
    temp_path = None
    try:
        with tempfile.NamedTemporaryFile(
            mode="w", encoding="utf-8", dir=path.parent,
            prefix=f".{path.name}.", suffix=".tmp", delete=False,
        ) as temp:
            temp_path = Path(temp.name)
            json.dump(report, temp, indent=2, sort_keys=True)
            temp.write("\n")
        os.replace(temp_path, path)
    except Exception:
        if temp_path is not None:
            temp_path.unlink(missing_ok=True)
        raise

def build_matching_elf(c, n_cobj):
    linked = (BUILD / "slus21782.elf").read_bytes()
    retail, retail_load_header, image = retail_load(c)
    phoff = struct.unpack_from("<I", linked, 0x1C)[0]
    phentsize, phnum = struct.unpack_from("<HH", linked, 0x2A)
    payload = None
    for index in range(phnum):
        header = phoff + index * phentsize
        if header + 32 > len(linked):
            print("build: linked ELF program header table is truncated")
            return 1
        segment = struct.unpack_from("<IIIIIIII", linked, header)
        if segment[0] == 1 and segment[2] == VRAM:
            payload = linked[segment[1]:segment[1] + segment[4]]
            break
    if payload is None:
        print("build: no loadable segment at target VRAM in linked output")
        return 1
    print(f"C objects linked from source: {n_cobj}")
    image_sha1 = hashlib.sha1(payload).hexdigest()
    img_ok = payload == image
    print(f"loadable image sha1: {image_sha1}  {'OK' if img_ok else 'MISMATCH'}")
    if not img_ok:
        for index in range(min(len(payload), len(image))):
            if payload[index] != image[index]:
                print(f"  first diff at vram {VRAM + index:#x} (payload {payload[index:index + 4].hex()} "
                      f"vs retail {image[index:index + 4].hex()})")
                break
        if len(payload) != len(image):
            print(f"  payload size {len(payload):#x}; expected {len(image):#x}")
        return 1
    offset = retail_load_header["offset"]
    final = retail[:offset] + payload + retail[offset + len(payload):]
    output = BUILD / ELF_TARGET["filename"]
    output.write_bytes(final)
    got = hashlib.sha1(final).hexdigest()
    whole_ok = got == RETAIL_SHA1
    print(f"{ELF_TARGET['filename']} sha1: {got}  {'OK' if whole_ok else 'MISMATCH'}")
    return 0 if whole_ok else 1


AS_TOOL = None
OBJCOPY_TOOL = None


def main():
    global AS_TOOL, OBJCOPY_TOOL
    parser = argparse.ArgumentParser()
    parser.add_argument("--progress-report", type=Path, metavar="PATH")
    parser.add_argument("--setup-only", action="store_true")
    args, _unknown = parser.parse_known_args()
    c = cfg()
    BUILD.mkdir(exist_ok=True)
    OBJ.mkdir(parents=True, exist_ok=True)
    ASM.mkdir(exist_ok=True)
    if args.setup_only:
        extract_image(c)
        print("wrote image.bin")
        return
    # A complete output ELF is hash-verified against retail, so a normal build
    # always needs the verified source ELF even when no C translation unit exists.
    retail_load(c)
    if not IMAGE.is_file():
        extract_image(c)
    validate_image()
    for name, kind, lo, hi in SEGMENTS:
        if kind == "code" and not (ASM / f"{name}.s").is_file():
            sys.exit(f"build: {name}.s missing; run `make split` first")
    if not c.get("ld_exe"):
        sys.exit("build: set mwcc/ld_exe in tools/build_config.local.json or P4_MWCC")
    source_files = list((REPO / "src").rglob("*.c"))
    if source_files and not c.get("mwcc"):
        sys.exit("build: matched C sources require mwcc in tools/build_config.local.json or P4_MWCC")
    AS_TOOL = A.find_gnu_tool("mipsel-linux-gnu-as", "P4_AS")
    OBJCOPY_TOOL = A.find_gnu_tool("mipsel-linux-gnu-objcopy", "P4_OBJCOPY")

    gp, defs = load_lcf_symbols()
    resolvable = set(defs) | load_symbol_names()
    boundaries = load_windows()
    cobjs = eligible_c_objects(c, resolvable, boundaries, gp) if c.get("retail_elf") else []
    print(f"eligible C objects: {len(cobjs)}  "
          f"({', '.join(o['src'].name for o in cobjs) if cobjs else 'none'})")
    linked_functions = linked_function_records(cobjs, boundaries)

    entries = []
    # Compile each decompiled TU once; place its .text and every owned data
    # section, and record the retail ranges to carve out of the baseline.
    c_text_ranges = []
    data_carves = []
    for o in cobjs:
        cobj = OBJ / (o["src"].relative_to(REPO / "src").as_posix().replace("/", "_") + ".o")
        compile_c(c, o["src"], cobj)
        o["obj"] = cobj
        entries.append((o["start"], cobj, ".text"))
        c_text_ranges.append((o["start"], o["end"], o))
        for sname, (base, size) in o["sections"].items():
            entries.append((base, cobj, sname))
            data_carves.append((base, base + size))

    # Splat asm references carved functions by their symbol_addrs names; when a
    # C object exports a canonical name instead, define the splat name as an
    # absolute address (the C object is placed byte-exact at retail).
    if c_text_ranges:
        exported = set()
        for o in cobjs:
            exported |= c_object_exports(o["obj"])
        for nm, addr in load_symbol_addr_map().items():
            if nm in exported or nm in defs:
                continue
            if any(s <= addr < e for s, e, _o in c_text_ranges):
                defs[nm] = addr

    for name, kind, lo, hi in SEGMENTS:
        if kind == "code":
            if any(VRAM + lo <= s < VRAM + hi for s, _e, _o in c_text_ranges):
                build_code_carved(c, name, lo, hi, cobjs, entries)
            else:
                build_code_plain(c, name, lo, hi, entries)
        else:
            build_data_carved(name, lo, hi, data_carves, entries)
    write_lcf(entries, gp, defs)
    link(c, entries)
    status = build_matching_elf(c, len(cobjs))
    if status == 0 and args.progress_report is not None:
        write_progress_report(
            args.progress_report,
            hashlib.sha1(IMAGE.read_bytes()).hexdigest(),
            hashlib.sha1((BUILD / ELF_TARGET["filename"]).read_bytes()).hexdigest(),
            len(boundaries),
            cobjs,
            linked_functions,
        )
    sys.exit(status)


if __name__ == "__main__":
    main()
