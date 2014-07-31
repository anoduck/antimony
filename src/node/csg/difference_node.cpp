#include "node/csg/difference_node.h"
#include "node/manager.h"

#include "datum/float_datum.h"
#include "datum/function_datum.h"
#include "datum/shape_datum.h"

DifferenceNode::DifferenceNode(QObject* parent)
    : Node(parent)
{
    // Nothing to do here
}

DifferenceNode::DifferenceNode(float x, float y, float z, float scale,
                     QObject* parent)
    : Node(NodeManager::manager()->getName("u"), parent)
{
    new FloatDatum("_x", QString::number(x), this);
    new FloatDatum("_y", QString::number(y), this);
    new FloatDatum("_z", QString::number(z), this);
    Q_UNUSED(scale);
    new ShapeDatum("a", this);
    new ShapeDatum("b", this);
    new ShapeFunctionDatum("shape", this, "difference", {"a", "b"});
}
