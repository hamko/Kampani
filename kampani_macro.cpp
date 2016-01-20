#include <iostream>
#include <string>
using namespace std;
#define woutput(str) wcout << (str) << endl;
#define output(str) cout << (str) << endl;

#define optionx 812
#define option1y 410
#define option2y 457
#define option3y 495
#define episodex 379
#define episode1y 350
#define episode8y 682
#define questx 473
#define questy 460
#define backx 281
#define backy 270

void comment(string str)
{
  cout << "' " << str << endl;
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
  repStart(10); {
    click(944, 348);
  } repEnd();
}

void enterLabyrinth1112(void)
{
  click(questx, questy); // クエストボタン
  wait_s(5); // クエストロード

  click(backx, backy); click(backx, backy); // 戻る
  click(862, 490); click(1008, 591); click(613, 539); click(812, 398); // 無限選択

  wait_s(15);
  clickSpeedingUp();

  click(optionx, option1y);
  wait_s(120);
  click(optionx, option1y);
  wait_s(150);
  click(optionx, option1y);
  wait_s(120);
  click(optionx, option2y);
  wait_s(150);

  clickReward();
}

void enterNormal(void)
{
  click(questx, questy);
  wait_s(5); // クエストロード

  click(backx, backy); click(backx, backy); // 戻る
  click(329, 381);
  click(375, 605);

  click(episodex, getEpisodeY(6));
  wait_s(5);

  click(1020, 590); wait_s(1);
  click(634, 549); wait_s(1);

  wait_s(6);
  clickSpeedingUp();

  wait_s(120);
  click(optionx, option1y);
  wait_s(100);

  clickReward();
}

int main(void)
{
  gotoHome();
  repStart(8); {
    comment("Normal"); 
    repStart(2); {
      enterNormal();
    } repEnd();
    comment("Labyrinth"); 
    repStart(1); {
      enterLabyrinth1112();
    } repEnd();
  } repEnd();

  return 0;
}
