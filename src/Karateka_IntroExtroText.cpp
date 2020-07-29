#include "Pokitto.h"
#include "Game.h"

#include "utils/Stack.h"
#include "utils/PlayerStances.h"
#include "utils/EnemyStances.h"
#include "images/images.h"
#include "utils/Enums.h"
#include "utils/Utils.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;

//                                 0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18   19   20   21   22   23   24   25   26   27   28   29   30   31 
const char introText_Line_00[] = { '9', 'h', 'i', 'g', 'h', ' ', 'a', 't', 'o', 'p', ' ', 'a', ' ', 'c', 'r', 'a', 'g', 'g', 'y', ' ', 'c', 'l', 'i', 'f', 'f', ',', '+' };
const char introText_Line_01[] = { '9', '1', 'g', 'u', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'y', ' ', 'a', 'n', ' ', 'a', 'r', 'm', 'y', ' ', 'o', 'f', '+', };
const char introText_Line_02[] = { '2', 'f', 'i', 'e', 'r', 'c', 'e', ' ', 'w', 'a', 'r', 'r', 'i', 'o', 'r', 's', ',', 's', 't', 'a', 'n', 'd', 's', ' ', 't', 'h', 'e', '+' };
const char introText_Line_03[] = { '7', '9', 'f', 'o', 'r', 't', 'r', 'e', 's', 's', ' ', 'o', 'f', ' ', 't', 'h', 'e', ' ', 'e', 'v', 'i', 'l', '+' };
const char introText_Line_04[] = { 'w', 'a', 'r', 'l', 'o', 'r', 'd', ' ', 'a', 'k', 'u', 'm', 'a', '.', 'd', 'e', 'e', 'p', ' ', 'i', 'n', ' ', 't', 'h', 'e', '+' };
const char introText_Line_05[] = { '9', 'd', 'a', 'r', 'k', 'e', 's', 't', ' ', 'd', 'u', 'n', 'g', 'e', 'o', 'n', ' ', 'o', 'f', ' ', 't', 'h', 'e', '+' };
const char introText_Line_06[] = { 'c', 'a', 's', 't', 'l', 'e', ',', 'a', 'k', 'u', 'm', 'a', ' ', 'g', 'l', 'o', 'a', 't', 's', ' ', 'o', 'v', 'e', 'r', ' ', 'h' ,'i', 's', '+',  };
const char introText_Line_07[] = { '2', 'l', 'o', 'v', 'e', 'l', 'y', ' ', 'c', 'a', 'p', 't', 'i', 'v', 'e', ',', 't', 'h', 'e', ' ', 'p', 'r', 'i', 'n', 'c', 'e', 's', 's', '+' };
const char introText_Line_08[] = { '9', '9', '9', '9', '7', 'm', 'a', 'r', 'i', 'k', 'o', '.', '+' };
const char introText_Line_09[] = { '=' };
const char introText_Line_10[] = { '4', 'y', 'o', 'u', ' ', 'a', 'r', 'e', ' ', 'o', 'n', 'e', ' ', 't', 'r', 'a', 'i', 'n', 'e', 'd', ' ', 'i', 'n', ' ', 't', 'h', 'e', '+' };
const char introText_Line_11[] = { 'w', 'a', 'y', ' ', 'o', 'f', ' ', 'k', 'a', 'r', 'a', 't', 'e', ':', 'a', ' ', 'k', 'a', 'r', 'a', 't', 'e', 'k', 'a', '.', '+' };
const char introText_Line_12[] = { '8', '2', 'a', 'l', 'o', 'n', 'e', ' ', 'a', 'n', 'd', ' ', 'u', 'n', 'a', 'r', 'm', 'e', 'd', ',', 'y', 'o', 'u', '+' };
const char introText_Line_13[] = { '8', '2', 'm', 'u', 's', 't', ' ', 'd', 'e', 'f', 'e', 'a', 't', ' ', 'a', 'k', 'u', 'm', 'a', ' ', 'a', 'n', 'd', '+' };
const char introText_Line_14[] = { 'r', 'e', 's', 'c', 'u', 'e', ' ', 't', 'h', 'e', ' ', 'b', 'e', 'a', 'u', 't', 'i', 'f', 'u', 'l', ' ', 'm', 'a', 'r', 'i', 'k', 'o', '.', '+' };
const char introText_Line_15[] = { '=' };
const char introText_Line_16[] = { '5', 'p', 'u', 't', ' ', 'f', 'e', 'a', 'r', ' ', 'a', 'n', 'd', ' ', 's', 'e', 'l', 'f', '-', 'c', 'o', 'n', 'c', 'e', 'r', 'n', '+' };
const char introText_Line_17[] = { '2', 'b', 'e', 'h', 'i', 'n', 'd', ' ', 'y', 'o', 'u', '.', 'f', 'o', 'c', 'u', 's', ' ', 'y', 'o', 'u', 'r', ' ', 'w', 'i', 'l', 'l', '+' };
const char introText_Line_18[] = { 'o', 'n', ' ', 'y', 'o', 'u', 'r', ' ', 'o', 'b', 'j', 'e', 'c', 't', 'i', 'v', 'e', ',', 'a', 'c', 'c', 'e', 'p', 't', 'i', 'n', 'g', '+' };
const char introText_Line_19[] = { '2', 'd', 'e', 'a', 't', 'h', ' ', 'a', 's', ' ', 'a', ' ', 'p', 'o', 's', 's', 'i', 'b', 'i', 'l', 'i', 't', 'y', '.', 't', 'h', 'i', 's', ' ', 'i', 's' ,'+' };
const char introText_Line_20[] = { '6', 't', 'h', 'e', ' ', 'w', 'a', 'y', ' ', 'o', 'f', ' ', 't', 'h', 'e', ' ', 'k', 'a', 'r', 'a', 't', 'e', 'k', 'a', '.', '+' };
const char introText_Line_99[] = { '#' };

const char * const introTextLines[] = {introText_Line_00, introText_Line_01, introText_Line_02, introText_Line_03, introText_Line_04, introText_Line_05, introText_Line_06, 
                                       introText_Line_07, introText_Line_08, introText_Line_09, introText_Line_10, introText_Line_11, introText_Line_12, introText_Line_13,
                                       introText_Line_14, introText_Line_15, introText_Line_16, introText_Line_17, introText_Line_18, introText_Line_19, 
                                       introText_Line_20, introText_Line_99 };

void Game::introText() {

    uint16_t cx = 0;
    uint16_t cy = 0;
    uint16_t x = 0;
    int16_t y = this->introTextVariables.y;


    if (PC::buttons.pressed(BTN_A)) this->gameStateDetails.setCurrState(GAME_STATE_FOLLOW_SEQUENCE);


    //if (PC::frameCount % 2 == 0) {

        this->introTextVariables.y = this->introTextVariables.y - 1;

        if (this->introTextVariables.y == -483) {
            this->gameStateDetails.setCurrState(GAME_STATE_FOLLOW_SEQUENCE);
        }

        while (cy < 999) {

            while (cx < 999) {

                const char *introText_Line_To_Read = introTextLines[cy];
                uint8_t character = introText_Line_To_Read[cx];

                switch (character) {

                    case '+':       //The end of a line ..
                        x = 0;
                        y = y + 21;
                        cx = 999;
                        cy++;
                        break;

                    case '=':       //The end of a paragraph ..
                        x = 0;
                        y = y + 42;
                        cx = 999;
                        cy++;
                        break;

                    case '#':       // The end of text ..
                        cx = 999;
                        cy = 999;
                        break;

                    case '1' ... '9':       // The end of text ..
                        x = x + (character - 48) * 2;
                        break;

                    case ' ':
                        x = x + 4;
                        break;

                    case ',':
                        if (y > -20 && y < 176) PD::directBitmap(x, y, Images::Chars[26], 4, 1);
                        x = x + Images::Char_Spacing[26];
                        break;

                    case '.':
                        if (y > -20 && y < 176) PD::directBitmap(x, y, Images::Chars[27], 4, 1);
                        x = x + Images::Char_Spacing[27];
                        break;

                    case ':':
                        if (y > -20 && y < 176) PD::directBitmap(x, y, Images::Chars[28], 4, 1);
                        x = x + Images::Char_Spacing[28];
                        break;

                    case '-':
                        if (y > -20 && y < 176) PD::directBitmap(x, y, Images::Chars[29], 4, 1);
                        x = x + Images::Char_Spacing[29];
                        break;

                    default:
                        if (y > -20 && y < 176) PD::directBitmap(x, y, Images::Chars[character - 97], 4, 1);
                        x = x + Images::Char_Spacing[character - 97];
                        break;

                }

                cx = cx + 1;

            }

            cx = 0;

        }

    //}

}


//                                 0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18   19   20   21   22   23   24   25   26   27   28   29   30   31 
const char extroText_Line_00[] = { '3', 'a', 'n', 'd', ' ', 's', 'o', ' ', 't', 'h', 'i', 's', ' ', 'a', 'd', 'v', 'e', 'n', 't', 'u', 'r', 'e', ' ', 'e', 'n', 'd', 's', '.', '+' };
const char extroText_Line_01[] = { '9', '9', 't', 'h', 'e', ' ', 'e', 'v', 'i', 'l', ' ', 'a', 'k', 'u', 'm', 'a', ' ', 'l', 'i', 'e', 's', ' ', '+', };
const char extroText_Line_02[] = { '6', 'v', 'a', 'n', 'q', 'u', 'i', 's', 'h', 'e', 'd', ',', 't', 'h', 'e', ' ', 'b', 'e', 'a', 'u', 't', 'i', 'f', 'u', 'l', '+' };
const char extroText_Line_03[] = { '4', 'm', 'a', 'r', 'i', 'k', 'o', ' ', 's', 'a', 'f', 'e', ' ', 'i', 'n', ' ', 'y', 'o', 'u', 'r', ' ', 'a', 'r', 'm', 's', '.', '+' };
const char extroText_Line_04[] = { '9', '7', 'f', 'o', 'r', ' ', 't', 'h', 'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 't', 'i', 'm', 'e', ' ', 'i', 'n', '+' };
const char extroText_Line_05[] = { '1', 'm', 'e', 'm', 'o', 'r', 'y', ',', 't', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', 'r', 'y', ' ', 'b', 'a', 's', 'k', 's', '+'  };
const char extroText_Line_06[] = { '1', 'i', 'n', ' ', 't', 'h', 'e', ' ', 's', 'u', 'n', 'l', 'i', 'g', 'h', 't', ' ', 'o', 'f', ' ', 'p', 'e', 'a', 'c', 'e', '.', 'b', 'u', 't', '+'  };
const char extroText_Line_07[] = { '6', 'b', 'e', 'w', 'a', 'r', 'e', ':', 'f', 'o', 'r', ' ', 't', 'h', 'e', ' ', 'k', 'a', 'r', 'a', 't', 'e', 'k', 'a', '+'  };
const char extroText_Line_08[] = { '9', '2', 't', 'h', 'e', 'r', 'e', ' ', 'i', 's', ' ', 'a', 'l', 'w', 'a', 'y', 's', ' ', 'a', ' ', 'n', 'e', 'x', 't', '+' };
const char extroText_Line_09[] = { '9', '9', '9', '9', '9', 't', 'i', 'm', 'e', ' ', '.', '.', '.', '+' };
const char extroText_Line_99[] = { '#' };

const char * const extroTextLines[] = {extroText_Line_00, extroText_Line_01, extroText_Line_02, extroText_Line_03, extroText_Line_04, extroText_Line_05, extroText_Line_06, 
                                       extroText_Line_07, extroText_Line_08, extroText_Line_09, extroText_Line_99 };

void Game::extroText() {

    uint16_t cx = 0;
    uint16_t cy = 0;
    uint16_t x = 0;
    int16_t y = 6;

    if (PC::buttons.pressed(BTN_A)) this->gameStateDetails.setCurrState(GAME_STATE_FOLLOW_SEQUENCE);

    this->stateCounter++;

    if (this->stateCounter == 180) {
        this->gameStateDetails.setCurrState(GAME_STATE_FOLLOW_SEQUENCE);
    }
    
    if (this->stateCounter == 1) {

        while (cy < 999) {

            while (cx < 999) {

                const char *extroText_Line_To_Read = extroTextLines[cy];
                uint8_t character = extroText_Line_To_Read[cx];

                switch (character) {

                    case '+':       //The end of a line ..
                        x = 0;
                        y = y + 17;
                        cx = 999;
                        cy++;
                        break;

                    case '=':       //The end of a paragraph ..
                        x = 0;
                        y = y + 42;
                        cx = 999;
                        cy++;
                        break;

                    case '#':       // The end of text ..
                        cx = 999;
                        cy = 999;
                        break;

                    case '1' ... '9':       // The end of text ..
                        x = x + (character - 48) * 2;
                        break;

                    case ' ':
                        x = x + 4;
                        break;

                    case ',':
                        if (y > -20 && y < 176) PD::directBitmap(x, y, Images::Chars[26], 4, 1);
                        x = x + Images::Char_Spacing[26];
                        break;

                    case '.':
                        if (y > -20 && y < 176) PD::directBitmap(x, y, Images::Chars[27], 4, 1);
                        x = x + Images::Char_Spacing[27];
                        break;

                    case ':':
                        if (y > -20 && y < 176) PD::directBitmap(x, y, Images::Chars[28], 4, 1);
                        x = x + Images::Char_Spacing[28];
                        break;

                    case '-':
                        if (y > -20 && y < 176) PD::directBitmap(x, y, Images::Chars[29], 4, 1);
                        x = x + Images::Char_Spacing[29];
                        break;

                    default:
                        if (y > -20 && y < 176) PD::directBitmap(x, y, Images::Chars[character - 97], 4, 1);
                        x = x + Images::Char_Spacing[character - 97];
                        break;

                }

                cx = cx + 1;

            }

            cx = 0;

        }

    }

}