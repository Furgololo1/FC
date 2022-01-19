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

void WHighlightPreferences::on_ReadKeywords(const QString &lang)
{
    document = new FSCDocument("config/" + lang + ".txt");

    document->ReadFromFile();

    for(auto &i : *document->GetObjectsFromFile())
        ui->keywordList->addItem(i.GetObjectName());

}

void WHighlightPreferences::on_ReadKeywordsValues(const QString &kw)
{

}
