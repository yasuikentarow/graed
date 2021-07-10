#include "wxdraw/property/Property.hpp"

namespace wxdraw::property {
/**
   コンストラクタ
*/
Property::Property(const std::string& name)
  : super(name)
{
}
/**
 */
void Property::appendMember(const std::string& name, glm::dvec2& value) {
  appendMember(name + ".x", value.x);
  appendMember(name + ".y", value.y);
}
}
