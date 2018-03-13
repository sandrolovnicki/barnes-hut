#ifndef UPDATE_H
#define UPDATE_H

#include <QObject>
#include "barnes-hut.h"

class UpdateBH : public QObject {
    Q_OBJECT
public:
    explicit UpdateBH(QObject* parent = 0);
    void clearTree();

    Q_INVOKABLE void nextStep();

    Q_INVOKABLE double get0x();
    Q_INVOKABLE double get0y();
    Q_INVOKABLE double get1x();
    Q_INVOKABLE double get1y();
    Q_INVOKABLE double get2x();
    Q_INVOKABLE double get2y();
    Q_INVOKABLE double get3x();
    Q_INVOKABLE double get3y();
    Q_INVOKABLE double get4x();
    Q_INVOKABLE double get4y();
    Q_INVOKABLE double get5x();
    Q_INVOKABLE double get5y();
    Q_INVOKABLE double get6x();
    Q_INVOKABLE double get6y();
    Q_INVOKABLE double get7x();
    Q_INVOKABLE double get7y();

    Q_INVOKABLE double get0m();
    Q_INVOKABLE double get1m();
    Q_INVOKABLE double get2m();
    Q_INVOKABLE double get3m();
    Q_INVOKABLE double get4m();
    Q_INVOKABLE double get5m();
    Q_INVOKABLE double get6m();
    Q_INVOKABLE double get7m();

    Q_INVOKABLE double getcx();
    Q_INVOKABLE double getcy();

    Q_INVOKABLE int getB() { return (*countB); }
    Q_INVOKABLE int getC() { return (*countC); }
private:
    Data* p0;
    Data* p1;
    Data* p2;
    Data* p3;
    Data* p4;
    Data* p5;
    Data* p6;
    Data* p7;

    quadTree* BH;

    int* countB;
    int* countC;
};

#endif // UPDATE_H
