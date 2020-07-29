#include "Pokitto.h"
#include <LibAudio>
#include "src/Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;


Game game;

Audio::Sink<4, PROJ_AUD_FREQ> audio;

int main(){
    
    PC::begin();
    PD::loadRGBPalette(palettePico);   
    PD::persistence = true;
    PD::setColor(5);
    PD::setInvisibleColor(14);
    PC::setFrameRate(40);
    PD::setFont(fontKoubit);

    game.setup();
    
    while( PC::isRunning() ){

        game.loop();

    }
    
    return 0;
}
