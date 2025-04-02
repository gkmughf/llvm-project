add_llvm_component_group(Gfv)

add_llvm_target(GfvCodeGen
  GfvTargetMachine.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  GfvInfo

  ADD_TO_COMPONENT
  Gfv
  )
add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
