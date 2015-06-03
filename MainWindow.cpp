#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), m_userFile(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    try
    {
        QString filePath = QFileDialog::getOpenFileName(this, "Find your 13-User-XXX file");
        if (filePath.length() == 0)
            return;

        // parse the user file
        std::shared_ptr<FileIO> userFileIO = std::make_shared<FileIO>(filePath.toStdString());
        m_userFile = new TigerWoodsUserFile(userFileIO, this);

        // update the GUI
        ui->spnXpEarned->setValue(m_userFile->xpEarned());
        ui->spnXpSpent->setValue(m_userFile->xpSpent());
        ui->spnXpBalance->setValue(m_userFile->xpEarned() - m_userFile->xpSpent());
        ui->spnPower->setValue(m_userFile->power());
        ui->spnAccuracy->setValue(m_userFile->accuracy());
        ui->spnWorkability->setValue(m_userFile->workability());
        ui->spnSpin->setValue(m_userFile->spin());
        ui->spnRecovery->setValue(m_userFile->recovery());
        ui->spnPutting->setValue(m_userFile->putting());
        ui->spnRoundsPlayed->setValue(m_userFile->roundsPlayed());
        ui->spnTotalScore->setValue(m_userFile->totalScore());
        ui->spnAverageScore->setValue(m_userFile->averageScore());
        ui->spnPuttsMade->setValue(m_userFile->madePutts());
        ui->spnPuttsTotal->setValue(m_userFile->totalPutts());
        ui->spnTotalDrives->setValue(m_userFile->totalDrives());
        ui->spnTotalYardsDriven->setValue(m_userFile->totalYardsDriven());
        ui->spnFIROpportunities->setValue(m_userFile->totalFIRAttempts());
        ui->spnFIRs->setValue(m_userFile->totalFIRs());
        ui->spnGIROpportunities->setValue(m_userFile->totalGIRAttempts());
        ui->spnGIRs->setValue(m_userFile->totalGIRs());
        ui->spnLongestDrive->setValue(m_userFile->longestDrive());
        ui->spnLongestPutt->setValue(m_userFile->longestPutt());
        ui->spnHolesInOne->setValue(m_userFile->holesInOne());
        ui->spnDoubleEagles->setValue(m_userFile->doubleEagles());
        ui->spnEagles->setValue(m_userFile->eagles());
        ui->spnBirdies->setValue(m_userFile->birdies());
        ui->spnPars->setValue(m_userFile->pars());
        ui->spnBogeys->setValue(m_userFile->bogeys());
        ui->spnDoubleBogeys->setValue(m_userFile->doubleBogeys());

        // enable the GUI elements
        QList<QSpinBox*> spinboxes = ui->tabUser->findChildren<QSpinBox*>(QRegularExpression("spn.+"));
        for (QSpinBox *spinBox : spinboxes)
            spinBox->setEnabled(true);

        // display the user file tab
        ui->tabWidget->setCurrentIndex(0);

    }
    catch (std::string s)
    {
        QMessageBox::critical(this, "Error", QString("An error occurred while reading the user file.\n") + QString::fromStdString(s));
    }
}

void MainWindow::on_actionOpen_Progress_File_triggered()
{
    try
    {
        QString filePath = QFileDialog::getOpenFileName(this, "Find your 13-Progress file");
        if (filePath.length() == 0)
            return;

        // parse the user file
        std::shared_ptr<FileIO> userFileIO = std::make_shared<FileIO>(filePath.toStdString());
        m_progressFile = new TigerWoodsProgressFile(userFileIO, this);

        // populate the tree widget with the legacy progress
        QString prevChallengeSection = "";
        QTreeWidgetItem *curSectionItem = nullptr;
        for (TigerWoodsTigerLegacyChallenge *challenge : m_progressFile->legacyChallenges())
        {
            // check to see if we need to create another section item
            if (challenge->section() != prevChallengeSection)
            {
                prevChallengeSection = challenge->section();

                // create a tree widget item for the legacy challenge section
                curSectionItem = new QTreeWidgetItem(ui->treeLegacyChallenges);
                curSectionItem->setText(0, challenge->section());
                curSectionItem->setExpanded(true);
                ui->treeLegacyChallenges->addTopLevelItem(curSectionItem);
            }

            // create a tree widget item for the challenge
            QTreeWidgetItem *challengeItem = new QTreeWidgetItem(curSectionItem);
            challengeItem->setText(0, challenge->name());
            challengeItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable);

            // the item should be checked if the challenge is fully completed
            Qt::CheckState checkState = (challenge->fullyComplete()) ? Qt::Checked : Qt::Unchecked;
            challengeItem->setCheckState(0, checkState);
        }

        // enable the necessary widgets
        ui->treeLegacyChallenges->setEnabled(true);
        ui->tabWidget->setCurrentIndex(1);
    }
    catch (std::string s)
    {
        QMessageBox::critical(this, "Error", QString("An error occurred while reading the progress file.\n") + QString::fromStdString(s));
    }
}
