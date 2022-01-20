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

    void on_lineEdit_R_textChanged(const QString &arg1);

    void on_lineEdit_G_textChanged(const QString &arg1);

    void on_lineEdit_B_textChanged(const QString &arg1);

    void on_saveButton_clicked();

private:
    Ui::WHighlightPreferences *ui;

    QList< QString > languagesList;

    FSCDocument *document = nullptr;
    FSCObject *fscobj = nullptr;

    //variables for colorpreview color
    QString r = "0";
    QString g = "0";
    QString b = "0";

    void ReadLanguages();
    void ChangePreviewColor();




};

#endif // WHIGHLIGHTPREFERENCES_H
