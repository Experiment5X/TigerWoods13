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

class TigerWoodsProgressFile : public QObject
{
    Q_OBJECT
public:
    TigerWoodsProgressFile(std::shared_ptr<BaseIO> progressFile, QObject *parent = 0);

    QList<TigerWoodsTigerLegacyChallenge *> legacyChallenges() const;

private:
    std::shared_ptr<BaseIO> m_progressFile;
    QList<TigerWoodsTigerLegacyChallenge*> m_legacyChallenges;

    void loadLegacyChallengeNames(QString fileName);

    void readFile();
};

#endif // TIGERWOODSPROGRESSFILE_H
