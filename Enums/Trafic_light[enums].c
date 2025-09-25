#include <stdio.h>
#include <unistd.h>

enum TraficLight
{
  RED,
  YELLOW,
  GREEN
};

enum TraficLight nextLight(enum TraficLight current)
{
  switch (current)
  {
    case RED: return GREEN;
    case GREEN: return YELLOW;
    case YELLOW: return RED;
    default: return RED;
  }
}

void printAction(enum TraficLight light)
{
  switch (light) 
  {
    case RED: printf("STOP! \n"); break;
    case YELLOW: printf("GET READY! \n"); break;
    case GREEN: printf("GO! \n"); break;
  }
}

int main(int argc, char *argv[])
{
  enum TraficLight light = RED;

  for (int i = 0; i < 10; i++)
  {
    printAction(light);
    sleep(1);
    light = nextLight(light);
  }

  return 0;
}
