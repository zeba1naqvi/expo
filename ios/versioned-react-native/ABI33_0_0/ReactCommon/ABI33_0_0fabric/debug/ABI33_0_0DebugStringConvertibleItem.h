/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <string>

#include <ReactABI33_0_0/debug/DebugStringConvertible.h>

namespace facebook {
namespace ReactABI33_0_0 {

#if RN_DEBUG_STRING_CONVERTIBLE

// Trivial implementation of `DebugStringConvertible` abstract class
// with a stored output; useful for assembling `DebugStringConvertible` values
// in custom implementations of `getDebugChildren` and `getDebugProps`.
class DebugStringConvertibleItem : public DebugStringConvertible {
 public:
  DebugStringConvertibleItem() = default;
  DebugStringConvertibleItem(const DebugStringConvertibleItem &item) = default;

  DebugStringConvertibleItem(
      const std::string &name = "",
      const std::string &value = "",
      const SharedDebugStringConvertibleList &props = {},
      const SharedDebugStringConvertibleList &children = {});

  std::string getDebugName() const override;
  std::string getDebugValue() const override;
  SharedDebugStringConvertibleList getDebugChildren() const override;
  SharedDebugStringConvertibleList getDebugProps() const override;

 private:
  std::string name_;
  std::string value_;
  SharedDebugStringConvertibleList props_;
  SharedDebugStringConvertibleList children_;
};

#endif

} // namespace ReactABI33_0_0
} // namespace facebook
