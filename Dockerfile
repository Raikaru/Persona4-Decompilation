# Reproducible Linux build environment for the Persona 4 PS2 decompilation.
#
# This image deliberately does not contain the non-redistributable MWCCPS2/
# MWLDPS2 compiler or SLUS_217.82.  Mount a directory containing those files at
# /opt/p4 (or set P4_MWCC_BINARY/P4_MWLD_BINARY and P4_RETAIL_ELF to mounted
# paths).  The P4_MWCC/P4_RETAIL_ELF defaults below let the existing Python tools
# use the wibo wrappers without changing the repository's configuration format.
# In the default layout, P4_MWCC is the Linux wrapper and
# P4_MWCC_BINARY is the mounted Windows executable that wibo launches.
# P4_RETAIL_ELF is the mounted ELF consumed by tools/verify.py/build.py.
#
# Example:
#   docker build -t p4-decomp .
#   docker run --rm -it -v "$PWD:/work" -v "/path/to/private-p4:/opt/p4:ro" \
#     p4-decomp
#
# Trixie (Debian 13, glibc 2.41), NOT bookworm (glibc 2.36): the prebuilt
# decompals binutils below is linked against GLIBC_2.38, so on bookworm the
# assembler dies with "version `GLIBC_2.38' not found" and the r5900 probe at
# the end of this file fails the image build.
FROM python:3.11-slim-trixie

ARG BINUTILS_VERSION=0.7
ARG WIBO_VERSION=0.6.13

ENV P4_MWCC=/usr/local/bin/mwccps2.exe \
    P4_MWCC_BINARY=/opt/p4/mwccps2.exe \
    P4_MWLD_BINARY=/opt/p4/mwldps2.exe \
    P4_RETAIL_ELF=/opt/p4/SLUS_217.82 \
    P4_AS=/usr/local/bin/mipsel-linux-gnu-as \
    P4_OBJCOPY=/usr/local/bin/mipsel-linux-gnu-objcopy \
    PYTHONUNBUFFERED=1

COPY tools/requirements-debian.txt /tmp/requirements-debian.txt
RUN set -eux; \
    apt-get update; \
    apt-get install -y --no-install-recommends $(cat /tmp/requirements-debian.txt); \
    rm -rf /var/lib/apt/lists/* /tmp/requirements-debian.txt

# Install the PS2-aware decompals binutils build.  The project tools retain the
# conventional mipsel-linux-gnu-* names, so expose the decompals binaries under
# those names as well as their upstream names.
RUN set -eux; \
    wget -q -O /tmp/binutils.tar.gz \
      "https://github.com/decompals/binutils-mips-ps2-decompals/releases/download/v${BINUTILS_VERSION}/binutils-mips-ps2-decompals-linux-x86-64.tar.gz"; \
    mkdir -p /tmp/binutils; \
    tar -xzf /tmp/binutils.tar.gz -C /tmp/binutils; \
    for tool in /tmp/binutils/mips-ps2-decompals-*; do \
      install -m 0755 "$tool" "/usr/local/bin/$(basename "$tool")"; \
    done; \
    ln -s /usr/local/bin/mips-ps2-decompals-as /usr/local/bin/mipsel-linux-gnu-as; \
    ln -s /usr/local/bin/mips-ps2-decompals-objcopy /usr/local/bin/mipsel-linux-gnu-objcopy; \
    rm -rf /tmp/binutils /tmp/binutils.tar.gz

# Fail the image build if the assembler does not accept the PS2 ISA/ABI used by
# tools/build.py and tools/asm.py.
RUN set -eux; \
    printf '%s\n' '.set noreorder' '.text' '.globl p4_r5900_probe' 'p4_r5900_probe:' \
      'padduw $1,$0,$0' 'jr $31' 'nop' > /tmp/r5900.s; \
    mipsel-linux-gnu-as -EL -march=r5900 -mabi=eabi -G=0 -o /tmp/r5900.o /tmp/r5900.s; \
    rm -f /tmp/r5900.s /tmp/r5900.o

# wibo runs the supplied Win32 CodeWarrior executables on Linux.  The wrapper
# names end in .exe intentionally: build.py derives mwldps2.exe from P4_MWCC.
RUN set -eux; \
    wget -q -O /usr/local/bin/wibo \
      "https://github.com/decompals/wibo/releases/download/${WIBO_VERSION}/wibo"; \
    chmod 0755 /usr/local/bin/wibo; \
    printf '%s\n' '#!/bin/sh' 'set -eu' \
      'exec /usr/local/bin/wibo "${P4_MWCC_BINARY:-/opt/p4/mwccps2.exe}" "$@"' \
      > /usr/local/bin/mwccps2.exe; \
    printf '%s\n' '#!/bin/sh' 'set -eu' \
      'exec /usr/local/bin/wibo "${P4_MWLD_BINARY:-/opt/p4/mwldps2.exe}" "$@"' \
      > /usr/local/bin/mwldps2.exe; \
    chmod 0755 /usr/local/bin/mwccps2.exe /usr/local/bin/mwldps2.exe

COPY requirements-python.txt /tmp/requirements-python.txt
RUN python -m pip install --no-cache-dir --disable-pip-version-check \
      -r /tmp/requirements-python.txt \
    && rm -f /tmp/requirements-python.txt

WORKDIR /work
CMD ["/bin/bash"]
