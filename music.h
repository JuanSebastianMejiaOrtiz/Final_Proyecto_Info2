#ifndef MUSIC_H
#define MUSIC_H

#include <QMediaPlayer>
#include <QObject>

class music : public QObject
{
    Q_OBJECT

public:
    music();
    ~music();

private slots:
    void handleMediaStatusChanged(QMediaPlayer::MediaStatus status);

private:
    QMediaPlayer *musica;
};

#endif // MUSIC_H
