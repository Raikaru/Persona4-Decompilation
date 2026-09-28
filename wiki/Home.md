# Persona 4 (PS2) Decompilation

Guides for the matching decompilation of *Shin Megami Tensei: Persona 4*
(USA, `SLUS_217.82`). Current progress is on
[decomp.dev](https://decomp.dev/Raikaru/Persona4-Decompilation) and in the
[README](https://github.com/Raikaru/Persona4-Decompilation#readme).
[CONTRIBUTING.md](https://github.com/Raikaru/Persona4-Decompilation/blob/main/CONTRIBUTING.md)
describes how to send a change.

## Setting up

- [Getting Started](Getting-Started): requirements, local configuration,
  first build and Docker.
- [Repository Layout](Repository-Layout): where source, configuration,
  generated files and research records live.
- [Tools](Tools): which script to reach for.

## Matching

- [How Matching Works](How-Matching-Works): markers, what the verifier and
  the build check, and what a `MATCH` does not prove.
- [Matching a Function](Matching-a-Function): the working loop for one
  function.
- [Rules](Rules): what the tree must keep true, and which check enforces it.
- [Compiler Floors](Compiler-Floors): residuals that no C source is known to
  reach.

## The executable

- [The Retail Build](The-Retail-Build): which compiler and flags built each
  part of the executable, and the evidence.
- [RenderWare](RenderWare): the RenderWare Graphics 3.7 block and how it is
  recovered from the public source.
