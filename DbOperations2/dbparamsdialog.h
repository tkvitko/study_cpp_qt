#ifndef DBPARAMSDIALOG_H
#define DBPARAMSDIALOG_H

#include <QDialog>

namespace Ui {
class DbParamsDialog;
}

class DbParamsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DbParamsDialog(QWidget *parent = nullptr);
    ~DbParamsDialog();

private:
    Ui::DbParamsDialog *ui;
};

#endif // DBPARAMSDIALOG_H
