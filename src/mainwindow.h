#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "board.h"
#include "node.h"
#include "gui_board.h"
#include "gui_node.h"
#include <QMainWindow>
#include <QGraphicsItem>
#include <QWidget>
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

signals:
    void AddedNewBlankNode(GUI_Node *node);

private slots:

    void on_pbStartGame_clicked();
    void on_pbSettings_clicked();
    void on_pbBackToMenu_clicked();
    void on_pbBackToMenu_2_clicked();
    void on_pbHelp_clicked();
    void on_pbExit_clicked();
    void on_pbContinue_clicked();
    void on_pbBackToMenu_3_clicked();


protected:
    Ui::MainWindow *ui;
    GUI_Board *m_board;


};
#endif // MAINWINDOW_H
