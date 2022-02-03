#ifndef LINECOUNTER_H
#define LINECOUNTER_H

#include <QLabel>
#include <QWidget>
#include <QList>

#include "style_sheets.h"

class LineCounter
{

public:
    LineCounter();
    LineCounter(QWidget *_parent);
   ~LineCounter();
    void AddMultipleLines(int lines);
    void LineNumbersChanged(int numbers);


private:
    int count = 0;
    int y = 0;

    void AddLine();
    void RemoveLine();

    QList< QLabel *> lineNumber;

    QWidget *parent = nullptr;

};

#endif // LINECOUNTER_H
