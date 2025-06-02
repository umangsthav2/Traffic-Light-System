#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

int unsigned timerValue = 3;

void setTimer()
{
    printf("Current Timer Value:%d", timerValue);
    printf("\nEnter new timer value:");
    scanf("%d", &timerValue);
}

void automaticControl()
{
    printf("Automatic Control Enabled !!!\nPress any key to interupt");
    
    while (!kbhit())
    {
        // Activate RED Light
        delay(timerValue * 1000);
        setfillstyle(SOLID_FILL, RED);
        floodfill(150, getmaxy() / 2, WHITE);

        setfillstyle(SOLID_FILL, BLACK);
        floodfill(getmaxx() / 2, getmaxy() / 2, WHITE);

        setfillstyle(SOLID_FILL, BLACK);
        floodfill(480, getmaxy() / 2, WHITE);

        // Activate YELLOW Light
        delay(timerValue * 1000);
        setfillstyle(SOLID_FILL, BLACK);
        floodfill(150, getmaxy() / 2, WHITE);

        setfillstyle(SOLID_FILL, YELLOW);
        floodfill(getmaxx() / 2, getmaxy() / 2, WHITE);

        setfillstyle(SOLID_FILL, BLACK);
        floodfill(480, getmaxy() / 2, WHITE);

        // Activate GREEN Light
        delay(timerValue * 1000);
        setfillstyle(SOLID_FILL, BLACK);
        floodfill(150, getmaxy() / 2, WHITE);

        setfillstyle(SOLID_FILL, BLACK);
        floodfill(getmaxx() / 2, getmaxy() / 2, WHITE);

        setfillstyle(SOLID_FILL, GREEN);
        floodfill(480, getmaxy() / 2, WHITE);

        // Activate YELLOW Light
        delay(timerValue * 1000);
        setfillstyle(SOLID_FILL, BLACK);
        floodfill(150, getmaxy() / 2, WHITE);

        setfillstyle(SOLID_FILL, YELLOW);
        floodfill(getmaxx() / 2, getmaxy() / 2, WHITE);

        setfillstyle(SOLID_FILL, BLACK);
        floodfill(480, getmaxy() / 2, WHITE);
    }
}

void manualOverride()
{
    printf("Press {R,Y,G} for lights control");
    int ch;
    while ((ch = getch()) != 27)
    {
        switch (ch)
        {

        case 48: exit(0);

        case 82:
        case 114:
            // Activate RED Light
            setfillstyle(SOLID_FILL, RED);
            floodfill(150, getmaxy() / 2, WHITE);

            // Deactivate Yellow Light
            setfillstyle(SOLID_FILL, BLACK);
            floodfill(getmaxx() / 2, getmaxy() / 2, WHITE);

            // Deactivate Green Light
            setfillstyle(SOLID_FILL, BLACK);
            floodfill(480, getmaxy() / 2, WHITE);
            break;

        case 89:
        case 121:

            // Deactivate RED Light
            setfillstyle(SOLID_FILL, BLACK);
            floodfill(150, getmaxy() / 2, WHITE);

            // Activate Yellow Light
            setfillstyle(SOLID_FILL, YELLOW);
            floodfill(getmaxx() / 2, getmaxy() / 2, WHITE);

            // Deactivate Green Light
            setfillstyle(SOLID_FILL, BLACK);
            floodfill(480, getmaxy() / 2, WHITE);
            break;

        case 71:
        case 103:
            // Deactivate RED Light
            setfillstyle(SOLID_FILL, BLACK);
            floodfill(150, getmaxy() / 2, WHITE);

            // Deactivate Yellow Light
            setfillstyle(SOLID_FILL, BLACK);
            floodfill(getmaxx() / 2, getmaxy() / 2, WHITE);

            // Activate Green Light
            setfillstyle(SOLID_FILL, GREEN);
            floodfill(480, getmaxy() / 2, WHITE);
            break;

        default:
            printf("Invalid Option\n");
            break;
        }
    }
}

void userMenu()
{
    int inp;
    while (1)
    {
    system("cls");
    printf("Welcome to Nirdip Traffic Light System\nChoose your option");
    printf("\n\n");
    printf("1. Automatic Control\n");
    printf("2. Manual Control\n");
    printf("3. Set Timer\n");
        printf("\nYour Option:");
        scanf("%d", &inp);
        switch (inp)
        {

        case 0:
            exit(0);
            break;

        case 1:
            automaticControl();
            break;
        case 2:
            manualOverride();
            break;
        case 3:
            setTimer();
            break;
        default:
            printf("Invalid Choice");
            break;
        }
    }
}

int main(void)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int inp;

    //Initial Traffic Lights
    setcolor(WHITE);
    circle(150, getmaxy() / 2, 50);

    circle(getmaxx() / 2, getmaxy() / 2, 50);

    circle(480, getmaxy() / 2, 50);

    // User Menu:
    userMenu();

    getch();
    closegraph();
    return 0;
}