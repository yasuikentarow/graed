﻿#pragma once

#include "wxdraw/palette/PaletteItem.hpp"

namespace wxdraw::palette {
/**
 */
class Brush
  : public PaletteItem
{
  using super = PaletteItem;

 public:
  static const char* TYPE;

 private:
  wxString name_;
  GradientPtr gradient_;

  static int Serial;

 public:
  Brush();
  Brush(const Brush& src) = default;
  ~Brush() override = default;

  WXDRAW_GETTER(Name, name_);
  WXDRAW_GETTER(Gradient, gradient_);

  void onCreate(const PaletteComponentPtr& palette) override;
  PropertyPtr createProperty(const PaletteComponentPtr& palette) override;
};
}
