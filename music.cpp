
#include "music.h"

music::music()
{
    musica = new QMediaPlayer();

    musica->setMedia(QUrl("qrc:/Resources/Music/Cancion_Juego_Proyecto_Final.wav"));
    musica->setVolume(50);  // Ajusta el volumen de la música según tus preferencias

    QObject::connect(musica, &QMediaPlayer::mediaStatusChanged, this, &music::handleMediaStatusChanged);

    musica->play();
}

music::~music()
{
    delete musica;
}

void music::handleMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia)
    {
        musica->setPosition(0);  // Reinicia la posición de reproducción al inicio
        musica->play();
    }
}
