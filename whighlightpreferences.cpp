#include "whighlightpreferences.h"
#include "ui_whighlightpreferences.h"

#include "style_sheets.h"

WHighlightPreferences::WHighlightPreferences(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WHighlightPreferences)
{
    ui->setupUi(this);

    ReadLanguages();
    ReadFonts();

    connect(ui->languagesComboBox, &QComboBox::textActivated, this, &WHighlightPreferences::on_ReadKeywords);
    connect(ui->keywordList, &QListWidget::currentTextChanged, this, &WHighlightPreferences::on_ReadKeywordsValues);
  //  setWindowFlags( Qt::FramelessWindowHint );

}

WHighlightPreferences::~WHighlightPreferences()
{
    delete document;
    delete fscobj;
    delete ui;
}

void WHighlightPreferences::ReadLanguages()
{
    QDir dir("config/");

    for(const auto &i : dir.entryInfoList(QDir::Files))
        ui->languagesComboBox->addItem(i.baseName());
}

void WHighlightPreferences::ReadFonts()
{
    QFile file("config/font.txt");

    if(!file.open(QIODevice::ReadOnly)) return;

    while(!file.atEnd())
        ui->fontComboBox->addItem(file.readLine());

    file.close();
}

void WHighlightPreferences::ChangePreviewColor()
{
    ui->colorPreview->setStyleSheet("QLabel{border: none; background-color: rgb("+r+","+g+","+b+");}");
}

void WHighlightPreferences::ChangePreviewText()
{
    QString style("QLabel{"
                  "border:1px solid #161616;"
                  "font-family: " + font + ";"
                  "color: rgb("+r+","+g+","+b+");");

    style.append(bold == true ? "font-weight: bold;" : "font-weight: normal;\n");
    style.append(italic == true ? "font-style: italic;" : "font-style: normal;\n");
    style.append(underline == true ? "text-decoration: underline;\n}" : "text-decoration: normal;\n}");

    ui->textPreview->setStyleSheet(style);
    //qDebug()<<style;
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
    keyword = kw;
    fscobj = document->GetObjectByName(keyword);

    ui->lineEdit_R->setText(fscobj->GetValue("R").toString());
    ui->lineEdit_G->setText(fscobj->GetValue("G").toString());
    ui->lineEdit_B->setText(fscobj->GetValue("B").toString());
    ui->fontComboBox->setCurrentText(fscobj->GetValue("font").toString());

    ui->textPreview->setText(kw);

    (fscobj->GetValue("bold").toBool()) ? ui->cbBold->setChecked(true): ui->cbBold->setChecked(false);
    (fscobj->GetValue("italic").toBool()) ? ui->cbItalic->setChecked(true): ui->cbItalic->setChecked(false);
    (fscobj->GetValue("underline").toBool()) ? ui->cbUnderline->setChecked(true): ui->cbUnderline->setChecked(false);

}

void WHighlightPreferences::on_saveButton_clicked()
{
    if(!fscobj) return;

    fscobj->ChangeValue("R", r.toInt());
    fscobj->ChangeValue("G", g.toInt());
    fscobj->ChangeValue("B", b.toInt());

    QString font = ui->fontComboBox->currentText();
    fscobj->ChangeValue("font", font.remove(font.length()-2, 2));
    fscobj->ChangeValue("bold", bold);
    fscobj->ChangeValue("italic", italic);
    fscobj->ChangeValue("underline", underline);

    document->SaveObjectsToFile();

}

void WHighlightPreferences::on_lineEdit_R_textChanged(const QString &arg1)
{
    r = arg1;
    ChangePreviewColor();
    ChangePreviewText();
}


void WHighlightPreferences::on_lineEdit_G_textChanged(const QString &arg1)
{
    g = arg1;
    ChangePreviewColor();
    ChangePreviewText();
}


void WHighlightPreferences::on_lineEdit_B_textChanged(const QString &arg1)
{
    b = arg1;
    ChangePreviewColor();
    ChangePreviewText();
}

void WHighlightPreferences::on_fontComboBox_currentTextChanged(const QString &arg1)
{
    font = arg1;
    ChangePreviewText();
}

void WHighlightPreferences::on_cbBold_stateChanged(int arg1)
{
    bold = (arg1 == Qt::Checked) ? true : false;
    ChangePreviewText();
}

void WHighlightPreferences::on_cbItalic_stateChanged(int arg1)
{
    italic = (arg1 == Qt::Checked) ? true : false;
    ChangePreviewText();
}

void WHighlightPreferences::on_cbUnderline_stateChanged(int arg1)
{
    underline = (arg1 == Qt::Checked) ? true : false;
    ChangePreviewText();
}

