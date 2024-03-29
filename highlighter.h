#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QRegularExpression>

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

//! [0]
class Highlighter : public QSyntaxHighlighter //继承QSyntaxHightliaghter
{
    Q_OBJECT

public:
    Highlighter(QTextDocument *parent = 0);//构造函数传一个 QTextDocument 对象 给父类

protected:
    void highlightBlock(const QString &text) override;//重写父类这个函数 自动调用

private:

    struct HighlightingRule//语法规则结构体，包含正则表达式模式串和匹配的样式
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;//规则的集合

    QRegularExpression commentStartExpression; //注释的高亮，使用highliangBlock()匹配
    QRegularExpression commentEndExpression;

    QTextCharFormat keywordFormat;//高亮样式，关键词
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
};
//! [0]

#endif // HIGHLIGHTER_H
