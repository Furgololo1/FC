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
#include "editorbutton.h"
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
    explicit TextEditor(const QString &filename, QWidget *parent, EditorButton *_button);
    explicit TextEditor(QWidget *parent, EditorButton *_button);
    ~TextEditor();

    bool SaveFile();
    bool SaveFileAs();

    [[noreturn]] void CloseEditor();

private:

    void OpenFileInEditor();
    void ConfigureEditor();
    void ReadGlobalSettings();
    bool eventFilter(QObject *object, QEvent *event);

public slots:

    void on_resize(int w, int h);
    void valueChanged(int value);
    void cursourPositionChanged();

private slots:

    void on_LineNumbersChanged(int line);

private:
    Ui::TextEditor *ui;

    int countLine = 0;

    LineCounter *linecounter;

    std::unique_ptr< QFile > file;

    QString language = "PlainText";
    EditorButton* button;

    Highlighter *highlighter;

    QWidget *parent = nullptr;
    FSCDocument *fscdocument;

};

#endif // TEXTEDITOR_H

