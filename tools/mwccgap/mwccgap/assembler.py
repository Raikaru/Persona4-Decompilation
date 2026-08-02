import hashlib
import os
import shutil
import subprocess
import sys
import tempfile

from pathlib import Path
from typing import Optional

from .exceptions import AssemblerException

def _wsl_distro() -> str:
    return os.environ.get("P4_WSL_DISTRO", "Debian")


def _wsl_has(cmd: str) -> bool:
    return subprocess.run(
        ["wsl", "-d", _wsl_distro(), "--", "sh", "-lc", f"command -v {cmd} >/dev/null"],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    ).returncode == 0


def _wslpath(path: str | Path) -> str:
    p = subprocess.run(
        ["wsl", "-d", _wsl_distro(), "--", "wslpath", "-a", str(path).replace("\\", "/")],
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
    )
    if p.returncode:
        raise AssemblerException(p.stdout)
    return p.stdout.strip()


class Assembler:
    def __init__(
        self,
        as_path="mipsel-linux-gnu-as",
        as_march="allegrex",
        as_mabi="32",
        as_flags: Optional[list[str]] = None,
        macro_inc_path: Optional[Path] = None,
    ):
        if as_flags is None:
            as_flags = []

        self.as_path = as_path
        self.as_march = as_march
        self.as_mabi = as_mabi
        self.as_flags = as_flags
        self.macro_inc_path = macro_inc_path

    def _cache_key(self, asm_filepath: Path, source: bytes) -> str:
        """Content address for an assembled object.

        Covers the assembly text and every input that changes the output, so a
        stale entry cannot survive a toolchain or macro.inc change.
        """
        digest = hashlib.sha256()
        digest.update(source)
        digest.update(repr((str(self.as_path), self.as_march, self.as_mabi,
                            tuple(self.as_flags))).encode())
        if self.macro_inc_path and Path(self.macro_inc_path).is_file():
            digest.update(Path(self.macro_inc_path).read_bytes())
        return digest.hexdigest()

    def assemble_file(
        self,
        asm_filepath: Path,
    ) -> bytes:
        # INCLUDE_ASM fallbacks are immutable: each is sliced from splat output
        # and never edited. Without a cache every compile re-assembles all of
        # them, and each invocation costs ~130 ms because the assembler runs
        # through WSL on Windows. With thousands of fallbacks in the tree that
        # dominates every verify and build, so cache on content.
        cache_dir = Path(os.environ.get("MWCCGAP_ASM_CACHE",
                                        Path(tempfile.gettempdir()) / "mwccgap-asm-cache"))
        entry = None
        try:
            source = Path(asm_filepath).read_bytes()
            entry = cache_dir / f"{self._cache_key(asm_filepath, source)}.o"
            if entry.is_file():
                return entry.read_bytes()
        except OSError:
            entry = None
        obj_bytes = self._assemble_uncached(asm_filepath)
        if entry is not None:
            try:
                cache_dir.mkdir(parents=True, exist_ok=True)
                temp = entry.with_suffix(f".{os.getpid()}.tmp")
                temp.write_bytes(obj_bytes)
                os.replace(temp, entry)  # atomic: concurrent builds share the cache
            except OSError:
                pass
        return obj_bytes

    def _assemble_uncached(
        self,
        asm_filepath: Path,
    ) -> bytes:
        with tempfile.NamedTemporaryFile(suffix=".o") as temp_file:
            as_name = str(self.as_path)
            use_wsl = os.name == "nt" and shutil.which(as_name) is None and _wsl_has(as_name)
            cmd = [as_name]
            out_path = temp_file.name
            include_dir = str(self.macro_inc_path.resolve().parent) if self.macro_inc_path else None
            if use_wsl:
                cmd = ["wsl", "-d", _wsl_distro(), "--", as_name]
                out_path = _wslpath(out_path)
                if include_dir:
                    include_dir = _wslpath(include_dir)
            cmd += ["-EL"]
            if include_dir:
                cmd.append(f"-I{include_dir}")
            cmd += [
                f"-march={self.as_march}",
                f"-mabi={self.as_mabi}",
                "-o",
                out_path,
                *self.as_flags,
            ]

            with subprocess.Popen(
                cmd,
                stdout=subprocess.PIPE,
                stdin=subprocess.PIPE,
                stderr=subprocess.PIPE,
            ) as process:
                in_bytes = asm_filepath.read_bytes()
                if self.macro_inc_path and self.macro_inc_path.is_file():
                    in_bytes = self.macro_inc_path.read_bytes() + in_bytes

                stdout, stderr = process.communicate(input=in_bytes)

            if stdout:
                sys.stderr.write(stdout.decode("utf-8"))
            if stderr:
                sys.stderr.write(stderr.decode("utf-8"))

            if process.returncode != 0:
                raise AssemblerException(
                    f"Failed to assemble {asm_filepath} (assembler returned {process.returncode})"
                )

            obj_bytes = temp_file.read()

        if len(obj_bytes) == 0:
            raise AssemblerException(
                f"Failed to assemble {asm_filepath} (object is empty)"
            )

        return obj_bytes
