#ifndef LLVM_LIB_TARGET_GFV_GFVISELLOWERING_H
#define LLVM_LIB_TARGET_GFV_GFVISELLOWERING_H
 
#include "Gfv.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"
 
namespace llvm {
 
  class GfvSubtarget;
  class GfvTargetMachine;
 
  namespace GfvISD {
 
    enum NodeType : unsigned {
      // Start the numbering where the builtin ops and target ops leave off.
      FIRST_NUMBER = ISD::BUILTIN_OP_END,
	RET,
	CALL,
	BR_CC,
	};
 
  } // namespace GfvISD
  
  class GfvTargetLowering : public TargetLowering {
  public:
    explicit GfvTargetLowering(const TargetMachine &TM, const GfvSubtarget &STI);
 
    /// This method returns the name of a target specific DAG node.
    const char *getTargetNodeName(unsigned Opcode) const override;
 
    GfvSubtarget const &getSubtarget() const { return STI; }
 
  private:
    const GfvSubtarget &STI;
  };
} // end namespace llvm
 
#endif // LLVM_LIB_TARGET_GFV_GFVISELLOWERING_H
