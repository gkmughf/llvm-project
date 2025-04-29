let TargetPrefix = "gfv" in {  // All intrinsics start with "llvm.gfv.".

def int_gfv_putpixel: ClangBuiltin<"gfvPutPixel">,
  Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;

def int_gfv_flush: ClangBuiltin<"gfvFlush">,
  Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;

def int_gfv_rand: ClangBuiltin<"gfvRand">,
  Intrinsic<[llvm_i32_ty], [], [IntrNoMem]>;
} // TargetPrefix = "gfv"