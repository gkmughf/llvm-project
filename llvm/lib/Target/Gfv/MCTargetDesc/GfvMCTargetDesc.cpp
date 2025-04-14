#include "Gfv.h"
#include "TargetInfo/GfvTargetInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"
 
using namespace llvm;
 
#define GET_REGINFO_MC_DESC
#include "GfvGenRegisterInfo.inc"
 
static MCRegisterInfo *createGfvMCRegisterInfo(const Triple &TT) {
  GFV_DUMP_MAGENTA
    MCRegisterInfo *X = new MCRegisterInfo();
  InitGfvMCRegisterInfo(X, Gfv::R0);
  return X;
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGfvTargetMC() {
  GFV_DUMP_MAGENTA
    Target &TheGfvTarget = getTheGfvTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheGfvTarget, createGfvMCRegisterInfo);
}
