// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef FXJS_XFA_CJX_AREA_H_
#define FXJS_XFA_CJX_AREA_H_

#include "fxjs/xfa/cjx_container.h"
#include "fxjs/xfa/jse_define.h"

class CXFA_Area;

class CJX_Area final : public CJX_Container {
 public:
  explicit CJX_Area(CXFA_Area* node);
  ~CJX_Area() override;
};

#endif  // FXJS_XFA_CJX_AREA_H_
