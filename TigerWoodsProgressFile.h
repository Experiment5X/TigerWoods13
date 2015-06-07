#ifndef TIGERWOODSPROGRESSFILE_H
#define TIGERWOODSPROGRESSFILE_H

#include <QString>
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QList>

#include <memory>

#include "IO/BaseIO.h"
#include "TigerWoodsTigerLegacyChallenge.h"

namespace TigerWoods13
{
class ProgressFile : public QObject
{
    Q_OBJECT
public:
    ProgressFile(std::shared_ptr<BaseIO> progressFile, QObject *parent = 0);

    QList<TigerLegacyChallenge *> legacyChallenges() const;

private:
    std::shared_ptr<BaseIO> m_progressFile;
    QList<TigerLegacyChallenge*> m_legacyChallenges;

    void loadLegacyChallengeNames(QString fileName);

    void readFile();
};
}

#endif // TIGERWOODSPROGRESSFILE_H
