#include "TargetInfo/GfvTargetInfo.h"
#include "Gfv.h"
#include "llvm/MC/TargetRegistry.h"
 
using namespace llvm;
 
Target &llvm::getTheGfvTarget() {
  GFV_DUMP_YELLOW
    static Target TheGfvTarget;
  return TheGfvTarget;
}
 
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGfvTargetInfo() {
  GFV_DUMP_YELLOW
    RegisterTarget<Triple::gfv> X(getTheGfvTarget(), "gfv",
				  "Gfvulator target for LLVM course", "GFV");
}
