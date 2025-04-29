#include "Gfv.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"

using namespace clang;
using namespace clang::targets;

void GfvTargetInfo::getTargetDefines(const LangOptions &Opts,
                                     MacroBuilder &Builder) const {
  Builder.defineMacro("__gfv__");
}

ArrayRef<Builtin::Info> GfvTargetInfo::getTargetBuiltins() const {
  return std::nullopt;
}
