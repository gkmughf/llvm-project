#ifndef LLVM_LIB_TARGET_GFV_GFVTARGETMACHINE_H
#define LLVM_LIB_TARGET_GFV_GFVTARGETMACHINE_H

#include "GfvSubtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>
 
namespace llvm {
  extern Target TheGfvTarget;
 
  class GfvTargetMachine : public CodeGenTargetMachineImpl {
    std::unique_ptr<TargetLoweringObjectFile> TLOF;
    GfvSubtarget Subtarget;
    
  public:
    GfvTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
		     StringRef FS, const TargetOptions &Options,
		     std::optional<Reloc::Model> RM,
		     std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
		     bool JIT);
    const GfvSubtarget *getSubtargetImpl(const Function &) const override {
      GFV_DUMP_CYAN
      return &Subtarget;
    }
    // Pass Pipeline Configuration
    TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
    TargetLoweringObjectFile *getObjFileLowering() const override;
  };
} // end namespace llvm
 
#endif // LLVM_LIB_TARGET_GFV_GFVTARGETMACHINE_H
