#ifndef LLVM_LIB_TARGET_Gfv_Gfv_H
#define LLVM_LIB_TARGET_Gfv_Gfv_H

#include "MCTargetDesc/GfvMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"

#define GFV_DUMP(Color)                                                        \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }
// #define GFV_DUMP(Color) {}

#define GFV_DUMP_RED GFV_DUMP(llvm::raw_ostream::RED)
#define GFV_DUMP_GREEN GFV_DUMP(llvm::raw_ostream::GREEN)
#define GFV_DUMP_YELLOW GFV_DUMP(llvm::raw_ostream::YELLOW)
#define GFV_DUMP_CYAN GFV_DUMP(llvm::raw_ostream::CYAN)
#define GFV_DUMP_MAGENTA GFV_DUMP(llvm::raw_ostream::MAGENTA)
#define GFV_DUMP_WHITE GFV_DUMP(llvm::raw_ostream::WHITE)

#endif // LLVM_LIB_TARGET_Gfv_Gfv_H
