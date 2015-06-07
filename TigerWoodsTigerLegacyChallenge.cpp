#include "TigerWoodsTigerLegacyChallenge.h"

using namespace TigerWoods13;

TigerLegacyChallenge::TigerLegacyChallenge(QObject *parent) :
    QObject(parent)
{
}

TigerLegacyChallenge::TigerLegacyChallenge(QString section, QString name, QList<bool> complete, QObject *parent) :
    m_section(section), m_name(name), m_complete(complete), QObject(parent)
{
    m_partCount = m_complete.size();
}

QString TigerLegacyChallenge::name() const
{
    return m_name;
}

void TigerLegacyChallenge::setName(const QString &name)
{
    m_name = name;
}
QString TigerLegacyChallenge::section() const
{
    return m_section;
}

void TigerLegacyChallenge::setSection(const QString &section)
{
    m_section = section;
}
QList<bool> TigerLegacyChallenge::complete() const
{
    return m_complete;
}

void TigerLegacyChallenge::setComplete(int partIndex, bool complete)
{
    m_complete.replace(partIndex, complete);
}

bool TigerLegacyChallenge::fullyComplete() const
{
    bool toReturn = true;
    for (bool complete : m_complete)
        toReturn = toReturn && complete;
    return toReturn;
}
int TigerLegacyChallenge::partCount() const
{
    return m_partCount;
}

void TigerLegacyChallenge::setPartCount(int partCount)
{
    m_partCount = partCount;

    // initialize all the parts to false
    m_complete.clear();
    for (int i = 0; i < partCount; i++)
        m_complete.push_back(false);
}
