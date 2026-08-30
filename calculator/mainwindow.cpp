#include "mainwindow.h"
#include "ui_mainwindow.h"


//КОНСТРУТОР И ДЕСТРУКТОР

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->l_result->setText("0");
    ui->l_memory->setText("");
    ui->l_formula->setText("");
}

MainWindow::~MainWindow() {
    delete ui;
}

//МЕТОДЫ КЛАССА

void MainWindow::SetInputText(const std::string &text){
    ui->l_result->setStyleSheet("");
    ui->l_result->setText(QString::fromStdString(text));
}

void MainWindow::SetErrorText(const std::string &text){
    ui->l_result->setText(QString::fromStdString(text));
    ui->l_result->setStyleSheet("color: Red;");
}

void MainWindow::SetFormulaText(const std::string &text){
    ui->l_formula->setText(QString::fromStdString(text));
}

void MainWindow::SetMemText(const std::string &text){
    ui->l_memory->setText(QString::fromStdString(text));
}

void MainWindow::SetExtraKey(const std::optional<std::string> &key){
    if(key == std::nullopt){
        ui->tb_extra->setVisible(false);
    }
    else{
        ui->tb_extra->setVisible(true);
        ui->tb_extra->setText(QString::fromStdString(key.value()));
    }
}

void MainWindow::SetDigitKeyCallback(std::function<void (int)> cb){
    digit_cb_ = cb;
}

void MainWindow::SetProcessOperationKeyCallback(std::function<void (Operation)> cb){
    operation_cb_ = cb;
}

void MainWindow::SetProcessControlKeyCallback(std::function<void (ControlKey)> cb){
    control_cb_ = cb;
}

void MainWindow::SetControllerCallback(std::function<void (ControllerType)> cb){
    controller_cb_ = cb;
}


//СЛОТЫ


void MainWindow::on_tb_one_clicked(){
    digit_cb_(1);
}

void MainWindow::on_tb_two_clicked(){
    digit_cb_(2);
}

void MainWindow::on_tb_three_clicked(){
    digit_cb_(3);
}

void MainWindow::on_tb_four_clicked(){
    digit_cb_(4);
}

void MainWindow::on_tb_five_clicked(){
    digit_cb_(5);
}

void MainWindow::on_tb_six_clicked(){
    digit_cb_(6);
}

void MainWindow::on_tb_seven_clicked(){
    digit_cb_(7);
}

void MainWindow::on_tb_eight_clicked(){
    digit_cb_(8);
}

void MainWindow::on_tb_nine_clicked(){
    digit_cb_(9);
}
void MainWindow::on_tb_zero_clicked(){
    digit_cb_(0);
}


void MainWindow::on_tb_add_clicked(){
    operation_cb_(Operation::ADDITION);
}


void MainWindow::on_tb_substract_clicked(){
    operation_cb_(Operation::SUBTRACTION);
}


void MainWindow::on_tb_multiplicate_clicked(){
    operation_cb_(Operation::MULTIPLICATION);
}


void MainWindow::on_tb_divide_clicked(){
    operation_cb_(Operation::DIVISION);
}


void MainWindow::on_tb_power_clicked(){
    operation_cb_(Operation::POWER);
}


void MainWindow::on_tb_extra_clicked(){
    control_cb_(ControlKey::EXTRA_KEY);
}


void MainWindow::on_tb_negate_clicked(){
    control_cb_(ControlKey::PLUS_MINUS);
}


void MainWindow::on_tb_backspace_clicked(){
    control_cb_(ControlKey::BACKSPACE);
}


void MainWindow::on_tb_equal_clicked(){
    control_cb_(ControlKey::EQUALS);
}


void MainWindow::on_tb_reset_clicked(){
    control_cb_(ControlKey::CLEAR);
}


void MainWindow::on_tb_ms_clicked(){
    control_cb_(ControlKey::MEM_SAVE);
}



void MainWindow::on_tb_mc_clicked(){
    control_cb_(ControlKey::MEM_CLEAR);
}


void MainWindow::on_tn_mr_clicked(){
    control_cb_(ControlKey::MEM_LOAD);
}

void MainWindow::on_cmb_controller_currentIndexChanged(int)
{
    controller_cb_(FromString(ui->cmb_controller->currentText()));
}
