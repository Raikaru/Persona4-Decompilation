"""Run C contract fixtures with real 32-bit pointers and no target-body rewrites.

Clang emits a freestanding Linux i386 executable. Linux runs it directly;
Windows uses an existing WSL installation for linking and execution. No SDK,
32-bit C library, root privileges, or installation is needed. Availability is
tested before a fixture is compiled, so fixture failures cannot become skips.
"""
from __future__ import annotations

from dataclasses import dataclass
from functools import lru_cache
import os
from pathlib import Path, PureWindowsPath
import platform
import shutil
import subprocess
import tempfile


RUNTIME_C = r'''
typedef char Native32PointerWidth[sizeof(void *) == 4 ? 1 : -1];
typedef char Native32IntegerWidth[sizeof(unsigned) == 4 ? 1 : -1];
void *memcpy(void *destination, const void *source, __SIZE_TYPE__ size) {
    unsigned char *out = destination;
    const unsigned char *in = source;
    for (__SIZE_TYPE__ i = 0; i < size; ++i) out[i] = in[i];
    return destination;
}
void *memset(void *destination, int value, __SIZE_TYPE__ size) {
    unsigned char *out = destination;
    for (__SIZE_TYPE__ i = 0; i < size; ++i) out[i] = (unsigned char)value;
    return destination;
}
int memcmp(const void *left, const void *right, __SIZE_TYPE__ size) {
    const unsigned char *a = left, *b = right;
    for (__SIZE_TYPE__ i = 0; i < size; ++i) {
        if (a[i] != b[i]) return a[i] < b[i] ? -1 : 1;
    }
    return 0;
}
static void native32_write(const char *data, unsigned size) {
    int result;
    __asm__ volatile ("int $0x80" : "=a"(result)
                      : "0"(4), "b"(1), "c"(data), "d"(size) : "memory");
    (void)result;
}
static void native32_text(const char *text) {
    unsigned size = 0;
    while (text[size]) ++size;
    native32_write(text, size);
}
static void native32_number(unsigned value) {
    char digits[10];
    unsigned size = 0;
    do { digits[size++] = (char)('0' + value % 10); value /= 10; } while (value);
    for (unsigned i = size; i; --i) native32_write(&digits[i - 1], 1);
}
__attribute__((noreturn)) static void native32_exit(int status) {
    __asm__ volatile ("int $0x80" : : "a"(1), "b"(status) : "memory");
    __builtin_unreachable();
}
__attribute__((noreturn)) static void native32_failure(unsigned line, unsigned scenario,
                                                     const char *condition) {
    native32_text("line "); native32_number(line);
    native32_text(", scenario "); native32_number(scenario);
    native32_text(": "); native32_text(condition); native32_text("\n");
    native32_exit(1);
}
'''

ENTRY_C = r'''
__attribute__((noreturn, force_align_arg_pointer)) void _start(void) {
    native32_exit(main());
}
'''


class Native32Unavailable(RuntimeError):
    """The host has no usable freestanding 32-bit execution path."""


@dataclass(frozen=True)
class Native32Runtime:
    compiler: str
    linker: tuple[str, ...]
    runner: tuple[str, ...]
    windows: bool

    def execution_path(self, path: Path) -> str:
        resolved = path.resolve()
        if not self.windows:
            return str(resolved)
        native = PureWindowsPath(resolved)
        if len(native.drive) != 2 or native.drive[1] != ":":
            raise Native32Unavailable("The WSL fixture requires a local drive path")
        return "/mnt/" + native.drive[0].lower() + "/" + "/".join(native.parts[1:])

    def compile(self, source: Path, output: Path, optimization: str,
                include_dirs: tuple[Path, ...] = ()) -> Path:
        if optimization not in ("-O0", "-O2"):
            raise ValueError("Fixture optimization must be -O0 or -O2")
        obj = output.with_suffix(".o")
        command = [self.compiler, "--target=i386-linux-gnu", "-m32", "-msse2", "-mfpmath=sse",
                   "-std=c11", optimization, "-ffreestanding", "-fno-builtin", "-fno-pie",
                   "-fno-stack-protector", "-ffp-contract=off", "-fno-strict-aliasing",
                   "-fsanitize=undefined,bounds", "-fsanitize-trap=all",
                   "-Werror=implicit-function-declaration", "-Werror=incompatible-pointer-types",
                   "-Werror=int-conversion", *["-I" + str(path) for path in include_dirs],
                   "-c", str(source), "-o", str(obj)]
        compiled = subprocess.run(command, capture_output=True, text=True, timeout=60)
        if compiled.returncode:
            raise RuntimeError(f"Native32 compilation failed ({compiled.returncode}):\n"
                               + compiled.stdout + compiled.stderr)
        command = [*self.linker, "-m", "elf_i386", "-e", "_start", "-o",
                   self.execution_path(output), self.execution_path(obj)]
        linked = subprocess.run(command, capture_output=True, text=True, timeout=60)
        if linked.returncode:
            raise RuntimeError(f"Native32 linking failed ({linked.returncode}):\n"
                               + linked.stdout + linked.stderr)
        header = output.read_bytes()[:20]
        if header[:5] != b"\x7fELF\x01" or header[5] != 1 or header[18:20] != b"\x03\0":
            raise RuntimeError("Fixture is not a little-endian 32-bit i386 ELF executable")
        return output

    def run(self, executable: Path) -> subprocess.CompletedProcess[str]:
        return subprocess.run([*self.runner, self.execution_path(executable)],
                              capture_output=True, text=True, timeout=60)


@lru_cache(maxsize=1)
def native32_runtime() -> Native32Runtime:
    compiler = shutil.which("clang")
    if compiler is None:
        raise Native32Unavailable("Clang is required for native 32-bit C contract fixtures")
    if os.name == "nt":
        wsl = shutil.which("wsl.exe")
        if wsl is None:
            raise Native32Unavailable("An existing WSL installation is required for native 32-bit fixtures")
        runtime = Native32Runtime(compiler, (wsl, "--exec", "/usr/bin/ld"), (wsl, "--exec"), True)
    elif platform.system() == "Linux" and platform.machine().lower() in ("x86_64", "amd64", "i386", "i686"):
        linker = shutil.which("ld")
        if linker is None:
            raise Native32Unavailable("GNU ld is required for native 32-bit fixtures")
        runtime = Native32Runtime(compiler, (linker,), (), False)
    else:
        raise Native32Unavailable("Native 32-bit contract fixtures require x86 Linux or Windows with WSL")

    source_text = RUNTIME_C + r'''
static unsigned sample = 0xA5732C91u;
int main(void) {
    unsigned address = (unsigned)&sample;
    int narrowed = (int)address;
    if (*(unsigned *)(unsigned)narrowed != 0xA5732C91u) return 1;
    native32_text("native32-ready\n");
    return 0;
}
''' + ENTRY_C
    try:
        with tempfile.TemporaryDirectory(prefix="p4_native32_preflight_") as directory:
            directory = Path(directory)
            source = directory / "preflight.c"
            source.write_text(source_text, encoding="utf-8")
            executable = runtime.compile(source, directory / "preflight", "-O2")
            result = runtime.run(executable)
            if result.returncode or result.stdout != "native32-ready\n":
                raise RuntimeError(f"Native32 execution failed ({result.returncode}): "
                                   + result.stdout + result.stderr)
    except (OSError, subprocess.SubprocessError, RuntimeError) as exc:
        raise Native32Unavailable(str(exc)) from exc
    return runtime
