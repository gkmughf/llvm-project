#ifndef LLVM_LIB_TARGET_GFV_MCTARGETDESC_GFVINFO_H
#define LLVM_LIB_TARGET_GFV_MCTARGETDESC_GFVINFO_H
 
#include "llvm/MC/MCInstrDesc.h"
 
namespace llvm {
 
  namespace GfvOp {
    enum OperandType : unsigned {
      OPERAND_SIMM16 = MCOI::OPERAND_FIRST_TARGET,
	};
  } // namespace GfvOp
 
} // end namespace llvm
 
#endif
