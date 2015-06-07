#include "TigerWoodsProgressFile.h"

using namespace TigerWoods13;

ProgressFile::ProgressFile(std::shared_ptr<BaseIO> progressFile, QObject *parent) :
    m_progressFile(progressFile), QObject(parent)
{
    loadLegacyChallengeNames("C:\\Users\\Adam\\Desktop\\Modding\\Tiger Woods 2013\\legacy challenges.txt");
    readFile();
}
QList<TigerLegacyChallenge *> ProgressFile::legacyChallenges() const
{
    return m_legacyChallenges;
}

void ProgressFile::loadLegacyChallengeNames(QString fileName)
{
    // attempt to open the file for reading
    QFile legacyChallengesFile(fileName);
    if (!legacyChallengesFile.open(QIODevice::ReadOnly))
        return;

    // read all the challenge names in
    QTextStream legacyChallengesIn(&legacyChallengesFile);
    while (!legacyChallengesIn.atEnd())
    {
        // read the next challenge from the file
        QString line = legacyChallengesIn.readLine();
        QStringList challengeComponents = line.split(":");

        // construct the challenge object
        TigerLegacyChallenge *challenge = new TigerLegacyChallenge(this);
        challenge->setSection(challengeComponents.at(0));
        challenge->setName(challengeComponents.at(1));
        challenge->setPartCount(challengeComponents.at(2).toInt());

        m_legacyChallenges.push_back(challenge);
    }

    legacyChallengesFile.close();
}

void ProgressFile::readFile()
{
    // read the tiger legacy challenge progress
    m_progressFile->SetPosition(0x24);
    for (int i = 0; i < m_legacyChallenges.size(); i++)
    {
        for (int partIndex = 0; partIndex < m_legacyChallenges.at(i)->partCount(); partIndex++)
        {
            bool curLegacyChallengeComplete = (bool)m_progressFile->ReadDword();
            m_legacyChallenges.at(i)->setComplete(partIndex, curLegacyChallengeComplete);
        }
    }
}
