#include "GfvRegisterInfo.h"
#include "Gfv.h"
#include "GfvFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"
 
using namespace llvm;
 
#define GET_REGINFO_TARGET_DESC
#include "GfvGenRegisterInfo.inc"
 
GfvRegisterInfo::GfvRegisterInfo() : GfvGenRegisterInfo(Gfv::R0) {
  GFV_DUMP_GREEN
    }
