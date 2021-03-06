#ifndef OVERVIEWPAGE_H
#define OVERVIEWPAGE_H

#include <QWidget>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

namespace Ui {
    class OverviewPage;
}
class WalletModel;
class ClientModel;
class TxViewDelegate;
class TransactionFilterProxy;

/** Overview ("home") page widget */
class OverviewPage : public QWidget
{
    Q_OBJECT

public:
    explicit OverviewPage(QWidget *parent = 0);
    ~OverviewPage();

    void setModel(WalletModel *model);
    void showOutOfSyncWarning(bool fShow);
    bool Staking;
    QString stakingColor;
    QString notstakingColor;

public slots:
    void setBalance(qint64 balance, qint64 stake, qint64 unconfirmedBalance);
    void setStatistics();
    void startStaking();
    void stopStaking();

signals:
    void transactionClicked(const QModelIndex &index);
    void displayUnitChanged(int unit);
    void decimalPointsChanged(int decimals);
    void hideAmountsChanged(bool hideamounts);

private:
    Ui::OverviewPage *ui;
    WalletModel *model;
    ClientModel *clientmodel;
    qint64 currentBalance;
    qint64 currentUnconfirmedBalance;
    qint64 currentStakeBalance;

    TxViewDelegate *txdelegate;
    TransactionFilterProxy *filter;

private slots:
    void updateDisplayUnit();
    void updateDecimalPoints();
    void updateHideAmounts();
    void handleTransactionClicked(const QModelIndex &index);
    void myOpenUrl(QUrl url);
    void sslErrorHandler(QNetworkReply* qnr, const QList<QSslError> & errlist);
    void on_stakeButton_clicked();
};

#endif // OVERVIEWPAGE_H
