#include "TigerWoodsUserFile.h"

TigerWoodsUserFile::TigerWoodsUserFile(std::shared_ptr<BaseIO> userFile, QObject *parent) :
    m_userFile(userFile), QObject(parent)
{
    readFile();
}

QString TigerWoodsUserFile::name() const
{
    return m_name;
}

void TigerWoodsUserFile::setName(const QString &name)
{
    m_name = name;
}
int TigerWoodsUserFile::xpEarned() const
{
    return m_xpEarned;
}

void TigerWoodsUserFile::setXpEarned(int xpEarned)
{
    m_xpEarned = xpEarned;
}
int TigerWoodsUserFile::xpSpent() const
{
    return m_xpSpent;
}

void TigerWoodsUserFile::setXpSpent(int xpSpent)
{
    m_xpSpent = xpSpent;
}
int TigerWoodsUserFile::longestDrive() const
{
    return m_longestDrive;
}

void TigerWoodsUserFile::setLongestDrive(int longestDrive)
{
    m_longestDrive = longestDrive;
}
int TigerWoodsUserFile::longestPutt() const
{
    return m_longestPutt;
}

void TigerWoodsUserFile::setLongestPutt(int longestPutt)
{
    m_longestPutt = longestPutt;
}
int TigerWoodsUserFile::doubleEagles() const
{
    return m_doubleEagles;
}

void TigerWoodsUserFile::setDoubleEagles(int doubleEagles)
{
    m_doubleEagles = doubleEagles;
}
int TigerWoodsUserFile::eagles() const
{
    return m_eagles;
}

void TigerWoodsUserFile::setEagles(int eagles)
{
    m_eagles = eagles;
}
int TigerWoodsUserFile::birdies() const
{
    return m_birdies;
}

void TigerWoodsUserFile::setBirdies(int birdies)
{
    m_birdies = birdies;
}
int TigerWoodsUserFile::pars() const
{
    return m_pars;
}

void TigerWoodsUserFile::setPars(int pars)
{
    m_pars = pars;
}
int TigerWoodsUserFile::bogeys() const
{
    return m_bogeys;
}

void TigerWoodsUserFile::setBogeys(int bogeys)
{
    m_bogeys = bogeys;
}
int TigerWoodsUserFile::doubleBogeys() const
{
    return m_doubleBogeys;
}

void TigerWoodsUserFile::setDoubleBogeys(int doubleBogeys)
{
    m_doubleBogeys = doubleBogeys;
}

void TigerWoodsUserFile::readFile()
{
    m_userFile->SetEndian(BigEndian);

    // read the name
    m_userFile->SetPosition(0x20);
    m_name = QString::fromStdString(m_userFile->ReadString());

    // read the xp info
    m_userFile->SetPosition(0x117FC);
    m_xpEarned = m_userFile->ReadDword();
    m_xpSpent = m_userFile->ReadDword();

    // read the stats
    m_userFile->SetPosition(0x118FC);
    m_longestDrive = m_userFile->ReadDword();
    m_longestPutt = m_userFile->ReadDword();

    m_userFile->SetPosition(0x1190C);
    m_doubleEagles = m_userFile->ReadDword();
    m_eagles = m_userFile->ReadDword();
    m_birdies = m_userFile->ReadDword();
    m_pars = m_userFile->ReadDword();
    m_bogeys = m_userFile->ReadDword();
    m_doubleBogeys = m_userFile->ReadDword();
}
