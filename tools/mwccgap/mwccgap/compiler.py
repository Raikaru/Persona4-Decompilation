import subprocess
import sys
import tempfile

from pathlib import Path
from typing import List, Optional


class Compiler:

    def __init__(
        self,
        c_flags: Optional[List[str]],
        mwcc_path: Path,
        use_wibo: bool,
        wibo_path: Path,
    ):
        if c_flags is None:
            c_flags = []

        self.c_flags = c_flags
        self.mwcc_path = mwcc_path
        self.use_wibo = use_wibo
        self.wibo_path = wibo_path

    def _compile_file(
        self,
        c_file: Path,
        o_file: Path,
    ) -> tuple[bytes, bytes]:
        o_file.parent.mkdir(exist_ok=True, parents=True)
        o_file.unlink(missing_ok=True)

        cmd = [
            str(self.mwcc_path),
            "-c",
            *self.c_flags,
            "-o",
            str(o_file),
            str(c_file),
        ]
        if self.use_wibo:
            cmd.insert(0, str(self.wibo_path))

        with subprocess.Popen(
            cmd,
            stdout=subprocess.PIPE,
            stdin=subprocess.PIPE,
            stderr=subprocess.PIPE,
        ) as proc:
            return proc.communicate()

    def compile_file(
        self,
        c_file: Path,
    ) -> bytes:
        with tempfile.TemporaryDirectory() as temp_dir:
            o_file = Path(temp_dir) / "result.o"
            stdout, stderr = self._compile_file(
                c_file,
                o_file,
            )

            if stdout:
                sys.stderr.write(stdout.decode("utf-8"))
            if stderr:
                sys.stderr.write(stderr.decode("utf-8"))

            if not o_file.is_file():
                raise Exception(f"Error compiling {c_file}")

            obj_bytes = o_file.read_bytes()
            if len(obj_bytes) == 0:
                raise Exception(f"Error compiling {c_file}, object is empty")

        return obj_bytes
