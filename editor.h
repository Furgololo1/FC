#ifndef EDITOR_H
#define EDITOR_H

#include <QTextEdit>
#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QStandardPaths>
#include <memory>

#include "highlighter.h"


class Editor//as
{

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

private:

    std::unique_ptr< QFile > file;
    std::unique_ptr< QTextEdit > texteditor;

    Highlighter *highlighter;

    QWidget *parent = nullptr;

    void OpenFileInEditor();

};

#endif // EDITOR_H
