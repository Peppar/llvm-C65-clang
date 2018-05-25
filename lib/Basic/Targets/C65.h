//===--- C65.h - Declare C65 target feature support -----------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares Sparc TargetInfo objects.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_LIB_BASIC_TARGETS_C65_H
#define LLVM_CLANG_LIB_BASIC_TARGETS_C65_H
#include "clang/Basic/TargetBuiltins.h"
#include "clang/Basic/TargetInfo.h"
#include "clang/Basic/TargetOptions.h"
#include "llvm/ADT/Triple.h"
#include "llvm/Support/Compiler.h"
namespace clang {
namespace targets {

// static const unsigned C65AddrSpaceMap[] = {
//   1, // Far addresses (opencl_global)
//   0, // opencl_local
//   0, // opencl_constant
//   0, // cuda_device
//   0, // cuda_constant
//   0  // cuda_shared
// };

// If you edit the description strings, make sure you update
// getPointerWidthV().

class LLVM_LIBRARY_VISIBILITY C65TargetInfo : public TargetInfo {
  static const TargetInfo::GCCRegAlias GCCRegAliases[];
  static const char *const GCCRegNames[];

  enum CPUKind {
    CK_NONE,
    CK_6502,
    CK_65C02,
    CK_65802,
    CK_65816
  } CPU;

public:
  C65TargetInfo(const llvm::Triple &Triple, const TargetOptions &);

  uint64_t getPointerWidthV(unsigned AddrSpace) const override;

  void getTargetDefines(const LangOptions &Opts,
                        MacroBuilder &Builder) const override;

  bool hasFeature(StringRef Feature) const override;

  ArrayRef<Builtin::Info> getTargetBuiltins() const override;

  const char *getClobbers() const override;

  ArrayRef<TargetInfo::GCCRegAlias> getGCCRegAliases() const override;

  ArrayRef<const char *> getGCCRegNames() const override;

  bool validateAsmConstraint(const char *&Name,
                             TargetInfo::ConstraintInfo &info) const override;

  BuiltinVaListKind getBuiltinVaListKind() const override;

  bool setCPU(const std::string &Name) override;
};
} // namespace targets
} // namespace clang
#endif // LLVM_CLANG_LIB_BASIC_TARGETS_C65_H
