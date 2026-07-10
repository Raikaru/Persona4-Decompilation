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

    def assemble_file(
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
