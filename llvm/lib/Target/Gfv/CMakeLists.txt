add_llvm_component_group(Gfv)

set(LLVM_TARGET_DEFINITIONS Gfv.td)
 
tablegen(LLVM GfvGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM GfvGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM GfvGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM GfvGenMCPseudoLowering.inc -gen-pseudo-lowering)

add_public_tablegen_target(GfvCommonTableGen)
 

add_llvm_target(GfvCodeGen
  GfvTargetMachine.cpp
  GfvRegisterInfo.cpp
  GfvInstrInfo.cpp
  GfvSubtarget.cpp
  GfvAsmPrinter.cpp
  
  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  GfvInfo
  AsmPrinter
  
  ADD_TO_COMPONENT
  Gfv
  )
add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
