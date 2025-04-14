include "llvm/Target/Target.td"
include "GfvRegisterInfo.td"
include "GfvInstrInfo.td"

def GfvInstrInfo : InstrInfo;
def Gfv : Target {
  let InstructionSet = GfvInstrInfo;
}