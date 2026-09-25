"""GNU ld backend for exact placement of unchanged native MIPS input sections."""
from __future__ import annotations

import os
from collections import Counter
from dataclasses import dataclass, field, replace
import hashlib
from pathlib import Path
import re
import struct
import subprocess
import sys

import asm as A
import verify as V


@dataclass(frozen=True)
class SharedLiteral:
    address: int
    size: int
    inputs: tuple[tuple[Path, int, str], ...]


@dataclass(frozen=True)
class InputPlan:
    functions: list[tuple[str, int, int]]
    definitions: set[str]
    shared_literals: list[SharedLiteral] = field(default_factory=list)
    literal_symbols: list[tuple[str, int, int]] = field(default_factory=list)


def quote(value: str) -> str:
    """Quote one GNU response-file or linker-script string, without a shell."""
    if any(character in value for character in "\0\r\n"):
        raise ValueError("GNU linker paths and arguments must fit on one line")
    return '"' + value.replace("\\", "\\\\").replace('"', '\\"') + '"'


def map_paths(tool: A.Tool, paths) -> dict[Path, str]:
    """Resolve all inputs once and translate their common directory once in WSL.

    Script selectors and response inputs must use identical full paths; basename
    selectors may otherwise cause ld to open a second object. Each path below the
    common directory is appended locally instead of spawning wslpath per object.
    """
    resolved = sorted({Path(path).resolve() for path in paths})
    if not resolved:
        return {}
    if not tool.wsl:
        return {path: path.as_posix() for path in resolved}
    if "--" not in tool.argv:
        raise ValueError("WSL P4_LD must use the form: wsl -d DISTRO -- LINKER")
    common = Path(os.path.commonpath([str(path.parent) for path in resolved]))
    prefix = tool.argv[:tool.argv.index("--") + 1]
    process = subprocess.run([*prefix, "wslpath", "-a", common.as_posix()],
                             stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    if process.returncode:
        raise RuntimeError(f"GNU linker path translation failed: {process.stdout}")
    translated = process.stdout.strip().rstrip("/")
    if not translated.startswith("/") or "\n" in translated:
        raise ValueError(f"Invalid wslpath output: {translated!r}")
    return {path: translated + "/" + path.relative_to(common).as_posix() for path in resolved}


def _literal_atom(obj, section):
    """Recognize a single compiler-local constant used only by GP literal loads.

    MWCC marks native MIPS pools writable even though these constants are loaded,
    never stored. Require all references to prove that property before allowing
    GNU to merge identical atoms at an independently established shared address.
    """
    match = re.fullmatch(r'\.lit([48])(?:\.p4_[0-9a-f]+)?', section['name'])
    if not match:
        return None
    width = int(match[1])
    if (section['type'] != 1 or section['size'] != width
            or section['addralign'] != width or not section['flags'] & 2
            or section['flags'] & ~0x10000003 or section['entsize'] not in (0, width)):
        return None
    symbols = [s for s in obj.symbols if s['shndx'] == section['idx']]
    if not symbols or any(s['info'] >> 4 != 0 or s['info'] & 15 not in (1, 3)
                          or s['value'] + s['size'] > width for s in symbols):
        return None
    references = 0
    for rel in obj.sections:
        if rel['type'] == 4:  # No RELA or unfamiliar addend semantics in this path.
            return None
        if rel['type'] != 9:
            continue
        if rel['info'] == section['idx'] and rel['size']:
            return None
        table = obj.symtabs[rel['link']]
        for offset in range(rel['offset'], rel['offset'] + rel['size'], rel['entsize'] or 8):
            position, info = struct.unpack_from('<II', obj.data, offset)
            symbol = table[info >> 8]
            if symbol['shndx'] != section['idx']:
                continue
            source = obj.sections[rel['info']]
            if (info & 255 != 8 or not source['flags'] & 4 or position + 4 > source['size']):
                return None
            word, = struct.unpack_from('<I', obj.data, source['offset'] + position)
            opcode = word >> 26
            addend = (word & 0xffff) - (0x10000 if word & 0x8000 else 0)
            start = symbol['value'] + addend
            if (opcode not in (49, 53) or (word >> 21) & 31 != 28
                    or start < 0 or start + (4 if opcode == 49 else 8) > width):
                return None
            references += 1
    if not references:
        return None
    return obj.data[section['offset']:section['offset'] + width]


def validate_inputs(entries, objects, vram: int, image_size: int):
    """Reject invalid placements; permit proven, identical shared literal atoms."""
    objects = {Path(path).resolve(): V.ObjectFile(path) for path in objects}
    selected = set()
    expected_functions = []
    shared = {}
    literal_symbols = []
    previous = None
    end = vram
    for address, path, name in sorted(entries, key=lambda item: item[0]):
        path = Path(path).resolve()
        if path not in objects or not vram <= address < vram + image_size:
            raise ValueError(f"GNU placement outside inputs or image: {path} at {address:#x}")
        if any(character in path.as_posix() + name for character in "*?["):
            raise ValueError("GNU exact placements cannot contain wildcard characters")
        obj = objects[path]
        matches = [section for section in obj.sections if section["name"] == name]
        if not matches:
            raise ValueError(f"Missing GNU placement: {path.name}({name})")
        cursor = address
        for section in matches:
            key = (path, section["idx"])
            if key in selected or not section["flags"] & 2:
                raise ValueError(f"Duplicate or non-allocated GNU placement: {path.name}({name})")
            selected.add(key)
            alignment = max(section["addralign"], 1)
            cursor = (cursor + alignment - 1) & -alignment
            if name.startswith(".text."):
                symbol_name = name[len(".text."):]
                definitions = [symbol for symbol in obj.symbols
                               if symbol["name"] == symbol_name and symbol["shndx"] == section["idx"]]
                if len(definitions) != 1:
                    raise ValueError(f"GNU function placement lacks one real definition: {symbol_name}")
                symbol = definitions[0]
                expected_functions.append((symbol_name, cursor + symbol["value"], symbol["size"]))
            cursor += section["size"]
        if cursor > vram + image_size:
            raise ValueError(f"GNU placement exceeds the image: {path.name}({name})")
        if address < end:
            atom = _literal_atom(obj, matches[0]) if len(matches) == 1 else None
            if previous is None:
                raise ValueError(f"Overlapping GNU placement: {path.name}({name})")
            old_address, old_path, old_sections = previous
            old_obj = objects[old_path]
            old_atom = _literal_atom(old_obj, old_sections[0]) if len(old_sections) == 1 else None
            if (atom is None or atom != old_atom or address != old_address or cursor != end):
                raise ValueError(f"Missing or overlapping GNU placement: {path.name}({name})")
            first = old_sections[0]
            group = shared.setdefault(address, [(old_path, first['idx'], first['name'])])
            group.append((path, matches[0]['idx'], name))
        else:
            end = cursor
            previous = (address, path, matches)
    for path, obj in objects.items():
        for section in obj.sections:
            if section["flags"] & 2 and section["size"] and (path, section["idx"]) not in selected:
                raise ValueError(f"Unplaced allocated section: {path.name}({section['name']})")
    definitions = {symbol["name"] for obj in objects.values() for symbol in obj.symbols
                   if symbol["shndx"] != 0 and symbol["info"] >> 4 in (1, 2)}
    pools = []
    for address, members in sorted(shared.items()):
        path, index, _ = members[0]
        width = objects[path].sections[index]['size']
        pools.append(SharedLiteral(address, width, tuple(members)))
        for path, index, _ in members:
            literal_symbols.extend((s['name'], address + s['value'], s['size'])
                                   for s in objects[path].symbols if s['shndx'] == index and s['name'])
    return InputPlan(expected_functions, definitions, pools, literal_symbols)


def prepare_literal_inputs(entries, objects, pools, build_dir):
    """Copy only shared-pool objects and add GNU merge metadata to their atoms.

    Native instructions, data, symbols, relocation records and ABI flags remain
    byte-identical. GNU performs the merge and relocates both original local
    definitions; there are no absolute aliases or discarded pool definitions.
    """
    indices = {}
    for pool in pools:
        for path, index, _ in pool.inputs:
            indices.setdefault(path, {})[index] = pool.size
    remap = {}
    for path, sections in indices.items():
        raw = path.read_bytes()
        data = bytearray(raw)
        shoff = struct.unpack_from('<I', data, 32)[0]
        stride = struct.unpack_from('<H', data, 46)[0]
        for index, width in sections.items():
            header = shoff + stride * index
            flags = struct.unpack_from('<I', data, header + 8)[0]
            struct.pack_into('<I', data, header + 8, flags | 0x10)  # SHF_MERGE
            struct.pack_into('<I', data, header + 36, width)       # One constant per entry
        directory = Path(build_dir) / 'gnu-merge-inputs'
        directory.mkdir(parents=True, exist_ok=True)
        digest = hashlib.sha256(path.as_posix().encode() + b'\0' + data).hexdigest()
        destination = (directory / (digest + '.o')).resolve()
        if destination.exists():
            if destination.read_bytes() != data:
                raise ValueError('Existing GNU merge input changed')
        else:
            destination.write_bytes(data)
        remap[path] = destination
        if path.read_bytes() != raw:
            raise ValueError('Native linker input changed during literal preparation')
    rewritten = [(address, remap.get(path, path), name) for address, path, name in entries]
    mapped_pools = [replace(pool, inputs=tuple((remap.get(path, path), index, name)
                    for path, index, name in pool.inputs)) for pool in pools]
    return rewritten, [remap.get(path, path) for path in objects], mapped_pools


def render_script(entries, paths, vram: int, image_size: int, entry_symbol: str,
                  gp: int | None, definitions: dict[str, int], shared_literals=()) -> str:
    body = []
    if gp is not None:
        body.append(f"    _gp = {gp:#010x};")
    for name, address in sorted(definitions.items(), key=lambda item: (item[1], item[0])):
        if not re.fullmatch(r"[A-Za-z_][A-Za-z_0-9]*", name):
            raise ValueError(f"Invalid GNU linker symbol: {name!r}")
        if name == "_gp" and gp is not None:
            if address != gp:
                raise ValueError("Conflicting GNU GP definitions")
            continue
        # Plain assignments override actual object definitions in GNU ld. These
        # addresses are fallbacks; source definitions must remain section-backed.
        body.append(f"    PROVIDE({name} = {address:#010x});")
    if shared_literals:
        return _render_shared_script(entries, paths, vram, image_size, entry_symbol, body, shared_literals)
    placed = []
    for address, path, section in sorted(entries, key=lambda item: item[0]):
        # Within an output section GNU's location counter is section-relative.
        placed.append(f"        . = {address - vram:#x};")
        placed.append(f"        {quote(paths[Path(path).resolve()])}({quote(section)})")
    return (
        'OUTPUT_FORMAT("elf32-tradlittlemips")\n'
        f"ENTRY({entry_symbol})\n"
        f"MEMORY {{ image : ORIGIN = {vram:#x}, LENGTH = {image_size:#x} }}\n"
        "PHDRS { image PT_LOAD FLAGS(7); }\n"
        "SECTIONS {\n" + "\n".join(body) + "\n"
        f"    .image {vram:#x} : {{\n" + "\n".join(placed) + "\n    } > image :image\n"
        "    .mwcats 0 : { *(.mwcats) } :NONE\n"
        "}\n"
        f'ASSERT(SIZEOF(.image) == {image_size:#x}, "load image size changed")\n'
    )


def _render_shared_script(entries, paths, vram, image_size, entry_symbol, definitions, pools):
    shared = {(path, name) for pool in pools for path, _index, name in pool.inputs}
    ordinary = sorted((address, path, name) for address, path, name in entries if (path, name) not in shared)
    sections, checks, sizes = [], [], []
    start = vram
    for index in range(len(pools) + 1):
        end = pools[index].address if index < len(pools) else vram + image_size
        if end > start:
            name = f'.image_{index}'
            rows = []
            for address, path, source in ordinary:
                if start <= address < end:
                    rows.extend((f'        . = {address - start:#x};',
                                 f'        {quote(paths[path])}({quote(source)})'))
            rows.append(f'        . = {end - start:#x};')
            sections.append(f'    {name} {start:#x} : {{\n' + '\n'.join(rows) + '\n    } > image :image')
            sizes.append(f'SIZEOF({name})')
        if index < len(pools):
            pool = pools[index]
            name = f'.shared_literal_{index}'
            rows = [f'        {quote(paths[path])}({quote(source)})' for path, _section, source in pool.inputs]
            sections.append(f'    {name} {pool.address:#x} : {{\n' + '\n'.join(rows) + '\n    } > image :image')
            checks.append(f'ASSERT(SIZEOF({name}) == {pool.size}, "shared literal size changed")')
            sizes.append(f'SIZEOF({name})')
            start = pool.address + pool.size
    return ('OUTPUT_FORMAT("elf32-tradlittlemips")\n' + f'ENTRY({entry_symbol})\n'
            + f'MEMORY {{ image : ORIGIN = {vram:#x}, LENGTH = {image_size:#x} }}\n'
            + 'PHDRS { image PT_LOAD FLAGS(7); }\nSECTIONS {\n' + '\n'.join(definitions + sections)
            + '\n    .mwcats 0 : { *(.mwcats) } :NONE\n}\n' + '\n'.join(checks)
            + '\nASSERT(' + ' + '.join(sizes) + f' == {image_size:#x}, "load image size changed")\n')


def validate_output(path: Path, vram: int, image_size: int, entry: int,
                    gp: int | None, expected_functions, expected_literals=()) -> None:
    raw = path.read_bytes()
    if len(raw) < 52 or raw[:7] != b"\x7fELF\x01\x01\x01":
        raise ValueError("GNU output is not ELF32 little-endian")
    elf_type, machine = struct.unpack_from("<HH", raw, 16)
    if (elf_type, machine) != (2, 8) or struct.unpack_from("<I", raw, 24)[0] != entry:
        raise ValueError("GNU output changed the target machine or entry point")
    phoff = struct.unpack_from("<I", raw, 28)[0]
    stride, count = struct.unpack_from("<HH", raw, 42)
    if stride != 32 or phoff + stride * count > len(raw):
        raise ValueError("GNU output has invalid program headers")
    loads = [struct.unpack_from("<8I", raw, phoff + index * stride) for index in range(count)]
    loads = [row for row in loads if row[0] == 1]
    if (len(loads) != 1 or loads[0][2:6] != (vram, vram, image_size, image_size)
            or loads[0][1] + image_size > len(raw)):
        raise ValueError("GNU output must contain exactly the target load span")
    obj = V.ObjectFile(path)
    if any(section["size"] and section["flags"] & 2 and
           not vram <= section["addr"] < section["addr"] + section["size"] <= vram + image_size
           for section in obj.sections):
        raise ValueError("GNU output allocated data outside the target image")
    if gp is not None and [symbol["value"] for symbol in obj.symbols if symbol["name"] == "_gp"] != [gp]:
        raise ValueError("GNU output changed the target GP")
    definitions = {(symbol["name"], symbol["value"], symbol["size"]) for symbol in obj.symbols
                   if 0 < symbol["shndx"] < len(obj.sections) and
                   obj.sections[symbol["shndx"]]["flags"] & 2}
    missing = [row for row in expected_functions if row not in definitions]
    if missing:
        raise ValueError(f"GNU output lost real function definitions: {missing[:8]}")
    local_data = Counter((s['name'], s['value'], s['size']) for s in obj.symbols
                         if s['info'] >> 4 == 0 and 0 < s['shndx'] < len(obj.sections)
                         and obj.sections[s['shndx']]['flags'] & 2)
    if Counter(expected_literals) - local_data:
        raise ValueError('GNU output lost section-backed local literal definitions')


def link(tool: A.Tool, entries, additional_objects, build_dir: Path, vram: int,
         image_size: int, entry_symbol: str, entry: int, gp: int | None,
         definitions: dict[str, int]) -> None:
    entries = [(address, Path(path).resolve(), section) for address, path, section in entries]
    objects = list(dict.fromkeys([path for _, path, _ in sorted(entries, key=lambda row: row[0])]
                                 + [Path(path).resolve() for path in additional_objects]))
    plan = validate_inputs(entries, objects, vram, image_size)
    entries, objects, pools = prepare_literal_inputs(entries, objects, plan.shared_literals, build_dir)
    # GNU may evaluate PROVIDE for an ENTRY symbol before reading later input
    # sections. Omit every definition already supplied by an actual object,
    # including data and entry symbols, so no fallback can shadow that input.
    definitions = {name: address for name, address in definitions.items() if name not in plan.definitions}
    build_dir = build_dir.resolve()
    script, response, output, map_file = [build_dir / ("slus21782" + suffix)
                                         for suffix in (".ld", ".rsp", ".elf", ".map")]
    paths = map_paths(tool, [*objects, script, response, output, map_file])
    script.write_text(render_script(entries, paths, vram, image_size, entry_symbol, gp, definitions, pools),
                      encoding="utf-8", newline="\n")
    # ee-gcc emits nonalloc ECOFF .mdebug with invalid external-string offsets;
    # BFD crashes while merging it. Drop debug only; keep symbols and load bytes.
    arguments = ["-EL", "--strip-debug", "--no-gc-sections", "-T", paths[script], "-Map", paths[map_file],
                 "-o", paths[output], *(paths[path] for path in objects)]
    response.write_text("\n".join(quote(argument) for argument in arguments) + "\n",
                        encoding="utf-8", newline="\n")
    process = subprocess.run([*tool.argv, "@" + paths[response]],
                             stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    if process.stdout:
        sys.stderr.write(process.stdout)
    if process.returncode:
        raise RuntimeError(f"GNU linker failed with exit code {process.returncode}")
    validate_output(output, vram, image_size, entry, gp, plan.functions, plan.literal_symbols)
