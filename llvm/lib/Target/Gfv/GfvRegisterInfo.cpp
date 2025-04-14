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

const MCPhysReg *
GfvRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  GFV_DUMP_GREEN
  return CSR_Gfv_SaveList;
}
 
BitVector GfvRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  GFV_DUMP_GREEN
  GfvFrameLowering const *TFI = getFrameLowering(MF);
 
  BitVector Reserved(getNumRegs());
  Reserved.set(Gfv::R1);
 
  if (TFI->hasFP(MF)) {
    Reserved.set(Gfv::R2);
  }
  return Reserved;
}
 
bool GfvRegisterInfo::requiresRegisterScavenging(
						 const MachineFunction &MF) const {
  return false;
}
 
bool GfvRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
					  int SPAdj, unsigned FIOperandNum,
					  RegScavenger *RS) const {
  GFV_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");
 
  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();
 
  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
    ->getFrameIndexReference(MF, FrameIndex, FrameReg)
    .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();
 
  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }
 
  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}
 
Register GfvRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  GFV_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? Gfv::R2 : Gfv::R1;
}
 
const uint32_t *
GfvRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
				      CallingConv::ID CC) const {
  GFV_DUMP_GREEN
  return CSR_Gfv_RegMask;
}
