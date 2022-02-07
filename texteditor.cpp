#include "texteditor.h"
#include "ui_texteditor.h"


TextEditor::TextEditor()
{

}

TextEditor::TextEditor(const QString &filename, QWidget *parent):
    QWidget(parent),
    ui(new Ui::TextEditor)
{
    ui->setupUi(this);
    file = std::make_unique< QFile >(filename);
    Config();
    OpenFileInEditor();
}

TextEditor::TextEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TextEditor)
{
    ui->setupUi(this);
    Config();
}

TextEditor::~TextEditor()
{
    delete ui;
}

void TextEditor::Config()
{

    highlighter = new Highlighter(ui->editor->document());
    if( !highlighter->LoadHighlightingRules("C++") ) //should be variable language instead of "C++"
        return;

    ui->editor->setStyleSheet(StyleSheetsGUI::editorStyle);
    ui->editor->setTabStopDistance(35);

    connect(ui->editor, &QPlainTextEdit::blockCountChanged, this, &TextEditor::on_LineNumbersChanged);

    ReadGlobalSettings();

    linecounter = new LineCounter(ui->verticalLayout);
    ui->verticalLayout->setSpacing(0);
    ui->editor->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

bool TextEditor::SaveFile()
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

    stream << ui->editor->toPlainText();

    return true;
}

bool TextEditor::SaveFileAs()
{
    highlighter = new Highlighter( ui->editor->document() );
    if( !highlighter->LoadHighlightingRules("C++") )
        return false;

    return true;
}

void TextEditor::on_resize(int w, int h)
{
    this->setFixedSize(w, h);
}

void TextEditor::on_LineNumbersChanged(int line)
{
   linecounter->LineNumbersChanged(line);
}

void TextEditor::OpenFileInEditor()
{
    if(  !file   ) return;

    if( file->open(  QIODevice::ReadOnly )   ) {

        ui->editor->appendPlainText(file->readAll());

        file->close();
    }

    linecounter->AddMultipleLines(ui->editor->blockCount());
    ui->editor->moveCursor(QTextCursor::Start);
    ui->editor->verticalScrollBar()->setDisabled(true);
//    ui->scrollArea->verticalScrollBar()->setValue(0);
}

void TextEditor::ReadGlobalSettings()
{
    fscdocument = new FSCDocument("config/GlobalSettings.txt");
    fscdocument->ReadFromFile();
    FSCObject *obj = fscdocument->GetObjectByName("globalsettings");

    ui->editor->setFont(QFont(obj->GetValue("font").toString(), obj->GetValue("fontsize").toInt()));

}

void TextEditor::wheelEvent(QWheelEvent *e)
{
    qDebug()<<"wheelEvent";
}

//follow the cursor




