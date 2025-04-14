#ifndef LLVM_LIB_TARGET_GFV_MCTARGETDESC_GFVMCASMINFO_H
#define LLVM_LIB_TARGET_GFV_MCTARGETDESC_GFVMCASMINFO_H
 
#include "llvm/MC/MCAsmInfoELF.h"
 
namespace llvm {
 
  class Triple;
 
  class GfvELFMCAsmInfo : public MCAsmInfoELF {
  public:
    explicit GfvELFMCAsmInfo(const Triple &TheTriple);
  };
 
} // end namespace llvm
 
#endif // LLVM_LIB_TARGET_GFV_MCTARGETDESC_GFVMCASMINFO_H
