from __future__ import annotations

import importlib.util
from pathlib import Path
import tempfile
import unittest

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "build_cache.py"
SPEC = importlib.util.spec_from_file_location("p4_build_cache", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
build_cache = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(build_cache)


class ObjectCacheTests(unittest.TestCase):
    def setUp(self) -> None:
        self.temporary = tempfile.TemporaryDirectory()
        self.root = Path(self.temporary.name)
        self.source = self.root / "src" / "unit.c"
        self.header = self.root / "include" / "outer.h"
        self.transitive = self.root / "include" / "inner.h"
        self.tool = self.root / "tool.exe"
        self.driver = self.root / "tools" / "build.py"
        for path in (self.source, self.header, self.transitive, self.tool, self.driver):
            path.parent.mkdir(parents=True, exist_ok=True)
        self.source.write_text('#include "outer.h"\nint value(void) { return INNER; }\n')
        self.header.write_text('#include "inner.h"\n')
        self.transitive.write_text("#define INNER 1\n")
        self.tool.write_bytes(b"compiler-v1")
        self.driver.write_bytes(b"driver-v1")
        self.cache_root = self.root / "build" / "cache" / "c"
        self.output = self.root / "build" / "obj" / "unit.o"
        self.calls = 0

    def tearDown(self) -> None:
        self.temporary.cleanup()

    def build(self, cache: object, *, flags: tuple[str, ...] = ("-O2",), succeed: bool = True):
        def producer(output: Path):
            self.calls += 1
            output.write_bytes(b"exact-object")
            return succeed, "compile failed" if not succeed else ""

        return cache.build(
            mode="link",
            output=self.output,
            source=self.source,
            include_dirs=[self.root / "include"],
            flags=flags,
            tools={"compiler": self.tool},
            inputs=[self.driver],
            producer=producer,
        )

    def test_reuses_exact_object_across_cache_instances(self) -> None:
        first = build_cache.ObjectCache(self.cache_root, self.root)
        self.assertEqual(self.build(first), (True, ""))
        self.assertEqual(first.stats["link"], {"hits": 0, "misses": 1})
        self.output.write_bytes(b"not-the-cached-object")

        second = build_cache.ObjectCache(self.cache_root, self.root)
        self.assertEqual(self.build(second), (True, ""))
        self.assertEqual(self.calls, 1)
        self.assertEqual(self.output.read_bytes(), b"exact-object")
        self.assertEqual(second.stats["link"], {"hits": 1, "misses": 0})
        self.assertEqual(second.summary(("eligibility", "link")),
                         "C cache: eligibility 0 hit(s), 0 miss(es); link 1 hit(s), 0 miss(es)")

    def test_transitive_header_flags_tool_and_driver_each_invalidate(self) -> None:
        cache = build_cache.ObjectCache(self.cache_root, self.root)
        self.build(cache)
        self.transitive.write_text("#define INNER 2\n")
        self.build(cache)
        self.build(cache, flags=("-O3",))
        self.tool.write_bytes(b"compiler-v2")
        self.build(cache, flags=("-O3",))
        self.driver.write_bytes(b"driver-v2")
        self.build(cache, flags=("-O3",))

        self.assertEqual(self.calls, 5)
        self.assertEqual(cache.stats["link"], {"hits": 0, "misses": 5})

    def test_failures_are_never_cached(self) -> None:
        first = build_cache.ObjectCache(self.cache_root, self.root)
        self.assertEqual(self.build(first, succeed=False), (False, "compile failed"))
        second = build_cache.ObjectCache(self.cache_root, self.root)
        self.assertEqual(self.build(second, succeed=False), (False, "compile failed"))
        self.assertEqual(self.calls, 2)
        self.assertFalse((self.cache_root / "actions" / "link").exists())

    def test_corrupt_cached_blob_is_a_miss(self) -> None:
        first = build_cache.ObjectCache(self.cache_root, self.root)
        self.build(first)
        blob = next((self.cache_root / "objects").glob("*.o"))
        blob.write_bytes(b"corrupt")

        second = build_cache.ObjectCache(self.cache_root, self.root)
        self.build(second)
        self.assertEqual(self.calls, 2)
        self.assertEqual(second.stats["link"], {"hits": 0, "misses": 1})
        self.assertEqual(self.output.read_bytes(), b"exact-object")


if __name__ == "__main__":
    unittest.main()
