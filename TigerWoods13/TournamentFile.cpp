#include "TournamentFile.h"

using namespace TigerWoods13;

TournamentFile::TournamentFile(std::shared_ptr<BaseIO> tournamentFile, QObject *parent) :
    m_tournamentFile(tournamentFile), QObject(parent)
{
    readFile();
}
QList<GolferScoreRecord *> TournamentFile::golferScores() const
{
    return m_golferScores;
}

void TournamentFile::readFile()
{
    // read all the golfer scores
    m_tournamentFile->SetPosition(0x48);
    int golferEntryCount = 128; // this isn't right, it should be read from the file

    for (int i = 0; i < golferEntryCount; i++)
    {
        GolferScoreRecord *record = new GolferScoreRecord(this);
        record->setIndex(i);
        record->setUnknown1(m_tournamentFile->ReadInt32());
        record->setUnknown2(m_tournamentFile->ReadInt32());
        record->setUnknown3(m_tournamentFile->ReadInt32());
        record->setUnknown4(m_tournamentFile->ReadInt32());

        // read all the golfer scores
        QList<int> scores;
        for (int i = 0; i < 18; i++)
            scores.append(m_tournamentFile->ReadInt32());
        record->setScores(scores);

        m_golferScores.append(record);
    }
}
