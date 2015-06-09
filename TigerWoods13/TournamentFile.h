#ifndef TOURNAMENTFILE_H
#define TOURNAMENTFILE_H

#include <QObject>
#include <QList>
#include <QDebug>

#include <memory>

#include "IO/BaseIO.h"
#include "TigerWoods13/GolferScoreRecord.h"

namespace TigerWoods13
{
class TournamentFile : public QObject
{
    Q_OBJECT
public:
    TournamentFile(std::shared_ptr<BaseIO> tournamentFile, QObject *parent = 0);

    QList<GolferScoreRecord *> golferScores() const;

private:
    std::shared_ptr<BaseIO> m_tournamentFile;
    QList<GolferScoreRecord*> m_golferScores;
    QList<int> m_puttCounts;
    QList<float> m_yardsDriven;

    void readFile();
};
}

#endif // TOURNAMENTFILE_H
