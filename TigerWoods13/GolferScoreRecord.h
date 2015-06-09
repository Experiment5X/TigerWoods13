#ifndef GOLFERSCORERECORD_H
#define GOLFERSCORERECORD_H

#include <QObject>
#include <QList>

namespace TigerWoods13
{
class GolferScoreRecord : public QObject
{
    Q_OBJECT
public:
    static const int SIZE = 0x58;

    GolferScoreRecord(QObject *parent = 0);

    int unknown1() const;
    void setUnknown1(int unknown1);

    int unknown2() const;
    void setUnknown2(int unknown2);

    int unknown3() const;
    void setUnknown3(int unknown3);

    int unknown4() const;
    void setUnknown4(int unknown4);

    QList<int> scores() const;
    void setScores(const QList<int> &scores);

    int totalScore() const;

    int index() const;
    void setIndex(int index);

private:
    int m_index;
    int m_unknown1;
    int m_unknown2;
    int m_unknown3;
    int m_unknown4;
    QList<int> m_scores;
};
}

#endif // GOLFERSCORERECORD_H
