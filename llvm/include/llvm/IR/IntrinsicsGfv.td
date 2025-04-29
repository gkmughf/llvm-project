let TargetPrefix = "gfv" in {  // All intrinsics start with "llvm.gfv.".

def int_gfv_putpixel:
  Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;

def int_gfv_flush:
  Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;

def int_gfv_rand:
  Intrinsic<[llvm_i32_ty], [], [IntrNoMem]>;
} // TargetPrefix = "gfv"