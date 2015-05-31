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
    explicit TigerWoodsUserFile(std::shared_ptr<BaseIO> userFile);

    QString name() const;
    void setName(const QString &name);

private:
    QString m_name;
    std::shared_ptr<BaseIO> m_userFile;

    void readFile();
};

#endif // TIGERWOODSUSERFILE_H
