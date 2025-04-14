#ifndef LLVM_LIB_TARGET_GFV_MCTARGETDESC_GFVMCTARGETDESC_H
#define LLVM_LIB_TARGET_GFV_MCTARGETDESC_GFVMCTARGETDESC_H


namespace llvm {
  class MCCodeEmitter;
  class MCContext;
  class MCInstrInfo;
 
  MCCodeEmitter *createGfvMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);
} // namespace llvm

// Defines symbolic names for Gfv registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "GfvGenRegisterInfo.inc"


// Defines symbolic names for the Gfv instructions.
#define GET_INSTRINFO_ENUM
#include "GfvGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_GFV_MCTARGETDESC_GFVMCTARGETDESC_H
