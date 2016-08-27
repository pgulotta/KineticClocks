#include "startup.hpp"
#include "view/clockslayoutview.hpp"
#include <QGraphicsScene>


namespace twentysixapps
{
Startup::Startup(QObject *parent) :
    QObject(parent),
    mClocksLayoutView(new ClocksLayoutView(new QGraphicsScene{0, 0, 1000,1000 }))
{
}

void Startup::show() const
{
  //  mClocksLayoutView.resize(width, height);
  //  mClocksLayoutView.show();
}

Startup::~Startup()
{
  delete mClocksLayoutView;
}

}
