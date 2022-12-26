#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "board.h"
#include "node.h"

#include "gui_node.h"
#include <QMainWindow>
#include <QGraphicsItem>
#include <QWidget>
#include "dice.h"
#include "game.h"
//#include <QMediaPlayer>
class QGraphicsScene;
class Node;
class GUI_Node;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addAllNodes();
    void displayResources();
    void displayBankResources();

signals:
    void AddedNewBlankNode(GUI_Node *node);
    void AddHouse();
private slots:

    void on_pbStartGame_clicked();
    void on_pbSettings_clicked();
    void on_pbBackToMenu_clicked();
    void on_pbBackToMenu_2_clicked();
    void on_pbHelp_clicked();
    void on_pbExit_clicked();
    void on_pbContinue_clicked();
    void on_pbBackToMenu_3_clicked();


    void on_pbRollDice_clicked();

    void on_rbON_toggled(bool checked);

    void on_rbOFF_toggled(bool checked);

    void on_pb_House_clicked();

    void on_pb_Road_clicked();

    void on_pb_Settlement_clicked();

    void on_pushButton_clicked();

protected:
    Ui::MainWindow *ui;
    Board *m_board;
    Dice *m_dice;
    //QMediaPlayer *m_music;
    Game *m_game;
};
#endif // MAINWINDOW_H
