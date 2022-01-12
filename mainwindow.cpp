#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "style_sheets.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ConfigureGUI();
    Connections();

}

MainWindow::~MainWindow()
{
    for (auto &e : editors)
        delete e;

    for (auto &b : buttonsToEditor)
        delete b;

    delete ui;
}

void MainWindow::ConfigureGUI()
{
    ui->menubar->setStyleSheet(StyleSheetsGUI::menuBarStyle);
    ui->menuFile->setStyleSheet(StyleSheetsGUI::menuStyle);
    ui->stackedWidget->setStyleSheet(StyleSheetsGUI::stackWidgetStyle);
}

void MainWindow::CreateEditor(const QString &filename)
{
    static int i = 0;
     //new tab for editor
     QWidget *newTab = new QWidget(ui->stackedWidget);
     ui->stackedWidget->addWidget( newTab );
     newTab->setStyleSheet(StyleSheetsGUI::widgetStyle);

     QSize size = this->size();
     newTab->resize(size.width()-50, size.height()-80);

     //new editor
     if(filename == nullptr)
        editors.emplaceBack(new Editor( newTab ));
     else
        editors.emplaceBack(new Editor( filename, newTab ));

     CreateButton(i);
     i++;
}

void MainWindow::CreateButton(int index)
{
    EditorButton* ptrbutton = new EditorButton();

    ptrbutton->setParent(this);
    ptrbutton->setText("unnamed");
    ptrbutton->SetEditorIndex(index);

    if(editors.count() <= 1)
        ptrbutton->setStyleSheet(StyleSheetsGUI::currentEditorButtonStyle);
    else
        ptrbutton->setStyleSheet(StyleSheetsGUI::editorButtonStyle);

    ptrbutton->setFixedSize(80,30);
    ptrbutton->move(40 + buttonx * buttonsToEditor.size(), buttony);
    ptrbutton->show();
    ptrbutton->connect(ptrbutton, &EditorButton::clicked, this, [=](){  this->on_OpenEditor(ptrbutton->GetEditorIndex());   });

    buttonsToEditor.push_back(ptrbutton);

}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QSize size = this->size();

    ui->stackedWidget->resize(size.width()-50, size.height()-80);

    for(auto &e : editors)
        e->on_resize(ui->stackedWidget->size().width(), ui->stackedWidget->size().height());

}


void MainWindow::on_pushButton_clicked()
{
    FSCDocument doc("config.txt");
    FSCObject obj1("int");
    obj1.CreateValue("keyword", QStringLiteral("//bint//b"));
    obj1.CreateValue("R", 40);
    obj1.CreateValue("G", 50);
    obj1.CreateValue("B", 255);
    obj1.CreateValue("bold", false);
    obj1.CreateValue("font", QStringLiteral("Arial Black"));

    FSCObject obj2("double");
    obj2.CreateValue("keyword", QStringLiteral("//bdouble//b"));
    obj2.CreateValue("R", 102);
    obj2.CreateValue("G", 28);
    obj2.CreateValue("B", 215);
    obj2.CreateValue("bold", true);
    obj2.CreateValue("font", QStringLiteral("Arial Black"));

//     doc.AppendObject(obj1);
//     doc.AppendObject(obj2);

//     doc.SaveObjectsToFile();

 //   qDebug()<<obj1.GetValue("font").toString();
    doc.ReadFromFile();


}

