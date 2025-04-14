#ifndef LLVM_LIB_TARGET_GFV_GFVTARGETMACHINE_H
#define LLVM_LIB_TARGET_GFV_GFVTARGETMACHINE_H
 
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>
 
namespace llvm {
  extern Target TheGfvTarget;
 
  class GfvTargetMachine : public CodeGenTargetMachineImpl {
  public:
    GfvTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
		     StringRef FS, const TargetOptions &Options,
		     std::optional<Reloc::Model> RM,
		     std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
		     bool JIT);
    // Pass Pipeline Configuration
   TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  };
} // end namespace llvm
 
#endif // LLVM_LIB_TARGET_GFV_GFVTARGETMACHINE_H
