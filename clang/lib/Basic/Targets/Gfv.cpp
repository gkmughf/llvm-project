#include "Gfv.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"
#include "clang/Basic/TargetBuiltins.h"

using namespace clang;
using namespace clang::targets;

static constexpr Builtin::Info BuiltinInfo[] = {
#define BUILTIN(ID, TYPE, ATTRS)					\
  {#ID, TYPE, ATTRS, nullptr, HeaderDesc::NO_HEADER, ALL_LANGUAGES},
#include "clang/Basic/BuiltinsGfv.def"
};

void GfvTargetInfo::getTargetDefines(const LangOptions &Opts,
                                     MacroBuilder &Builder) const {
  Builder.defineMacro("__gfv__");
}

ArrayRef<Builtin::Info> GfvTargetInfo::getTargetBuiltins() const {
  return llvm::ArrayRef(BuiltinInfo,
			clang::Gfv::LastTSBuiltin - Builtin::FirstTSBuiltin);
}
