#include "GfvInstrInfo.h"
#include "Gfv.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
 
using namespace llvm;
 
#define GET_INSTRINFO_CTOR_DTOR
#include "GfvGenInstrInfo.inc"
 
#define DEBUG_TYPE "Gfv-inst-info"
 
GfvInstrInfo::GfvInstrInfo() : GfvGenInstrInfo() { GFV_DUMP_GREEN }
