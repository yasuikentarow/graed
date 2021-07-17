﻿#pragma once

#include "wxdraw/gui/PaletteList.hpp"

namespace wxdraw::gui {
/**
 */
class GradientStopList
  : public PaletteList<GradientStop>
{
  using super = PaletteList<GradientStop>;

 private:
  GradientPtr gradient_;

 public:
  GradientStopList(wxWindow* parent, Palette* palette);
  ~GradientStopList() override = default;

  void setGradient(const GradientPtr& gradient);

 protected:
  std::vector<GradientStopPtr>& getItems() const override;
  void onUpdate(const GradientStopPtr& gradient, wxListItem& item) override;
};
}
