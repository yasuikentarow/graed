#include "wxdraw/component/ContainerComponent.hpp"
#include "wxdraw/file/XmlExporter.hpp"
#include "wxdraw/node/Node.hpp"
#include "wxdraw/property/Member.hpp"

namespace wxdraw::file {
/**
   コンストラクタ
*/
XmlExporter::XmlExporter(const NodePtr& node, const wxFileName& fileName)
  : super(node), 
    fileName_(fileName)
{
  document_.SetRoot(parse(node));
}
/**
   出力
*/
bool XmlExporter::save() {
  wxFileOutputStream output(fileName_.GetFullPath());
  return document_.Save(output);
}
/**
 */
wxString XmlExporter::ToString(int value) {
  return wxNumberFormatter::ToString(static_cast<long>(value), wxNumberFormatter::Style_None);
}
/**
 */
wxString XmlExporter::ToString(double value) {
  return wxNumberFormatter::ToString(value, 16, wxNumberFormatter::Style_NoTrailingZeroes);
}
/**
 */
wxString XmlExporter::ToString(bool value) {
  return ToString(static_cast<int>(value));
}
/**
 */
wxXmlNode* XmlExporter::parse(const NodePtr& node) {
  auto xml = parse(*node);
  for(auto& component : node->getComponents()) {
    auto componentXml = parse(*component);
    xml->AddChild(componentXml);
    if(auto container = std::dynamic_pointer_cast<ContainerComponent>(component)) {
      for(auto& child : container->getChildren()) {
        componentXml->AddChild(parse(child));
      }
    }
  }
  return xml;
}
/**
 */
wxXmlNode* XmlExporter::parse(const Property& property) {
  auto xml = new wxXmlNode(wxXML_ELEMENT_NODE, property.getName());
  for(auto& member : property.getMembers()) {
    xml->AddAttribute(member->getName(), getValue(member));
  }
  return xml;
}
/**
 */
wxString XmlExporter::getValue(const MemberBasePtr& member) {
  if(auto m = Member<int>::As(member)) {
    return ToString(m->getValue());
  }
  else if(auto m = Member<double>::As(member)) {
    return ToString(m->getValue());
  }
  else if(auto m = Member<bool>::As(member)) {
    return ToString(m->getValue());
  }
  else if(auto m = Member<wxString>::As(member)) {
    return m->getValue();
  }
  else if(auto m = Member<wxColour>::As(member)) {
    return m->getValue().GetAsString();
  }
  else if(auto m = Member<wxFileName>::As(member)) {
    auto fileName(m->getValue());
    fileName.MakeRelativeTo(fileName_.GetPath());
    return fileName.GetFullPath();
  }
  wxLogError("illegal member");
  return wxEmptyString;
}
}
