#pragma once
#include "utils/colorgenerator.hpp"
#include "model\clocksymbols.hpp"
#include "model\symbol.hpp"
#include "model\clocktime.hpp"
#include "model/display.hpp"
#include "view\clockslayoutview.hpp"
#include "view\clockgraphicsitem.hpp"
#include "utils/utils.hpp"
#include <QObject>
#include <QRectF>


class QTimer;
namespace twentysixapps
{
class ClockTime;
class ClockGraphicsItem;
class ClocksLayoutViewManager : public QObject
{
    Q_OBJECT
public:
    static constexpr int GridsDepth = 3 ;
    static constexpr  int DisplayGridIndex= 1;

    ClocksLayoutViewManager(QObject*  parent,   const QScreen* primaryScreen,     DisplayAdapter* displayAdapter);

    ~ClocksLayoutViewManager()
    {
        Utils::destructorMsg(this);
    }


signals:


private slots:
    void rotateClocksTimerChanged();
    void updateDisplayTimerChanged();
    void onOrientationChanged(Qt::ScreenOrientation newOrientation);

private:
    typedef std::array<ClockGraphicsItem*, GridsDepth  *   ClockTime::SymbolsCount  * Symbol::ItemsPerSymbolCount*Clock::AnglesPerClock> ClockItems;
    typedef ClockItems::const_iterator  ClockItemsCIterator;
    typedef ClockItems::iterator  ClockItemsIterator;

    static constexpr int  ClockLayoutWidth= 500;
    static constexpr int ClockLayoutHeight = 360;

    const QScreen& mPrimaryScreen;
    DisplayAdapter&  mDisplayAdapter;
    ClocksLayoutView mClocksLayoutView;
    QTimer& mRotateClocksTimer;
    QTimer& mUpdateDisplayTimer;
    ClockSymbols mClockSymbols;
    ClockItems mClockGraphicsItems;
    QString mDisplayedSymbols;
    ColorGenerator mColorGenerator;

    void changePenColor();
    void displaySymbols() ;
    void createSceneItems();
    void invalidatelClocks();
    void invalidatelClocks(ClockItemsIterator start, ClockItemsIterator end,  int angleDelta=1 , int indexIncrement=1);
    QRectF getScreenRect() const;
    QRectF getScreenRect(Qt::ScreenOrientation orientation) const;

    QColor mLineColor  = Qt::GlobalColor::white;
    QColor mBackColor  = Qt::GlobalColor::black;

    explicit ClocksLayoutViewManager(const ClocksLayoutViewManager& rhs) = delete;
    ClocksLayoutViewManager& operator= (const ClocksLayoutViewManager& rhs) = delete;
    ClocksLayoutViewManager(ClocksLayoutViewManager&&) =delete;
    ClocksLayoutViewManager& operator=(ClocksLayoutViewManager&&) =delete;



};
}
