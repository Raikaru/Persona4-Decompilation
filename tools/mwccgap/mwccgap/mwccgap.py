import copy
import tempfile

from pathlib import Path
from typing import List, Optional

from .assembler import Assembler
from .compiler import Compiler
from .constants import (
    FUNCTION_PREFIX,
    SYMBOL_AT,
    SYMBOL_DOLLAR,
    DOLLAR_SIGN,
    SYMBOL_SINIT,
    IGNORED_RELOCATIONS,
)
from .elf import Elf, TextSection, Relocation
from .preprocessor import Preprocessor


def process_c_file(
    c_file: Path,
    o_file: Path,
    c_flags: Optional[List[str]] = None,
    mwcc_path="mwccpsp.exe",
    as_path="mipsel-linux-gnu-as",
    as_flags: Optional[List[str]] = None,
    as_march="allegrex",
    as_mabi="32",
    use_wibo=False,
    wibo_path="wibo",
    asm_dir_prefix: Optional[Path] = None,
    macro_inc_path: Optional[Path] = None,
    c_file_encoding: Optional[str] = None,
):
    # 1. compile file as-is, any INCLUDE_ASM'd functions will be missing from the object
    compiler = Compiler(c_flags, mwcc_path, use_wibo, wibo_path)
    if c_file_encoding:
        temp_c_file_path = None
        try:
            with tempfile.NamedTemporaryFile(suffix=".c", dir=c_file.parent, delete=False) as temp_c_file:
                data = c_file.read_text(encoding="utf-8")
                temp_c_file.write(data.encode(c_file_encoding))
                temp_c_file_path = Path(temp_c_file.name)
            obj_bytes = compiler.compile_file(temp_c_file_path)
        finally:
            if temp_c_file_path:
                temp_c_file_path.unlink(missing_ok=True)
    else:
        obj_bytes = compiler.compile_file(c_file)

    precompiled_elf = Elf(obj_bytes)
    # for now we only care about the names of the functions that exist
    c_functions = set(f.function_name for f in precompiled_elf.get_functions())

    # 2. identify all INCLUDE_ASM statements and replace with asm statements full of nops
    with c_file.open("r", encoding="utf-8") as f:
        out_lines, asm_files = Preprocessor(asm_dir_prefix).preprocess_c_file(f)

    # filter out functions that can be found in the compiled c object
    asm_files = [(x, y) for (x, y) in asm_files if x.stem not in c_functions]

    # if there's nothing to do, write out the bytes from the precompiled object
    if len(asm_files) == 0:
        o_file.parent.mkdir(exist_ok=True, parents=True)
        o_file.write_bytes(obj_bytes)
        return

    # 3. compile the modified .c file for real
    temp_c_file_path = None
    try:
        with tempfile.NamedTemporaryFile(suffix=".c", dir=c_file.parent, delete=False) as temp_c_file:
            temp_c_file.write("\n".join(out_lines).encode(c_file_encoding or "utf-8"))
            temp_c_file_path = Path(temp_c_file.name)

        temp_c_file_name = temp_c_file_path.name
        obj_bytes = compiler.compile_file(temp_c_file_path)
    finally:
        if temp_c_file_path:
            temp_c_file_path.unlink(missing_ok=True)
    compiled_elf = Elf(obj_bytes)

    rel_text_sh_name = compiled_elf.add_sh_symbol(".rel.text")

    symbol_to_section_idx = {}
    for symbol in compiled_elf.symtab.symbols:
        if symbol.name.startswith(FUNCTION_PREFIX):
            symbol.name = symbol.name[len(FUNCTION_PREFIX) :]
            symbol.st_name += len(FUNCTION_PREFIX)

        elif symbol.name.startswith(SYMBOL_AT):
            symbol.name = "@" + symbol.name.removeprefix(SYMBOL_AT)
            symbol.st_name = compiled_elf.strtab.add_symbol(symbol.name)

        elif SYMBOL_DOLLAR in symbol.name:
            symbol.name = symbol.name.replace(SYMBOL_DOLLAR, DOLLAR_SIGN)
            symbol.st_name = compiled_elf.strtab.add_symbol(symbol.name)

        elif symbol.name.find(SYMBOL_SINIT + temp_c_file_name) != -1:
            symbol.name = replace_sinit(symbol.name, temp_c_file_name, c_file.name)
            symbol.st_name = compiled_elf.strtab.add_symbol(symbol.name)

        symbol_to_section_idx[symbol.name] = symbol.st_shndx

    assembler = Assembler(
        as_path=as_path,
        as_flags=as_flags,
        as_march=as_march,
        as_mabi=as_mabi,
        macro_inc_path=macro_inc_path,
    )

    for asm_file, num_rodata_symbols in asm_files:
        function = asm_file.stem

        asm_bytes = assembler.assemble_file(asm_file)
        assembled_elf = Elf(asm_bytes)

        asm_functions = assembled_elf.get_functions()
        assert (
            len(asm_functions) == 1
        ), f"Maximum of 1 function per ASM file (found {len(asm_functions)})"

        asm_text = asm_functions[0].data
        has_text = len(asm_text) > 0

        if has_text:
            # identify the .text section for this function
            for text_section_index, text_section in enumerate(compiled_elf.sections):
                if (
                    isinstance(text_section, TextSection)
                    and text_section.function_name == f"{FUNCTION_PREFIX}{function}"
                ):
                    break
            else:
                raise Exception(f"{function} not found in {c_file}")

            # assumption is that .rodata will immediately follow the .text section
            rodata_section_indices = []
            if num_rodata_symbols > 0:
                for i, section in enumerate(
                    compiled_elf.sections[text_section_index + 1 :]
                ):
                    if section.name == ".rodata":
                        # found some .rodata before another .text section
                        rodata_section_indices.append(text_section_index + 1 + i)
                        if len(rodata_section_indices) == num_rodata_symbols:
                            # reached end of rodata sections for this text section
                            break

            assert num_rodata_symbols == len(
                rodata_section_indices
            ), ".rodata section count mismatch"
        else:
            # this file only contains .rodata
            assert (
                num_rodata_symbols == 1
            ), f"Maximum of 1 symbol per rodata ASM file (found {num_rodata_symbols})"
            idx = symbol_to_section_idx.get(function)
            assert (
                idx is not None
            ), f"Could not find .rodata section for symbol '{function}'"
            rodata_section_indices = [idx]

        if has_text:
            # transplant .text section data from assembled object
            compiled_function_length = len(text_section.data)

            assert (
                len(asm_text) >= compiled_function_length
            ), f"Not enough assembly to fill {function} in {c_file}"

            text_section.data = asm_text[:compiled_function_length]

        if num_rodata_symbols > 0:
            assert (
                len(assembled_elf.rodata_sections) == 1
            ), f"Expected ASM to contain 1 .rodata section, found {len(assembled_elf.rodata_sections)}"
            asm_rodata = assembled_elf.rodata_sections[0]

            offset = 0
            rodata_section_offsets = []
            for idx in rodata_section_indices:
                # copy slices of rodata from ASM object into each .rodata section
                data_len = len(compiled_elf.sections[idx].data)
                compiled_elf.sections[idx].data = asm_rodata.data[
                    offset : offset + data_len
                ]
                offset += data_len
                rodata_section_offsets.append(offset)

                # force 4-byte alignment for .rodata sections (defaults to 16-byte)
                compiled_elf.sections[idx].sh_addralign = 2  # 1 << 2 = 4

            rel_rodata_sh_name = compiled_elf.add_sh_symbol(".rel.rodata")

        relocation_records = [
            record
            for record in assembled_elf.get_relocations()
            if record.name not in IGNORED_RELOCATIONS
        ]
        assert (
            len(relocation_records) < 3
        ), f"{asm_file} has too many relocation records!"

        reloc_symbols = set()

        initial_sh_info_value = compiled_elf.symtab.sh_info
        local_syms_inserted = 0

        # assumes .text relocations precede .rodata relocations
        for i, relocation_record in enumerate(relocation_records):
            relocation_record.sh_link = compiled_elf.symtab_index
            if has_text and i == 0:
                relocation_record.sh_name = rel_text_sh_name
                relocation_record.sh_info = text_section_index
            else:
                relocation_record.sh_name = rel_rodata_sh_name
                relocation_record.sh_info = rodata_section_indices[0]

            for relocation in relocation_record.relocations:
                symbol = assembled_elf.symtab.symbols[relocation.symbol_index]

                if symbol.bind == 0:
                    local_syms_inserted += 1

                if has_text and i == 0:
                    force = False
                else:
                    force = True

                relocation.symbol_index = compiled_elf.add_symbol(symbol, force=force)
                reloc_symbols.add(symbol.name)

                if has_text and i == 1:
                    # repoint .rodata reloc to .text section
                    symbol.st_shndx = text_section_index

            compiled_elf.add_section(relocation_record)

        new_rodata_relocs = []
        if local_syms_inserted > 0:
            # update relocations
            for relocation_record in compiled_elf.get_relocations():
                if relocation_record.sh_info == rodata_section_indices[0]:
                    if num_rodata_symbols == 1:
                        # nothing to do when only a single .rodata section
                        continue

                    # otherwise we need to split the rodata relocations across each .rodata section
                    new_relocations: List[List[Relocation]] = [
                        [] for _ in rodata_section_indices
                    ]
                    for relocation in relocation_record.relocations:
                        for i in range(len(rodata_section_offsets)):
                            if relocation.r_offset < rodata_section_offsets[i]:
                                if i > 0:
                                    relocation.r_offset -= rodata_section_offsets[i - 1]
                                new_relocations[i].append(relocation)
                                break

                    for i, relocations in enumerate(new_relocations):
                        if i == 0:
                            # amend original in place
                            new_rodata_reloc = relocation_record
                        else:
                            # take a copy of the original
                            new_rodata_reloc = copy.copy(relocation_record)

                        new_rodata_reloc.relocations = relocations
                        new_rodata_reloc.sh_info = rodata_section_indices[i]
                        new_rodata_relocs.append(new_rodata_reloc)

                    continue

                for relocation in relocation_record.relocations:
                    if relocation.symbol_index >= initial_sh_info_value:
                        relocation.symbol_index += local_syms_inserted

            for new_rodata_reloc in new_rodata_relocs[1:]:
                compiled_elf.add_section(new_rodata_reloc)

        for symbol in assembled_elf.symtab.symbols:
            if symbol.st_name == 0:
                continue

            if symbol.bind == 0:
                # ignore local symbols
                continue

            if has_text and symbol.name not in reloc_symbols:
                symbol.st_shndx = text_section_index
                compiled_elf.add_symbol(symbol)

    o_file.parent.mkdir(exist_ok=True, parents=True)
    o_file.write_bytes(compiled_elf.pack())


def replace_sinit(symbol_name, temp_file_name, c_file_name):
    """
    Substitute original file name into MWCC static initializer symbol names

    When files contain static initializer code (e.g. static definitions
    referencing the address of another static variable), MWCC emits the symbols:
    - `.p__sinit_foo.cpp`
    - `__sinit_foo.cpp`
    - `.mwcats___sinit_foo.cpp`

    On certain versions of MWCC, the symbol generation code is bugged. When
    generating the symbol name, the first character is treated as the minimum
    format width and the filename is right padded.

    `.p__sinit_foo.cpp` is a pointer object in the `.ctor` section, with a
    reloc pointing to `__sinit_foo.cpp`. This is linked into a table alongside
    every other `.p__sinit_*` symbol so that the runtime support can call the
    static initailizer code before passing control to the application.

    `__sinit_foo.cpp` is a function in the `.init` section, containing the
    static initializer instructions. `.mwcats__sinit_foo.cpp` is a proprietary
    debugging section.

    Since we are compiling a temporary file, MWCC generates these symbols
    using the temporary file's name. We replace it with the original file name
    to operate transparently & enable linking these symbols.
    """
    prefix, _, symbol_file_name = symbol_name.partition(SYMBOL_SINIT)
    assert len(symbol_file_name) > 0

    # MWCC bug: filename is padded based on first character of file name
    if len(symbol_file_name) > len(temp_file_name):
        assert symbol_file_name == temp_file_name.ljust(ord(temp_file_name[0]))
        return prefix + SYMBOL_SINIT + c_file_name.ljust(ord(c_file_name[0]))

    return prefix + SYMBOL_SINIT + c_file_name
