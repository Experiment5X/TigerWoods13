#include "MainWindow.h"
#include "TigerWoodsUserFile.h"
#include "TigerWoodsProgressFile.h"
#include "IO/FileIO.h"

#include <QApplication>
#include <QDebug>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

    /*std::shared_ptr<FileIO> progressFile = std::make_shared<FileIO>("C:\\Users\\Adam\\Desktop\\Modding\\Tiger Woods 2013\\Adam Tiger Legacy\\Finished Junior Years\\13-Progress");
    TigerWoodsProgressFile progressData(progressFile);

    for (TigerWoodsTigerLegacyChallenge *challenge : progressData.legacyChallenges())
    {
        qDebug() << challenge->name();
        for (bool partComplete : challenge->complete())
            qDebug() << "\t" << partComplete;
    }*/

    /*try
    {
        std::shared_ptr<FileIO> userFile(new FileIO("C:\\Users\\Adam\\Desktop\\Modding\\Tiger Woods 2013\\All Skills 100 Adam\\13-User 0"));
        TigerWoodsUserFile userData(userFile);\

        qDebug() << userData.name();
        qDebug() << "XP Earned: " << userData.xpEarned();
        qDebug() << "XP Spent: " << userData.xpSpent();

        qDebug() << endl << "Stats";
        qDebug() << "\tLongest Drive: " << userData.longestDrive() << "yds";
        qDebug() << "\tLongest Putt: " << userData.longestPutt() << "ft";
        qDebug() << "\tDouble Eagles: " << userData.doubleEagles();
        qDebug() << "\tEagles: " << userData.eagles();
        qDebug() << "\tBirdies: " << userData.birdies();
        qDebug() << "\tPars: " << userData.pars();
        qDebug() << "\tBogeys: " << userData.bogeys();
        qDebug() << "\tDouble Bogeys: " << userData.doubleBogeys();
    }
    catch (std::exception ex)
    {
        qDebug() << ex.what();
    }
    catch (std::string s)
    {
        qDebug() << QString::fromStdString(s);
    }*/

    return 0;
}
