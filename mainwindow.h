#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QStandardPaths>
#include <QList>

#include "texteditor.h"
#include "editorbutton.h"
#include "fscdocument.h"
#include "fscobject.h"
#include "whighlightpreferences.h"
//#include "style_sheets.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void ConfigureGUI();
    void resizeEvent(QResizeEvent*);
    void Connections();
    void CreateEditor(const QString &);
    EditorButton* CreateButton(int index);

private slots:
    void on_OpenFile();
    void on_NewFile();
    void on_SaveFile();
    void on_SaveFileAs();
    void on_OpenEditor(int index);
    void on_highlightPref();

private:

    QList< TextEditor* > texteditors;
    QList< EditorButton *> buttonsToEditor;

    //button coords
    const int buttonx = 80;
    const int buttony = 25;


};
#endif // MAINWINDOW_H
