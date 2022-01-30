#include "highlighter.h"

Highlighter::Highlighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
{
        FSCDocument *document = new FSCDocument("config/C++.txt");
        document->ReadFromFile();

        HighlightingRule rule;

        keywordFormat.setForeground(Qt::darkBlue);
        keywordFormat.setFontWeight(QFont::Bold);

        for (auto &pattern : *document->GetObjectsFromFile()) {

            rule.pattern = QRegularExpression(pattern.GetValue("keyword").toString());

                if(pattern.GetObjectName() != "multi line comment"){
                    QColor color(pattern.GetValue("R").toInt(), pattern.GetValue("G").toInt(), pattern.GetValue("B").toInt(), 255  );
                    QBrush brush(color);
                    keywordFormat.setForeground(brush);

                    QFont font(pattern.GetValue("font").toString(), 16, QFont::Bold);
                    keywordFormat.setFont(font);

                    rule.format = keywordFormat;
                    highlightingRules.append(rule);
                }

                else{
                    QColor color(pattern.GetValue("R").toInt(), pattern.GetValue("G").toInt(), pattern.GetValue("B").toInt(), 255  );
                    QBrush brush(color);
                    multiLineCommentFormat.setForeground(brush);

                    QFont font(pattern.GetValue("font").toString());
                    multiLineCommentFormat.setFont(font);
                }

        }

            commentStartExpression = QRegularExpression(QStringLiteral("/\\*"));
            commentEndExpression = QRegularExpression(QStringLiteral("\\*/"));

}


void Highlighter::highlightBlock(const QString &text)
{

    for (const HighlightingRule &rule : qAsConst(highlightingRules)) {
           QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
           while (matchIterator.hasNext()) {
               QRegularExpressionMatch match = matchIterator.next();
               setFormat(match.capturedStart(), match.capturedLength(), rule.format);
           }
       }

      setCurrentBlockState(0);

      int startIndex = 0;
       if (previousBlockState() != 1)
           startIndex = text.indexOf(commentStartExpression);

       while (startIndex >= 0) {
              QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
              int endIndex = match.capturedStart();
              int commentLength = 0;
              if (endIndex == -1) {
                  setCurrentBlockState(1);
                  commentLength = text.length() - startIndex;
              } else {
                  commentLength = endIndex - startIndex
                                  + match.capturedLength();
              }
              setFormat(startIndex, commentLength, multiLineCommentFormat);
              startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
          }


}
