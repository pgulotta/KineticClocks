#pragma once
#include <QGraphicsView>

namespace twentysixapps
{
class ClocksLayoutView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ClocksLayoutView(QGraphicsScene *scene);
    void Initialize();
protected:
    virtual void resizeEvent(QResizeEvent *event) override;

private:
    explicit ClocksLayoutView(const ClocksLayoutView& rhs) = delete;
    ClocksLayoutView& operator= (const ClocksLayoutView& rhs) = delete;


};
}

