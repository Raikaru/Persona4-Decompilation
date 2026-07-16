"""Persistent content-addressed object cache for the build driver."""
from __future__ import annotations

from collections import defaultdict
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import tempfile
from typing import Callable, Iterable, Mapping, Sequence

_INCLUDE_RE = re.compile(rb"^[ \t]*#[ \t]*include[ \t]*([<\"])([^>\"\r\n]+)[>\"]", re.MULTILINE)
_CACHE_FORMAT = 1


def _sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def _canonical_path(path: Path) -> str:
    try:
        return path.resolve().as_posix()
    except OSError:
        return path.absolute().as_posix()


def project_dependencies(source: Path, include_dirs: Sequence[Path], project_root: Path) -> list[Path]:
    """Return the source and all recursively included project files.

    Both quoted and angle-bracket includes are followed when they resolve inside
    ``project_root``. Conditional includes are intentionally included: hashing a
    harmless extra dependency is safer than reusing a stale object.
    """
    root = project_root.resolve()
    directories = [directory.resolve() for directory in include_dirs]
    pending = [source.resolve()]
    seen: set[Path] = set()
    dependencies: list[Path] = []
    while pending:
        path = pending.pop()
        if path in seen:
            continue
        seen.add(path)
        try:
            data = path.read_bytes()
        except OSError:
            # The producer will report the real compile error. The missing path
            # remains represented by the source directive already being hashed.
            continue
        dependencies.append(path)
        for match in _INCLUDE_RE.finditer(data):
            quoted = match.group(1) == b'"'
            try:
                include = match.group(2).decode("utf-8")
            except UnicodeDecodeError:
                continue
            candidates = ([path.parent] if quoted else []) + directories
            for directory in candidates:
                candidate = (directory / include).resolve()
                try:
                    candidate.relative_to(root)
                except ValueError:
                    continue
                if candidate.is_file():
                    pending.append(candidate)
                    break
    return sorted(dependencies, key=_canonical_path)


def tool_version_identity(command: str | Path | Sequence[str]) -> dict[str, object]:
    """Return a stable version probe for tools that may live behind a wrapper."""
    import subprocess

    argv = [str(command)] if isinstance(command, (str, Path)) else [str(arg) for arg in command]
    try:
        process = subprocess.run(
            [*argv, "--version"],
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            timeout=10,
            check=False,
        )
        return {
            "returncode": process.returncode,
            "output_sha256": _sha256(process.stdout),
        }
    except (OSError, subprocess.SubprocessError) as exc:
        return {"error": type(exc).__name__}


def local_tool_files(command: str | Path | Sequence[str]) -> list[Path]:
    """Resolve locally readable executables named by a tool command."""
    argv = [str(command)] if isinstance(command, (str, Path)) else [str(arg) for arg in command]
    if not argv:
        return []
    executable = Path(argv[0])
    if not executable.is_file():
        resolved = shutil.which(argv[0])
        executable = Path(resolved) if resolved else executable
    return [executable.resolve()] if executable.is_file() else []


class ObjectCache:
    """Action-keyed cache backed by content-addressed object blobs."""

    def __init__(self, root: Path, project_root: Path):
        self.root = root
        self.project_root = project_root.resolve()
        self._stats: dict[str, dict[str, int]] = defaultdict(lambda: {"hits": 0, "misses": 0})
        self._file_hashes: dict[tuple[str, int, int], str] = {}

    @property
    def stats(self) -> dict[str, dict[str, int]]:
        return {mode: dict(counts) for mode, counts in self._stats.items()}

    def summary(self, modes: Iterable[str] = ()) -> str:
        names = list(dict.fromkeys([*modes, *sorted(self._stats)]))
        details = []
        for mode in names:
            counts = self._stats[mode]
            details.append(f"{mode} {counts['hits']} hit(s), {counts['misses']} miss(es)")
        return "C cache: " + "; ".join(details)

    def _file_digest(self, path: Path) -> str:
        path = path.resolve()
        stat = path.stat()
        memo_key = (_canonical_path(path), stat.st_size, stat.st_mtime_ns)
        digest = self._file_hashes.get(memo_key)
        if digest is None:
            digest = _sha256(path.read_bytes())
            self._file_hashes[memo_key] = digest
        return digest

    def action_key(
        self,
        *,
        mode: str,
        source: Path,
        include_dirs: Sequence[Path],
        flags: Sequence[str],
        tools: Mapping[str, str | Path | Sequence[str]],
        inputs: Sequence[Path] = (),
        values: Mapping[str, object] | None = None,
    ) -> str:
        files = set(project_dependencies(source, include_dirs, self.project_root))
        files.update(path.resolve() for path in inputs if path.is_file())
        tool_descriptions: dict[str, list[str]] = {}
        for name, command in tools.items():
            argv = [str(command)] if isinstance(command, (str, Path)) else [str(arg) for arg in command]
            tool_descriptions[name] = argv
            resolved_tools = local_tool_files(argv)
            if not resolved_tools and argv:
                relative_tool = self.project_root / argv[0]
                if relative_tool.is_file():
                    resolved_tools = [relative_tool.resolve()]
            files.update(resolved_tools)
        file_records = []
        for path in sorted(files, key=_canonical_path):
            try:
                display_path = path.relative_to(self.project_root).as_posix()
            except ValueError:
                display_path = _canonical_path(path)
            file_records.append((display_path, self._file_digest(path)))
        record = {
            "format": _CACHE_FORMAT,
            "mode": mode,
            "source": source.resolve().relative_to(self.project_root).as_posix(),
            "flags": list(flags),
            "tools": tool_descriptions,
            "files": file_records,
            "values": dict(values or {}),
        }
        encoded = json.dumps(record, sort_keys=True, separators=(",", ":"), ensure_ascii=True).encode("ascii")
        return _sha256(encoded)

    def build(
        self,
        *,
        mode: str,
        output: Path,
        source: Path,
        include_dirs: Sequence[Path],
        flags: Sequence[str],
        tools: Mapping[str, str | Path | Sequence[str]],
        producer: Callable[[Path], tuple[bool, str]],
        inputs: Sequence[Path] = (),
        values: Mapping[str, object] | None = None,
    ) -> tuple[bool, str]:
        """Restore an object or run ``producer`` and cache only its success."""
        key = self.action_key(
            mode=mode,
            source=source,
            include_dirs=include_dirs,
            flags=flags,
            tools=tools,
            inputs=inputs,
            values=values,
        )
        action = self.root / "actions" / mode / f"{key}.json"
        output.parent.mkdir(parents=True, exist_ok=True)
        try:
            metadata = json.loads(action.read_text(encoding="ascii"))
            object_hash = metadata["object_sha256"]
            cached = self.root / "objects" / f"{object_hash}.o"
            if cached.is_file() and self._file_digest(cached) == object_hash:
                self._copy_atomic(cached, output)
                self._stats[mode]["hits"] += 1
                return True, ""
        except (OSError, ValueError, KeyError, TypeError):
            pass

        self._stats[mode]["misses"] += 1
        self.root.mkdir(parents=True, exist_ok=True)
        fd, temporary_name = tempfile.mkstemp(prefix="object-", suffix=".o", dir=self.root)
        os.close(fd)
        temporary = Path(temporary_name)
        temporary.unlink(missing_ok=True)
        try:
            success, log = producer(temporary)
            if not success or not temporary.is_file():
                return False, log
            object_hash = _sha256(temporary.read_bytes())
            cached = self.root / "objects" / f"{object_hash}.o"
            cached.parent.mkdir(parents=True, exist_ok=True)
            if not cached.is_file() or _sha256(cached.read_bytes()) != object_hash:
                self._copy_atomic(temporary, cached)
            action.parent.mkdir(parents=True, exist_ok=True)
            self._write_atomic(action, json.dumps({"object_sha256": object_hash}, sort_keys=True) + "\n")
            self._copy_atomic(cached, output)
            return True, log
        finally:
            temporary.unlink(missing_ok=True)

    @staticmethod
    def _copy_atomic(source: Path, destination: Path) -> None:
        temporary = destination.with_name(f".{destination.name}.{os.getpid()}.tmp")
        try:
            shutil.copyfile(source, temporary)
            os.replace(temporary, destination)
        finally:
            temporary.unlink(missing_ok=True)

    @staticmethod
    def _write_atomic(destination: Path, content: str) -> None:
        temporary = destination.with_name(f".{destination.name}.{os.getpid()}.tmp")
        try:
            temporary.write_text(content, encoding="ascii")
            os.replace(temporary, destination)
        finally:
            temporary.unlink(missing_ok=True)
