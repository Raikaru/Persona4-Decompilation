import argparse
import sys
import traceback
import tempfile

from pathlib import Path

from mwccgap.mwccgap import process_c_file


class CustomTildeFormatter(argparse.HelpFormatter):
    def format_help(self):
        text = super().format_help()
        return text.replace("~~", "--")


def main() -> None:
    """
    Hack: We replace `--` with `~~` before parsing so argparse ignores user-supplied
    flags meant for the assembler. The prefixes are restored afterward.
    """
    parser = argparse.ArgumentParser(
        prefix_chars="~", formatter_class=CustomTildeFormatter
    )

    # Upstream also supports piping C on stdin.  In this harness stdin may be a
    # non-tty pipe that never reaches EOF, so prefer explicit path mode whenever
    # the usual `input.c output.o` form is present.
    read_from_file = len(sys.argv) >= 3 or sys.stdin.isatty()
    if not read_from_file:
        in_lines = sys.stdin.readlines()
        if len(in_lines) == 0:
            read_from_file = True

    if read_from_file:
        parser.add_argument("c_file", type=Path)

    parser.add_argument("o_file", type=Path)

    default_as_flags = ["-G0"]  # TODO: base this on -sdatathreshold value from c_flags

    def add_argument(arg, **kwargs):
        parser.add_argument(arg.replace("--", "~~"), **kwargs)

    add_argument("--mwcc-path", type=Path, default=Path("mwccpsp.exe"))
    add_argument("--as-path", type=Path, default=Path("mipsel-linux-gnu-as"))
    add_argument("--as-march", type=str, default="allegrex")
    add_argument("--as-mabi", type=str, default="32")
    add_argument("--as-flags", nargs="*", default=default_as_flags)
    add_argument("--use-wibo", action="store_true")
    add_argument("--wibo-path", type=Path, default=Path("wibo"))
    add_argument("--asm-dir-prefix", type=Path)
    add_argument("--macro-inc-path", type=Path)
    add_argument("--target-encoding", type=str)
    add_argument("--src-dir", type=Path)

    argv = [arg.replace("--", "~~") for arg in sys.argv[1:]]
    args, c_flags = parser.parse_known_args(argv)

    try:
        with tempfile.NamedTemporaryFile(suffix=".c", dir=args.src_dir) as temp_c_file:
            c_file = args.c_file if read_from_file else Path(temp_c_file.name)

            if not read_from_file:
                temp_c_file.writelines([x.encode("utf") for x in in_lines])
                temp_c_file.flush()
            process_c_file(
                c_file,
                args.o_file,
                c_flags,
                mwcc_path=args.mwcc_path,
                as_path=args.as_path,
                as_march=args.as_march,
                as_mabi=args.as_mabi,
                as_flags=args.as_flags,
                use_wibo=args.use_wibo,
                wibo_path=args.wibo_path,
                asm_dir_prefix=args.asm_dir_prefix,
                macro_inc_path=args.macro_inc_path,
                c_file_encoding=args.target_encoding,
            )

    except Exception as e:
        sys.stderr.write(f"Exception processing {c_file.name}: {e}\n")
        sys.stderr.write(traceback.format_exc())
        sys.stderr.write("\n")
        # cleanup
        args.o_file.unlink(missing_ok=True)
        sys.exit(1)

    sys.exit(0)


if __name__ == "__main__":
    main()
