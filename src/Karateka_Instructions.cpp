#include "Pokitto.h"
#include "Game.h"

#include "utils/Stack.h"
#include "utils/PlayerStances.h"
#include "utils/EnemyStances.h"
#include "images/images.h"
#include "utils/Enums.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;

//                                 0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18   19   20   21   22   23   24   25   26   27   28   29   30   31 
const char instructionText_Line_00[] = { 'k', 'i', 'c', 'k', 'i', 'n', 'g', ':', '=' };
const char instructionText_Line_01[] = { 'p', 'r', 'e', 's', 's', ' ', 'a', 'n', 'd', ' ', 'h', 'o', 'l', 'd', ' ', 't', '+', };
const char instructionText_Line_02[] = { 'f', 'i', 'e', 'r', 'c', 'e', ' ', 'w', 'a', 'r', 'r', 'i', 'o', 'r', 's', '+' };
const char instructionText_Line_03[] = { 'l', 'f', 'o', 'r', 't', 'r', 'e', 's', 's', ' ', 'o', 'f', ' ', 't', 'h', '+' };
const char instructionText_Line_04[] = { '#' };

const char * const intructionTextLines[] = {instructionText_Line_00, instructionText_Line_01, instructionText_Line_02, instructionText_Line_03, instructionText_Line_04 };


void Game::instructions_Init() {

    this->player.setStance(STANCE_STANDING_UPRIGHT);
    this->gameStateDetails.background = Background::Instructions;
    this->instructionVariables.reset();

}

void Game::instructions() {

    // Kick

    draw_background();
    renderPlayerStance(4, 80, this->player.getStance());


    uint16_t cx = 0;
    uint16_t cy = 0;
    uint16_t x = 100;
    int16_t y = 6;

    //if (PC::buttons.pressed(BTN_A)) this->gameStateDetails.setCurrState(GAME_STATE_FOLLOW_SEQUENCE);

    switch (this->instructionVariables.instruction) {

        case 0:
            PD::setCursor(44, 25);
            PD::print("Movements:");
            PD::drawBitmap(44, 34, Images::ButtonDown);
            PD::setCursor(56, 36);
            PD::print("Fight ready");
            PD::drawBitmap(44, 45, Images::ButtonUp);
            PD::setCursor(56, 47);
            PD::print("Upright");
            break;

        case 1:
            PD::setCursor(44, 25);
            PD::print("Kicking:");
            PD::drawBitmap(44, 34, Images::ButtonA);
            PD::setCursor(56, 36);
            PD::print("Kick ready");
            PD::drawBitmap(44, 45, Images::ButtonUp);
            PD::setCursor(56, 47);
            PD::print("High kick");
            PD::drawBitmap(44, 56, Images::ButtonRight);
            PD::setCursor(56, 58);
            PD::print("Medium kick");
            PD::drawBitmap(44, 67, Images::ButtonDown);
            PD::setCursor(56, 69);
            PD::print("Low kick");
            break;

        case 2:
            PD::setCursor(44, 25);
            PD::print("Punching:");
            PD::drawBitmap(44, 34, Images::ButtonB);
            PD::setCursor(56, 36);
            PD::print("Punch ready");
            PD::drawBitmap(44, 45, Images::ButtonUp);
            PD::setCursor(56, 47);
            PD::print("High punch");
            PD::drawBitmap(44, 56, Images::ButtonRight);
            PD::setCursor(56, 58);
            PD::print("Medium punch");
            PD::drawBitmap(44, 67, Images::ButtonDown);
            PD::setCursor(56, 69);
            PD::print("Low punch");
            break;

        case 3:
            PD::setCursor(44, 25);
            PD::print("Practice:");
            PD::setCursor(44, 36);
            PD::print("Try out the kicks");
            PD::setCursor(44, 45);
            PD::print("and punches you");
            PD::setCursor(44, 54);
            PD::print("have learnt.");
            PD::drawBitmap(44, 64, Images::ButtonC);
            PD::setCursor(56, 66);
            PD::print("Finished");
            break;

    }

    this->player.update();

    if (this->player.getStackFrame() == 0) {
    
        if (!this->player.isEmpty()) {
            this->player.setStance(this->player.pop());
            //this->player.setXPos(this->player.getXPos() + this->player.getXPosDelta());
        }
        
    }


    if (this->player.isEmpty()) {

        switch (this->instructionVariables.instruction) {

            case 0:
                if (this->instructionVariables.performedFightReady && this->instructionVariables.performedUpright) {
                    this->instructionVariables.instruction++;
                }
                break;

            case 1:
                if (this->instructionVariables.kickLow && this->instructionVariables.kickMed && this->instructionVariables.kickHigh) {
                    this->instructionVariables.instruction++;
                }
                break;

            case 2:
                if (this->instructionVariables.punchLow && this->instructionVariables.punchMed && this->instructionVariables.punchHigh) {
                    this->instructionVariables.instruction++;
                }
                break;

            case 3:
                if (PC::buttons.pressed(BTN_C)) {
                    this->gameStateDetails.setCurrState(GAME_STATE_TITLE_SCENE_INIT);
                }
                break;
                
        }

    }


    if (this->player.isEmpty()) {

        if (PC::buttons.pressed(BTN_A) || PC::buttons.repeat(BTN_A, 1)) {

            switch (this->player.getStance()) {

                case STANCE_STANDING_UPRIGHT:
                    this->player.push(STANCE_DEFAULT, STANCE_DEFAULT_LEAN_BACK, true);
                    this->playSoundEffect(SoundEffect::Kiai);
                    if (this->instructionVariables.instruction == 0) this->instructionVariables.performedFightReady = true;
                    break;

                case STANCE_DEFAULT:

                    // Move to the Kick Ready position ..

                    if (!PC::buttons.pressed(BTN_UP) && !PC::buttons.pressed(BTN_RIGHT) && !PC::buttons.pressed(BTN_DOWN)) {

                        this->player.push(STANCE_KICK_READY, STANCE_DEFAULT_LEAN_BACK, true);
                        this->player.setActionsBeforeReturn(random(PLAYER_KICK_ACTIONS_MIN, PLAYER_KICK_ACTIONS_MAX));

                    }
                    else {

                        // Perform an immediate kick from the default position ..

                        if (PC::buttons.pressed(BTN_RIGHT))  {             // Medium kick ..
                            this->player.push(STANCE_KICK_MED_END, STANCE_KICK_STANDING_TRANSITION, STANCE_DEFAULT_LEAN_BACK, true);
                            if (this->instructionVariables.instruction == 1) this->instructionVariables.kickMed = true;
                        }

                        else if (PC::buttons.pressed(BTN_UP))  {           // High kick ..
                            this->player.push(STANCE_KICK_HIGH_END, STANCE_KICK_STANDING_TRANSITION, STANCE_DEFAULT_LEAN_BACK, true);
                            if (this->instructionVariables.instruction == 1) this->instructionVariables.kickHigh = true;
                        }

                        else if (PC::buttons.pressed(BTN_DOWN))  {         // Low kick ..
                            this->player.push(STANCE_KICK_LOW_END, STANCE_KICK_STANDING_TRANSITION, STANCE_DEFAULT_LEAN_BACK, true);
                            if (this->instructionVariables.instruction == 1) this->instructionVariables.kickLow = true;
                        }

                    }
                    break;

                case STANCE_KICK_HIGH_END:
                case STANCE_KICK_MED_END:
                case STANCE_KICK_LOW_END:                               // As the A button is still being held, return to the Kick Ready position ..
        
                    this->player.push(STANCE_KICK_READY, true);
                    if (this->player.decActionsBeforeReturn(10)) {

                        this->player.setActivity(0);    
                        this->player.push(STANCE_DEFAULT, STANCE_DEFAULT_LEAN_FORWARD, true);
                        this->player.setActionsBeforeReturn(0);

                    }
                    break;

                case STANCE_KICK_READY:

                    if (this->player.decActionsBeforeReturn(1)) {

                        this->player.setActivity(0);    
                        this->player.push(STANCE_DEFAULT, STANCE_DEFAULT_LEAN_FORWARD, true);
                        this->player.setActionsBeforeReturn(0);

                    }
                    else if (PC::buttons.pressed(BTN_UP) || PC::buttons.pressed(BTN_RIGHT) || PC::buttons.pressed(BTN_DOWN) || PC::buttons.pressed(BTN_LEFT)) {

                        this->player.setActivity(this->player.getActivity() + 1);

                        if (this->player.getActivity() > 4) {
                            this->player.push(STANCE_DEFAULT, STANCE_DEFAULT_LEAN_FORWARD, true);
                            this->player.setActivity(0);
                        }

                        if (PC::buttons.pressed(BTN_RIGHT))  {               // Medium kick ..
                            this->player.push(STANCE_KICK_READY, STANCE_KICK_MED_END, true);
                            if (this->instructionVariables.instruction == 1) this->instructionVariables.kickMed = true;
                        }

                        else if (PC::buttons.pressed(BTN_UP))  {             // High kick ..
                            this->player.push(STANCE_KICK_READY, STANCE_KICK_HIGH_END, true);
                            if (this->instructionVariables.instruction == 1) this->instructionVariables.kickHigh = true;
                        }

                        else if (PC::buttons.pressed(BTN_DOWN))  {           // Low kick ..
                            this->player.push(STANCE_KICK_READY, STANCE_KICK_LOW_END, true);
                            if (this->instructionVariables.instruction == 1) this->instructionVariables.kickLow = true;
                        }

                    }

                    break;

                case STANCE_PUNCH_READY:                                  // Really shouldn't happen but if B is pressed before A and both held ..

                    playerMovements_Punch();

                    // if (PC::buttons.pressed(BTN_RIGHT))  {             // Medium punch ..
                    //     this->player.push(STANCE_PUNCH_READY, (this->player.getRightPunch() ? STANCE_PUNCH_MED_RH_END : STANCE_PUNCH_MED_LH_END), true);
                    //     this->player.setRightPunch(!this->player.getRightPunch());
                    //     if (this->instructionVariables.instruction == 2) this->instructionVariables.punchMed = true;
                    // }

                    // else if (PC::buttons.pressed(BTN_UP))  {           // High punch ..
                    //     this->player.push(STANCE_PUNCH_READY, (this->player.getRightPunch() ? STANCE_PUNCH_HIGH_RH_END : STANCE_PUNCH_HIGH_LH_END), true);
                    //     this->player.setRightPunch(!this->player.getRightPunch());
                    //     if (this->instructionVariables.instruction == 2) this->instructionVariables.punchHigh = true;
                    // }

                    // else if (PC::buttons.pressed(BTN_DOWN))  {         // Low punch ..
                    //     this->player.push(STANCE_PUNCH_READY, (this->player.getRightPunch() ? STANCE_PUNCH_LOW_RH_END : STANCE_PUNCH_LOW_LH_END), true);
                    //     this->player.setRightPunch(!this->player.getRightPunch());
                    //     if (this->instructionVariables.instruction == 2) this->instructionVariables.punchLow = true;
                    // }
                    break;

                default:
                    break;

            }

        }
        else {


            // If the A Button is no longer being pressed ..

            switch (this->player.getStance()) {

                case STANCE_KICK_READY:
                    this->player.setActivity(0);
                    this->player.push(STANCE_DEFAULT, STANCE_DEFAULT_LEAN_FORWARD, true);
                    this->player.setActionsBeforeReturn(0);
                    break;

                case STANCE_KICK_HIGH_END:
                case STANCE_KICK_MED_END:
                case STANCE_KICK_LOW_END:
                    this->player.setActivity(0);
                    this->player.push(STANCE_DEFAULT, STANCE_DEFAULT_LEAN_FORWARD, STANCE_KICK_READY, true);
                    this->player.setActionsBeforeReturn(0);
                    break;

            }


            // Is the B button being pressed ?

            if (PC::buttons.pressed(BTN_B) || PC::buttons.repeat(BTN_B, 1)) {

                switch (this->player.getStance()) {

                    case STANCE_STANDING_UPRIGHT:                         // If standing upright, move to the fighting position ..
                        this->player.push(STANCE_DEFAULT, STANCE_DEFAULT_LEAN_BACK, true);
                        if (this->instructionVariables.instruction == 0) this->instructionVariables.performedFightReady = true;
                        this->playSoundEffect(SoundEffect::Kiai);
                        break;

                    case STANCE_DEFAULT:                                  // Move to the Punch Ready position ..

                        if (!PC::buttons.pressed(BTN_UP) && !PC::buttons.pressed(BTN_RIGHT) && !PC::buttons.pressed(BTN_DOWN)) {

                            this->player.push(STANCE_PUNCH_READY, STANCE_DEFAULT_LEAN_BACK, true);

                        }
                        else {


                            // Perform a immediate punch from the standing position ..

                            playerMovements_Punch();
                            // if (PC::buttons.pressed(BTN_RIGHT))  {                // Medium punch ..
                            //     this->player.push(STANCE_PUNCH_MED_RH_END, STANCE_PUNCH_READY, STANCE_DEFAULT_LEAN_BACK, true);
                            //     if (this->instructionVariables.instruction == 2) this->instructionVariables.punchMed = true;
                            // }

                            // else if (PC::buttons.pressed(BTN_UP))  {              // High punch ..
                            //     this->player.push(STANCE_PUNCH_HIGH_RH_END, STANCE_PUNCH_READY, STANCE_DEFAULT_LEAN_BACK, true);
                            //     if (this->instructionVariables.instruction == 2) this->instructionVariables.punchHigh = true;
                            // }

                            // else if (PC::buttons.pressed(BTN_UP))  {              // Low punch ..
                            //     this->player.push(STANCE_PUNCH_LOW_RH_END, STANCE_PUNCH_READY, STANCE_DEFAULT_LEAN_BACK, true);
                            //     if (this->instructionVariables.instruction == 2) this->instructionVariables.punchLow = true;
                            // }

                        }

                        break;

                    case STANCE_PUNCH_HIGH_LH_END:                        // As the B button is still being held, return to the Puch Ready position ..
                    case STANCE_PUNCH_HIGH_RH_END:
                    case STANCE_PUNCH_MED_LH_END:
                    case STANCE_PUNCH_MED_RH_END:
                    case STANCE_PUNCH_LOW_LH_END:
                    case STANCE_PUNCH_LOW_RH_END:

                        this->player.push(STANCE_PUNCH_READY, true);
                        break;

                    case STANCE_PUNCH_READY:

                        // if (PC::buttons.pressed(BTN_RIGHT))  {             // Medium punch ..
                        //     this->player.push(STANCE_PUNCH_READY, (this->player.getRightPunch() ? STANCE_PUNCH_MED_RH_END : STANCE_PUNCH_MED_LH_END), true);
                        //     this->player.setRightPunch(!this->player.getRightPunch());
                        //     if (this->instructionVariables.instruction == 2) this->instructionVariables.punchMed = true;
                        // }

                        // else if (PC::buttons.pressed(BTN_UP))  {           // High punch ..
                        //     this->player.push(STANCE_PUNCH_READY, (this->player.getRightPunch() ? STANCE_PUNCH_HIGH_RH_END : STANCE_PUNCH_HIGH_LH_END), true);
                        //     this->player.setRightPunch(!this->player.getRightPunch());
                        //     if (this->instructionVariables.instruction == 2) this->instructionVariables.punchHigh = true;
                        // }

                        // else if (PC::buttons.pressed(BTN_DOWN))  {         // Low punch ..
                        //     this->player.push(STANCE_PUNCH_READY, (this->player.getRightPunch() ? STANCE_PUNCH_LOW_RH_END : STANCE_PUNCH_LOW_LH_END), true);
                        //     this->player.setRightPunch(!this->player.getRightPunch());
                        //     if (this->instructionVariables.instruction == 2) this->instructionVariables.punchLow = true;
                        // }
                        // break;
                        playerMovements_Punch();

                    default:
                        break;

                }

            }
            else {

                // Neither the A or B button has been pressed ..

                switch (this->player.getStance()) {    // If the B Button is no longer being pressed return to the default stance ..

                    case STANCE_PUNCH_READY:

                    //     if ((PC::buttons.pressed(BTN_LEFT) || PC::buttons.repeat(BTN_LEFT, 1)) && this->player.getXPosOverall() > 16)  { // Sidle backwards ..

                    //         this->player.setMovement(Movement::Sidle_Backward);
                    //         this->player.setXPosDelta(MAIN_SCENE_X_SIDLING_2_DELTA); 
                    //         this->player.push(STANCE_DEFAULT, STANCE_DEFAULT_LEAN_BACK, STANCE_SIDLING_3, true);
                    //         this->player.push(STANCE_SIDLING_2, STANCE_SIDLING_1, STANCE_DEFAULT_LEAN_FORWARD, true);

                    //     }
                    //     else {
                            
                             this->player.push(STANCE_DEFAULT, STANCE_DEFAULT_LEAN_FORWARD, true);

                    //     }
                         break;

                    case STANCE_PUNCH_HIGH_LH_END:
                    case STANCE_PUNCH_HIGH_RH_END:
                    case STANCE_PUNCH_MED_LH_END:
                    case STANCE_PUNCH_MED_RH_END:
                    case STANCE_PUNCH_LOW_LH_END:
                    case STANCE_PUNCH_LOW_RH_END:

                        this->player.push(STANCE_DEFAULT, STANCE_DEFAULT_LEAN_FORWARD, STANCE_PUNCH_READY, true);
                        break;

                    case STANCE_DEFAULT:

                        if (PC::buttons.pressed(BTN_UP))  { // Stand upright again ..
                            this->player.push(STANCE_STANDING_UPRIGHT, STANCE_DEFAULT_LEAN_BACK, true);
                            if (this->instructionVariables.instruction == 0) this->instructionVariables.performedUpright = true;
                        }

                        break;

                    case STANCE_STANDING_UPRIGHT:

                        if (PC::buttons.pressed(BTN_UP))  { // Bow ..
                            this->player.push(STANCE_DEFAULT, STANCE_DEFAULT_LEAN_BACK, true);
                            this->player.push(STANCE_STANDING_UPRIGHT, STANCE_BOW_1, true);
                            this->player.push(STANCE_BOW_2, STANCE_BOW_1, true);
                            this->playSoundEffect(SoundEffect::Kiai);
                            if (this->instructionVariables.instruction == 0) this->instructionVariables.performedFightReady = true;
                        }

                        if (PC::buttons.pressed(BTN_DOWN))  { // If standing upright, move to the fighting position ..
                            this->player.push(STANCE_DEFAULT, STANCE_DEFAULT_LEAN_BACK, true);
                            this->playSoundEffect(SoundEffect::Kiai);
                            if (this->instructionVariables.instruction == 0) this->instructionVariables.performedFightReady = true;
                        }

                        break;

                }

            }

        }

    }

}