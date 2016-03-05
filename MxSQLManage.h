#ifndef SQLITE
#define SQLITE

#include <QObject>
#include <QSqlDatabase>
#include <QSqlTableModel>

class sqlite:public QObject
{
    Q_OBJECT
public:
    static sqlite* getInstance();
    bool checkingUP(QWidget *parent, QString username, QString password);//ºÏ≤‚’À∫≈∫Õ√‹¬Î
    void insertKey(int key);
    bool searchKey(QString &name, int& key);

private:
    sqlite(QWidget* parent=0);
    sqlite(const sqlite&)Q_DECL_EQ_DELETE;
    sqlite& operator =(sqlite sql)Q_DECL_EQ_DELETE;
    QSqlDatabase mDataBase;
    QSqlTableModel* mModel;


};

#endif // SQLITE

