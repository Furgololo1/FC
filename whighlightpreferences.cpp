#include "whighlightpreferences.h"
#include "ui_whighlightpreferences.h"

WHighlightPreferences::WHighlightPreferences(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WHighlightPreferences)
{
    ui->setupUi(this);
    ReadLanguages();

    connect(ui->languagesComboBox, &QComboBox::textActivated, this, &WHighlightPreferences::on_ReadKeywords);
    connect(ui->keywordList, &QListWidget::currentTextChanged, this, &WHighlightPreferences::on_ReadKeywordsValues);

}

WHighlightPreferences::~WHighlightPreferences()
{
    delete ui;
}

void WHighlightPreferences::ReadLanguages()
{
    QDir dir("config/");

    for(const auto &i : dir.entryInfoList(QDir::Files))
        ui->languagesComboBox->addItem(i.baseName());
}

void WHighlightPreferences::ChangePreviewColor()
{
    ui->colorPreview->setStyleSheet("QLabel{background-color: rgb("+r+","+g+","+b+");}");
    qDebug()<<"QLabel{background-color: rgb("+r+","+g+","+b+");}";
}

void WHighlightPreferences::on_ReadKeywords(const QString &lang)
{
    ui->keywordList->clear();

    if(document)
        delete document;

    document = new FSCDocument("config/" + lang + ".txt");

    document->ReadFromFile();

    for(auto &i : *document->GetObjectsFromFile())
        ui->keywordList->addItem(i.GetObjectName());

}

void WHighlightPreferences::on_ReadKeywordsValues(const QString &kw)
{
    fscobj = document->GetObjectByName(kw);

    ui->lineEdit_R->setText(fscobj->GetValue("R").toString());
    ui->lineEdit_G->setText(fscobj->GetValue("G").toString());
    ui->lineEdit_B->setText(fscobj->GetValue("B").toString());
    ui->fontComboBox->addItem(fscobj->GetValue("font").toString());

    (fscobj->GetValue("bold").toBool()) ? ui->cbBold->setChecked(true): ui->cbBold->setChecked(false);
    (fscobj->GetValue("italic").toBool()) ? ui->cbItalic->setChecked(true): ui->cbItalic->setChecked(false);
    (fscobj->GetValue("underline").toBool()) ? ui->cbUnderline->setChecked(true): ui->cbUnderline->setChecked(false);

}


void WHighlightPreferences::on_lineEdit_R_textChanged(const QString &arg1)
{
    r = arg1;
    ChangePreviewColor();
}


void WHighlightPreferences::on_lineEdit_G_textChanged(const QString &arg1)
{
    g = arg1;
    ChangePreviewColor();
}


void WHighlightPreferences::on_lineEdit_B_textChanged(const QString &arg1)
{
    b = arg1;
    ChangePreviewColor();
}


void WHighlightPreferences::on_saveButton_clicked()
{

}

