#include "wxdraw/component/LayoutComponent.hpp"
#include "wxdraw/component/RectangleComponent.hpp"
#include "wxdraw/gui/Renderer.hpp"
#include "wxdraw/node/Node.hpp"

namespace wxdraw::component {
const char* RectangleComponent::TYPE = "Rectangle";
/**
   コンストラクタ
*/
RectangleComponent::RectangleComponent(Node& node)
  : super(TYPE, node), 
    round_(0.0)
{
  setup();
}
/**
   コピーコンストラクタ
*/
RectangleComponent::RectangleComponent(const RectangleComponent& src, Node& node)
  : super(src, node), 
    round_(src.round_)
{
  setup();
}
/**
 */
ComponentPtr RectangleComponent::clone(Node& node) const {
  return std::make_shared<RectangleComponent>(*this, node);
}
/**
 */
void RectangleComponent::onRender(Renderer& renderer) {
  auto& context = renderer.getContext();
  if(auto layout = getNode().getComponent<LayoutComponent>()) {
    auto& rect = layout->getRect();
    if(round_ <= 0.0) {
      context.DrawRectangle(rect.pos.x, rect.pos.y, rect.size.x, rect.size.y);
    }
    else {
      context.DrawRoundedRectangle(rect.pos.x, rect.pos.y, rect.size.x, rect.size.y, round_);
    }
  }
}
/**
 */
void RectangleComponent::setup() {
  appendMember("Round", round_);
}
}
