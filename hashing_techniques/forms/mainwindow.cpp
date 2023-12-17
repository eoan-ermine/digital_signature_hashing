#include "mainwindow.hpp"

#include "hashing.hpp"

MainWindowForm::MainWindowForm(QWidget *parent) : QMainWindow(parent) {
    ui.setupUi(this);

    QObject::connect(ui.hashButton, &QPushButton::clicked, this, [this]() {
        auto res = controlSum(ui.textEdit->text(), {.max = ui.cEdit->text().toLongLong() - 1});
        ui.hashLabel->setText(QString::number(res));
    });
    QObject::connect(ui.gammaButton, &QPushButton::clicked, this, [this]() {
        auto res = gammaSum(ui.textEdit->text(), {
                .a = ui.aEdit->text().toLongLong(),
                .b = ui.bEdit->text().toLongLong(),
                .c = ui.cEdit->text().toLongLong(),
                .t = ui.tEdit->text().toLongLong()
        });
        ui.gammaLabel->setText(QString::number(res));
    });
}