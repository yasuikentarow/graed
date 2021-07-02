#include "wxdraw/command/InsertNode.hpp"
#include "wxdraw/node/Node.hpp"

namespace wxdraw::command {
/**
   コンストラクタ
*/
InsertNode::InsertNode(const NodePtr& node, const NodePtr& parent, size_t index)
  : super(true, "InsertNode"), 
    node_(node), 
    parent_(parent), 
    index_(index)
{
}
/**
 */
bool InsertNode::Do() {
  Node::InsertChild(node_, parent_, index_);
  return true;
}
/**
 */
bool InsertNode::Undo() {
  parent_->removeChild(node_);
  return true;
}
}
