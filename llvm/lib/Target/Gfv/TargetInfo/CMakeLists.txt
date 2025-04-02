add_llvm_component_library(LLVMGfvInfo
 GfvTargetInfo.cpp
 
 LINK_COMPONENTS
 MC
 Support
 
 ADD_TO_COMPONENT
 Gfv
 )
