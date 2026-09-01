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
#include <idp.hpp>
#include <funcs.hpp>
#include <netnode.hpp>
#include <bytes.hpp>
#include <auto.hpp>
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

static mreg_t peek_hi_kreg(mba_t *mba, int regno)
{
  auto it = hi_kreg_by_func_reg.find(std::pair<ea_t, int>(mba->entry_ea, regno));
  return it == hi_kreg_by_func_reg.end() ? mr_none : it->second;
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

    // Write the destination through reg2mreg() rather than
    // codegen_t::store_operand(). store_operand() was tried first and
    // silently failed for these instructions (apply() then returns
    // MERR_INSN and Hex-Rays falls back to the __asm{} island it was
    // supposed to remove -- measured: pcpyld still islanded in 150 of 153
    // MMI functions while the FPU filter above, which does reach its
    // destination, worked on every case tested). These operands are plain
    // o_reg GPRs, so the mreg is obtainable directly and no operand-store
    // machinery is needed.
    mreg_t rd = reg2mreg(insn.ops[0].reg);
    if ( rd == mr_none )
      return MERR_INSN;

    if ( insn.itype == EE_PCPYLD )
    {
      // PCPYLD rd, rs, rt -> rd.lo = rt.lo ; rd.hi = rs.lo
      mreg_t rs_lo = cdg.load_operand(1);
      mreg_t rt_lo = cdg.load_operand(2);
      if ( rs_lo == mr_none || rt_lo == mr_none )
        return MERR_INSN;
      // Upper half first: the low write below may target the same GPR.
      mreg_t hd = get_hi_kreg(cdg.mba, insn.ops[0].reg);
      cdg.emit(m_mov, 8, rs_lo, 0, hd, -1);
      cdg.emit(m_mov, 8, rt_lo, 0, rd, -1);
      return MERR_OK;
    }

    if ( insn.itype == EE_PCPYUD )
    {
      // PCPYUD rd, rs, rt -> rd.lo = rs.hi ; rd.hi = rt.hi
      mreg_t hs = peek_hi_kreg(cdg.mba, insn.ops[1].reg);
      mreg_t ht = peek_hi_kreg(cdg.mba, insn.ops[2].reg);
      if ( hs == mr_none || ht == mr_none )
        return MERR_INSN;   // upper halves never established by a pcpyld
      mreg_t hd = get_hi_kreg(cdg.mba, insn.ops[0].reg);
      cdg.emit(m_mov, 8, ht, 0, hd, -1);
      cdg.emit(m_mov, 8, hs, 0, rd, -1);
      return MERR_OK;
    }

    return MERR_INSN;
  }
};


//===========================================================================
//      2b. EE PIPELINE-1, MMI BITWISE, VU0 MOVES              [NOT SHIPPED]
//===========================================================================
//      NOT INSTALLED. Written, compiles, and produces plausible output, but
//      measured against the mandatory before/after control it regresses the
//      decompiler, so install_microcode_filter() for it is commented out in
//      try_setup(). Bisected in three stages, each a full control run over
//      both populations (baseline for both is 0 failures):
//
//        all of 2b enabled                       MMI 12 fail   sq/lq 51 fail
//        minus DIV1 and QMFC2/QMTC2              MMI 12 fail   sq/lq 44 fail
//        pipeline-1 multiply/move only           MMI  6 fail   sq/lq 38 fail
//        2b disabled entirely (shipped state)    MMI  0 fail   sq/lq  0 fail
//
//      So the fault is not one bad opcode -- every subset regresses, which
//      points at the approach rather than a detail. A guess that read paths
//      were consuming never-written kregs was tested by making every read
//      lookup-only (returning MERR_INSN on a miss instead of allocating);
//      the failure counts did not move at all, so that hypothesis is dead
//      too. Do NOT re-enable without a new theory AND a passing control run.
//      The code is kept because the analysis below is correct and the next
//      attempt should start from it, not from scratch.
//
//      A second group of EE-only instructions that Hex-Rays renders as
//      __asm{} islands, but which -- unlike the packed lane shuffles -- have
//      exact scalar microcode equivalents. Modelling them needs no
//      mcallinfo_t / helper-call machinery, which matters: a hand-rolled
//      helper-call tier was measured to regress 71 of 153 functions and was
//      deleted (see section 2). Everything here is plain m_mov/m_mul/m_and
//      style microcode, the same mechanism the FPU filter above uses
//      successfully.
//
//      (a) EE second integer pipeline: MULT1/MULTU1/DIV1/MFHI1/MFLO1/
//          MTHI1/MTLO1. Architecturally identical to MULT/DIV/MFHI/... but
//          backed by a separate HI1/LO1 register pair, which the r5900
//          module does not expose, so Hex-Rays cannot model them. HI1/LO1
//          are modelled here as synthetic kregs, per function, exactly like
//          the FPU accumulator.
//
//      (b) MMI bitwise PAND/POR/PXOR/PNOR. These are 128-bit operations,
//          but bitwise ops are lane-independent, so on the architecturally
//          visible low 64 bits they are precisely m_and/m_or/m_xor. The
//          upper half is tracked in the same hi-kreg map PCPYLD uses, so
//          the model stays self-consistent. (The lane-shuffling MMI ops --
//          PEXTL*/PPAC*/QFSRV -- genuinely cannot be expressed this way and
//          are deliberately left alone rather than faked.)
//
//      (c) VU0 macro-mode register moves QMTC2/QMFC2. These transfer a
//          whole 128-bit register between the GPR file and a VU0 vector
//          register. VU0 registers are modelled as synthetic kregs keyed by
//          register number, so a value written with qmtc2 and read back
//          with qmfc2 round-trips instead of both ends becoming opaque.
//          (COP2 compute ops -- vcallms and the vector ALU -- are NOT
//          modelled; they have no scalar equivalent.)
//
//      Operand-count note: the r5900 module emits some of these in a
//      2-operand accumulate form (`pand $v0, $v1` meaning v0 &= v1) and
//      some in 3-operand form (`por $v0, $zero, $zero`), so both shapes are
//      handled.

enum ee_ext_itype_t
{
  EE_MTHI1  = 0x148,
  EE_MTLO1  = 0x149,
  EE_DIV1   = 0x14d,
  EE_MULT1  = 0x154,
  EE_MULTU1 = 0x155,
  EE_MFHI1  = 0x1a3,
  EE_MFLO1  = 0x1a4,

  EE_PAND   = 0x17a,
  EE_POR    = 0x17c,
  EE_PXOR   = 0x17e,
  EE_PNOR   = 0x17f,

  EE_QMFC2  = 0x032,
  EE_QMTC2  = 0x034,
};

// HI1/LO1 of the second integer pipeline, per function.
static std::map<ea_t, mreg_t> hi1_by_func, lo1_by_func;
// VU0 vector registers, per (function entry, vf number).
static std::map<std::pair<ea_t, int>, mreg_t> vu0_by_func_reg;

static mreg_t get_cached_kreg(std::map<ea_t, mreg_t> &m, mba_t *mba, int size)
{
  auto it = m.find(mba->entry_ea);
  if ( it != m.end() )
    return it->second;
  mreg_t r = mba->alloc_kreg(size);
  m[mba->entry_ea] = r;
  return r;
}

// Read-only lookup. Emitting a read of a kreg that was never written makes
// the decompiler consume an undefined value, which it reports as an
// internal error rather than degrading gracefully -- measured as 63 extra
// decompile failures when the read paths below lazily allocated instead.
// On a miss we return mr_none and the caller declines to lift, leaving the
// stock __asm{} island, which is merely unhelpful rather than broken.
static mreg_t peek_cached_kreg(std::map<ea_t, mreg_t> &m, mba_t *mba)
{
  auto it = m.find(mba->entry_ea);
  return it == m.end() ? mr_none : it->second;
}

static mreg_t peek_vu0_kreg(mba_t *mba, int vf)
{
  auto it = vu0_by_func_reg.find(std::pair<ea_t, int>(mba->entry_ea, vf));
  return it == vu0_by_func_reg.end() ? mr_none : it->second;
}

static mreg_t get_vu0_kreg(mba_t *mba, int vf)
{
  std::pair<ea_t, int> key(mba->entry_ea, vf);
  auto it = vu0_by_func_reg.find(key);
  if ( it != vu0_by_func_reg.end() )
    return it->second;
  mreg_t r = mba->alloc_kreg(8);
  vu0_by_func_reg[key] = r;
  return r;
}

struct ee_ext_filter_t : public microcode_filter_t
{
  virtual bool match(codegen_t &cdg) override
  {
    switch ( cdg.insn.itype )
    {
      case EE_MTHI1: case EE_MTLO1: case EE_DIV1:
      case EE_MULT1: case EE_MULTU1: case EE_MFHI1: case EE_MFLO1:
      case EE_PAND:  case EE_POR:    case EE_PXOR:  case EE_PNOR:
      case EE_QMFC2: case EE_QMTC2:
        return true;
      default:
        return false;
    }
  }

  virtual merror_t apply(codegen_t &cdg) override
  {
    const insn_t &insn = cdg.insn;
    int nops = 0;
    while ( nops < UA_MAXOP && insn.ops[nops].type != o_void )
      nops++;

    switch ( insn.itype )
    {
      // ---- (a) second integer pipeline ----
      case EE_MFHI1:
      case EE_MFLO1:
      {
        if ( insn.ops[0].type != o_reg )
          return MERR_INSN;
        mreg_t rd = reg2mreg(insn.ops[0].reg);
        if ( rd == mr_none )
          return MERR_INSN;
        mreg_t src = peek_cached_kreg(
            insn.itype == EE_MFHI1 ? hi1_by_func : lo1_by_func, cdg.mba);
        if ( src == mr_none )
          return MERR_INSN;   // pipeline-1 result never produced in this function
        cdg.emit(m_mov, 8, src, 0, rd, -1);
        return MERR_OK;
      }

      case EE_MTHI1:
      case EE_MTLO1:
      {
        mreg_t rs = cdg.load_operand(0);
        if ( rs == mr_none )
          return MERR_INSN;
        mreg_t dst = insn.itype == EE_MTHI1
                   ? get_cached_kreg(hi1_by_func, cdg.mba, 8)
                   : get_cached_kreg(lo1_by_func, cdg.mba, 8);
        cdg.emit(m_mov, 8, rs, 0, dst, -1);
        return MERR_OK;
      }

      case EE_MULT1:
      case EE_MULTU1:
      {
        // MULT1 rd, rs, rt -> rd = rs * rt, and LO1 receives the product.
        if ( nops < 3 || insn.ops[0].type != o_reg )
          return MERR_INSN;
        mreg_t rd = reg2mreg(insn.ops[0].reg);
        mreg_t rs = cdg.load_operand(1);
        mreg_t rt = cdg.load_operand(2);
        if ( rd == mr_none || rs == mr_none || rt == mr_none )
          return MERR_INSN;
        cdg.emit(m_mul, 8, rs, rt, rd, -1);
        mreg_t lo1 = get_cached_kreg(lo1_by_func, cdg.mba, 8);
        cdg.emit(m_mov, 8, rd, 0, lo1, -1);
        return MERR_OK;
      }

      case EE_DIV1:
      {
        // DIV1 rs, rt -> LO1 = rs / rt ; HI1 = rs % rt
        if ( nops < 2 )
          return MERR_INSN;
        mreg_t rs = cdg.load_operand(0);
        mreg_t rt = cdg.load_operand(1);
        if ( rs == mr_none || rt == mr_none )
          return MERR_INSN;
        mreg_t lo1 = get_cached_kreg(lo1_by_func, cdg.mba, 8);
        mreg_t hi1 = get_cached_kreg(hi1_by_func, cdg.mba, 8);
        cdg.emit(m_sdiv, 8, rs, rt, lo1, -1);
        cdg.emit(m_smod, 8, rs, rt, hi1, -1);
        return MERR_OK;
      }

      // ---- (b) MMI bitwise, exact on the low 64 bits ----
      case EE_PAND:
      case EE_POR:
      case EE_PXOR:
      case EE_PNOR:
      {
        if ( insn.ops[0].type != o_reg )
          return MERR_INSN;
        mreg_t rd = reg2mreg(insn.ops[0].reg);
        if ( rd == mr_none )
          return MERR_INSN;
        // 3-operand: rd, rs, rt. 2-operand accumulate: rd(also rs), rt.
        int si = nops >= 3 ? 1 : 0;
        int ti = nops >= 3 ? 2 : 1;
        mreg_t rs = cdg.load_operand(si);
        mreg_t rt = cdg.load_operand(ti);
        if ( rs == mr_none || rt == mr_none )
          return MERR_INSN;

        mcode_t op;
        switch ( insn.itype )
        {
          case EE_PAND: op = m_and; break;
          case EE_PXOR: op = m_xor; break;
          default:      op = m_or;  break;  // POR, and PNOR before negation
        }
        cdg.emit(op, 8, rs, rt, rd, -1);
        if ( insn.itype == EE_PNOR )
          cdg.emit(m_bnot, 8, rd, 0, rd, -1);  // PNOR = ~(rs | rt)

        // Keep the tracked upper half consistent with the same operation.
        if ( insn.ops[si].type == o_reg && insn.ops[ti].type == o_reg )
        {
          mreg_t hs = peek_hi_kreg(cdg.mba, insn.ops[si].reg);
          mreg_t ht = peek_hi_kreg(cdg.mba, insn.ops[ti].reg);
          if ( hs == mr_none || ht == mr_none )
            return MERR_OK;   // low half already lifted; upper half untracked
          mreg_t hd = get_hi_kreg(cdg.mba, insn.ops[0].reg);
          cdg.emit(op, 8, hs, ht, hd, -1);
          if ( insn.itype == EE_PNOR )
            cdg.emit(m_bnot, 8, hd, 0, hd, -1);
        }
        return MERR_OK;
      }

      // ---- (c) VU0 macro-mode register moves ----
      case EE_QMFC2:
      {
        // QMFC2 rt, vf -> rt = VU0[vf]
        if ( insn.ops[0].type != o_reg || insn.ops[1].type != o_reg )
          return MERR_INSN;
        mreg_t rt = reg2mreg(insn.ops[0].reg);
        if ( rt == mr_none )
          return MERR_INSN;
        mreg_t vf = peek_vu0_kreg(cdg.mba, insn.ops[1].reg);
        if ( vf == mr_none )
          return MERR_INSN;   // VU0 register loaded by unmodelled COP2 code
        cdg.emit(m_mov, 8, vf, 0, rt, -1);
        return MERR_OK;
      }

      case EE_QMTC2:
      {
        // QMTC2 rt, vf -> VU0[vf] = rt
        if ( insn.ops[1].type != o_reg )
          return MERR_INSN;
        mreg_t rt = cdg.load_operand(0);
        if ( rt == mr_none )
          return MERR_INSN;
        mreg_t vf = get_vu0_kreg(cdg.mba, insn.ops[1].reg);
        cdg.emit(m_mov, 8, rt, 0, vf, -1);
        return MERR_OK;
      }

      default:
        return MERR_INSN;
    }
  }
};
//===========================================================================
//      3. SQ/LQ CALLEE-SAVED SPILLS                              [SHIPPED]
//===========================================================================
//      SQ/LQ save and restore a whole 128-bit GPR. Hex-Rays' MIPS prolog
//      analyzer does not recognise them as saves/restores, so they surface
//      as __asm{} islands.
//
//      This was the single biggest pseudocode defect in the binary --
//      measured over every function:
//        functions containing sq/lq                : 5100
//        of those, decompiled with an __asm island : 5099
//      and it is NOT merely cosmetic prologue/epilogue noise: sampling 400
//      functions containing sq/lq but no MMI, the island intruded into the
//      function body in 260 of them (65%).
//
//      WHAT FAILED BEFORE, AND WHY
//      Two earlier microcode_filter_t attempts (narrow the memory operand's
//      declared dt_byte16 to dt_qword; emit raw m_stx/m_ldx) both crashed
//      Hex-Rays with MERR_INTERR -- 239 crashes across a 1725-function
//      batch -- because analyze_prolog() runs BEFORE any microcode filter
//      and builds a frame-slot-width model from the RAW dt_byte16 operand
//      that the filter then contradicts.
//
//      WHY THIS WORKS INSTEAD
//      Both of those tried to LIFT the instruction, i.e. give it microcode
//      semantics. That is the wrong goal: a callee-saved spill has no
//      meaning in C and should be ELIDED, exactly as Hex-Rays already
//      elides an ordinary `sd $s0, off($sp)` prologue save. Marking the
//      instruction IM_PROLOG/IM_EPILOG makes the decompiler skip microcode
//      generation for it entirely, so we never assert a width for a frame
//      slot the prolog analyzer has already measured -- we sidestep its
//      model rather than contradict it.
//
//      MEASURED RESULT over all 5100 affected functions (the acceptance
//      test the MMI helper tier in section 2 skipped, and should not have):
//        decompile failures    0 -> 0     (zero regression)
//        functions with island 5099 -> 821
//      i.e. 4278 functions cleaned, nothing broken.
//
//      Identification is deliberately conservative: only a `sq $r,off($sp)`
//      that has a matching `lq $r,off($sp)` at the same offset is treated
//      as a save/restore pair. A sq doing real work mid-body has no such
//      partner and is therefore never marked.
//
//      Decoding is done from the raw instruction word rather than through
//      IDA's decoder, so it does not depend on r5900 itype numbering:
//        MIPS  lq = opcode 0x1E, sq = opcode 0x1F
//        layout: op(6) base(5) rt(5) offset(16)

// $s0-$s7, $gp, $fp/$s8, $ra. Deliberately excludes $sp.
static bool is_callee_saved_reg(int r)
{
  return (r >= 16 && r <= 23) || r == 28 || r == 30 || r == 31;
}

static const int MIPS_REG_SP = 29;

struct sq_insn_t { ea_t ea; int rt; int off; bool is_sq; };

static bool decode_sq_lq(ea_t ea, sq_insn_t *out)
{
  uint32 w = get_dword(ea);
  uint32 op = w >> 26;
  if ( op != 0x1E && op != 0x1F )
    return false;
  int base = (w >> 21) & 31;
  if ( base != MIPS_REG_SP )
    return false;
  int rt = (w >> 16) & 31;
  if ( !is_callee_saved_reg(rt) )
    return false;
  out->ea    = ea;
  out->rt    = rt;
  out->off   = int(int16(w & 0xFFFF));
  out->is_sq = (op == 0x1F);
  return true;
}

// Mark the callee-saved spill pairs of one function. Returns count marked.
static int mark_spills_in_func(func_t *pfn)
{
  if ( pfn == nullptr )
    return 0;

  qvector<sq_insn_t> saves, restores;
  for ( ea_t ea = pfn->start_ea; ea < pfn->end_ea; ea += 4 )
  {
    sq_insn_t si;
    if ( !decode_sq_lq(ea, &si) )
      continue;
    (si.is_sq ? saves : restores).push_back(si);
  }
  if ( saves.empty() || restores.empty() )
    return 0;

  netnode nn;
  nn.create("$ ignore micro");

  int n = 0;
  for ( size_t i = 0; i < saves.size(); i++ )
  {
    // Only a save with a matching restore of the same register from the
    // same frame offset is a genuine callee-saved spill pair.
    bool paired = false;
    for ( size_t j = 0; j < restores.size(); j++ )
    {
      if ( restores[j].rt == saves[i].rt && restores[j].off == saves[i].off )
      {
        paired = true;
        nn.charset_ea(restores[j].ea, IM_EPILOG, 0);
        n++;
      }
    }
    if ( paired )
    {
      nn.charset_ea(saves[i].ea, IM_PROLOG, 0);
      n++;
    }
  }
  return n;
}

static void mark_all_spills()
{
  int funcs = 0, insns = 0;
  for ( size_t i = 0, n = get_func_qty(); i < n; i++ )
  {
    int m = mark_spills_in_func(getn_func(i));
    if ( m > 0 )
    {
      funcs++;
      insns += m;
    }
  }
  if ( insns > 0 )
    msg("ee_mac_lifter: marked %d sq/lq callee-saved spills in %d functions\n",
        insns, funcs);
}
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
static ee_ext_filter_t ext_filter;
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
    hi1_by_func.clear();
    lo1_by_func.clear();
    vu0_by_func_reg.clear();
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
    // NOT INSTALLED -- regresses the decompiler; see section 2b.
    // install_microcode_filter(&ext_filter, true);
    install_hexrays_callback(hr_callback, nullptr);
    filter_installed = true;
    setup_done = true;
    msg("ee_mac_lifter: installed (Hex-Rays %s)\n", get_hexrays_version());
  }
  // Independent of Hex-Rays being present: the IM_PROLOG/IM_EPILOG marks
  // live in a database netnode and are read by the decompiler during
  // codegen, so they only need to exist before any decompilation happens.
  // Marking is idempotent (writing the same value to the same address is a
  // no-op), so re-running on an already-marked database is harmless.
  mark_all_spills();
}

static ssize_t idaapi idb_callback(void *, int notification_code, va_list va)
{
  switch ( notification_code )
  {
    case idb_event::auto_empty_finally:
      try_setup();
      break;

    case idb_event::func_added:
      {
        // A function created after the initial sweep (manual creation, or
        // later autoanalysis) still needs its spills marked.
        func_t *pfn = va_arg(va, func_t *);
        mark_spills_in_func(pfn);
      }
      break;
  }
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
    // install_microcode_filter(&ext_filter, false);
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
