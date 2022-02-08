#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QStandardPaths>
#include <QScrollBar>
#include <memory>
#include <QObject>

#include "fscdocument.h"
#include "fscobject.h"
#include "linecounter.h"
#include "highlighter.h"
#include "style_sheets.h"

namespace Ui {
class TextEditor;
}

class TextEditor : public QWidget
{
    Q_OBJECT

public:
    TextEditor();
    TextEditor(const QString &filename, QWidget *parent);
    TextEditor(QWidget *parent);
    ~TextEditor();


    bool SaveFile();
    bool SaveFileAs();

private:

    void OpenFileInEditor();
    void Config();
    void ReadGlobalSettings();

public slots:

    void on_resize(int w, int h);
    void valueChanged(int val);

private slots:

    void on_LineNumbersChanged(int line);

private:
    Ui::TextEditor *ui;

    int countLine = 0;

    LineCounter *linecounter;

    std::unique_ptr< QFile > file;
//    std::unique_ptr< QPlainTextEdit > texteditor;

    QString language = "PlainText";

    Highlighter *highlighter;

    QWidget *parent = nullptr;
    FSCDocument *fscdocument;

};

#endif // TEXTEDITOR_H
