#include "whighlightpreferences.h"
#include "ui_whighlightpreferences.h"

WHighlightPreferences::WHighlightPreferences(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WHighlightPreferences)
{
    ui->setupUi(this);
    ReadLanguages();
}

WHighlightPreferences::~WHighlightPreferences()
{
    delete ui;
}

void WHighlightPreferences::ReadLanguages()
{
    QDir dir("config/");

    for(const auto &i : dir.entryInfoList(QDir::Files))
    //    languagesList.push_back(i.baseName());

    ui->languages->addItem(i.baseName());
}
