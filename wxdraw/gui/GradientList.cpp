#include "wxdraw/component/PaletteComponent.hpp"
#include "wxdraw/gui/GradientList.hpp"
#include "wxdraw/gui/Palette.hpp"
#include "wxdraw/palette/Gradient.hpp"

namespace wxdraw::gui {
/**
 */
GradientList::GradientList(wxWindow* parent, Palette* palette)
  : super(parent, palette)
{
  getList()->AppendColumn("Gradient");
}
/**
 */
std::vector<GradientPtr>& GradientList::getItems() const {
  return getPaletteComponent()->getGradients();
}
/**
 */
void GradientList::onSelectItem(const PaletteItemPtr& item) {
  super::onSelectItem(item);
  auto gradient = std::static_pointer_cast<Gradient>(item);
  getPalette()->setGradient(gradient);
}
/**
 */
void GradientList::onUpdate(const GradientPtr& gradient, wxListItem& item) {
  item.SetText(gradient->getName());
  item.SetImage(appendGradientImage(gradient));
  super::onUpdate(gradient, item);
}
}
