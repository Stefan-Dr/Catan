#include "../headers/mainwindow.h"
#include "../headers/board.h"
#include "../headers/game.h"
#include "../headers/gui_node.h"
#include "../headers/node.h"
#include "../headers/resourcetype.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_board(new Board(this)),
      m_dice(new Dice())
      //    , m_music(new QMediaPlayer())
      ,
      m_game(new Game()) {
  ui->setupUi(this);
  ui->rbON->setChecked(true);

  // connect(this,&MainWindow::AddHouse,dynamic_cast<Board*>(m_board),&Board::setHouse);
  // connect(ui->pb_House,&QPushButton::clicked,this,&MainWindow::on_pb_House_clicked);
  // connect(ui->pb_Settlement,&QPushButton::clicked,this,&MainWindow::on_pb_Settlement_clicked);
  // connect(ui->pb_Road,&QPushButton::clicked,this,&MainWindow::on_pb_Road_clicked);
  m_board->setSceneRect(ui->gvMapa->rect());
  ui->gvMapa->setScene(m_board);
  ui->gvMapa->setRenderHint(QPainter::Antialiasing);

  connect(dynamic_cast<Board *>(m_board), &Board::manageResourcesHouse, this,
          &MainWindow::manageResourcesHouse);
  connect(dynamic_cast<Board *>(m_board), &Board::manageResourcesRoad, this,
          &MainWindow::manageResourcesRoad);
  connect(dynamic_cast<Board *>(m_board), &Board::manageResourcesCity, this,
          &MainWindow::manageResourcesCity);
  connect(dynamic_cast<Board *>(m_board), &Board::invalidHouse, this,
          &MainWindow::invalidHouse);
  connect(dynamic_cast<Board *>(m_board), &Board::invalidRoad, this,
          &MainWindow::invalidRoad);
  connect(dynamic_cast<Board *>(m_board), &Board::invalidCity, this,
          &MainWindow::invalidCity);

  // m_music->setMedia(QUrl("qrc:/resources/sounds/background_music.mp3"));
  // m_music->play();
  // m_music->setVolume(10);

  // dodavenje izbora u prvi dropdown meni
  ui->cbTradePlayer->addItem(
      QIcon("qrc:/resources/images/resources--wheat.png"), "Wheat");
  ui->cbTradePlayer->addItem(QIcon("qrc:/resources/images/resources--wool.png"),
                             "Wool");
  ui->cbTradePlayer->addItem(
      QIcon("qrc:/resources/images/resources--stone.png"), "Stone");
  ui->cbTradePlayer->addItem(QIcon("qrc:/resources/images/resources--wood.png"),
                             "Wood");
  ui->cbTradePlayer->addItem(
      QIcon("qrc:/resources/images/resources--brick.png"), "Brick");

  // dodavanje izbora u 2. dropdown meni
  ui->cbTradeBank->addItem(QIcon("qrc:/resources/images/resources--wheat.png"),
                           "Wheat");
  ui->cbTradeBank->addItem(QIcon("qrc:/resources/images/resources--wool.png"),
                           "Wool");
  ui->cbTradeBank->addItem(QIcon("qrc:/resources/images/resources--stone.png"),
                           "Stone");
  ui->cbTradeBank->addItem(QIcon("qrc:/resources/images/resources--wood.png"),
                           "Wood");
  ui->cbTradeBank->addItem(QIcon("qrc:/resources/images/resources--brick.png"),
                           "Brick");

  // m_board->addAllFields();

  // m_boardScene->addAllFields(ui->gvBoard->width(), ui->gvBoard->height(),
  // offset);

  // connect(ui->pushButton_2, &QPushButton::clicked, this,
  // &MainWindow::AddNewBlankNode); connect(this,
  // &MainWindow::AddedNewBlankNode, dynamic_cast<Board *>(m_board));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::displayResources() {
  //    Player *curr_p =  m_game->getCurrentPlayer();
  //    if ( curr_p->get_id() == 1){
  //        ui->lbWheatP1->setText(QString::number((curr_p->get_num_of_wheat())));
  //        ui->lbWoodP1->setText(QString::number(curr_p->get_num_of_wood()));
  //        ui->lbBrickP1->setText(QString::number(curr_p->get_num_of_brick()));
  //        ui->lbWoolP1->setText(QString::number(curr_p->get_num_of_wool()));
  //        ui->lbStoneP1->setText(QString::number(curr_p->get_num_of_stone()));
  //    }
  //    if ( curr_p->get_id() == 2){
  //        ui->lbWheatP2->setText((QString::number(curr_p->get_num_of_wheat())));
  //        ui->lbWoodP2->setText((QString::number(curr_p->get_num_of_wood())));
  //        ui->lbBrickP2->setText((QString::number(curr_p->get_num_of_brick())));
  //        ui->lbWoolP2->setText((QString::number(curr_p->get_num_of_wool())));
  //        ui->lbStoneP2->setText((QString::number(curr_p->get_num_of_stone())));
  //    }
  //    if ( curr_p->get_id() == 3){
  //        ui->lbWheatP3->setText(QString::number((curr_p->get_num_of_wheat())));
  //        ui->lbWoodP3->setText(QString::number(curr_p->get_num_of_wood()));
  //        ui->lbBrickP3->setText(QString::number(curr_p->get_num_of_brick()));
  //        ui->lbWoolP3->setText(QString::number(curr_p->get_num_of_wool()));
  //        ui->lbStoneP3->setText(QString::number(curr_p->get_num_of_stone()));
  //    }
  //    if ( curr_p->get_id() == 4){
  //        ui->lbWheatP4->setText(QString::number((curr_p->get_num_of_wheat())));
  //        ui->lbWoodP4->setText(QString::number(curr_p->get_num_of_wood()));
  //        ui->lbBrickP4->setText(QString::number(curr_p->get_num_of_brick()));
  //        ui->lbWoolP4->setText(QString::number(curr_p->get_num_of_wool()));
  //        ui->lbStoneP4->setText(QString::number(curr_p->get_num_of_stone()));
  //    }

  // drugaciji nacin implementacije
  ui->lbWheatP1->setText(
      QString::number(m_game->getPlayer1()->get_num_of_wheat()));
  ui->lbWoodP1->setText(
      QString::number(m_game->getPlayer1()->get_num_of_wood()));
  ui->lbBrickP1->setText(
      QString::number(m_game->getPlayer1()->get_num_of_brick()));
  ui->lbWoolP1->setText(
      QString::number(m_game->getPlayer1()->get_num_of_wool()));
  ui->lbStoneP1->setText(
      QString::number(m_game->getPlayer1()->get_num_of_stone()));

  ui->lbWheatP2->setText(
      QString::number(m_game->getPlayer2()->get_num_of_wheat()));
  ui->lbWoodP2->setText(
      QString::number(m_game->getPlayer2()->get_num_of_wood()));
  ui->lbBrickP2->setText(
      QString::number(m_game->getPlayer2()->get_num_of_brick()));
  ui->lbWoolP2->setText(
      QString::number(m_game->getPlayer2()->get_num_of_wool()));
  ui->lbStoneP2->setText(
      QString::number(m_game->getPlayer2()->get_num_of_stone()));

  ui->lbWheatP3->setText(
      QString::number(m_game->getPlayer3()->get_num_of_wheat()));
  ui->lbWoodP3->setText(
      QString::number(m_game->getPlayer3()->get_num_of_wood()));
  ui->lbBrickP3->setText(
      QString::number(m_game->getPlayer3()->get_num_of_brick()));
  ui->lbWoolP3->setText(
      QString::number(m_game->getPlayer3()->get_num_of_wool()));
  ui->lbStoneP3->setText(
      QString::number(m_game->getPlayer3()->get_num_of_stone()));

  ui->lbWheatP4->setText(
      QString::number(m_game->getPlayer4()->get_num_of_wheat()));
  ui->lbWoodP4->setText(
      QString::number(m_game->getPlayer4()->get_num_of_wood()));
  ui->lbBrickP4->setText(
      QString::number(m_game->getPlayer4()->get_num_of_brick()));
  ui->lbWoolP4->setText(
      QString::number(m_game->getPlayer4()->get_num_of_wool()));
  ui->lbStoneP4->setText(
      QString::number(m_game->getPlayer4()->get_num_of_stone()));
}

void MainWindow::displayBankResources() {
  Bank *bank = m_game->getBank();

  ui->lbBrickBank->setText(QString::number(bank->get_num_of_brick_from_bank()));
  ui->lbStoneBank->setText(QString::number(bank->get_num_of_stone_from_bank()));
  ui->lbWheatBank->setText(QString::number(bank->get_num_of_wheat_from_bank()));
  ui->lbWoodBank->setText(QString::number(bank->get_num_of_wood_from_bank()));
  ui->lbWoolBank->setText(QString::number(bank->get_num_of_wool_from_bank()));
}

void MainWindow::displayPlayerPoints() {
  ui->lbPointsPlayer1->setText(
      QString::number(m_game->getPlayer1()->get_victory_points()));
  ui->lbPointsPlayer2->setText(
      QString::number(m_game->getPlayer2()->get_victory_points()));
  ui->lbPointsPlayer3->setText(
      QString::number(m_game->getPlayer3()->get_victory_points()));
  ui->lbPointsPlayer4->setText(
      QString::number(m_game->getPlayer4()->get_victory_points()));
}

void MainWindow::displayPlayerRoads() {
  ui->lbRoadsPlayer1->setText(
      QString::number(m_game->getPlayer1()->get_num_of_roads()));
  ui->lbRoadsPlayer2->setText(
      QString::number(m_game->getPlayer2()->get_num_of_roads()));
  ui->lbRoadsPlayer3->setText(
      QString::number(m_game->getPlayer3()->get_num_of_roads()));
  ui->lbRoadsPlayer4->setText(
      QString::number(m_game->getPlayer4()->get_num_of_roads()));
}

void MainWindow::on_pbStartGame_clicked() {
  ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pbSettings_clicked() {
  ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pbBackToMenu_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pbBackToMenu_2_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pbHelp_clicked() { ui->stackedWidget->setCurrentIndex(2); }

void MainWindow::on_pbExit_clicked() { qApp->exit(); }

void MainWindow::on_pbBackToMenu_3_clicked() {
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

void MainWindow::on_pbContinue_clicked() {
  bool con1 = false;
  bool con2 = false;
  bool con3 = false;
  bool con4 = false;
  if (ui->lePlayer1->text().length() < 2 ||
      ui->lePlayer1->text().length() > 13) {
    ui->lbPlayer1Required->setText("Name length must be within 2-13 letters!");
  } else {
    con1 = true;
    ui->lbPlayer1Required->setText("");
  }
  if (ui->lePlayer2->text().length() < 2 ||
      ui->lePlayer2->text().length() > 13) {
    ui->lbPlayer2Required->setText("Name length must be within 2-13 letters!");
  } else {
    con2 = true;
    ui->lbPlayer2Required->setText("");
  }
  if (ui->lePlayer3->text().length() < 2 ||
      ui->lePlayer3->text().length() > 13) {
    ui->lbPlayer3Required->setText("Name length must be within 2-13 letters!");
  } else {
    con3 = true;
    ui->lbPlayer3Required->setText("");
  }
  if (ui->lePlayer4->text().length() < 2 ||
      ui->lePlayer4->text().length() > 13) {
    ui->lbPlayer4Required->setText("Name length must be within 2-13 letters!");
  } else {
    con4 = true;
    ui->lbPlayer4Required->setText("");
  }

  if (con1 && con2 && con3 && con4) {
    ui->lbPlayer1Name->setText(ui->lePlayer1->text());
    m_game->getPlayer1()->set_name(ui->lePlayer1->text().toStdString());
    ui->lbPlayer2Name->setText(ui->lePlayer2->text());
    m_game->getPlayer2()->set_name(ui->lePlayer2->text().toStdString());
    ui->lbPlayer3Name->setText(ui->lePlayer3->text());
    m_game->getPlayer3()->set_name(ui->lePlayer3->text().toStdString());
    ui->lbPlayer4Name->setText(ui->lePlayer4->text());
    m_game->getPlayer4()->set_name(ui->lePlayer4->text().toStdString());
    ui->stackedWidget->setCurrentIndex(4);
    m_board->setRoadColor(m_game->getCurrentPlayer()->get_player_color());
    m_board->addAllFields();
    // za svakog playera predstavljamo koliko resursa ima na pocetku
    displayResources();
    ui->lbPlayerTurn->setText(
        QString::fromStdString(m_game->getCurrentPlayer()->get_name()));
    //        m_game->nextPlayer();
    //        displayResources();
    //        m_game->nextPlayer();
    //        displayResources();
    //        m_game->nextPlayer();
    //        displayResources();
    //        m_game->nextPlayer();

    displayBankResources();
    displayPlayerPoints();
    displayPlayerRoads();
  }
}

void MainWindow::on_pbRollDice_clicked() {
  // if(korisnik je opet klinuo na dugme za bacanje kockice)
  if (m_dice->get_button_clicked() == true) {
    QMessageBox msgBox;
    msgBox.setText("Dice already rolled!");
    msgBox.exec();
  } else {
    m_dice->roll_dice();
    m_dice->set_button_is_clicked(true);
    m_dice->set_dice_is_rolled(true);

    int result = m_dice->get_dice_sum();
    m_game->Turn(result, m_board);

    displayResources();
    displayBankResources();

    int d1 = m_dice->get_dice1();
    int d2 = m_dice->get_dice2();
    switch (d1) {
    case 1:
      ui->wDice1->setStyleSheet(
          "border-image: url(:/resources/images/dice1.png) 0 0 0 0 stretch "
          "stretch;");
      break;
    case 2:
      ui->wDice1->setStyleSheet(
          "border-image: url(:/resources/images/dice2.png) 0 0 0 0 stretch "
          "stretch;");
      break;
    case 3:
      ui->wDice1->setStyleSheet(
          "border-image: url(:/resources/images/dice3.png) 0 0 0 0 stretch "
          "stretch;");
      break;
    case 4:
      ui->wDice1->setStyleSheet(
          "border-image: url(:/resources/images/dice4.png) 0 0 0 0 stretch "
          "stretch;");
      break;
    case 5:
      ui->wDice1->setStyleSheet(
          "border-image: url(:/resources/images/dice5.png) 0 0 0 0 stretch "
          "stretch;");
      break;
    case 6:
      ui->wDice1->setStyleSheet(
          "border-image: url(:/resources/images/dice6.png) 0 0 0 0 stretch "
          "stretch;");
      break;
    }

    switch (d2) {
    case 1:
      ui->wDice2->setStyleSheet(
          "border-image: url(:/resources/images/dice1.png) 0 0 0 0 stretch "
          "stretch;");
      break;
    case 2:
      ui->wDice2->setStyleSheet(
          "border-image: url(:/resources/images/dice2.png) 0 0 0 0 stretch "
          "stretch;");
      break;
    case 3:
      ui->wDice2->setStyleSheet(
          "border-image: url(:/resources/images/dice3.png) 0 0 0 0 stretch "
          "stretch;");
      break;
    case 4:
      ui->wDice2->setStyleSheet(
          "border-image: url(:/resources/images/dice4.png) 0 0 0 0 stretch "
          "stretch;");
      break;
    case 5:
      ui->wDice2->setStyleSheet(
          "border-image: url(:/resources/images/dice5.png) 0 0 0 0 stretch "
          "stretch;");
      break;
    case 6:
      ui->wDice2->setStyleSheet(
          "border-image: url(:/resources/images/dice6.png) 0 0 0 0 stretch "
          "stretch;");
      break;
    }
  }
}

void MainWindow::on_rbON_toggled(bool checked) {
  // if ( checked ) { m_music->play(); }
}

void MainWindow::on_rbOFF_toggled(bool checked) {
  // if ( checked ) { m_music->stop(); }
}

void MainWindow::on_pb_House_clicked() {
  if (m_dice->get_dice_is_rolled() == true) {
    if (m_game->can_build_house()) {
      m_board->m_setHouse = true;
      m_board->m_setRoad = false;
      m_board->m_setCity = false;
      // m_game->BuildHouse();
      m_board->setCurrColor(m_game->getCurrentPlayer()->get_player_color());
      //            displayResources();
      //            displayBankResources();
      //            displayPlayerPoints();
      //            ui->lbError->setText("");
      // m_game->getCurrentPlayer()->increase_victory_points(1);
    } else {
      m_board->m_setHouse = false;
      m_board->m_setRoad = false;
      m_board->m_setCity = false;

      QMessageBox msgBox;
      msgBox.setText("Not enough resources for a house!");
      msgBox.exec();
    }
  } else {

    QMessageBox msgBox;
    msgBox.setText("You must first roll dice!");
    msgBox.exec();
  }
}

void MainWindow::manageResourcesHouse() {
  m_game->BuildHouse();
  displayResources();
  displayBankResources();
  displayPlayerPoints();
  if (m_game->win()) {
    QMessageBox msgBox;
    msgBox.setText(
        "CONGRATS " +
        QString::fromStdString(m_game->getCurrentPlayer()->get_name()) +
        ", YOU WON");
    int ret = msgBox.exec();
    if (ret == QMessageBox::Ok) {
      qApp->exit();
    }
  } else {
    houseBuilt();
  }
}

void MainWindow::houseBuilt() {
  //    QMessageBox msgBox;
  //    msgBox.setText("You have successfully built a house!");
  //    msgBox.exec();
}

void MainWindow::invalidHouse() {
  QMessageBox msgBox;
  msgBox.setText("Invalid house placement!");
  msgBox.exec();
}

void MainWindow::on_pb_Road_clicked() {
  if (m_dice->get_dice_is_rolled() == true) {
    if (m_game->can_build_road()) {
      m_board->m_setRoad = true;
      m_board->m_setCity = false;
      m_board->m_setHouse = false;
      //            m_game->BuildRoad();
      //            displayResources();
      //            displayBankResources();
      //            displayPlayerPoints();
      //            displayPlayerRoads();
      //            ui->lbError->setText("");
      // m_game->getCurrentPlayer()->increase_num_of_roads();
    } else {
      m_board->m_setHouse = false;
      m_board->m_setRoad = false;
      m_board->m_setCity = false;

      QMessageBox msgBox;
      msgBox.setText("Not enough resources for a road!");
      msgBox.exec();
    }
  } else {

    QMessageBox msgBox;
    msgBox.setText("You must first roll dice!");
    msgBox.exec();
  }
}

void MainWindow::manageResourcesRoad() {
  m_game->BuildRoad();
  displayResources();
  displayBankResources();
  displayPlayerPoints();
  displayPlayerRoads();
  if (m_game->win()) {
    QMessageBox msgBox;
    msgBox.setText(
        "CONGRATS " +
        QString::fromStdString(m_game->getCurrentPlayer()->get_name()) +
        ", YOU WON");
    int ret = msgBox.exec();
    if (ret == QMessageBox::Ok) {
      qApp->exit();
    }
  } else {
    roadBuilt();
  }
}

void MainWindow::roadBuilt() {
  //    QMessageBox msgBox;
  //    msgBox.setText("You have successfully built a road!");
  //    msgBox.exec();
}

void MainWindow::invalidRoad() {
  QMessageBox msgBox;
  msgBox.setText("Invalid road placement!");
  msgBox.exec();
}

void MainWindow::on_pb_Settlement_clicked() {
  if (m_dice->get_dice_is_rolled() == true) {
    if (m_game->can_build_city()) {
      m_board->m_setCity = true;
      m_board->m_setHouse = false;
      m_board->m_setRoad = false;
      //            m_game->BuildCity();
      m_board->setCurrColor(m_game->getCurrentPlayer()->get_city_color());
      //            displayResources();
      //            displayBankResources();
      //            displayPlayerPoints();
      //            ui->lbError->setText("");
      // m_game->getCurrentPlayer()->decrease_victory_point();
      // m_game->getCurrentPlayer()->increase_victory_points(2);
    } else {
      m_board->m_setHouse = false;
      m_board->m_setRoad = false;
      m_board->m_setCity = false;

      QMessageBox msgBox;
      msgBox.setText("Not enough resources for a city!");
      msgBox.exec();
    }
  } else {

    QMessageBox msgBox;
    msgBox.setText("You must first roll dice!");
    msgBox.exec();
  }
}

void MainWindow::on_pb_MagicCard_clicked() {
  if (m_dice->get_dice_is_rolled() == true) {
    if (m_game->can_get_magic_card()) {
      m_board->m_setCity = false;
      m_board->m_setHouse = false;
      m_board->m_setRoad = false;
      m_game->MagicCard();
      displayResources();
      displayBankResources();
      displayPlayerPoints();
      if (m_game->win()) {
        QMessageBox msgBox;
        msgBox.setText(
            "CONGRATS " +
            QString::fromStdString(m_game->getCurrentPlayer()->get_name()) +
            ", YOU WON");
        int ret = msgBox.exec();
        if (ret == QMessageBox::Ok) {
          qApp->exit();
        }
      } else {
        magicCardDrawn();
      }

    } else {
      m_board->m_setHouse = false;
      m_board->m_setRoad = false;
      m_board->m_setCity = false;

      QMessageBox msgBox;
      msgBox.setText("Not enough resources for a magic card!");
      msgBox.exec();
    }
  } else {
    QMessageBox msgBox;
    msgBox.setText("You must first roll dice!");
    msgBox.exec();
  }
}

void MainWindow::manageResourcesCity() {
  m_game->BuildCity();
  displayResources();
  displayBankResources();
  displayPlayerPoints();
  if (m_game->win()) {
    QMessageBox msgBox;
    msgBox.setText(
        "CONGRATS " +
        QString::fromStdString(m_game->getCurrentPlayer()->get_name()) +
        ", YOU WON");
    int ret = msgBox.exec();
    if (ret == QMessageBox::Ok) {
      qApp->exit();
    }
  } else {
    cityBuilt();
  }
}

void MainWindow::cityBuilt() {
  //    QMessageBox msgBox;
  //    msgBox.setText("You have successfully built a city!");
  //    msgBox.exec();
}

void MainWindow::invalidCity() {
  QMessageBox msgBox;
  msgBox.setText("Invalid city placement!");
  msgBox.exec();
}

// Next player button
void MainWindow::on_pushButton_clicked() {

  m_game->nextPlayer();
  if (m_game->player_turn_counter < 4) {
    m_game->player_turn_counter++;
  } else {
    m_board->set_first_turn(false);
  }
  ui->lbPlayerTurn->setText(
      QString::fromStdString(m_game->getCurrentPlayer()->get_name()));
  m_board->m_setHouse = false;
  m_board->m_setRoad = false;
  m_board->m_setCity = false;
  m_board->setCurrColor(m_game->getCurrentPlayer()->get_player_color());
  m_board->setRoadColor(m_game->getCurrentPlayer()->get_player_color());

  m_dice->set_button_is_clicked(false);
  m_dice->set_dice_is_rolled(false);
}

void MainWindow::on_pbTrade_clicked() {
  m_board->m_setHouse = false;
  m_board->m_setRoad = false;
  m_board->m_setCity = false;
  if (m_dice->get_dice_is_rolled() == true) {
    ResourceType player_resource = ResourceType::Wheat;
    ResourceType bank_resource = ResourceType::Wheat;
    int player_index = ui->cbTradePlayer->currentIndex();
    int bank_index = ui->cbTradeBank->currentIndex();
    // proveravamo sta je igrac odabrao za svoj resurs
    if (player_index == 0) {
      player_resource = ResourceType::Wheat;
    }
    if (player_index == 1) {
      player_resource = ResourceType::Wool;
    }
    if (player_index == 2) {
      player_resource = ResourceType::Stone;
    }
    if (player_index == 3) {
      player_resource = ResourceType::Wood;
    }
    if (player_index == 4) {
      player_resource = ResourceType::Brick;
    }
    // proveravamo sta je igrac odabrao za resurs banke
    if (bank_index == 0) {
      bank_resource = ResourceType::Wheat;
    }
    if (bank_index == 1) {
      bank_resource = ResourceType::Wool;
    }
    if (bank_index == 2) {
      bank_resource = ResourceType::Stone;
    }
    if (bank_index == 3) {
      bank_resource = ResourceType::Wood;
    }
    if (bank_index == 4) {
      bank_resource = ResourceType::Brick;
    }

    if (m_game->can_trade_with_bank(player_resource, bank_resource)) {
      m_game->trade_with_bank(player_resource, bank_resource);
      displayResources();
      displayBankResources();
      tradeSuccessfull();
    } else {
      QMessageBox msgBox;
      msgBox.setText(
          "Not enough resources form a player or in bank for procceding!");
      msgBox.exec();
    }

  } else {
    QMessageBox msgBox;
    msgBox.setText("You must first roll dice!");
    msgBox.exec();
  }
}

void MainWindow::tradeSuccessfull() {
  QMessageBox msgBox;
  msgBox.setText("Trade successfull!");
  msgBox.exec();
}

void MainWindow::magicCardDrawn() {
  QMessageBox msgBox;
  msgBox.setText("You have successfully drawn a magic card!");
  msgBox.exec();
}
