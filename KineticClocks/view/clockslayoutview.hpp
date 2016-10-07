#pragma once
#include <QGraphicsView>
#include "utils/utils.hpp"


namespace twentysixapps
{
class ClocksLayoutView : public QGraphicsView
{
Q_OBJECT

public:
    explicit ClocksLayoutView(QWidget *parent = Q_NULLPTR) : QGraphicsView(parent){
    }
    ~ClocksLayoutView()
    {
        Utils::destructorMsg(" ClocksLayoutView" );
    }

    explicit ClocksLayoutView(const ClocksLayoutView& rhs) = delete;
    ClocksLayoutView& operator= (const ClocksLayoutView& rhs) = delete;
    ClocksLayoutView(ClocksLayoutView&&) =delete;
    ClocksLayoutView& operator=(ClocksLayoutView&&) =delete;

protected:
    virtual void resizeEvent(QResizeEvent *event) override
    {
        fitInView(scene()->sceneRect());
        QGraphicsView::resizeEvent(event);
    }

private:



};
}
