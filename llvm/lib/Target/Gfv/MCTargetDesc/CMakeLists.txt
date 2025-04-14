add_llvm_component_library(LLVMGfvDesc
  GfvMCTargetDesc.cpp
  GfvMCAsmInfo.cpp
  
  LINK_COMPONENTS
  MC
  Support
  GfvInfo

  ADD_TO_COMPONENT
  Gfv
 )
