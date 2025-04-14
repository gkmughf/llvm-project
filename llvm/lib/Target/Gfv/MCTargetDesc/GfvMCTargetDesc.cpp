#include "MCTargetDesc/GfvInfo.h"
#include "Gfv.h"
#include "GfvInstPrinter.h"
#include "GfvMCAsmInfo.h"
#include "TargetInfo/GfvTargetInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

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


static MCAsmInfo *createGfvMCAsmInfo(const MCRegisterInfo &MRI,
				     const Triple &TT,
				     const MCTargetOptions &Options) {
  GFV_DUMP_MAGENTA
  MCAsmInfo *MAI = new GfvELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(Gfv::R1, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

static MCInstPrinter *createGfvMCInstPrinter(const Triple &T,
                                              unsigned SyntaxVariant,
                                              const MCAsmInfo &MAI,
                                              const MCInstrInfo &MII,
                                              const MCRegisterInfo &MRI) {
   GFV_DUMP_MAGENTA
   return new GfvInstPrinter(MAI, MII, MRI);
 }


// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGfvTargetMC() {
  GFV_DUMP_MAGENTA
  Target &TheGfvTarget = getTheGfvTarget();
  RegisterMCAsmInfoFn X(TheGfvTarget, createGfvMCAsmInfo);
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheGfvTarget, createGfvMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheGfvTarget, createGfvMCInstrInfo);
  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheGfvTarget,
					  createGfvMCSubtargetInfo);
  // Register the MCInstPrinter
  TargetRegistry::RegisterMCInstPrinter(TheGfvTarget, createGfvMCInstPrinter);
}
