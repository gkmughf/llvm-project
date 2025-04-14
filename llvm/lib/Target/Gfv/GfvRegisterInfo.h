#ifndef LLVM_LIB_TARGET_GFV_GFVREGISTERINFO_H
#define LLVM_LIB_TARGET_GFV_GFVREGISTERINFO_H
 
#define GET_REGINFO_HEADER
#include "GfvGenRegisterInfo.inc"
 
namespace llvm {
 
  struct GfvRegisterInfo : public GfvGenRegisterInfo {
  public:
    GfvRegisterInfo();
  };
 
} // end namespace llvm
 
#endif // LLVM_LIB_TARGET_GFV_GFVREGISTERINFO_H
