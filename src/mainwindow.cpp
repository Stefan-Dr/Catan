#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "board.h"
#include "node.h"
#include "gui_node.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_board(new Board(this))
{
    ui->setupUi(this);
    ui->rbON->setChecked(true);
    ui->rbSLOW->setChecked(true);

    m_board->setSceneRect(ui->graphicsView->rect());
    ui->graphicsView->setScene(m_board);

    connect(ui->pbContinue, &QPushButton::clicked, this, &MainWindow::AddNewBlankNode);
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
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::AddNewBlankNode()
{
    const auto node = new Node(1);

    const auto guiNode = new GUI_Node(node);
    m_board->addItem(guiNode);
}

void MainWindow::on_pbContinue_clicked(){
    ui->stackedWidget->setCurrentIndex(4);
}


