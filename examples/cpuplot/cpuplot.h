/*****************************************************************************
 * Qwt Examples - Copyright (C) 2002 Uwe Rathmann
 * This file may be used under the terms of the 3-clause BSD License
 *****************************************************************************/

#pragma once

#include "cpustat.h"
#include <QwtPlot>

#define HISTORY 60 // seconds

class QwtPlotCurve;

class CpuPlot : public QwtPlot
{
    Q_OBJECT
  public:
    enum CpuData
    {
        User,
        System,
        Total,
        Idle,

        NCpuData
    };

    CpuPlot( QWidget* = 0 );
    const QwtPlotCurve* cpuCurve( int id ) const
    {
        return data[id].curve;
    }

  protected:
    void timerEvent( QTimerEvent* ) QWT_OVERRIDE;

  private Q_SLOTS:
    void legendChecked( const QVariant&, bool on );

  private:
    void showCurve( QwtPlotItem*, bool on );

    struct
    {
        QwtPlotCurve* curve;
        double data[HISTORY];
    } data[NCpuData];

    double timeData[HISTORY];

    int dataCount;
    CpuStat cpuStat;
};
