#include "mywindow.h"
#include "ui_mywindow.h"
#include <QMessageBox>

MyWindow::MyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyWindow)
{
    ui->setupUi(this);

    // Sets which "stackwidget" page to start on when program starts
    ui->stackedWidget->setCurrentIndex(0);
}

MyWindow::~MyWindow()
{
    delete ui;
}


// LOGIN PAGE
void MyWindow::on_pushButton_clicked()
{
    // Define strings to rep user/pw
    QString  username = ui->usernameLE->text();
    QString  password = ui->passwordLE->text();

    if(username=="admin" && password=="admin")
    {
        //Clear username and password
      ui->usernameLE->clear();
      ui->passwordLE->clear();

      // Go to page meant for actor
      ui->stackedWidget->setCurrentIndex(3);
    }
    else if (username=="student" && password=="student")
    {
        ui->usernameLE->clear();
        ui->passwordLE->clear();

        ui->stackedWidget->setCurrentIndex(1);
    }
    else if (username=="teacher" && password=="teacher")
    {
        ui->usernameLE->clear();
        ui->passwordLE->clear();

        ui->stackedWidget->setCurrentIndex(2);
    }
    else
    {
        //Clear username and password
      ui->usernameLE->clear();
      ui->passwordLE->clear();

      //Display Wrong U/PW Box
        QMessageBox::warning(this,"Login", "Incorrect Username or Password");
    }
}



// STUDENT PAGE
void MyWindow::on_logout_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//Teacher Page
void MyWindow::on_logout_button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//Admin Page
void MyWindow::on_logout_button_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
