/* object_size=not-attempted window=240 normalized_diff=not-measured classification=multi-entry-retail-window; retail func_003ca740.s contains three entry points at +0x00 (func_003ca740), +0x40 (func_003ca780), and +0x60 (func_003ca7a0), with the final framed body at +0x60; no plain-C body probe performed; ruled_out=movz-movn,COP1-MAC,standalone-MMI,framed-tail-jump,sd-saved-register; measured_minutes=1 */
/* The 240-byte symbol window is a concatenation of two unframed 64-byte
   callback trampolines and the 128-byte framed ca7a0 body. The source marker
   at ca740 owns only one INCLUDE_ASM symbol, while ca780 and ca7a0 are
   separate retail labels inside that window; replacing it with one C
   function cannot preserve the three entry addresses. */
