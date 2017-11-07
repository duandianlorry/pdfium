// Copyright 2016 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cxfa_binditemsdata.h"

#include "xfa/fxfa/parser/cxfa_node.h"

CXFA_BindItemsData::CXFA_BindItemsData(CXFA_Node* pNode) : CXFA_Data(pNode) {}

void CXFA_BindItemsData::GetLabelRef(WideStringView& wsLabelRef) {
  m_pNode->JSNode()->TryCData(XFA_ATTRIBUTE_LabelRef, wsLabelRef, true);
}

void CXFA_BindItemsData::GetValueRef(WideStringView& wsValueRef) {
  m_pNode->JSNode()->TryCData(XFA_ATTRIBUTE_ValueRef, wsValueRef, true);
}

void CXFA_BindItemsData::GetRef(WideStringView& wsRef) {
  m_pNode->JSNode()->TryCData(XFA_ATTRIBUTE_Ref, wsRef, true);
}

bool CXFA_BindItemsData::SetConnection(const WideString& wsConnection) {
  return m_pNode->JSNode()->SetCData(XFA_ATTRIBUTE_Connection, wsConnection,
                                     false, false);
}