#include "GfvISelLowering.h"
#include "Gfv.h"
#include "GfvRegisterInfo.h"
#include "GfvSubtarget.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"
 
#define DEBUG_TYPE "Gfv-lower"
 
using namespace llvm;
 
GfvTargetLowering::GfvTargetLowering(const TargetMachine &TM,
				     const GfvSubtarget &STI)
  : TargetLowering(TM), STI(STI) {
  GFV_DUMP_RED
    addRegisterClass(MVT::i32, &Gfv::GPRRegClass);
}
 
const char *GfvTargetLowering::getTargetNodeName(unsigned Opcode) const {
  GFV_DUMP_RED
    switch (Opcode) {
    case GfvISD::CALL:
      return "GfvISD::CALL";
    case GfvISD::RET:
      return "GfvISD::RET";
    }
  return nullptr;
}
