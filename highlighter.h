#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QTextEdit>
#include <QRegularExpression>
#include <QRegularExpressionMatchIterator>
#include <QObject>
#include <QFile>
#include <fscdocument.h>
#include <fscobject.h>

#include "style_sheets.h"

class Highlighter : public QSyntaxHighlighter
{
public:
    explicit Highlighter(QTextDocument *parent = 0);

    bool LoadHighlightingRules(const QString &language);


protected:
    void highlightBlock(const QString &text) override;

private:
    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;

    FSCDocument *document;

    void ReadPatternFromObjects();

};

#endif // HIGHLIGHTER_H
