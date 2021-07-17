﻿#pragma once

#include "wxdraw/gui/PaletteList.hpp"

namespace wxdraw::gui {
/**
 */
class ColorList
  : public PaletteList<Color>
{
  using super = PaletteList<Color>;

 private:
  GradientPtr gradient_;

 public:
  ColorList(wxWindow* parent, Palette* palette);
  ~ColorList() override = default;

  void setGradient(const GradientPtr& gradient);

 protected:
  std::vector<ColorPtr>& getItems() const override;
  void onUpdate() override;

 private:
  void updateImageList();

  static wxBitmap CreateBitmap(const Color& color);
};
}
