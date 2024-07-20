#include "dbparamsdialog.h"
#include "ui_dbparamsdialog.h"

DbParamsDialog::DbParamsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DbParamsDialog)
{
    ui->setupUi(this);
}

DbParamsDialog::~DbParamsDialog()
{
    delete ui;
}
