#include "GfvSubtarget.h"
#include "Gfv.h"
#include "llvm/Target/TargetMachine.h"
 
using namespace llvm;
 
#define DEBUG_TYPE "gfv-subtarget"
 
#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "GfvGenSubtargetInfo.inc"
 
GfvSubtarget::GfvSubtarget(const StringRef &CPU, const StringRef &TuneCPU,
			   const StringRef &FS, const TargetMachine &TM)
  : GfvGenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {
  GFV_DUMP_CYAN
}
