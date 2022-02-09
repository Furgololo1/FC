#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "style_sheets.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setWindowFlags( );
    setStyleSheet(StyleSheetsGUI::windowStyle);
    ConfigureGUI();
    Connections();

}

MainWindow::~MainWindow()
{
    for (auto &e : texteditors)
        delete e;

    for (auto &b : buttonsToEditor)
        delete b;

    delete ui;
}

void MainWindow::ConfigureGUI()
{
    ui->menubar->setStyleSheet(StyleSheetsGUI::menuBarStyle);
    ui->menuFile->setStyleSheet(StyleSheetsGUI::menuStyle);
    ui->menuEdit->setStyleSheet(StyleSheetsGUI::menuStyle);
    ui->menuPreferences->setStyleSheet(StyleSheetsGUI::menuStyle);
    ui->stackedWidget->setStyleSheet(StyleSheetsGUI::stackWidgetStyle);

//    QFile styleFile( "style.qss" );
//    styleFile.open( QFile::ReadOnly );

//    // Apply the loaded stylesheet
//    QString style( styleFile.readAll() );
//    this->setStyleSheet( style );

}

void MainWindow::CreateEditor(const QString &filename)
{
    static int i = 0;

     //new tab for editor
    TextEditor *newTextEditor;
    if(filename == nullptr)
        newTextEditor = new TextEditor( ui->stackedWidget);
    else
        newTextEditor = new TextEditor(filename, ui->stackedWidget);


     ui->stackedWidget->addWidget( newTextEditor );
     newTextEditor->setStyleSheet(StyleSheetsGUI::editorStyle);

     //new editor
     if(filename == nullptr)
        texteditors.emplaceBack(newTextEditor);
     else
        texteditors.emplaceBack(newTextEditor);

     CreateButton(i);
     i++;
}

void MainWindow::CreateButton(int index)
{
    EditorButton* ptrbutton = new EditorButton();

    ptrbutton->setParent(this);
    ptrbutton->setText("unnamed");
    ptrbutton->SetEditorIndex(index);

    if(texteditors.count() <= 1)
        ptrbutton->setStyleSheet(StyleSheetsGUI::currentEditorButtonStyle);
    else
        ptrbutton->setStyleSheet(StyleSheetsGUI::editorButtonStyle);

    ptrbutton->setFixedSize(80,29);
    ptrbutton->move(buttonx * buttonsToEditor.size(), buttony);
    ptrbutton->show();
    ptrbutton->connect(ptrbutton, &EditorButton::clicked, this, [=](){  this->on_OpenEditor(ptrbutton->GetEditorIndex());   });

    buttonsToEditor.push_back(ptrbutton);

}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QSize size = this->size();

    ui->stackedWidget->resize(size.width(), size.height()-50);

   // for(auto &e : texteditors)
        //e->on_resize(ui->stackedWidget->size().width(), ui->stackedWidget->size().height()-80);
     //   e->resize(ui->stackedWidget->size().width(), ui->stackedWidget->size().height()-70);

}



