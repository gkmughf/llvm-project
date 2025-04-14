add_llvm_component_group(Gfv)

set(LLVM_TARGET_DEFINITIONS Gfv.td)
 
tablegen(LLVM GfvGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM GfvGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM GfvGenSubtargetInfo.inc -gen-subtarget)

add_public_tablegen_target(GfvCommonTableGen)
 

add_llvm_target(GfvCodeGen
  GfvTargetMachine.cpp
  GfvRegisterInfo.cpp
  GfvInstrInfo.cpp
  GfvSubtarget.cpp
  
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
