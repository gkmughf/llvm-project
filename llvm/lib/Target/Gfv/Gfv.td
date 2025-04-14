include "llvm/Target/Target.td"
include "GfvRegisterInfo.td"
include "GfvInstrInfo.td"
include "GfvCallingConv.td"

class Proc<string Name, list<SubtargetFeature> Features>
  : Processor<Name, NoItineraries, Features>;
 
 def : Proc<"generic", []>;

def GfvInstrInfo : InstrInfo;
def Gfv : Target {
  let InstructionSet = GfvInstrInfo;
}