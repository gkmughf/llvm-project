add_llvm_component_library(LLVMGfvDesc
  GfvMCTargetDesc.cpp
  GfvMCAsmInfo.cpp
  GfvInstPrinter.cpp
  GfvMCCodeEmitter.cpp
  GfvAsmBackend.cpp
  
  LINK_COMPONENTS
  MC
  Support
  GfvInfo

  ADD_TO_COMPONENT
  Gfv
 )
