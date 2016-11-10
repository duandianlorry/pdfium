// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef XFA_FWL_CORE_CFWL_COMBOBOX_H_
#define XFA_FWL_CORE_CFWL_COMBOBOX_H_

#include <memory>
#include <vector>

#include "xfa/fwl/core/cfwl_widget.h"
#include "xfa/fwl/core/ifwl_combobox.h"

class CFWL_ComboBox : public CFWL_Widget, public IFWL_ComboBoxDP {
 public:
  CFWL_ComboBox(const IFWL_App*);
  ~CFWL_ComboBox() override;

  void Initialize();

  int32_t AddString(const CFX_WideStringC& wsText);
  int32_t AddString(const CFX_WideStringC& wsText, CFX_DIBitmap* pIcon);
  bool RemoveAt(int32_t iIndex);  // Returns false iff |iIndex| out of range.
  void RemoveAll();
  int32_t CountItems();
  FWL_Error GetTextByIndex(int32_t iIndex, CFX_WideString& wsText);
  int32_t GetCurSel();
  FWL_Error SetCurSel(int32_t iSel);
  void SetEditText(const CFX_WideString& wsText);
  int32_t GetEditTextLength() const;
  FWL_Error GetEditText(CFX_WideString& wsText,
                        int32_t nStart = 0,
                        int32_t nCount = -1) const;
  FWL_Error SetEditSelRange(int32_t nStart, int32_t nCount = -1);
  int32_t GetEditSelRange(int32_t nIndex, int32_t& nStart);
  int32_t GetEditLimit();
  FWL_Error SetEditLimit(int32_t nLimit);
  FWL_Error EditDoClipboard(int32_t iCmd);
  bool EditRedo(const IFDE_TxtEdtDoRecord* pRecord);
  bool EditUndo(const IFDE_TxtEdtDoRecord* pRecord);
  FWL_Error SetMaxListHeight(FX_FLOAT fMaxHeight);
  FWL_Error SetItemData(int32_t iIndex, void* pData);
  void* GetItemData(int32_t iIndex);
  void SetListTheme(IFWL_ThemeProvider* pTheme);
  bool AfterFocusShowDropList();
  FWL_Error OpenDropDownList(bool bActivate);

  bool EditCanUndo();
  bool EditCanRedo();
  bool EditUndo();
  bool EditRedo();
  bool EditCanCopy();
  bool EditCanCut();
  bool EditCanSelectAll();
  bool EditCopy(CFX_WideString& wsCopy);
  bool EditCut(CFX_WideString& wsCut);
  bool EditPaste(const CFX_WideString& wsPaste);
  bool EditSelectAll();
  bool EditDelete();
  bool EditDeSelect();
  FWL_Error GetBBox(CFX_RectF& rect);
  void EditModifyStylesEx(uint32_t dwStylesExAdded, uint32_t dwStylesExRemoved);

  // IFWL_DataProvider
  FWL_Error GetCaption(IFWL_Widget* pWidget,
                       CFX_WideString& wsCaption) override;

  // IFWL_ListBoxDP
  int32_t CountItems(const IFWL_Widget* pWidget) override;
  CFWL_ListItem* GetItem(const IFWL_Widget* pWidget, int32_t nIndex) override;
  int32_t GetItemIndex(IFWL_Widget* pWidget, CFWL_ListItem* pItem) override;
  bool SetItemIndex(IFWL_Widget* pWidget,
                    CFWL_ListItem* pItem,
                    int32_t nIndex) override;

  uint32_t GetItemStyles(IFWL_Widget* pWidget, CFWL_ListItem* pItem) override;
  void GetItemText(IFWL_Widget* pWidget,
                   CFWL_ListItem* pItem,
                   CFX_WideString& wsText) override;
  void GetItemRect(IFWL_Widget* pWidget,
                   CFWL_ListItem* pItem,
                   CFX_RectF& rtItem) override;
  void* GetItemData(IFWL_Widget* pWidget, CFWL_ListItem* pItem) override;
  void SetItemStyles(IFWL_Widget* pWidget,
                     CFWL_ListItem* pItem,
                     uint32_t dwStyle) override;
  void SetItemText(IFWL_Widget* pWidget,
                   CFWL_ListItem* pItem,
                   const FX_WCHAR* pszText) override;
  void SetItemRect(IFWL_Widget* pWidget,
                   CFWL_ListItem* pItem,
                   const CFX_RectF& rtItem) override;
  FX_FLOAT GetItemHeight(IFWL_Widget* pWidget) override;
  CFX_DIBitmap* GetItemIcon(IFWL_Widget* pWidget,
                            CFWL_ListItem* pItem) override;
  void GetItemCheckRect(IFWL_Widget* pWidget,
                        CFWL_ListItem* pItem,
                        CFX_RectF& rtCheck) override;
  void SetItemCheckRect(IFWL_Widget* pWidget,
                        CFWL_ListItem* pItem,
                        const CFX_RectF& rtCheck) override;
  uint32_t GetItemCheckState(IFWL_Widget* pWidget,
                             CFWL_ListItem* pItem) override;
  void SetItemCheckState(IFWL_Widget* pWidget,
                         CFWL_ListItem* pItem,
                         uint32_t dwCheckState) override;

  // IFWL_ComboBoxDP
  FX_FLOAT GetListHeight(IFWL_Widget* pWidget) override;

 private:
  std::vector<std::unique_ptr<CFWL_ListItem>> m_ItemArray;
  FX_FLOAT m_fMaxListHeight;
  FX_FLOAT m_fItemHeight;
};

#endif  // XFA_FWL_CORE_CFWL_COMBOBOX_H_
