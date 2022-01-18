#ifndef WHIGHLIGHTPREFERENCES_H
#define WHIGHLIGHTPREFERENCES_H

#include <QWidget>
#include <QFile>
#include <QDir>
#include <QList>

namespace Ui {
class WHighlightPreferences;
}

class WHighlightPreferences : public QWidget
{
    Q_OBJECT

public:
    explicit WHighlightPreferences(QWidget *parent = nullptr);
    ~WHighlightPreferences();

private:
    Ui::WHighlightPreferences *ui;
    QList< QString > languagesList;

    void ReadLanguages();

};

#endif // WHIGHLIGHTPREFERENCES_H
