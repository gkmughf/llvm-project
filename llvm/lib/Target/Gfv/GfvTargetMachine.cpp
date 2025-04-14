#include "GfvTargetMachine.h"
#include "Gfv.h"
#include "TargetInfo/GfvTargetInfo.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>
 
using namespace llvm;
 
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGfvTarget() {
  // Register the target.
  GFV_DUMP_CYAN
    RegisterTargetMachine<GfvTargetMachine> A(getTheGfvTarget());
}
 
GfvTargetMachine::GfvTargetMachine(const Target &T, const Triple &TT,
				   StringRef CPU, StringRef FS,
				   const TargetOptions &Options,
				   std::optional<Reloc::Model> RM,
				   std::optional<CodeModel::Model> CM,
				   CodeGenOptLevel OL, bool JIT)
  : CodeGenTargetMachineImpl(
			     T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32", TT, CPU, FS, Options,
			     Reloc::Static, getEffectiveCodeModel(CM, CodeModel::Small), OL) {
  GFV_DUMP_CYAN
  initAsmInfo();
}

namespace {
 
  /// Gfv Code Generator Pass Configuration Options.
  class GfvPassConfig : public TargetPassConfig {
  public:
    GfvPassConfig(GfvTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}
 
    bool addInstSelector() override {
      GFV_DUMP_CYAN
	return false;
    }
  };
 
} // end anonymous namespace
 
TargetPassConfig *GfvTargetMachine::createPassConfig(PassManagerBase &PM) {
  GFV_DUMP_CYAN
    return new GfvPassConfig(*this, PM);
}
