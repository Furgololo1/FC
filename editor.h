#ifndef EDITOR_H
#define EDITOR_H

#include <QPlainTextEdit>
#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QStandardPaths>
#include <memory>
#include <QObject>

#include "linecounter.h"
#include "highlighter.h"


class Editor: public QObject
{
    Q_OBJECT

public:
    Editor();
    Editor(const QString &filename, QWidget *parent);
    Editor(QWidget *parent);
   ~Editor();

    bool SaveFile();
    bool SaveFileAs();

public slots:

    void on_resize(int w, int h);

private slots:

    void on_newText();
    void on_LineNumbersChanged(int line);

private:

    int countLine = 0;

    LineCounter *linecounter;

    std::unique_ptr< QFile > file;
    std::unique_ptr< QPlainTextEdit > texteditor;

    QString language = "PlainText";

    Highlighter *highlighter;

    QWidget *parent = nullptr;

    void OpenFileInEditor();

};

#endif // EDITOR_H
