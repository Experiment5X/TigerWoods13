#ifndef TIGERWOODSUSERFILE_H
#define TIGERWOODSUSERFILE_H

#include <QString>
#include <QObject>

#include <memory>

#include "IO/BaseIO.h"

class TigerWoodsUserFile : public QObject
{
    Q_OBJECT
public:
    TigerWoodsUserFile(std::shared_ptr<BaseIO> userFile, QObject *parent = nullptr);

    QString name() const;
    void setName(const QString &name);

    int xpEarned() const;
    void setXpEarned(int xpEarned);

    int xpSpent() const;
    void setXpSpent(int xpSpent);

    int longestDrive() const;
    void setLongestDrive(int longestDrive);

    int longestPutt() const;
    void setLongestPutt(int longestPutt);

    int doubleEagles() const;
    void setDoubleEagles(int doubleEagles);

    int eagles() const;
    void setEagles(int eagles);

    int birdies() const;
    void setBirdies(int birdies);

    int pars() const;
    void setPars(int pars);

    int bogeys() const;
    void setBogeys(int bogeys);

    int doubleBogeys() const;
    void setDoubleBogeys(int doubleBogeys);

    int power() const;
    void setPower(int power);

    int accuracy() const;
    void setAccuracy(int accuracy);

    int workability() const;
    void setWorkability(int workability);

    int spin() const;
    void setSpin(int spin);

    int recovery() const;
    void setRecovery(int recovery);

    int putting() const;
    void setPutting(int putting);

    int roundsPlayed() const;
    void setRoundsPlayed(int roundsPlayed);

    int totalScore() const;
    void setTotalScore(int totalScore);

    float averageScore() const;

    int madePutts() const;
    void setMadePutts(int madePutts);

    int totalPutts() const;
    void setTotalPutts(int totalPutts);

    int totalDrives() const;
    void setTotalDrives(int totalDrives);

    int totalYardsDriven() const;
    void setTotalYardsDriven(int totalYardsDriven);

    int totalFIRAttempts() const;
    void setTotalFIRAttempts(int totalFIRAttempts);

    int totalFIRs() const;
    void setTotalFIRs(int totalFIRs);

    int totalGIRAttempts() const;
    void setTotalGIRAttempts(int totalGIRAttempts);

    int totalGIRs() const;
    void setTotalGIRs(int totalGIRs);

    int holesInOne() const;
    void setHolesInOne(int holesInOne);

private:
    QString m_name;

    int m_xpEarned;
    int m_xpSpent;

    int m_roundsPlayed;
    int m_totalScore;
    int m_madePutts;
    int m_totalPutts;
    int m_totalDrives;
    int m_totalYardsDriven;
    int m_totalFIRAttempts;
    int m_totalFIRs;
    int m_totalGIRAttempts;
    int m_totalGIRs;
    int m_longestDrive;
    int m_longestPutt;
    int m_holesInOne;
    int m_doubleEagles;
    int m_eagles;
    int m_birdies;
    int m_pars;
    int m_bogeys;
    int m_doubleBogeys;

    int m_power;
    int m_accuracy;
    int m_workability;
    int m_spin;
    int m_recovery;
    int m_putting;

    std::shared_ptr<BaseIO> m_userFile;

    void readFile();
};

#endif // TIGERWOODSUSERFILE_H
