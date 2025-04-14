#ifndef LLVM_LIB_TARGET_GFV_GFVINSTRINFO_H
#define LLVM_LIB_TARGET_GFV_GFVINSTRINFO_H
 
#include "GfvRegisterInfo.h"
#include "MCTargetDesc/GfvInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"
 
#define GET_INSTRINFO_HEADER
#include "GfvGenInstrInfo.inc"
 
namespace llvm {
 
  class GfvSubtarget;
 
  class GfvInstrInfo : public GfvGenInstrInfo {
  public:
    GfvInstrInfo();
 
  };
 
} // end namespace llvm
 
#endif // LLVM_LIB_TARGET_GFV_GFVINSTRINFO_H
