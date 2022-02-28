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
    void ChangeOneLineCountersHeight(int value);


private:
    int count = 0;
    const int width = 30;
    const int height = 22;
    int multiplier = 0;

    void AddLine();
    void RemoveLine();
    QLabel *CreateLabel();

    QList< QLabel *> lineNumber;

    QWidget *parent = nullptr;
    QVBoxLayout *vlayout;

};

#endif // LINECOUNTER_H
