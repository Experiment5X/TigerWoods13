#include "MainWindow.h"
#include "TigerWoodsUserFile.h"
#include "IO/FileIO.h"

#include <QApplication>
#include <QDebug>
#include <memory>

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/

    try
    {
        std::shared_ptr<FileIO> userFile(new FileIO("C:\\Users\\Adam\\Desktop\\Modding\\Tiger Woods 2013\\Adam Skills 52 51 48 37 36 35\\13-User 0"));
        TigerWoodsUserFile userData(userFile);
        qDebug() << userData.name();
    }
    catch (std::exception ex)
    {
        qDebug() << ex.what();
    }
    catch (std::string s)
    {
        qDebug() << QString::fromStdString(s);
    }

    return 0;
}
