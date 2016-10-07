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
#include <QFutureWatcher>



class QTimer;

namespace twentysixapps
{
class ClockTime;
class ClockGraphicsItem;

class ClocksViewManager : public QObject
{
Q_OBJECT

public:
    static constexpr int GridsDepth = 3;
    static constexpr int DisplayGridIndex= 1;

    ClocksViewManager(QApplication*  app,    DisplayAdapter* displayAdapter);

    ~ClocksViewManager()
    {
        Utils::destructorMsg(this);
    }

    explicit ClocksViewManager(const ClocksViewManager& rhs) = delete;
    ClocksViewManager& operator= (const ClocksViewManager& rhs) = delete;
    ClocksViewManager(ClocksViewManager&&) =delete;
    ClocksViewManager& operator=(ClocksViewManager&&) =delete;

signals:

private slots:
    void rotateClocksTimerChanged();
    void updateDisplayTimerChanged();
    void onOrientationChanged(Qt::ScreenOrientation newOrientation);
    void restartRotateClocksTimer();

private:
    using ClockItems = std::array<ClockGraphicsItem*, GridsDepth  *   ClockTime::SymbolsCount  * Symbol::ItemsPerSymbolCount*Clock::AnglesPerClock>;
    using ClockItemsCIterator = ClockItems::const_iterator;
    using ClockItemsIterator = ClockItems::iterator;

    static constexpr int ClockLayoutWidth= 500;
    static constexpr int ClockLayoutHeight = 360;

    const QScreen& mPrimaryScreen;
    DisplayAdapter&  mDisplayAdapter;
    ClocksLayoutView mClocksLayoutView;
    QTimer& mRotateClocksTimer;
    QTimer& mUpdateDisplayTimer;
    QFutureWatcher<void>& mUpdateClocksWatcher;

    ClockSymbols mClockSymbols;
    ClockItems mClockGraphicsItems;
    QString mDisplayedSymbols;
    ColorGenerator mColorGenerator;

    void updateClocks();

    void displaySymbols();
    void createSceneItems();
    void invalidatelClocks();
    QRectF getScreenRect() const;
    QRectF getScreenRect(Qt::ScreenOrientation orientation) const;
    QColor mLineColor = Qt::GlobalColor::white;
    QColor mBackColor  = Qt::GlobalColor::black;






};
}
