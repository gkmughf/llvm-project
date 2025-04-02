#include "../Gfv.h"
#include "llvm/Support/raw_ostream.h"

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGfvTargetMC() { GFV_DUMP_MAGENTA }
