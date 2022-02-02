#include "editor.h"

#include "style_sheets.h"

Editor::Editor()
{

}

Editor::Editor( QWidget *parent )
{
    this->parent = parent;
    texteditor = std::make_unique< QPlainTextEdit >(parent);
    texteditor->move(30,0);

    linecounter = new LineCounter(parent);

    highlighter = new Highlighter(texteditor->document());
    highlighter->LoadHighlightingRules("PlainText");

    QSize size = parent->size();

    texteditor->setFixedSize(size);
    texteditor->setStyleSheet(StyleSheetsGUI::editorStyle);
    texteditor->setTabStopDistance(35);

    texteditor->show();

  //  texteditor->connect(texteditor.get(), &QPlainTextEdit::blockCountChanged, linecounter, &LineCounter::LineNumbersChanged);

}

Editor::Editor( const QString &filename, QWidget *parent )
{
    this->parent = parent;

    file = std::make_unique< QFile >(filename);
    texteditor = std::make_unique< QPlainTextEdit >(parent);
    texteditor->move(30,0);

    qDebug() << "filename: " << filename;

    highlighter = new Highlighter(texteditor->document());
    if( !highlighter->LoadHighlightingRules("C++") )
        return;

    QSize size = parent->size();

    texteditor->setFixedSize(size);
    texteditor->setStyleSheet(StyleSheetsGUI::editorStyle);
    texteditor->setTabStopDistance(35);

    texteditor->show();

    OpenFileInEditor();

//    texteditor->connect(texteditor.get(), &QPlainTextEdit::blockCountChanged, linecounter, &LineCounter::LineNumbersChanged);
}

Editor::~Editor()
{

}

bool Editor::SaveFile()
{
    if( !file ){
        QString filters("*.cpp;; *.c;; *.cs;; *.html;; *.css;; *.php;; *.txt;;");
        QString defaultFilter("Text files (*.txt)");
        QString path = QFileDialog::getSaveFileName(parent, QFileDialog::tr("Save File"),
                                                    QDir::currentPath(), filters, &defaultFilter);
        file = std::make_unique< QFile >(path);
    }

    if( !file->open(QIODevice::WriteOnly) ) return false;

    QTextStream stream(file.get());

    stream << texteditor->toPlainText();

    return true;
}

bool Editor::SaveFileAs()
{
    highlighter = new Highlighter( texteditor->document() );
    if( !highlighter->LoadHighlightingRules("C++") )
        return false;

    return true;
}

void Editor::on_resize(int w, int h)
{
    texteditor->setFixedSize(w, h);
}

void Editor::on_newText()
{

}

void Editor::OpenFileInEditor()
{
    if(  !file   ) return;

    if( file->open(  QIODevice::ReadOnly )   ) {

        texteditor->appendPlainText(file->readAll());

        file->close();
    }

    linecounter->AddMultipleLines(texteditor->blockCount());
}
