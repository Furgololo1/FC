#include "linecounter.h"

LineCounter::LineCounter()
{
    AddLine();
}

LineCounter::LineCounter(QVBoxLayout *_vlayout): vlayout(_vlayout)
{
    AddLine();
}

LineCounter::~LineCounter()
{

}

void LineCounter::AddLine()
{

        vlayout->insertWidget(count-1, CreateLabel());
}

void LineCounter::RemoveLine()
{
    count--;
    vlayout->removeWidget(lineNumber.last());
    delete lineNumber.last();
    lineNumber.removeLast();
}

QLabel *LineCounter::CreateLabel()
{
    QLabel *temp = new QLabel();
    temp->setAlignment(Qt::AlignCenter);
    temp->setMinimumSize(width, height);
    temp->setStyleSheet(StyleSheetsGUI::lineNumberStyle);
    count++;
    temp->setText(QString::number(count));
    lineNumber.push_back(temp);

    return temp;
}

void LineCounter::LineNumbersChanged(int numbers)
{
    if(count < numbers)
        AddLine();

    else if(count > numbers)
        RemoveLine();
}

void LineCounter::ChangeOneLineCountersHeight(int value)
{
    multiplier += value;
    for(QLabel* lbl : lineNumber)
        lbl->setMinimumSize(width, height + multiplier);
}

void LineCounter::AddMultipleLines(int lines)
{

    for(int i = 0; i < lines; i++)
        vlayout->insertWidget(count-1, CreateLabel());
}
