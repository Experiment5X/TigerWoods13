#include "TigerWoodsUserFile.h"

using namespace TigerWoods13;

UserFile::UserFile(std::shared_ptr<BaseIO> userFile, QObject *parent) :
    m_userFile(userFile), QObject(parent)
{
    readFile();
}

QString UserFile::name() const
{
    return m_name;
}

void UserFile::setName(const QString &name)
{
    m_name = name;
}
int UserFile::xpEarned() const
{
    return m_xpEarned;
}

void UserFile::setXpEarned(int xpEarned)
{
    m_xpEarned = xpEarned;
}
int UserFile::xpSpent() const
{
    return m_xpSpent;
}

void UserFile::setXpSpent(int xpSpent)
{
    m_xpSpent = xpSpent;
}
int UserFile::longestDrive() const
{
    return m_longestDrive;
}

void UserFile::setLongestDrive(int longestDrive)
{
    m_longestDrive = longestDrive;
}
int UserFile::longestPutt() const
{
    return m_longestPutt;
}

void UserFile::setLongestPutt(int longestPutt)
{
    m_longestPutt = longestPutt;
}
int UserFile::doubleEagles() const
{
    return m_doubleEagles;
}

void UserFile::setDoubleEagles(int doubleEagles)
{
    m_doubleEagles = doubleEagles;
}
int UserFile::eagles() const
{
    return m_eagles;
}

void UserFile::setEagles(int eagles)
{
    m_eagles = eagles;
}
int UserFile::birdies() const
{
    return m_birdies;
}

void UserFile::setBirdies(int birdies)
{
    m_birdies = birdies;
}
int UserFile::pars() const
{
    return m_pars;
}

void UserFile::setPars(int pars)
{
    m_pars = pars;
}
int UserFile::bogeys() const
{
    return m_bogeys;
}

void UserFile::setBogeys(int bogeys)
{
    m_bogeys = bogeys;
}
int UserFile::doubleBogeys() const
{
    return m_doubleBogeys;
}

void UserFile::setDoubleBogeys(int doubleBogeys)
{
    m_doubleBogeys = doubleBogeys;
}
int UserFile::power() const
{
    return m_power;
}

void UserFile::setPower(int power)
{
    m_power = power;
}
int UserFile::accuracy() const
{
    return m_accuracy;
}

void UserFile::setAccuracy(int accuracy)
{
    m_accuracy = accuracy;
}
int UserFile::workability() const
{
    return m_workability;
}

void UserFile::setWorkability(int workability)
{
    m_workability = workability;
}
int UserFile::spin() const
{
    return m_spin;
}

void UserFile::setSpin(int spin)
{
    m_spin = spin;
}
int UserFile::recovery() const
{
    return m_recovery;
}

void UserFile::setRecovery(int recovery)
{
    m_recovery = recovery;
}
int UserFile::putting() const
{
    return m_putting;
}

void UserFile::setPutting(int putting)
{
    m_putting = putting;
}
int UserFile::roundsPlayed() const
{
    return m_roundsPlayed;
}

void UserFile::setRoundsPlayed(int roundsPlayed)
{
    m_roundsPlayed = roundsPlayed;
}
int UserFile::totalScore() const
{
    return m_totalScore;
}

void UserFile::setTotalScore(int totalScore)
{
    m_totalScore = totalScore;
}

float UserFile::averageScore() const
{
    return (float)m_totalScore / m_roundsPlayed;
}
int UserFile::madePutts() const
{
    return m_madePutts;
}

void UserFile::setMadePutts(int madePutts)
{
    m_madePutts = madePutts;
}
int UserFile::totalPutts() const
{
    return m_totalPutts;
}

void UserFile::setTotalPutts(int totalPutts)
{
    m_totalPutts = totalPutts;
}
int UserFile::totalDrives() const
{
    return m_totalDrives;
}

void UserFile::setTotalDrives(int totalDrives)
{
    m_totalDrives = totalDrives;
}
int UserFile::totalYardsDriven() const
{
    return m_totalYardsDriven;
}

void UserFile::setTotalYardsDriven(int totalYardsDriven)
{
    m_totalYardsDriven = totalYardsDriven;
}
int UserFile::totalFIRAttempts() const
{
    return m_totalFIRAttempts;
}

void UserFile::setTotalFIRAttempts(int totalFIRAttempts)
{
    m_totalFIRAttempts = totalFIRAttempts;
}
int UserFile::totalFIRs() const
{
    return m_totalFIRs;
}

void UserFile::setTotalFIRs(int totalFIRs)
{
    m_totalFIRs = totalFIRs;
}
int UserFile::totalGIRAttempts() const
{
    return m_totalGIRAttempts;
}

void UserFile::setTotalGIRAttempts(int totalGIRAttempts)
{
    m_totalGIRAttempts = totalGIRAttempts;
}
int UserFile::totalGIRs() const
{
    return m_totalGIRs;
}

void UserFile::setTotalGIRs(int totalGIRs)
{
    m_totalGIRs = totalGIRs;
}
int UserFile::holesInOne() const
{
    return m_holesInOne;
}

void UserFile::setHolesInOne(int holesInOne)
{
    m_holesInOne = holesInOne;
}

void UserFile::readFile()
{
    m_userFile->SetEndian(BigEndian);

    // read the name
    m_userFile->SetPosition(0x20);
    m_name = QString::fromStdString(m_userFile->ReadString());

    // read the skills
    m_userFile->SetPosition(0x117C0);
    m_power = (int)(m_userFile->ReadFloat() * 100);
    m_accuracy = (int)(m_userFile->ReadFloat() * 100);
    m_workability = (int)(m_userFile->ReadFloat() * 100);
    m_spin = (int)(m_userFile->ReadFloat() * 100);
    m_recovery = (int)(m_userFile->ReadFloat() * 100);
    m_putting = (int)(m_userFile->ReadFloat() * 100);

    // read the xp info
    m_userFile->SetPosition(0x117FC);
    m_xpEarned = m_userFile->ReadInt32();
    m_xpSpent = m_userFile->ReadInt32();

    // read the stats
    m_userFile->SetPosition(0x118D4);
    m_totalScore = m_userFile->ReadInt32();
    m_roundsPlayed = m_userFile->ReadInt32();
    m_madePutts = m_userFile->ReadInt32();
    m_totalPutts = m_userFile->ReadInt32();
    m_totalDrives = m_userFile->ReadInt32();
    m_totalYardsDriven = m_userFile->ReadInt32();
    m_totalFIRAttempts = m_userFile->ReadInt32();
    m_totalFIRs = m_userFile->ReadInt32();
    m_totalGIRAttempts = m_userFile->ReadInt32();
    m_totalGIRs = m_userFile->ReadInt32();
    m_longestDrive = m_userFile->ReadInt32();
    m_longestPutt = m_userFile->ReadInt32();

    m_userFile->SetPosition(0x11908);
    m_holesInOne = m_userFile->ReadInt32();
    m_doubleEagles = m_userFile->ReadInt32();
    m_eagles = m_userFile->ReadInt32();
    m_birdies = m_userFile->ReadInt32();
    m_pars = m_userFile->ReadInt32();
    m_bogeys = m_userFile->ReadInt32();
    m_doubleBogeys = m_userFile->ReadInt32();
}
