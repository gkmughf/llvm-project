#include "MCTargetDesc/GfvInfo.h"
#include "Gfv.h"
#include "TargetInfo/GfvTargetInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
 
using namespace llvm;
 
#define GET_REGINFO_MC_DESC
#include "GfvGenRegisterInfo.inc"


#define GET_INSTRINFO_MC_DESC
#include "GfvGenInstrInfo.inc"


#define GET_SUBTARGETINFO_MC_DESC
#include "GfvGenSubtargetInfo.inc"

static MCRegisterInfo *createGfvMCRegisterInfo(const Triple &TT) {
  GFV_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitGfvMCRegisterInfo(X, Gfv::R0);
  return X;
}


static MCInstrInfo *createGfvMCInstrInfo() {
  GFV_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitGfvMCInstrInfo(X);
  return X;
}


static MCSubtargetInfo *createGfvMCSubtargetInfo(const Triple &TT,
                                                  StringRef CPU, StringRef FS) {
  GFV_DUMP_MAGENTA
  return createGfvMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGfvTargetMC() {
  GFV_DUMP_MAGENTA
    Target &TheGfvTarget = getTheGfvTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheGfvTarget, createGfvMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheGfvTarget, createGfvMCInstrInfo);
  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheGfvTarget,
					  createGfvMCSubtargetInfo);
}
