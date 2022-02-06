#ifndef LINECOUNTER_H
#define LINECOUNTER_H

#include <QLabel>
#include <QWidget>
#include <QList>
#include <QVBoxLayout>
#include <QSpacerItem>

#include "style_sheets.h"

class LineCounter
{

public:
    LineCounter();
    LineCounter(QVBoxLayout *_vlayout);
   ~LineCounter();
    void AddMultipleLines(int lines);
    void LineNumbersChanged(int numbers);


private:
    int count = 0;
    int y = 0;

    void AddLine();
    void RemoveLine();
    QLabel* CreateLabel();

    QList< QLabel *> lineNumber;

    QWidget *parent = nullptr;
    QVBoxLayout *vlayout;

};

#endif // LINECOUNTER_H
