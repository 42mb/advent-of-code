#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct sym { //symbol
    std::pair<int, int> coordinate{};
    char digit{};
    std::vector<int>numbers{};
};

struct nmb{ //number
    std::pair<int, int> coordinate{};
    int len{};
    int nmb;
    std::vector<std::pair<int, int>> coordinatesAround;
};

int main() {
    std::vector<sym> symbolList{};
    std::vector<nmb> numberList{};

    std::ifstream myfile ("/home/archi/Projects/adventofcode/2023/day03CPP/day3.prod");
    std:: string line {};
    int y{};
    if(!myfile.is_open()) {
        std::cout << "file not found\n";
    } else {
        while (std::getline (myfile, line)) {
        for(int x =0; x < line.length(); ++x) {
                if(isdigit(line[x]) == false && line[x] != '.') {
                    symbolList.push_back(sym({x, y}, line[x]));
                }
                if(isdigit(line[x])) {
                    int len{};
                    std::string nmb;
                    int coordinateX = x;
                    int coordinateY = y;
                    while(isdigit(line[x])){
                        len++;
                        nmb+=line[x];
                        x++;
                    }
                    x-=1;
                    std::vector<std::pair<int, int>> coordinatesAroundNumber{};
                    coordinatesAroundNumber.emplace_back(coordinateX - 1, coordinateY);
                    coordinatesAroundNumber.emplace_back(coordinateX + len, coordinateY); //??
                    for( int t = -1; t<len+1; ++t) {
                        coordinatesAroundNumber.emplace_back(coordinateX + t, coordinateY - 1);
                        coordinatesAroundNumber.emplace_back(coordinateX + t, coordinateY + 1);
                        ///////////////////////
                        //####
                        //#23#      coorAroundNmb should be the #
                        //####
                        ////////////////
                    }
                    struct nmb N({coordinateX, coordinateY}, len, std::stoi(nmb), coordinatesAroundNumber);
                    numberList.push_back(N);
                }
            }
            y++;
        }
        myfile.close();
    }

    int sum{};
    for(auto &nmb:numberList) {
        for(auto & adjacentCoordinate: nmb.coordinatesAround) {
            bool isAdjacent{false};
            for(auto &sym: symbolList) {
               if(sym.coordinate.first == adjacentCoordinate.first && sym.coordinate.second == adjacentCoordinate.second) {
                   if(sym.digit == '*') {
                       sym.numbers.emplace_back(nmb.nmb);
                   }
                   isAdjacent = true;
               }
            }
            if(isAdjacent) {
                sum+=nmb.nmb;
            }
        }
    }
    std::cout<<"Part1:   "<<  sum  <<"\n";

    int gearRatioSum{};
    for(auto &gears:symbolList) {
        if(gears.numbers.size() == 2) {
            gearRatioSum+= gears.numbers[0] * gears.numbers[1];
        }
    }
    std::cout << "Part2: " << gearRatioSum;

    return 0; //result p1: 507214  p2: 72553319
}
