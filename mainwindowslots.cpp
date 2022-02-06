#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "style_sheets.h"

void MainWindow::Connections()
{
    ui->menuFile->addAction("New File", this, &MainWindow::on_NewFile, QKeySequence::New);
    ui->menuFile->addAction("Open File ...", this, &MainWindow::on_OpenFile, QKeySequence::Open);
    ui->menuFile->addAction("Save File", this, &MainWindow::on_SaveFile, QKeySequence::Save);
    ui->menuFile->addAction("Save File As ...", this, &MainWindow::on_SaveFileAs, QKeySequence::SaveAs);
    ui->menuPreferences->addAction("Highlights", this, &MainWindow::on_highlightPref);
}

void MainWindow::on_OpenFile()
{
    //get file to open
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose File"), QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));

    CreateEditor(filename);
}

void MainWindow::on_NewFile()
{
    CreateEditor(nullptr);
}

void MainWindow::on_SaveFile()
{
   if(texteditors.at(ui->stackedWidget->currentIndex())->SaveFile()) return;
}

void MainWindow::on_SaveFileAs()
{

}

void MainWindow::on_OpenEditor(int index)
{
    ui->stackedWidget->setCurrentIndex(index);

    for (const auto &b: buttonsToEditor) {
        if(b->GetEditorIndex() == index)
            b->setStyleSheet(StyleSheetsGUI::currentEditorButtonStyle);
        else
            b->setStyleSheet(StyleSheetsGUI::editorButtonStyle);

    }
}

void MainWindow::on_highlightPref()
{
    WHighlightPreferences *whp = new WHighlightPreferences();
    //ui->stackedWidget->addWidget(whp);
    whp->show();

}
