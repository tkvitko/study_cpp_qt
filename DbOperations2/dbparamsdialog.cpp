#include "dbparamsdialog.h"
#include "ui_dbparamsdialog.h"

DbParamsDialog::DbParamsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DbParamsDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("DB params");
    ui->le_host->setFocus();
}

DbParamsDialog::~DbParamsDialog()
{
    delete ui;
}
