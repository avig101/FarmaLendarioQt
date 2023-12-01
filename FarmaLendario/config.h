#ifndef CONFIG_H
#define CONFIG_H
#include <QString>

class Config
{
public:
    explicit Config();

    QString getStyles();
    QString getAppName();
    QString getVersion();
};

#endif // CONFIG_H
