#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Point {
public:
    int x, y;
};



class Character {

private:
    int hp, max_hp;
    string name;
    int dmg, def;
    Point posit;
    bool alive = 1;
public:

    void setposit(Point a) {
        posit.x = a.x;
        posit.y = a.y;
    }


    void setmaxhp(int maxh) {
        if (maxh <= 0) maxh = 1;
        max_hp = maxh;
    }

    void setname(string newname) {
        name = newname;
    }

    void sethp(int newhp) {
        if (newhp < 0) { newhp = 0; alive = 0; }

        if (newhp > max_hp) newhp = max_hp;
        hp = newhp;
    }

    void setdmg(int d) {
        if (d < 1) d = 1;
        dmg = d;
    }

    void setdef(int deff) {
        if (deff < 0) deff = 0;
        def = deff;
    }

    int getdmg() {
        return dmg;
    }

    int getdef() {
        return def;
    }

    int getmaxhp() {
        return max_hp;
    }

    string getname() {
        return name;
    }
    int gethp() {
        return hp;
    }
    bool isalive() {
        return alive;
    }

    Point getposit() {
        return posit;
    }
    void status() {
        cout << "Name: " << getname() << "\n";
        cout << "Status: ";
        if (isalive()) cout << "alive\n";
        else cout << "died\n";
        printf("HP: %d/%d\n", gethp(), getmaxhp());
        printf("Damage: %d\nDefence: %d\n", getdmg(), getdef());
        Point b = getposit();
        printf("Position: (%d, %d)\n", b.x, b.y);
    }
};

void bioms(Character& chara) {
    Point po = chara.getposit();
    int dmg = chara.getdmg(), def = chara.getdef(), hp = chara.gethp();
    //Desert
    if (po.x < 0 && po.y > 0) {
        chara.setdmg(dmg - 1);
        chara.sethp(hp - 5);
    }
    //Mountain Dew
    if (po.x < 0 && po.y < 0) {
        if (def > 100) chara.sethp(hp - 2);
    }
    //Swamp
    if (po.x > 0 && po.y < 0) {
        chara.setdef(def + 1);
    }
    //Bonfire
    if (po.x == 0 && po.y == 0) {
        chara.sethp(chara.getmaxhp());
    }
}


int main() {
    string s; cin >> s;
    int h, m; cin >> m >> h;
    Character AshenOne;
    AshenOne.setname(s);
    AshenOne.setmaxhp(m);
    AshenOne.sethp(h);
    int dm, df; cin >> dm >> df;
    AshenOne.setdmg(dm);
    AshenOne.setdef(df);
    Point z;
    cin >> z.x >> z.y;
    AshenOne.setposit(z);

    int it; cin >> it;
    for (int i = 0; i < it; i++) {
        string com;
        cin >> com;
        if (com == "move") {
            int x, y; cin >> x >> y;
            if (AshenOne.isalive()) {
                Point newpos;
                newpos.x = x; newpos.y = y;
                AshenOne.setposit(newpos);
                bioms(AshenOne);
            }
        }
        if (com == "status") {
            AshenOne.status();
        }
    }
}