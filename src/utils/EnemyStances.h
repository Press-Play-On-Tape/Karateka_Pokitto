#pragma once

#include "Pokitto.h"
#include "../images/images.h"
#include "Enums.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;

const int8_t enemy_head[] = {
12, -40, 1, 1,        // STANCE_DEFAULT
12, -40, 1, 1,        // STANCE_DEFAULT_LEAN_BACK
23, -40, 1, 1,        // STANCE_KICK_READY
12, -40, 1, 1,        // STANCE_DEFAULT_LEAN_FORWARD
21, -40, 1, 1,        // STANCE_KICK_STANDING_TRANSITION
24, -38, 1, 1,        // STANCE_KICK_MED_END
23, -40, 1, 1,        // STANCE_KICK_LOW_END
29, -36, 1, 1,        // STANCE_KICK_HIGH_END
10, -40, 1, 1,        // STANCE_PUNCH_MED_RH_END
11, -40, 1, 1,        // STANCE_PUNCH_MED_LH_END
11, -40, 1, 1,        // STANCE_PUNCH_HIGH_RH_END
10, -40, 1, 1,        // STANCE_PUNCH_HIGH_LH_END
10, -40, 1, 1,        // STANCE_PUNCH_LOW_RH_END
10, -40, 1, 1,        // STANCE_PUNCH_LOW_LH_END
13, -40, 1, 1,        // STANCE_PUNCH_READY
24, -40, 1, 1,        // STANCE_STANDING_UPRIGHT
12, -40, 1, 1,        // STANCE_SIDLING_1
12, -40, 1, 1,        // STANCE_SIDLING_2
12, -40, 1, 1,        // STANCE_SIDLING_3
12, -40, 1, 1,        // STANCE_SIDLING_4
12, -40, 1, 1,        // STANCE_SIDLING_5
12, -40, 1, 1,        // STANCE_SIDLING_6
12, -40, 1, 1,        // STANCE_SIDLING_7
14, -40, 1, 1,        // STANCE_RUNNING_1
11, -40, 1, 1,        // STANCE_RUNNING_2
11, -40, 1, 1,        // STANCE_RUNNING_3
11, -40, 1, 1,        // STANCE_RUNNING_4
11, -40, 1, 1,        // STANCE_RUNNING_5
11, -40, 1, 1,        // STANCE_RUNNING_6
11, -40, 1, 1,        // STANCE_RUNNING_7
11, -40, 1, 1,        // STANCE_RUNNING_8
20, -40, 1, 1,        // STANCE_RUNNING_STRAIGHTEN_UP
15, -40, 1, 0,        // STANCE_STANDING_UPRIGHT_REV
11, -40, 1, 0,        // STANCE_RUNNING_1_REV
15, -40, 1, 0,        // STANCE_RUNNING_2_REV
15, -40, 1, 0,        // STANCE_RUNNING_3_REV
15, -40, 1, 0,        // STANCE_RUNNING_4_REV
15, -40, 1, 0,        // STANCE_RUNNING_5_REV
15, -40, 1, 0,        // STANCE_RUNNING_6_REV
15, -40, 1, 0,        // STANCE_RUNNING_7_REV
15, -40, 1, 0,        // STANCE_RUNNING_8_REV
15, -40, 1, 0,        // STANCE_RUNNING_STRAIGHTEN_UP_REV
20, -38, 1, 0,        // STANCE_BOW_1
20, -36, 1, 0,        // STANCE_BOW_2
21, -35, 1, 1,        // STANCE_DEATH_1
25, -25, 1, 1,        // STANCE_DEATH_2
25, -22, 1, 1,        // STANCE_DEATH_3   
31, -18, 1, 1,        // STANCE_DEATH_4  
/*
0, 0, 127, 1,         // STANCE_DEATH_5  
0, 0, 127, 1,         // STANCE_DEATH_6  
0, 0, 127, 0,         // STANCE_ENTRANCE_1
0, 0, 127, 0,         // STANCE_ENTRANCE_2
0, 0, 127, 0,         // STANCE_ENTRANCE_3
0, 0, 127, 0,         // STANCE_ENTRANCE_4
0, 0, 127, 0,         // STANCE_ENTRANCE_5
0, 0, 127, 0,         // STANCE_ENTRANCE_6
0, 0, 127, 1,         // STANCE_EAGLE_1  
0, 0, 127, 1,         // STANCE_EAGLE_2  
0, 0, 127, 1,         // STANCE_EAGLE_3  
0, 0, 127, 1,         // STANCE_EAGLE_4  
0, 0, 127, 1,         // STANCE_EAGLE_1_REV  
0, 0, 127, 1,         // STANCE_EAGLE_2_REV  
0, 0, 127, 1,         // STANCE_EAGLE_3_REV  
0, 0, 127, 1,         // STANCE_EAGLE_4_REV  
0, 0, 127, 1,         // STANCE_PRINCESS_SITTING  
0, 0, 127, 1,         // STANCE_PRINCESS_STANDING  
0, 0, 127, 1,         // STANCE_PRINCESS_KISSING  
*/
};

const int8_t enemy_body[] = {
1, -31, 0, 1,         // STANCE_DEFAULT
1, -31, 0, 1,         // STANCE_DEFAULT_LEAN_BACK
10, -31, 1, 1,        // STANCE_KICK_READY
1, -31, 0, 1,         // STANCE_DEFAULT_LEAN_FORWARD
8, -32, 4, 1,         // STANCE_KICK_STANDING_TRANSITION
8, -31, 2, 1,         // STANCE_KICK_MED_END
8, -32, 3, 1,         // STANCE_KICK_LOW_END
19, -42, 5, 1,        // STANCE_KICK_HIGH_END
-9, -33, 6, 1,        // STANCE_PUNCH_MED_RH_END
-5, -33, 10, 1,       // STANCE_PUNCH_MED_LH_END
-9, -35, 7, 1,        // STANCE_PUNCH_HIGH_RH_END
-7, -37, 11, 1,       // STANCE_PUNCH_HIGH_LH_END
-5, -33, 8, 1,        // STANCE_PUNCH_LOW_RH_END
-5, -33, 9, 1,        // STANCE_PUNCH_LOW_LH_END
10, -32, 12, 1,       // STANCE_PUNCH_READY
24, -31, 13, 1,       // STANCE_STANDING_UPRIGHT
1, -31, 0, 1,         // STANCE_SIDLING_1
1, -31, 0, 1,         // STANCE_SIDLING_2
1, -31, 0, 1,         // STANCE_SIDLING_3
1, -31, 0, 1,         // STANCE_SIDLING_4
1, -31, 0, 1,         // STANCE_SIDLING_5
1, -31, 0, 1,         // STANCE_SIDLING_6
1, -31, 0, 1,         // STANCE_SIDLING_7
15, -32, 14, 1,       // STANCE_RUNNING_1
10, -32, 15, 1,       // STANCE_RUNNING_2
10, -32, 15, 1,       // STANCE_RUNNING_3
10, -32, 16, 1,       // STANCE_RUNNING_4
6, -32, 17, 1,        // STANCE_RUNNING_5
4, -32, 18, 1,        // STANCE_RUNNING_6
8, -32, 20, 1,        // STANCE_RUNNING_7
4, -32, 18, 1,        // STANCE_RUNNING_8
20, -32, 19, 1,       // STANCE_RUNNING_STRAIGHTEN_UP
13, -31, 13, 0,       // STANCE_STANDING_UPRIGHT_REV
5, -32, 14, 0,        // STANCE_RUNNING_1_REV
8, -32, 15, 0,        // STANCE_RUNNING_2_REV
8, -32, 15, 0,        // STANCE_RUNNING_3_REV
12, -32, 16, 0,       // STANCE_RUNNING_4_REV    
12, -32, 17, 0,       // STANCE_RUNNING_5_REV 
6, -32, 18, 0,        // STANCE_RUNNING_6_REV 
12, -32, 20, 0,       // STANCE_RUNNING_7_REV
6, -32, 18, 0,        // STANCE_RUNNING_8_REV 
10, -32, 19, 0,       // STANCE_RUNNING_STRAIGHTEN_UP_REV
13, -30, 21, 0,       // STANCE_BOW_1 
13, -28, 22, 0,       // STANCE_BOW_2
4, -27, 23, 1,        // STANCE_DEATH_1
8, -19, 24, 1,        // STANCE_DEATH_2
/*
0, 0, 127, 1,         // STANCE_DEATH_3   
0, 0, 127, 1,         // STANCE_DEATH_4   
0, 0, 127, 1,         // STANCE_DEATH_5   
0, 0, 127, 1,         // STANCE_DEATH_6   
0, 0, 127, 0,         // STANCE_ENTRANCE_1
0, 0, 127, 0,         // STANCE_ENTRANCE_2
0, 0, 127, 0,         // STANCE_ENTRANCE_3
0, 0, 127, 0,         // STANCE_ENTRANCE_4
0, 0, 127, 0,         // STANCE_ENTRANCE_5
0, 0, 127, 0,         // STANCE_ENTRANCE_6
0, 0, 127, 1,         // STANCE_EAGLE_1   
0, 0, 127, 1,         // STANCE_EAGLE_2   
0, 0, 127, 1,         // STANCE_EAGLE_3   
0, 0, 127, 1,         // STANCE_EAGLE_4   
0, 0, 127, 1,         // STANCE_EAGLE_1_REV   
0, 0, 127, 1,         // STANCE_EAGLE_2_REV   
0, 0, 127, 0,         // STANCE_EAGLE_3_REV  
0, 0, 127, 0,         // STANCE_EAGLE_4_REV  
0, 0, 127, 1,         // STANCE_PRINCESS_SITTING  
0, 0, 127, 1,         // STANCE_PRINCESS_STANDING  
0, 0, 127, 1,         // STANCE_PRINCESS_KISSING  
*/
};

const int8_t enemy_legs[] = {
-1, -18, 0, 1,         // STANCE_DEFAULT
-1, -18, 1, 1,        // STANCE_DEFAULT_LEAN_BACK
9, -22, 2, 1,         // STANCE_KICK_READY
6, -18, 1, 0,         // STANCE_DEFAULT_LEAN_FORWARD
7, -19, 7, 1,         // STANCE_KICK_STANDING_TRANSITION
-6, -25, 3, 1,        // STANCE_KICK_MED_END
-9, -24, 6, 1,        // STANCE_KICK_LOW_END
-6, -35, 8, 1,        // STANCE_KICK_HIGH_END
-2, -18, 9, 1,        // STANCE_PUNCH_MED_RH_END
-1, -18, 9, 1,        // STANCE_PUNCH_MED_LH_END
-1, -18, 9, 1,        // STANCE_PUNCH_HIGH_RH_END
-1, -18, 9, 1,        // STANCE_PUNCH_HIGH_LH_END
-1, -18, 9, 1,        // STANCE_PUNCH_LOW_RH_END
-1, -18, 9, 1,        // STANCE_PUNCH_LOW_LH_END
2, -19, 10, 1,        // STANCE_PUNCH_READY
24, -15, 11, 1,       // STANCE_STANDING_UPRIGHT
9, -18, 5, 1,         // STANCE_SIDLING_1
8, -18, 12, 1,        // STANCE_SIDLING_2
7, -18, 5, 0,         // STANCE_SIDLING_3
-3, -18, 22, 1,       // STANCE_SIDLING_4
-3, -18, 23, 1,       // STANCE_SIDLING_5
7, -18, 24, 1,        // STANCE_SIDLING_6
-3, -18, 22, 1,       // STANCE_SIDLING_7
13, -8, 13, 1,        // STANCE_RUNNING_1
5, -20, 14, 1,        // STANCE_RUNNING_2
4, -20, 15, 1,        // STANCE_RUNNING_3   
8, -20, 16, 1,        // STANCE_RUNNING_4 
8, -20, 17, 1,        // STANCE_RUNNING_5
5, -20, 18, 1,        // STANCE_RUNNING_6
8, -19, 21, 1,        // STANCE_RUNNING_7
4, -20, 20, 1,        // STANCE_RUNNING_8
15, -20, 19, 1,       // STANCE_RUNNING_STRAIGHTEN_UP
13, -15, 11, 0,       // STANCE_STANDING_UPRIGHT_REV
-1, -8, 13, 0,        // STANCE_RUNNING_1_REV
-1, -20, 14, 0,       // STANCE_RUNNING_2_REV
-4, -20, 15, 0,       // STANCE_RUNNING_3_REV
-0, -20, 16, 0,       // STANCE_RUNNING_4_REV
8, -20, 17, 0,        // STANCE_RUNNING_5_REV 
-5, -20, 18, 0,       // STANCE_RUNNING_6_REV    
8, -19, 21, 0,        // STANCE_RUNNING_7_REV
0, -20, 20, 0,        // STANCE_RUNNING_8_REV 
9, -20, 19, 0,        // STANCE_RUNNING_STRAIGHTEN_UP_REV
12, -19, 25, 0,       // STANCE_BOW_1
12, -19, 26, 0,       // STANCE_BOW_2
3, -13, 27, 1,        // STANCE_DEATH_1    
1, -11, 28, 1,        // STANCE_DEATH_2
3, -17, 29, 1,        // STANCE_DEATH_3  
-1, -13, 30, 1,       // STANCE_DEATH_4  
-3, -10, 31, 1,       // STANCE_DEATH_5  
-2, -11, 32, 1,       // STANCE_DEATH_6  
0, 0, 127, 0,         // STANCE_ENTRANCE_1
0, 0, 127, 0,         // STANCE_ENTRANCE_2
0, 0, 127, 0,         // STANCE_ENTRANCE_3
0, 0, 127, 0,         // STANCE_ENTRANCE_4
0, 0, 127, 0,         // STANCE_ENTRANCE_5
0, 0, 127, 0,         // STANCE_ENTRANCE_6
-2, -2, 39, 0,        // STANCE_EAGLE_1  
-2, -11, 40, 0,       // STANCE_EAGLE_2  
-2, -11, 41, 0,       // STANCE_EAGLE_3  
-2, -11, 42, 0,       // STANCE_EAGLE_4  
-2, -2, 39, 1,        // STANCE_EAGLE_1_REV  
-2, -11, 40, 1,       // STANCE_EAGLE_2_REV  
0, 0, 41, 0,          // STANCE_EAGLE_3_REV
0, 0, 42, 0,          // STANCE_EAGLE_4_REV
0, 0, 43, 0,          // STANCE_PRINCESS_SITTING  
0, 0, 44, 0,          // STANCE_PRINCESS_STANDING  
0, 0, 45, 0,          // STANCE_PRINCESS_KISSING  

};    
