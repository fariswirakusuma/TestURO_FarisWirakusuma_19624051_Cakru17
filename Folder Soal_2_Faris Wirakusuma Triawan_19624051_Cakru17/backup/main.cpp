#include <iostream>
#include <raylib.h>
#include <cmath>
#include <string>
#include <chrono>
#include <thread>     

using namespace std;

typedef enum GameScreen{Pilih_Robot,Battle,Hasil}GameScreen;
GameScreen current_Scene = Pilih_Robot;



int main (void) {

    const int screenWidth = 800;
    const int screenHeight = 600;
    const int RobotWidth = 60;
    const int RobotHeight = 60;

    using namespace std::this_thread;
    using namespace std::chrono;

    int damage = 0;


    string Inplayer1 = "true";
    string Inplayer2 = "false";
    string battlelogging = "false";
    string logging = "false";

    string OpeningBattleScene = "yes";

    const Vector2 PosisiRobot_1 = Vector2{100,100};
    const Vector2 PosisiRobot_2 = Vector2{300,100};
    const Vector2 PosisiRobot_3 = Vector2{500,100};
    const Vector2 PosisiRobot_4 = Vector2{700,100};
    const Vector2 ButtonPos = Vector2{400,550};

    string Robot_Player1= "none";
    string Robot_Player2= "none";

    string giliran = "player1";
    string pemenang = "none";
    

    int player1_healthSkrg=0;
    int player2_healthSkrg=0;


    int Robot_Player1Stat[]={1,0};
    int Robot_Player2Stat[]={1,0};
    

    SetTargetFPS(60);
    InitWindow(screenWidth, screenHeight, "Robot_Battle");


    while (WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(BLUE);

        const Vector2 MousePos = GetMousePosition();
        
        Color Robot_Player1Color;
        Color Robot_Player2Color;

        Color Robot1_Color = MAROON;
        Color Robot2_Color = WHITE;
        Color Robot3_Color = GREEN;
        Color Robot4_Color = PURPLE;
        


        //array = Health,Damage
        int Robot_1[]={100,GetRandomValue(10,20)};
        int Robot_2[]={200,GetRandomValue(5,10)};
        int Robot_3[]={50,GetRandomValue(15,50)};
        int Robot_4[]={90,GetRandomValue(15,18)};


        switch (current_Scene)
        {
            case Pilih_Robot:{
                DrawText("Pilih Robot",310,50,30,WHITE);
                DrawText("Player1",100,200,30,WHITE);
                DrawText("Player2",600,200,30,WHITE);
                DrawCircle(ButtonPos.x,ButtonPos.y,10,RED);

                DrawRectangle(PosisiRobot_1.x,PosisiRobot_1.y,RobotWidth,RobotHeight,Robot1_Color);
                DrawRectangle(PosisiRobot_2.x,PosisiRobot_2.y,RobotWidth,RobotHeight,Robot2_Color);
                DrawRectangle(PosisiRobot_3.x,PosisiRobot_3.y,RobotWidth,RobotHeight,Robot3_Color);
                DrawRectangle(PosisiRobot_4.x,PosisiRobot_4.y,RobotHeight,RobotHeight,Robot4_Color);

                

                if (Inplayer1 == "true"){
                    DrawText("Player1",ButtonPos.x-150,535,30,WHITE);
                }
                else if (Inplayer2 == "true"){
                    DrawText("Player2",ButtonPos.x-150,535,30,WHITE);
                }

                 if (Robot_Player2 == "RoboOne"){
                    DrawText("RoboOne",600,350,30,WHITE);
                    Robot_Player2Color = Robot1_Color;
                    for (int i = 0; i<2;i++){
                        Robot_Player2Stat[i]=Robot_1[i];
                    };
                }
                else if (Robot_Player2 == "RoboTwo"){
                    DrawText("RoboTwo",600,350,30,WHITE);
                    Robot_Player2Color = Robot2_Color;
                    for (int i = 0; i<2;i++){
                        Robot_Player2Stat[i]=Robot_2[i];
                    };
                }
                else if (Robot_Player2 == "RoboThree"){
                    DrawText("RoboThree",600,350,30,WHITE);
                    Robot_Player2Color = Robot3_Color;
                    for (int i = 0; i<2;i++){
                        Robot_Player2Stat[i]=Robot_3[i];
                    };
                }
                else if (Robot_Player2 == "RoboFour"){
                    DrawText("RoboFour",600,350,30,WHITE);
                    Robot_Player2Color = Robot4_Color;
                    for (int i = 0; i<2;i++){
                        Robot_Player2Stat[i]=Robot_4[i];
                    };
                }

                if (Robot_Player1 == "RoboOne"){
                    
                    DrawText("RoboOne",100,350,30,WHITE);
                    Robot_Player1Color = Robot1_Color;
                    for (int i = 0; i<2;i++){
                        Robot_Player1Stat[i]=Robot_1[i];
                    };
                }
                else if (Robot_Player1 == "RoboTwo"){
                    DrawText("RoboTwo",100,350,30,WHITE);
                    Robot_Player1Color = Robot2_Color;
                    for (int i = 0; i<2;i++){
                        Robot_Player1Stat[i]=Robot_2[i];
                    };
                }
                else if (Robot_Player1 == "RoboThree"){
                    DrawText("RoboThree",100,350,30,WHITE);
                    Robot_Player1Color = Robot3_Color;
                    for (int i = 0; i<2;i++){
                        Robot_Player1Stat[i]=Robot_3[i];
                    };
                }
                else if (Robot_Player1 == "RoboFour"){
                    DrawText("RoboFour",100,350,30,WHITE);
                    Robot_Player1Color = Robot4_Color;
                    for (int i = 0; i<2;i++){
                        Robot_Player1Stat[i]=Robot_4[i];
                    };
                }


                

                if (Robot_Player1 != "none" and Robot_Player2 != "none" ){
                    DrawText("Press Space To Continued",200,470,30,WHITE);
                    if (IsKeyPressed(KEY_SPACE)){
                        current_Scene = Battle;
                    }
                }
                
                
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    if(abs(floorf(MousePos.x)-ButtonPos.x)<=6.0f && abs(floorf(MousePos.y)-ButtonPos.y)<=6.0f){
                        if (Inplayer1 == "false"){
                            Inplayer1 = "true";
                            Inplayer2 = "false";
                        }
                        else if (Inplayer2 == "false"){
                            Inplayer2 = "true";
                            Inplayer1 = "false";
                        }
                        
                        printf("Work");
                    }
                    if  (abs(PosisiRobot_1.x-floorf(MousePos.x))<=float(RobotWidth) && abs(PosisiRobot_1.y-floorf(MousePos.y))<=float(RobotHeight)){
                        if (Inplayer1 == "true"){
                            Robot_Player1 = "RoboOne";
                            
                        }
                        else if (Inplayer2 == "true"){
                            Robot_Player2 = "RoboOne";
                        }
                    }
                     if (abs(PosisiRobot_2.x-floorf(MousePos.x))<=float(RobotWidth) && abs(PosisiRobot_2.y-floorf(MousePos.y))<=float(RobotHeight)){
                        if (Inplayer1 == "true"){
                            Robot_Player1 = "RoboTwo";
                        }
                        else if (Inplayer2 == "true"){
                            Robot_Player2 = "RoboTwo";
                        }
                     }
                     if (abs(PosisiRobot_3.x-floorf(MousePos.x))<=float(RobotWidth) && abs(PosisiRobot_3.y-floorf(MousePos.y))<=float(RobotHeight)){
                        if (Inplayer1 == "true"){
                            Robot_Player1 = "RoboThree";
                            
                        }
                        else if (Inplayer2 == "true"){
                            Robot_Player2 = "RoboThree";
                        }
                        
                    }
                     if (abs(PosisiRobot_4.x-floorf(MousePos.x))<=float(RobotWidth) && abs(PosisiRobot_1.y-floorf(MousePos.y))<=float(RobotHeight)){
                        if (Inplayer1 == "true"){
                            Robot_Player1 = "RoboFour";
                            
                        }
                        else if (Inplayer2 == "true"){
                            Robot_Player2 = "RoboFour";
                        }
                        
                    }
                  }
                    
                }break;
                
             case Battle:{
                if (OpeningBattleScene == "yes"){
                    player1_healthSkrg = Robot_Player1Stat[0];
                    player2_healthSkrg = Robot_Player2Stat[0]+GetRandomValue(7,35);
                    printf("y");
                    OpeningBattleScene = "no";

                }
                

                DrawText("Player 1",100,100,30,WHITE);
                DrawText("Player 2",600,100,30,WHITE);

                DrawText(TextFormat("Health: %i",player1_healthSkrg),100,400,30,PINK);
                DrawText(TextFormat("Health: %i",player2_healthSkrg),600,400,30,PINK);

                DrawRectangle(100,300,RobotWidth,RobotHeight,Robot_Player1Color);
                DrawRectangle(600,300,RobotWidth,RobotHeight,Robot_Player2Color);
                if (giliran == "player1" && player2_healthSkrg > 0){
                    if (IsKeyPressed(KEY_ENTER)){
                        battlelogging = "true";
                        player2_healthSkrg = player2_healthSkrg - Robot_Player1Stat[1];
                        printf("Gantian1");
                        damage = player2_healthSkrg - Robot_Player1Stat[1];
                        giliran = "player2";
                        
                    }
                }
                else if (giliran == "player2" && player1_healthSkrg > 0){
                    if (IsKeyPressed(KEY_ENTER)){
                        player1_healthSkrg = player1_healthSkrg - Robot_Player2Stat[1];
                        printf("Gantian1");
                        damage = player1_healthSkrg - Robot_Player2Stat[1];
                        giliran = "player1";
                    }
                }
                if (player1_healthSkrg <= 0){
                    pemenang = "player 2";
                    current_Scene = Hasil;
                }
                else if (player2_healthSkrg <= 0){
                    pemenang = "player 1";
                    current_Scene = Hasil;
                }
                if(battlelogging == "true"&& giliran == "player1"){
                    DrawText(Robot_Player1.c_str(),50,50,30,GRAY);
                    DrawText("Attacks",250,50,30,GRAY);
                    DrawText(Robot_Player2.c_str(),450,50,30,GRAY);
                    DrawText(TextFormat("for %i",damage),650,50,30,GRAY);

                    logging = "true";
                }
                else if(battlelogging == "true" && giliran == "player2"){
                    DrawText(Robot_Player1.c_str(),50,50,30,GRAY);
                    DrawText("Attacks",250,50,30,GRAY);
                    DrawText(Robot_Player2.c_str(),450,50,30,GRAY);
                    DrawText(TextFormat("for %i",damage),650,50,30,GRAY);

                    logging = "true";

                }
            }break;
             case Hasil:{
                if (pemenang != "none"){
                    DrawText()
                    DrawText(pemenang.c_str(),345,300,50,WHITE);
                }
             }               
        }EndDrawing();
    }
}

