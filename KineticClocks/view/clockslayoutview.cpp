#include "clockslayoutview.hpp"
#include "clockgraphicsitem.hpp"
#include "model\clock.hpp"
#include "model\symbol.hpp"
#include "model\clocksymbols.hpp"
#include <QGraphicsItem>
#include <QDebug>

namespace twentysixapps
{

ClocksLayoutView::ClocksLayoutView(QWidget *parent):QGraphicsView(parent)
{

}

void ClocksLayoutView::resizeEvent(QResizeEvent *event)
{
    fitInView(scene()->sceneRect());
    QGraphicsView::resizeEvent(event);
}


}
