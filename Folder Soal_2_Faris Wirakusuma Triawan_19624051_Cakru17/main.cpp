#include <iostream>
#include <raylib.h>
#include <cmath>
#include <string>
#include <chrono>
#include <thread>     

using namespace std;

typedef enum GameScreen{Pilih_Robot,Battle,Hasil}GameScreen;
GameScreen current_Scene = Pilih_Robot;
    Color robotColors[4]={
        MAROON, WHITE, GREEN, PURPLE
    };

class Robot{
    public:
    int health;
    int attack;
    int robot; 
    int player;
    string robotName = "";

    int robotStats[4][2]={
        {100,GetRandomValue(10,20)},
        {200,GetRandomValue(5,10)}
        ,{50,GetRandomValue(15,50)}
        ,{90,GetRandomValue(15,18)}
    };
    Color color = WHITE;
    void setRobot(int robot){
        this->robot = robot;
        robotName = "Robo "+ to_string(robot);
    }
    Robot(int robot, int player){
        printf("test");
        setRobot(robot);
        color = robotColors[robot-1];
        health=robotStats[robot-1][0];
        attack=robotStats[robot-1][1];
        this->player=player;
    }
};

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

    string Player1Ready = "false";
    string Player2Ready = "false";

    string OpeningBattleScene = "yes";

    const Vector2 PosisiRobot_1 = Vector2{100,100};
    const Vector2 PosisiRobot_2 = Vector2{300,100};
    const Vector2 PosisiRobot_3 = Vector2{500,100};
    const Vector2 PosisiRobot_4 = Vector2{700,100};
    const Vector2 ButtonPos = Vector2{470,550};

    Robot* Robot_Player1 = new Robot(1,1);
    Robot* Robot_Player2 = new Robot(1,1);

    string giliran = "player1";
    string pemenang = "none";
    string losser = "none";

    int player1_healthSkrg=0;
    int player2_healthSkrg=0;


    

    SetTargetFPS(60);
    InitWindow(screenWidth, screenHeight, "Robot_Battle");


    while (WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(BLUE);

        const Vector2 MousePos = GetMousePosition();
        
        //array = Health,Damage
        


        switch (current_Scene)
        {
            case Pilih_Robot:{
                DrawText("Pilih Robot",310,50,30,WHITE);
                DrawText("Player1",100,200,30,WHITE);
                DrawText("Player2",600,200,30,WHITE);
                DrawCircle(ButtonPos.x,ButtonPos.y,10,RED);

                DrawRectangle(PosisiRobot_1.x,PosisiRobot_1.y,RobotWidth,RobotHeight,robotColors[0]);
                DrawRectangle(PosisiRobot_2.x,PosisiRobot_2.y,RobotWidth,RobotHeight,robotColors[1]);
                DrawRectangle(PosisiRobot_3.x,PosisiRobot_3.y,RobotWidth,RobotHeight,robotColors[2]);
                DrawRectangle(PosisiRobot_4.x,PosisiRobot_4.y,RobotHeight,RobotHeight,robotColors[3]);

                

                if (Inplayer1 == "true"){
                    DrawText("Player1",ButtonPos.x-150,535,30,WHITE);
                }
                else if (Inplayer2 == "true"){
                    DrawText("Player2",ButtonPos.x-150,535,30,WHITE);
                }
                
                if (Player1Ready == "true" && Player2Ready == "true" ){
                    DrawText("Press Space To Continued",200,470,30,WHITE);
                    if (IsKeyPressed(KEY_SPACE)){
                        current_Scene = Battle;
                    }
                }

                if (Player1Ready == "true"){
                    DrawText(Robot_Player1->robotName.c_str(),100,350,30,WHITE);
                }
                if (Player2Ready == "true"){
                    DrawText(Robot_Player2->robotName.c_str(),600,350,30,WHITE);
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
                            Robot_Player1->setRobot(1);
                            Robot_Player1 = new Robot(1,1);
                            Player1Ready = "true";

                            
                        }
                        else if (Inplayer2 == "true"){
                            Robot_Player2->setRobot(1);
                            Robot_Player2 = new Robot(1,2);
                            Player2Ready = "true";
                        }
                    }
                     if (abs(PosisiRobot_2.x-floorf(MousePos.x))<=float(RobotWidth) && abs(PosisiRobot_2.y-floorf(MousePos.y))<=float(RobotHeight)){
                        if (Inplayer1 == "true"){
                            Robot_Player1->setRobot(2);
                            Robot_Player1 = new Robot(2,1);
                            Player1Ready = "true";
                        }
                        else if (Inplayer2 == "true"){
                            Robot_Player2->setRobot(2);
                            Robot_Player2 = new Robot(2,2);
                            Player2Ready = "true";
                        }
                     }
                     if (abs(PosisiRobot_3.x-floorf(MousePos.x))<=float(RobotWidth) && abs(PosisiRobot_3.y-floorf(MousePos.y))<=float(RobotHeight)){
                        if (Inplayer1 == "true"){
                            Robot_Player1->setRobot(3);
                            Robot_Player1 = new Robot(3,1);
                            Player1Ready = "true";
                        }
                        else if (Inplayer2 == "true"){
                            Robot_Player2->setRobot(3);
                            Robot_Player2 = new Robot(3,2);
                            Player2Ready = "true";
                        }
                        
                    }
                     if (abs(PosisiRobot_4.x-floorf(MousePos.x))<=float(RobotWidth) && abs(PosisiRobot_1.y-floorf(MousePos.y))<=float(RobotHeight)){
                        if (Inplayer1 == "true"){
                            Robot_Player1->setRobot(4);
                            Robot_Player1 = new Robot(4,1);
                            Player1Ready = "true";
                            
                        }
                        else if (Inplayer2 == "true"){
                            Robot_Player2->setRobot(4);
                            Robot_Player2 = new Robot(4,2);
                            Player2Ready = "true";
                        }
                        
                    }
                  }
                    
                }break;
                
             case Battle:{
                if (OpeningBattleScene == "yes"){
                    player1_healthSkrg = Robot_Player1->health;
                    player2_healthSkrg = Robot_Player2->health+GetRandomValue(7,35);
                    damage = 1;

                    printf("y");
                    OpeningBattleScene = "no";

                }
                

                DrawText((Robot_Player1->robotName).c_str(),100,100,30,WHITE);
                DrawText((Robot_Player2->robotName).c_str(),600,100,30,WHITE);

                DrawText(TextFormat("Health: %i",player1_healthSkrg),100,400,30,PINK);
                DrawText(TextFormat("Health: %i",player2_healthSkrg),600,400,30,PINK);
                DrawText("Press Enter to Attack",250,500,30,GREEN);



                DrawRectangle(130,300,RobotWidth,RobotHeight,Robot_Player1->color);
                DrawRectangle(630,300,RobotWidth,RobotHeight,Robot_Player2->color);
                if (giliran == "player1" && player2_healthSkrg > 0){
                    DrawText((Robot_Player1->robotName+" Turn").c_str(),320,450,30,Robot_Player1->color);
                    if (IsKeyPressed(KEY_ENTER)){
                        battlelogging = "true";
                        player2_healthSkrg = player2_healthSkrg - Robot_Player1->attack;
                        printf("Gantian1");
                        damage = Robot_Player1->attack;
                        giliran = "player2";
                    }
                }
                else if (giliran == "player2" && player1_healthSkrg > 0){
                    DrawText((Robot_Player2->robotName+" Turn").c_str(),320,450,30,Robot_Player2->color);
                    if (IsKeyPressed(KEY_ENTER)){
                        player1_healthSkrg = player1_healthSkrg - Robot_Player2->attack;
                        printf("Gantian1");
                        damage = Robot_Player2->attack;
                        giliran = "player1";
                    }
                }
                if (player1_healthSkrg <= 0){
                    pemenang = "player 2";
                    losser = "player 1";
                    current_Scene = Hasil;
                }
                else if (player2_healthSkrg <= 0){
                    pemenang = "player 1";
                    losser = "player 2";
                    current_Scene = Hasil;
                }
                if(battlelogging == "true"&& giliran == "player1"){
                    DrawText(Robot_Player1->robotName.c_str(),50,50,30,GRAY);
                    DrawText("Attacks",250,50,30,GRAY);
                    DrawText(Robot_Player2->robotName.c_str(),450,50,30,GRAY);
                    DrawText(TextFormat("for %i",damage),600,50,30,GRAY);

                    //logging = "true";
                }
                else if(battlelogging == "true" && giliran == "player2"){
                    DrawText(Robot_Player2->robotName.c_str(),50,50,30,GRAY);
                    DrawText("Attacks",250,50,30,GRAY);
                    DrawText(Robot_Player1->robotName.c_str(),450,50,30,GRAY);
                    DrawText(TextFormat("for %i",damage),600,50,30,GRAY);

                    //logging = "true";

                }
            }break;
             case Hasil:{
                if (pemenang == "player 1"){
                    DrawText((Robot_Player2->robotName+" is Defeated").c_str(),140,100,50,RED);
                    DrawText((Robot_Player1->robotName+"Wins").c_str(),145,300,50,WHITE);
                }
                else if (pemenang == "player 2"){
                    DrawText((Robot_Player1->robotName+" is Defeated").c_str(),140,100,50,RED);
                    DrawText((Robot_Player2->robotName+" Wins").c_str(),145,300,50,WHITE);
                }
             }               
        }EndDrawing();
    }
}

