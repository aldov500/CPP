#ifndef WIN_ERROR_H
#define WIN_ERROR_H

#include <QDialog>

namespace Ui {
class Win_Error;
}

class Win_Error : public QDialog
{
    Q_OBJECT

public:
    explicit Win_Error(QWidget *parent = nullptr);
    ~Win_Error();

    void setErrorMessage(QString sMessage);

private:
    QString sErrorMessage;

private slots:
    void on_BTN_Accept_clicked();

private:
    Ui::Win_Error *ui;
};

#endif // WIN_ERROR_H
