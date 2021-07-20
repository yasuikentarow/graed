﻿#pragma once

#include "wxdraw/property/Member.hpp"

namespace wxdraw::property {
/**
   プロパティ
*/
class Property {
 private:
  ObjectPtr object_;
  std::vector<MemberBasePtr> members_;

 public:
  Property(const ObjectPtr& object);
  virtual ~Property() = default;

  WXDRAW_GETTER(Object, object_);
  WXDRAW_GETTER(Members, members_);

  const wxString& getName() const;

  void appendMember(const MemberBasePtr& member);
  void appendMember(const std::string& name, glm::ivec2& value);
  void appendMember(const std::string& name, glm::dvec2& value);

  template <class T>
  Member<T>& appendMember(const std::string& name, T& value) {
    auto member = std::make_shared<Member<T>>(name, value);
    appendMember(member);
    return *member;
  }
};
}
