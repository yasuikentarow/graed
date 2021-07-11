#include "wxdraw/component/LayerComponent.hpp"
#include "wxdraw/gui/Renderer.hpp"

namespace wxdraw::component {
/**
   コンストラクタ
*/
LayerComponent::LayerComponent(Node& node)
  : super("LayerComponent", node), 
    opacity_(1.0), 
    clip_(false)
{
  appendMember("Opacity", opacity_);
  appendMember("Clip", clip_);
}
/**
 */
void LayerComponent::onBeginRender(Renderer& renderer) {
  auto& context = renderer.getContext();
  context.PushState();
  context.BeginLayer(opacity_);
}
/**
 */
void LayerComponent::onEndRender(Renderer& renderer) {
  auto& context = renderer.getContext();
  context.EndLayer();
  context.PopState();
}
}
