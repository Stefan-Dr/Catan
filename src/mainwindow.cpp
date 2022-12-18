#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "board.h"
#include "node.h"
#include "gui_node.h"
#include "gui_board.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_board(new Board(this))
    , m_dice(new Dice())
{
    ui->setupUi(this);
    ui->rbON->setChecked(true);
    ui->rbSLOW->setChecked(true);

    m_board->setSceneRect(ui->gvMapa->rect());
    ui->gvMapa->setScene(m_board);
    ui->gvMapa->setRenderHint(QPainter::Antialiasing);

    m_board->addAllNodes();
    //m_boardScene->addAllFields(ui->gvBoard->width(), ui->gvBoard->height(),
    //offset);

    //connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::AddNewBlankNode);
    //connect(this, &MainWindow::AddedNewBlankNode, dynamic_cast<Board *>(m_board));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbStartGame_clicked(){
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pbSettings_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pbBackToMenu_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pbBackToMenu_2_clicked(){
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pbHelp_clicked(){
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pbExit_clicked(){
    qApp->exit();
}

void MainWindow::on_pbBackToMenu_3_clicked(){
    ui->lePlayer1->setText("");
    ui->lbPlayer1Required->setText("");
    ui->lePlayer2->setText("");
    ui->lbPlayer2Required->setText("");
    ui->lePlayer3->setText("");
    ui->lbPlayer3Required->setText("");
    ui->lePlayer4->setText("");
    ui->lbPlayer4Required->setText("");
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_pbContinue_clicked(){
    bool con1 = false;
    bool con2 = false;
    bool con3 = false;
    bool con4 = false;
    if ( ui->lePlayer1->text().length() < 3){
        ui->lbPlayer1Required->setText("Name must be at least 3 characters long!");
    }
    else {
       con1 = true;
       ui->lbPlayer1Required->setText("");
    }
    if ( ui->lePlayer2->text().length() < 3){
        ui->lbPlayer2Required->setText("Name must be at least 3 characters long!");
    }
    else {
        con2 = true;
        ui->lbPlayer2Required->setText("");
     }
    if ( ui->lePlayer3->text().length() < 3){
        ui->lbPlayer3Required->setText("Name must be at least 3 characters long!");
    }
    else {
        con3 = true;
        ui->lbPlayer3Required->setText("");
     }
    if ( ui->lePlayer4->text().length() < 3){
        ui->lbPlayer4Required->setText("Name must be at least 3 characters long!");
    }
    else {
        con4 = true;
        ui->lbPlayer4Required->setText("");
     }

    if (con1 && con2 && con3 && con4){
        ui->stackedWidget->setCurrentIndex(4);
    }
}



void MainWindow::on_pbRollDice_clicked()
{
    m_dice->roll_dice();
    int d1 = m_dice->get_dice1();
    int d2 = m_dice->get_dice2();
    switch (d1) {
        case 1 :
            ui->wDice1->setStyleSheet("border-image: url(:/resources/images/dice1.png) 0 0 0 0 stretch stretch;");
            break;
        case 2 :
            ui->wDice1->setStyleSheet("border-image: url(:/resources/images/dice2.png) 0 0 0 0 stretch stretch;");
            break;
        case 3 :
            ui->wDice1->setStyleSheet("border-image: url(:/resources/images/dice3.png) 0 0 0 0 stretch stretch;");
            break;
        case 4 :
            ui->wDice1->setStyleSheet("border-image: url(:/resources/images/dice4.png) 0 0 0 0 stretch stretch;");
            break;
        case 5 :
            ui->wDice1->setStyleSheet("border-image: url(:/resources/images/dice5.png) 0 0 0 0 stretch stretch;");
            break;
        case 6 :
            ui->wDice1->setStyleSheet("border-image: url(:/resources/images/dice6.png) 0 0 0 0 stretch stretch;");
            break;
    }

    switch (d2) {
        case 1 :
            ui->wDice2->setStyleSheet("border-image: url(:/resources/images/dice1.png) 0 0 0 0 stretch stretch;");
            break;
        case 2 :
            ui->wDice2->setStyleSheet("border-image: url(:/resources/images/dice2.png) 0 0 0 0 stretch stretch;");
            break;
        case 3 :
            ui->wDice2->setStyleSheet("border-image: url(:/resources/images/dice3.png) 0 0 0 0 stretch stretch;");
            break;
        case 4 :
            ui->wDice2->setStyleSheet("border-image: url(:/resources/images/dice4.png) 0 0 0 0 stretch stretch;");
            break;
        case 5 :
            ui->wDice2->setStyleSheet("border-image: url(:/resources/images/dice5.png) 0 0 0 0 stretch stretch;");
            break;
        case 6 :
            ui->wDice2->setStyleSheet("border-image: url(:/resources/images/dice6.png) 0 0 0 0 stretch stretch;");
            break;
    }
}

