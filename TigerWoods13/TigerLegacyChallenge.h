#ifndef TIGERWOODSTIGERLEGACYCHALLENGE_H
#define TIGERWOODSTIGERLEGACYCHALLENGE_H

#include <QObject>
#include <QList>

namespace TigerWoods13
{
class TigerLegacyChallenge : public QObject
{
    Q_OBJECT
public:
    explicit TigerLegacyChallenge(QObject *parent = 0);
    TigerLegacyChallenge(QString section, QString name, QList<bool> complete, QObject *parent = 0);

    QString section() const;
    void setSection(const QString &section);

    QString name() const;
    void setName(const QString &name);

    QList<bool> complete() const;
    void setComplete(int partIndex, bool complete);

    // true if all the parts of the challenge are completed
    bool fullyComplete() const;

    // the number of parts to the challenge, for example some challenges have a putting, chipping, and driving part
    int partCount() const;
    void setPartCount(int partCount);

private:
    QString m_section;
    QString m_name;
    int m_partCount;
    QList<bool> m_complete;
};
}

#endif // TIGERWOODSTIGERLEGACYCHALLENGE_H
