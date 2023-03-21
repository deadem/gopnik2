#include "comm.h"
#include "../main.h"
#include "../list.h"
#include "../hero.h"
#include "../game.h"
#include "../utils.h"

extern game *cur_game;

int help()
{
  // объект героя
  hero *main_hero;

  // сообщения функции
  const char *mess[1] = {
      "Ну слушай, %s, в чём тут батва\n\n"};

  main_hero = cur_game->main_hero;

  settextattr(WHITE);
  printw(mess[0], main_hero->get_name());

  switch (cur_game->active_loc)
  {
  case 0:
    printw("%s", "  Чтобы прокачаться, ты должен увеличивать свои навыки. Изначально навыки в\nсумме составляют 12, поэтому вероятность увеличения навыка при получении нового\nуровня понтовости составляет отношение начальной величины этого навыка к 12.\n");
    printw("%s", "  Всего навыков четыре штуки:\n");
    printw("%s", "    Сила      - увеличивает урон и добавляет 1 здоровья\n");
    printw("%s", "    Ловкость  - +5% попадания, если больше 90% то можно бить дважды\n");
    printw("%s", "    Живучесть - 5 здоровья\n");
    printw("%s", "    Удача     - будет чаще везти по жизни\n");
    printw("%s", "  Навыки влияют на следующие характеристики:\n");
    printw("%s", "    Здоровье = 10+Живучесть*5+Сила\n");
    printw("%s", "    Урон     = (Сила/2)мин - (Сила)макс урона который нанесёшь\n");
    printw("%s", "    Точность = 20+Ловкость*5\n");
    printw("%s", "    Броня    - насколько уменьшается сила вражеского удара\n");
    printw("%s", "  Навыки и характеристики могут также повышаться с помощью различных вещей,\nкоторые будут обнаруживаться по ходу игры.\n\n");
    printw("%s", "  На районе есть много разных мест, куда можно зайти на досуге (рынок, притон и\nт.д.) и которые могут давать ряд преимуществ и возможностей. Помни, что при\nсмене района тебе заново придётся осваивать эти места!\n\n");
    printw("%s", "  Ну и напоследок, при смене режима или локации не забывай просматривать новые\nкоманды (для этого нужно набрать i).\n");
    break;

  case 1:
  case 12:
    printw("%s", "  Сейчас ты находишься в режиме битвы. Находится ты тут можешь по двум\nпричинам - либо ты захотел кого-то прикончить, либо кто-то захотел\nприкончить тебя, третьего не дано.\n");
    printw("%s", "  Твоя основная задача на данный момент - выжить. Если вдруг совсем\nприжмёт, то можешь глотнуть пивка или выкурить косячок, что б не сдохнуть.\nТакже можешь позвать подмогу, если у тебя имеется мобила и есть знакомые\nкореша в этом районе.\n");
    printw("%s", "  В случае отпина врага ты получаешь опыт в размере суммы его навыков.\nКроме того, к тебе переходят все его вещи (это могут быть оружие, какие-то\nартефакты, хлам или деньги).\n");
    printw("%s", "  Помни, что помимо снижения здоровья битва черевата переломами челюсти\n(не сможешь жрать, пить и курить) и ноги (не сможешь наносит двойных\nударов).\n");
    break;

  case 2:
    printw("%s", "  У ветеринара ты можешь поправить здоровье. Главное помни, что всё\nстоит денег. Так что, если нет бабла, смысла идти сюда нет никакого.\n");
    break;

  case 3:
  case 11:
    printw("%s", "  На рынке ты можешь приобрести разного рода вещи, либо потискать\nкошельки у лохов - тут главное не попасться, а то могут возникнуть\nбольшие проблемы.\n");
    break;

  case 4:
    printw("%s", "  В притоне тусуются реальные пацаны, много чего можно сделать. Заходи\nсюда почаще. Главное, если дела пойдут плохо, сможешь позвать на помощь\nсвоих корешей - следи за притонной понтовостью.\n");
    break;

  case 5:
    printw("%s", "  Всё то, что нельзя купить на рынке, можно купить у барыг. Также имеется\nвозможность спихнуть им награбленный хлам и продать ненужные вещи.\n");

    if (main_hero->station == 0)
    {
      printw("%s", "  У районных барыг, как правило, не особо большой выбор. Говорят, что\nпо-настоящему здравые вещи можно пробить у барыг на Невском. Правда и\nзаплатить за них придётся немалую цену.\n");
    }
    break;

  case 6:
    printw("%s", "  Если тебе нужны бабки, то ты всегда можешь продать ненужные вещи. Помни,\nчто после продажи выкупить ты уже ничего не сможешь!\n");

    if (main_hero->station == 0)
    {
      printw("%s", "  Правда, районные барыги за них могут дать не так много, как хотелось бы.\nХочешь наварить побольше деньжать - толкай вещи у барыг на Невском.\n");
    }
    break;

  case 7:
    printw("%s", "  В качалке ты можешь поднять свои навыки. Даже если сейчас ты самый\nкрутой, то не факт, что завтра ты останешься таким же. Так что почаще\nсюда заглядывай.\n");
    break;

  case 8:
    printw("%s", " В клубе ты можешь как следуе отдохнуть: потусить на танцполе или\nотдохнуть за кружкой пива в баре.");

    if (main_hero->station)
    {
      printw("%s", " Также можешь попробовать\nзакадрить девчонку (сможешь вписываться у неё на хате, чтобы поправить\nздоровье).");
    }

    printw("%s", "\n");
    break;

  case 9:
    printw("%s", "  Благодаря метро, ты имеешь возможность выбираться из своих ебеней в\nцентр города.\n");
    break;

  case 13:
    printw("%s", "  В слэме ты можешь офигенно прокачать свою ловкость. Чем жёстче слэм,\nтем больше ловкости ты можешь прокачать, но тем опаснее это будет для\nтвоего здоровья.\n");
    break;
  }

  return 0;
}

/*  0
    Чтобы прокачаться, ты должен увеличивать свои навыки. Изначально навыки в сумме
    составляют 12, поэтому вероятность увеличения навыка при получении нового
    уровня понтовости составляет отношение начальной величины этого навыка к 12.

    Всего навыков четыре штуки:

      Сила      - увеличивает урон и довавляет 1 здоровья
      Ловкость  - +5% попадания, если больше 90% то можно бить дважды
      Живучесть - 5 здоровья
      Удача     - будет чаще везти по жизни

    Навыки влияют на следующие характеристики:

      Здоровье = 10+Живучесть*5+Сила
      Урон     = (Сила/2)мин - (Сила)макс урона который нанесёшь
      Точность = 20+Ловкость*5
      Броня    - насколько уменьшается сила вражеского удара

   Навыки и характеристики могут также повышаться с помощью различных вещей,
   которые будут обнаруживаться по ходу игры.

   На районе есть много разных мест, куда можно зайти на досуге (рынок, притон и
   т.д.) и которые могут давать ряд преимуществ и возможностей. Помни, что при
   смене района тебе заново придётся осваивать эти места!

   Ну и напоследок, при смене режима или локации не забывай просматривать новые
   команды (для этого нужно набрать i).
*/

/* 1, 12
     Сейчас ты находишься в режиме битвы. Находится ты тут можешь по двум
   причинам - либо ты захотел кого-то прикончить, либо кто-то захотел
   прикончить тебя, третьего не дано.
     Твоя основная задача на данный момент - выжить. Если вдруг совсем
   прижмёт, то можешь глотнуть пивка или выкурить косячок, что б не сдохнуть.
   Также можешь позвать подмогу, если у тебя имеется мобила и есть знакомые
   кореша в этом районе.
     В случае отпина врага ты получаешь опыт в размере суммы его навыков.
   Кроме того, к тебе переходят все его вещи (это могут быть оружие, какие-то
   артефакты, хлам или деньги).
     Помни, что помимо снижения здоровья битва черевата переломами челюсти
   (не сможешь жрать, пить и курить) и ноги (не сможешь наносит двойных
   ударов).
*/

/* 2
     У ветеринара ты можешь поправить здоровье. Главное помни, что всё
   стоит денег. Так что, если нет бабла, смысла идти сюда нет никакого.
*/

/* 3, 11
     На рынке ты можешь приобрести разного рода вещи, либо потискать
   кошельки у лохов - тут главное не попасться, а то могут возникнуть
   большие проблемы.
*/

/* 4
     В притоне тусуются реальные пацаны, много чего можно сделать. Заходи
   сюда почаще. Главное, если дела пойдут плохо, сможешь позвать на помощь
   своих корешей - следи за притонной понтовостью.
*/

/*
   5
     Всё то, что нельзя купить на рынке, можно купить у барыг. Также имеется
   возможность спихнуть им награбленный хлам и продать ненужные вещи.
     У районных барыг, как правило, не особо большой выбор. Говорят, что
   по-настоящему здравые вещи можно пробить у барыг на Невском. Правда и
   заплатить за них придётся немалую цену.
*/

/*
   6
     Если тебе нужны бабки, то ты всегда можешь продать ненужные вещи. Помни,
   что после продажи выкупить ты уже ничего не сможешь!
     Правда, районные барыги за них могут дать не так много, как хотелось бы.
   Хочешь наварить побольше деньжать - толкай вещи у барыг на Невском.
*/

/*
   7
     В качалке ты можешь поднять свои навыки. Даже если сейчас ты самый
   крутой, то не факт, что завтра ты останешься таким же. Так что почаще
   сюда заглядывай.
*/

/*
   8
     В клубе ты можешь как следуе отдохнуть: потусить на танцполе или
   отдохнуть за кружкой пива в баре. По возможности, можешь закадрить
   девчонку (сможешь вписываться у неё на хате, чтобы поправить здоровье).
*/

/*
   9
     Благодаря метро, ты имеешь возможность выбираться из своих ебеней в
   центр города.
*/

/*
   13
     В слэме ты можешь офигенно прокачать свою ловкость. Чем жёстче слэм,
   тем больше ловкости ты можешь прокачать, но тем опаснее это будет для
   твоего здоровья.
*/
