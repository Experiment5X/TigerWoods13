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

private:
    QString m_name;
    int m_xpEarned;
    int m_xpSpent;
    int m_longestDrive;
    int m_longestPutt;
    int m_doubleEagles;
    int m_eagles;
    int m_birdies;
    int m_pars;
    int m_bogeys;
    int m_doubleBogeys;

    std::shared_ptr<BaseIO> m_userFile;

    void readFile();
};

#endif // TIGERWOODSUSERFILE_H
