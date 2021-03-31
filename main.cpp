#include <bits/stdc++.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

typedef long double ld;
typedef long long ll;
vector<vector<int>> screenA(200);
vector<char[200]> frame_buff_0(200);
vector<char[200]> frame_buff_1(200);
bool buff_num = true;
vector<vector<bool>> screenB(200);




ld R = 20; // centerDistance
ld radius = 10;
ld pi = 3.1415926535897932384626433832795028841971693993751058209749445923;
string charlist = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/()1{}[]?-_+~<>i!lI;:,\"^`'. ";



void gotoxy(int x, int y) { 
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void clearC() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    // FillConsoleOutputAttribute(
    //     console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
    //     screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    // );
    SetConsoleCursorPosition(console, topLeft);
}

void clearBuff0(int height=100, int width=100)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
         frame_buff_0[y][x] = ' ';
        }
        frame_buff_0[y][width+1] = '\0';
    }
}
void clearBuff1(int height=100, int width=100)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
         frame_buff_1[y][x] = ' ';
        }
        frame_buff_1[y][width+1] = '\0';
    }
}


void *renderer(void *arg)
{
    int cnt = 0;
    while (true)
    {
        while (!buff_num)
        {
            gotoxy(0,0);
            for (int y = 0; y < 40; y++)
            {
                printf("%s\n", frame_buff_0[y]);
            }
        }
        while (buff_num)
        {
            gotoxy(0,0);
            for (int y = 0; y < 40; y++)
            {
                printf("%s\n", frame_buff_1[y]);
            }

        }
    }
    pthread_exit(NULL);
}



int main(){
    // cin.tie(nullptr);

    pthread_t thread1;
    pthread_create(&thread1, NULL, renderer, NULL);

    for (int i = 0; i < 200; i++)
    {
        screenA[i] = vector<int>(200);
        screenB[i] = vector<bool>(200);
    }
    // printf("\033[2J");
    clearC();
    ld q = 0;
    for (int i = 0; i < 10000000; i++)
    {
        for (int thetam = 0; thetam < 100; thetam++)
        {
            for (int rhom = 0; rhom < 100; rhom++)
            {
                ld theta = thetam*pi/50;
                ld rho = rhom*pi/50;
                int x = (R + radius*cos(theta))*cos(rho);
                int y = ((R + radius*cos(theta))*sin(rho));
                int z = radius*sin(theta);
                
                z = z*cos(q) - x*sin(q);
                x = z*sin(q) + x*cos(q);
                y = y;

                

                x+=40;
                y= y/2 + 20;
                // printf("z%d\n",z);
                // Sleep(100);
                if (screenA[y][x]<=z){
                screenA[y][x] = z;
                screenB[y][x] = true;
                }
                // if (false)
                // {
                // // cout << "\033[" << y << ";" << x <<"f";
                // // gotoxy(x,y);
                // // cout << "\033["<< 230 + z << "m"; // 40
                // // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30+z % 15);
                // // cout << "\033[" << 38 << ';' << 2 << ';' << z << ';' << z << ';' << z <<'m'; // 40
                // cout << '.';
                // }
                
            }
        }

        q+=pi/80;

        
        // clearC();
        // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);


        if (buff_num)
        {
            clearBuff0();
        }
        else
        {
            clearBuff1();
        }


        
        for (int yy = 0; yy < 40; yy++)
        {
            for (int xx = 0; xx < 100; xx++)
            {
                int dep = screenA[yy][xx];
                if (screenB[yy][xx])
                {
                    // cout << "\033[" << y << ";" << x <<"f";
                    // gotoxy(xx,yy);
                    // cout << "\033["<< 230 + z << "m"; // 40
                    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30 - dep);
                    // if (dep == 0) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);cout << ':';}
                    // if (1<= dep && dep <= 4) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);cout << ';';}
                    // if (5<= dep && dep <= 8) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);cout << 'o';}
                    // if (9<= dep && dep <= 12) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);cout << '#';}
                    // if (13<= dep ) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);cout << '#';}
                    // if (-4<= dep && dep <= -1) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);cout << ',';}
                    // if (-8<= dep && dep <= -5) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);cout << '.';}
                    // if (-12<= dep && dep <= -9) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);cout << '.';}
                    // if ( dep <= -13) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);cout << '.';}
                    // cout << charlist[35-dep];
                    if (buff_num)
                    {
                        frame_buff_0[yy][xx] = charlist[35-dep];
                    }
                    else
                    {
                        frame_buff_1[yy][xx] = charlist[35-dep];
                    }
                    
                    // if (dep == 0) { cout << ':';}
                    // if (1<= dep && dep <= 4) { cout << ';';}
                    // if (5<= dep && dep <= 8) { cout << 'o';}
                    // if (9<= dep && dep <= 12) { cout << '#';}
                    // if (13<= dep ) { cout << '#';}
                    // if (-4<= dep && dep <= -1) { cout << ',';}
                    // if (-8<= dep && dep <= -5) { cout << '.';}
                    // if (-12<= dep && dep <= -9) { cout << '.';}
                    // if ( dep <= -13) { cout << '.';}

                    // cout << "\033[" << 38 << ';' << 2 << ';' << z << ';' << z << ';' << z <<'m'; // 40
                    
                }
            }
            
        }
        buff_num ^= true;
        Sleep(133);
        for (int i = 0; i < 200; i++)
        {
            for (int o = 0; o < 200; o++)
            {
                screenA[i][o] = -100000;
                screenB[i][o] = false;
            }
        }
        
        
        
    }
    
    
}