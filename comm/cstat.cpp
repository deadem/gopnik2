#include <time.h>

#include "comm.h"
#include "../main.h"
#include "../list.h"
#include "../utils.h"
#include "../hero.h"
#include "../game.h"

extern game *cur_game;

void show_timer(time_t); // вывести таймер, отсчитывающего время от данного количества секунд до нуля
void show_timer(time_t sec_amount)
{
  time_t last_time;

  int
      max_da,
      da,
      ch;

  last_time = time(NULL);

  //  _setcursortype (_NOCURSOR);

  max_da = getdigitamount(sec_amount);

  sec_amount++;

  while (sec_amount > 0)
  {
    if ((time(NULL) - last_time) == 1)
    {
      last_time = time(NULL);
      sec_amount--;
      da = getdigitamount(sec_amount);
      while (da < max_da)
      {
        printw("0");
        da++;
      }
      printw("%ld", sec_amount);
#warning Надо разобраться, зачем здесь gotoxy
      //      gotoxy (wherex () - max_da, wherey ());
    }
    if (kbhit())
    {
      ch = getch();

      if (ch == 2)
      {
        break;
      }
    }
  }

  //  gotoxy (wherex () + max_da, wherey ());

  showcursor();
}

int cstat(
    int index)
{
  // объект героя
  hero *main_hero;

  // сообщения функции
  const char *mess[4] = {
      "Ты щас на этой станции находишься\n",
      "\nТы приехал на станцию \"%s\"\n",
      "Ты вошёл в вагон и тебя со всех сторон сжала толпа.\nВ воздухе пронёсся голос машиниста:\n-Чё за мудаки держат двери?! Ща выйду - въебу!\nПоезд дёрнулся и понёсся по тёмному тоннелю...",
      "До прибытия на станцию осталось "};

  main_hero = cur_game->main_hero;

  int
      // время следования до станции
      time;

  if (
      (index < 0) ||
      (index >= cur_game->stn_amount))
  {
    return 0;
  }

  if (index != main_hero->station)
  {
    if (cur_game->stn[index].avail)
    {
      time = (main_hero->station - index) * 10;

      if (time < 0)
      {
        time *= (-1);
      }

      if (
          (main_hero->station == 0) ||
          (index == 0))
      {
        main_hero->station = index;

        cur_game->new_station();
      }
      else
      {
        main_hero->station = index;
      }

      settextattr(14);
      printw("%s", mess[2]);

      settextattr(9);
      printw("%s", mess[3]);

      show_timer(time);

      settextattr(15);
      printw(mess[1], cur_game->stn[index].name);
    }
    else
    {
      settextattr(12);
      printw("%s", cur_game->stn[index].unavail_reason);
    }
  }
  else
  {
    settextattr(12);
    printw("%s", mess[0]);
  }

  return 0;
}
