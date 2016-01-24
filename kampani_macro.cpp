#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#define woutput(str) wcout << (str) << endl;
#define output(str) cout << (str) << endl;

#define optionx 812
#define option1y 410
#define option2y 457
#define option3y 495
#define sectionx 379
#define episodex 379
#define episode1y 350
#define episode8y 682
#define section1y 354
#define section5y 663
#define questx 473
#define questy 460
#define backx 281
#define backy 270

void comment(string str)
{
  cout << "' " << str << endl;
}
int getSectionY(int i)
{
  double interval = (section5y - section1y) / 4;
  return (int)((double)section1y + (i - 1) * interval);
}
int getEpisodeY(int i)
{
  double interval = (episode8y - episode1y) / 7;
  return (int)((double)episode1y + (i - 1) * interval);
}

void wait_ms(int ms)
{
  cout << ms << endl;
}
void wait_s(int s)
{
  wait_ms(s*1000);
}

void click(int x, int y) {
  cout << "LMouCl Down (" << to_string(x) << ", " << to_string(y) << ")" << endl;  
  wait_ms(100);
  cout << "LMouCl Up (" << to_string(x) << ", " << to_string(y) << ")" << endl;  
  wait_ms(500);
}

void def(string s, int val)
{
  cout << "#" << s << "=" << val << endl;
}

void gotoHome(void)
{
  wait_ms(500);

  click(80, 150);
  output("Home");
  click(821, 437);
}

void repStart(int num)
{
  cout << "<r " << num << ">" << endl;
}
void repEnd(void)
{
  cout << "</r>" << endl;
}
void clickSpeedingUp(void)
{
  click(1114, 592);
}

void clickReward(void)
{
  repStart(20); {
    click(944, 348);
  } repEnd();
}

// Mag 60, 40, Sol 50, 60
void enterLabyrinth(string route)
{
  // Quest Button title
  click(questx, questy); wait_s(5); click(228, 376); wait_s(5);

  click(backx, backy); click(backx, backy); // 戻る
  click(862, 490); click(1008, 591); click(613, 539); wait_s(2); click(812, 398); // 無限選択

  wait_s(15);
  clickSpeedingUp();

  if (route == "1112") {
    click(optionx, option1y);
    wait_s(60);
    click(optionx, option1y);
    wait_s(90);
    click(optionx, option1y);
    wait_s(90);
    click(optionx, option2y);
    wait_s(120);
  } else {
    cerr << "No Labyrinth quest" << endl;
    exit(1);
  }

  clickReward();
}

// Mag 60, 40, Sol 50, 60
void enterNormal(int section, int episode)
{
  // Quest Button title
  click(questx, questy); wait_s(5); click(228, 376); wait_s(5);

  click(backx, backy); click(backx, backy); // 戻る
  click(329, 381);
  click(sectionx, getSectionY(section));
  click(episodex, getEpisodeY(episode));

  wait_s(5);

  click(1020, 590); wait_s(1);
  click(634, 549); wait_s(1);

  wait_s(10);
  clickSpeedingUp();

  if (section == 4 && episode == 6) {
    wait_s(110);
    click(optionx, option1y);
    wait_s(80);
  } else if (section == 3 && episode == 1) {
    wait_s(130);
  } else {
    cerr << "No Normal quest" << endl;
    exit(1);
  }

  clickReward();
}

void enterAnn(void)
{
  // Quest Button title
  click(questx, questy); wait_s(5); click(228, 376); wait_s(5);

  click(1117, 271); // character story
  wait_s(5);
  click(504, 489); // kurerikku
  wait_s(2);
  click(392, 679); // ann
  wait_s(2);
  click(664,424); // epi2
  wait_s(2);
  click(1077,660); // enter 
  wait_s(2);
  click(624,540); // enter2

  wait_s(16);
  clickSpeedingUp();

  wait_s(280);

  clickReward();
}

int main(void)
{
  gotoHome();
  repStart(8); {
    comment("Normal"); 
    repStart(2); {
      enterNormal(3, 1);
    } repEnd();
    /*
       comment("Ann"); 
       repStart(1); {
       enterAnn();
       } repEnd();
       */

    comment("Labyrinth"); 
    repStart(1); {
      enterLabyrinth("1112");
    } repEnd();
  } repEnd();

  return 0;
}
