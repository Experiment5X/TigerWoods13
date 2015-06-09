#include "MainWindow.h"
#include "TigerWoods13/UserFile.h"
#include "TigerWoods13/ProgressFile.h"
#include "TigerWoods13/TournamentFile.h"
#include "IO/FileIO.h"

#include <QApplication>
#include <QList>
#include <QDebug>
#include <memory>

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/

    /*std::shared_ptr<FileIO> progressFile = std::make_shared<FileIO>("C:\\Users\\Adam\\Desktop\\Modding\\Tiger Woods 2013\\Adam Tiger Legacy\\Finished Junior Years\\13-Progress");
    TigerWoodsProgressFile progressData(progressFile);

    for (TigerWoodsTigerLegacyChallenge *challenge : progressData.legacyChallenges())
    {
        qDebug() << challenge->name();
        for (bool partComplete : challenge->complete())
            qDebug() << "\t" << partComplete;
    }*/

    std::shared_ptr<FileIO> tourFile = std::make_shared<FileIO>("C:\\Users\\Adam\\Desktop\\Modding\\Tiger Woods 2013\\Adam Tiburon Open\\Hole 3 Complete\\13-TourEvent0");
    TigerWoods13::TournamentFile tournament(tourFile);

    // sort the golfers by their scores
    QList<TigerWoods13::GolferScoreRecord*> golferScores = tournament.golferScores();
    qSort(golferScores.begin(), golferScores.end(),
          [](TigerWoods13::GolferScoreRecord *a, TigerWoods13::GolferScoreRecord *b) { return a->totalScore() < b->totalScore(); });

    for (auto golfer : golferScores)
        qDebug() << "Index" << golfer->index() << "Score" << golfer->totalScore();

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
