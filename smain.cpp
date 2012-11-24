// See: http://www.wiki.crossplatform.ru/index.php/%D0%9F%D1%80%D0%B8%D0%B2%D1%8F%D0%B7%D0%BA%D0%B0_SQLCipher_%D0%BA_Qt

#include <qsqldriverplugin.h>
#include <qstringlist.h>
#include "../src/sql/drivers/sqlite/qsql_sqlite.h"

QT_BEGIN_NAMESPACE

class QSqlCipherDriverPlugin : public QSqlDriverPlugin
{
public:
    QSqlCipherDriverPlugin();

    QSqlDriver* create(const QString &);
    QStringList keys() const;
};

QSqlCipherDriverPlugin::QSqlCipherDriverPlugin()
    : QSqlDriverPlugin()
{
}

QSqlDriver* QSqlCipherDriverPlugin::create(const QString &name)
{
    if (name == QLatin1String("QSQLCIPHER")) {
        QSQLiteDriver* driver = new QSQLiteDriver();
        return driver;
    }
    return 0;
}

QStringList QSqlCipherDriverPlugin::keys() const
{
    QStringList l;
    l  << QLatin1String("QSQLCIPHER");
    return l;
}

Q_EXPORT_STATIC_PLUGIN(QSQLiteDriverPlugin)
Q_EXPORT_PLUGIN2(qsqlcipher, QSqlCipherDriverPlugin)

QT_END_NAMESPACE
