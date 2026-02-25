#include <iostream>
#include <random>
#include <string>
using namespace std;

random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dist(1, 3);

class plant {
protected:
    int time;
    int water;
    int growth;

public:
    plant(int time, int water, int growth) {
        set(time, water, growth);
    }

    virtual ~plant() = default;

    void set(int time, int water, int growth) {
        this->time = time;
        this->water = water;
        this->growth = growth;
    }

    int gettime() {
        return time;
    }

    int getwater() {
        return water;
    }

    virtual void getattributes() {
        cout << " time: " << time << " water: " << water << endl;
    }

    int addwater(int addedwater, int ugrowth) {
        if (addedwater == water) {
            ugrowth += dist(mt);
        } else {
            ugrowth -= dist(mt);
        }
        return ugrowth;
    }

    int addWater(int addwaterr) {
        growth = addwater(addwaterr, growth);
        return growth;
    }
};

class tree : public plant {
private:
    int fruit;

public:
    tree(int time, int water, int growth) : plant(time, water, growth), fruit(0) {}

    ~tree() override = default;

    int growthfruits(int time, int water) {
        if (time > 2 && water > 1 && water < 7) {
            fruit = dist(mt);
        } else {
            fruit = 0;
        }
        return fruit;
    }
};

class flower : public plant {
public:
    flower(int time, int water, int growth) : plant(time, water, growth) {}

    ~flower() override = default;

    int growing(int addwater, int sunexposure) {
        int current_growth = 0;
        if (addwater > 0)
            current_growth = dist(mt);
        else
            current_growth = 0;

        if (sunexposure > 10) {
            current_growth -= 2;
        } else if (sunexposure < 5) {
            current_growth -= 1;
        } else {
            current_growth += dist(mt);
        }

        return current_growth;
    }

    void grow(int addw, int sun, int &flo, int &current_growth) {
        current_growth = growing(addw, sun);
        if (current_growth > 2)
            flo = 3 * dist(mt);
        cout << "Number of flowers grown today: " << flo << endl;
    }
};

class vegetables : public plant {
private:
    string soil;
    string bestquality = "x";
    string worstquality = "y";
    int tastiness = 0;
    int colourfulness = 0;

public:
    vegetables(int time, int water, int growth, string soil) : plant(time, water, growth), soil(soil) {}

    ~vegetables() override = default;

    void veggiesgrowth(string current_soil) {
        if (current_soil == bestquality) {
            tastiness++;
            colourfulness++;
        } else if (current_soil == worstquality) {
            tastiness--;
            colourfulness--;
        }
    }

    void getattributes() override {
        plant::getattributes();
        cout << " soil: " << soil << endl;
    }

    int get_tastiness() { return tastiness; }
    
    int get_colourfulness() { return colourfulness; }
};

void vegetabless(vegetables &z, int &g) {
    int n;
    string soil;
    cout << "Add water: " << endl;
    cin >> n;
    g = g + z.addWater(n);
    cout << "Growth of vegetable: " << g << endl;
    cout << "Choose the soil (x or y): " << endl;
    cin >> soil;
    cout << "Vegetable aspect: " << endl;
    z.veggiesgrowth(soil);
    cout << "Colour: " << z.get_colourfulness() << endl;
