// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_LIB_UI_TEXT_PARAGRAPH_BUILDER_STUB_H_
#define FLUTTER_LIB_UI_TEXT_PARAGRAPH_BUILDER_STUB_H_

#include "flutter/lib/ui/text/paragraph_stub.h"
#include "lib/tonic/dart_wrappable.h"
#include "lib/tonic/typed_data/int32_list.h"

namespace tonic {
class DartLibraryNatives;
}  // namespace tonic

namespace blink {

class ParagraphBuilder : public ftl::RefCountedThreadSafe<ParagraphBuilder>,
                         public tonic::DartWrappable {
  DEFINE_WRAPPERTYPEINFO();
  FRIEND_MAKE_REF_COUNTED(ParagraphBuilder);

 public:
  static ftl::RefPtr<ParagraphBuilder> create() {
    return ftl::MakeRefCounted<ParagraphBuilder>();
  }

  ~ParagraphBuilder() override;

  void pushStyle(tonic::Int32List& encoded,
                 const std::string& fontFamily,
                 double fontSize,
                 double letterSpacing,
                 double wordSpacing,
                 double height);
  void pop();

  void addText(const std::string& text);

  ftl::RefPtr<Paragraph> build(tonic::Int32List& encoded,
                               const std::string& fontFamily,
                               double fontSize,
                               double lineHeight);

  static void RegisterNatives(tonic::DartLibraryNatives* natives);

 private:
  ParagraphBuilder();
};

}  // namespace blink

#endif  // FLUTTER_LIB_UI_TEXT_PARAGRAPH_BUILDER_STUB_H_