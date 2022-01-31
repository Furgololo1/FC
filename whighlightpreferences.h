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

    void on_fontComboBox_currentTextChanged(const QString &arg1);

    void on_cbBold_stateChanged(int arg1);

    void on_cbItalic_stateChanged(int arg1);

    void on_cbUnderline_stateChanged(int arg1);

    void on_manageKeywordButton_clicked();

    void on_createButton_clicked();

    void on_RemovButton_clicked();

    void on_fontSize_textChanged(const QString &arg1);

private:
    Ui::WHighlightPreferences *ui;

    QList< QString > languagesList;

    FSCDocument *document = nullptr;
    FSCObject *fscobj = nullptr;

    QString keyword;

    //variables for text preview
    QString r = "0";
    QString g = "0";
    QString b = "0";
    QString font = "Consolas";
    int fontsize = 10;
    bool bold = false;
    bool italic = false;
    bool underline = false;

    void ReadLanguages();
    void ReadFonts();
    void ChangePreviewColor();
    void ChangePreviewText();




};

#endif // WHIGHLIGHTPREFERENCES_H
