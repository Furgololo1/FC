#ifndef WHIGHLIGHTPREFERENCES_H
#define WHIGHLIGHTPREFERENCES_H

#include <QWidget>
#include <QFile>
#include <QDir>
#include <QList>

#include <fscdocument.h>
#include <fscobject.h>

namespace Ui {
class WHighlightPreferences;
}

class WHighlightPreferences : public QWidget
{
    Q_OBJECT

public:
    explicit WHighlightPreferences(QWidget *parent = nullptr);
    ~WHighlightPreferences();

private slots:
    void on_ReadKeywordsValues(const QString &kw);
    void on_ReadKeywords(const QString &lang);

private:
    Ui::WHighlightPreferences *ui;

    QList< QString > languagesList;

    FSCDocument *document = nullptr;

    void ReadLanguages();




};

#endif // WHIGHLIGHTPREFERENCES_H
