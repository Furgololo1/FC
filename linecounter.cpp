#include "linecounter.h"

LineCounter::LineCounter()
{

}

LineCounter::LineCounter(QWidget *_parent): parent(_parent)
{
    AddLine();
}

LineCounter::~LineCounter()
{

}

void LineCounter::AddLine()
{
    QLabel *temp = new QLabel(parent);
    temp->move(0, 22 * count + 3);
    temp->resize(30,22);
    temp->setStyleSheet(StyleSheetsGUI::lineNumberStyle);
    count++;
    temp->setText(QString::number(count));
    temp->show();

    lineNumber.push_back(temp);
}

void LineCounter::RemoveLine()
{
    count--;
    delete lineNumber.last();
    lineNumber.removeLast();
}

void LineCounter::LineNumbersChanged(int numbers)
{
    if(count < numbers)
        AddLine();

    else if(count > numbers)
        RemoveLine();
}

void LineCounter::AddMultipleLines(int lines)
{
    QLabel *temp;

    for(int i = 0; i < lines; i++){
        temp = new QLabel(parent);
        temp->move(0, 22 * count + 3);
        temp->resize(30,22);
        temp->setStyleSheet(StyleSheetsGUI::lineNumberStyle);
        count++;
        temp->setText(QString::number(count));
        temp->show();

        lineNumber.push_back(temp);
    }
}
