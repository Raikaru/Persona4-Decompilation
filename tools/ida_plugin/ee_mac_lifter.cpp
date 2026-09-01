/*
 *      Hex-Rays Decompiler plugin: EE (PS2 "Emotion Engine") lifter.
 *
 *      Three independent fixes for places where IDA/Hex-Rays does not model
 *      the Emotion Engine correctly, all of which otherwise produce opaque
 *      __asm{} islands (or outright wrong disassembly) in the pseudocode
 *      used as reconstruction reference by this decompilation campaign:
 *
 *        1. FPU accumulator chain (ADDA/SUBA/MULA/MADDA/MSUBA/MADD/MSUB) --
 *           SHIPPED, works.
 *        2. COP0 BC0F/BC0T branches, which the stock r5900 module
 *           mis-decodes as a bogus "mfthc1" -- SHIPPED, works.
 *        3. MMI / 128-bit instructions -- PARTIALLY shipped, see the long
 *           note above ee_mmi_filter_t. The generic helper-call tier was
 *           MEASURED TO REGRESS THE DECOMPILER AND HAS BEEN REMOVED.
 *
 *      BUILD: needs the IDA SDK (hexrays.hpp et al), which is NOT shipped
 *      with the IDA Pro install (~/ida-pro-9.4/include contains only
 *      defs.h and arm_sys_reg.h). This file lives in the repo rather than
 *      in a scratch dir because an earlier /tmp wipe destroyed both the
 *      SDK checkout and the only copy of this source while the built .so
 *      was still installed -- i.e. a binary was live with no recoverable
 *      source. Do not move it back out of the repo.
 */

//===========================================================================
//      1. FPU ACCUMULATOR CHAIN                                  [SHIPPED]
//===========================================================================
//      The EE has a hidden FPU accumulator register used by the paired
//      ADDA/SUBA + MADD/MSUB family (single precision only -- the EE FPU
//      has no double-precision unit, so there are no .d variants).
//
//      IDA's stock r5900 processor module disassembles every one of these
//      correctly. But the accumulator is not exposed as an architectural
//      register in the r5900 module's register table (verified by dumping
//      ph_get_regnames(): 69 registers, $zero..$ra, $f0..$f31,
//      pc/cs/ds/mips16/gp -- no ACC slot at all), so Hex-Rays has no way to
//      model it and falls back to a raw __asm{} island for every ADDA/SUBA
//      + MADD/MSUB pair.
//
//      Fix: a microcode_filter_t that models the accumulator as a synthetic
//      kernel register (mba_t::alloc_kreg), one per function, lazily
//      allocated on first use and cached by mba->entry_ea. ADDA/SUBA write
//      the accumulator from their two real operands; MADD/MSUB read it,
//      fold in fs*ft, and write the result back to both the accumulator and
//      the real destination register. The surrounding SSA/propagation
//      passes then treat the whole chain as ordinary float arithmetic.
//
//      Validated against retail function 0x0048aff0: before, Hex-Rays
//      emitted `_$F1 = v7 - _$F4; __asm { adda.s $f0,$f4
//      madd.s $f0,$f2,$f1 } return result;`. After, it emits
//      `return (float)(v6 + 0.0) + (float)(v8 * (float)(v7 - v6));` --
//      exactly `from + t*(to-from)`, with no residual asm.
//
//      itypes discovered empirically via ida_ua::decode_insn on the retail
//      EE binary (IDA 9.4, r5900 module), each confirmed by scanning .text
//      for a real occurrence of the mnemonic and reading insn.itype there.
//      They are not exported under any MIPS_adda_s/... SDK constant.

#include <hexrays.hpp>
#include <map>
#include <utility>

enum ee_mac_itype_t
{
  EE_ADDA_S  = 0x13e,
  EE_SUBA_S  = 0x13f,
  EE_MULA_S  = 0x140,
  EE_MADDA_S = 0x141,
  EE_MSUBA_S = 0x142,
  EE_MADD_S  = 0x143,
  EE_MSUB_S  = 0x144,
};

// Keyed by mba->entry_ea rather than mba_t* identity purely for
// debuggability; mba_t* is a stable C++ pointer for one decompilation, so
// either key works here, but entry_ea prints usefully in logs.
static std::map<ea_t, mreg_t> acc_kreg_by_func;

static mreg_t get_acc_kreg(mba_t *mba)
{
  auto it = acc_kreg_by_func.find(mba->entry_ea);
  if ( it != acc_kreg_by_func.end() )
    return it->second;
  mreg_t r = mba->alloc_kreg(4);
  acc_kreg_by_func[mba->entry_ea] = r;
  return r;
}

//-------------------------------------------------------------------------
struct ee_mac_filter_t : public microcode_filter_t
{
  virtual bool match(codegen_t &cdg) override
  {
    switch ( cdg.insn.itype )
    {
      case EE_ADDA_S:
      case EE_SUBA_S:
      case EE_MULA_S:
      case EE_MADDA_S:
      case EE_MSUBA_S:
      case EE_MADD_S:
      case EE_MSUB_S:
        return true;
      default:
        return false;
    }
  }

  virtual merror_t apply(codegen_t &cdg) override
  {
    const insn_t &insn = cdg.insn;
    mreg_t acc = get_acc_kreg(cdg.mba);

    switch ( insn.itype )
    {
      case EE_ADDA_S:
      case EE_SUBA_S:
      {
        // ADDA.S fs, ft  ->  ACC = fs + ft
        // SUBA.S fs, ft  ->  ACC = fs - ft
        mreg_t l = cdg.load_operand(0);
        mreg_t r = cdg.load_operand(1);
        if ( l == mr_none || r == mr_none )
          return MERR_INSN;
        mcode_t op = insn.itype == EE_ADDA_S ? m_fadd : m_fsub;
        cdg.emit(op, 4, l, r, acc, -1);
        return MERR_OK;
      }

      case EE_MULA_S:
      {
        // MULA.S fs, ft  ->  ACC = fs * ft
        mreg_t l = cdg.load_operand(0);
        mreg_t r = cdg.load_operand(1);
        if ( l == mr_none || r == mr_none )
          return MERR_INSN;
        cdg.emit(m_fmul, 4, l, r, acc, -1);
        return MERR_OK;
      }

      case EE_MADDA_S:
      case EE_MSUBA_S:
      {
        // MADDA.S fs, ft  ->  ACC = ACC + fs*ft
        // MSUBA.S fs, ft  ->  ACC = ACC - fs*ft
        mreg_t fs = cdg.load_operand(0);
        mreg_t ft = cdg.load_operand(1);
        if ( fs == mr_none || ft == mr_none )
          return MERR_INSN;
        mreg_t tmp = cdg.mba->alloc_kreg(4);
        cdg.emit(m_fmul, 4, fs, ft, tmp, -1);
        mcode_t op = insn.itype == EE_MADDA_S ? m_fadd : m_fsub;
        cdg.emit(op, 4, acc, tmp, acc, -1);
        cdg.mba->free_kreg(tmp, 4);
        return MERR_OK;
      }

      case EE_MADD_S:
      case EE_MSUB_S:
      {
        // MADD.S fd, fs, ft  ->  fd = ACC + fs*ft; ACC = fd
        // MSUB.S fd, fs, ft  ->  fd = ACC - fs*ft; ACC = fd
        mreg_t fs = cdg.load_operand(1);
        mreg_t ft = cdg.load_operand(2);
        if ( fs == mr_none || ft == mr_none )
          return MERR_INSN;
        mreg_t tmp = cdg.mba->alloc_kreg(4);
        cdg.emit(m_fmul, 4, fs, ft, tmp, -1);
        mcode_t op = insn.itype == EE_MADD_S ? m_fadd : m_fsub;
        cdg.emit(op, 4, acc, tmp, acc, -1);
        cdg.mba->free_kreg(tmp, 4);
        mop_t mop;
        mop.make_reg(acc, 4);
        cdg.store_operand(0, mop);
        return MERR_OK;
      }

      default:
        return MERR_INSN;
    }
  }
};

//===========================================================================
//      2. MMI / 128-bit INSTRUCTIONS                     [PARTIAL/UNBUILT]
//===========================================================================
//      The EE's GPRs are 128 bits wide; the upper 64 bits are reachable only
//      through the MMI instruction set. Hex-Rays' generic MIPS model has no
//      notion of the upper half, so each MMI instruction becomes an opaque
//      __asm{} island. Unlike the sq/lq case in section 3, MMI instructions
//      are register-to-register with operands the r5900 module declares
//      dt_qword (verified: pcpyld at 0x003a2a70 -> itype 0x171, all three
//      operands dtype=7), so they never touch a stack slot and
//      analyze_prolog() has no stake in them.
//
//      MEASURED PREVALENCE (whole retail binary, per-function scan):
//        functions containing MMI  : 153
//        functions containing sq/lq: 5100
//      So MMI is by far the smaller problem; see section 3.
//
//      TIER 1 -- PCPYLD/PCPYUD modelled with real microcode: WORKS.
//      These are the 128-bit build/extract pair and dominate MMI usage
//      (pcpyld alone: 639 of ~1050 in-function MMI instructions). The
//      architecturally visible low 64 bits lift as an ordinary move; the
//      upper 64 bits are tracked in a synthetic kreg allocated per
//      (function, GPR), the same technique the FPU accumulator uses, so a
//      value built with pcpyld and read back with pcpyud round-trips.
//
//      Confirmed on retail func_003a29f0. Before:
//          _$V0 = -2;
//          __asm { pcpyld $v0, $zero, $v0 }
//      After:
//          v11 &= ~1uLL;   / else /   v11 |= 1u;
//      i.e. the real bit-clear/bit-set logic, island gone.
//
//      TIER 2 -- generic MMI as intrinsic helper calls: REMOVED, REGRESSED.
//      A second tier emitted every other MMI opcode as a helper call
//      (`__pextlb(a,b)` etc) built from a hand-constructed mcallinfo_t.
//      It looked correct and produced good output on spot checks, but a
//      controlled before/after measurement over all 153 MMI-containing
//      functions was decisive:
//          without plugin : 153 decompiled ok,  0 failed
//          with helper tier:  82 decompiled ok, 71 FAILED
//      That is the same class of self-inflicted breakage as the abandoned
//      sq/lq work below -- a filter asserting something the decompiler's
//      own invariants disagree with. The helper tier is therefore deleted
//      rather than left in commented-out form, so nobody re-enables it
//      casually. If it is ever retried, the 153-function control run above
//      is the minimum acceptance test, and it must be run BEFORE shipping.
//
//      Tier 1 below is believed good but is NOT currently built or
//      installed: the SDK needed to compile it was lost in the /tmp wipe
//      described in the header. It must pass the same 153-function control
//      run before being installed.

enum ee_mmi_itype_t
{
  EE_PCPYLD = 0x171,
  EE_PCPYUD = 0x172,
};

// Upper 64 bits of an EE GPR, per (function entry, processor register).
static std::map<std::pair<ea_t, int>, mreg_t> hi_kreg_by_func_reg;

static mreg_t get_hi_kreg(mba_t *mba, int regno)
{
  std::pair<ea_t, int> key(mba->entry_ea, regno);
  auto it = hi_kreg_by_func_reg.find(key);
  if ( it != hi_kreg_by_func_reg.end() )
    return it->second;
  mreg_t r = mba->alloc_kreg(8);
  hi_kreg_by_func_reg[key] = r;
  return r;
}

struct ee_mmi_filter_t : public microcode_filter_t
{
  virtual bool match(codegen_t &cdg) override
  {
    int it = cdg.insn.itype;
    return it == EE_PCPYLD || it == EE_PCPYUD;
  }

  virtual merror_t apply(codegen_t &cdg) override
  {
    const insn_t &insn = cdg.insn;

    if ( insn.itype == EE_PCPYLD )
    {
      // PCPYLD rd, rs, rt -> rd.lo = rt.lo ; rd.hi = rs.lo
      mreg_t rs_lo = cdg.load_operand(1);
      mreg_t rt_lo = cdg.load_operand(2);
      if ( rs_lo == mr_none || rt_lo == mr_none )
        return MERR_INSN;
      // Upper half first: the low store below may target the same GPR.
      mreg_t hd = get_hi_kreg(cdg.mba, insn.ops[0].reg);
      cdg.emit(m_mov, 8, rs_lo, 0, hd, -1);
      mop_t lo;
      lo.make_reg(rt_lo, 8);
      return cdg.store_operand(0, lo) ? MERR_OK : MERR_INSN;
    }

    if ( insn.itype == EE_PCPYUD )
    {
      // PCPYUD rd, rs, rt -> rd.lo = rs.hi ; rd.hi = rt.hi
      mreg_t hs = get_hi_kreg(cdg.mba, insn.ops[1].reg);
      mreg_t ht = get_hi_kreg(cdg.mba, insn.ops[2].reg);
      mreg_t hd = get_hi_kreg(cdg.mba, insn.ops[0].reg);
      cdg.emit(m_mov, 8, ht, 0, hd, -1);
      mop_t lo;
      lo.make_reg(hs, 8);
      return cdg.store_operand(0, lo) ? MERR_OK : MERR_INSN;
    }

    return MERR_INSN;
  }
};

//===========================================================================
//      3. SQ/LQ CALLEE-SAVED SPILLS                            [NOT FIXED]
//===========================================================================
//      SQ/LQ save and restore a whole 128-bit GPR, and Hex-Rays' MIPS prolog
//      analyzer does not recognise them as saves/restores, so they surface
//      as __asm{} islands.
//
//      PREVALENCE, measured over the retail binary -- this is the single
//      biggest remaining pseudocode defect, ~33x more common than MMI:
//        functions containing sq/lq                : 5100
//        of those, decompiled with an __asm island : 5031
//      And it is NOT merely cosmetic prologue/epilogue noise. Sampling 400
//      functions that contain sq/lq but no MMI:
//        island confined to prologue/epilogue : 140
//        island intruding into the body       : 260  (65%)
//
//      WHAT WAS TRIED AND WHY IT FAILED
//      Two microcode_filter_t approaches were written: narrowing the memory
//      operand's declared dt_byte16 to dt_qword, and emitting raw m_stx/
//      m_ldx. BOTH crash Hex-Rays with MERR_INTERR on any function whose
//      prologue saves enough registers for analyze_prolog() -- which runs
//      BEFORE any microcode_filter_t and reads the RAW dt_byte16 operand to
//      build its own frame-slot-width model -- to disagree with the width
//      the filter claims for the same slot. Confirmed on 5+ retail
//      addresses by disabling the filter and reproducing a clean
//      decompile_func() in its absence. func_003a4d50 (4 saved registers)
//      never hit it; a 1725-function batch found 239 crashes, essentially
//      all multi-register prologues. Correctly not shipped.
//
//      WHY THAT IS NOT THE END OF IT
//      Both attempts tried to LIFT these instructions -- to give them
//      microcode semantics. That is the wrong goal. A callee-saved spill has
//      no meaning in C; the correct outcome is for it to be ELIDED, exactly
//      as Hex-Rays already elides an ordinary `sd $s0, off($sp)` prologue
//      save. The reason it fights back is that we are asserting a width for
//      a frame slot its own prolog analyzer has already measured.
//
//      THE APPROACH THAT HAS NOT BEEN TRIED
//      Hex-Rays exposes an "ignore this instruction" channel intended for
//      precisely this: get_ignore_micro()/set_ignore_micro() with IM_PROLOG
//      / IM_EPILOG. codegen_t even carries the per-instruction value
//      (`char ignore_micro = IM_NONE; // value of get_ignore_micro()`).
//      Marking a callee-saved sq as IM_PROLOG and its matching lq as
//      IM_EPILOG makes the decompiler skip microcode generation for them
//      entirely -- sidestepping analyze_prolog()'s width model instead of
//      contradicting it, which is why it should not reproduce the
//      MERR_INTERR class of failure.
//
//      Identification rule (conservative): a `sq $r, off($sp)` where $r is
//      callee-saved AND there is a matching `lq $r, off($sp)` from the same
//      offset is a save/restore pair by construction. Only mark those; a sq
//      doing real work mid-body must never be marked.
//
//      NOTE: set_ignore_micro/IM_PROLOG are NOT exposed in IDA 9.4's Python
//      API (checked: ida_hexrays exports only NORET_IGNORE_WAS_NORET_ICALL,
//      and IM_* are absent), so this cannot be prototyped from idalib and
//      requires the C++ SDK.
//
//      ACCEPTANCE TEST for any future attempt, non-negotiable: the
//      before/after control run over all 5100 sq/lq functions must show
//      failures not increasing from the no-plugin baseline. The MMI helper
//      tier in section 2 shipped without that check and regressed 71
//      functions.

//===========================================================================
//      4. COP0 BC0F/BC0T                                        [SHIPPED]
//===========================================================================
//      IDA's stock r5900 module mis-decodes the standard MIPS COP0
//      branch-on-condition instructions (BC0F/BC0T -- branch on the COP0
//      condition line, wired on the EE to hardware side-channels like the
//      DMAC channel-drain arbitration signal) as a bogus COP1
//      "mfthc1 $ra, $f0". Confirmed empirically: decode_insn on a retail
//      address known (via Ghidra's correct r5900 module) to hold
//      `bc0f 0x3a4f0c` -- raw word 0x4100fffa -- reports itype 0x2fe
//      ("mfthc1") with garbage operands that correspond to nothing in the
//      real instruction. This is a disassembler-level bug, not a Hex-Rays
//      gap: no microcode filter can fix wrong operands from a wrong decode,
//      since filters only run after ana() succeeds.
//
//      Fix: an HT_IDP hook intercepting ev_ana_insn/ev_emu_insn/ev_out_insn
//      for the specific 17-bit-fixed encoding (bits 31-17 =
//      0b01000001000000000, i.e. top 16 bits & 0xFFFE0000 == 0x41000000;
//      bit 16 is TF, 0=BC0F/1=BC0T; bits 15-0 are the standard MIPS branch
//      displacement in words). HT_IDP hooks run through the same
//      invoke_callbacks(HT_IDP, ...) dispatch the processor module's own
//      listener uses, and a callback returning nonzero short-circuits the
//      chain, so this pre-empts the module's wrong decode for this one bit
//      pattern and falls through (returns 0) for everything else.
//      Synthetic itypes 0x7f00/0x7f01 are used since the module's itype
//      table has no correct slot; they never escape this hook.

enum
{
  EE_SYN_BC0F = 0x7f00,
  EE_SYN_BC0T = 0x7f01,
};

static bool decode_bc0(ea_t ea, bool *tf, ea_t *target)
{
  uint32 word = get_dword(ea);
  if ( (word & 0xFFFE0000) != 0x41000000 )
    return false;
  *tf = ((word >> 16) & 1) != 0;
  int16 off16 = int16(word & 0xFFFF);
  *target = ea + 4 + ea_t(int32(off16) * 4);
  return true;
}

static ssize_t idaapi idp_callback(void *, int notification_code, va_list va)
{
  switch ( notification_code )
  {
    case processor_t::ev_ana_insn:
    {
      insn_t *out = va_arg(va, insn_t *);
      bool tf;
      ea_t target;
      if ( !decode_bc0(out->ea, &tf, &target) )
        return 0;
      out->itype = tf ? EE_SYN_BC0T : EE_SYN_BC0F;
      out->size = 4;
      out->ops[0].type = o_near;
      out->ops[0].dtype = dt_code;
      out->ops[0].addr = target;
      for ( int i = 1; i < UA_MAXOP; i++ )
        out->ops[i].type = o_void;
      return out->size;
    }

    case processor_t::ev_emu_insn:
    {
      const insn_t *insn = va_arg(va, const insn_t *);
      if ( insn->itype != EE_SYN_BC0F && insn->itype != EE_SYN_BC0T )
        return 0;
      // Conditional branch with a delay slot, same as every other MIPS
      // branch: the delay-slot instruction at ea+size always executes,
      // then control either continues or jumps to the decoded target.
      insn->add_cref(insn->ops[0].addr, 0, fl_JN);
      insn->add_cref(insn->ea + insn->size, 0, fl_F);
      return 1;
    }

    case processor_t::ev_out_insn:
    {
      outctx_t *ctx = va_arg(va, outctx_t *);
      if ( ctx->insn.itype != EE_SYN_BC0F && ctx->insn.itype != EE_SYN_BC0T )
        return 0;
      ctx->out_custom_mnem(ctx->insn.itype == EE_SYN_BC0T ? "bc0t" : "bc0f");
      ctx->out_name_expr(ctx->insn.ops[0], ctx->insn.ops[0].addr);
      ctx->flush_outbuf();
      return 1;
    }

    default:
      return 0;
  }
}

//===========================================================================
//      PLUGIN PLUMBING
//===========================================================================

static ee_mac_filter_t filter;
static ee_mmi_filter_t mmi_filter;
static bool filter_installed = false;

//-------------------------------------------------------------------------
static ssize_t idaapi hr_callback(void *, hexrays_event_t event, va_list)
{
  // Clear the per-function synthetic-register caches whenever a function's
  // microcode is regenerated from scratch, so a stale entry_ea->mreg_t
  // mapping from a previous decompilation of the same address (whose mba_t
  // has since been destroyed) is never reused.
  if ( event == hxe_maturity )
  {
    acc_kreg_by_func.clear();
    hi_kreg_by_func_reg.clear();
  }
  return 0;
}

static bool setup_done = false;

static void try_setup()
{
  if ( setup_done )
    return;
  if ( init_hexrays_plugin() )
  {
    install_microcode_filter(&filter, true);
    install_microcode_filter(&mmi_filter, true);
    install_hexrays_callback(hr_callback, nullptr);
    filter_installed = true;
    setup_done = true;
    msg("ee_mac_lifter: installed (Hex-Rays %s)\n", get_hexrays_version());
  }
}

static ssize_t idaapi idb_callback(void *, int notification_code, va_list)
{
  if ( notification_code == idb_event::auto_empty_finally )
    try_setup();
  return 0;
}

//-------------------------------------------------------------------------
static ssize_t idaapi ui_callback(void *, int notification_code, va_list)
{
  // Two independent hooks are used because no single notification is
  // confirmed to fire in every invocation mode:
  //   - ui_database_inited ("database initialization has completed") here.
  //   - idb_event::auto_empty_finally ("analysis queues empty,
  //     definitively") in idb_callback above, as a fallback for the case
  //     where this .idb/.i64 was already fully analyzed by an earlier
  //     session and reopening never re-triggers that empty-queue
  //     transition.
  // try_setup() is idempotent (guarded by setup_done), so firing from both
  // is safe. ui_ready_to_run was tried first and never fires under
  // `idat -A -S` or idalib (confirmed empirically: a debug-log write placed
  // inside its handler never appeared under either, even with a 2-second
  // wait before querying).
  //
  // Calling init_hexrays_plugin()/install_microcode_filter() directly from
  // init() crashes IDA (SIGSEGV): this plugin's filename sorts, and
  // therefore loads, before "hexmips"/"hexx64" within the same load pass,
  // so Hex-Rays' internal filter-list state is not allocated yet at that
  // point (confirmed via `idat -z20` plugin-load tracing and a reproducible
  // crash).
  if ( notification_code == ui_database_inited )
    try_setup();
  return 0;
}

//-------------------------------------------------------------------------
static plugmod_t *idaapi init()
{
  hook_to_notification_point(HT_IDP, idp_callback, nullptr);
  hook_to_notification_point(HT_IDB, idb_callback, nullptr);
  hook_to_notification_point(HT_UI, ui_callback, nullptr);
  return PLUGIN_KEEP;
}

static void idaapi term()
{
  unhook_from_notification_point(HT_IDP, idp_callback, nullptr);
  unhook_from_notification_point(HT_IDB, idb_callback, nullptr);
  unhook_from_notification_point(HT_UI, ui_callback, nullptr);
  if ( filter_installed )
  {
    install_microcode_filter(&filter, false);
    install_microcode_filter(&mmi_filter, false);
    remove_hexrays_callback(hr_callback, nullptr);
    filter_installed = false;
  }
}

//-------------------------------------------------------------------------
static const char comment[] =
  "Lift EE (PS2 MIPS) FPU accumulator-chain instructions "
  "(adda.s/suba.s/mula.s/madda.s/msuba.s/madd.s/msub.s), MMI pcpyld/pcpyud, "
  "and COP0 bc0f/bc0t branches to real Hex-Rays pseudocode / correct "
  "disassembly instead of __asm{} islands / wrong mnemonics";

plugin_t PLUGIN =
{
  IDP_INTERFACE_VERSION,
  PLUGIN_HIDE,   // decompiler-dependent init: must run in the later
                 // "remaining plugins" load pass, after the processor-
                 // specific hexrays engine (hexmips.so etc) has registered
                 // -- a plain PLUGIN_FIX runs too early (before the
                 // decompiler loads) and init_hexrays_plugin() legitimately
                 // fails every time. Confirmed via `idat -z20` plugin-load
                 // tracing. (PLUGIN_MULTI was tried too but is incompatible
                 // with a plain term() callback -- would need the plugmod_t
                 // class pattern instead.)
  init,
  term,
  nullptr,
  comment,
  "",
  "EE FPU accumulator-chain + MMI + bc0f/bc0t lifter",
  ""
};
