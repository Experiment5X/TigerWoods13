#include "GolferScoreRecord.h"

using namespace TigerWoods13;

GolferScoreRecord::GolferScoreRecord(QObject *parent) :
    QObject(parent)
{
}
int GolferScoreRecord::unknown1() const
{
    return m_unknown1;
}

void GolferScoreRecord::setUnknown1(int unknown1)
{
    m_unknown1 = unknown1;
}
int GolferScoreRecord::unknown2() const
{
    return m_unknown2;
}

void GolferScoreRecord::setUnknown2(int unknown2)
{
    m_unknown2 = unknown2;
}
int GolferScoreRecord::unknown3() const
{
    return m_unknown3;
}

void GolferScoreRecord::setUnknown3(int unknown3)
{
    m_unknown3 = unknown3;
}
int GolferScoreRecord::unknown4() const
{
    return m_unknown4;
}

void GolferScoreRecord::setUnknown4(int unknown4)
{
    m_unknown4 = unknown4;
}
QList<int> GolferScoreRecord::scores() const
{
    return m_scores;
}

void GolferScoreRecord::setScores(const QList<int> &scores)
{
    m_scores = scores;
}

int GolferScoreRecord::totalScore() const
{
    int toReturn = 0;
    for (int score : m_scores)
        toReturn += score;
    return toReturn;
}
int GolferScoreRecord::index() const
{
    return m_index;
}

void GolferScoreRecord::setIndex(int index)
{
    m_index = index;
}
