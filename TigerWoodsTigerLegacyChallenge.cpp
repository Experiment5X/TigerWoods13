#include "TigerWoodsTigerLegacyChallenge.h"

TigerWoodsTigerLegacyChallenge::TigerWoodsTigerLegacyChallenge(QObject *parent) :
    QObject(parent)
{
}

TigerWoodsTigerLegacyChallenge::TigerWoodsTigerLegacyChallenge(QString section, QString name, QList<bool> complete, QObject *parent) :
    m_section(section), m_name(name), m_complete(complete), QObject(parent)
{
    m_partCount = m_complete.size();
}

QString TigerWoodsTigerLegacyChallenge::name() const
{
    return m_name;
}

void TigerWoodsTigerLegacyChallenge::setName(const QString &name)
{
    m_name = name;
}
QString TigerWoodsTigerLegacyChallenge::section() const
{
    return m_section;
}

void TigerWoodsTigerLegacyChallenge::setSection(const QString &section)
{
    m_section = section;
}
QList<bool> TigerWoodsTigerLegacyChallenge::complete() const
{
    return m_complete;
}

void TigerWoodsTigerLegacyChallenge::setComplete(int partIndex, bool complete)
{
    m_complete.replace(partIndex, complete);
}
int TigerWoodsTigerLegacyChallenge::partCount() const
{
    return m_partCount;
}

void TigerWoodsTigerLegacyChallenge::setPartCount(int partCount)
{
    m_partCount = partCount;

    // initialize all the parts to false
    m_complete.clear();
    for (int i = 0; i < partCount; i++)
        m_complete.push_back(false);
}
