#include <iostream>
#include <vector>
#include <algorithm>
#include "Circle.h"
#include "parallelogram.h"


unsigned int menu() {

    while (true) {
        std::cout << "/----------SELECT_ACTION----------/\n\n";
        std::cout << "1 - Add figure\n";
        std::cout << "2 - Show all figures\n";
        std::cout << "3 - Sum all figure's squares\n";
        std::cout << "4 - Sum all figure's perimeters\n";
        std::cout << "5 - Show figure's mass' center\n";
        std::cout << "6 - Show count of memory from all classes\n";
        /*std::cout << "7 - Sort all figures by mass\n";*/
        std::cout << "7 - Exit from program\n";

        unsigned int action;
        std::cin >> action;

        if (action < 1 || action > 7) {
            std::cout << "Error, no such command in list!!! Try again!\n";
            continue;
        }

        return action;
    }

}

unsigned int FigureSELECT() {

    while (true) {
        std::cout << "/-----Select_type_of_figure-----/\n";
        std::cout << "1 - Circle\n";
        std::cout << "2 - Parallelogram\n";
        unsigned int select;
        std::cin >> select;

        if (select < 1 || select > 2) {
            std::cout << "Error, no such command in list!!! Try again!\n";
            continue;
        }
        return select;
    }
}


int main () {

    std::vector <Figure*> figures;

    size_t count = 0;
    while (true) {
        unsigned int command = menu();

        switch (command) {
            case 1: {
                unsigned int select = FigureSELECT();
                if (select == 1) {
                    figures.push_back(new Circle);
                    figures[count]->initFromDialog();
                    count++;
                    break;
                } else {
                    figures.push_back(new Parallelogram);
                    figures[count]->initFromDialog();
                    count++;
                    break;
                }
            }

            case 2: {
                for (int i = 0; i < figures.size(); i++){
                    std::cout << figures[i]->classname() << "\n";
                }
                break;
            }

            case 3: {
                double sum = 0;
                for (int i = 0; i < figures.size(); i++)
                    sum += figures[i]->square();
                std::cout << "Sum all figure's squares is - " << sum << '\n';
                break;
            }

            case 4: {
                double sum = 0;
                for (int i = 0; i < figures.size(); i++)
                    sum += figures[i]->perimeter();
                std::cout << "Sum all figure's perimeters is - " << sum << '\n';
                break;

            }

            case 5: {
                double allMX = 0, allMY = 0, allM = 0;
                for (int i = 0; i < figures.size(); i++) {
                    allMX += figures[i]->position().x * figures[i]->mass();
                    allMY += figures[i]->position().y * figures[i]->mass();
                    allM += figures[i]->mass();
                }
                std::cout << "Center is " << allMX / allM << " by OX and " << allMY / allM << " by OY\n";
                break;
            }

            case 6: {
                int countMemory = 0;
                for (int i = 0; i < figures.size(); i++)
                    countMemory += figures[i]->size();
                std::cout << "Count of memory for this system is - " << countMemory << '\n';
                break;
            }

            /*case 7: {
                std::sort (figures.begin(), figures.end(), figures);
                std::cout << "All figures was successfully sorted\n";
                break;
            }*/

            default:
                std::cout << "MY FINALE MASSAGE GOODBYE\n";
                return 0;
        }
    }
}
