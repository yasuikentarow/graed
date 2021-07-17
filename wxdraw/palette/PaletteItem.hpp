﻿#pragma once

namespace wxdraw::palette {
/**
   パレット要素基底クラス
*/
class PaletteItem {
 private:
  wxString name_;

 public:
  PaletteItem() = default;
  PaletteItem(const PaletteItem& src) = default;
  virtual ~PaletteItem() = default;

  virtual PropertyPtr createProperty(const PaletteComponentPtr& palette) = 0;

 protected:
  PropertyPtr createProperty(const char* type, 
                             const PaletteComponentPtr& palette);
};
}