# Texture visitor contract, 2026-09-22

The first-party texture visitor `func_00463100` now accepts an `RwTexture *`
and its user-data pointer and returns that same texture pointer. Its old
`s32 (u8 *, u32 **)` declaration disagreed with the callback interface used by
the newly recovered model loader. Other game callers carried unrelated
one-argument, void-returning or integer-returning declarations.

`include/texture_callback_internal.h` provides one declaration for the visitor
and the existing dictionary traversal function. Its opaque structure tags,
callback parameters and return types agree with `include/rw/core/batextur.h`.
The five first-party owners use this interface. Dictionary addresses carried
as words are explicitly converted to pointers at the call boundary. No vendor
implementation or vendor header is modified.

Inside the visitor, typed byte/list views retain the existing memory accesses.
Returning the original texture parameter keeps the actual callback input live
through the resource and list operations. This produces the original native
register allocation without an added operation or synthetic state. Returning
only the local view was measured separately and exchanged two registers; that
nonmatching form is retained in scratch and was not installed.

The native b210 visitor remains 324 bytes in its 336-byte retail window, with
15 fully resolved relocations and twelve zero suffix bytes. The visitor's
eighteen-function owner preserves all instruction bytes, relocation meanings,
and allocated data. Full-owner checks also cover the model loader and every
affected effect, field-resource and clump-instance caller. Native and official
current-source receipts are retained in
`build/finish-first-party-20260922/texture-callback/family-current/`; the combined
result is `texture-callback/family-completed.json`.

This interface correction does not add a function to the matching count. It
preserves the previously matched implementation while making the function
type shared by its callers and definition consistent.
