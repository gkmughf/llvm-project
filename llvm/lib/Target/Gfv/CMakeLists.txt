add_llvm_component_group(Gfv)

set(LLVM_TARGET_DEFINITIONS Gfv.td)
 
tablegen(LLVM GfvGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM GfvGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM GfvGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM GfvGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM GfvGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM GfvGenCallingConv.inc -gen-callingconv)
tablegen(LLVM GfvGenAsmWriter.inc -gen-asm-writer)

add_public_tablegen_target(GfvCommonTableGen)
 

add_llvm_target(GfvCodeGen
  GfvTargetMachine.cpp
  GfvRegisterInfo.cpp
  GfvInstrInfo.cpp
  GfvSubtarget.cpp
  GfvAsmPrinter.cpp
  GfvISelDagToDag.cpp
  GfvISelLowering.cpp
  
  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  GfvInfo
  AsmPrinter
  SelectionDAG
  
  ADD_TO_COMPONENT
  Gfv
  )
add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
