﻿#pragma once

#include "wxdraw/component/Component.hpp"

namespace wxdraw::component {
/**
   カラーパレットコンポーネント
*/
class PaletteComponent
  : public Component<PaletteComponent>
{
  using super = Component<PaletteComponent>;

 public:
  static const char* TYPE;

 private:
  std::vector<PenPtr> pens_;
  std::vector<BrushPtr> brushes_;
  std::vector<GradientPtr> gradients_;
  std::vector<ColorPtr> colors_;

 public:
  PaletteComponent(const NodePtr& node);
  PaletteComponent(const PaletteComponent& src, const NodePtr& node);
  ~PaletteComponent() override = default;

  WXDRAW_ACCESSOR(Pens, pens_);
  WXDRAW_ACCESSOR(Brushes, brushes_);
  WXDRAW_ACCESSOR(Gradients, gradients_);
  WXDRAW_ACCESSOR(Colors, colors_);
};
}
