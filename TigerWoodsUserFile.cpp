#include "TigerWoodsUserFile.h"

TigerWoodsUserFile::TigerWoodsUserFile(std::shared_ptr<BaseIO> userFile) :
    m_userFile(userFile)
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

void TigerWoodsUserFile::readFile()
{
    m_userFile->SetEndian(BigEndian);

    m_userFile->SetPosition(0x20);
    m_name = QString::fromStdString(m_userFile->ReadString());
}
