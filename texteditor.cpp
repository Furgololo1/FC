#include "texteditor.h"
#include "ui_texteditor.h"


TextEditor::TextEditor()
{

}

TextEditor::TextEditor(const QString &filename, QWidget *parent, EditorButton *_button):
    QWidget(parent),
    ui(new Ui::TextEditor),
    button(_button)
{
    ui->setupUi(this);
    file = std::make_unique< QFile >(filename);
    Config();
    OpenFileInEditor();
}

TextEditor::TextEditor(QWidget *parent, EditorButton *_button) :
    QWidget(parent),
    ui(new Ui::TextEditor),
    button(_button)
{
    ui->setupUi(this);
    Config();
}

TextEditor::~TextEditor()
{
    delete linecounter;
    delete highlighter;
    delete fscdocument;
    delete ui;
}

void TextEditor::Config()
{

    highlighter = new Highlighter(ui->editor->document());
    if( !highlighter->LoadHighlightingRules("C++") ) //should be variable language instead of "C++"
        return;

    ui->editor->setTabStopDistance(35);

    connect(ui->editor, &QPlainTextEdit::blockCountChanged, this, &TextEditor::on_LineNumbersChanged);
    connect(ui->editor->verticalScrollBar(), &QAbstractSlider::valueChanged, this, &TextEditor::valueChanged);
    connect(ui->editor, &QPlainTextEdit::cursorPositionChanged, this, &TextEditor::cursourPositionChanged);

    ReadGlobalSettings();

    linecounter = new LineCounter(ui->vLayout);
    ui->vLayout->setSpacing(0);

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

//    button->setText(file.get()->fileName());  you know what to do with this

    return true;
}

void TextEditor::on_resize(int w, int h)
{
    this->setFixedSize(w, h);
}

void TextEditor::valueChanged(int val)
{
    qDebug()<<"val "<<val;
    ui->scrollArea->verticalScrollBar()->setValue((val*22)+3);
}

void TextEditor::cursourPositionChanged()
{
    int value = ui->editor->verticalScrollBar()->value();
    if(value == 0)
        ui->scrollArea->verticalScrollBar()->setValue((value*22));
    else
        ui->scrollArea->verticalScrollBar()->setValue((value*22) + 3);
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

    QString fileName = file.get()->fileName().mid(file.get()->fileName().lastIndexOf('/')+1);

    button->setText(fileName);

    linecounter->AddMultipleLines(ui->editor->blockCount());
    ui->editor->moveCursor(QTextCursor::Start);
    ui->editor->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

}

void TextEditor::ReadGlobalSettings()
{
    fscdocument = new FSCDocument("config/GlobalSettings.txt");
    fscdocument->ReadFromFile();
    FSCObject *obj = fscdocument->GetObjectByName("globalsettings");

    ui->editor->setFont(QFont(obj->GetValue("font").toString(), obj->GetValue("fontsize").toInt()));

}

//follow the cursor




